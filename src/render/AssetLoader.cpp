#include "AssetLoader.h"
#include <memory>
#include "Mesh3d.h"
#include "Vertex3d.h"
#include "Model3d.h"

// default
namespace sqr{
	AssetLoader::AssetLoader() {
		// hard code, but can b external load
// 		float rect[12]{-0.5f, 0.5f, 0.0f,
// 			-0.5f, -0.5f, 0.0f,
// 			0.5f, -0.5f, 0.0f,
// 			0.5f, 0.5f, 0.0f,
// 		};

		float rect[18]{-0.25f, 0.25f, 0.0f,
			-0.25f, -0.25f, 0.0f,
			0.25f, -0.25f, 0.0f,

			0.25f, -0.25f, 0.0f,
			0.25f, 0.25f, 0.0f,
			-0.25f, 0.25f, 0.0f
		};


		std::vector<std::shared_ptr<IVertex3d>> vertices;
		for(uint8_t i = 0; i < 18; i += 3) {
			std::array <float, 3> v = {rect[i], rect[i + 1], rect[i + 2]};
			auto vertex = std::make_shared<Vertex3d>(v);
			vertices.push_back(vertex);
		}

		std::vector<uint16_t> indices{0, 1, 2, 2, 3, 0};
		std::shared_ptr<Mesh3d> mesh = std::make_shared<Mesh3d>(vertices, indices);

 		std::vector<std::shared_ptr<IMesh3d>> meshes;
 		meshes.push_back(mesh);
 		auto model = std::make_shared<Model3d>(Model3d::DEFAULT_MODEL, meshes);
		//

		nameToModel.emplace(Model3d::DEFAULT_MODEL, model);
	}
		
	AssetLoader::~AssetLoader() {
	}

	std::shared_ptr<IModel3d> AssetLoader::getModel3dBy(std::string keyName) {
		return nameToModel.at(keyName);
	}

}
