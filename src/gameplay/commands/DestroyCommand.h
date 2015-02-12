#pragma once
#include "Command.h"

namespace sg {
	class DestroyCommand : public Command{
	public:
		DestroyCommand(IEngine*, uint32_t objectId);
		virtual ~DestroyCommand() override;

		virtual bool canExecute() override;

	protected:
		virtual void execute() override;

		uint32_t objectId;
	};
}

