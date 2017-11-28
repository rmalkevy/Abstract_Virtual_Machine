//
// Created by Roman Malkevych on 11/20/17.
//

#ifndef ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP
#define ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP

#include "../General.hpp"

class PrecisionHandle final {
private:
	void	_stringToInt8(std::string const &stringInt8, CortageType &value) const {
		std::get<0>(value) = (std::stoi(stringInt8));
		std::get<1>(value) = std::get<0>(value);
//		value.valueString = std::to_string(value.valueInt8);
	}
	void	_stringToInt16(std::string const &stringInt16, CortageType &value) const {
		std::get<0>(value) = (std::stoi(stringInt16));
		std::get<1>(value) = std::get<0>(value);
//		value.valueString = std::to_string(value.valueInt16);
	}
	void	_stringToInt32(std::string const &stringInt32, CortageType &value) const {
		std::get<0>(value) = std::stoi(stringInt32);
		std::get<1>(value) = std::get<0>(value);
//		value.valueString = std::to_string(value.valueInt32);
	}
	void	_stringToFloat(std::string const &stringFloat, CortageType &value) const {
		std::get<1>(value) = std::stof(stringFloat);
		std::get<0>(value) = std::get<1>(value);
//		value.valueString = std::to_string(value.valueFloat);
	}
	void	_stringToDouble(std::string const &stringDouble, CortageType &value) const {
		std::get<1>(value) = std::stod(stringDouble);
		std::get<0>(value) = std::get<1>(value);
//		value.valueString = std::to_string(value.valueDouble);
	}

	using	_pf_StringToValue = void (PrecisionHandle::*)(std::string const &stringInt8, CortageType & value) const;
	std::array<_pf_StringToValue, NumberOperands> _arrPf_StringToValue;

public:
	PrecisionHandle(PrecisionHandle const &) = delete;
	PrecisionHandle &operator=(PrecisionHandle const &) = delete;

	// *** Default constructor *** //
	PrecisionHandle() {
		_arrPf_StringToValue[Int8] = &PrecisionHandle::_stringToInt8;
		_arrPf_StringToValue[Int16] = &PrecisionHandle::_stringToInt16;
		_arrPf_StringToValue[Int32] = &PrecisionHandle::_stringToInt32;
		_arrPf_StringToValue[Float] = &PrecisionHandle::_stringToFloat;
		_arrPf_StringToValue[Double] = &PrecisionHandle::_stringToDouble;
	}
	~PrecisionHandle() = default;

	void stringToValue(std::string const &valueString, CortageType & valueOperand, eOperandType eType) const{
		(this->*_arrPf_StringToValue[eType])(valueString, valueOperand);
	}

	template <typename T>
	bool IsInRange( T value ) const {
		return (value >= std::numeric_limits<T>::min()) &&
			   (value <= std::numeric_limits<T>::max());
	}

	// TODO: handle all errors with precision
};


#endif //ABSTRACTVM_PRECISIONHANDLE_SINGLETONCLASS_HPP
