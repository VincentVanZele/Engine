#pragma once
#include "Transform.h"

namespace proxy
{
	class GameObject; //CFD
	class TransformComponent;

	class BaseComponent
	{
		friend class GameObject;
	public:
		BaseComponent(); // no gamecontext
		virtual ~BaseComponent() = default;

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) noexcept = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) noexcept = delete;

		virtual void Initialize() {};
		virtual void Update() {};
		virtual void LateUpdate() {};

		virtual void Draw() {};

		// Functions
		GameObject* GetGameObject() const { return m_pGameObject; }
		void SetGameObject(GameObject* pGO);

		void SetActive(bool active);
		bool GetActive() const;

		TransformComponent* GetTransform() const;

	protected:
		GameObject* m_pGameObject = nullptr;

		bool m_IsActive = true;
		bool m_IsPaused = false;
		bool m_IsInitialized = false;
	};
}
