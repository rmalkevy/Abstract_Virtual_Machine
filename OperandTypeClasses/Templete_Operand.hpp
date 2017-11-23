//
// Created by Roman Malkevych on 11/22/17.
//

#ifndef ABSTRACTVM_TEMPLETE_OPERAND_H
#define ABSTRACTVM_TEMPLETE_OPERAND_H

#include "../General.hpp"
#include "../OperandTypeClasses/IOperand.hpp"

template <typename T>
class Operand : public IOperand {
private:
	static const PrecisionHandle<T>  _precision;

	std::string		_valueString;
	eOperandType	_eType;
	T				_value;

public:
	Operand() = delete;
	Operand(Operand const &) = delete;
	Operand &operator=(Operand const &) = delete;

	Operand(std::string const & valueString, eOperandType type, T value = 0)
			: _valueString(valueString),
			  _eType(type),
			  _value(value)
	{}

	~Operand() = default;

	int getPrecision() const override {
		return 0;
	} // Precision of the type of the instance

	eOperandType getType() const override {
		return _eType;
	} // Type of the instance

	IOperand const * operator+( IOperand const & rhs ) const override {
		auto value = Operand::_precision.stringToValue(rhs.toString(), rhs.getPrecision());
		value += Operand::_precision.stringToValue(toString(), getPrecision());
		Operand::_precision.IsInRange(value);


		// Todo: Check if number fit in Type, if no -> throw exception!!!

		return new Operand(std::to_string(value), rhs.getType());
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