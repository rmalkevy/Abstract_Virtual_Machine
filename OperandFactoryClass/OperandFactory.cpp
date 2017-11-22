//
// Created by Roman Malkevych on 11/19/17.
//

#include "OperandFactory.hpp"

OperandFactory::OperandFactory() {
	_arrPf_createOperand[Int8] = &OperandFactory::createInt8;
//	_arrPf_createOperand[Int16] = &OperandFactory::createInt16;
//	_arrPf_createOperand[Int32] = &OperandFactory::createInt32;
//	_arrPf_createOperand[Float] = &OperandFactory::createFloat;
//	_arrPf_createOperand[Double] = &OperandFactory::createDouble;
}

OperandFactory* OperandFactory::getInstance() {
	static OperandFactory instance;
	return &instance;
}

IOperand const* OperandFactory::createOperand(eOperandType type, std::string const &value) const {
	return (this->*_arrPf_createOperand[type])(value);
}

IOperand const* OperandFactory::createInt8(std::string const &value) const {
	return new Int8_Operand(value);
}

//IOperand const* OperandFactory::createInt16(std::string const &value) const {
//	return new Int16_Operand(value);
//}
//
//IOperand const* OperandFactory::createInt32(std::string const &value) const {
//	return new Int32_Operand(value);
//}
//
//IOperand const* OperandFactory::createFloat(std::string const &value) const {
//	return new Float_Operand(value);
//}
//IOperand const* OperandFactory::createDouble(std::string const &value) const {
//	return new Double_Operand(value);
//}