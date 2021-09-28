#ifndef HOGEVECTOR_HPP_INCLUDED
#define HOGEVECTOR_HPP_INCLUDED

#include <memory>
#include <stdexcept>
#include <iostream>
#include <string>

namespace voidhoge {

template<class T>
class vector {
private:
	using reference = T&;
	using size_type = std::size_t;
	using value_type = T;
	using pointer = T*;
	pointer e;
	size_type _size = 0, _cap = 0;
public:
	vector (){};
	vector (const vector<T>& cp) {
		this->_size = cp.size();
		this->_cap = cp.cap();
		this->e = new value_type[_cap];
		for (size_type i = 0; i < this->size(); i++) {
			*(this->e+i) = *(cp.e+i);
		}
	}
	~vector (){
		delete[] e;
	};
	size_type size() const {
		return _size;
	}
	size_type cap() const {
		return _cap;
	}
	void extend() {
		pointer p;
		if (_cap == 0) {
			p = new value_type[1];
			_cap = 1;
		}else {
			p = new value_type[_size*2];
			for (size_type i = 0; i < _size; i++) {
				*(p+i) = *(e+i);
			}
			delete[] e;
			_cap = _cap*2;
		}
		e = p;
	}
	void push_back(value_type value) {
		if (_size >= _cap) {
			extend();
		}
		e[_size] = value;
		_size++;
	}
	void pop_back() {
		if (_size == 0) {
			throw std::out_of_range("pop_back: size == 0");
		}
		_size--;
	}
	reference operator[](size_type idx) {
		if (_size <= idx) {
			throw std::out_of_range("operator[]: idx too large");
		}
		return e[idx];
	}
	reference at(size_type idx) {
		if (_size <= idx) {
			throw std::out_of_range("at: idx too large");
		}
		return e[idx];
	}
	void dump(std::ostream& os, std::string sep) {
		for (size_type i = 0; i < size()-1; i++) {
			os << at(i) << sep;
		}
		os << at(size()-1);
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, voidhoge::vector<T> v) {
	v.dump(os, " ");
	return os;
}

} // namespace voidhoge

#endif /* end of include guard: HOGEVECTOR_HPP_INCLUDED */
