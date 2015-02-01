#include "GameObject.h"
#include "..\render\View.h"
#include "..\render\Model3d.h"
#include "..\world\Object.h"
#include "GameObjectInfo.h"


namespace sg {

	GameObject::GameObject(std::weak_ptr<sqr::IRenderEngine> renderer,
		std::weak_ptr<sqw::IWorld> world, 
		uint32_t id, std::weak_ptr<sg::IGameObjectInfo> info, const glm::vec2& position) 
		: id(id){

		auto sInfo = info.lock();
		auto objectInfo = (sg::GameObjectInfo*)sInfo.get();

		points = objectInfo->points;

		auto view = std::make_shared<sqr::View>(objectInfo->modelName, objectInfo->color);
		auto sRenderer = renderer.lock();
		if(sRenderer) {
			sRenderer->addObject(id, view);
			this->renderer = renderer;
			this->view = sRenderer->getObjectBy(id);
		}

		auto worldObject = std::make_shared<sqw::Object>(position, objectInfo->speed);
		auto sWorld = world.lock();
		if(sWorld) {
			sWorld->addObject(id, worldObject);
			this->world = world;
			this->worldObject = sWorld->getObjectBy(id);
		}
	}
		
	GameObject::~GameObject() {
		if(auto sRenderer = renderer.lock())
			sRenderer->removeObject(id);

		if(auto sWorld = world.lock())
			sWorld->removeObject(id);
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

	int32_t GameObject::getPoints() {
		return points;
	}

}
