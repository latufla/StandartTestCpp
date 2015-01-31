#include "Vertex3d.h"


namespace sqr{	
	Vertex3d::Vertex3d(const std::array<float, 3>& position) 
		: position(position) {

	}

	Vertex3d::~Vertex3d() {
	}

	std::array<float, 3>& Vertex3d::getPosition() {
		return position;
	}
}
