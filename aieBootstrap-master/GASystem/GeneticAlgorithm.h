#include "Chromosomes.h"
#include <iostream>
#pragma once

template<typename T,  int GENE_NUM, int POPULATION_NUM>
class GeneticAlgorithm
{
public:
	
	GeneticAlgorithm() 
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
		//std::vector<T> ChromosomeList[POPULATION_NUM];
		//std::vector<T> test;

		for (int i = 0; i < POPULATION_NUM; i++)
		{
			std::cout << "Chromosomes: " << chromosomeCount << std::endl;
			m_Chromosomes->GenerateChromosome();
			Population.push_back(m_Chromosomes->getChromosomes());
			chromosomeCount++;
		}
	}

	void FitnissFuction()
	{
		for(int i = 0; i < Population; i++)
		{
			
		}
	}

	void CrossOver()
	{

	}

protected:
	Chromosomes<T, GENE_NUM>* m_Chromosomes;
	std::vector<std::vector<T>> Population;
};