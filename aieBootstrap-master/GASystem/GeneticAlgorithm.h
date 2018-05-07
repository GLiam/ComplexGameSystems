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
		PotentialParents = Population;
		Population.clear();

		for (int i = 0; i < PotentialParents.size(); i++)
		{
			int PotentialParent1 = rand() % PotentialParents.size();
			int PotentialParent2 = rand() % PotentialParents.size();
			int PotentialParent3 = rand() % PotentialParents.size();
			int PotentialParent4 = rand() % PotentialParents.size();

			if (FitnessScore[PotentialParent1] <= FitnessScore[PotentialParent2])
			{
				CrossOverParent.push_back(PotentialParents[PotentialParent1]);
			}
			else
			{
				CrossOverParent.push_back(PotentialParents[PotentialParent2]);
			}

			if (FitnessScore[PotentialParent3] <= FitnessScore[PotentialParent4])
			{
				CrossOverParent.push_back(PotentialParents[PotentialParent3]);
			}
			else
			{
				CrossOverParent.push_back(PotentialParents[PotentialParent4]);
			}
			std::vector<T> childOne;
			std::vector<T> childTwo;
			CrossOver(CrossOverParent[0], CrossOverParent[1], childOne, childTwo);

			//Store childOne, childTwo in the general population
			if (Population.size() < POPULATION_NUM)
			{
				Population.push_back(childOne);
				Population.push_back(childTwo);
			}
			else
			{
				break;
			}
		}
		PotentialParents.clear();
		CrossOverParent.clear();
	}

	void CrossOver(const std::vector<T>& parentOne, const std::vector<T>& parentTwo, std::vector<T>& childOne, std::vector<T>& childTwo)
	{
		int halfWayPoint = GENE_NUM / 2;

		for (int i = 0; i < GENE_NUM; ++i)
		{
			if (i < halfWayPoint)
			{
				childOne.push_back(parentOne[i]);
				childTwo.push_back(parentTwo[i]);
			}
			else
			{
				childOne.push_back(parentTwo[i]);
				childTwo.push_back(parentOne[i]);
			}
		}
	}

	std::vector<std::vector<T>> getPopulation() { return Population; }

	float FitnessScore[POPULATION_NUM];
	//float getFitnessScore() { return FitnessScore[]; }
protected: 
	Chromosomes<T, GENE_NUM>* m_Chromosomes;
	std::vector<std::vector<T>> Population;
	std::vector<std::vector<T>> PotentialParents;
	std::vector<std::vector<T>> CrossOverParent;
	std::vector<T> GeneContainer;
};

//Parents = Population;
//Population.clear();
//bool attempt1;
//bool attempt2;
//bool attempt3;
//bool attempt4;
//for (int i = 0; i < 4; i++)
//{
//	if (!attempt1)
//	{
//		auto PotentialParent1 = Parents.at(rand() % Parents.size());
//	}
//}
//if (FitnessScore[] <= FitnessScore[])
//{
//	CrossOverParent.push_back(PotentialParent1);
//}
////else
////	CrossOverParent.push_back(Parents.at(Parents[PotentialParent2]));
////if (FitnessScore[PotentialParent3] <= FitnessScore[PotentialParent4])
////{
////	CrossOverParent.push_back(Parents.at(Parents[PotentialParent3]));
////}
////else
////	CrossOverParent.push_back(Parents.at(Parents[PotentialParent4]));