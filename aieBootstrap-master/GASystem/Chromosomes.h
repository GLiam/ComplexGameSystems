#include <list>
#include <iostream>
#include <vector>
#include "Gene.h"
#pragma once

//enum Directions
//{
//	UP,
//	DOWN,
//	LEFT,
//	RIGHT,
//	NO_DIRECTION,
//};

template<typename T, int GENE_NUM>
class Chromosomes
{
public:
	Chromosomes() {};

	//void setfitness();
	//void getfitness();

	void GenerateChromosome()
	{
		T Genes[GENE_NUM];
		for (int CurrentChromosome = 0; CurrentChromosome < GENE_NUM; CurrentChromosome++)
		{
			Genes[CurrentChromosome] = static_cast<T>(rand() % T::MAX_VALUE);
			std::cout << Genes[CurrentChromosome] << std::endl;
		}
		T chromosomes = Genes[GENE_NUM];
	}

	

protected:
	std::vector<T> chromosomes;
	int ChromosomePopulationSize;
	int GenerationSurvivorCount;
};

