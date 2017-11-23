cmake_minimum_required(VERSION 3.8)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        OperandTypeClasses/IOperand.hpp
        General.hpp
        OperandFactoryClass/OperandFactory.cpp
        TaskAdd.cpp TaskAdd.hpp
        OperandTypeClasses/Int8_Operand.cpp OperandTypeClasses/Int8_Operand.hpp
        PrecisionHandlingClass/PrecisionHandleClass.hpp
        AbstractVM_SingletonClass/AbstractVM.cpp AbstractVM_SingletonClass/AbstractVM.hpp OperandTypeClasses/Templete_Operand.hpp)
add_executable(AbstractVM ${SOURCE_FILES})