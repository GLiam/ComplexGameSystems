#include "GASystemApp.h"
#include "Texture.h"
#include "Input.h"
#include "GeneticAlgorithm.h"

GASystemApp::GASystemApp()
	: m_GeneticAlgorithm(0.1f, 0.5f)
{
	//m_GeneticAlgorithm.setMutationRate(0.1f);
}

GASystemApp::~GASystemApp() {

}


//template<typename T>
bool GASystemApp::startup() {

	m_2dRenderer = new aie::Renderer2D();

	xPos = 250;
	yPos = 500;
	int currentX = xPos;
	int currentY = yPos;


	///Genetic Algorithm START
	m_GeneticAlgorithm.GeneratePopulation();

	return true;
}

void GASystemApp::shutdown() {

	//delete m_font;
	delete m_2dRenderer;
}

void GASystemApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	Fitness();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void GASystemApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//auto Population = m_GeneticAlgorithm.getPopulation();
	//for (auto& Individual : Population)
	//{
	//}

	//Indervidual
	m_2dRenderer->drawBox(xPos, yPos, 20, 20);
	m_2dRenderer->drawLine(250, 500, xPos, yPos);

	//Left
	m_2dRenderer->drawCircle(250, 500, 10);
	m_2dRenderer->drawCircle(250, 400, 10);
	m_2dRenderer->drawCircle(250, 300, 10);
	m_2dRenderer->drawCircle(250, 200, 10);
	m_2dRenderer->drawCircle(250, 100, 10);

	//Center Left
	m_2dRenderer->drawCircle(350, 500, 10);
	m_2dRenderer->drawCircle(350, 400, 10);
	m_2dRenderer->drawCircle(350, 300, 10);
	m_2dRenderer->drawCircle(350, 200, 10);
	m_2dRenderer->drawCircle(350, 100, 10);

	//Center
	m_2dRenderer->drawCircle(450, 500, 10);
	m_2dRenderer->drawCircle(450, 400, 10);
	m_2dRenderer->drawCircle(450, 300, 10);
	m_2dRenderer->drawCircle(450, 200, 10);
	m_2dRenderer->drawCircle(450, 100, 10);

	//Center Right
	m_2dRenderer->drawCircle(550, 500, 10);
	m_2dRenderer->drawCircle(550, 400, 10);
	m_2dRenderer->drawCircle(550, 300, 10);
	m_2dRenderer->drawCircle(550, 200, 10);
	m_2dRenderer->drawCircle(550, 100, 10);

	//Right
	m_2dRenderer->drawCircle(650, 500, 10);
	m_2dRenderer->drawCircle(650, 400, 10);
	m_2dRenderer->drawCircle(650, 300, 10);
	m_2dRenderer->drawCircle(650, 200, 10);
	m_2dRenderer->drawCircle(650, 100, 10);

	//m_2dRenderer->drawCircle(xPos, yPos, 20, 0);
	// draw your stuff here!
	
	// output some text, uses the last used colour
	//m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

void GASystemApp::Fitness()
{
	auto Pop = m_GeneticAlgorithm.getPopulation();
	int i = 0;
	m_GeneticAlgorithm.FitnessScore[i];
	m_2dRenderer->setRenderColour(1, 0.5f, 0, 1.0f);
	for (auto& Dir : Pop)
	{
		for (auto& gene : Dir)
		{
			switch (gene)
			{
			case DIRECTIONS::UP:
				yPos += 0.3f;
				std::cout << " UP " << std::endl;
				m_2dRenderer->drawLine(currentX, currentY, xPos, yPos, 1, 0);
				//m_GeneticAlgorithm.FitnessScore[i] += 1;
				break;
			case DIRECTIONS::DOWN:
				yPos -= 0.3f;
				std::cout << " DOWN " << std::endl;
				m_2dRenderer->drawLine(currentX, currentY, xPos, yPos, 1, 0);
				//m_GeneticAlgorithm.FitnessScore[i] += 1;
				break;
			case DIRECTIONS::LEFT:
				xPos -= 0.3f;
				std::cout << " LEFT " << std::endl;
				m_2dRenderer->drawLine(currentX, currentY, xPos, yPos, 1, 0);
				//m_GeneticAlgorithm.FitnessScore[i] += 1;
				break;
			case DIRECTIONS::RIGHT:
				xPos += 0.3f;
				std::cout << " RIGHT " << std::endl;
				m_2dRenderer->drawLine(currentX, currentY, xPos, yPos, 1, 0);
				//m_GeneticAlgorithm.FitnessScore[i] += 1;
				break;
			case DIRECTIONS::NO_DIRECTION:
				std::cout << " NO DIRECTION " << std::endl;
				break;
			default:
				break;
			}
		}
		i++;
	}
	m_GeneticAlgorithm.FitnissEvaluation();
}