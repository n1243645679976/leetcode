CXX = g++
CXXFLAGS = -I. -Wall -Wextra -Wconversion -O2 -std=c++20 -DLOCAL
LDFLAGS = -static -Wl,--stack=268435456

TARGET = temp

SRCS = temp.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	temp.exe < test.txt

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -f $(TARGET) $(OBJS) $(OBJS:.o=.d)