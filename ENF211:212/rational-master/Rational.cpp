#include "Rational.h"

Rational::Rational(){
			pay=0;
			payda=1;
		}
	Rational ::Rational(int pay,int payda){
			if(payda!=0){
				this->pay=pay;
				this->payda=payda;
			}
			else {
				this->pay=0;
				this->payda=1;
			}
		}
	Rational Rational:: sadelestir(Rational rational){
			Rational temp(0,0);
			if(rational.pay>=rational.payda){
				for(int i=2;i<=pay;i++){
					if(rational.pay%i==0 && rational.payda%i==0){
						temp.pay=rational.pay/i;
						temp.payda=rational.payda/i;
					}
				}
			}
			return temp;
		}
	void Rational::kusuratli_print(Rational rational){
			float x;
			x=(float)rational.pay/rational.payda;
			cout<<"Kusuratli sonuc:"<<x<<endl;
		}
	Rational Rational:: operator+(Rational r1){
			cout<<"+ overloaded"<<endl;
			Rational temp(0,0);
			temp.pay=r1.pay*this->payda+this->pay*r1.payda;
			temp.payda=r1.payda*this->payda;
			return temp;
		}
	Rational Rational::operator-(Rational r1){
			cout<<"- overloaded"<<endl;
			Rational temp(0,0);
			temp.pay=r1.pay*this->payda-this->pay*r1.payda;
			temp.payda=r1.payda*this->payda;
			return temp;
		}
	Rational Rational::operator*(Rational r1){
			cout<<"* overloaded"<<endl;
			Rational temp(0,0);
			temp.pay=r1.pay*this->pay;
			temp.payda=r1.payda*this->payda;
			return temp;
		}
	Rational Rational::operator/(Rational r1){
			cout<<"/ overloaded"<<endl;
			Rational temp(0,0);
			temp.pay=r1.pay*this->payda;
			temp.payda=r1.payda*this->pay;
			return temp;
		}
		
		void Rational:: print(void){
			cout<<"Kesirli sonuc:"<<pay<<"/"<<payda<<endl;
		}
