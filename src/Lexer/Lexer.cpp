//
// Created by Roman Malkevych on 12/6/17.
//

#include "Lexer.hpp"
#include "../LogException/LogException.hpp"

//const std::uint32_t GroupType	= (1 << _14_Int8) | (1 << _16_Int32) | (1 << _15_Int16) | (1 <<_17_Float) | (1 << _18_Double);
//const std::uint32_t GroupPush	= (1 << _1_Push) | (1 << _19_LeftP) | (1 << _20_RightP) | (1 << _21_Number) | GroupType;
//const std::uint32_t GroupAssert = (1 << _2_Assert) | (1 << _19_LeftP) | (1 << _20_RightP) | (1 << _21_Number) | GroupType;

Lexer::Lexer()
		: _1_tokenPush("((\\s|\\t|\\r)+)?(push)((\\s|\\t|\\r)+)?"),
		  _2_tokenAssert("((\\s|\\t|\\r)+)?(assert)((\\s|\\t|\\r)+)?"),
		  _3_tokenAdd("((\\s|\\t|\\r)+)?(add)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _4_tokenSub("((\\s|\\t|\\r)+)?(sub)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _5_tokenMul("((\\s|\\t|\\r)+)?(mul)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _6_tokenDiv("((\\s|\\t|\\r)+)?(div)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _7_tokenMod("((\\s|\\t|\\r)+)?(mod)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _8_tokenPop("((\\s|\\t|\\r)+)?(pop)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _9_tokenDump("((\\s|\\t|\\r)+)?(dump)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _10_tokenPrint("((\\s|\\t|\\r)+)?(print)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _11_tokenExit("((\\s|\\t|\\r)+)?(exit)((\\s|\\t|\\r)+)?(;(.+)?)?"),
		  _12_tokenEndCircle("((\\s|\\t|\\r)+)?(;;)((\\s|\\t|\\r)+)?"),
		  _13_tokenComment("((\\s|\\t|\\r)+)?;(.+)?"),
		  _14_tokenInt8("((\\s|\\t|\\r)+)?int8((\\s|\\t|\\r)+)?"),
		  _15_tokenInt16("((\\s|\\t|\\r)+)?int16((\\s|\\t|\\r)+)?"),
		  _16_tokenInt32("((\\s|\\t|\\r)+)?int32((\\s|\\t|\\r)+)?"),
		  _17_tokenFloat("((\\s|\\t|\\r)+)?float((\\s|\\t|\\r)+)?"),
		  _18_tokenDouble("((\\s|\\t|\\r)+)?double((\\s|\\t|\\r)+)?"),
		  _19_tokenLeftParenthesis("((\\s|\\t|\\r)+)?"
										   "\\("
										   "((\\s|\\t|\\r)+)?"),
		  _20_tokenRightParenthesis("((\\s|\\t|\\r)+)?"
											"\\)"
											"((\\s|\\t|\\r)+)?"),
		  _21_tokenNumber("\\(((\\s|\\t|\\r)+)?"
								  "(\\+|-)?[\\d]+(\\.[\\d]+)?((\\s|\\t|\\r)+)?"
								  "\\)"),
		  _tokens()

{
	_matchTokens = 0;
	_tokens[0] = _1_tokenPush;
	_tokens[1] = _2_tokenAssert;
	_tokens[2] = _3_tokenAdd;
	_tokens[3] = _4_tokenSub;
	_tokens[4] = _5_tokenMul;
	_tokens[5] = _6_tokenDiv;
	_tokens[6] = _7_tokenMod;
	_tokens[7] = _8_tokenPop;
	_tokens[8] = _9_tokenDump;
	_tokens[9] = _10_tokenPrint;
	_tokens[10] = _11_tokenExit;
	_tokens[11] = _12_tokenEndCircle;
	_tokens[12] = _13_tokenComment;
	_tokens[13] = _14_tokenInt8;
	_tokens[14] = _15_tokenInt16;
	_tokens[15] = _16_tokenInt32;
	_tokens[16] = _17_tokenFloat;
	_tokens[17] = _18_tokenDouble;
	_tokens[18] = _19_tokenLeftParenthesis;
	_tokens[19] = _20_tokenRightParenthesis;
	_tokens[20] = _21_tokenNumber;
}

void Lexer::analyzeInputString(const std::string &input) {
//	std::smatch	sm;

	for (size_t i = 0; i < _tokens.size(); i++) {
		if (std::regex_search(input, _tokens[i])) {
//			_orderTokens.push_back(static_cast<size_t>(sm.prefix().length()));
			_matchTokens |= 1 << i;
		}
	}
	if (_matchTokens != 0) {
		throw LogException::LexicalError();
	}
//	analyzeOrderOfTokens();
}

//bool Lexer::analyzeOrderOfTokens() {
//	for (size_t i = 0; i < _orderTokens.size() - 1; i++) {
//		if (_orderTokens.at(i) > _orderTokens.at(i + 1))  {
//			return false;
//		}
//	}
//	return true;
//}

//void Lexer::tokenizer(const std::string &str, std::vector<std::string> &cont) {
//	std::smatch result;
//	std::regex r("([[:w:]]+)");
//	std::size_t start = 0, end = 0, len = 0;
//	std::string s = str;
//
//	while (std::regex_search(s, result, r)) {
//		start = result.prefix().length();
//		end = result.suffix().length();
//		len = s.length() - start - end;
//
//		cont.push_back(s.substr(start, len));
//		s.erase(0, s.length() - end);
//	}
//}