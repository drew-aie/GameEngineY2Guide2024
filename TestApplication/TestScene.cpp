#include "TestScene.h"
#include "GameEngine/Entity.h"
#include "GameGraphics/CircleComponent.h"

void TestScene::onStart()
{
	GameEngine::Entity* circle = new GameEngine::Entity();
	circle->addComponent(new GameGraphics::CircleComponent());
	circle->getTransform()->setLocalPosition({ 100,100,0 });
	addEntity(circle);
}
