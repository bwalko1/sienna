// __________
// Sienna CPP
//

#include "sienna.hpp"

Individual::Individual(){

	// Initializes the Individual
	x = randomGen();
	y = randomGen();
	fitNum = 0.0;
	ID = 0;
	crossovers = 0;
	mutations = 0;
	refreshes = 0;
}

void Individual::setX(double newX){
	x = newX;
}

void Individual::setY(double newY){
	y = newY;
}

void Individual::setID(int newID){
	ID = newID;
}

int Individual::getID(){
	return ID;
}

double Individual::getX(){
	return x;
}

double Individual::getY(){
	return y;
}

double Individual::randomGen(){

	// Randomly Generates a number.
	// Ensures no Individual can pass with just its 
		// variables. It needs to crossover/mutate/refresh
		// to be able to Pass.
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> rand1(35.0, 175.0);

	int randInt = rand1(generator) / 100.0;
	return randInt;
}

void Individual::mutate(){

	// Mutates a random variable (either x or y)
		// of the Individual.
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int>
		rand1(1, 100), rand2(0,15), rand3(0, 600.0), rand4(0, 550.0);

	double randInt, randInt2 = 0;
	randInt = rand1(generator);
	if (randInt <= 25){
		randInt = rand2(generator);
		if (randInt == (0 || 10)){
			randInt2 = rand3(generator) / 100.0;
			setX(randInt2);
			mutations++;
		}
		else if (randInt == 5)
		{
			randInt2 = rand3(generator) / 100.0;
			setY(randInt2);
			mutations++;
		}
	}
	else if (randInt >= 75){
		randInt = rand2(generator);
		if (randInt == (2 || 13)){
			randInt2 = rand4(generator) / 100.0;
			setY(randInt2);
			mutations++;
		}
		else if (randInt == 15)
		{
			randInt2 = rand4(generator) / 100.0;
			setX(randInt2);
			mutations++;
		}
	}
}

double Individual::fitness(){

	// Assesses the fitness of the Individual.
	double sum = x + y;
	double fitness = sum / 10;
	return fitness;
	
	// Inefficient way to calculate fitness.
	/*
	double sum = x + y;
	if (sum <= 2.0){
		return 0.25;
	}

	else if (sum <= 2.5){
		return 0.30;
	}

	else if (sum <= 3.5){
		return 0.40;
	}

	else if (sum <= 4.0){
		return 0.50;
	}

	else if (sum <= 5.0){
		return 0.60
	}

	else if (sum <= 6.0){
		return 0.70;
	}

	else if (sum <= 8.0){
		return 0.85;
	}

	else if (sum <= 9.0){
		return 0.90;
	}

	else if (sum <= 9.5 || sum < 10.0){
		return 0.99;
	}
	
	else if (sum >= 10.0){
		return 1.0;
	}

	else
		return 0.0;
	*/
}

void Individual::crossover(Individual& rhs){

	// Crossover swaps the x or y values of two Individuals.
	// If random number is 0 it will swap the x values
		// else (if its 1) it will swap the y values.
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> rand1(0, 7);

	double randInt = rand1(generator);
	if (randInt == 2){
		double tmpX = x;
		x = rhs.x;
		rhs.x = tmpX;
		crossovers++;
	}
	else if (randInt == 5)
	{
		double tmpY = y;
		y = rhs.y;
		rhs.y = tmpY;
		crossovers++;
	}

}

void Individual::printData(){

	// Prints out all the data of the Individual.
	std::cout 
		<< "==============" << std::endl
		<< "ID: " << ID << std::endl
		<< "X value: " << x << std::endl
		<< "Y value: " << y << std::endl
		<< "Fitness: " << fitness() << std::endl
		<< "Crossovers: " << crossovers << std::endl
		<< "Mutations: " << mutations << std::endl
		<< "Refreshes: " << refreshes << std::endl
	//	<< "==============" << std::endl
		<< std::endl;
}

int selectRandomID(){

	// Selects a random ID of an Individual.
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> rand1(0, ARRAY_SIZE - 1);
	int randID = rand1(generator);
	return randID;
}