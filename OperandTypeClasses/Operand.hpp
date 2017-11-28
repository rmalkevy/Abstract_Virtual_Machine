//
// Created by Roman Malkevych on 11/24/17.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

#include "../General.hpp"
#include "../OperandTypeClasses/IOperand.hpp"
#include "../PrecisionHandlingClass/PrecisionHandleClass.hpp"

// *** Forward declaration: class FactoryOperand *** //
class FactoryOperand;

template <eOperandType T>
class Operand : public IOperand {
private:
	eOperandType		_eType;
	std::string			_valueString;
	mutable CortageType _valueOperand;

	static const PrecisionHandle  _precision;

public:
	Operand<T>() = delete;
	Operand<T>(Operand<T> const &) = delete;
	Operand<T> &operator=(Operand<T> const &) = delete;

	explicit Operand<T>(std::string const & valueString)
			: _eType(T),
			  _valueString(valueString),
			  _valueOperand(0, 0)
	{
		_precision.stringToValue(_valueString, _valueOperand, _eType);
	}

	~Operand<T>() = default;

	int getPrecision() const override {
		return _eType;
	} // Precision of the type of the instance

	eOperandType getType() const override {
		return _eType;
	} // Type of the instance

	CortageType getValue() const override {
		return _valueOperand;
	}
	IOperand const * operator+( IOperand const & rhs ) const override;

//	IOperand const * operator-( IOperand const & rhs ) const override; // Difference
//	IOperand const * operator*( IOperand const & rhs ) const override; // Product
//	IOperand const * operator/( IOperand const & rhs ) const override; // Quotient
//	IOperand const * operator%( IOperand const & rhs ) const override; // Modulo

	std::string const & toString() const override {
		return _valueString; // String representation of the instance
	}
};

//
//*** Initialization static instance ***//
//

template <eOperandType T>
const PrecisionHandle Operand<T>::_precision;


//
//*** Implementation member functions - operators ***//
//

#include "../OperandFactoryClass/FactoryOperand.hpp"

//*** Sum operator ***//

template <eOperandType T>
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const {
	eOperandType eType = _eType > rhs.getType() ? _eType : rhs.getType();

	if (eType <= Int32) {
		auto value = std::get<0>(_valueOperand) + std::get<0>(rhs.getValue());

//	_precision.IsInRange(value);
// Todo: Check if number fit in Type, if no -> throw exception!!!

		return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
	} else {
		auto value = std::get<1>(_valueOperand) + std::get<1>(rhs.getValue());
		return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
//		_precision.IsInRange(value);
	}
}

#endif //ABSTRACTVM_OPERAND_HPP
