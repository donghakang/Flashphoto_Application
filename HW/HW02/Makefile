# We are giving a name to the executable to be created and defining
#the g++ compiler flags we will use in our compile (but not linking) commands.
EXEFILE = MyDuckApplication
CXXFLAGS = -c -Wall


$(EXEFILE): Duck.o MallardDuck.o DecoyDuck.o RubberDuck.o QuackBehavior.o MuteQuack.o Quack.o Squeak.o main.o
	g++ $^ -o $@


Duck.o: Duck.h Duck.cpp
	g++ -c Duck.cpp

DecoyDuck.o: Duck.h DecoyDuck.h DecoyDuck.cpp
	g++ -c DecoyDuck.cpp

%.o: %.cpp
	g++ $(CXXFLAGS) $^ -o $@


clean:
	rm *.o $(EXEFILE)
