#include "Vector3.h"
#include <cmath>

GameMath::Vector3::Vector3()
{
    x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

GameMath::Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
	this->y = y;
	this->z = z;
}

GameMath::Vector3 GameMath::Vector3::operator+(GameMath::Vector3 rhs)
{
    return GameMath::Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

GameMath::Vector3 GameMath::Vector3::operator-(GameMath::Vector3 rhs)
{
    return GameMath::Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

GameMath::Vector3 GameMath::Vector3::operator*(float scalar)
{
    return GameMath::Vector3(x * scalar, y * scalar, z * scalar);
}

GameMath::Vector3 GameMath::Vector3::operator/(float scalar)
{
    return GameMath::Vector3(x / scalar, y / scalar, z / scalar);
}

bool GameMath::Vector3::operator==(GameMath::Vector3 rhs)
{
    return x == rhs.x && y == rhs.y && z == rhs.z;
}

float GameMath::Vector3::getMagnitude()
{
    return sqrt(x * x + y * y + z * z);
}

GameMath::Vector3 GameMath::Vector3::getNormalized()
{
    return normalize(*this);
}

GameMath::Vector3 GameMath::Vector3::normalize(GameMath::Vector3 vector)
{
    if (vector.getMagnitude() == 0)
		return GameMath::Vector3();

    return vector / vector.getMagnitude();
}

GameMath::Vector3 GameMath::Vector3::normalize()
{
    *this = normalize(*this);
    return *this;
}

float GameMath::Vector3::dotProduct(GameMath::Vector3 lhs, GameMath::Vector3 rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

GameMath::Vector3 GameMath::Vector3::crossProduct(GameMath::Vector3 lhs, GameMath::Vector3 rhs)
{
    return GameMath::Vector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}

GameMath::Vector3 GameMath::operator*(float scalar, GameMath::Vector3 lhs)
{
    return lhs * scalar;
}
