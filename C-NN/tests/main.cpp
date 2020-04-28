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

    int
    main()
{
	std::unordered_map<std::string, arch_value_type> arch
	    = {{"num_hidden", 2},
	       {"width", 20},
	       {"input_dim", 1},
	       {"output_dim", 1},
	       {"activation_fn", cnn_math::relu}};

	auto nn                 = FeedForward( arch );
	nn.weights              = Eigen::VectorXd::Ones( nn.D_W );
	nn.biases               = Eigen::VectorXd::Zero( nn.D_b );
	Eigen::VectorXd x_train = Eigen::VectorXd::Ones( 1E6 );
	auto start              = std::chrono::system_clock::now();
	auto prediction         = nn.forward_pass( x_train );
	auto end                = std::chrono::system_clock::now();
	std::cout << std::chrono::duration<double>( end - start ).count()
	          << std::endl;
	// std::cout << nn.forward_pass( x_train ) << std::endl;
	return 0;
}
