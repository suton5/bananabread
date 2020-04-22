
#include <Eigen/Dense>

#include "cnn.hpp"

Eigen::ArrayXd forward_pass(Eigen::ArrayXd x) {
	assert (W.size() == self.D_W);
	assert (b.size() == self.D_b);  
	W = W(Eigen::seq(0, width * D_in - 1));
	b = b(Eigen::seq(0, width - 1));
	
	return x;
}
