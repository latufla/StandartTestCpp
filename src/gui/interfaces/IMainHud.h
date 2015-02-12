#pragma once
#include "../../SharedHeaders.h"
#include <memory>
#include "IMainHudData.h"
#include "SFML/Graphics/Text.hpp"

namespace sr {
	class IMainHud {
	public:
		virtual void update(std::shared_ptr<IMainHudData>) = 0;
		virtual std::shared_ptr<sf::Text> getScoreTextField() = 0; // sorry, rapid
	};
}