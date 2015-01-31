#pragma once
#include "IMesh3d.h"

namespace sqr{
	class Vertex3d : public IVertex3d {
	public:
		Vertex3d() = delete;
		Vertex3d(const std::array<float, 3>& position);
	
		virtual ~Vertex3d();
	
		virtual std::array<float, 3>& getPosition() override;
	
	protected:
		std::array<float, 3> position;
	};
}

