PROJECT=cnn
CXX=clang++
OBJDIR=target
EXT_DIR=external
CXXFLAGS=-I$(EXT_DIR)/include/eigen3 -I$(EXT_DIR)/include/libigl
INCLUDES=.

.PHONY:
clean:
	rm -rf target
	rm -rf *.out
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

$(OBJDIR)/%.o: %.cpp $(HDRS)
	$(CXX) -c $< $(CXXFLAGS) -o $@

# Compile but don't link'
.PHONY: compile_src
compile_src: $(OBJ) 

main: main.cpp $(OBJ) $(HDRS)
	$(CXX) $^ $(CXXFLAGS)

.PHONY:
exec:
	$(OBJDIR)/main


all: clean setup compile_src main
