all:
	gcc -Wall --pedantic src/*.c -lm -o bin/gauss

test: all
	bin/gauss dane/testowe/1indeks0A dane/testowe/1indeks0b dane/testowe/1indeks0wyniki
	bin/gauss dane/testowe/dobry2A dane/testowe/dobry2b dane/testowe/dobry2wyniki
	bin/gauss dane/testowe/dobry5A dane/testowe/dobry5b dane/testowe/dobry5wyniki
	bin/gauss dane/testowe/osobliwa2A dane/testowe/osobliwa2b
	bin/gauss dane/testowe/zlewymiary2A dane/testowe/zlewymiary2b
