all: temp
	./temp  < test.txt

ans: temp
	./temp < test.txt > out.txt
	fc .\out.txt .\ans.txt

temp: temp.cpp
	g++ temp.cpp -o temp -std=c++20

temp1: temp1.cpp
	g++ temp1.cpp -o temp1 -std=c++20
	./temp1 < test1.txt
test:
	python t_generate_test.py > test.txt

input: temp
	./temp
