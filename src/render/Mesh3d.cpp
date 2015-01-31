#include "Mesh3d.h"


namespace sqr{

	Mesh3d::Mesh3d(std::vector<std::shared_ptr<IVertex3d>> vertices, std::vector<uint16_t> indices) 
		: vertices(vertices), indices(indices) {

	}


	Mesh3d::~Mesh3d() {
	}

	std::vector<std::shared_ptr<IVertex3d>>& Mesh3d::getVertices() {
		return vertices;
	}

	std::vector<uint16_t>& Mesh3d::getIndices() {
		return indices;
	}
}
