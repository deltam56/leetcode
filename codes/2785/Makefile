CXX := g++
CXXFLAGS := -std=c++23 -Wall
DBGFLAGS := -g

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=)
DBG_OBJS := $(addsuffix _debug, $(OBJS))

.PHONY: all clean

all: $(OBJS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $(DBGFLAGS) $< 

clean:
	rm -rf $(OBJS) $(DBG_OBJS) *.dSYM a.out
