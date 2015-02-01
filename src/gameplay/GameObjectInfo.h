#pragma once
#include "interface\IGameObjectInfo.h"
#include <glm.hpp>

namespace sg {
	class GameObjectInfo : public IGameObjectInfo {
	public:
		GameObjectInfo() = default;
		virtual ~GameObjectInfo();

		std::string modelName;

		float radius;
		uint32_t points;
		glm::vec4 color;
	
		glm::vec2 speed;

	};
}

