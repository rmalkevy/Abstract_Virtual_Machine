cmake_minimum_required(VERSION 3.8)
project(src/AbstractVM)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/main.cpp
        src/AbstractVM/AbstractVM.cpp src/AbstractVM/AbstractVM.hpp
        src/OperandType/IOperand.hpp
        src/OperandFactory/OperandFactory.cpp src/OperandFactory/OperandFactory.hpp
        src/General/General.hpp
#        LogException/LogException.hpp
        src/OperandType/Operand.hpp
        src/Lexer/Lexer.cpp src/Lexer/Lexer.hpp
        src/TaskManager/TaskManager.cpp src/TaskManager/TaskManager.hpp src/General/General.cpp src/LogException/LogException.cpp)
add_executable(src/AbstractVM ${SOURCE_FILES})