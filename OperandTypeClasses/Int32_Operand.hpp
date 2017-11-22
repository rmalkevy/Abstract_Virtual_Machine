//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_INT32_OPERAND_HPP
#define ABSTRACTVM_INT32_OPERAND_HPP


#include "IOperand.hpp"

class Int32_Operand : public IOperand {
public:
	Int32_Operand();
	static IOperand* create(std::string const &value);
};


#endif //ABSTRACTVM_INT32_OPERAND_HPP
