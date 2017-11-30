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

enum eTask {
	TaskExit,
	TaskDefault
};

struct InfoForTask {
	InfoForTask(bool push, bool assert, eOperandType type, const std::string &value);
	~InfoForTask() = default;
	InfoForTask() = delete;
	InfoForTask(const InfoForTask &) = delete;
	InfoForTask &operator=(const InfoForTask&) = delete;

	size_t			task;
	bool			pushCheck;
	bool			assertCheck;
	eOperandType	typeCheck;
	std::string		numberString;
};

#endif //ABSTRACTVM_GENERAL_HPP
