PROJECT=cnn
CXX=clang++
OBJDIR=target
EXT_DIR=external
INCLUDES=include
CXXFLAGS=-I$(EXT_DIR)/include/eigen3 -I$(EXT_DIR)/include/autodiff -I$(EXT_DIR)/include -I$(INCLUDES) -std=c++17 -pthread -g
TESTDIR=tests

.PHONY:
clean:
	rm -rf target
	rm -rf tests/*.out
	rm -rf *.out
	rm -rf *.o
	rm -rf *.gch

setup:
	chmod a+x get_eigen3.sh
	chmod a+x get_igl.sh
	$(shell mkdir -p target/bin)
	./get_eigen3.sh
	./get_autodiff.sh
	./get_csv_parser.sh
	./get_catch2.sh

#./get_optim.sh
#./get_igl.sh

_HDRS = cnn.hpp cnn_math.hpp
HDRS = $(patsubst %,$(INCLUDES)/%,$(_HDRS))

_OBJ = cnn.o cnn_math.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

# Tests for infra
_TESTS = csv.out catch.out
TESTS = $(patsubst %,$(TESTDIR)/%,$(_TESTS))

# Tests for C-NN
_DRIVERS = main.out
DRIVERS = $(patsubst %,$(TESTDIR)/%,$(_DRIVERS))

$(OBJDIR)/%.o: %.cpp $(HDRS)
	$(CXX) -c $< $(CXXFLAGS) -o $@

# Compile but don't link'
.PHONY: compile_src
compile_src: $(OBJ) 

$(TESTDIR)/%.out: $(TESTDIR)/%.cpp $(OBJ)
	$(CXX) $^ $(CXXFLAGS) -o $@

.PHONY: compile_tests
compile_tests: $(TESTS)

.PHONY: compile_drivers
compile_drivers: $(DRIVERS)

TORCH_TEST_DIR=$(PWD)/torch_tests
TORCH_DIR=$(PWD)/libtorch
.PHONY: torch
torch:
	./get_libtorch.sh
	cd $(TORCH_TEST_DIR) && \
		cmake -DCMAKE_PREFIX_PATH=$(TORCH_DIR) $(TORCH_TEST_DIR) && \
		cmake --build .

all: clean setup compile_src compile_drivers
