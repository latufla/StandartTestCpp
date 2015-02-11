#include "Mesh3d.h"


namespace sqr{

	Mesh3d::Mesh3d(std::string name, std::vector<std::shared_ptr<IVertex3d>> vertices, std::vector<uint16_t> indices) 
		: name(name), vertices(vertices), indices(indices) {

		for(auto i : vertices) {
			auto pos = i->getPosition();
			rawVertices.push_back(pos.x);
			rawVertices.push_back(pos.y);
			rawVertices.push_back(pos.z);
		}
	}


	Mesh3d::~Mesh3d() {
	}

	std::vector<std::shared_ptr<IVertex3d>>& Mesh3d::getVertices() {
		return vertices;
	}

	std::vector<uint16_t>& Mesh3d::getIndices() {
		return indices;
	}

	std::string Mesh3d::getName() {
		return name;
	}

	std::vector<float>& Mesh3d::getRawVertices() {
		return rawVertices;
	}
}
