//
// Created by Roman Malkevych on 11/20/17.
//

#include "AbstractVM.hpp"
#include "../LogException/LogException.hpp"

int AbstractVM::_numberLine = 0;

AbstractVM::AbstractVM(int ac, char** av)
		: _ac(ac),
		  _av(av),
		  _lexer(new Lexer),
		  _taskManager(new TaskManager),
		  _logInstructions(),
		  _logExceptions()
{}

AbstractVM::~AbstractVM() {
	delete _lexer;
	delete _taskManager;
}

void AbstractVM::distributor() {
	if (_ac == 1) {
		logic_forConsoleInput();
	}
	else {
		logic_forReadingFiles();
	}
}

void AbstractVM::logic_forConsoleInput() {

	// TODO: how handle problem with command exit and other commands after exit
	std::string	input;

	while (true) {
		try {
			std::getline(std::cin, input);
			_logInstructions.push_back(input);
			AbstractVM::_numberLine++;

			// Forming package for taskManager
			processLine_forTaskManager(input);

			// Transfer package and receive signal
			taskDistributor();
		}
		catch (const std::exception & e) {
			_logExceptions.push_back(e.what());
			std::cout << e.what() << std::endl;
		}

		// TODO: if you give exit task - you must turn on flat TaskExit and will not receive else nothing instructions
		if (TaskManager::taskSignal() == TaskExit
			&& TaskManager::breakCircle() == TaskBreakCircle) {
			break;
		}
	}
	log_toFileInstructions();
	log_toFileExceptions();
}

void AbstractVM::logic_forReadingFiles() {
	std::string     line;

	for (int i = 1; i < _ac; i++) {
		std::ifstream   inStream(_av[i]);

		// *** Check for valid file *** //
		try {
			if (! inStream.is_open()) {
				throw LogException::OpeningFileError();
			}
		}
		catch (const std::exception & e) {
			_logExceptions.push_back(std::string(e.what()));
			std::cout << e.what() << std::endl;
		}

		// *** Read file and processing all lines *** //
		while ( std::getline (inStream, line) )
		{
			try {
				AbstractVM::_numberLine++;

				// Forming package for taskManager
				processLine_forTaskManager(line);

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
		inStream.close();
	}
	log_toFileExceptions();
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

void AbstractVM::log_toFileInstructions() {
	std::ofstream ofstream("logInstructions.txt");
	for (const auto & item : _logInstructions) {
		ofstream << item << "\n";
	}
}

void AbstractVM::log_toFileExceptions() {
	std::ofstream ofstream("logExceptions.txt");
	for (const auto & item : _logExceptions) {
		ofstream << item << "\n";
	}
}
