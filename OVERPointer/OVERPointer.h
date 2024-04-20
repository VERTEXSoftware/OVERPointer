// https://github.com/VERTEXSoftware/OVERPointer
// Copyright (C) 2024 VERTEX Software by Sleptsov Vladimir
// SPDX-License-Identifier: MIT
// Version: 2.1.0-Release
//
//    /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$  /$$$$$$$           /$$             /$$                        
//   /$$__  $$| $$   | $$| $$_____/| $$__  $$| $$__  $$         |__/            | $$                        
//  | $$  \ $$| $$   | $$| $$      | $$  \ $$| $$  \ $$ /$$$$$$  /$$ /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ 
//  | $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/| $$$$$$$//$$__  $$| $$| $$__  $$|_  $$_/   /$$__  $$ /$$__  $$
//  | $$  | $$ \  $$ $$/ | $$__/   | $$__  $$| $$____/| $$  \ $$| $$| $$  \ $$  | $$    | $$$$$$$$| $$  \__/
//  | $$  | $$  \  $$$/  | $$      | $$  \ $$| $$     | $$  | $$| $$| $$  | $$  | $$ /$$| $$_____/| $$      
//  |  $$$$$$/   \  $/   | $$$$$$$$| $$  | $$| $$     |  $$$$$$/| $$| $$  | $$  |  $$$$/|  $$$$$$$| $$      
//   \______/     \_/    |________/|__/  |__/|__/      \______/ |__/|__/  |__/   \___/   \_______/|__/      
//                                                                                                 

#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>

#define OVERPTR_VER_MAJOR 2
#define OVERPTR_VER_MINOR 1
#define OVERPTR_VER_BUGFIX 0

#define OVERPTR_VER ((OVERPTR_VER_MAJOR<<24) + (OVERPTR_VER_MINOR<<16) + (OVERPTR_VER_BUGFIX<<8) + 0)

#define OVERPTR_SIZE sizeof(OVERPTR)
#define OVERPTR_SIZE_ADDRESS sizeof(size_t)
#define OVERPTR_MAX_ADDRESS (size_t)-1


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
		if (pt == NULL) {
			_ptr = NULL;
			_type = 0;
		}
		else if (typeid(OVERPTR) == typeid(T)) {
			this->Copy(pt);
		}
		else {
			_ptr = (void*)(pt);
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
		std::cout << "ADDRESS:   0x" << std::hex << _ptr << std::dec << std::endl;
		std::cout << "HASH_TYPE: 0x" << std::hex << _type << std::dec << std::endl;
	}

	bool IsExist() {
		return (_ptr != NULL) && (_type != 0);
	}

	bool IsNULL() {
		return (_ptr == NULL) || (_type == 0);
	}

	bool IsCorrect() {
		return ((_ptr != NULL) && (_type != 0)||(_ptr == NULL) && (_type == 0));
	}

	bool Compare(const  OVERPTR& pt) {
		return (_ptr == pt._ptr) && (_type == pt._type);
	}	

	void Copy(const  OVERPTR& pt) {
		_ptr = pt._ptr;
		_type = pt._type;
	}

	void* GetRealPTR() {
		return _ptr;
	}

	size_t GetTypeHash() {
		return _type;
	}

	size_t Size() {
		if (_ptr == NULL || _type == 0) { return 0; }
		return sizeof(_ptr);
	}

	template <typename T>
	bool ComparePTR(const T& pt) {
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
			_ptr = (void*)(pt);
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

	void* operator*() {
		return _ptr;
	}

	template <typename T>
	bool Delete() {
		if (_ptr != NULL && _type == typeid(T).hash_code()) {
			delete (T)(_ptr);
			_ptr = NULL;
			_type = 0;
			return true;
		}
		return false;
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
			_ptr = (void*)(pt);
			_type = typeid(pt).hash_code();
		}
	}

	template <typename T>
	T Get() {
		if (_ptr != NULL && _type == typeid(T).hash_code()) {
			return (T)(_ptr);
		}
		return NULL;
	}

	template <typename Func>
	void SetFunc(Func&& f) {

		if (pt == NULL) {
			_ptr = NULL;
			_type = 0;
		}
		else {
			_ptr = reinterpret_cast<void*>(std::addressof(f));
			_type = typeid(std::addressof(f)).hash_code();
		}
	}

	template <typename Func, typename... Args>
	int ExeFunc(Args&&... args) {

		if (_ptr != NULL) {
			auto f = reinterpret_cast<Func>(_ptr);
			f(std::forward<Args>(args)...);

			return 0;
		}
		return 1;

	}

};


//OVERPTRFULL in developing

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
			_ptr = (void*)(pt);
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
		std::cout << "ADDRESS:   0x" << std::hex << _ptr << std::dec << std::endl;
		std::cout << "HASH_TYPE: 0x" << std::hex << _type << std::dec << std::endl;
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

	void* GetRealPTR() {
		return _ptr;
	}

	size_t GetTypeHash() {
		return _type;
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
		if (pt == NULL) {
			_ptr = NULL;
			_name = NULL;
			_type = 0;
		}
		else if (typeid(OVERPTRFULL) == typeid(T)) {
			this->Copy(pt);
		}
		else {
			_ptr = (void*)(pt);
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

	void* operator*() {
		return _ptr;
	}

	template <typename T>
	void Delete() {
		if (_ptr != NULL && _type == typeid(T).hash_code()) {
			delete (T)(_ptr);
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
			_ptr = (void*)(pt);
			_type = typeid(pt).hash_code();
		}
	}

	template <typename T>
	T Get() {
		if (_ptr != NULL && _type == typeid(T).hash_code()) {
			return (T)(_ptr);
		}

		return NULL;
	}



};


