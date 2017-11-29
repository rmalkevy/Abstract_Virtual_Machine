//
// Created by Roman Malkevych on 11/24/17.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

#include "../General.hpp"
#include "../OperandTypeClasses/IOperand.hpp"
#include "../LoggerException/LoggerException.hpp"

// *** Forward declaration: class FactoryOperand *** //
class FactoryOperand;

template <typename T>
class Operand : public IOperand {
private:
	eOperandType					_eType;
	std::string						_valueString;
	static const LoggerException 	_loggerException;

public:
	Operand<T>() = delete;
	Operand<T>(Operand<T> const &) = delete;
	Operand<T> &operator=(Operand<T> const &) = delete;

	explicit Operand<T>(std::string const & valueString, eOperandType eType)
			: _eType(eType),
			  _valueString(valueString)
	{
		//_precision.stringToValue(_valueString, _valueOperand, _eType);
	}

	~Operand<T>() = default;

	int getPrecision() const override {
		return _eType;
	} // Precision of the type of the instance

	eOperandType getType() const override {
		return _eType;
	} // Type of the instance

	IOperand const * operator+( IOperand const & rhs ) const override; // Plus
	IOperand const * operator-( IOperand const & rhs ) const override; // Difference
	IOperand const * operator*( IOperand const & rhs ) const override; // Product
	IOperand const * operator/( IOperand const & rhs ) const override; // Quotient
	IOperand const * operator%( IOperand const & rhs ) const override; // Modulo

	std::string const & toString() const override {
		return _valueString; // String representation of the instance
	}
};

//
//*** Initialization static instance ***//
//

template <typename T>
const LoggerException Operand<T>::_loggerException;


//
//*** Implementation member functions - operators ***//
//

#include "../OperandFactoryClass/FactoryOperand.hpp"

//*** Sum operator ***//

template <typename T>
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const {

	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables
	if (eType <= Int32) {
		auto value = std::stol(_valueString) + std::stol(rhs.toString());
		_loggerException.IsInRange<T, long>(value);
		return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
	}

	// Processing floating point type variables
	auto value = std::stod(_valueString) + std::stod(rhs.toString());
	_loggerException.IsInRange<T, double>(value);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
}

//*** Difference operator ***//

template <typename T>
IOperand const * Operand<T>::operator-( IOperand const & rhs ) const {
	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables
	if (eType <= Int32) {
		auto value = std::stol(_valueString) - std::stol(rhs.toString());
		_loggerException.IsInRange<T, long>(value);
		return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
	}

	// Processing floating point type variables
	auto value = std::stod(_valueString) - std::stod(rhs.toString());
	_loggerException.IsInRange<T, double>(value);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
}

//*** Product operator ***//

template <typename T>
IOperand const * Operand<T>::operator*( IOperand const & rhs ) const {
	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables
	if (eType <= Int32) {
		auto value = std::stol(_valueString) * std::stol(rhs.toString());
		_loggerException.IsInRange<T, long>(value);
		return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
	}

	// Processing floating point type variables
	auto value = std::stod(_valueString) * std::stod(rhs.toString());
	_loggerException.IsInRange<T, double>(value);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
}

//*** Quotient operator ***//

template <typename T>
IOperand const * Operand<T>::operator/( IOperand const & rhs ) const {
	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables
	if (eType <= Int32) {
		auto value = std::stol(_valueString) / std::stol(rhs.toString());
		_loggerException.IsInRange<T, long>(value);
		return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
	}

	// Processing floating point type variables
	auto value = std::stod(_valueString) / std::stod(rhs.toString());
	_loggerException.IsInRange<T, double>(value);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
}

//*** Modulo operator ***//

template <typename T>
IOperand const * Operand<T>::operator%( IOperand const & rhs ) const {
	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables

	// Maybe exception for modulo on double numbers???
	auto value = std::stol(_valueString) % std::stol(rhs.toString());
	_loggerException.IsInRange<T, long>(value);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);


	// Processing floating point type variables
//	auto value = std::stod(_valueString) % std::stod(rhs.toString());
//	_precision.IsInRange<T, double>(value);
//	return FactoryOperand::Instance()->createOperand(std::to_string(value), _eType);
}

#endif //ABSTRACTVM_OPERAND_HPP
