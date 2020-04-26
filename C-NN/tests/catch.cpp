#include <sstream>
#include <Eigen/Dense>
#include <string>
#include <unordered_map>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "cnn.hpp"

TEST_CASE( "Forward pass returns correct output dimension", "[C-NN]" )
{
	std::unordered_map<std::string, arch_value_type> arch
	    = {{"num_hidden", 2},
	       {"width", 20},
	       {"input_dim", 1},
	       {"output_dim", 3},
	       {"activation_fn", ActivationFns::ReLU}};

	auto nn                 = FeedForward( arch );
	Eigen::VectorXd x_train = Eigen::VectorXd::Random( 5 );
	REQUIRE(x_train.size() == std::get<int>(arch["output_dim"]));
}
