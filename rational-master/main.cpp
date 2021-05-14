#include "Rational.h"
int main(int argc, char** argv) {
	Rational r1(6,1);
	Rational r2(15,3);
	Rational r3;

	r3=r1+r2;
	r3.kusuratli_print(r3);
	r3=r3.sadelestir(r3);
	r3.print();
	
	r3=r2-r1;
	r3.kusuratli_print(r3);
	r3=r3.sadelestir(r3);
	r3.print();
	
	r3=r2*r1;
	r3.kusuratli_print(r3);
	r3=r3.sadelestir(r3);
	r3.print();
	
	r3=r2/r1;
	r3.kusuratli_print(r3);
	r3=r3.sadelestir(r3);
	r3.print();
	return 0;
}
