//
// Created by Roman Malkevych on 11/20/17.
//

#ifndef ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP
#define ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP

#include "../General/General.hpp"
#include <exception>

class AbstractVM;

class LogException {
private:
	LogException() = default;

public:
	LogException(LogException const &) = delete;
	LogException &operator=(LogException const &) = delete;

	static LogException *Instance();

	struct LexicalError : public std::exception {
		// TODO: several functions for all lexical errors
		const char* what() const throw() override;
	};

	struct UnknownInstructionError : public std::exception {
		const char* what() const throw() override;
	};

	struct OverflowError : public std::exception {
		const char* what() const throw() override;
	};

	struct UnderflowError : public std::exception {
		const char* what() const throw() override;
	};

	struct PopEmptyStackError : public std::exception {
		const char* what() const throw() override;
	};

	struct DivisionByZeroError : public std::exception {
		const char* what() const throw() override;
	};

	struct ModuloByZeroError : public std::exception {
		const char* what() const throw() override;
	};

	struct NoExitInstructionError : public std::exception {
		const char* what() const throw() override;
	};

	struct BadAssertInstructionError : public std::exception {
		const char* what() const throw() override;
	};

	struct LessThanTwoValuesInStackError : public std::exception {
		const char* what() const throw() override;
	};

	struct TopValueNotCharError : public std::exception {
		const char* what() const throw() override;
	};

	struct AfterExitNotReceiveInstructionsError : public std::exception {
		const char* what() const throw() override;
	};

	struct OpeningFileError : public std::exception {
		const char* what() const throw() override;
	};

	struct EmptyStackError : public std::exception {
		const char* what() const throw() override;
	};

	template <typename T>
	void IsInRange(const T &value, const eOperandType & eType) const;
};


template <typename T>
void LogException::IsInRange(const T &value, const eOperandType & eType) const {
	switch (eType) {
		case Int8:
			if (value < std::numeric_limits<std::int8_t>::min()) {
				throw LogException::UnderflowError();
			}
			else if (value > std::numeric_limits<std::int8_t>::max()) {
				throw LogException::OverflowError();
			}
			break;
		case Int16:
			if (value < std::numeric_limits<std::int16_t>::min()) {
				throw LogException::UnderflowError();
			}
			else if (value > std::numeric_limits<std::int16_t>::max()) {
				throw LogException::OverflowError();
			}
			break;
		case Int32:
			if (value < std::numeric_limits<std::int32_t>::min()) {
				throw LogException::UnderflowError();
			}
			else if (value > std::numeric_limits<std::int32_t>::max()) {
				throw LogException::OverflowError();
			}
			break;
		case Float:
			if (value < std::numeric_limits<float>::lowest()) {
				throw LogException::UnderflowError();
			}
			else if (value > std::numeric_limits<float>::max()) {
				throw LogException::OverflowError();
			}
			break;
		case Double:
			if (value < std::numeric_limits<double>::lowest()) {
				throw LogException::UnderflowError();
			}
			else if (value > std::numeric_limits<double>::max()) {
				throw LogException::OverflowError();
			}
			break;
		case NumberOperands:
			break;
	}
}

#endif //ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP
















