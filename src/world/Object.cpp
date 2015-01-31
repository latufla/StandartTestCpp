#include "Object.h"

namespace sqw{	
	Object::~Object() {
	}

	glm::vec2& Object::getPosition() {
		return position;
	}

	glm::vec2& Object::getSpeed() {
		return speed;
	}

}
