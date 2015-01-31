#pragma once
#include "IRenderer.h"
#include <memory>
#include "ILoader.h"
#include <unordered_map>

// default
namespace sqr {
	class Renderer : public IRenderer {
	public:
		Renderer() = delete;
		Renderer(std::shared_ptr<ILoader> assetLoader);

		virtual ~Renderer();
	
		virtual void addObject(uint32_t id, std::shared_ptr<IView> object) override;
		virtual void removeObject(uint32_t id) override;

		virtual std::shared_ptr<IView> getObjectBy(uint32_t id) override;

		virtual bool doStep(double step) override;

	protected:
		std::shared_ptr<ILoader> assetLoader;
		std::unordered_map<uint32_t, std::shared_ptr<IView>> idToObject;
	};
}
