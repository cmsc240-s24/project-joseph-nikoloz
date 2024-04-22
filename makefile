all: barAPI 

barAPI: barAPI.o Drink.o Food.o drinkFunctions.o
	g++ Drink.o drinkFunctions.o Food.o barAPI.o -o barAPI -pthread

barAPI.o: barAPI.cpp Consumable.h Drink.h Food.h drinkFunctions.h
	g++ barAPI.cpp -c

Food.o: Food.h Food.cpp Consumable.h
	g++ Food.cpp -c

Drink.o: Drink.h Drink.cpp Consumable.h 
	g++ Drink.cpp -c

drinkFunctions.o: drinkFunctions.cpp drinkFunctions.h
	g++ drinkFunctions.cpp -c

clean-code: 
	rm -f *.o barAPI

clean: clean-code
