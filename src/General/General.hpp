//
// Created by Roman Malkevych on 11/19/17.
//

#ifndef ABSTRACTVM_GENERAL_HPP
#define ABSTRACTVM_GENERAL_HPP

#include <iostream>
#include <array>

enum eOperandType {
	Int8,
	Int16,
	Int32,
	Float,
	Double,
	NumberOperands
};

enum eTaskSignal {
	TaskExit,
	TaskDefault,
	TaskBreakCircle,
	TaskEmpty = 100
};

enum eToken {
	_1_Push,
	_2_Assert,
	_3_Add,
	_4_Sub,
	_5_Mul,
	_6_Div,
	_7_Mod,
	_8_Pop,
	_9_Dump,
	_10_Print,
	_11_Exit,
	_12_EndCircle,
	_13_Comment,
	_14_Int8,
	_15_Int16,
	_16_Int32,
	_17_Float,
	_18_Double,
	_19_LeftP,  // LeftParenthesis
	_20_RightP, // RightParenthesis
	_21_Number
};

struct InfoForTask {
	InfoForTask(eOperandType type, const std::string &value);
	~InfoForTask() = default;
	InfoForTask() = delete;
	InfoForTask(const InfoForTask &) = delete;
	InfoForTask &operator=(const InfoForTask& info);

	size_t			task;
	eOperandType	type;
	std::string		value;
};

#endif //ABSTRACTVM_GENERAL_HPP
