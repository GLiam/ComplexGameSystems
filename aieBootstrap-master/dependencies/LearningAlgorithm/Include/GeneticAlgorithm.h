#include "Chromosomes.h"
#include <iostream>
#pragma once

template<typename T, int GENE_NUM, int POPULATION_NUM>
class GeneticAlgorithm
{
public:
	using ChromosomesType = Chromosomes<T, GENE_NUM>;

	GeneticAlgorithm() = delete;

	GeneticAlgorithm(float Mutation_Chance, float Mutation_Rate)
	{	
		MutateChance = Mutation_Chance;
		MutationRate = Mutation_Rate;
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
			Population.push_back(*m_Chromosomes);
			FitnessScore[i] = 0.1f;
			chromosomeCount++;
		}
	}

	void SortByFitness()
	{
		for (int i = 0; i < Population.size() - 1; i++)
		{
			for (int j = 0; j > Population.size() - i + 1; j++)
			{
				if (Population[j].getFitness() < Population[j + 1].getFitness())
				{
					std::swap(&Population[j], &Population[j + 1]);
				}
			}
		}
	}

	void FitnissEvaluation()
	{	
		PotentialParents = Population;
		Population.clear();

		for (int i = 0; i < PotentialParents.size(); i++)
		{
			int PotentialParent1 = rand() % POPULATION_NUM;
			int PotentialParent2 = rand() % POPULATION_NUM;
			int PotentialParent3 = rand() % POPULATION_NUM;
			int PotentialParent4 = rand() % POPULATION_NUM;

			if (PotentialParents[PotentialParent1].getFitness() >= PotentialParents[PotentialParent2].getFitness())
			{
				CrossOverParent.push_back(PotentialParents[PotentialParent1]);
			}
			else
			{
				CrossOverParent.push_back(PotentialParents[PotentialParent2]);
			}

			if (PotentialParents[PotentialParent3].getFitness() >= PotentialParents[PotentialParent4].getFitness())
			{
				CrossOverParent.push_back(PotentialParents[PotentialParent3]);
			}
			else
			{
				CrossOverParent.push_back(PotentialParents[PotentialParent4]);
			}

			ChromosomesType childOne;
			ChromosomesType childTwo;
			CrossOver(CrossOverParent[0].getChromosomes(), CrossOverParent[1].getChromosomes(), childOne.getChromosomes(), childTwo.getChromosomes());

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
			if(Population.size() > POPULATION_NUM)
			{
				Population.pop_back();
			}

		}
		PotentialParents.clear();
		CrossOverParent.clear();
	}

	void CrossOver(const std::vector<T>& parentOne, const std::vector<T>& parentTwo, std::vector<T>& childOne, std::vector<T>& childTwo)
	{
		int halfWayPoint = rand() % GENE_NUM;

		for (int i = 0; i < GENE_NUM; ++i)
		{
			if (i < halfWayPoint)
			{
				childOne.push_back(parentOne[i]);
				childTwo.push_back(parentTwo[i]);
				//m_Chromosomes->mutation(MutateChance, MutationRate);
			}
 			else
			{
				childOne.push_back(parentTwo[i]);
				childTwo.push_back(parentOne[i]);
				//m_Chromosomes->mutation(MutateChance, MutationRate);
			}
		}
	}

	void Mutate()
	{
		for (auto& chromosome : Population)
		{
			chromosome.mutation(MutateChance, MutationRate);
		}
	}

	std::vector<ChromosomesType>& getPopulation() { return Population; }

	float FitnessScore[POPULATION_NUM];
	//float getFitnessScore() { return FitnessScore[]; }
protected: 
	ChromosomesType* m_Chromosomes;
	std::vector<ChromosomesType> Population;
	std::vector<ChromosomesType> PotentialParents;
	std::vector<ChromosomesType> CrossOverParent;
	std::vector<T> GeneContainer;
	float MutationRate;
	float MutateChance;
};