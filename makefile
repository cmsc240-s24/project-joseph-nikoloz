all: barAPI 

barAPI: barAPI.o Drink.o Food.o GenericAPI.o
	g++ Drink.o Food.o barAPI.o GenericAPI.o -o barAPI -pthread

barAPI.o: barAPI.cpp Consumable.h Drink.h Food.h GenericAPI.h persistence.h
	g++ -Wall barAPI.cpp -c

Food.o: Food.h Food.cpp Consumable.h
	g++ -Wall Food.cpp -c

Drink.o: Drink.h Drink.cpp Consumable.h 
	g++ -Wall Drink.cpp -c

GenericAPI.o: GenericAPI.cpp GenericAPI.h Drink.h 
	g++ -Wall -c GenericAPI.cpp 



clean-code: 
	rm -f *.o barAPI

clean: clean-code
