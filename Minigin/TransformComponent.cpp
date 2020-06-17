#include "MiniginPCH.h"
#include "TransformComponent.h"
#include "Structs.h"
#include "GameObject.h"

proxy::TransformComponent::TransformComponent()
	: BaseComponent()
	, m_pChild(nullptr)
	
{
}

void proxy::TransformComponent::SetChildObject(GameObject* pGO)
{
	m_pChild = pGO;
}

void proxy::TransformComponent::SetPosition(Float2 pos)
{
	m_Position = pos;
}

proxy::Float2 proxy::TransformComponent::GetPosition() const
{
	return m_Position;
}

void proxy::TransformComponent::SetObjectPosition(Float2 pos)
{
	Translate(Float2(pos._x - GetObjectPosition()._x, pos._y - GetObjectPosition()._y));
}

proxy::Float2 proxy::TransformComponent::GetObjectPosition() const
{
	Float2 temp{};
	GameObject* tempObj{ m_pChild };

	while (tempObj)
	{
		temp._x += tempObj->GetTransform()->GetPosition()._x;
		temp._y += tempObj->GetTransform()->GetPosition()._y;

		tempObj = tempObj->GetParent();
	}

	return temp;
}

void proxy::TransformComponent::SetRotation(float rot)
{
	m_Rotation = rot;
}

float proxy::TransformComponent::GetRotation() const
{
	return m_Rotation;
}

void proxy::TransformComponent::SetObjectRotation(float rot)
{
	Rotate( rot - m_Rotation );
}

float proxy::TransformComponent::GetObjectRotation() const
{
	float temp{};
	GameObject* tempObj{ m_pChild };

	while (tempObj)
	{
		temp += tempObj->GetTransform()->GetRotation();

		tempObj = tempObj->GetParent();
	}

	return temp;
}

void proxy::TransformComponent::SetScale(Float2 sca)
{
	m_Scale = sca;
}

proxy::Float2 proxy::TransformComponent::GetScale() const
{
	return m_Scale;
}

void proxy::TransformComponent::SetObjectScale(Float2 sca)
{
	Scale(Float2(sca._x - m_Scale._x, sca._y - m_Scale._y));
}

proxy::Float2 proxy::TransformComponent::GetObjectScale() const
{
	Float2 temp{};
	GameObject* tempObj{ m_pChild };

	while (tempObj)
	{
		temp._x *= tempObj->GetTransform()->GetScale()._x;
		temp._y *= tempObj->GetTransform()->GetScale()._y;

		tempObj = tempObj->GetParent();
	}

	return temp;
}

void proxy::TransformComponent::Translate(const Float2& pos)
{
	m_Position._x += pos._x;
	m_Position._y += pos._y;
}

void proxy::TransformComponent::Rotate(float rot)
{
	m_Rotation += rot;
}

void proxy::TransformComponent::Scale(const Float2& sca)
{
	m_Scale._x += sca._x;
	m_Scale._y += sca._y;
}