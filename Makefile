build: src/hr.c
	gcc -Wall -O2 -o ./hr src/hr.c

clean: ./hr
	rm ./hr
