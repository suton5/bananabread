#!/bin/bash

if [ ! -f external/include/csv.h ]; then
	git clone https://github.com/ben-strasser/fast-cpp-csv-parser
	cp fast-cpp-csv-parser/csv.h external/include

	rm -rf fast-cpp-csv-parser
else
	echo "fast-cpp-csv-parser already installed"
fi
