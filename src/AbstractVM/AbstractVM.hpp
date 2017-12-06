//
// Created by Roman Malkevych on 11/20/17.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP

#include <fstream>
#include <sstream>
#include "../OperandFactory/OperandFactory.hpp"
#include "../Lexer/Lexer.hpp"
#include "../TaskManager/TaskManager.hpp"

class LogException;

class AbstractVM {
private:
	int							_ac;
	char						**_av;
	static int					_numberLine;
	Lexer						*_lexer;
	TaskManager					*_taskManager;
	std::vector<std::string>	_logInstructions;
	std::vector<std::string>	_logExceptions;

public:
	AbstractVM(int ac, char **av);
	~AbstractVM();

	void		distributor();
	void		logic_forConsoleInput();
	void		logic_forReadingFiles();
	static int	getNumberLine();

	// Delegate function from Lexer to AbstractVM
	void		processLine_forTaskManager(const std::string & input);

	// Delegate function from TaskManager to AbstractVM
	void		taskDistributor();

	void		log_toFileInstructions();
	void		log_toFileExceptions();
};


#endif //ABSTRACTVM_ABSTRACTVM_HPP
