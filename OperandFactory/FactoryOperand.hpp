//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_OPERANDFACTORY_HPP
#define ABSTRACTVM_OPERANDFACTORY_HPP

#include "../General.hpp"
#include "../OperandType/IOperand.hpp"

// *** Forward declaration: template <eOperandType T> class Operand; *** //
template <typename T>
class Operand;

class FactoryOperand {
private:

	IOperand const * createInt8(const std::string &value);
	IOperand const * createInt16(const std::string &value);
	IOperand const * createInt32(const std::string &value);
	IOperand const * createFloat(const std::string &value);
	IOperand const * createDouble(const std::string &value);

	using _pfCreateOperand = IOperand const * (FactoryOperand::*)(const std::string &);
	_pfCreateOperand _arrPf[NumberOperands];
	//std::array<_pfCreateOperand, NumberOperands> _arrPf;

public:
	FactoryOperand();
	~FactoryOperand() = default;
	FactoryOperand(const FactoryOperand&) = delete;
	FactoryOperand &operator=(const FactoryOperand&) = delete;

	IOperand const * createOperand(const std::string &value, eOperandType eType);
};

#endif //ABSTRACTVM_OPERANDFACTORY_HPP
