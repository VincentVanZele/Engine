#include "MiniginPCH.h"
#include "Structs.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "Renderer.h"

proxy::TextureComponent::TextureComponent()
	: BaseComponent()
	, m_pTexture2D(nullptr)
{
}

void proxy::TextureComponent::Draw()
{
	Float2 pos{ m_pGameObject->GetTransform()->GetPosition() };
	Renderer::GetInstance().RenderTexture(*m_pTexture2D, pos._x, pos._y);
}

proxy::Texture2D& proxy::TextureComponent::GetTexture() const
{
	return *m_pTexture2D;
}

void proxy::TextureComponent::SetTexture(std::shared_ptr<Texture2D> pTexture)
{
	m_pTexture2D = pTexture;
}
