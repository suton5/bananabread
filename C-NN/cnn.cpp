#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <Eigen/Dense>
// #include <autodiff/forward.hpp>

class FeedForward {
	std::unordered_map architecture;
	Eigen::ArrayXd weights;
	Eigen::ArrayXd biases;

	FeedForward(std::unordered_map architecture, Eigen::ArrayXd weights = None, Eigen::ArrayXd biases = None) {
		//activation function
		self.h = architecture["activation_fn"];
		//number of hidden layers (excludes input and output layers)
		self.L = architecture["num_hidden"];
		//width of hidden layers (assume constant for now)
		self.width = architecture["width"];
		//dimension of input layer
		self.D_in = architecture["input_dim"];
		//dimension of output layer
		self.D_out = architecture["output_dim"];
		//number of weights needed
		self.D_W = (self.D_in * self.width) + ((self.L - 1) * self.width * self.width) + (self.width * self.D_out);
		//number of biased needed
		self.D_b = (self.width) + ((self.L - 1) * self.width) + (self.D_out);
		//initialise weights
		if (weights == None) {
			self.W = random(self.D_W);
		} else {
			self.W = weights;
		}
		//initialise biases
		if (biases == None) {
			self.b = random(self.D_b);
		} else {
			self.b = biases;
		}
	}

	Eigen::ArrayXd forward_pass(x) {
		assert (self.W.size() == self.D_W);
		assert (self.b.size() == self.D_b);  
	//   assert (shape());
		W = self.W(Eigen::seq(0, self.width * self.D_in - 1));
		b = self.b(Eigen::seq(0, self.width - 1));
		
		return x;
	}
}