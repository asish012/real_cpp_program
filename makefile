
bin/scheck : main.o parser.o
	g++ bin/main.o bin/parser.o -o bin/scheck

main.o : src/main.cpp inc/Parser.h inc/ScheckError.h inc/Dictionary.h
	g++ -I inc -c src/main.cpp -o bin/main.o

parser.o : src/Parser.cpp inc/Parser.h inc/ScheckError.h
	g++ -I inc -c src/Parser.cpp -o bin/parser.o

clean :
	rm bin/scheck bin/parser.o bin/main.o