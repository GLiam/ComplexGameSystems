#include "Chromosomes.h"
#include <iostream>
#pragma once

template<typename T, int GENE_NUM, int POPULATION_NUM>
class GeneticAlgorithm
{
public:
	
	GeneticAlgorithm() = delete;

	GeneticAlgorithm(float Mutation_Rate, float CrossOver_Rate)
	{		
		m_Chromosomes = new Chromosomes<T, GENE_NUM>;
		//T Gene = m_Chromosomes->getChromosomes();
	}
	
	~GeneticAlgorithm()
	{
		delete m_Chromosomes;
	}

	void GeneratePopulation()
	{
		float chromosomeCount = 1;

		for (int i = 0; i < POPULATION_NUM; i++)
		{
			std::cout << "Chromosomes: " << chromosomeCount << std::endl;
			m_Chromosomes->GenerateChromosome();
			Population.push_back(m_Chromosomes->getChromosomes());
			FitnessScore[i] = 0.1f;
			chromosomeCount++;
		}
	}

	void FitnissFuction()
	{
		for(int i = 0; i < Population; i++)
		{
			
		}
	}

	void CrossOver(float CrossOver_Rate)
	{
		int PotentialParent1 = Population[rand() % Population.size()];
		int PotentialParent2 = Population[rand() % Population.size()];
		int PotentialParent3 = Population[rand() % Population.size()];
		int PotentialParent4 = Population[rand() % Population.size()];

		FirstCross

		Mutation(Mutation_Rate);
	}

	std::vector<std::vector<T>> getPopulation() { return Population; }

protected: 
	Chromosomes<T, GENE_NUM>* m_Chromosomes;
	std::vector<std::vector<T>> Population;
	float FitnessScore[POPULATION_NUM];
};