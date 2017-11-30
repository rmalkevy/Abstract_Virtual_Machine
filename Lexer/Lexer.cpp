//
// Created by Roman Malkevych on 11/29/17.
//

#include "Lexer.hpp"

// TODO: for bonus - lexer that analyze tokens
Lexer::Lexer()
		: _regexPushAssert("((\\s|\\t|\\r)+)?(push|assert)((\\s|\\t|\\r)+)?"
								   "(int8|int16|int32|float|double)((\\s|\\t|\\r)+)?"
								   "\\(((\\s|\\t|\\r)+)?"
								   "(\\+|-)?[\\d]+(\\.[\\d]+)?((\\s|\\t|\\r)+)?"
								   "\\)((\\s|\\t|\\r)+)?"
								   "(;.+)?"),
		  _regexAdd("((\\s|\\t|\\r)+)?(add)((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexSub("((\\s|\\t|\\r)+)?(sub)((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexMul("((\\s|\\t|\\r)+)?(mul)((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexDiv("((\\s|\\t|\\r)+)?(div)((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexMod("((\\s|\\t|\\r)+)?(mod)((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexPop("((\\s|\\t|\\r)+)?(pop)((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexDump("((\\s|\\t|\\r)+)?(dump)((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexPrint("((\\s|\\t|\\r)+)?(print)((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexExit("((\\s|\\t|\\r)+)?(exit)((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexEndCircle("((\\s|\\t|\\r)+)?(;;)((\\s|\\t|\\r)+)?"),
		  _regexComment("((\\s|\\t|\\r)+)?(;.+)?"),
		  _regexPush("((\\s|\\t|\\r)+)?push((\\s|\\t|\\r)+)?"),
		  _regexAssert("((\\s|\\t|\\r)+)?assert((\\s|\\t|\\r)+)?"),
		  _regexInt8("((\\s|\\t|\\r)+)?int8((\\s|\\t|\\r)+)?"),
		  _regexInt32("((\\s|\\t|\\r)+)?int32((\\s|\\t|\\r)+)?"),
		  _regexInt16("((\\s|\\t|\\r)+)?int16((\\s|\\t|\\r)+)?"),
		  _regexFloat("((\\s|\\t|\\r)+)?float((\\s|\\t|\\r)+)?"),
		  _regexDouble("((\\s|\\t|\\r)+)?double((\\s|\\t|\\r)+)?"),
		  _regexNumber("\\(((\\s|\\t|\\r)+)?"
							   "(\\+|-)?[\\d]+(\\.[\\d]+)?((\\s|\\t|\\r)+)?"
							   "\\)"),
		  _infoForCreateOperand(false, false, NumberOperands, "0")

// TODO: number of spaces doesn't matter!!!
// TODO; missing argument or command or missing space between tokens or lexical mistake in tokens

//std::regex regex_tokens("#([a-f0-9]{2})"
//							   "([a-f0-9]{2})"
//							   "([a-f0-9]{2})");
{
	_regexArr[0] = _regexPushAssert;
	_regexArr[1] = _regexAdd;
	_regexArr[2] = _regexSub;
	_regexArr[3] = _regexMul;
	_regexArr[4] = _regexDiv;
	_regexArr[5] = _regexMod;
	_regexArr[6] = _regexPop;
	_regexArr[7] = _regexDump;
	_regexArr[8] = _regexPrint;
	_regexArr[9] = _regexExit;
	_regexArr[10] = _regexEndCircle;
	_regexArr[11] = _regexComment;
}

size_t Lexer::processLine_forTaskManager(const std::string &input) {

	size_t i;
	bool find = false;
	for (i = 0; i < _regexArr.size(); i++) {
		if (std::regex_match(input, _regexArr[i])) {
			find = true;
			if (i == 0) {
				analyzeTokens_fromRegexPushAssert(input);
				std::cout << _infoForCreateOperand.numberString << std::endl;
			}
			break ;
		}
	}
	// if find == false -> exception
	std::cout << i << std::endl;
	return i;
}

void Lexer::analyzeTokens_fromRegexPushAssert(const std::string &input) {

	initializeCheckers();
	std::smatch resultMatch;

	// three blocks
	// 1) choose push or assert
	if (std::regex_search(input, _regexPush))
		_infoForCreateOperand.pushCheck = true;
	else if (std::regex_search(input, _regexAssert))
		_infoForCreateOperand.assertCheck = true;

	// 2) find out of type number
	if (std::regex_search(input, _regexInt8))
		_infoForCreateOperand.typeCheck = Int8;
	else if (std::regex_search(input, _regexInt16))
		_infoForCreateOperand.typeCheck = Int16;
	else if (std::regex_search(input, _regexInt32))
		_infoForCreateOperand.typeCheck = Int32;
	else if (std::regex_search(input, _regexFloat))
		_infoForCreateOperand.typeCheck = Float;
	else if (std::regex_search(input, _regexDouble))
		_infoForCreateOperand.typeCheck = Double;

	// 3) parse number
	std::regex_search(input, resultMatch, _regexNumber);
	size_t start = resultMatch.prefix().length();
	_infoForCreateOperand.numberString = input.substr(start, input.size());
}

void Lexer::initializeCheckers() {
	_infoForCreateOperand.pushCheck = false;
	_infoForCreateOperand.assertCheck = false;
	_infoForCreateOperand.typeCheck = NumberOperands;
	_infoForCreateOperand.numberString = "0";
}

const InfoForTask& Lexer::getInfo_forTask() const {
	return _infoForCreateOperand;
}