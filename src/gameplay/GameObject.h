#pragma once
#include "interfaces\IGameObject.h"
#include <memory>
#include "interfaces\IGameObjectInfo.h"

// default
// controller for view, world interaction
namespace sg{
	class GameObject : public IGameObject{
	public:
		GameObject() = delete;
		GameObject(std::weak_ptr<sr::IRenderEngine> renderer,
			std::weak_ptr<sw::IWorld> world,
			uint32_t id, std::weak_ptr<sg::IGameObjectInfo> info, const glm::mat4& transform);

		virtual ~GameObject();

		virtual bool doStep(long long step);

		virtual std::weak_ptr<sr::IRenderEngine> getRenderer() override;
		virtual std::weak_ptr<sr::IView> getView() override;

		virtual std::weak_ptr<sw::IWorld> getWorld() override;
		virtual std::weak_ptr<sw::IObject> getWorldObject() override;

		virtual int32_t getPoints() override;
	protected:
		uint32_t id;
		int32_t points;

		std::weak_ptr<sr::IRenderEngine> renderer;
		std::weak_ptr<sr::IView> view;

		std::weak_ptr<sw::IWorld> world;
		std::weak_ptr<sw::IObject> worldObject;
	};
}

