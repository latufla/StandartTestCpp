#pragma once
#include "interface\IGameField.h"

namespace sg {
	class GameField : public IGameField{
	public:
		GameField() = delete;
		GameField(std::weak_ptr<sqr::IRenderEngine> renderer, std::weak_ptr<sqw::IWorld> world);

		virtual ~GameField();

		virtual void addObject(uint32_t id, std::shared_ptr<IGameObject> object) override;
		virtual void removeObject(uint32_t id) override;

		virtual void addProcessor(std::shared_ptr<IGameProcessor>) override;

		virtual bool doStep(long long step) override;

		virtual std::weak_ptr<sqr::IRenderEngine> getRenderer() override;
		virtual std::weak_ptr<sqw::IWorld> getWorld() override;

		virtual std::unordered_map<uint32_t, std::shared_ptr<IGameObject>>& getObjects() override;

	protected:
		std::unordered_map<uint32_t, std::shared_ptr<IGameObject>> idToObject;
		std::vector<std::shared_ptr<IGameProcessor>> processors;

		std::weak_ptr<sqr::IRenderEngine> renderer;
		std::weak_ptr<sqw::IWorld> world;
	};
}

