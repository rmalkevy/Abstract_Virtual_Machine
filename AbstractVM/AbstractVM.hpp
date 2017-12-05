//
// Created by Roman Malkevych on 11/20/17.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP

#include <stack>
#include "../OperandFactory/FactoryOperand.hpp"
#include "../Lexer/Lexer.hpp"
#include "../TaskManager/TaskManager.hpp"

class LogException;

class AbstractVM {
private:
	Lexer						*_lexer;
	TaskManager					*_taskManager;
	int							_ac;
	char						**_av;
	static int					_numberLine;
	std::vector<std::string>	_instructions;

public:
	AbstractVM(int ac, char **av);
	~AbstractVM();

	void	distributor();
	void	logic_forConsoleInput();
//	void	logic_forReadingFiles();

	void	read_fromConsoleInput();
//	void	read_fromFile();

	// Delegate function from Lexer to AbstractVM
	void	processLine_forTaskManager(const std::string & input);

	// Delegate function from TaskManager to AbstractVM
	void	taskDistributor();

	static int	getNumberLine();
	//TODO: write all exceptions in list and write they all to console near program end
	// static that write all exceptions in static list
};


#endif //ABSTRACTVM_ABSTRACTVM_HPP
