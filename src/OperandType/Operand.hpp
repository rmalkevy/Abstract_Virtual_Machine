//
// Created by Roman Malkevych on 11/24/17.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

#include <cmath>
#include "../General/General.hpp"
#include "IOperand.hpp"
#include "../LogException/LogException.hpp"

// *** Forward declaration: class FactoryOperand *** //
class FactoryOperand;

template <eOperandType T> // return to eOperandType template,
class Operand : public IOperand {
private:
	eOperandType	_eType;
	std::string		_value;

public:
	explicit Operand<T>(std::string const & valueString)
			: _eType(T),
			  _value(valueString)
	{}
	~Operand<T>() = default;

	Operand<T>() = delete;
	Operand<T>(Operand<T> const &) = delete;
	Operand<T> &operator=(Operand<T> const &) = delete;

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
		return _value; // String representation of the instance
	}
};


//
//*** Implementation member functions - operators ***//
//

#include "../OperandFactory/OperandFactory.hpp"

//*** Sum operator ***//

template <eOperandType T>
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const {

	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables
	if (eType <= Int32) {
		auto value = std::stol(_value) + std::stol(rhs.toString());
		LogException::Instance()->IsInRange<long>(value, eType);
		return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
	}

	// Processing floating point type variables
	auto value = std::stod(_value) + std::stod(rhs.toString());
	LogException::Instance()->IsInRange<double>(value, eType);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
}

//*** Difference operator ***//

template <eOperandType T>
IOperand const * Operand<T>::operator-( IOperand const & rhs ) const {
	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables
	if (eType <= Int32) {
		auto value = std::stol(_value) - std::stol(rhs.toString());
		LogException::Instance()->IsInRange<long>(value, eType);
		return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
	}

	// Processing floating point type variables
	auto value = std::stod(_value) - std::stod(rhs.toString());
	LogException::Instance()->IsInRange<double>(value, eType);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
}

//*** Product operator ***//

template <eOperandType T>
IOperand const * Operand<T>::operator*( IOperand const & rhs ) const {
	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables
	if (eType <= Int32) {
		auto value = std::stol(_value) * std::stol(rhs.toString());
		LogException::Instance()->IsInRange<long>(value, eType);
		return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
	}

	// Processing floating point type variables
	auto value = std::stod(_value) * std::stod(rhs.toString());
	LogException::Instance()->IsInRange<double>(value, eType);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
}

//*** Quotient operator ***//

template <eOperandType T>
IOperand const * Operand<T>::operator/( IOperand const & rhs ) const {
	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables
	if (eType <= Int32) {
		auto denominator = std::stol(rhs.toString());
		if (denominator == 0) throw LogException::DivisionByZeroError();
		auto value = std::stol(_value) / denominator;
		LogException::Instance()->IsInRange<long>(value, eType);
		return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
	}

	// Processing floating point type variables
	auto denominator = std::stod(rhs.toString());
	if (denominator == 0) throw LogException::DivisionByZeroError();
	auto value = std::stod(_value) / denominator;
	LogException::Instance()->IsInRange<double>(value, eType);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
}

//*** Modulo operator ***//

template <eOperandType T>
IOperand const * Operand<T>::operator%( IOperand const & rhs ) const {
	// Find out precision of new Operand
	eOperandType eType = std::max(_eType, rhs.getType());

	// Processing integer type variables
	if (eType <= Int32) {
		auto denominator = std::stol(rhs.toString());
		if (denominator == 0) throw LogException::ModuloByZeroError();
		auto value = std::stol(_value) % denominator;
		LogException::Instance()->IsInRange<long>(value, eType);
		return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
	}

	// Processing floating point type variables
	auto denominator = std::stod(rhs.toString());
	if (denominator == 0) throw LogException::ModuloByZeroError();
	auto value = fmod(std::stod(_value), denominator);
	LogException::Instance()->IsInRange<double>(value, eType);
	return FactoryOperand::Instance()->createOperand(std::to_string(value), eType);
}

#endif //ABSTRACTVM_OPERAND_HPP
