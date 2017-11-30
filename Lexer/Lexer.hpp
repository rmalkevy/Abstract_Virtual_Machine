//
// Created by Roman Malkevych on 11/29/17.
//

#ifndef ABSTRACTVM_LEXER_HPP
#define ABSTRACTVM_LEXER_HPP

#include <regex>
#include "../General.hpp"

class Lexer {
private:
	const std::string _regexPushAssert;
	const std::string _regexAdd;
	const std::string _regexSub;
	const std::string _regexMul;
	const std::string _regexDiv;
	const std::string _regexMod;
	const std::string _regexPop;
	const std::string _regexDump;
	const std::string _regexPrint;
	const std::string _regexExit;
	const std::string _regexEndCircle;
	const std::string _regexComment;
	const std::regex _regexPush;
	const std::regex _regexAssert;
	const std::regex _regexInt8;
	const std::regex _regexInt32;
	const std::regex _regexInt16;
	const std::regex _regexFloat;
	const std::regex _regexDouble;
	const std::regex _regexNumber;

	std::array<std::regex, 12> _regexArr;
	bool			_pushCheck;
	bool			_assertCheck;
	eOperandType	_typeCheck;
	std::string		_numberString;

public:
	Lexer();
	~Lexer() = default;

	void	processLine_forDistributor(const std::string &input);
	void	analyzeTokens_fromRegexPushAssert(const std::string &input);
	void	initializeCheckers();
};


#endif //ABSTRACTVM_LEXER_HPP
