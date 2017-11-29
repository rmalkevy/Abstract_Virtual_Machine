//
// Created by Roman Malkevych on 11/20/17.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP

#include "../OperandFactoryClass/FactoryOperand.hpp"
#include "../Lexer/Lexer.hpp"

class AbstractVM {
private:
	FactoryOperand	*_factoryOperand;
	Lexer 			*lexer;

public:
	AbstractVM(int ac, char **av);
	~AbstractVM();

	//TODO: write all exceptions in list and write they all to console near program end
	// static that write all exceptions in static list
};


#endif //ABSTRACTVM_ABSTRACTVM_HPP
