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
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};