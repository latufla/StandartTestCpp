#include "Model3d.h"


namespace sqr{
	const std::string Model3d::DEFAULT_MODEL = "circle";

	Model3d::Model3d(std::string keyName, std::vector<std::shared_ptr<IMesh3d>>& meshes) 
		: keyName(keyName), meshes(meshes){

	}

	Model3d::~Model3d() {
		
	}

	std::string Model3d::getKeyName() {
		return keyName;
	}

	std::vector<std::shared_ptr<IMesh3d>>& Model3d::getMeshes() {
		return meshes;
	}
}
