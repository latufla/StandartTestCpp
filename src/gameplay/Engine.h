#pragma once
#include "interfaces\IEngine.h"

// default
// controller for game objects
namespace sg {
	class Engine : public IEngine{
	public:
		Engine() = delete;
		Engine(std::shared_ptr<sqr::IRenderEngine> renderer, std::shared_ptr<sqw::IWorld> world);

		virtual ~Engine();

		virtual void addObject(uint32_t id, std::shared_ptr<IGameObject> object) override;
		virtual void removeObject(uint32_t id) override;

		virtual std::shared_ptr<IGameObject> getObjectBy(uint32_t id) override;

		virtual void addProcessor(std::shared_ptr<IProcessor>) override;

		virtual bool doStep(long long step) override;

		virtual std::shared_ptr<sqr::IRenderEngine> getRenderer() override;
		virtual std::shared_ptr<sqw::IWorld> getWorld() override;

		virtual std::unordered_map<uint32_t, std::shared_ptr<IGameObject>>& getObjects() override;

	protected:
		std::unordered_map<uint32_t, std::shared_ptr<IGameObject>> idToObject;
		std::vector<std::shared_ptr<IProcessor>> processors;

		std::shared_ptr<sqr::IRenderEngine> renderer;
		std::shared_ptr<sqw::IWorld> world;
	};
}

