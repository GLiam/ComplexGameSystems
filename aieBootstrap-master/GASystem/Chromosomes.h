#include <list>
#include <iostream>
#include <vector>
#include <ctime>
#include "Gene.h"
#pragma once

template<typename T, int GENE_NUM>
class Chromosomes
{
public:
	Chromosomes() {};

	void GenerateChromosome()
	{
		chromosomes.clear();
		srand(time(NULL));
		for (int CurrentChromosome = 0; CurrentChromosome < GENE_NUM; CurrentChromosome++)
		{
			T temp = static_cast<T>(rand() % T::MAX_VALUE);
			chromosomes.push_back(temp);
		}
	}

	void mutation(float mutation_rate)
	{
		float chance = rand() % 0.2;
		float HighLowChance = rand() % 1;
		T temp;
		int Mutatedgene = rand() % chromosomes.size();
		temp = chromosomes[Mutatedgene];
		if (chance <= mutation_rate)
		{
			if (HighLowChance == 1)
			{
				temp -= 1;
			}
			else
			{
				temp += 1;
			}
			chromosomes.at(Mutatedgene) = temp;
		}
	}

	std::vector<T> getChromosomes() { return chromosomes; }	

private:
	std::vector<T> chromosomes;
};