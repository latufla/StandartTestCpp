#include "AssetLoader.h"


namespace sqr{
	AssetLoader::AssetLoader() {
	}
		
	AssetLoader::~AssetLoader() {
	}

	std::shared_ptr<IModel3d> AssetLoader::getModel3dBy(std::string keyName) {
		return nameToModel.at(keyName);
	}

}
