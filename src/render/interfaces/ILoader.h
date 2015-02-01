#pragma once
#include "../../SharedHeaders.h"
#include <memory>
#include "IModel3d.h"
#include "SFML/Graphics/Font.hpp"

namespace sqr {
	class ILoader {
	public:
		virtual std::shared_ptr<IModel3d> getModel3dBy(std::string keyName) = 0;
		virtual std::shared_ptr<sf::Font> getFont(std::string keyName) = 0; // sorry bout that, just rapid
	};
}