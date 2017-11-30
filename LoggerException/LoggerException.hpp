//
// Created by Roman Malkevych on 11/20/17.
//

#ifndef ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP
#define ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP

#include "../General.hpp"

class LoggerException final {
public:
	LoggerException() = default;
	LoggerException(LoggerException const &) = delete;
	LoggerException &operator=(LoggerException const &) = delete;

	template <typename T, typename N>
	bool IsInRange(const N &value ) const throw() {
		return (value >= std::numeric_limits<T>::min()) &&
			   (value <= std::numeric_limits<T>::max());
	}
	// TODO: handle all errors with precision
};


#endif //ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP
















