CXX := g++
CXXFLAGS := -std=c++23 -Wall
DBGFLAGS := -g

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=)
DBG_OBJS := $(addsuffix _debug, $(OBJS))

.PHONY: all clean

all: $(OBJS) $(DBG_OBJS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

%_debug: %.cpp
	$(CXX) $(CXXFLAGS) $(DBGFLAGS) $< 

clean:
	rm -rf $(OBJS) $(DBG_OBJS) *.dSYM
