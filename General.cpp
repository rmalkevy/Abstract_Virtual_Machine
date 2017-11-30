//
// Created by Roman Malkevych on 11/30/17.
//

#include "General.hpp"

InfoForTask::InfoForTask(bool push, bool assert, eOperandType type, const std::string &value)
		: task(11),
		  pushCheck(push),
		  assertCheck(assert),
		  typeCheck(type),
		  numberString(value)
{}