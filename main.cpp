#include "General.hpp"
#include "OperandTypeClasses/Operand.hpp"

int main() {

//	{
//		IOperand const *a = OperandFactory::getInstance()->createOperand(Int8, "34");
//		IOperand const *b = OperandFactory::getInstance()->createOperand(Int8, "-24");
//		IOperand const *c = *a + *b;
//		std::cout << a->toString() << std::endl;
//		std::cout << b->toString() << std::endl;
//		std::cout << c->toString() << std::endl;
//	}
//
//	{
//		const Operand<double> aa("34.34", Double);
//		const Operand<double> bb("-24.34", Double);
//		IOperand const *a = &aa;
//		IOperand const *b = &bb;
//		IOperand const *c = *a + *b;
//		std::cout << a->toString() << std::endl;
//		std::cout << b->toString() << std::endl;
//		std::cout << c->toString() << std::endl;
//	}
//
//	{
//		const Operand<int16_t> aa("34", Int16);
//		const Operand<double> bb("-24.50", Double);
//		IOperand const *a = &aa;
//		IOperand const *b = &bb;
//		IOperand const *c = *a + *b;
//		std::cout << a->toString() << std::endl;
//		std::cout << b->toString() << std::endl;
//		std::cout << c->toString() << std::endl;
//	}

	{
		Operand<Int8> aa("34");
		Operand<Double> bb("-24.50");

		IOperand const *a = &aa;
		IOperand const *b = &bb;
		IOperand const *c = *a + *b;

		std::cout << a->toString() << std::endl;
		std::cout << b->toString() << std::endl;
		std::cout << c->toString() << std::endl;
		std::cout << std::endl << std::endl;
	}

	{
		Operand<Double> aa("34");
		Operand<Int32> bb("-24.50");

		IOperand const *a = &aa;
		IOperand const *b = &bb;
		IOperand const *c = *a + *b;

		std::cout << a->toString() << std::endl;
		std::cout << b->toString() << std::endl;
		std::cout << c->toString() << std::endl;
		std::cout << std::endl << std::endl;
	}

	return 0;
}