// _______________
// Sienna HPP File
//______________________________
// Created by Benjamin Walko
// First Working Copy: 9/28/2016 (Revision 1.0)
// 
// Revision 1.1
// Last Updated: 10/3/2016
// 

#include <iostream>
#include <random>

const int ARRAY_SIZE = 16;

class Individual{
public:
	Individual();

	void setX(double);
	void setY(double);
	void setID(int);
	int getID();
	double getX();
	double getY();
	double randomGen();
	void mutate();
	double fitness();
	void printData();
	void crossover(Individual&);
	void addRefresh() { refreshes++; }

private:
	double x, y, fitNum;
	int ID, mutations, crossovers, refreshes;
};

int selectRandomID();
