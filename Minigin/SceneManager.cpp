#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

void proxy::SceneManager::AddScene(std::shared_ptr<Scene> scene)
{
	mScenes.push_back(scene);
}

void proxy::SceneManager::Update()
{
	mActiveScene->Update();
}

void proxy::SceneManager::LateUpdate()
{
	mActiveScene->LateUpdate();
}

void proxy::SceneManager::Render()
{
	mActiveScene->Render();
}

std::vector<std::shared_ptr<proxy::Scene>> proxy::SceneManager::GetScenes() const
{
	return mScenes;
}

void proxy::SceneManager::SetActiveScene(const std::string& name)
{
	for (auto scene : mScenes)
	{
		if (scene->GetName() == name)
		{
			mActiveScene = scene;
			return;
		}
	}
}
