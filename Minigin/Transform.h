#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#pragma warning(pop)

namespace proxy
{
	class Transform final
	{
		glm::vec3 mPosition;
		glm::vec2 mScale;
	public:
		const glm::vec3& GetPosition() const { return mPosition; }
		void SetPosition(const glm::vec3& newPos);
		void SetPosition(float x, float y, float z);

		const glm::vec2& GetScale() const;
		void SetScale(const glm::vec2& scale);
		void SetScale(float x, float y);
	};
}
