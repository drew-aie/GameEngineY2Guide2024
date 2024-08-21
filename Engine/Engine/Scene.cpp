#include "Scene.h"
#include "Entity.h"

void GameEngine::Scene::start()
{
	for (Entity* entity : m_entities)
	{
		entity->start();
	}

	onStart();
}

void GameEngine::Scene::update(double deltaTime)
{
	for (Entity* entity : m_entities)
	{
		if (!entity->getStarted())
			entity->start();

		entity->update(deltaTime);
	}

	

	onUpdate(deltaTime);
}

void GameEngine::Scene::fixedUpdate(float fixedDeltaTime)
{
	for (Entity* entity : m_entities)
	{
		entity->fixedUpdate(fixedDeltaTime);
	}

	onFixedUpdate(fixedDeltaTime);

}

void GameEngine::Scene::draw()
{
	for (Entity* entity : m_entities)
	{
		entity->draw();
	}

	onDraw();
}

void GameEngine::Scene::end()
{
	for (Entity* entity : m_entities)
	{
		entity->end();
	}

	onEnd();
}
