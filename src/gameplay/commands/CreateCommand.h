#pragma once
#include <memory>
#include <glm.hpp>
#include "Command.h"
#include "..\GameObjectInfo.h"

namespace sg {
	class CreateCommand : public Command{
	public:
		CreateCommand(IEngine*, std::shared_ptr<GameObjectInfo>, glm::mat4& transform);
		virtual ~CreateCommand() override;
	
	protected:
		virtual void execute() override;

		std::shared_ptr<GameObjectInfo> objectInfo;
		glm::mat4& transform;
	
		static uint32_t nextObjectId;
	};
}

