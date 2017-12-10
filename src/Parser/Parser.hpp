//
// Created by Roman Malkevych on 11/29/17.
//

#ifndef ABSTRACTVM_LEXER_HPP
#define ABSTRACTVM_LEXER_HPP

#include <regex>
#include "../General/General.hpp"
#include "../Lexer/Lexer.hpp"

class Parser {
private:
	const std::string _regexPush;
	const std::string _regexAssert;
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
	const std::regex _regexInt8;
	const std::regex _regexInt16;
	const std::regex _regexInt32;
	const std::regex _regexFloat;
	const std::regex _regexDouble;
	const std::regex _regexNumber;
	std::array<std::regex, 13> _regexArr;

	Lexer		_lexer;
	InfoForTask _infoForCreateOperand;

public:
	Parser();
	~Parser() = default;

	void	processLine_forTaskManager(const std::string &input);
	void	analyzeTokens_fromRegexPushAssert(const std::string &input);
	void	initializeCheckers();

	const std::string&	trim(std::string &s);
	const InfoForTask&	getInfo_forTask() const;
};


#endif //ABSTRACTVM_LEXER_HPP
