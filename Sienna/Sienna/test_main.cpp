// test_main CPP
//

#include "sienna.hpp"

int main(){
	// Initial Test
	std::cout << "Initial Test" << std::endl
		<< "====================" << std::endl;
	Individual test1;
	test1.printData();

	// Fitness Eval
	std::cout << "Fitness Test" << std::endl
		<< "====================" << std::endl;
	test1.fitness();
	test1.printData();

	// Mutate Test
	std::cout << "Mutate Test" << std::endl
		<< "====================" << std::endl;
	test1.mutate();
	test1.printData();

	// Crossover Test
	Individual test2;
	std::cout << "Crossover Test" << std::endl
		<< "====================" << std::endl;
	test1.printData();
	test2.printData();
	std::cout << "-----Crossover-----" << std::endl;
	test1.crossover(test2);
	test1.printData();
	test2.printData();

}