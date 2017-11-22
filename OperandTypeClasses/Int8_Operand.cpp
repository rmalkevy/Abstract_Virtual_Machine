//
// Created by Roman Malkevych on 11/19/17.
//

#include "Int8_Operand.hpp"

const PrecisionHandle<std::int8_t> Int8_Operand::_precision;

Int8_Operand::Int8_Operand(std::string const &value, int8_t valueInt8)
	: _valueStringInt8(value),
	  _valueInt8(valueInt8)
{}

int Int8_Operand::getPrecision() const {
	// TODO: Why int??? What is this precision mean?
	return Int8;
}

eOperandType Int8_Operand::getType() const {
	return Int8;
}

IOperand const* Int8_Operand::operator+(IOperand const &rhs) const {
	auto value = Int8_Operand::_precision.stringToValue(rhs.toString(), rhs.getPrecision());
	value += Int8_Operand::_precision.stringToValue(toString(), getPrecision());
	Int8_Operand::_precision.IsInRange(value);


	// Todo: Check if number fit in Type, if no -> throw exception!!!

	return OperandFactory::getInstance()->createOperand(rhs.getType(), std::to_string(value));
}

std::string const& Int8_Operand::toString() const {
	return _valueStringInt8;
}