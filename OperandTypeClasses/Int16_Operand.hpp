//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_INT16_OPERAND_HPP
#define ABSTRACTVM_INT16_OPERAND_HPP


#include "IOperand.hpp"

class Int16_Operand : public IOperand {
private:
	std::string _valueStringInt16;
	std::int16_t _valueInt16;

public:
	Int16_Operand() = delete;
	Int16_Operand(Int16_Operand const &) = delete;
	Int16_Operand &operator=(Int16_Operand const &) = delete;

	explicit Int16_Operand(std::string const & value);
	//Int16_Operand(std::int16_t valueInt16, std::string const & valueStringInt16);
	~Int16_Operand() = default;

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



#endif //ABSTRACTVM_INT16_OPERAND_HPP
