#!/bin/bash

if [ ! -d external/include/optim ]; then
	git clone https://github.com/kthohr/optim

	mkdir external/include/optim
	cd optim
	./configure --header-version-only
	mv header_version_only ../external/include/optim

	wget http://sourceforge.net/projects/arma/files/armadillo-9.860.2.tar.xz
	tar xf armadillo-9.860.2.tar.xz
	cd armadillo-9.860.2
	cmake . -DCMAKE_INSTALL_PREFIX:PATH=$PWD/../external
	make all
	make install

	cd ../..
	rm -rf optim
else
	echo "liboptim already installed"
fi
