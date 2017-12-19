//
// Created by Roman Malkevych on 11/30/17.
//

#include "TaskManager.hpp"
#include "../LogException/LogException.hpp"
#include <sstream>

eTaskSignal TaskManager::_taskSignal = TaskDefault;
eTaskSignal TaskManager::_breakCircle = TaskDefault;

TaskManager::TaskManager()
		: _stack(),
		  _info(NumberOperands, ""),
		  _arrPfTask{
							 &TaskManager::_pushTask,
							 &TaskManager::_assertTask,
							 &TaskManager::_addTask,
							 &TaskManager::_subTask,
							 &TaskManager::_mulTask,
							 &TaskManager::_divTask,
							 &TaskManager::_modTask,
							 &TaskManager::_popTask,
							 &TaskManager::_dumpTask,
							 &TaskManager::_printTask,
							 &TaskManager::_exitTask,
							 &TaskManager::_endCircleTask,
							 &TaskManager::_commentTask
					 },
		  _logPrints()
{}

eTaskSignal TaskManager::taskDistributor(const InfoForTask &info) {
	_info = info;
	if (info.task == TaskEmpty)
		return TaskEmpty;
	return (this->*_arrPfTask[info.task])();
}

eTaskSignal TaskManager::_pushTask() {
//	std::cout << "pushTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (_info.type <= Int32) {
		auto value = std::stol(_info.value);
		LogException::Instance()->IsInRange<long>(value, _info.type);
	}
	else {
		auto value = std::stod(_info.value);
		LogException::Instance()->IsInRange<double>(value, _info.type);
	}
	auto iOperand = std::make_shared<const IOperand*>(FactoryOperand::Instance()->createOperand(_info.value, _info.type));
	_stack.push_front(iOperand);
	return TaskDefault;
}

eTaskSignal TaskManager::_assertTask() {
//	std::cout << "assertTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (! _stack.empty()) {
		if (_info.type <= Int32) {
			auto value = std::stol(_info.value);
			LogException::Instance()->IsInRange<long>(value, _info.type);
		}
		else {
			auto value = std::stod(_info.value);
			LogException::Instance()->IsInRange<double>(value, _info.type);
		}
		auto top = *_stack.begin();
		if (((*top)->toString() != _info.value) || ((*top)->getType() != _info.type)) {
			throw LogException::BadAssertInstructionError();
		}
		_logPrints.push_back("Instruction assert : values equal !");
	} else {
		throw LogException::EmptyStackError();
	}
	return TaskDefault;
}

eTaskSignal TaskManager::_addTask() {
//	std::cout << "addTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto begin = _stack.begin();
	auto a = *begin;
	auto b = *(++begin);
	auto c = std::make_shared<const IOperand*>((**b) + (**a));
	_stack.erase(_stack.begin()); _stack.erase(_stack.begin());
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_subTask() {
//	std::cout << "subTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto begin = _stack.begin();
	auto a = *begin;
	auto b = *(++begin);
	auto c = std::make_shared<const IOperand*>((**b) - (**a));
	_stack.erase(_stack.begin()); _stack.erase(_stack.begin());
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_mulTask() {
//	std::cout << "mulTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto begin = _stack.begin();
	auto a = *begin;
	auto b = *(++begin);
	auto c = std::make_shared<const IOperand*>((**b) * (**a));
	_stack.erase(_stack.begin()); _stack.erase(_stack.begin());
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_divTask() {
//	std::cout << "divTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto begin = _stack.begin();
	auto a = *begin;
	auto b = *(++begin);
	auto c = std::make_shared<const IOperand*>((**b) / (**a));
	_stack.erase(_stack.begin()); _stack.erase(_stack.begin());
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_modTask() {
//	std::cout << "modTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto begin = _stack.begin();
	auto a = *begin;
	auto b = *(++begin);
	auto c = std::make_shared<const IOperand*>((**b) % (**a));
	_stack.erase(_stack.begin()); _stack.erase(_stack.begin());
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_popTask() {
//	std::cout << "popTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (_stack.empty()) {
		throw LogException::PopEmptyStackError();
	}
	auto a = *_stack.begin();
	_stack.erase(_stack.begin());
	delete *a;
	return TaskDefault;
}

eTaskSignal TaskManager::_dumpTask() {
//	std::cout << "dumpTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (! _stack.empty()) {
		for (auto const & item : _stack) {
			_logPrints.push_back((*item)->toString());
		}
	} else {
		throw LogException::EmptyStackError();
	}
	return TaskDefault;
}

eTaskSignal TaskManager::_printTask() {
//	std::cout << "printTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	if (! _stack.empty()) {
		auto top = *_stack.begin();
		if ((*top)->getType() != Int8) {
			throw LogException::TopValueNotCharError();
		}
		auto a = static_cast<char>(std::stoi((*top)->toString()));
		_logPrints.push_back(std::string({a, '\0'}));
	} else {
		throw LogException::EmptyStackError();
	}
	return TaskDefault;
}

eTaskSignal TaskManager::_exitTask() {
//	std::cout << "exitTask" << std::endl;
	if (TaskManager::taskSignal() == TaskExit) {
		throw LogException::AfterExitNotReceiveInstructionsError();
	}
	TaskManager::taskSignal() = TaskExit;
	return TaskExit;
}

eTaskSignal TaskManager::_endCircleTask() {
//	std::cout << "endCircleTask" << std::endl;
	if (TaskManager::taskSignal() != TaskExit) {
		throw LogException::NoExitInstructionError();
	}
	TaskManager::breakCircle() = TaskBreakCircle;
	return TaskExit;
}

eTaskSignal TaskManager::_commentTask() {
//	std::cout << "commentTask" << std::endl;
	return TaskDefault;
}

eTaskSignal& TaskManager::taskSignal() {
	return _taskSignal;
}

eTaskSignal& TaskManager::breakCircle() {
	return _breakCircle;
}

void TaskManager::printLogResults() const {
	for (const auto & item: _logPrints) {
		std::cout << item << std::endl;
	}
}