#pragma once
#include "List.h"


namespace GameEngine
{
	class Component;
	class TransformComponent;

	class Entity
	{
	public:
		Entity();

		void start();
		void update(float deltaTime);
		void draw();
		void end();

		void addComponent(Component* component);

		template<typename T>
		T getComponent();

		virtual void onStart() {};
		virtual void onUpdate(float deltaTime) {};
		virtual void onEnd() {};

		bool getStarted() { return m_started; };
		TransformComponent* getTransform() { return m_transform; }
	private:
		bool m_started;
		TransformComponent* m_transform;
		List<Component*> m_components;
	};

	template<typename T>
	inline T Entity::getComponent()
	{
		T result;

		for (Component* component : m_components)
		{
			if (result = dynamic_cast<T>(component))
				break;
		}

		return nullptr;
	}
}
