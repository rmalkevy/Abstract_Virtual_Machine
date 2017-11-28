//
// Created by Roman Malkevych on 11/19/17.
//

#include "FactoryOperand.hpp"
#include "../OperandTypeClasses/Operand.hpp"

FactoryOperand::FactoryOperand() {
	_arrPf[Int8] = &FactoryOperand::createInt8;
	_arrPf[Int16] = &FactoryOperand::createInt16;
	_arrPf[Int32] = &FactoryOperand::createInt32;
	_arrPf[Float] = &FactoryOperand::createFloat;
	_arrPf[Double] = &FactoryOperand::createDouble;
}

IOperand const * FactoryOperand::createOperand(const std::string &value, eOperandType eType) {
	return (this->*_arrPf[eType])(value);
}

FactoryOperand *FactoryOperand::Instance() {
	static FactoryOperand instance;
	return &instance;
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