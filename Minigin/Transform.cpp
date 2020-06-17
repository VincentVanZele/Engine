#include "MiniginPCH.h"
#include "Transform.h"

void proxy::Transform::SetPosition(const glm::vec3& newPos)
{
	mPosition = newPos;
}

void proxy::Transform::SetPosition(const float x, const float y, const float z)
{
	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;
}

const glm::vec2& proxy::Transform::GetScale() const
{
	return mScale;
}

void proxy::Transform::SetScale(const glm::vec2& scale)
{
	mScale = scale;
}

void proxy::Transform::SetScale(float x, float y)
{
	mScale.x = x;
	mScale.y = y;
}
