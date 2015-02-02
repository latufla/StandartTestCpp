#pragma once
#include "src\gui\interfaces\IMainHudData.h"

// default
// DTO, so all fields public
class MainHudData : public sqr::IMainHudData {
public:
	MainHudData() = default;
	virtual ~MainHudData();

	uint32_t score = 0;
};
