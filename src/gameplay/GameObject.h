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
		GameObject(std::weak_ptr<sqr::IRenderEngine> renderer,
			std::weak_ptr<sqw::IWorld> world,
			uint32_t id, std::weak_ptr<sg::IGameObjectInfo> info, const glm::mat4& transform);

		virtual ~GameObject();

		virtual bool doStep(long long step);

		virtual std::weak_ptr<sqr::IRenderEngine> getRenderer() override;
		virtual std::weak_ptr<sqr::IView> getView() override;

		virtual std::weak_ptr<sqw::IWorld> getWorld() override;
		virtual std::weak_ptr<sqw::IObject> getWorldObject() override;

		virtual int32_t getPoints() override;
	protected:
		uint32_t id;
		int32_t points;

		std::weak_ptr<sqr::IRenderEngine> renderer;
		std::weak_ptr<sqr::IView> view;

		std::weak_ptr<sqw::IWorld> world;
		std::weak_ptr<sqw::IObject> worldObject;
	};
}

