//
// Created by Roman Malkevych on 11/30/17.
//

#ifndef ABSTRACTVM_TASK_MANAGER_HPP
#define ABSTRACTVM_TASK_MANAGER_HPP

#include <stack>
#include "../General.hpp"
#include "../OperandFactory/FactoryOperand.hpp"

class TaskManager {
private:
	std::stack<IOperand*> & _stack;
	std::unique_ptr<FactoryOperand> _factoryOperand;

	using _pfTask = eTask (TaskManager::*)();
	_pfTask _arrPfTask[13];
//	std::array<_pfTask, 13> _arrPfTask;

	eTask _pushTask();
	eTask _assertTask();
	eTask _addTask();
	eTask _subTask();
	eTask _mulTask();
	eTask _divTask();
	eTask _modTask();
	eTask _popTask();
	eTask _dumpTask();
	eTask _printTask();
	eTask _exitTask();
	eTask _endCircleTask();
	eTask _commentTask();

public:
	TaskManager(std::stack<IOperand*> & stack);
	~TaskManager() = default;
	TaskManager() = delete;
	TaskManager(const TaskManager &) = delete;
	TaskManager &operator=(const TaskManager&) = delete;

	eTask	taskDistributor(const InfoForTask &info);
};

#endif //ABSTRACTVM_TASKER_HPP
