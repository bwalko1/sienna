// ______________
// SiennaMain CPP
// ____________________________________________________________
// The goal of Sienna is to add two randomly selected variables
// and get as close to the number '10' as possible.
// The program will randomly mutate, crossover, and recalculate
// these "Individuals".
//

#include "sienna.hpp"

int main(){

	// Initialize Main loop variable
	char repeat = ' ';

	// Main loop
	do{
		// Initialize variables
		int generations = 0,
			ID1, ID2;
		bool endProgram = false;

		// Create and initialize individual array
		Individual* individualSet = new Individual[ARRAY_SIZE];
		for (int i = 0; i < ARRAY_SIZE; i++)
			individualSet[i].setID(i);

		// Start Sienna
		do{
			generations++;

		//  std::cout << "<========== GENERATION " << generations << " ==========>" << std::endl;

		// Crossover
			ID1 = selectRandomID();
			ID2 = selectRandomID();

			// Ensures the same Individual is not selected for crossover
			do{
				ID2 = selectRandomID();
			} while (ID1 == ID2);

			individualSet[ID1].crossover(individualSet[ID2]);

		// Mutation
			ID1 = selectRandomID();
			ID2 = selectRandomID();

			// Ensures the same Individual is not selected for mutation
			do{
				ID2 = selectRandomID();
			} while (ID1 == ID2);

			individualSet[ID1].mutate();
			individualSet[ID2].mutate();

			// Re-calculate any individuals with low fitness and mutates
				// "Refreshes"
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				if (individualSet[i].fitness() <= 0.15){
					individualSet[i].setX(individualSet[i].randomGen());
					individualSet[i].setY(individualSet[i].randomGen());
					individualSet[i].addRefresh();
					individualSet[i].mutate();
				}
			}

			
			// Prints the Array
			// Disabling this improves speed.
			/*
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				individualSet[i].printData();
			}
			*/

			// Checking array for any individual with extremely high fitness
			// Will also stop the program.
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				if (individualSet[i].fitness() >= 0.95){
					std::cout
						<< "The individual " << individualSet[i].getID()
						<< " passed with " << individualSet[i].fitness()
						<< " fitness after " << generations
						<< " generations." << std::endl;
					individualSet[i].printData();
					endProgram = true;
				}
			}

		} while (!endProgram);

		std::cout << "Would you like to repeat? (y/n)" << std::endl;
		std::cin >> repeat;

	} while (repeat == 'y');
}