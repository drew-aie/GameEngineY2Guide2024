#pragma once
#include "List.h"

namespace GameEngine
{
	class Entity;

	class Scene
	{
	public:
		Scene() { m_entities = List<Entity*>(); }

		void start();
		void update(float deltaTime);
		void draw();
		void end();

		virtual void onStart() {};
		virtual void onUpdate(float deltaTime) {};
		virtual void onDraw() {}
		virtual void onEnd() {};

		void addEntity(Entity* entity)
		{
			m_entities.add(entity);
		}
		void removeEntity(Entity* entity) { m_entities.remove(entity); }

	private:

		List<Entity*> m_entities;
	};

}