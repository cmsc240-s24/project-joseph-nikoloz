all: barAPI 

barAPI: barAPI.o 
	g++ barAPI.o -o barAPI -pthread

barAPI.o: barAPI.cpp Consumable.h Drink.h
	g++ barAPI.cpp -c

clean-code: 
	rm -f barAPI.o barAPI

clean: clean-code