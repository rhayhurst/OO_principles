rhayhu2_project2: main.o List.o Ulist.o Olist.o Stack.o Queue.o
	g++ main.o List.o Ulist.o Olist.o Stack.o Queue.o -o rhayhu2_project2

main.o: main.cpp
	g++ -c main.cpp

List.o: List.cpp List.o
	g++ -c List.cpp

Ulist.o: Ulist.cpp Ulist.o
	g++ -c Ulist.cpp

Stack.o: Stack.cpp Stack.o
	g++ -c Stack.cpp

Queue.o: Queue.cpp Queue.o
	g++ -c Queue.cpp

clean:
	rm *.o rhayhu2_project2