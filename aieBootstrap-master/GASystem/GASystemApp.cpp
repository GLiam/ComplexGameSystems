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

	Fitness(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void GASystemApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->drawCircle(xPos, yPos, 20, 0);
	// draw your stuff here!
	
	// output some text, uses the last used colour
	//m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

void GASystemApp::Fitness(float DeltaTime)
{
	auto Pop = m_GeneticAlgorithm.getPopulation();
	for (auto& Dir : Pop)
	{
		for (auto& gene : Dir)
		{
			switch (gene)
			{
				case DIRECTIONS::UP:
					yPos += 10 * DeltaTime;
					break;
				case DIRECTIONS::DOWN:
					yPos -= 10 * DeltaTime;
					break;
				case DIRECTIONS::LEFT:
					xPos -= 10 * DeltaTime;
					break;
				case DIRECTIONS::RIGHT:
					xPos += 10 * DeltaTime;
					break;
				case DIRECTIONS::NO_DIRECTION:
					"NO";
					break;
				default:
					break;
			}
		}
	}
}