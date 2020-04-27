#!/bin/bash

if [ ! -d libtorch ]; then
	wget https://download.pytorch.org/libtorch/cpu/libtorch-macos-1.5.0.zip 
	unzip libtorch-macos-1.5.0.zip
	rm libtorch-macos-1.5.0.zip
else
	echo "libtorch already installed"
fi
