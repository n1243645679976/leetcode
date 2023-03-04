all: temp.py
	python temp.py < test.txt

ans: temp.py
	python temp.py < test.txt > out.txt
	fc .\out.txt .\ans.txt
	
test:
	python t_generate_test.py > test.txt