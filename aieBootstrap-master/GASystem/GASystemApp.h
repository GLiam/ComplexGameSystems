#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "GeneticAlgorithm.h"

enum DIRECTIONS
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NO_DIRECTION,
	MAX_VALUE
};

class GASystemApp : public aie::Application {
public:

	GASystemApp();
	virtual ~GASystemApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	GeneticAlgorithm<DIRECTIONS, 10, 10>	m_GeneticAlgorithm;
	aie::Renderer2D*						m_2dRenderer;
	aie::Font*								m_font;
};

//void Mutation(float Mutation_Rate)
//{
//	float Chance = rand() % 0.2;
//	float HighLowChance = rand() % 1;
//	T temp;
//	int MutatedGene = rand() % chromosomes.size();
//	temp = chromosomes[MutatedGene];
//	if (Chance <= Mutation_Rate)
//	{
//		if (HighLowChance == 1)
//		{
//			temp -= 1;
//		}
//		else
//		{
//			temp += 1;
//		}
//		chromosomes.at(MutatedGene) = temp;
//	}
//}