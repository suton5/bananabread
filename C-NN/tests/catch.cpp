#include <Eigen/Dense>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "cnn.hpp"

TEST_CASE( "catch2 infra test", "[INFRA]" )
{
	std::vector<int> v( 5 );
	Eigen::VectorXd x( 5 );

	REQUIRE( v.size() == 5 );
	REQUIRE( v.capacity() >= 5 );

	SECTION( "resizing bigger changes size and capacity" )
	{
		v.resize( 10 );

		REQUIRE( v.size() == 10 );
		REQUIRE( v.capacity() >= 10 );
	}

	SECTION( "Eigen::VectorXd is of correct size" )
	{
		REQUIRE(x.size() == 5);
	}
}
