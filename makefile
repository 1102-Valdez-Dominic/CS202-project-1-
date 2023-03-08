meatMob: driver.o customer.o menuItem.o
	g++ -o meatMob driver.o customer.o menuItem.o
driver.o: driver.cpp customer.h
	g++ -c driver.cpp
customer.o: customer.cpp customer.h menuItem.h
	g++ -c customer.cpp
menuItem.o: menuItem.cpp menuItem.h
	g++ -c menuItem.cpp
clean:
	rm *.o meatMob