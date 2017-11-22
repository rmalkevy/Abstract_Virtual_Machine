//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_DOUBLE_OPERAND_HPP
#define ABSTRACTVM_DOUBLE_OPERAND_HPP


#include "IOperand.hpp"

class Double_Operand : public IOperand {
public:
	static IOperand* create(std::string const &value);
};


#endif //ABSTRACTVM_DOUBLE_OPERAND_HPP
