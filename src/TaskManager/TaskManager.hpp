//
// Created by Roman Malkevych on 11/30/17.
//

#ifndef ABSTRACTVM_TASK_MANAGER_HPP
#define ABSTRACTVM_TASK_MANAGER_HPP

#include <list>
#include <vector>
#include "../General/General.hpp"
#include "../OperandFactory/OperandFactory.hpp"

class TaskManager {
private:
	std::list< std::shared_ptr<const IOperand*> > _stack;
	InfoForTask _info;

	using _pfTask = eTaskSignal (TaskManager::*)();
	_pfTask _arrPfTask[13];

	static eTaskSignal _taskSignal;
	static eTaskSignal _breakCircle;

	eTaskSignal _pushTask();
	eTaskSignal _assertTask();
	eTaskSignal _addTask();
	eTaskSignal _subTask();
	eTaskSignal _mulTask();
	eTaskSignal _divTask();
	eTaskSignal _modTask();
	eTaskSignal _popTask();
	eTaskSignal _dumpTask();
	eTaskSignal _printTask();
	eTaskSignal _exitTask();
	eTaskSignal _endCircleTask();
	eTaskSignal _commentTask();

	std::vector<std::string>	_logPrints;

public:
	TaskManager();
	~TaskManager() = default;
	TaskManager(const TaskManager &) = delete;
	TaskManager &operator=(const TaskManager&) = delete;

	eTaskSignal	taskDistributor(const InfoForTask &info);
	static eTaskSignal &taskSignal();
	static eTaskSignal &breakCircle();
	void	printLogResults() const;
};

#endif //ABSTRACTVM_TASKER_HPP
