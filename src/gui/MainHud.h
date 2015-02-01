#pragma once
#include "interfaces\IMainHud.h"
#include "SFML\Graphics\Text.hpp"
#include "..\render\interfaces\ILoader.h"

// default
namespace sqr{
	class MainHud : public IMainHud {
	public:
		MainHud() = delete;
		MainHud(std::weak_ptr<ILoader>);

		virtual ~MainHud();

		virtual void update(std::shared_ptr<IMainHudData>) override;
		virtual std::shared_ptr<sf::Text> getScoreTextField() override;

	protected:
		std::weak_ptr<ILoader> assetLoader;
		std::shared_ptr<sf::Text> scoreTextField;
	};

}

