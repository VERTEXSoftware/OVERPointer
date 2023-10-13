// https://github.com/VERTEXSoftware/OVERPointer
// Copyright (C) 2023 VERTEX Software by Sleptsov Vladimir
// SPDX-License-Identifier: MIT


#pragma once

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>



class OVERPTR {
private:
	void* _ptr;
	size_t _type;
public:

	OVERPTR() {
		_ptr = NULL;
		_type = 0;
	}

	template <typename T>
	OVERPTR(const T& pt) {
		if (pt == nullptr) {
			_ptr = NULL;
			_type = 0;
		}
		else if (typeid(OVERPTR) == typeid(T)) {
			this->Copy(pt);
		}
		else {
			_ptr = static_cast<void*>(pt);
			_type = typeid(pt).hash_code();
		}
	}

	~OVERPTR() {
		_ptr = NULL;
		_type = 0;
	}

	void Clear() {
		_ptr = NULL;
		_type = 0;
	}

	void Print() {
		std::cout << "ADDRESS:   0x" << std::hex << _ptr << std::endl;
		std::cout << "HASH_TYPE: 0x" << std::hex << _type << std::endl;
	}

	bool IsExist() {
		return (_ptr != NULL) && (_type != 0);
	}

	bool Compare(const  OVERPTR& pt) {
		return (_ptr == pt._ptr) && (_type == pt._type);
	}
	

	void Copy(const  OVERPTR& pt) {
		_ptr = pt._ptr;
		_type = pt._type;
	}

	size_t Size() {
		if (_ptr == NULL || _type == 0) { return 0; }
		return sizeof(_ptr);
	}

	template <typename T>
	bool ÑomparePTR(const T& pt) {
		return (_ptr == pt) && (_type == typeid(T).hash_code());
	}

	template <typename T>
	OVERPTR& operator=(const T& pt) {
		if (pt == nullptr) {
			_ptr = NULL;
			_type = 0;
		}
		else if (typeid(OVERPTR) == typeid(T)) {
			this->Copy(pt);
		}
		else {
			_ptr = static_cast<void*>(pt);
			_type = typeid(pt).hash_code();
		}
		return *this;
	}

	bool operator==(const OVERPTR& pt) const {
		return (_ptr == pt._ptr) && (_type == pt._type);
	}

	bool operator!=(const OVERPTR& pt) const {
		return (_ptr != pt._ptr) || (_type != pt._type);
	}

	template <typename T>
	void Delete() {
		if (_ptr != NULL && _type == typeid(T).hash_code()) {
			delete static_cast<T>(_ptr);
			_ptr = NULL;
			_type = 0;
		}
	}

	template <typename T>
	bool Is() {
		if (_ptr == NULL || _type == 0) { return false; }
		return (_type == typeid(T).hash_code());
	}

	template <typename T>
	void Set(const T& pt) {
		if (pt == NULL) {
			_ptr = NULL;
			_type = 0;
		}
		else {
			_ptr = static_cast<void*>(pt);
			_type = typeid(pt).hash_code();
		}
	}

	template <typename T>
	T Get() {
		if (_ptr == NULL || _type != typeid(T).hash_code()) {
			return NULL;
		}
		else {
			return static_cast<T>(_ptr);
		}
	}


};



class OVERPTRFULL {
private:
	void* _ptr;
	const char* _name;
	size_t _type;
public:

	OVERPTRFULL() {
		_ptr = NULL;
		_name = NULL;
		_type = 0;
	}

	template <typename T>
	OVERPTRFULL(const T& pt) {
		if (pt == nullptr) {
			_ptr = NULL;
			_name = NULL;
			_type = 0;
		}
		else if (typeid(OVERPTR) == typeid(T)) {
			this->Copy(pt);
		}
		else {
			_ptr = static_cast<void*>(pt);
			_name = typeid(pt).name();
			_type = typeid(pt).hash_code();
		}
	}

	~OVERPTRFULL() {
		_ptr = NULL;
		_name = NULL;
		_type = 0;
	}

	void Clear() {
		_ptr = NULL;
		_name = NULL;
		_type = 0;
	}

	void Print() {
		std::cout << "ADDRESS:   0x" << std::hex << _ptr << std::endl;
		std::cout << "HASH_TYPE: 0x" << std::hex << _type << std::endl;
		std::cout << "NAME_TYPE: " << ((_name==NULL) ? "NULL" : _name) << std::endl;
	}

	const char* Name() {
		return ((_name == NULL) ? "NULL" : _name);
	}

	bool IsExist() {
		return (_ptr != NULL) && (_type != 0);
	}

	bool Compare(const  OVERPTRFULL& pt) {
		return (_ptr == pt._ptr) && (_type == pt._type);
	}


	void Copy(const  OVERPTRFULL& pt) {
		_ptr = pt._ptr;
		_name = pt._name;
		_type = pt._type;
	}

	size_t Size() {
		if (_ptr == NULL || _type == 0) { return 0; }
		return sizeof(_ptr);
	}

	template <typename T>
	bool ÑomparePTR(const T& pt) {
		return (_ptr == pt) && (_type == typeid(T).hash_code());
	}

	template <typename T>
	OVERPTRFULL& operator=(const T& pt) {
		if (pt == nullptr) {
			_ptr = NULL;
			_name = NULL;
			_type = 0;
		}
		else if (typeid(OVERPTRFULL) == typeid(T)) {
			this->Copy(pt);
		}
		else {
			_ptr = static_cast<void*>(pt);
			_name = typeid(pt).name();
			_type = typeid(pt).hash_code();
		}
		return *this;
	}

	bool operator==(const OVERPTRFULL& pt) const {
		return (_ptr == pt._ptr) && (_type == pt._type);
	}

	bool operator!=(const OVERPTRFULL& pt) const {
		return (_ptr != pt._ptr) || (_type != pt._type);
	}

	template <typename T>
	void Delete() {
		if (_ptr != NULL && _type == typeid(T).hash_code()) {
			delete static_cast<T>(_ptr);
			_ptr = NULL;
			_name = NULL;
			_type = 0;
		}
	}

	template <typename T>
	bool Is() {
		if (_ptr == NULL || _type == 0) { return false; }
		return (_type == typeid(T).hash_code());
	}

	template <typename T>
	void Set(const T& pt) {
		if (pt == NULL) {
			_ptr = NULL;
			_name = NULL;
			_type = 0;
		}
		else {
			_ptr = static_cast<void*>(pt);
			_type = typeid(pt).hash_code();
		}
	}

	template <typename T>
	T Get() {
		if (_ptr == NULL || _type != typeid(T).hash_code()) {
			return NULL;
		}
		else {
			return static_cast<T>(_ptr);
		}
	}


};


