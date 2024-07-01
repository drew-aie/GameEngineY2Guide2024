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

void GameEngine::Entity::update(float deltaTime)
{
	for (Component* component : m_components)
	{
		if (component->getEnabled())
			component->update(deltaTime);
	}
	onUpdate(deltaTime);
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

void GameEngine::Entity::addComponent(Component* component)
{
	component->setOwner(this);
	m_components.add(component);
}
