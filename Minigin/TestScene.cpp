#include "MiniginPCH.h"
#include "TestScene.h"

#include "Scene.h"
#include "Renderer.h"
#include "GameTime.h"
#include "GameObject.h"

#include "SceneManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

#include "TextComponent.h"
#include "SpriteComponent.h"
#include "TextComponent.h"

proxy::TestScene::TestScene()
	:Scene("TestScene")
	, m_pSprite(nullptr), m_pText(nullptr), m_pTexture(nullptr)
{
	Initialize();
}

void proxy::TestScene::Initialize()
{
	if (GetInitialized())
	{
		return;
	}

	// Input
	InputManager::GetInstance().AddInput("left", 'a');
	InputManager::GetInstance().AddInput("right", 'd');
	InputManager::GetInstance().AddInput("up", 'w');
	InputManager::GetInstance().AddInput("down", 's');

	// Texture Object
	TextureComponent* spriteComponent = new TextureComponent();
	auto background = ResourceManager::GetInstance().LoadTexture("background.jpg");
	spriteComponent->SetTexture(background);

	auto go = std::make_shared<GameObject>();
	go->AddComponent(spriteComponent);
	Add(go);

	// Text object
	std::shared_ptr<Font> font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	TextComponent* textComp = new TextComponent("Text Component Test ", font);
	textComp->Texture();

	auto goText = std::make_shared<GameObject>();
	goText->AddComponent(textComp);
	goText->GetTransform()->SetPosition({ 80, 20 });
	Add(goText);


	// Sprite Object
	auto tex = ResourceManager::GetInstance().LoadTexture("Sprites/Bobby/Run.png");
	
	auto anim = std::make_shared<Animation>(tex, "runAnim", 4);
	anim->SetPos(m_SpriteObject->GetTransform()->GetPosition());
	anim->SetFrameDeltatime(0.2f);
	
	spritecomp->AddAnimation(anim);
	spritecomp->SetActiveAnimation("run");
	
	m_SpriteObject->AddComponent(spritecomp);
	Add(m_SpriteObject);

	Renderer::GetInstance().SetScale(1);

	SetInitialized(true);
}

void proxy::TestScene::Update()
{
	auto deltaT = GameTime::GetInstance().GetDeltaTime();

	// Object update
	if (InputManager::GetInstance().IsPressed("left"))
	{
		m_SpriteObject->GetTransform()->Translate(Float2(-deltaT*75, 0));
		spritecomp->GetActiveAnimation().SetPos(m_SpriteObject->GetTransform()->GetPosition());
	}
	if (InputManager::GetInstance().IsPressed("right"))
	{
		m_SpriteObject->GetTransform()->Translate(Float2(deltaT * 75, 0));
		spritecomp->GetActiveAnimation().SetPos(m_SpriteObject->GetTransform()->GetPosition());

	}
	if (InputManager::GetInstance().IsPressed("up"))
	{
		m_SpriteObject->GetTransform()->Translate(Float2(0, -deltaT * 75));
		spritecomp->GetActiveAnimation().SetPos(m_SpriteObject->GetTransform()->GetPosition());

	}
	if (InputManager::GetInstance().IsPressed("down"))
	{
		m_SpriteObject->GetTransform()->Translate(Float2(0, deltaT * 75));
		spritecomp->GetActiveAnimation().SetPos(m_SpriteObject->GetTransform()->GetPosition());

	}

	// scene root update
	Scene::Update();
}
