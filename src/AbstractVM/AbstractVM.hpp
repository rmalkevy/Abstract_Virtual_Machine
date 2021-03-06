//
// Created by Roman Malkevych on 11/20/17.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP

#include <fstream>
#include <sstream>
#include "../OperandFactory/OperandFactory.hpp"
#include "../TaskManager/TaskManager.hpp"
#include "../Parser/Parser.hpp"

class LogException;

class AbstractVM {
private:
	int								_ac;
	char							**_av;
	static int						_numberLine;
	std::unique_ptr<Parser>			_parser;
	std::unique_ptr<TaskManager>	_taskManager;
	std::vector<std::string>		_logInstructions;
	std::vector<std::string>		_logExceptions;

public:
	AbstractVM() = default;
	AbstractVM(int ac, char **av);
	~AbstractVM() = default;
	AbstractVM(const AbstractVM &) = delete;
	const AbstractVM &operator=(const AbstractVM &) = delete;

	void		distributor();
	void		logic_forConsoleInput();
	void		logic_forReadingFiles();
	static int	getNumberLine();

	// Delegate function from Parser to AbstractVM
	void		processLine_forTaskManager(const std::string & input);

	// Delegate function from TaskManager to AbstractVM
	void		taskDistributor();

	void		log_toFileInstructions();
	void		log_toFileExceptions();
	void		log_toConsoleResults() const;
	void		log_toConsoleExceptions() const;
};


#endif //ABSTRACTVM_ABSTRACTVM_HPP
