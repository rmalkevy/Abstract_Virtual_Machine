//
// Created by Roman Malkevych on 11/30/17.
//

#include "TaskManager.hpp"

TaskManager::TaskManager(std::stack<IOperand*> & stack)
		: _stack(stack),
		  _factoryOperand(std::make_unique<FactoryOperand>()),
		  _arrPfTask({
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
					 })

{
//
//	_arrPfTask[0] = &TaskManager::_pushTask;
//	_arrPfTask[1] = &TaskManager::_assertTask;
//	_arrPfTask[2] = &TaskManager::_addTask;
//	_arrPfTask[3] = &TaskManager::_subTask;
//	_arrPfTask[4] = &TaskManager::_mulTask;
//	_arrPfTask[5] = &TaskManager::_divTask;
//	_arrPfTask[6] = &TaskManager::_modTask;
//	_arrPfTask[7] = &TaskManager::_popTask;
//	_arrPfTask[8] = &TaskManager::_dumpTask;
//	_arrPfTask[9] = &TaskManager::_printTask;
//	_arrPfTask[10] = &TaskManager::_exitTask;
//	_arrPfTask[11] = &TaskManager::_endCircleTask;
//	_arrPfTask[12] = &TaskManager::_commentTask;
}

eTask TaskManager::taskDistributor(const InfoForTask &info) {
	return (this->*_arrPfTask[info.task])();
	// TODO: return eTask;
}

eTask TaskManager::_pushTask() {
	return TaskDefault;
}

eTask TaskManager::_assertTask() {
	return TaskDefault;
}

eTask TaskManager::_addTask() {
	return TaskDefault;
}

eTask TaskManager::_subTask() {
	return TaskDefault;
}

eTask TaskManager::_mulTask() {
	return TaskDefault;
}

eTask TaskManager::_divTask() {
	return TaskDefault;
}

eTask TaskManager::_modTask() {
	return TaskDefault;
}

eTask TaskManager::_popTask() {
	return TaskDefault;
}

eTask TaskManager::_dumpTask() {
	return TaskDefault;
}

eTask TaskManager::_printTask() {
	return TaskDefault;
}

eTask TaskManager::_exitTask() {
	return TaskExit;
}

eTask TaskManager::_endCircleTask() {
	return TaskExit;
}

eTask TaskManager::_commentTask() {
	return TaskDefault;
}