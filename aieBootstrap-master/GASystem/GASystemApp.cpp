#include "GASystemApp.h"
#include "Texture.h"
#include "Input.h"
#include "GeneticAlgorithm.h"

GASystemApp::GASystemApp()
	: m_GeneticAlgorithm(0.1f, 0.5f)
	, m_maze(20, 20)
{

	//m_GeneticAlgorithm.setMutationRate(0.1f);
}

GASystemApp::~GASystemApp() {

}

bool GASystemApp::startup() {

	//srand((unsigned int)time(nullptr));
	srand(5);

	m_maze.GenerateMaze();
	m_GeneticAlgorithm.GeneratePopulation();

	m_2dRenderer = new aie::Renderer2D();
	xPos = 250;
	yPos = 500;
	int currentX = xPos;
	int currentY = yPos;

	Fitness();

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

	m_maze.RenderAtLocation(m_2dRenderer, position, { getWindowWidth() * 0.5f, getWindowHeight() * 0.5f }, 30, { 1.0f, 0.5f, 1.0f });
	// done drawing sprites
	m_2dRenderer->end();
}

void GASystemApp::Fitness()
{
	auto Pop = m_GeneticAlgorithm.getPopulation();
	for (auto& dir : Pop)
	{
		m_maze.FollowDirections(dir);
	}
	position = m_maze.getFinalLocation();

	//int i = 0;
	//float position;
	//float endpos;
	//float distance;
	//float fit;
	//position = xPos + yPos;
	//endpos = endposX + endposY;
	//distance = position - endpos;
	//fit = distance;
	//m_GeneticAlgorithm.FitnessScore[i] = -fit;
	//m_GeneticAlgorithm.FitnissEvaluation();
}