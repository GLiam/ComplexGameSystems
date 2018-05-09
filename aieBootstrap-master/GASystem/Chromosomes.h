#include <list>
#include <iostream>
#include <vector>
#include <ctime>
#include "Directions.h"
#pragma once

template<typename T, int GENE_NUM>
class Chromosomes
{
public:
	Chromosomes() 
	{
		srand((unsigned int)time(nullptr));
	};

	void GenerateChromosome()
	{
		chromosomes.clear();
		//srand(time(NULL));
		for (int CurrentChromosome = 0; CurrentChromosome < GENE_NUM; CurrentChromosome++)
		{
			T temp = static_cast<T>(rand() % T::MAX_VALUE);
			chromosomes.push_back(temp);
		}
	}

	void mutation(float mutation_chance, float mutate_rate)
	{
		//Calculate value from 0 to 1
		//if value is greater than mutation chance
		//return - no mutation


		//For each gene
		//calculate value from 0 to 1
		//if value is greater than mutation rate
		//skip gene

		int mutatedGene = rand() % GENE_NUM;

		if (mutate_rate <= mutation_chance)
		{
			T newGene = (T)(rand() % T::MAX_VALUE);
			chromosomes.at(mutatedGene) = newGene;
		}
	}

	std::vector<T>& getChromosomes() { return chromosomes; }	

	void setFitness(float fitness) { m_fitness = fitness; }
	float getFitness() const { return m_fitness; }

private:
	float m_fitness;
	std::vector<T> chromosomes;
};