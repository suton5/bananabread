#!/bin/bash

if [ ! -d external/include/libigl ]; then
	git clone https://github.com/libigl/libigl.git

	mkdir libigl-build
	cd libigl-build
	cmake ../libigl -DCMAKE_INSTALL_PREFIX=$PWD/../external
	make install

	rm -rf libigl-build libigl
else
	echo "libigl already installed"
fi
