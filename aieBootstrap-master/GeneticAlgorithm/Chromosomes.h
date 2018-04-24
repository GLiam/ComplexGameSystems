#include <list>
#include <iostream>
#include "Gene.h"
#pragma once
class Chromosomes
{
public:
	Chromosomes();
	~Chromosomes();
	
	void GenerateChromosome();

	void setfitness();
	void getfitness();


	std::list<Chromosomes> chromosomePopulation;
protected:
	int ChromosomePopulationSize;
	int GenerationSurvivorCount;
};

