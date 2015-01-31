#include "AssetLoader.h"
#include <memory>
#include "Mesh3d.h"
#include "Vertex3d.h"
#include "Model3d.h"

// default
namespace sqr{
	AssetLoader::AssetLoader() {
		// hard code, but can b external load
		std::vector<std::shared_ptr<IVertex3d>> vertices;
		std::vector<uint16_t> indices;
		std::shared_ptr<Mesh3d> mesh = std::make_shared<Mesh3d>(vertices, indices);

 		std::vector<std::shared_ptr<IMesh3d>> meshes;
 		meshes.push_back(mesh);
 		auto model = std::make_shared<Model3d>(Model3d::DEFAULT_MODEL, meshes);
		
		nameToModel.emplace(Model3d::DEFAULT_MODEL, model);
	}
		
	AssetLoader::~AssetLoader() {
	}

	std::shared_ptr<IModel3d> AssetLoader::getModel3dBy(std::string keyName) {
		return nameToModel.at(keyName);
	}

}
