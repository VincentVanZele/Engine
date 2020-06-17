#pragma once
#include "BaseComponent.h"

namespace proxy
{
	class FPSComponent : public BaseComponent
	{
	public:
		virtual void Update() override;

		// Functions
		float GetFPS() const;

	private:
		float m_FPS = 0;
	};
}