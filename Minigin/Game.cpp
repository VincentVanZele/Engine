#include "MiniginPCH.h"
#include "Game.h"

#include "Minigin.h"
#include "SceneManager.h"

#include "TestScene.h"

void proxy::Game::Run()
{
	proxy::Minigin engine{};
	engine.Initialize();

	LoadScenes();

	engine.Run();
}

void proxy::Game::LoadScenes()
{
	std::shared_ptr<Scene> scene = std::make_shared<TestScene>();

	SceneManager::GetInstance().AddScene(scene);
	SceneManager::GetInstance().SetActiveScene(scene->GetName());
}
