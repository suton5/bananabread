#!/bin/bash

if [ ! -f external/include/catch.hpp ]; then
	wget https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp
	mv catch.hpp external/include
else
	echo "catch2 already installed"
fi
