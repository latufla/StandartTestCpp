#include "AssetLoader.h"
#include <memory>
#include "Mesh3d.h"
#include "Vertex3d.h"
#include "Model3d.h"

#define _USE_MATH_DEFINES
#include <math.h>

// default
namespace sqr{
	AssetLoader::AssetLoader() {
		// hard code, but can b external load
		const float delta = 2.0f * M_PI / 80.0f;
		std::vector<float> shape;
		float radius = 0.5;
		for(uint32_t i = 0; i < 80; ++i) {					
			shape.push_back(radius * cos(i * delta));
			shape.push_back(radius * sin(i * delta));
			shape.push_back(0.0f);
			
			shape.push_back(radius * cos((i + 1) * delta));
			shape.push_back(radius * sin((i + 1) * delta));
			shape.push_back(0.0f);
			
			shape.push_back(0.0f);
			shape.push_back(0.0f);
			shape.push_back(0.0f);
		}

		std::vector<std::shared_ptr<IVertex3d>> vertices;
		for(uint32_t i = 0; i < shape.size(); i += 3) {
			std::array <float, 3> v = {shape[i], shape[i + 1], shape[i + 2]};
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
