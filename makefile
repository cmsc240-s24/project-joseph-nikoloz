all: barAPI 

barAPI: barAPI.o Drink.o Food.o Consumable.o GenericAPI.o
	g++ Drink.o Food.o barAPI.o GenericAPI.o -o barAPI -pthread

barAPI.o: barAPI.cpp Consumable.h Drink.h Food.h GenericAPI.h persistence.h
	g++ -Wall barAPI.cpp -c

Consumable.o: Consumable.h Consumable.cpp
	g++ -Wall Consumable.cpp -c
	
Food.o: Food.h Food.cpp Consumable.h
	g++ -Wall Food.cpp -c

Drink.o: Drink.h Drink.cpp Consumable.h 
	g++ -Wall Drink.cpp -c

GenericAPI.o: GenericAPI.cpp GenericAPI.h Drink.h  Consumable.h Food.h
	g++ -Wall -c GenericAPI.cpp 

ConsumableTest: ConsumableTest.cpp Consumable.cpp Consumable.h Consumable.o
	g++ -lpthread ConsumableTest.cpp Consumable.o -o ConsumableTest

DrinkTest: DrinkTest.cpp Drink.cpp Drink.h Drink.o
	g++ -lpthread DrinkTest.cpp Drink.o -o DrinkTest

FoodTest: FoodTest.cpp Food.cpp Food.h Food.o
	g++ -lpthread FoodTest.cpp Food.o -o FoodTest

#run-unit-tests: GenericAPITest persistenceTest
#	./GenericAPITest    ;\
	./persistenceTest	;\
	./ConsumableTest	;\
	./DrinkTest	;\
	./FoodTest

run-unit-tests:
	./ConsumableTest	;\
	./DrinkTest	;\
	./FoodTest	;\

clean-code: 
	rm -f *.o barAPI

clean-unit-tests:
	rm GenericAPITest persistenceTest ConsumableTest DrinkTest FoodTest
	
clean: clean-code clean-unit-tests
