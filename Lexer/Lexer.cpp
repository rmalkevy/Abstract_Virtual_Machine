//
// Created by Roman Malkevych on 11/29/17.
//

#include "Lexer.hpp"

// TODO: for bonus - lexer that analyze tokens
Lexer::Lexer()
		: _regexAll(12),
		  _regexPushAssert("(push|assert) (int8|int16|int32|float|double)"
								   "\\((\\+|-)?[\\d]+(\\.[\\d]+)?\\)(;.+)?"),
		  _regexAdd("(add)(;.+)?"),
		  _regexSub("(sub)(;.+)?"),
		  _regexMul("(mul)(;.+)?"),
		  _regexDiv("(div)(;.+)?"),
		  _regexMod("(mod)(;.+)?"),
		  _regexPop("(pop)(;.+)?"),
		  _regexDump("(dump)(;.+)?"),
		  _regexPrint("(print)(;.+)?"),
		  _regexExit("(exit)(;.+)?"),
		  _regexEndCircle("(;;)"),
		  _regexComment("(;.+)?")
{
	_regexAll.at(0) = _regexPushAssert;
	_regexAll.at(1) = _regexAdd;
	_regexAll.at(2) = _regexSub;
	_regexAll.at(3) = _regexMul;
	_regexAll.at(4) = _regexDiv;
	_regexAll.at(5) = _regexMod;
	_regexAll.at(6) = _regexPop;
	_regexAll.at(7) = _regexDump;
	_regexAll.at(8) = _regexPrint;
	_regexAll.at(9) = _regexExit;
	_regexAll.at(10) = _regexEndCircle;
	_regexAll.at(11) = _regexComment;
}

void Lexer::processLine(const std::string &input) {

	for (size_t i = 0; i < _regexAll.size(); ++i) {
		if (std::regex_match(input, _regexAll.at(i))) {

		}
	}
}