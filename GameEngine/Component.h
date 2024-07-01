#pragma once

#include "Entity.h"

namespace GameEngine
{
	class Component
	{
	public:
		Component() { m_enabled = true; };

		virtual void start() {};
		virtual void update(float deltaTime) {};
		virtual void draw() {};
		virtual void end() {};

		bool getEnabled() { return m_enabled; }
		void setEnabled(bool enabled) { m_enabled = enabled; }

		Entity* getOwner() { return m_owner; }
		void setOwner(Entity* entity) { m_owner = entity; }

	private:

		bool m_enabled;
		Entity* m_owner;
	};
}