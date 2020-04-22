#!/bin/bash

if [ ! -d external/include/eigen3 ]; then
	git clone https://gitlab.com/libeigen/eigen.git

	mkdir eigen3-build
	cd eigen3-build
	cmake ../eigen -DCMAKE_INSTALL_PREFIX=$PWD/../external
	make install

	rm -r eigen3-build eigen
else
	echo "Eigen 3 already installed"
fi
