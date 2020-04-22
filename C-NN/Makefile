PROJECT=cnn
CXX=clang++
OBJDIR=target
EXT_DIR=external
CXXFLAGS=-I$(EXT_DIR)/include/eigen3
INCLUDES=.

.PHONY:
clean:
	rm -rf target
	rm -rf *.out
	rm -rf *.gch

setup:
	$(shell mkdir -p target/bin)
	./get_eigen3.sh

_HDRS = cnn.hpp
HDRS = $(patsubst %,$(INCLUDES)/%,$(_HDRS))

_OBJ = cnn.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

$(OBJDIR)/%.o: %.cpp $(HDRS)
	$(CXX) -c $< $(CFLAGS) -o $@

# Compile but don't link'
.PHONY: compile_src
compile_src: $(OBJ) 

main: main.cpp $(OBJ) $(HDRS)
	$(CXX) $^ $(CXXFLAGS)

.PHONY:
exec:
	$(OBJDIR)/main


all: clean setup compile_src main
