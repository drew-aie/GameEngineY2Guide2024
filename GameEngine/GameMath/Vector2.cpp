#include "Vector2.h"
#include <cmath>

GameMath::Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

GameMath::Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

GameMath::Vector2 GameMath::Vector2::operator+(GameMath::Vector2 rhs)
{
	return GameMath::Vector2(x + rhs.x, y + rhs.y);
}

GameMath::Vector2 GameMath::Vector2::operator-(GameMath::Vector2 rhs)
{
	return GameMath::Vector2(x - rhs.x, y - rhs.y);
}

GameMath::Vector2 GameMath::Vector2::operator*(float scalar)
{
	return GameMath::Vector2(x * scalar, y * scalar);
}

GameMath::Vector2 GameMath::Vector2::operator/(float scalar)
{
	return GameMath::Vector2(x / scalar, y / scalar);
}

bool GameMath::Vector2::operator==(GameMath::Vector2 rhs)
{
	return x == rhs.x && y == rhs.y;
}

float GameMath::Vector2::getMagnitude()
{
	return sqrt(x * x + y * y);
}

GameMath::Vector2 GameMath::Vector2::getNormalized()
{
	return normalize(*this);
}

GameMath::Vector2 GameMath::Vector2::normalize(GameMath::Vector2 vector)
{
	if (vector.getMagnitude() == 0)
		return Vector2();

	return vector / vector.getMagnitude();
}

GameMath::Vector2 GameMath::Vector2::normalize()
{
	*this = normalize(*this);
	return *this;
}

float GameMath::Vector2::dotProduct(GameMath::Vector2 lhs, GameMath::Vector2 rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

float GameMath::Vector2::findAngle(GameMath::Vector2 lhs, GameMath::Vector2 rhs)
{
	lhs = normalize(lhs);
	rhs = normalize(rhs);

	//Use the dotproduct to find the angle the actor needs to rotate
	double dotProd = dotProduct(lhs, rhs);

	if (abs(dotProd) > 1)
		return 0;

	double angle = (double)acos(dotProd);

	//Find a perpindicular vector to the direction
	Vector2 perp = Vector2(rhs.y, -rhs.x);

	//Find the dot product of the perpindicular vector and the current forward
	double perpDot = dotProduct(perp, lhs);

	//If the result isn't 0, use it to change the sign of the angle to be either positive or negative
	if (perpDot != 0)
		angle *= perpDot / abs(perpDot);

	return angle;
}

GameMath::Vector2 GameMath::operator*(float scalar, GameMath::Vector2 lhs)
{
	return lhs * scalar;
}
