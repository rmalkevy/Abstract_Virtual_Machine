//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_OPERANDFACTORY_HPP
#define ABSTRACTVM_OPERANDFACTORY_HPP

#include "../General.hpp"
#include "../OperandTypeClasses/IOperand.hpp"
#include "../OperandTypeClasses/Templete_Operand.hpp"

// *** Singleton class with factory method *** //
class OperandFactory {
private:
	OperandFactory();
	IOperand const * createInt8( std::string const & value ) const;
//	IOperand const * createInt16( std::string const & value ) const;
//	IOperand const * createInt32( std::string const & value ) const;
//	IOperand const * createFloat( std::string const & value ) const;
//	IOperand const * createDouble( std::string const & value ) const;

	using _pf_createOperand = const IOperand* (OperandFactory::*)(std::string const &) const;
	std::array<_pf_createOperand, NumberOperands> _arrPf_createOperand;

public:
	~OperandFactory() = default;
	OperandFactory(OperandFactory const &) = delete;
	OperandFactory &operator=(OperandFactory const &) = delete;

	IOperand const * createOperand(eOperandType type, std::string const & value) const;
	static OperandFactory *getInstance();
};


#endif //ABSTRACTVM_OPERANDFACTORY_HPP
