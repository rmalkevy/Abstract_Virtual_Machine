cmake_minimum_required(VERSION 3.8)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        AbstractVM/AbstractVM.cpp AbstractVM/AbstractVM.hpp
        OperandType/IOperand.hpp
        OperandFactory/FactoryOperand.cpp OperandFactory/FactoryOperand.hpp
        General.hpp
        LoggerException/LoggerException.hpp
        OperandType/Operand.hpp Lexer/Lexer.cpp Lexer/Lexer.hpp)
add_executable(AbstractVM ${SOURCE_FILES})