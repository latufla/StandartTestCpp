#pragma once
#include "interfaces\IMainHudData.h"

// default
// DTO, so all fields public
namespace sqr{
	class MainHudData : public IMainHudData{
	public:
		MainHudData() = default;
		virtual ~MainHudData();

		uint32_t score = 0;
	};
}

