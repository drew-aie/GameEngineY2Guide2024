#pragma once
#include "List.h"
#include "Entity.h"

namespace GameEngine
{

	class Scene
	{
	public:
		Scene() { m_entities = List<Entity*>(); }

		void start();
		void update(double deltaTime);
		void fixedUpdate(float fixedDeltaTime);
		void draw();
		void end();

		virtual void onStart() {};
		virtual void onUpdate(double deltaTime) {};
		virtual void onFixedUpdate(float fixedDeltaTime) {};
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