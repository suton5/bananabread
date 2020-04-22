PROJECT=cnn
CXX=clang++
OBJDIR=target
EXT_DIR=external
CXXFLAGS=-I$(EXT_DIR)/include/eigen3 -I$(EXT_DIR)/include -I$(EXT_DIR)/include/igl -std=c++17
INCLUDES=.
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

#./get_igl.sh

_HDRS = cnn.hpp cnn_math.hpp
HDRS = $(patsubst %,$(INCLUDES)/%,$(_HDRS))

_OBJ = cnn.o cnn_math.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

_TESTS = trial.out
TESTS = $(patsubst %,$(TESTDIR)/%,$(_TESTS))

$(OBJDIR)/%.o: %.cpp $(HDRS)
	$(CXX) -c $< $(CXXFLAGS) -o $@

# Compile but don't link'
.PHONY: compile_src
compile_src: $(OBJ) 

$(TESTDIR)/%.out: $(TESTDIR)/%.cpp $(OBJ)
	$(CC) $^ $(CXXFLAGS) -o $(TESTDIR)/$@

.PHONY: compile_tests
compile_tests: $(TESTS)

all: clean setup compile_src compile_tests
