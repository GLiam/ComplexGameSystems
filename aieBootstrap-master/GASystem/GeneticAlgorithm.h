#include "Chromosomes.h"
#include <iostream>
#pragma once

template<typename T,  int GENE_NUM, int POPULATION_NUM>
class GeneticAlgorithm
{
public:
	GeneticAlgorithm() {};

	Chromosomes<T, GENE_NUM>* m_Chromosomes;
	
	std::vector<T> getChromosomes() { return m_Chromosomes->chromosomes };
	
	void GeneratePopulation()
	{
		float chromosomeCount = 1;
		std::vector<T> ChromosomeList[POPULATION_NUM];
		//std::vector<T> test;

		for (int i = 0; i < POPULATION_NUM; i++)
		{
			std::cout << "Chromosomes" << chromosomeCount << std::endl;
			//test = m_Chromosomes->GenerateChromosome();
			m_Chromosomes->GenerateChromosome();
			//T test = m_Chromosomes->chromosomes;
			T ChromosomeList[i] = getChromosomes();
			//ChromosomeList[test];
			chromosomeCount++;
		}
		//Population = m_Chromosomes->chromosomes;
		T Population = ChromosomeList[POPULATION_NUM];
	}

	void FitnissFuction()
	{

	}

protected:
	std::vector<T> Population;
};

