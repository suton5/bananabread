#include <assert.h>
#include <Eigen/Dense>
#include <chrono>
#include <iostream>
#include <random>
#include <unordered_map>
#include <variant>

#include "cnn.hpp"
#include "cnn_math.hpp"

FeedForward::FeedForward(
    std::unordered_map<std::string, arch_value_type> architecture,
    Eigen::VectorXd weights_, Eigen::VectorXd biases_ )
    :
	// activation function
	h(),
	//number of hidden layers (excludes input and output layers)
	L(std::get < int > (architecture["num_hidden"])),
	//width of hidden layers (assume constant for now)
	width(std::get < int > (architecture["width"])),
	//dimension of input layer
	D_in(std::get < int > (architecture["input_dim"])),
	//dimension of output layer
	D_out(std::get < int > (architecture["output_dim"])),
	//number of weights needed
	D_W((D_in * width) + ((L - 1) * width * width) + (width * D_out)),
	//number of biased needed
	D_b((width) + ((L - 1) * width) + (D_out)),
	//initialise weights
	weights(weights_),
	//initialise biases
	biases(biases_)
    {
	    unsigned seed
	        = std::chrono::system_clock::now().time_since_epoch().count();
	    std::default_random_engine generator( seed );

	    std::normal_distribution<double> distribution( 0.0, 1.0 );

	    if( weights.size() == 0 )
	    {
		    weights.resize( D_W );
		    for( auto& e: weights )
			    e = distribution( generator );
	    }

	    if( biases.size() == 0 )
	    {
		    biases.resize( D_b );
		    for( auto& e: biases )
			    e = distribution( generator );
	    }

	    switch( std::get<ActivationFns>( architecture["activation_fn"] ) )
	    {
		    case ActivationFns::Tanh: h = cnn_math::tanh; break;

		    default: h = cnn_math::relu; break;
	    }
    }

    Eigen::VectorXd FeedForward::forward_pass( Eigen::VectorXd x )
    {
	    assert( weights.size() == D_W );
	    assert( biases.size() == D_b );
	    int index_W       = width * D_in - 1;
	    int index_b       = width - 1;
	    Eigen::VectorXd W = weights( Eigen::seq( 0, index_W ) );
	    Eigen::VectorXd b = biases( Eigen::seq( 0, index_b ) );

	    // //input layer
	    // Eigen::MatrixXd input = W * x.transpose();
	    // input.colwise() += b;
	    // Eigen::MatrixXd output = h(input);

	    // //hidden layers
	    // for (int l=0; l<L-1; ++l) {
	    //     W = weights(Eigen::seq(index_W + 1, index_W + width*width));
	    //     b = biases(Eigen::seq(index_b + 1, index_b + width));
	    //     Eigen::MatrixXd input = W * output.transpose();
	    //     input.colwise() += b;
	    //     output = h(input);
	    //     index_W += width*width;
	    //     index_b += width;
	    // }

	    // //output layer
	    // W = weights(Eigen::seq(index_W + 1, index_W + width*width));
	    // b = biases(Eigen::seq(index_b + 1, index_b + width));
	    // Eigen::MatrixXd input = output.transpose() * W;
	    // // output.colwise() += b;
	    // // output = h(output);
	    // std::cout << input << std::endl;
	    // CHANGE TO output LATER
	    return W;
    }
