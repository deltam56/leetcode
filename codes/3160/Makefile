CXX := g++
CXXFLAGS := -std=c++17 -Wall
DBGFLAGS := -g

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=)
DBG_OBJS := $(addsuffix _debug, $(OBJS))

.PHONY: all clean

all: $(OBJS) $(DBG_OBJS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

%_debug: %.cpp
	$(CXX) $(CXXFLAGS) $(DBGFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(DBG_OBJS)
