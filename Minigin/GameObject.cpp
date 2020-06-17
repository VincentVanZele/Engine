#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "SceneObject.h"


proxy::GameObject::GameObject(const Float2& pos, float rot, const Float2& sca)
	: m_pParentObject(nullptr)
	, m_pTransform(nullptr)
{
	TransformComponent* trans = new TransformComponent();
	
	trans->SetPosition(pos);
	trans->SetRotation(rot);
	trans->SetScale(sca);

	m_pTransform = trans;
}

proxy::GameObject::~GameObject()
{
	delete m_pParentObject;
	delete m_pTransform;

	for (auto comps : m_pComponents)
	{
		delete comps;
	}
}

std::shared_ptr<proxy::GameObject> proxy::GameObject::NewGameObject()
{
	auto go = std::make_shared<GameObject>();
	//scene manager
	return go;
}

void proxy::GameObject::AddComponent(BaseComponent * pComp)
{
	for (auto *component : m_pComponents)
	{
		if (component == pComp)
		{
			std::cout<<"GameObject::AddComponent > GameObject already contains this component!";
			return;
		}
	}

	m_pComponents.push_back(pComp);
	pComp->m_pGameObject = this;
}

void proxy::GameObject::RemoveComponent(BaseComponent * pComp)
{
	auto it = find(m_pComponents.begin(), m_pComponents.end(), pComp);

	if (it == m_pComponents.end())
	{
		std::cout<<"GameObject::RemoveComponent > Component is not attached to this GameObject!";
		return;
	}

	m_pComponents.erase(it);
	pComp->m_pGameObject = nullptr;
}

void proxy::GameObject::SetParent(GameObject* parent)
{
	m_pParentObject = parent;
}

proxy::GameObject* proxy::GameObject::GetParent()
{
	return m_pParentObject;
}

void proxy::GameObject::SetActive(bool active)
{
	if (m_IsActive != active)
	{
		m_IsActive = active;

		for (BaseComponent* pComp : m_pComponents)
		{
			pComp->SetActive(active);
		}
	}
}

bool proxy::GameObject::GetActive() const
{
	
	return m_IsActive;
}

void proxy::GameObject::Update()
{
	for (BaseComponent* pComp : m_pComponents)
	{
		if (pComp->GetActive())
		{
			if (!pComp->m_IsInitialized)
			{
				pComp->Initialize();
				pComp->m_IsInitialized = true;
			}

			pComp->Update();
		}
	}
}

void proxy::GameObject::Render() const
{

	for (BaseComponent* pComp : m_pComponents)
	{
		pComp->Draw();
	}
}



