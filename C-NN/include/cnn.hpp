#ifndef CNN_H_IN
#define CNN_H_IN

#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <Eigen/Dense>
#include <random>
#include <chrono>
#include <variant>

enum class FunNames {
	RELU,
	TANH
};

using arch_value_type = std::variant<int, FunNames>;

class FeedForward {
  private:
	std::unordered_map<std::string, FunNames> architecture;
	std::function<Eigen::ArrayXd(Eigen::ArrayXd)> h;
	int L;
	int width;
	int D_in;
	int D_out;
	int D_W;
	int D_b;
	Eigen::ArrayXd weights;
	Eigen::ArrayXd biases;

  public:
	FeedForward(std::unordered_map<std::string, arch_value_type> architecture) 
		: h(),
		  L(std::get<int>(architecture["num_hidden"])),
		  //width of hidden layers (assume constant for now)
		  width(std::get<int>(architecture["width"])),
		//dimension of input layer
		  D_in(std::get<int>(architecture["input_dim"])),
		//dimension of output layer
		  D_out(std::get<int>(architecture["output_dim"])),
		//number of weights needed
		  D_W((D_in * width) + ((L - 1) * width * width) + (width * D_out)),
		//number of biased needed
		  D_b((width) + ((L - 1) * width) + (D_out)),
		//initialise weights
		  weights(),
		//initialise biases
		  biases()
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);

		std::normal_distribution<double> distribution(0.0,1.0);

		weights.resize(D_W);
		for(auto e : weights)
			e = distribution(generator);

		weights.resize(D_b);
		for(auto e : biases)
			e = distribution(generator);
	}

	Eigen::ArrayXd forward_pass(Eigen::ArrayXd x);
};

#endif // CNN_H_IN
