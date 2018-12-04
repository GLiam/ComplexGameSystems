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
	};

	void GenerateChromosome()
	{
		chromosomes.clear();
		for (int CurrentChromosome = 0; CurrentChromosome < GENE_NUM; CurrentChromosome++)
		{
			T Rdirections = static_cast<T>(rand() % T::MAX_VALUE);
			chromosomes.push_back(Rdirections);
		}
	}

	void mutation(float mutation_chance, float mutate_rate)
	{
		//Calculate value from 0 to 1
		//if value is greater than mutation chance
		//return - no mutation
		float randomValue = rand() / (float)RAND_MAX;
		if (randomValue > mutation_chance) return;

		//For each gene
		//calculate value from 0 to 1
		//if value is greater than mutation rate
		//skip gene

		for (int i = 0; i < GENE_NUM; ++i)
		{
			float randomValue = rand() / (float)RAND_MAX;
			if (randomValue < mutate_rate)
			{
				T newGene = (T)(rand() % T::MAX_VALUE);
				chromosomes[i] = newGene;
			}
		}

		//int mutatedGene = rand() % GENE_NUM;
		//
		//if (mutate_rate <= mutation_chance)
		//{
		//	T newGene = (T)(rand() % T::MAX_VALUE);
		//	chromosomes.at(mutatedGene) = newGene;
		//}
	}

	std::vector<T>& getChromosomes() { return chromosomes; }	

	void setFitness(float fitness) { m_fitness = fitness; }
	float getFitness() const { return m_fitness; }

private:
	float m_fitness;
	std::vector<T> chromosomes;
};