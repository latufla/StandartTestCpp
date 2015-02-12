#include "AssetLoader.h"
#include <memory>
#include "Mesh3d.h"
#include "Vertex3d.h"
#include "Model3d.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include "..\exceptions\Exception.h"

using std::shared_ptr;
using std::make_shared;
using std::string;
using std::vector;

using glm::vec3;

// default
namespace sr{
	AssetLoader::AssetLoader() {
		auto defaultModel = createDefaultModel();
		nameToModel.emplace(Model3d::DEFAULT_MODEL, defaultModel);

		auto font = loadDefaultFont();
		nameToFont.emplace(font->getInfo().family, font);
	}
		
	AssetLoader::~AssetLoader() {
	}


	shared_ptr<IModel3d> AssetLoader::getModel3dBy(string keyName) {
		try {
			return nameToModel.at(keyName);
		} catch(std::out_of_range&) {
			throw sx::InvalidKeyException(EXCEPTION_INFO, keyName);
		}
	}

	shared_ptr<sf::Font> AssetLoader::getFont(string familyAsKey) {
		try {
			return nameToFont.at(familyAsKey);
		} catch(std::out_of_range&) {
			throw sx::InvalidKeyException(EXCEPTION_INFO, familyAsKey);
		}
	}


	shared_ptr<IModel3d> AssetLoader::createDefaultModel() {
		const uint16_t segments = 50;
		const float delta = 2.0f * (float)M_PI / (float)segments;
		float radius = 1.0f; // just to build model
		vector<shared_ptr<IVertex3d>> vertices;
		for(uint32_t i = 0; i < segments; ++i) {
			vec3 v(vec3{radius * cos(i * delta), radius * sin(i * delta), 0.0f});
			auto vertex = make_shared<Vertex3d>(v);
			vertices.push_back(vertex);

			v = vec3{radius * cos((i + 1) * delta), radius * sin((i + 1) * delta), 0.0f};
			vertex = make_shared<Vertex3d>(v);
			vertices.push_back(vertex);

			v = vec3{0.0f, 0.0f, 0.0f};
			vertex = make_shared<Vertex3d>(v);
			vertices.push_back(vertex);
		}

		vector<uint16_t> indices;
		shared_ptr<Mesh3d> mesh = make_shared<Mesh3d>(Model3d::DEFAULT_MODEL, vertices, indices);

		vector<shared_ptr<IMesh3d>> meshes;
		meshes.push_back(mesh);
		auto model = make_shared<Model3d>(Model3d::DEFAULT_MODEL, meshes);
		return model;
	}

	shared_ptr<sf::Font> AssetLoader::loadDefaultFont() {
		auto font = make_shared<sf::Font>();
		font->loadFromFile("fonts/arial.ttf");
		return font;
	}
}
