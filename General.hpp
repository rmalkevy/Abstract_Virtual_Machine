//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_GENERAL_HPP
#define ABSTRACTVM_GENERAL_HPP

#include <iostream>
#include <array>
#include <string>

enum eOperandType {
	Int8,
	Int16,
	Int32,
	Float,
	Double,
	NumberOperands
};

#include "PrecisionHandlingClass/PrecisionHandleClass.hpp"

#endif //ABSTRACTVM_GENERAL_HPP
