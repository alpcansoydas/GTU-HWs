#ifndef rational_h
#define rational_h
#include <iostream>
using namespace std;

class Rational{
	private:
		int pay;
		int payda;
	public:
		Rational();
		Rational(int pay,int payda);
		Rational sadelestir(Rational rational);
		void kusuratli_print(Rational rational);
		Rational operator+(Rational r1);
		Rational operator-(Rational r1);
		Rational operator*(Rational r1);
		Rational operator/(Rational r1);
		void print(void);
};

#endif
