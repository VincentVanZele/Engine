#pragma once
#include "Scene.h"
#include "SpriteComponent.h"

namespace proxy
{
	class GameObject;

	class TestScene final : public Scene
	{
	public:
		TestScene();

		virtual void Initialize() override;
		virtual void Update() override;

	private:
		std::shared_ptr<GameObject> m_pSprite, m_pText, m_pTexture;

		std::shared_ptr<GameObject> m_SpriteObject = std::make_shared<GameObject>();
		SpriteComponent* spritecomp = new SpriteComponent();


	};
}


