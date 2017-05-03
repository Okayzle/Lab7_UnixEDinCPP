
a.out: object.o line.o doc.o ed.o
	g++ -std=c++11 object.o line.o doc.o ed.o

object.o: object.h object.cpp
	g++ -c -std=c++11 object.cpp

line.o: line.cpp line.h object.h words.h
	g++ -c -std=c++11 line.cpp

doc.o: doc.cpp doc.h object.h words.h line.h
	g++ -c -std=c++11 doc.cpp

ed.o: ed.cpp line.h words.h doc.h
	g++ -c -std=c++11 ed.cpp

clean:
	rm -f *.o a.out a.exe
