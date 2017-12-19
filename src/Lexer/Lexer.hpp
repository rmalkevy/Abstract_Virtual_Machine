//
// Created by Roman Malkevych on 12/6/17.
//

#ifndef ABSTRACTVM_PARSER_HPP
#define ABSTRACTVM_PARSER_HPP

#include <vector>
#include <regex>
#include "../../src/General/General.hpp"

class Lexer {
private:
	std::uint32_t	_matchTokens;			// 1 -> matching token, 0 -> not matching token
//	std::uint32_t	_countMatchingToken; 	// 1 -> count more than 1 matching, 0 -> count 1 matching
//	std::uint32_t	orderTokens; 			// 1 -> right order, 0 -> bad order

	// tokens for regex using
	const std::string	_1_tokenPush;
	const std::string	_2_tokenAssert;
	const std::string	_3_tokenAdd;
	const std::string	_4_tokenSub;
	const std::string	_5_tokenMul;
	const std::string	_6_tokenDiv;
	const std::string	_7_tokenMod;
	const std::string	_8_tokenPop;
	const std::string	_9_tokenDump;
	const std::string	_10_tokenPrint;
	const std::string	_11_tokenExit;
	const std::string	_12_tokenEndCircle;
	const std::string	_13_tokenComment;
	const std::string	_14_tokenInt8;
	const std::string	_15_tokenInt16;
	const std::string	_16_tokenInt32;
	const std::string	_17_tokenFloat;
	const std::string	_18_tokenDouble;
	const std::string	_19_tokenLeftParenthesis;
	const std::string	_20_tokenRightParenthesis;
	const std::regex	_21_tokenNumber;

	std::array<std::regex, 21>	_tokens;
//	std::vector<size_t>			_orderTokens;

public:
	Lexer();
	~Lexer() = default;

	void	analyzeInputString(const std::string &input);
//	bool	analyzeOrderOfTokens();
//	void	identifyErrors();
//	void 	tokenizer(const std::string &str, std::vector<std::string> &cont);

};


#endif //ABSTRACTVM_PARSER_HPP
