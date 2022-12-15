#include "BigInt.h"


BigInt::BigInt() {
	value.push_back(0);
	sign = true;
}


BigInt::BigInt(int arg) {
	value.push_back((unsigned int)abs(arg));
	sign = arg >= 0 ? true : false;
}

BigInt::BigInt(std::string strl) {
	value.push_back(0);
	sign = true;
	unsigned long long size_strl = strl.size();
	char start = 0;
	if (size_strl == 0)
		throw std::invalid_argument("wrong input");
	if (size_strl == 1 && (strl[0] == '+' || strl[0] == '-'))
		throw std::invalid_argument("wrong inpout");
	if (strl[0] == '-') {
		start++;
	}else
	if(strl[0] == '+'){
	  start++;
	}
    if (!std::isdigit(strl[start])) {
		throw std::invalid_argument("it isn't a number");
    }
    (*this) += BigInt(int(strl[start] - '0'));
    start++;
    for (int i = start; i < size_strl; i++) {
        (*this) *= BigInt(10);
        if (!std::isdigit(strl[i]))
			throw std::invalid_argument("it isn't a number");
        (*this) += BigInt(int(strl[i] - '0'));

	}
    if (strl[0] == '-')
            sign= false;
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
	this->deleteNulls();
	return *this;
}

BigInt& BigInt::operator/=(const BigInt& number){
  BigInt this_mod = this->sign ? (*this) : -(*this);
  BigInt number_mod = number.sign ? (number) : -(number);
  BigInt left(1);
  BigInt right(this_mod);
  BigInt buffer(0);
  BigInt zero(0);
  BigInt one(1);
  BigInt temp_res;
  if (number_mod == zero) {
      throw std::invalid_argument("Invalid argument of divide\n");
  }
  if ((this_mod == zero) || (this_mod < number_mod)) {
      return (*this = zero);
  }
  while ((left != right) && ((left + one) != right)) {
      buffer = right + left;
      buffer.div2();
      temp_res = buffer * number_mod;
      if (temp_res >= this_mod)
          right = buffer;
      if (temp_res <= this_mod)
          left = buffer;
  }
  if ((left != right) && (right * number_mod <= this_mod))
      left = right;
  left.sign = true;
  if ((number.sign) ^ (this->sign)) {
      left = -left;
  }
  left.deleteNulls();
  return (*this = left);
}

BigInt& BigInt::operator%=(const BigInt &arg) {
    BigInt buff = (*this / arg);
    buff *= arg;
    *this -= buff;
    return *this;
}

void BigInt::div2() {
    unsigned int buffer;
    for (size_t i = 0; i + 1 < value.size(); ++i) {
        value[i] >>= 1;
        buffer = (value[i + 1] & 0x01);
        buffer <<= 31;
        value[i] |= buffer;
    }
    value[value.size() - 1] >>= 1;
    this->deleteNulls();
}
void BigInt::deleteNulls(){
  size_t n = this->value.size();
  for(int i = n-1; i > 0; i--){
    if(this->value[i] != 0) return;
    this->value.pop_back();
    }
}

BigInt& BigInt::operator*=(const BigInt& arg){
    BigInt res(0);
    unsigned long long buffer = 0;
    BigInt mid_res;
    size_t ln = this->value.size();
    size_t rn = arg.value.size();
    mid_res = BigInt(0);
    mid_res.value.resize(ln+rn);
    for(size_t itr = 0; itr < ln; itr++){
        for(size_t jtr = 0; jtr < rn;jtr++){
          buffer = static_cast<unsigned long long>(arg.value[jtr]) * static_cast<unsigned long long>(value[itr]);
          mid_res.value[itr + jtr] = buffer % UINT_MAX;
          mid_res.value[itr + jtr + 1] = (buffer / UINT_MAX);
          res += mid_res;
          mid_res.value[itr + jtr] = 0;
          mid_res.value[itr + jtr + 1] = 0;
        }
    }
    res.deleteNulls();
    res.sign = this->sign == arg.sign ? true : false;
    *this = res;
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
	return *this;
}

const BigInt BigInt::operator--(int) {
	const BigInt cp = *this;
	--(*this);
	return cp;
}

BigInt& BigInt::operator=(const BigInt& arg) {
    this->value = arg.value;
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
	BigInt cp(arg);
	if (this->value.size() > cp.value.size()) cp.value.resize(this->value.size());
	if (this->value.size() < cp.value.size()) this->value.resize(cp.value.size());
	unsigned long long n = this->value.size();
	for (long long itr = 0; itr < n; itr++) {
		this->value[itr] ^= cp.value[itr];
	}
	return *this;
}

BigInt& BigInt::operator&=(const BigInt& arg) {
	BigInt cp(arg);
	if (this->value.size() > cp.value.size()) cp.value.resize(this->value.size());
	if (this->value.size() < cp.value.size()) this->value.resize(cp.value.size());
	unsigned long long n = this->value.size();
	for (long long itr = 0; itr < n; itr++) {
		this->value[itr] &= cp.value[itr];
	}
	return *this;
}

BigInt& BigInt::operator|=(const BigInt& arg) {
	BigInt cp(arg);
	if (this->value.size() > cp.value.size()) cp.value.resize(this->value.size());
	if (this->value.size() < cp.value.size()) this->value.resize(cp.value.size());
	unsigned long long n = this->value.size();
    for (unsigned long long itr = 0; itr < n; itr++) {
		this->value[itr] |= cp.value[itr];
	}
	return *this;
}

bool BigInt::operator==(const BigInt&arg) const {
	if (arg.value.size() != this->value.size()) return false;
	unsigned long long n = this->value.size();
	for (unsigned long long itr = 0; itr < n; itr++) {
		if (arg.value[itr] != this->value[itr]) return false;
	}
	return true;
}

bool BigInt::operator!=(const BigInt&arg) const {
	if (arg.value.size() != this->value.size()) return true;
	unsigned long long n = this->value.size();
	for (unsigned long long itr = 0; itr < n; itr++) {
		if (arg.value[itr] != this->value[itr]) return true;
	}
	return false;
}

bool BigInt::operator<(const BigInt&arg) const {
	if (this->sign < arg.sign) return true;
	if (this->sign > arg.sign) return false;
	if (this->value.size() < arg.value.size()) return true;
	if (this->value.size() > arg.value.size()) return false;
	long long n = this->value.size();
	for(long long i = n-1; i >= 0; i--)
	  if(arg.value[i] != this->value[i])
	    return this->value[i] < arg.value[i];
	return false;
}

bool BigInt::operator>(const BigInt&arg) const {
	if (this->sign < arg.sign) return false;
	if (this->sign > arg.sign) return true;
	if (this->value.size() < arg.value.size()) return false;
	if (this->value.size() > arg.value.size()) return true;
	long long n = this->value.size();
	for(long long i = n-1; i >= 0; i--)
	  if(arg.value[i] != this->value[i])
	    return this->value[i] > arg.value[i];
	return false;
}

bool BigInt::operator<=(const BigInt& arg) const {
	if (this->sign < arg.sign) return true;
	if (this->sign > arg.sign) return false;
	if (this->value.size() < arg.value.size()) return true;
	if (this->value.size() > arg.value.size()) return false;
	long long n = this->value.size();
	for(long long i = n-1; i >= 0; --i)
	  if(this->value[i] != arg.value[i])
	    return this->value[i] < arg.value[i];
	return true;
}

bool BigInt::operator>=(const BigInt& arg) const {
	if (this->sign < arg.sign) return false;
	if (this->sign > arg.sign) return true;
	if (this->value.size() < arg.value.size()) return false;
	if (this->value.size() > arg.value.size()) return true;
	long long n = this->value.size();
	for(long long i = n-1; i >= 0; i--)
	  if(arg.value[i] != this->value[i])
	    return this->value[i] > arg.value[i];
	return true;
}

size_t BigInt::size() const {
	return sizeof(BigInt);
}

BigInt operator+(const BigInt&arg1, const BigInt&arg2) {
	BigInt cp(arg1);
	cp += arg2;
	return cp;
}

BigInt operator-(const BigInt&arg1, const BigInt&arg2) {
	BigInt cp(arg1);
	cp -= arg2;
	return cp;
}

BigInt operator/(const BigInt&arg1, const BigInt&arg2) {
	BigInt cp(arg1);
	cp /= arg2;
	return cp;
}

BigInt operator%(const BigInt&arg1, const BigInt&arg2) {
	BigInt cp(arg1);
	cp %= arg2;
	return cp;
}

BigInt operator*(const BigInt& arg1, const BigInt& arg2) {
	BigInt bg1 = arg1, bg2 = arg2;
	bg1 *= bg2;
	return bg1;
}


BigInt operator^(const BigInt&arg1, const BigInt&arg2) {
	BigInt bg1 = arg1, bg2 = arg2;
	bg1 ^= bg2;
	return bg1;
}

BigInt operator&(const BigInt&arg1, const BigInt&arg2) {
	BigInt bg1 = arg1, bg2 = arg2;
	bg1 &= bg2;
	return bg1;
}

BigInt operator|(const BigInt& arg1, const BigInt& arg2) {
	BigInt bg1 = arg1, bg2 = arg2;
	bg1 |= bg2;
	return bg1;
}

BigInt::operator std::string() const{
	BigInt base(10);
	BigInt zero(0);
	BigInt cp(*this > zero ? *this : -(*this));
	std::string strl = "";

	while(cp > zero){
	      BigInt bd(cp);
	      bd %= BigInt(10);
	      strl += ('0' + (cp % base).value[0]);
	      cp /= BigInt(10);
	}
	if(*this < zero)
	  strl += '-';
	for(int i = 0; i < strl.length()/2; i++){
	    std::swap(strl[i], strl[strl.length() - i - 1]);
	  }
	return strl;
}

std::ostream& operator<<(std::ostream& o, const BigInt& i){
  std::string strl = std::string(i);
  for(int i =0;i < strl.length(); i++){
      o << strl[i];
    }
    return o;
}
