#pragma once
#include "interfaces/IMesh3d.h"

// default
namespace sqr {
	class Mesh3d : public IMesh3d{
	public:
		Mesh3d() = delete;
		Mesh3d(std::string name, std::vector<std::shared_ptr<IVertex3d>> vertices, std::vector<uint16_t> indices);

		virtual ~Mesh3d();

		virtual std::vector<std::shared_ptr<IVertex3d>>& getVertices() override;
		virtual std::vector<float>& getRawVertices() override;

		virtual std::vector<uint16_t>& getIndices() override;

		std::string getName() override;

	protected:
		std::string name;

		std::vector<std::shared_ptr<IVertex3d>> vertices;
		std::vector<float> rawVertices;

		std::vector<uint16_t> indices;
	};
}

