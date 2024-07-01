#include "Engine.h"
#include <ctime>
#include "Scene.h"
#include "GameGraphics/Window.h"

void GameEngine::Engine::run()
{
	float lastTime = std::time(NULL);
	float deltaTime = 0;

	GameGraphics::Window window = GameGraphics::Window(800, 800, "Test Application");
	window.open();
	window.setTargetFrameRate(60);

	start();

	while (!window.shouldClose())
	{
		deltaTime = std::time(NULL) - lastTime;

		update(deltaTime);

		window.beginDrawing();
		draw();
		window.endDrawing();

		lastTime = std::time(NULL);
	}

	end();

	window.close();
}

void GameEngine::Engine::start()
{
	m_currentScene->start();
}

void GameEngine::Engine::update(float deltaTime)
{
	m_currentScene->update(deltaTime);
}

void GameEngine::Engine::draw()
{
	m_currentScene->draw();
}

void GameEngine::Engine::end()
{
	m_currentScene->end();
}
