all: tester
check: key_header_support_test
	./key_header_support_test
travis: key_header_support_test
	./key_header_support_test --simple
c-simple_lexer/lexer.a: c-simple_lexer/lexer.c
	$(MAKE) -C c-simple_lexer
key_header_support_test: main.c c-simple_lexer/lexer.a
	gcc -DTESTS main.c c-simple_lexer/lexer.a -o key_header_support_test
clean:
	rm -f *.o key_header_support_test
