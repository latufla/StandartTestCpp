#pragma once
#include "ILoader.h"
#include <unordered_map>

// default

namespace sqr {
	class AssetLoader : public ILoader{
	public:
		AssetLoader();
		virtual ~AssetLoader();

		virtual std::shared_ptr<IModel3d> getModel3dBy(std::string keyName) override;
	
	protected:
		std::unordered_map<std::string, std::shared_ptr<IModel3d>> nameToModel;
	};
}

