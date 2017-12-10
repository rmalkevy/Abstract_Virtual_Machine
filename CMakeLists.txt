cmake_minimum_required(VERSION 3.8)
project(AbstractVM_)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/main.cpp
        src/AbstractVM/AbstractVM.cpp src/AbstractVM/AbstractVM.hpp
        src/OperandType/IOperand.hpp
        src/OperandFactory/OperandFactory.cpp src/OperandFactory/OperandFactory.hpp
        src/General/General.cpp src/General/General.hpp
        src/OperandType/Operand.hpp
        src/Parser/Parser.cpp src/Parser/Parser.hpp
        src/TaskManager/TaskManager.cpp src/TaskManager/TaskManager.hpp
        src/LogException/LogException.cpp src/LogException/LogException.hpp
        src/Lexer/Lexer.cpp src/Lexer/Lexer.hpp main.cpp)

add_executable(AbstractVM_ ${SOURCE_FILES})