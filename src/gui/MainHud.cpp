#include "MainHud.h"
#include "MainHudData.h"

namespace sqr {
	MainHud::MainHud(std::weak_ptr<ILoader> assetLoader)
		: assetLoader(assetLoader){

		auto sAssetLoader = assetLoader.lock();

		// hard code
		auto font = sAssetLoader->getFont("Arial");
		scoreTextField = std::make_shared<sf::Text>("0", *font.get());
		scoreTextField->setColor(sf::Color(255, 255, 255, 255));
		scoreTextField->setPosition(30.f, 710.0f);
	}

	MainHud::~MainHud() {
	}

	void MainHud::update(std::shared_ptr<IMainHudData> data) {
		auto hudData = (MainHudData*)data.get();
		scoreTextField->setString(std::to_string(hudData->score)); // to_string acts bad on devices
	}

	std::shared_ptr<sf::Text> MainHud::getScoreTextField() {
		return scoreTextField;
	}

}
