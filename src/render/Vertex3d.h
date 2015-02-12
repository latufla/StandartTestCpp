#pragma once
#include "interfaces/IMesh3d.h"

namespace sr{
	class Vertex3d : public IVertex3d {
	public:
		Vertex3d() = delete;
		Vertex3d(const glm::vec3& position);
	
		virtual ~Vertex3d();
	
		virtual glm::vec3& getPosition() override;
	
	protected:
		glm::vec3 position;
	};
}

