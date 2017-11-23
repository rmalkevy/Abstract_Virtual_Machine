#include "General.hpp"
#include "OperandTypeClasses/Templete_Operand.hpp"
#include "OperandFactoryClass/OperandFactory.hpp"

int main() {

	{
		IOperand const *a = OperandFactory::getInstance()->createOperand(Int8, "34");
		IOperand const *b = OperandFactory::getInstance()->createOperand(Int8, "-24");
		IOperand const *c = *a + *b;
		std::cout << a->toString() << std::endl;
		std::cout << b->toString() << std::endl;
		std::cout << c->toString() << std::endl;
	}

	{
		const Operand<int8_t> aa("34", Int8);
		const Operand<int8_t> bb("-24", Int8);
		IOperand const *a = &aa;
		IOperand const *b = &bb;
		IOperand const *c = *a + *b;
		std::cout << a->toString() << std::endl;
		std::cout << b->toString() << std::endl;
		std::cout << c->toString() << std::endl;
	}
	return 0;
}