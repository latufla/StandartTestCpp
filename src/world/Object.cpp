#include "Object.h"

namespace sqw {
	Object::Object(const glm::vec2& position, const glm::vec2& speed) 
		: position(position), speed(speed) {		
	}

	Object::~Object() {
	}


	glm::vec2& Object::getPosition() {
		return position;
	}

	glm::vec2& Object::getSpeed() {
		return speed;
	}
}
