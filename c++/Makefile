all: temp
	.\temp  < test.txt

ans: temp
	.\temp < test.txt > out.txt
	fc .\out.txt .\ans.txt

temp: temp.cpp
	g++ temp.cpp -o temp
	
test:
	python t_generate_test.py > test.txt