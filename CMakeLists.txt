cmake_minimum_required(VERSION 3.8)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        OperandTypeClasses/IOperand.hpp
        OperandFactoryClass/FactoryOperand.cpp OperandFactoryClass/FactoryOperand.hpp
        General.hpp
        LoggerException/LoggerException.hpp
        OperandTypeClasses/Operand.hpp)
add_executable(AbstractVM ${SOURCE_FILES})