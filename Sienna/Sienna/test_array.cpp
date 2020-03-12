// test_array CPP
//

#include "sienna.hpp"

int main(){
	Individual* individualSet = new Individual[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; ++i){
		individualSet[i].setID(i);
	}

	for (int i = 0; i < ARRAY_SIZE; ++i)
		individualSet[i].printData();

	std::cout << "Crossover two sets with id's 3 and 7." << std::endl
		<< "Data before Crossover: " << std::endl;
	individualSet[3].printData();
	individualSet[7].printData();

	individualSet[3].crossover(individualSet[7]);

	std::cout << "Printing Set 3 and 7 after crossover." << std::endl;
	individualSet[3].printData();
	individualSet[7].printData();
}