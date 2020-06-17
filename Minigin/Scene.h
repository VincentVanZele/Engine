#pragma once
#include "SceneManager.h"

namespace proxy
{
	class SceneObject;
	class Scene
	{
	public:
		explicit Scene(const std::string& name);
		virtual ~Scene() = default;

		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

		virtual void Initialize() = 0;
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render() const;

		void Add(const std::shared_ptr<SceneObject>& object);

		void SetName(std::string& name);
		std::string GetName() const;

		void SetInitialized(bool init);
		bool GetInitialized() const;

	private: 
		std::string mName{};
		std::vector<std::shared_ptr<SceneObject>> mObjects{};

		bool m_IsInitialized;
		static unsigned int idCounter; 
	};

}
