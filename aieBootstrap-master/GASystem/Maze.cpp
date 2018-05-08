#include "Maze.h"
#include <Renderer2D.h>
#include <iostream>

Maze::Maze(int width, int height)
	: m_width(width)
	, m_height(height)
{
	

}

void Maze::GenerateMaze()
{
	m_maze.resize(m_width);
	for (int x = 0; x < m_width; ++x)
	{
		m_maze[x].resize(m_height);
		for (int y = 0; y < m_height; ++y)
		{
			int random = rand() % 1000;
			if (random < 100)
			{
				m_maze[x][y] = NodeType::Blocked;
			}
			else
			{
				m_maze[x][y] = NodeType::Empty;
			}
		}
	}

	int startX = rand() % m_width;
	int startY = rand() % m_height;
	m_maze[startX][startY] = NodeType::Start;
	m_startLocation.x = startX;
	m_startLocation.y = startY;

	int endX;
	int endY;
	do
	{
		endX = rand() % m_width;
		endY = rand() % m_height;
	} while (endX == startX && endY == startY);

	m_maze[endX][endY] = NodeType::End;
	m_endLocation.x = endX;
	m_endLocation.y = endY;
}

void Maze::Render(aie::Renderer2D * renderer, glm::vec2 center, float nodeWidth)
{
	glm::vec2 drawLocation = center;
	drawLocation.x -= (m_width / 2) * nodeWidth;
	drawLocation.y += (m_height / 2)* nodeWidth;
	for (int x = 0; x < m_width; ++x)
	{
		float baseYDrawLocation = drawLocation.y;
		for (int y = 0; y < m_height; ++y)
		{
			switch (m_maze[x][y])
			{
			case Empty:
				renderer->setRenderColour(1.0f, 1.0f, 1.0f);
				break;
			case Blocked:
				renderer->setRenderColour(1.0f, 0.0f, 0.0f);
				break;
			case Start:
				renderer->setRenderColour(0.0f, 1.0f, 0.0f);
				break;
			case End:
				renderer->setRenderColour(0.0f, 0.0f, 1.0f);
				break;
			default:
				renderer->setRenderColour(1.0f, 0.0f, 1.0f);
				break;
			}

			renderer->drawBox(drawLocation.x, drawLocation.y, nodeWidth, nodeWidth);
			drawLocation.y -= nodeWidth;
		}
		drawLocation.y = baseYDrawLocation;
		drawLocation.x += nodeWidth;
	}
}

Maze::MazePosition Maze::FollowDirections(std::vector<DIRECTIONS> directionsToFollow)
{
	MazePosition currentLocation = getStartLocation();

	for (DIRECTIONS& direction : directionsToFollow)
	{
 		switch (direction)
		{
		case DIRECTIONS::UP:
			std::cout << " UP " << std::endl;
			if (currentLocation.y >= m_height || currentLocation.y <= 0)
			{
				break;
			}
			else if (currentLocation.y <= m_height && m_maze[currentLocation.x][currentLocation.y - 1] != NodeType::Blocked)
			{
				currentLocation.y -= 1;
			}
			break;
		case DIRECTIONS::DOWN:
			std::cout << " DOWN " << std::endl;
			if (currentLocation.y >= m_height || currentLocation.y <= 0)
			{
				break;
			}
			else if (currentLocation.y <= m_height && m_maze[currentLocation.x][currentLocation.y + 1] != NodeType::Blocked)
			{
				currentLocation.y += 1;
			}
			break;
		case DIRECTIONS::LEFT:
			std::cout << " LEFT " << std::endl;
			if (currentLocation.x >= m_width || currentLocation.x <= 0)
			{
				break;
			}
			else if (currentLocation.x <= m_width && m_maze[currentLocation.x - 1][currentLocation.y] != NodeType::Blocked)
			{
				currentLocation.x -= 1;
			}
			break;
		case DIRECTIONS::RIGHT:
			std::cout << " RIGHT " << std::endl;
			if (currentLocation.x >= m_width || currentLocation.x <= 0)
			{
				break;
			}
			else if (currentLocation.x <= m_width && m_maze[currentLocation.x + 1][currentLocation.y] != NodeType::Blocked)
			{
				currentLocation.x += 1;
			}
			break;
		case DIRECTIONS::NO_DIRECTION:
			std::cout << " NO DIRECTON " << std::endl;
			break;
		default:
			break;
		}
	}
	std::cout << " end of geneom " << std::endl;
	m_finalLocation = currentLocation;
	return m_finalLocation;
}

void Maze::RenderAtLocation(aie::Renderer2D* renderer, MazePosition position, glm::vec2 center, float nodeWidth, glm::vec3 colour) 
{
	glm::vec2 drawLocation = center;
	drawLocation.x -= (m_width / 2) * nodeWidth;
	drawLocation.x += (nodeWidth * position.x);
	drawLocation.y += (m_height / 2)* nodeWidth;
	drawLocation.y -= (nodeWidth * position.y);

	renderer->setRenderColour(colour.r, colour.g, colour.b);
	renderer->drawBox(drawLocation.x, drawLocation.y, nodeWidth, nodeWidth);
}