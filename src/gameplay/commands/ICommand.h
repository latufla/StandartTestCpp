#pragma once

namespace sg {
	class ICommand {
	public:
		virtual bool canExecute() = 0;
		virtual bool tryToExecute() = 0;
	};
}

