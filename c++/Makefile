CXX = g++
CXXFLAGS =  -I. -Wall -Wextra -Wconversion -static -DLOCAL -Wl,--stack=268435456 -O2 -std=c++20
TARGET = temp

SRCS = temp.cpp
OBJS = $(SRCS:.cpp=.o)


temp: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ -DLOCAL
	./temp < test.txt

temp1: temp1.cpp
	$(CXX) $(CXXFLAGS) temp1.cpp -o ./temp1 -DLOCAL
	temp1 < test.txt

temppy: temp.py
	python temp.py < test.txt

ans: $(TARGET)
	$(TARGET) < test.txt > out.txt
	fc .\out.txt .\ans.txt

ml: tempml
	./temp < test.txt

check: all
	python t_generate_test.py > test.txt
	python temp.py < test.txt > a.txt
	$(TARGET) < test.txt > b.txt
	fc .\a.txt .\b.txt
test: $(TARGET)
	python t_generate_test.py > test.txt
	$(TARGET) < test.txt


diff: temp temp1 test.txt
	temp < test.txt > output_temp.txt
	temp1 < test.txt > output_temp1.txt
	fc output_temp.txt output_temp1.txt

input: $(TARGET)
	$(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 用于检查.cpp文件是否有更改的规则
$(OBJS): $(SRCS)
	$(CXX) -MMD -MP $(CXXFLAGS) -c $<

-include $(OBJS:.o=.d)

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJS:.o=.d) $(TARGET) tempml temp1 out.txt
