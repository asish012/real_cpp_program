
bin/scheck : main.o parser.o csvreporter.o commandline.o settings.o
	g++ bin/main.o bin/parser.o bin/csvreporter.o bin/commandline.o bin/settings.o -o bin/scheck

main.o : src/main.cpp inc/Parser.h inc/ScheckError.h inc/Dictionary.h
	g++ -std=c++0x -I inc -c src/main.cpp -o bin/main.o

parser.o : src/Parser.cpp inc/Parser.h inc/ScheckError.h
	g++ -std=c++0x -I inc -c src/Parser.cpp -o bin/parser.o

csvreporter.o : src/CSVReporter.cpp inc/CSVReporter.h inc/Reporter.h
	g++ -std=c++0x -I inc -c src/CSVReporter.cpp -o bin/csvreporter.o

commandline.o : src/CommandLine.cpp inc/CommandLine.h
	g++ -std=c++0x -I inc -c src/CommandLine.cpp -o bin/commandline.o

settings.o : src/Settings.cpp inc/Settings.h inc/CommandLine.h inc/ScheckError.h
	g++ -std=c++0x -I inc -c src/Settings.cpp -o bin/settings.o

clean :
	rm bin/scheck bin/parser.o bin/csvreporter.o bin/commandline.o bin/ settings.o bin/main.o