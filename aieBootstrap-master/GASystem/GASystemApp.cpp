#include "GASystemApp.h"
#include "Texture.h"
#include "Input.h"
#include "GeneticAlgorithm.h"

GASystemApp::GASystemApp()
	: m_GeneticAlgorithm(1, 5)
	, m_maze(20, 20)
{

	//m_GeneticAlgorithm.setMutationRate(0.1f);
}

GASystemApp::~GASystemApp() {

}

bool GASystemApp::startup() {

	//srand((unsigned int)time(nullptr));
	srand(10);


	m_maze.GenerateMaze();
	m_GeneticAlgorithm.GeneratePopulation();

	m_2dRenderer = new aie::Renderer2D();

	//std::vector<DIRECTIONS> demo;
	//demo.push_back(DIRECTIONS::DOWN);
	//demo.push_back(DIRECTIONS::DOWN);
	//demo.push_back(DIRECTIONS::RIGHT);
	//demo.push_back(DIRECTIONS::RIGHT);
	//demo.push_back(DIRECTIONS::UP);
	//demo.push_back(DIRECTIONS::UP);
	//demo.push_back(DIRECTIONS::UP);
	/*p = m_maze.FollowDirections(demo);*/

	///Genetic Algorithm START

	return true;
}

void GASystemApp::shutdown() {

	//delete m_font;
	delete m_2dRenderer;
}

void GASystemApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		Fitness();
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void GASystemApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_maze.Render(m_2dRenderer, { getWindowWidth() * 0.5f, getWindowHeight() * 0.5f }, 30);

	for(int i = 0; i < position.size(); i++)
	{
		m_maze.RenderAtLocation(m_2dRenderer, position[i], { getWindowWidth() * 0.5f, getWindowHeight() * 0.5f }, 30, { 1.0f, 0.5f, 1.0f });
	}

	// done drawing sprites
	m_2dRenderer->end();
}

void GASystemApp::Fitness()
{
	auto Pop = m_GeneticAlgorithm.getPopulation();
	position.clear();
	for (auto& dir : Pop)
	{
		Maze::MazePosition finalPos = m_maze.FollowDirections(dir.getChromosomes());
		
		Maze::MazePosition endPos = m_maze.getEndLocation();

		float xDist = (float)(endPos.x - finalPos.x);
		float yDist = (float)(endPos.y - finalPos.y);
		float distance = glm::sqrt(xDist * xDist + yDist * yDist);
		
		dir.setFitness(-distance);
		position.push_back(finalPos);
	}
	//m_GeneticAlgorithm.SortByFitness();
	m_GeneticAlgorithm.FitnissEvaluation();
}