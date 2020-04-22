
#include <Eigen/Dense>

#include "cnn.hpp"

Eigen::ArrayXd FeedForward::forward_pass(Eigen::ArrayXd x) {
	assert (weights.size() == D_W);
	assert (biases.size() == D_b);  
	weights = weights(Eigen::seq(0, width * D_in - 1));
	biases = biases(Eigen::seq(0, width - 1));
	
	return x;
}
