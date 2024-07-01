#pragma once

namespace GameEngine 
{
	class Scene;

	class Engine
	{
	public:
		Engine() {};
		void run();

		static float getDeltaTime() { return m_deltaTime; }

		void setCurrentScene(Scene* scene) { m_currentScene = scene; }
		Scene* getCurrentScene() { return m_currentScene; }

	private:
		void start();
		void update(float deltaTime);
		void draw();
		void end();

		Scene* m_currentScene;

		static float m_deltaTime;
	};
}