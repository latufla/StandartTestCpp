#pragma once
#include "interfaces/IMesh3d.h"

// default
namespace sqr {
	class Mesh3d : public IMesh3d{
	public:
		Mesh3d() = delete;
		Mesh3d(std::vector<std::shared_ptr<IVertex3d>> vertices, std::vector<uint16_t> indices);

		virtual ~Mesh3d();

		virtual std::vector<std::shared_ptr<IVertex3d>>& getVertices() override;
		virtual std::vector<uint16_t>& getIndices() override;

	private:
		std::vector<std::shared_ptr<IVertex3d>> vertices; // this is crap, but see no way ac. to design
		std::vector<uint16_t> indices;
	};
}

