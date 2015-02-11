#include "AssetLoader.h"
#include <memory>
#include "Mesh3d.h"
#include "Vertex3d.h"
#include "Model3d.h"

#define _USE_MATH_DEFINES
#include <math.h>

using glm::vec3;

// default
namespace sqr{
	AssetLoader::AssetLoader() {
		auto defaultModel = createDefaultModel();
		nameToModel.emplace(Model3d::DEFAULT_MODEL, defaultModel);

		auto font = loadDefaultFont();
		nameToFont.emplace(font->getInfo().family, font);
	}
		
	AssetLoader::~AssetLoader() {
	}


	std::shared_ptr<IModel3d> AssetLoader::getModel3dBy(std::string keyName) {
		return nameToModel.at(keyName);
	}


	std::shared_ptr<IModel3d> AssetLoader::createDefaultModel() {
		const uint16_t segments = 50;
		const float delta = 2.0f * (float)M_PI / (float)segments;
		float radius = 1.0f; // just to build model
		std::vector<std::shared_ptr<IVertex3d>> vertices;
		for(uint32_t i = 0; i < segments; ++i) {
			glm::vec3 v(vec3{radius * cos(i * delta), radius * sin(i * delta), 0.0f});
			auto vertex = std::make_shared<Vertex3d>(v);
			vertices.push_back(vertex);

			v = vec3{radius * cos((i + 1) * delta), radius * sin((i + 1) * delta), 0.0f};
			vertex = std::make_shared<Vertex3d>(v);
			vertices.push_back(vertex);

			v = vec3{0.0f, 0.0f, 0.0f};
			vertex = std::make_shared<Vertex3d>(v);
			vertices.push_back(vertex);
		}

		std::vector<uint16_t> indices;
		std::shared_ptr<Mesh3d> mesh = std::make_shared<Mesh3d>(Model3d::DEFAULT_MODEL, vertices, indices);

		std::vector<std::shared_ptr<IMesh3d>> meshes;
		meshes.push_back(mesh);
		auto model = std::make_shared<Model3d>(Model3d::DEFAULT_MODEL, meshes);
		return model;
	}

	std::shared_ptr<sf::Font> AssetLoader::getFont(std::string familyAsKey) {
		return nameToFont.at(familyAsKey);
	}

	std::shared_ptr<sf::Font> AssetLoader::loadDefaultFont() {
		auto font = std::make_shared<sf::Font>();
		font->loadFromFile("fonts/arial.ttf");
		return font;
	}

}
