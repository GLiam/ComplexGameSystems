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
		chromosomes.clear();
		for (int CurrentChromosome = 0; CurrentChromosome < GENE_NUM; CurrentChromosome++)
		{
			chromosomes.push_back(static_cast<T>(rand() % T::MAX_VALUE));
			if(isFirstCreated)
			{
				Mutation();
			}
		}
	}

	void Mutation()
	{



		isFirstCreated = true;
	}

	std::vector<T> getChromosomes() { return chromosomes; }	

private:
	std::vector<T> chromosomes;
	bool isFirstCreated = false;
};

