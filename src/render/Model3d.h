#pragma once
#include "interfaces/IModel3d.h"

namespace sr {
	class Model3d : public IModel3d{
	public:
		Model3d() = delete;
		Model3d(std::string keyName, std::vector<std::shared_ptr<IMesh3d>>& meshes);
		
		virtual ~Model3d();

		virtual std::vector<std::shared_ptr<IMesh3d>>& getMeshes() override;
		virtual std::string getKeyName() override;

		virtual std::shared_ptr<IMesh3d>& getHitMesh() override;

		static const std::string DEFAULT_MODEL;

	protected:
		std::string keyName;
		std::vector<std::shared_ptr<IMesh3d>> meshes;
	};
}

