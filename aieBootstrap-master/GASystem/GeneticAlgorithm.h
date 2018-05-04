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
			//std::cout << "Chromosomes: " << chromosomeCount << std::endl;
			m_Chromosomes->GenerateChromosome();
			Population.push_back(m_Chromosomes->getChromosomes());
			FitnessScore[i] = 0.1f;
			chromosomeCount++;
		}
	}

	void FitnissEvaluation()
	{	
	}

	void CrossOver(float CrossOver_Rate)
	{
		Parents = Population;
		Population.clear();

		bool attempt1;
		bool attempt2;
		bool attempt3;
		bool attempt4;

		for (int i = 0; i < 4; i++)
		{
			if (!attempt1)
			{
				auto PotentialParent1 = Parents.at(rand() % Parents.size());
			}
		}

		if (FitnessScore[] <= FitnessScore[])
		{
			CrossOverParent.push_back(PotentialParent1);
		}
		//else
		//	CrossOverParent.push_back(Parents.at(Parents[PotentialParent2]));

		//if (FitnessScore[PotentialParent3] <= FitnessScore[PotentialParent4])
		//{
		//	CrossOverParent.push_back(Parents.at(Parents[PotentialParent3]));
		//}
		//else
		//	CrossOverParent.push_back(Parents.at(Parents[PotentialParent4]));

		//Mutation(Mutation_Rate);

		FirstCross;

	}

	std::vector<std::vector<T>> getPopulation() { return Population; }

	float FitnessScore[POPULATION_NUM];
	//float getFitnessScore() { return FitnessScore[]; }
protected: 
	Chromosomes<T, GENE_NUM>* m_Chromosomes;
	std::vector<std::vector<T>> Population;
	std::vector<std::vector<T>> Parents;
	std::vector<std::vector<T>> CrossOverParent;
	std::vector<std::vector<T>> child;
};