//
// Created by Roman Malkevych on 11/29/17.
//

#ifndef ABSTRACTVM_LEXER_HPP
#define ABSTRACTVM_LEXER_HPP

#include <regex>
#include "../General.hpp"

class Lexer {
private:
	const std::regex _regexPushAssert;
	const std::regex _regexAdd;
	const std::regex _regexSub;
	const std::regex _regexMul;
	const std::regex _regexDiv;
	const std::regex _regexMod;
	const std::regex _regexPop;
	const std::regex _regexDump;
	const std::regex _regexPrint;
	const std::regex _regexExit;
	const std::regex _regexEndCircle;
	const std::regex _regexComment;
	const std::vector<std::regex> _regexAll;
public:
	Lexer();
	~Lexer();

	void	processLine(const std::string &input);
};


#endif //ABSTRACTVM_LEXER_HPP
