#pragma once
#include "GameEngine/TransformComponent.h"

namespace GameGraphics
{
	class CircleComponent : public GameEngine::Component
	{
	public:
		void setColor(unsigned int color) { m_color = color; }
		unsigned int getColor() { return m_color; }

		void draw() override;

	private:
		float m_radius = 10;
		unsigned int m_color = 0XFFFFFFFF;
	};
}