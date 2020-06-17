#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"

unsigned int proxy::Scene::idCounter = 0;

proxy::Scene::Scene(const std::string& name) 
	: mName(name) 
	, m_IsInitialized(false)
{
}

void proxy::Scene::Add(const std::shared_ptr<SceneObject>& object)
{
	mObjects.push_back(object);
	
}

void proxy::Scene::SetName(std::string& name)
{
	mName = name;
}

std::string proxy::Scene::GetName() const
{
	return mName;
}

void proxy::Scene::SetInitialized(bool init)
{
	m_IsInitialized = init;
}

bool proxy::Scene::GetInitialized() const
{
	return m_IsInitialized;
}

void proxy::Scene::Update()
{
	for(auto gameObject : mObjects)
	{
		gameObject->Update();
	}
}

void proxy::Scene::LateUpdate()
{
}

void proxy::Scene::Render() const
{
	for (const auto gameObject : mObjects)
	{
		gameObject->Render();
	}
}

