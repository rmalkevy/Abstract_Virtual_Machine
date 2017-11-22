//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_INT8_OPERAND_HPP
#define ABSTRACTVM_INT8_OPERAND_HPP

#include "IOperand.hpp"
#include "../AbstractVM_SingletonClass/AbstractVM.hpp"
#include "../OperandFactoryClass/OperandFactory.hpp"

class Int8_Operand : public IOperand {
private:
	static const PrecisionHandle<std::int8_t>  _precision;

	std::string		_valueStringInt8;
	std::int8_t		_valueInt8;

public:
	Int8_Operand() = delete;
	Int8_Operand(Int8_Operand const &) = delete;
	Int8_Operand &operator=(Int8_Operand const &) = delete;

	Int8_Operand(std::string const & value, std::int8_t valueInt8 = 0);
	~Int8_Operand() = default;

	int getPrecision() const override; // Precision of the type of the instance
	eOperandType getType() const override; // Type of the instance
	//std::int8_t getValue() const;

	IOperand const * operator+( IOperand const & rhs ) const override; // Sum
//	IOperand const * operator-( IOperand const & rhs ) const override; // Difference
//	IOperand const * operator*( IOperand const & rhs ) const override; // Product
//	IOperand const * operator/( IOperand const & rhs ) const override; // Quotient
//	IOperand const * operator%( IOperand const & rhs ) const override; // Modulo

	std::string const & toString() const override; // String representation of the instance
};


#endif //ABSTRACTVM_INT8_OPERAND_HPP
