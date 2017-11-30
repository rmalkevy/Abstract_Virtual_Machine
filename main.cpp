#include <iostream>
#include "General.hpp"
#include "Lexer/Lexer.hpp"
#include <regex>
//#include "OperandType/Operand.hpp"
//#include "AbstractVM_SingletonClass/AbstractVM.hpp"

int main(int ac, char **av) {

	//AbstractVM abstractVM(ac, av);

//	{
//		Operand<int8_t > aa("34", Int8);
//		Operand<double> bb("-24000000000000000000.50", Double);
//
//		IOperand const *a = &aa;
//		IOperand const *b = &bb;
//		IOperand const *c = *a + *b;
//
//		std::cout << a->toString() << std::endl;
//		std::cout << b->toString() << std::endl;
//		std::cout << c->toString() << std::endl;
//		std::cout << std::endl << std::endl;
//	}
//
//	{
//		Operand<int8_t> aa("2", Int8);
//		Operand<int8_t> bb("3", Int8);
////		Operand<int32_t> bb("-24.50", Int32);
//
//		IOperand const *a = &aa;
//		IOperand const *b = &bb;
//		IOperand const *c = *a + *b;
//
//		std::cout << a->toString() << std::endl;
//		std::cout << b->toString() << std::endl;
//		std::cout << c->toString() << std::endl;
//		std::cout << std::endl << std::endl;
//	}

	Lexer lexer;
	std::string input;
	while (true) {
		std::getline(std::cin, input);
		if (input == "q") { break; }

		lexer.processLine_forDistributor(input);

	}
	return 0;

}

// TOdo: spaces string