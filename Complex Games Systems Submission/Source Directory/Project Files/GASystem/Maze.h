#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "Directions.h"
namespace aie
{
	class Renderer2D;
}
class Maze
{
public:
	enum NodeType
	{
		Empty,
		Blocked,
		Start,
		End
	};
	struct MazePosition
	{
		int x;
		int y;
	};
	Maze(int width, int height);
	void GenerateMaze();
	void Render(aie::Renderer2D* renderer, glm::vec2 center, float nodeWidth);
	void RenderAtLocation(aie::Renderer2D* renderer, MazePosition position, glm::vec2 center, float nodeWidth, glm::vec3 colour);

	MazePosition getStartLocation() { return m_startLocation; }
	MazePosition getEndLocation() { return m_endLocation; }
	MazePosition FollowDirections(std::vector<DIRECTIONS> directionsToFollow);

private:
	std::vector<std::vector<NodeType>> m_maze;
	MazePosition m_startLocation;
	MazePosition m_endLocation;
	int m_width;
	int m_height;
};