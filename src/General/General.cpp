//
// Created by Roman Malkevych on 11/30/17.
//

#include "General.hpp"

InfoForTask::InfoForTask(eOperandType type, const std::string &value)
		: task(0),
		  type(type),
		  value(value)
{}

InfoForTask& InfoForTask::operator=(const InfoForTask &info) {
	if (this != &info) {
		task = info.task;
		type = info.type;
		value = info.value;
	}
	return *this;
}