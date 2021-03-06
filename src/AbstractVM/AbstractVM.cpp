//
// Created by Roman Malkevych on 11/20/17.
//

#include "AbstractVM.hpp"
#include "../LogException/LogException.hpp"

int AbstractVM::_numberLine = 0;

AbstractVM::AbstractVM(int ac, char** av)
		: _ac(ac),
		  _av(av),
		  _parser(std::make_unique<Parser>()),
		  _taskManager(std::make_unique<TaskManager>()),
		  _logInstructions(),
		  _logExceptions()
{}

void AbstractVM::distributor() {
	if (_ac == 1) {
		logic_forConsoleInput();
	}
	else if (_ac == 2) {
		logic_forReadingFiles();
	}
	else
		std::cout << "Too many arguments" << std::endl;
}

void AbstractVM::logic_forConsoleInput() {

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
		}

		if (TaskManager::taskSignal() == TaskExit
			&& TaskManager::breakCircle() == TaskBreakCircle) {
			break;
		}
	}
	try {
		if (TaskManager::taskSignal() != TaskExit) {
			throw LogException::NoExitInstructionError();
		}
	}
	catch (const std::exception & e) {
		_logExceptions.push_back(e.what());
	}
	if (_logExceptions.empty())
		log_toConsoleResults();
	else
		log_toConsoleExceptions();
	log_toFileInstructions();
	log_toFileExceptions();
}

void AbstractVM::logic_forReadingFiles() {
	std::string     line;

	std::ifstream   inStream(_av[1]);

	// *** Check for valid file *** //
	try {
		if (! inStream.is_open()) {
			throw LogException::OpeningFileError();
		}
	}
	catch (const std::exception & e) {
		_logExceptions.push_back(std::string(e.what()));
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
			_logExceptions.push_back(e.what());
		}

		if (TaskManager::taskSignal() == TaskExit) {
			break;
		}
	}
	try {
		if (TaskManager::taskSignal() != TaskExit) {
			throw LogException::NoExitInstructionError();
		}
	}
	catch (const std::exception & e) {
		_logExceptions.push_back(e.what());
	}
	inStream.close();
	if (_logExceptions.empty())
		log_toConsoleResults();
	else
		log_toConsoleExceptions();
	log_toFileExceptions();
}

int AbstractVM::getNumberLine() {
	return _numberLine;
}

void AbstractVM::processLine_forTaskManager(const std::string &input) {
	_parser->processLine_forTaskManager(input);
}

void AbstractVM::taskDistributor() {
	_taskManager->taskDistributor(_parser->getInfo_forTask());
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

void AbstractVM::log_toConsoleResults() const {
	_taskManager->printLogResults();
}

void AbstractVM::log_toConsoleExceptions() const {
	for (const auto & item : _logExceptions) {
		std::cout << item << std::endl;
	}
}