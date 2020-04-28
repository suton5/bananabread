#include <torch/torch.h>
#include <iostream>

// Define a new Module.
struct Net : torch::nn::Module {
  Net() {
    // Construct and register two Linear submodules.
    fc1 = register_module("fc1", torch::nn::Linear(1, 20));
    fc2 = register_module("fc2", torch::nn::Linear(20, 20));
    fc3 = register_module("fc3", torch::nn::Linear(20, 1));
  }

  // Implement the Net's algorithm.
  torch::Tensor forward(torch::Tensor x) {
    // Use one of many tensor manipulation functions.
    x = torch::relu(fc1->forward(x.reshape({x.size(0), 1})));
    x = torch::relu(fc2->forward(x));
    x = fc3->forward(x);
    return x;
  }

  // Use one of many "standard library" modules.
  torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};
};

int main() {
  // Create a new Net.
  auto net = std::make_shared<Net>();
  torch::Tensor prediction = net->forward(torch::randn({5, 1}));
  std::cout << prediction << std::endl;
}
