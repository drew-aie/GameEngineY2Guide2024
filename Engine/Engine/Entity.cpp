#include "TransformComponent.h"
#include "Entity.h"

GameEngine::Entity::Entity()
{
	TransformComponent* transform = new TransformComponent();
	addComponent(transform);
	m_transform = transform;
}

void GameEngine::Entity::start()
{
	m_started = true;

	for (Component* component : m_components)
	{
		if (component->getEnabled())
			component->start();
	}

	onStart();
}

void GameEngine::Entity::update(double deltaTime)
{
	for (Component* component : m_components)
	{
		if (component->getEnabled())
			component->update(deltaTime);
	}
	onUpdate(deltaTime);
}

void GameEngine::Entity::fixedUpdate(float fixedDeltaTime)
{
	for (Component* component : m_components)
	{
		if (component->getEnabled())
			component->fixedUpdate(fixedDeltaTime);
	}

	onFixedUpdate(fixedDeltaTime);
}

void GameEngine::Entity::draw()
{
	for (Component* component : m_components)
	{
		if (component->getEnabled())
			component->draw();
	}
}

void GameEngine::Entity::end()
{
	for (Component* component : m_components)
	{
		component->end();
	}
	m_started = false;
	onEnd();
}
