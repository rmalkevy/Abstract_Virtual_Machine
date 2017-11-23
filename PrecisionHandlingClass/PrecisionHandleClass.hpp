//
// Created by Roman Malkevych on 11/20/17.
//

#ifndef ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP
#define ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP

#include "../General.hpp"

template <typename T>
class PrecisionHandle {
private:
	std::int8_t		_stringToInt8(std::string const &stringInt8) const {
		return static_cast<std::int8_t>(std::stoi(stringInt8));
	}
	std::int16_t	_stringToInt16(std::string const &stringInt16) const {
		return static_cast<std::int16_t>(std::stoi(stringInt16));
	}
	int				_stringToInt32(std::string const &stringInt32) const {
		return std::stoi(stringInt32);
	}
	float			_stringToFloat(std::string const &stringFloat) const {
		return std::stof(stringFloat);
	}
	double			_stringToDouble(std::string const &stringDouble) const {
		return std::stod(stringDouble);
	}

	using _pf_StringToValue = T (PrecisionHandle::*)(std::string const &) const;
	std::array<_pf_StringToValue, NumberOperands> _arrPf_StringToValue;

public:
	PrecisionHandle(PrecisionHandle const &) = delete;
	PrecisionHandle &operator=(PrecisionHandle const &) = delete;

	// *** Default constructor *** //
	PrecisionHandle() {
		_arrPf_StringToValue[Int8] = 	&PrecisionHandle::_stringToInt8;
//		_arrPf_StringToValue[Int16] = 	&PrecisionHandle::_stringToInt16;
//		_arrPf_StringToValue[Int32] = 	&PrecisionHandle::_stringToInt32;
//		_arrPf_StringToValue[Float]	= 	&PrecisionHandle::_stringToFloat;
//		_arrPf_StringToValue[Double] = 	&PrecisionHandle::_stringToDouble;
	}
	~PrecisionHandle() = default;

//	static PrecisionHandle *getInstance() {
//		static PrecisionHandle instance;
//		return &instance;
//	}

	//template<typename T>
	T stringToValue(std::string const &valueString, int numberFunction) const {
		return (this->*_arrPf_StringToValue[numberFunction])(valueString);
	}

	//template<typename T>
	bool IsInRange( T value ) const {
		return (value >= std::numeric_limits<T>::min()) &&
			   (value <= std::numeric_limits<T>::max());
	}

	// TODO: handle all errors with precision
};


#endif //ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP
