.PHONY: clean

main: hello
	gcc -g -o $@ main.c elf32.c 

hello: hello.c
	gcc -g -m32 -no-pie -o $@ $^

clean:
	rm -fr *.o main hello