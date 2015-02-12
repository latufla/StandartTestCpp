#pragma once
#include "interfaces/ILoader.h"
#include <unordered_map>

// default

namespace sr {
	class AssetLoader : public ILoader{
	public:
		AssetLoader();
		virtual ~AssetLoader();

		virtual std::shared_ptr<IModel3d> getModel3dBy(std::string keyName) override;
		virtual std::shared_ptr<sf::Font> getFont(std::string familyAsKey) override;

	protected:
		// hard code, but can b external load
		std::shared_ptr<IModel3d> createDefaultModel(); 
		std::shared_ptr<sf::Font> loadDefaultFont();
		//--

		std::unordered_map<std::string, std::shared_ptr<IModel3d>> nameToModel;
		std::unordered_map<std::string, std::shared_ptr<sf::Font>> nameToFont;
	};
}

