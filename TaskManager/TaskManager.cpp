//
// Created by Roman Malkevych on 11/30/17.
//

#include "TaskManager.hpp"
#include "../LogException/LogException.hpp"

eTaskSignal TaskManager::_taskSignal = TaskDefault;

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
					 }
{}

eTaskSignal TaskManager::taskDistributor(const InfoForTask &info) {
	_info = info;
	if (info.task == TaskEmpty)
		return TaskEmpty;
	return (this->*_arrPfTask[info.task])();
	// TODO: return eTask;
}

eTaskSignal TaskManager::_pushTask() {
	std::cout << "pushTask" << std::endl;

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
	std::cout << "assertTask" << std::endl;

	if (_info.type <= Int32) {
		auto value = std::stol(_info.value);
		LogException::Instance()->IsInRange<long>(value, _info.type);
	}
	else {
		auto value = std::stod(_info.value);
		LogException::Instance()->IsInRange<double>(value, _info.type);
	}
	auto top = *_stack.begin();
	if (! ((*top)->toString() == _info.value) && ((*top)->getType() == _info.type)) {
		throw LogException::BadAssertInstructionError();
	}
	std::cout << "Instruction assert : values equal !" << std::endl;
	return TaskDefault;
}

eTaskSignal TaskManager::_addTask() {
	std::cout << "addTask" << std::endl;

	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto a = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto b = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto c = std::make_shared<const IOperand*>(*a + *b);
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_subTask() {
	std::cout << "subTask" << std::endl;

	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto a = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto b = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto c = std::make_shared<const IOperand*>(*a - *b);
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_mulTask() {
	std::cout << "mulTask" << std::endl;

	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto a = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto b = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto c = std::make_shared<const IOperand*>(*a * *b);
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_divTask() {
	std::cout << "divTask" << std::endl;

	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto a = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto b = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto c = std::make_shared<const IOperand*>(*a / *b);
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_modTask() {
	std::cout << "modTask" << std::endl;

	if (_stack.size() < 2)
		throw LogException::LessThanTwoValuesInStackError();
	auto a = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto b = *(*_stack.begin()); _stack.erase(_stack.begin());
	auto c = std::make_shared<const IOperand*>(*a % *b);
	_stack.push_front(c);
	return TaskDefault;
}

eTaskSignal TaskManager::_popTask() {
	std::cout << "popTask" << std::endl;

	if (_stack.empty()) {
		LogException::PopEmptyStackError();
	}
	_stack.erase(_stack.begin());
	return TaskDefault;
}

eTaskSignal TaskManager::_dumpTask() {
	std::cout << "dumpTask" << std::endl;

	for (auto const & item : _stack) {
		std::cout << (*item)->toString() << std::endl;
	}
	return TaskDefault;
}

eTaskSignal TaskManager::_printTask() {
	std::cout << "printTask" << std::endl;

	auto top = *_stack.begin();
	if ((*top)->getType() != Int8) {
		throw LogException::TopValueNotChar();
	}
	auto a = static_cast<char>(std::stoi((*top)->toString()));
	std::cout << a << std::endl;
	return TaskDefault;
}

eTaskSignal TaskManager::_exitTask() {
	std::cout << "exitTask" << std::endl;
	TaskManager::taskSignal() = TaskExit;
	return TaskExit;
}

eTaskSignal TaskManager::_endCircleTask() {
	std::cout << "endCircleTask" << std::endl;
	TaskManager::taskSignal() = TaskExit;
	return TaskExit;
}

eTaskSignal TaskManager::_commentTask() {
	std::cout << "commentTask" << std::endl;
	return TaskDefault;
}

eTaskSignal& TaskManager::taskSignal() {
	return _taskSignal;
}