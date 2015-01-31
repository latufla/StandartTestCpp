#pragma once
#include "interfaces/IRenderEngine.h"
#include <memory>
#include "interfaces/ILoader.h"
#include <unordered_map>

#include <SFML/Graphics.hpp>
#include <glm.hpp>

// default
// should impl one more connector to sfml and gl
// and add components to renderer
// but it`s not a spaceship
namespace sqr {
	class RenderEngine : public IRenderEngine {
	public:
		RenderEngine() = delete;
		RenderEngine(std::shared_ptr<ILoader> assetLoader);

		virtual ~RenderEngine();
	
		virtual void addObject(uint32_t id, std::shared_ptr<IView> object) override;
		virtual void removeObject(uint32_t id) override;

		virtual std::shared_ptr<IView> getObjectBy(uint32_t id) override;

		virtual bool doStep(double step) override;

		virtual bool getMouseLeftDown() override;
		virtual int32_t getMouseOver() override;

	protected:
		int32_t mouseOver;

		void calcMouseOverObject(glm::mat4&);
		bool isInsideTrianle(glm::vec3& p, glm::vec3& a, glm::vec3& b, glm::vec3& c);

		std::shared_ptr<ILoader> assetLoader;
		std::unordered_map<uint32_t, std::shared_ptr<IView>> idToObject;

		std::shared_ptr<sf::RenderWindow> window;

	};
}
