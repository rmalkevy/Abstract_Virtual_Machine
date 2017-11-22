//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_IOPERAND_HPP
#define ABSTRACTVM_IOPERAND_HPP

#include <iostream>
#include "../General.hpp"

class IOperand {
public:
	virtual int getPrecision() const = 0; // Precision of the type of the instance
	virtual eOperandType getType() const = 0; // Type of the instance

	virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
//	virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
//	virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
//	virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
//	virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

	virtual std::string const & toString() const = 0; // String representation of the instance

	virtual ~IOperand() {}
};

#endif //ABSTRACTVM_IOPERAND_HPP
