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
	TaskEmpty = 100
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
