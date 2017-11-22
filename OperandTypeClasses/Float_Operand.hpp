//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_FLOAT_OPERAND_HPP
#define ABSTRACTVM_FLOAT_OPERAND_HPP


#include "IOperand.hpp"

class Float_Operand : public IOperand {
public:
	static IOperand* create(std::string const &value);
};


#endif //ABSTRACTVM_FLOAT_OPERAND_HPP
