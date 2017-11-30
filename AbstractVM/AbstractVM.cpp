//
// Created by Roman Malkevych on 11/20/17.
//

#include "AbstractVM.hpp"

AbstractVM::AbstractVM(int ac, char** av)
		: _lexer(new Lexer),
		  _taskManager(new TaskManager),
		  _ac(ac),
		  _av(av)
{}

AbstractVM::~AbstractVM() {
	delete _lexer;
}

void AbstractVM::distributor() {
	if (_ac == 1) {
		logicForCycling();
	}
//	else {
//		logicForReadingFiles();
//	}
}

void AbstractVM::logicForCycling() {
	std::string	input;
	eTask		task;

	while (true) {
		std::getline(std::cin, input);
		_lexer->processLine_forTaskManager(input);
		task = _taskManager->taskDistributor(_lexer->getInfo_forTask());
		if (task == TaskExit) { break; }
	}
}