//
// Created by Roman Malkevych on 11/22/17.
//

#ifndef ABSTRACTVM_TEMPLETE_OPERAND_H
#define ABSTRACTVM_TEMPLETE_OPERAND_H

#include "IOperand.hpp"
#include "../AbstractVM_SingletonClass/AbstractVM.hpp"
#include "../OperandFactoryClass/OperandFactory.hpp"

template <typename T>
class Operand : public IOperand {
private:
	static const PrecisionHandle<T>  _precision;

	std::string		_valueString;
	T				_value;

public:
	Operand() = delete;
	Operand(Operand const &) = delete;
	Operand &operator=(Operand const &) = delete;

	explicit Operand(std::string const & valueString, T value = 0)
			: _valueString(valueString),
			  _value(value)
	{}

	~Operand() = default;

	int getPrecision() const override {
		return 0;
	} // Precision of the type of the instance

	eOperandType getType() const override {
		return Int8;
	} // Type of the instance

	IOperand const * operator+( IOperand const & rhs ) const override {
		auto value = Operand::_precision.stringToValue(rhs.toString(), rhs.getPrecision());
		value += Operand::_precision.stringToValue(toString(), getPrecision());
		Operand::_precision.IsInRange(value);


		// Todo: Check if number fit in Type, if no -> throw exception!!!

		return OperandFactory::getInstance()->createOperand(rhs.getType(), std::to_string(value));
	} // Sum
//	IOperand const * operator-( IOperand const & rhs ) const override; // Difference
//	IOperand const * operator*( IOperand const & rhs ) const override; // Product
//	IOperand const * operator/( IOperand const & rhs ) const override; // Quotient
//	IOperand const * operator%( IOperand const & rhs ) const override; // Modulo

	std::string const & toString() const override {
		return _valueString; 							// String representation of the instance
	}
};

template <typename T>
const PrecisionHandle<T> Operand<T>::_precision;

#endif //ABSTRACTVM_TEMPLETE_OPERAND_H