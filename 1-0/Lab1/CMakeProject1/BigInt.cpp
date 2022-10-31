#include "BigInt.h"


BigInt::BigInt() {
	value.push_back(0);
	sign = true;
}


BigInt::BigInt(int arg) {
	value.push_back((unsigned int)abs(arg));
	sign = arg >= 0 ? true : false;
}

BigInt::BigInt(std::string) {

}

BigInt::BigInt(const BigInt& arg) {
	this->value = arg.value;
	this->sign = arg.sign;

}

BigInt::~BigInt() {

}

BigInt& BigInt::operator+=(const BigInt& arg) {
	BigInt cp(arg);
	if (this->value.size() > cp.value.size()) cp.value.resize(this->value.size());
	if (this->value.size() < cp.value.size()) this->value.resize(cp.value.size());
	long long buffer = 0;
	char overbuff = 0;
	long long n = this->value.size();
	for (int itr = 0; itr < n; itr++) {
		buffer = (long long)this->value[itr] + (long long)(cp.sign == this->sign ? 1 : -1) * cp.value[itr];
		buffer += (long long)overbuff;
		overbuff = buffer / UINT_MAX;
		this->value[itr] = (unsigned int) abs(buffer) % UINT_MAX;
	}
	if (buffer < 0) {
		this->sign = !this->sign;
	}
	if (overbuff < 0) {
		this->value.resize(this->value.size()+1);
		this->value[this->value.size() - 1] = overbuff;
	}
	if (overbuff > 0) {
		this->value.resize(this->value.size() + 1);
		this->value[this->value.size() - 1] = overbuff;
	}
	return *this;
}

BigInt& BigInt::operator++() {
	*this += BigInt(1);
	return *this;
}

const BigInt BigInt::operator++(int) {
	const BigInt cp = *this;
	++(*this);
	return cp;
}

BigInt& BigInt::operator--() {
	*this += BigInt(-1);
}

const BigInt BigInt::operator--(int) {
	const BigInt cp = *this;
	--(*this);
	return cp;
}

BigInt& BigInt::operator=(const BigInt& arg) {
	this->value = value;
	this->sign = arg.sign;
	return *this;
}

BigInt BigInt::operator~() const {
	unsigned int n = this->value.size();
	BigInt cp(*this);
	for (int itr = 0; itr < n; itr++) {
		cp.value[itr] = ~cp.value[itr];
	}
	return cp;
}

BigInt BigInt::operator+() const {  // unary +
	return *this;
}

BigInt BigInt::operator-() const {  // unary -
	BigInt cp(*this);
	cp.sign = !cp.sign;
	return cp;
}

BigInt& BigInt::operator-=(const BigInt& arg) {
	(*this) += -arg;
	return *this;
}

BigInt& BigInt::operator^=(const BigInt& arg) {
	if (this->value.size() > arg.value.size()) arg.value.resize(this->value.size());
	if (this->value.size() < arg.value.size()) this->value.resize(arg.value.size());
}
BigInt& operator%=(const BigInt&);
BigInt& operator&=(const BigInt&);
BigInt& operator|=(const BigInt&);