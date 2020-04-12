X = g++
CXXFLAGS = -Wall -I/usr/include/eigen3/

proj4: io.o main.cpp
	$(CXX) $(CXXFLAGS) io.o main.cpp -o proj4
  
io.o: io.cpp io.h
	$(CXX) $(CXXFLAGS) -c io.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj4