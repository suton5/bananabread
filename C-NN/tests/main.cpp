#include <assert.h>
#include <Eigen/Dense>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <variant>

// #include "optim.hpp" // For Adam optimizer

#include "cnn.hpp"
#include "cnn_math.hpp"

int main()
{
	std::unordered_map<std::string, arch_value_type> arch
	    = {{"num_hidden", 2},
	       {"width", 20},
	       {"input_dim", 1},
	       {"output_dim", 3},
	       {"activation_fn", cnn_math::relu}};

   auto nn = FeedForward(arch);
   Eigen::VectorXd x_train = Eigen::VectorXd::Random(5);
   // nn.forward_pass(x_train);
   std::cout << nn.forward_pass(x_train) << std::endl;
   return 0; 
}
