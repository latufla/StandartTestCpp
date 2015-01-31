#include "Vertex3d.h"


namespace sqr{	
	Vertex3d::Vertex3d(const glm::vec3& position)
		: position(position) {
	}

	Vertex3d::~Vertex3d() {
	}

	glm::vec3& Vertex3d::getPosition() {
		return position;
	}
}
