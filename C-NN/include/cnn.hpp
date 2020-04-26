#ifndef CNN_H_IN
#define CNN_H_IN

#include <assert.h>
#include <Eigen/Dense>
#include <chrono>
#include <iostream>
#include <random>
#include <unordered_map>
#include <variant>

#include "cnn_math.hpp"

using ActivationFnType = std::function<Eigen::MatrixXd( Eigen::MatrixXd )>;
using arch_value_type = std::variant<int, ActivationFnType>;

class FeedForward
{
   public:
	std::unordered_map<std::string, arch_value_type> architecture;
	ActivationFnType h;
	int L;
	int width;
	int D_in;
	int D_out;
	int D_W;
	int D_b;
	Eigen::VectorXd weights;
	Eigen::VectorXd biases;

   public:
	FeedForward( std::unordered_map<std::string, arch_value_type> architecture,
	             Eigen::VectorXd weights_ = Eigen::VectorXd{},
	             Eigen::VectorXd biases_  = Eigen::VectorXd{} );
	Eigen::MatrixXd forward_pass( Eigen::VectorXd x );
};

#endif // CNN_H_IN
