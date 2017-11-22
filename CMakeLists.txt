cmake_minimum_required(VERSION 3.8)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        OperandFactoryClass/OperandFactory.cpp
        TaskAdd.cpp TaskAdd.hpp
        OperandTypeClasses/Int8_Operand.cpp OperandTypeClasses/Int8_Operand.hpp
        OperandTypeClasses/Int16_Operand.cpp OperandTypeClasses/Int16_Operand.hpp
        OperandTypeClasses/Int32_Operand.cpp OperandTypeClasses/Int32_Operand.hpp
        OperandTypeClasses/Float_Operand.cpp OperandTypeClasses/Float_Operand.hpp
        OperandTypeClasses/Double_Operand.cpp OperandTypeClasses/Double_Operand.hpp
        PrecisionHandlingClass/PrecisionHandleClass.hpp
        AbstractVM_SingletonClass/AbstractVM.cpp AbstractVM_SingletonClass/AbstractVM.hpp OperandTypeClasses/Templete_Operand.h)
add_executable(AbstractVM ${SOURCE_FILES})