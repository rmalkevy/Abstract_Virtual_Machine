//
// Created by Roman Malkevych on 11/29/17.
//

#include "Parser.hpp"
#include "../LogException/LogException.hpp"
#include "../TaskManager/TaskManager.hpp"

// TODO: for bonus - lexer that analyze tokens
Parser::Parser()
		: _regexPush("((\\s|\\t|\\r)+)?(push)((\\s|\\t|\\r)+)?"
								   "(int8|int16|int32|float|double)((\\s|\\t|\\r)+)?"
								   "\\(((\\s|\\t|\\r)+)?"
								   "(\\+|-)?[\\d]+(\\.[\\d]+)?((\\s|\\t|\\r)+)?"
								   "\\)((\\s|\\t|\\r)+)?"
								   "(;(.+)?)?"),
		  _regexAssert("((\\s|\\t|\\r)+)?(assert)((\\s|\\t|\\r)+)?"
								   "(int8|int16|int32|float|double)((\\s|\\t|\\r)+)?"
								   "\\(((\\s|\\t|\\r)+)?"
								   "(\\+|-)?[\\d]+(\\.[\\d]+)?((\\s|\\t|\\r)+)?"
								   "\\)((\\s|\\t|\\r)+)?"
								   "(;(.+)?)?"),
		  _regexAdd("((\\s|\\t|\\r)+)?(add)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _regexSub("((\\s|\\t|\\r)+)?(sub)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _regexMul("((\\s|\\t|\\r)+)?(mul)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _regexDiv("((\\s|\\t|\\r)+)?(div)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _regexMod("((\\s|\\t|\\r)+)?(mod)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _regexPop("((\\s|\\t|\\r)+)?(pop)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _regexDump("((\\s|\\t|\\r)+)?(dump)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _regexPrint("((\\s|\\t|\\r)+)?(print)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _regexExit("((\\s|\\t|\\r)+)?(exit)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _regexEndCircle("((\\s|\\t|\\r)+)?(;;)((\\s|\\t|\\r)+)?"),
		  _regexComment("((\\s|\\t|\\r)+)?;(.+)?"),
		  _regexInt8("((\\s|\\t|\\r)+)?int8((\\s|\\t|\\r)+)?"),
		  _regexInt16("((\\s|\\t|\\r)+)?int16((\\s|\\t|\\r)+)?"),
		  _regexInt32("((\\s|\\t|\\r)+)?int32((\\s|\\t|\\r)+)?"),
		  _regexFloat("((\\s|\\t|\\r)+)?float((\\s|\\t|\\r)+)?"),
		  _regexDouble("((\\s|\\t|\\r)+)?double((\\s|\\t|\\r)+)?"),
		  _regexNumber("\\(((\\s|\\t|\\r)+)?"
							   "(\\+|-)?[\\d]+(\\.[\\d]+)?((\\s|\\t|\\r)+)?"
							   "\\)"),
		  _infoForCreateOperand(NumberOperands, "0")

{
	_regexArr[0] = _regexPush;
	_regexArr[1] = _regexAssert;
	_regexArr[2] = _regexAdd;
	_regexArr[3] = _regexSub;
	_regexArr[4] = _regexMul;
	_regexArr[5] = _regexDiv;
	_regexArr[6] = _regexMod;
	_regexArr[7] = _regexPop;
	_regexArr[8] = _regexDump;
	_regexArr[9] = _regexPrint;
	_regexArr[10] = _regexExit;
	_regexArr[11] = _regexEndCircle;
	_regexArr[12] = _regexComment;
}

void Parser::processLine_forTaskManager(const std::string &input) {
	initializeCheckers();
	size_t i;

	for (i = 0; i < _regexArr.size(); ++i) {
		if (std::regex_match(input, _regexArr[i])) {
			_infoForCreateOperand.task = i;
			if (i == 0 || i == 1) {
				analyzeTokens_fromRegexPushAssert(input);
			}
			return ;
		}
	}

	// if not found instruction -> analyze string for find lexical mistake
	_lexer.analyzeInputString(input);
	if (input.length()) // Check line for empty instructions
		throw LogException::UnknownInstructionError();
}

void Parser::analyzeTokens_fromRegexPushAssert(const std::string &input) {
	std::smatch resultMatch;

	// two blocks

	// 1) find out of type number
	if (std::regex_search(input, _regexInt8))
		_infoForCreateOperand.type = Int8;
	else if (std::regex_search(input, _regexInt16))
		_infoForCreateOperand.type = Int16;
	else if (std::regex_search(input, _regexInt32))
		_infoForCreateOperand.type = Int32;
	else if (std::regex_search(input, _regexFloat))
		_infoForCreateOperand.type = Float;
	else if (std::regex_search(input, _regexDouble))
		_infoForCreateOperand.type = Double;

	// 2) parse number
	std::regex_search(input, resultMatch, _regexNumber);
	size_t start = static_cast<size_t>(resultMatch.prefix().length()) + 1;
	size_t lenNumber = input.length() - start - resultMatch.suffix().length() - 1;
	_infoForCreateOperand.value = input.substr(start, lenNumber);
	_infoForCreateOperand.value = trim(_infoForCreateOperand.value);
}

void Parser::initializeCheckers() {
	_infoForCreateOperand.task = TaskEmpty;
	_infoForCreateOperand.type = NumberOperands;
	_infoForCreateOperand.value = "";
}

const InfoForTask& Parser::getInfo_forTask() const {
	return _infoForCreateOperand;
}

const std::string& Parser::trim(std::string &s) {
	const char* ws = " \t\n\r\f\v";

	s.erase(0, s.find_first_not_of(ws));
	s.erase(s.find_last_not_of(ws) + 1);
	return s;
}