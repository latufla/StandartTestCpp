#pragma once
#include "interface\IGameObject.h"
#include <memory>

// default
// controller for view, world interaction
// and components support
namespace sg{
	class GameObject : public IGameObject{
	public:
		GameObject() = delete;
		GameObject(std::weak_ptr<sqr::IRenderEngine> renderer,
			std::weak_ptr<sqw::IWorld> world,
			uint32_t id, uint32_t radius, const glm::vec2& position, const glm::vec4& color);

		virtual ~GameObject();

		virtual bool doStep(long long step);

		virtual std::weak_ptr<sqr::IRenderEngine> getRenderer();
		virtual std::weak_ptr<sqr::IView> getView();

		virtual std::weak_ptr<sqw::IWorld> getWorld();
		virtual std::weak_ptr<sqw::IObject> getWorldObject();
	private:
		uint32_t id;

		std::weak_ptr<sqr::IRenderEngine> renderer;
		std::weak_ptr<sqr::IView> view;

		std::weak_ptr<sqw::IWorld> world;
		std::weak_ptr<sqw::IObject> worldObject;
	};
}

