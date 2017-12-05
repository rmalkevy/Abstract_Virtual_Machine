//
// Created by Roman Malkevych on 12/2/17.
//

#include "LogException.hpp"
#include "../AbstractVM/AbstractVM.hpp"

LogException *LogException::Instance() {
	static LogException instance;
	return &instance;
}

const char* LogException::LexicalError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: lexical mistake !");
	return errorMassage.c_str();
}

const char* LogException::UnknownInstructionError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: unknown instruction !");
	return errorMassage.c_str();
}

const char* LogException::OverflowError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: overflow on a value or the result of an operation !");
	return errorMassage.c_str();
}

const char* LogException::UnderflowError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: underflow on a value or the result of an operation !");
	return errorMassage.c_str();
}

const char* LogException::PopEmptyStackError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: instruction pop on an empty stack !");
	return errorMassage.c_str();
}

const char* LogException::DivisionByZeroError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: division by zero !");
	return errorMassage.c_str();
}

const char* LogException::ModuloByZeroError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: division by modulo !");
	return errorMassage.c_str();
}

const char* LogException::NoExitInstructionError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: program doesn't have exit instruction !");
	return errorMassage.c_str();
}

const char* LogException::BadAssertInstructionError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: assert value doesn't equal to top value from stack !");
	return errorMassage.c_str();
}

const char* LogException::LessThanTwoValuesInStackError::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: Arithmetic instruction need at least two items !");
	return errorMassage.c_str();
}

const char* LogException::TopValueNotChar::what() const throw() {
//	TaskManager::taskSignal() = TaskExit;
	std::string errorMassage("Line " + std::to_string(AbstractVM::getNumberLine()) +
							 " : Error: Value on the top of stack isn't a ASCII symbol !");
	return errorMassage.c_str();
}