//
// Created by Roman Malkevych on 11/20/17.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP

#include "../OperandFactory/FactoryOperand.hpp"
#include "../Lexer/Lexer.hpp"
#include "../TaskManager/TaskManager.hpp"

class AbstractVM {
private:

	Lexer		*_lexer;
	TaskManager *_taskManager;
	int			_ac;
	char		**_av;

public:
	AbstractVM(int ac, char **av);
	~AbstractVM();

	void	distributor();
	void	logicForCycling();
	//void	logicForReadingFiles();

	//TODO: write all exceptions in list and write they all to console near program end
	// static that write all exceptions in static list
};


#endif //ABSTRACTVM_ABSTRACTVM_HPP
