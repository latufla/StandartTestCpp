#include "GameObject.h"
#include "..\render\View.h"
#include "..\render\Model3d.h"
#include "..\world\Object.h"


namespace sg {

	GameObject::GameObject(std::weak_ptr<sqr::IRenderEngine> renderer,
		std::weak_ptr<sqw::IWorld> world, 
		uint32_t id, uint32_t radius, const glm::vec2& position, const glm::vec4& color) : id(id) {

		auto view = std::make_shared<sqr::View>(sqr::Model3d::DEFAULT_MODEL, color);
		auto sRenderer = renderer.lock();
		if(sRenderer) {
			sRenderer->addObject(1, view);
			this->renderer = renderer;
			this->view = view;
		}

		auto worldObject = std::make_shared<sqw::Object>();
		auto& speed = worldObject->getSpeed();
		speed.y = -0.000001f;
		auto sWorld = world.lock();
		if(sWorld) {
			sWorld->addObject(1, worldObject);
			this->world = world;
			this->worldObject = worldObject;
		}
	}
		
	GameObject::~GameObject() {
	}

	bool GameObject::doStep(long long step) {
		auto sWorldObject = worldObject.lock();
		if(!sWorldObject)
			return false;

		auto sView = view.lock();
		if(sView){
			auto& pos = sWorldObject->getPosition();
			sView->translate(pos.x, pos.y, 0.0f);
		}
			
		return true;
	}

	std::weak_ptr<sqr::IRenderEngine> GameObject::getRenderer() {
		return renderer;
	}

	std::weak_ptr<sqr::IView> GameObject::getView() {
		return view;
	}

	std::weak_ptr<sqw::IWorld> GameObject::getWorld() {
		return world;
	}

	std::weak_ptr<sqw::IObject> GameObject::getWorldObject() {
		return worldObject;
	}

}
