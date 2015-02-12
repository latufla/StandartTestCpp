#include "GameObject.h"
#include "..\render\View.h"
#include "..\render\Model3d.h"
#include "..\world\Object.h"
#include "GameObjectInfo.h"
#include "..\exceptions\Exception.h"

namespace sg {

	GameObject::GameObject(std::weak_ptr<sr::IRenderEngine> renderer,
		std::weak_ptr<sw::IWorld> world, 
		uint32_t id, std::weak_ptr<sg::IGameObjectInfo> info, const glm::mat4& transform)
		: id(id){

		auto sInfo = info.lock();
		if(!sInfo)
			throw sx::WeakPtrException(EXCEPTION_INFO);

		auto objectInfo = (sg::GameObjectInfo*)sInfo.get();
		points = objectInfo->points;

		auto view = std::make_shared<sr::View>(objectInfo->modelName, objectInfo->color);
		auto sRenderer = renderer.lock();
		if(sRenderer) {
			sRenderer->addObject(id, view);
			this->renderer = renderer;
			this->view = sRenderer->getObjectBy(id);
		}

		auto worldObject = std::make_shared<sw::Object>(transform, objectInfo->speed);
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
		auto sView = view.lock();
		if(sWorldObject && sView) {
			auto& transform = sWorldObject->getTransform();
			sView->setTransform(transform);
		}
			
		return true;
	}

	std::weak_ptr<sr::IRenderEngine> GameObject::getRenderer() {
		return renderer;
	}

	std::weak_ptr<sr::IView> GameObject::getView() {
		return view;
	}

	std::weak_ptr<sw::IWorld> GameObject::getWorld() {
		return world;
	}

	std::weak_ptr<sw::IObject> GameObject::getWorldObject() {
		return worldObject;
	}

	int32_t GameObject::getPoints() {
		return points;
	}

}
