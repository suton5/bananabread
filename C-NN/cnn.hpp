#ifndef CNN_H_IN
#define CNN_H_IN

#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <Eigen/Dense>



class FeedForward {
  private:
	std::unordered_map architecture;
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
	FeedForward(std::unordered_map architecture) 
		: h(architecture["activation_fn"]),
		  L(architecture["num_hidden"]),
		  //width of hidden layers (assume constant for now)
		  width(architecture["width"]),
		//dimension of input layer
		  D_in(architecture["input_dim"]),
		//dimension of output layer
		  D_out(architecture["output_dim"]),
		//number of weights needed
		  D_W((D_in * width) + ((L - 1) * width * width) + (width * D_out)),
		//number of biased needed
		  D_b((width) + ((L - 1) * width) + (D_out)),
		//initialise weights
		  weights(random(D_W)),
		//initialise biases
		  biases(random(D_b))
	{}

	Eigen::ArrayXd forward_pass(Eigen::ArrayXd x);
}

#endif // CNN_H_IN
