#include "CircleComponent.h"
#include "GameEngine/TransformComponent.h"
#include <raylib.h>

void GameGraphics::CircleComponent::draw()
{
	GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();

	Color color = RAYLIB_H::GetColor(m_color);

	RAYLIB_H::DrawCircle(position.x, position.y, m_radius, color);
}
