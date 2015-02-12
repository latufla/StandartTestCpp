#pragma once
#include "SFML\Graphics\Text.hpp"
#include "src\gui\interfaces\IMainHud.h"
#include "src\render\interfaces\ILoader.h"

class MainHud : public sr::IMainHud {
public:
	MainHud() = delete;
	MainHud(std::weak_ptr<sr::ILoader>);

	virtual ~MainHud();

	virtual void update(std::shared_ptr<sr::IMainHudData>) override;
	virtual std::shared_ptr<sf::Text> getScoreTextField() override;

protected:
	std::weak_ptr<sr::ILoader> assetLoader;
	std::shared_ptr<sf::Text> scoreTextField;
};

