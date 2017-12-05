//
// Created by Roman Malkevych on 11/20/17.
//

#include "AbstractVM.hpp"
#include "../LogException/LogException.hpp"

int AbstractVM::_numberLine = 0;

AbstractVM::AbstractVM(int ac, char** av)
		: _lexer(new Lexer),
		  _taskManager(new TaskManager),
		  _ac(ac),
		  _av(av)
{}

AbstractVM::~AbstractVM() {
	delete _lexer;
	delete _taskManager;
}

void AbstractVM::distributor() {
	if (_ac == 1) {
		logic_forConsoleInput();
	}
//	else {
//		logicForReadingFiles();
//	}
}

void AbstractVM::logic_forConsoleInput() {

	// TODO: how handle problem with command exit and other commands after exit
	std::string	input;

	while (true) {
		TaskManager::taskSignal() = TaskDefault;
		try {
			std::getline(std::cin, input);
			AbstractVM::_numberLine++;

			// Forming package for taskManager
			processLine_forTaskManager(input);

			// Transfer package and receive signal
			taskDistributor();
		}
		catch (const std::exception & e) {
			std::cout << e.what() << std::endl;
			// TODO: logger that write all mistakes in string and in end write it all in cout
		}

		// TODO: if you give exit task - you must turn on flat TaskExit and will not receive else nothing instructions
		if (TaskManager::taskSignal() == TaskExit) {
			break;
		}
	}
}

void AbstractVM::read_fromConsoleInput() {
	std::string	input;

	while (true) {
		std::getline(std::cin, input);
		_instructions.push_back(input);

		if (TaskManager::taskSignal() == TaskExit) { //TODO: I don't know why this item for new logic ?????
			break;
		}
	}
	// TODO: checking after writing all instructions
}

int AbstractVM::getNumberLine() {
	return _numberLine;
}

void AbstractVM::processLine_forTaskManager(const std::string &input) {
	_lexer->processLine_forTaskManager(input);
}

void AbstractVM::taskDistributor() {
	_taskManager->taskDistributor(_lexer->getInfo_forTask());
}