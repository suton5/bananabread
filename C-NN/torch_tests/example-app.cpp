#include <torch/torch.h>
#include <iostream>
#include <chrono>

// Define a new Module.
struct Net : torch::nn::Module {
  Net() {
    // Construct and register two Linear submodules.
    fc1 = register_module("fc1", torch::nn::Linear(1, 20));
    fc2 = register_module("fc2", torch::nn::Linear(20, 20));
    fc3 = register_module("fc3", torch::nn::Linear(20, 1));
	layers.push_back(fc1);
	layers.push_back(fc2);
	layers.push_back(fc3);
	no_layers = layers.size();
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
  std::vector<torch::nn::Linear> layers;
  int no_layers;
};

int main() {
  // Create a new Net.
  auto net = std::make_shared<Net>();
  torch::autograd::GradMode::set_enabled(false);
  for(int k = 0; k < net->no_layers; ++k) {
	  net->layers[k]->weight.uniform_(1,1);
	  net->layers[k]->bias.uniform_(0,0);
  }
  torch::autograd::GradMode::set_enabled(true);

  auto start = std::chrono::system_clock::now();
  torch::Tensor prediction = net->forward(torch::ones(1E6));
  auto end = std::chrono::system_clock::now();
  std::cout << std::chrono::duration<double>(end - start).count() << std::endl;
}
