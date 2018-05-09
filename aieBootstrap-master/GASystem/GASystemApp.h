#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "GeneticAlgorithm.h"
#include "Maze.h"
#include "Directions.h"

class GASystemApp : public aie::Application {
public:

	GASystemApp();
	virtual ~GASystemApp();


	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void Fitness();

protected:

	GeneticAlgorithm<DIRECTIONS, 20 , 5>	m_GeneticAlgorithm;
	aie::Renderer2D*						m_2dRenderer;
	aie::Font*								m_font;
	float									xPos;
	float									yPos;
	float									currentX;
	float									currentY;
	float									endposX = currentX;
	float									endposY = currentY;
	int										Time = 0;
	Maze									m_maze;
	std::vector<Maze::MazePosition>			position;
};