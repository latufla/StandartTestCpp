#pragma once
#include "ICommand.h"
#include "..\interfaces\IEngine.h"

namespace sg {
	class Command : public ICommand{
	public:
		Command() = delete;
		Command(IEngine*);

		virtual ~Command();

		virtual bool canExecute() override;
		virtual bool tryToExecute() override;
	
	protected:
		virtual void execute() = 0;

		IEngine* engine;
	};
}

