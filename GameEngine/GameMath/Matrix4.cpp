#include "Matrix4.h"
#include "Vector4.h"
#include "Vector3.h"
#include <cmath>

GameMath::Matrix4::Matrix4()
{
	m00 = 1.0f; m01 = 0.0f; m02 = 0.0f; m03 = 0.0f;
	m10 = 0.0f; m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
	m20 = 0.0f; m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
	m30 = 0.0f; m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
}

GameMath::Matrix4::Matrix4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
{
	this->m00 = m11; this->m01 = m12; this->m02 = m13; this->m03 = m14;
	this->m10 = m21; this->m11 = m22; this->m12 = m23; this->m13 = m24;
	this->m20 = m31; this->m21 = m32; this->m22 = m33; this->m23 = m34;
	this->m30 = m41; this->m31 = m42; this->m32 = m43; this->m33 = m44;
}

GameMath::Matrix4 GameMath::Matrix4::operator+(GameMath::Matrix4 rhs)
{
	return GameMath::Matrix4(
		m00 + rhs.m00, m01 + rhs.m01, m02 + rhs.m02, m03 + rhs.m03,
		m10 + rhs.m10, m11 + rhs.m11, m12 + rhs.m12, m13 + rhs.m13,
		m20 + rhs.m20, m21 + rhs.m21, m22 + rhs.m22, m23 + rhs.m23,
		m30 + rhs.m30, m31 + rhs.m31, m32 + rhs.m32, m33 + rhs.m33);
}

GameMath::Matrix4 GameMath::Matrix4::operator-(GameMath::Matrix4 rhs)
{
	return GameMath::Matrix4(
		m00 - rhs.m00, m01 - rhs.m01, m02 - rhs.m02, m03 - rhs.m03,
		m10 - rhs.m10, m11 - rhs.m11, m12 - rhs.m12, m13 - rhs.m13,
		m20 - rhs.m20, m21 - rhs.m21, m22 - rhs.m22, m23 - rhs.m23,
		m30 - rhs.m30, m31 - rhs.m31, m32 - rhs.m32, m33 - rhs.m33);
}

GameMath::Matrix4 GameMath::Matrix4::operator*(GameMath::Matrix4 rhs)
{
	return GameMath::Matrix4(
		m00 * rhs.m00 + m01 * rhs.m10 + m02 * rhs.m20 + m03 * rhs.m30,
		m00 * rhs.m01 + m01 * rhs.m11 + m02 * rhs.m21 + m03 * rhs.m31,
		m00 * rhs.m02 + m01 * rhs.m12 + m02 * rhs.m22 + m03 * rhs.m32,
		m00 * rhs.m03 + m01 * rhs.m13 + m02 * rhs.m23 + m03 * rhs.m33,
		m10 * rhs.m00 + m11 * rhs.m10 + m12 * rhs.m20 + m13 * rhs.m30,
		m10 * rhs.m01 + m11 * rhs.m11 + m12 * rhs.m21 + m13 * rhs.m31,
		m10 * rhs.m02 + m11 * rhs.m12 + m12 * rhs.m22 + m13 * rhs.m32,
		m10 * rhs.m03 + m11 * rhs.m13 + m12 * rhs.m23 + m13 * rhs.m33,
		m20 * rhs.m00 + m21 * rhs.m10 + m22 * rhs.m20 + m23 * rhs.m30,
		m20 * rhs.m01 + m21 * rhs.m11 + m22 * rhs.m21 + m23 * rhs.m31,
		m20 * rhs.m02 + m21 * rhs.m12 + m22 * rhs.m22 + m23 * rhs.m32,
		m20 * rhs.m03 + m21 * rhs.m13 + m22 * rhs.m23 + m23 * rhs.m33,
		m30 * rhs.m00 + m31 * rhs.m10 + m32 * rhs.m20 + m33 * rhs.m30,
		m30 * rhs.m01 + m31 * rhs.m11 + m32 * rhs.m21 + m33 * rhs.m31,
		m30 * rhs.m02 + m31 * rhs.m12 + m32 * rhs.m22 + m33 * rhs.m32,
		m30 * rhs.m03 + m31 * rhs.m13 + m32 * rhs.m23 + m33 * rhs.m33);
}

GameMath::Vector4 GameMath::Matrix4::operator*(GameMath::Vector4 rhs)
{
	return GameMath::Vector4(
		m00 * rhs.x + m01 * rhs.y + m02 * rhs.z + m03 * rhs.w,
		m10 * rhs.x + m11 * rhs.y + m12 * rhs.z + m13 * rhs.w,
		m20 * rhs.x + m21 * rhs.y + m22 * rhs.z + m23 * rhs.w,
		m30 * rhs.x + m31 * rhs.y + m32 * rhs.z + m33 * rhs.w);
}

bool GameMath::Matrix4::operator==(GameMath::Matrix4 rhs)
{
	return 
		m00 == rhs.m00 && m01 == rhs.m01 && m02 == rhs.m02 && m03 == rhs.m03 &&
		m10 == rhs.m10 && m11 == rhs.m11 && m12 == rhs.m12 && m13 == rhs.m13 &&
		m20 == rhs.m20 && m21 == rhs.m21 && m22 == rhs.m22 && m23 == rhs.m23 &&
		m30 == rhs.m30 && m31 == rhs.m31 && m32 == rhs.m32 && m33 == rhs.m33;
}

GameMath::Matrix4 GameMath::Matrix4::createRotationZ(float radians)
{
	return GameMath::Matrix4(
		cos(radians), -sin(radians), 0, 0,
		sin(radians), cos(radians), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

GameMath::Matrix4 GameMath::Matrix4::createRotationY(float radians)
{
	return GameMath::Matrix4(
		cos(radians), 0, sin(radians), 0,
		0, 1, 0, 0,
		-sin(radians), 0, cos(radians), 0,
		0, 0, 0, 1);
}

GameMath::Matrix4 GameMath::Matrix4::createRotationX(float radians)
{
	return GameMath::Matrix4(
		1, 0, 0, 0,
		0, cos(radians), -sin(radians), 0,
		0, sin(radians), cos(radians), 0,
		0, 0, 0, 1);
}

GameMath::Matrix4 GameMath::Matrix4::createTranslation(GameMath::Vector3 position)
{
	return GameMath::Matrix4(
		1, 0, 0, position.x,
		0, 1, 0, position.y,
		0, 0, 1, position.z,
		0, 0, 0, 1);
}

GameMath::Matrix4 GameMath::Matrix4::createScale(GameMath::Vector3 scale)
{
	return GameMath::Matrix4(
		scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		0, 0, 0, 1);
}
