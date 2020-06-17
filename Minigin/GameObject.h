#pragma once
#include <memory>
#include "TransformComponent.h"
#include "Texture2D.h"
#include "SceneObject.h"
#include "SceneObject.h"

namespace proxy
{
	class GameObject final : public SceneObject
	{
		friend class BaseComponent;
	public:

		GameObject(const Float2& pos = { 0.f, 0.f }, float rot = 0.0f, const Float2& sca = { 1.f, 1.f });
		virtual ~GameObject();

		void Update() override;
		void Render() const override;

		static std::shared_ptr<GameObject> NewGameObject();

		TransformComponent* GetTransform() const { return m_pTransform; }

		void AddComponent(BaseComponent* pComp);
		void RemoveComponent(BaseComponent* pComp);

		// Template
		template<class T>
		T* GetComponent(bool searchChildren = false)
		{
			const std::type_info& templateInfo = typeid(T);
			for (BaseComponent* const pComp : m_pComponents)
			{
				if (pComp && typeid(*pComp) == templateInfo)
				{
					return dynamic_cast<T*>(pComp);
				}
			}

			if (searchChildren)
			{
				for (auto* child : m_pChildren)
				{
					if (child->GetComponent<T>(searchChildren) != nullptr)
					{
						return child->GetComponent<T>(searchChildren);
					}
				}
			}

			return nullptr;
		}

		template <class T>
		bool HasComponent(bool searchChildren = false)
		{
			return GetComponent<T>(searchChildren) != nullptr;
		}

		void SetParent(GameObject* parent);
		GameObject* GetParent();

		void SetActive(bool active);
		bool GetActive() const;

	protected:
	private:
		TransformComponent* m_pTransform;
		std::vector<BaseComponent*> m_pComponents;

		GameObject* m_pParentObject;
		std::vector<GameObject*> m_pChildren;

		bool m_IsActive = true;
	};

}
