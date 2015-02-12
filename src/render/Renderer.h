#pragma once
#include "interfaces/IRenderEngine.h"
#include <memory>
#include "interfaces/ILoader.h"
#include <map>

#include <SFML/Graphics.hpp>
#include <glm.hpp>
#include "../gui/interfaces/IMainHud.h"

// default
// should impl one more connector to sfml and gl
namespace sr {
	class Renderer : public IRenderEngine {
	public:
		Renderer() = delete;
		Renderer(std::shared_ptr<ILoader> assetLoader, std::shared_ptr<sr::IMainHud>);

		virtual ~Renderer();
	
		virtual void addObject(uint32_t id, std::shared_ptr<IView> object) override;
		virtual void removeObject(uint32_t id) override;

		virtual std::shared_ptr<IView> getObjectBy(uint32_t id) override;
		virtual bool hasObject(uint32_t id) override;

		virtual bool doStep(long long step) override;

		virtual bool getMouseLeftDown() override;
		virtual int32_t getMouseOver() override;
		
		virtual glm::vec2 getWindowSize() override;

		virtual std::shared_ptr<sr::IMainHud> getMainHud() override;
	protected:
		int32_t mouseOver;

		void calcMouseOverObject(glm::mat4&);
		bool isInsideTrianle(glm::vec3& p, glm::vec3& a, glm::vec3& b, glm::vec3& c);

		std::shared_ptr<ILoader> assetLoader;
		std::map<uint32_t, std::shared_ptr<IView>> idToObject;

		std::shared_ptr<sf::RenderWindow> window;
		std::shared_ptr<sr::IMainHud> mainHud;
	};
}
