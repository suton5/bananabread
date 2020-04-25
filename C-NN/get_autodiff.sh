#!/bin/bash

if [ ! -d external/include/autodiff ]; then
	git clone https://github.com/autodiff/autodiff

	mkdir autodiff-build
	cd autodiff-build
	cmake ../autodiff -DCMAKE_INSTALL_PREFIX=$PWD/../external
	make -j4 install

	cd ..
	rm -rf autodiff-build autodiff
else
	echo "autodiff already installed"
fi
