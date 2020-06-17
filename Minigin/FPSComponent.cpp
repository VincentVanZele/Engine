#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "ResourceManager.h"

void proxy::FPSComponent::Update()
{
	int deltaTime{};
	m_FPS = 1.f / deltaTime;
}

float proxy::FPSComponent::GetFPS() const
{
	return m_FPS;
}
