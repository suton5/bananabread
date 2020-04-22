#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <Eigen/Dense>
#include <random>
#include <chrono>
#include <variant>
#include <string>

#include "cnn_math.hpp"
#include "cnn.hpp"

int main() {
   std::unordered_map<std::string, arch_value_type> arch = {
      {"num_hidden", 1},
      {"width", 10},
      {"input_dim", 1},
      {"output_dim", 1},
      {"activation_fn", ActivationFns::ReLU}
   };
   auto nn = FeedForward(arch);
   Eigen::VectorXd x_train = Eigen::VectorXd::Random(5);
   std::cout << nn.forward_pass(x_train) << std::endl;
   return 0; 
}