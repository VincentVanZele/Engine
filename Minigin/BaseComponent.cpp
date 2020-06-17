#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "TransformComponent.h"

#include "GameObject.h"


proxy::BaseComponent::BaseComponent()
{
}

void proxy::BaseComponent::SetGameObject(GameObject* pGO)
{
	m_pGameObject = pGO;
}

void proxy::BaseComponent::SetActive(bool active)
{
	m_IsActive = active;

	if (!m_IsActive)
	{
		bool allInactive = true;

		for (auto pComp : m_pGameObject->m_pComponents)
		{
			if (pComp->GetActive())
			{
				allInactive = false;
				break;
			}

		}

		if (allInactive)
		{
			m_pGameObject->m_IsActive = false;
		}
	}
	else
	{
		m_pGameObject->m_IsActive = true;
	}
}

bool proxy::BaseComponent::GetActive() const
{
	return m_IsActive;
}

proxy::TransformComponent* proxy::BaseComponent::GetTransform() const
{
	// TODO: insert return statement here
#if _DEBUG
	if (m_pGameObject == nullptr)
	{
		std::cout << "BaseComponent::GetTransform() > Failed to retrieve the TransformComponent. GameObject is NULL." << '\n';
	}
#endif

	return m_pGameObject->GetTransform();
}






