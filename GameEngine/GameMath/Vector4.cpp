#include "Vector4.h"
#include <cmath>

GameMath::Vector4::Vector4()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

GameMath::Vector4::Vector4(float x, float y, float z, float w)
{
    this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

GameMath::Vector4 GameMath::Vector4::operator+(GameMath::Vector4 rhs)
{
    return GameMath::Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

GameMath::Vector4 GameMath::Vector4::operator-(GameMath::Vector4 rhs)
{
    return GameMath::Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

GameMath::Vector4 GameMath::Vector4::operator*(float scalar)
{
    return GameMath::Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

GameMath::Vector4 GameMath::Vector4::operator/(float scalar)
{
    return GameMath::Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

bool GameMath::Vector4::operator==(GameMath::Vector4 rhs)
{
    return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

float GameMath::Vector4::getMagnitude()
{
    return sqrt(x * x + y * y + z * z + w * w);
}

GameMath::Vector4 GameMath::Vector4::getNormalized()
{
    return normalize(*this);
}

GameMath::Vector4 GameMath::Vector4::normalize(GameMath::Vector4 vector)
{
    if (vector.getMagnitude() == 0)
        return GameMath::Vector4();

    return vector / vector.getMagnitude();
}

GameMath::Vector4 GameMath::Vector4::normalize()
{
    *this = normalize(*this);
    return *this;
}

float GameMath::Vector4::dotProduct(GameMath::Vector4 lhs, GameMath::Vector4 rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

GameMath::Vector4 GameMath::Vector4::crossProduct(GameMath::Vector4 lhs, GameMath::Vector4 rhs)
{
    return GameMath::Vector4(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x, 0.0f);
}

GameMath::Vector4 GameMath::operator*(float scalar, GameMath::Vector4 lhs)
{
    return lhs * scalar;
}
