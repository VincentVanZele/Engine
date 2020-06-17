#include "MiniginPCH.h"
#include "SpriteComponent.h"
#include "Animation.h"
#include "Renderer.h"
#include "GameTime.h"
#include "Texture2D.h"

#include "GameObject.h"

proxy::SpriteComponent::SpriteComponent()
	:BaseComponent()
	, m_deltaTime{ 0.0f }
{
}

void proxy::SpriteComponent::Update()
{
	m_deltaTime += GameTime::GetInstance().GetDeltaTime();

	m_ActiveSprite->Update(m_deltaTime);
}

void proxy::SpriteComponent::Draw()
{
	m_ActiveSprite->Draw();
}

void proxy::SpriteComponent::AddAnimation(std::shared_ptr<Animation> sprite)
{
	m_vSprites.push_back(sprite);
}

void proxy::SpriteComponent::RemoveAnimation(const std::string& name)
{
	for (auto sprite : m_vSprites)
	{
		if (sprite->CheckName(name))
		{
			m_vSprites.erase(
				std::remove(m_vSprites.begin(), m_vSprites.end()
				, sprite)
				, m_vSprites.end()
			);
			return;
		}
	}
}

void proxy::SpriteComponent::RemoveAllAnimations()
{
	for (auto sprite : m_vSprites)
	{
		m_vSprites.erase(
			std::remove(m_vSprites.begin(), m_vSprites.end()
			, sprite)
			, m_vSprites.end()
		);
	}
}

void proxy::SpriteComponent::SetActiveAnimation(const std::string& name)
{
	if (m_ActiveSprite)
	{
		if (m_ActiveSprite->CheckName(name))
		{
			return;
		}
	}

	for (auto sprite : m_vSprites)
	{
		if (sprite->CheckName(name))
		{
			m_ActiveSprite = sprite;
			return;
		}
	}
}

proxy::Animation& proxy::SpriteComponent::GetActiveAnimation() const
{
	return *m_ActiveSprite;
}

bool proxy::SpriteComponent::CheckActiveAnimation(const std::string& name)
{
	return m_ActiveSprite->CheckName(name);
}

void proxy::SpriteComponent::SetAnimDeltatime(float deltaT)
{
	m_deltaTime = deltaT;
}

float proxy::SpriteComponent::GetAnimDeltatime() const
{
	return m_deltaTime;
}

void proxy::SpriteComponent::SetFrame(int frame)
{
	m_ActiveSprite->SetFrame(frame);
	m_deltaTime = 0.0f;
}
