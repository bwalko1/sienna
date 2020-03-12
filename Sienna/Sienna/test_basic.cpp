// test_basic CPP
//

#include "sienna.hpp"

int main(){

	char repeat;

	do{
		Individual* individualSet = new Individual[ARRAY_SIZE];

		for (int i = 0; i < ARRAY_SIZE; ++i)
			individualSet[i].setID(i);

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

		std::cout << "Printing Individuals with high fitness." << std::endl;
		for (int i = 0; i < ARRAY_SIZE; ++i)
			if (individualSet[i].fitness() >= 0.85)
				individualSet[i].printData();

		std::cout << "Would you like to recalculate? (y/n)" << std::endl;
		std::cin >> repeat;

	} while (repeat == 'y');
}