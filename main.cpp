//
// Created by Roman Malkevych on 12/8/17.
//
#include <iostream>
#include <vector>
#include <regex>

template<class Container>
void explode(const std::string &str, Container &cont) {
	std::smatch result;
	std::regex r("([[:w:]]+)");
	std::size_t start = 0, end = 0, len = 0;
	std::string s = str;

	while (std::regex_search(s, result, r)) {
		start = result.prefix().length();
		end = result.suffix().length();
		len = s.length() - start - end;

		cont.push_back(s.substr(start, len));
		s.erase(0, s.length() - end);
	}
}

int main() {
	std::string input;
	std::vector<std::string> container;

	while (true) {
		std::getline(std::cin, input);
		explode(input, container);
		for (const auto &item : container) { std::cout << item << std::endl; }
		if (input == "q") {
			break;
		}
	}
	return 0;
}