//
// Created by Roman Malkevych on 11/19/17.
//

#include "OperandFactory.hpp"
#include "../OperandType/Operand.hpp"

FactoryOperand::FactoryOperand()
		: _arrPf{
						 &FactoryOperand::createInt8,
						 &FactoryOperand::createInt16,
						 &FactoryOperand::createInt32,
						 &FactoryOperand::createFloat,
						 &FactoryOperand::createDouble
				 }
{}

FactoryOperand* FactoryOperand::Instance() {
	static FactoryOperand instance;
	return &instance;
}

IOperand const * FactoryOperand::createOperand(const std::string &value, eOperandType eType) {
	return (this->*_arrPf[eType])(value);
}

IOperand const * FactoryOperand::createInt8(const std::string &value) {
	return new Operand<Int8>(value);
}

IOperand const * FactoryOperand::createInt16(const std::string &value) {
	return new Operand<Int16>(value);
}

IOperand const * FactoryOperand::createInt32(const std::string &value) {
	return new Operand<Int32>(value);
}

IOperand const * FactoryOperand::createFloat(const std::string &value) {
	return new Operand<Float>(value);
}

IOperand const * FactoryOperand::createDouble(const std::string &value) {
	return new Operand<Double>(value);
}