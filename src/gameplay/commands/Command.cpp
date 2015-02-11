#include "Command.h"


namespace sg {
	Command::Command(IEngine* engine) 
		: engine(engine){
	}


	Command::~Command() {
	}

	bool Command::tryToExecute() {
		bool res = canExecute();
		if(res)
			execute();

		return res;
	}

	bool Command::canExecute() {
		return true;
	}
}
