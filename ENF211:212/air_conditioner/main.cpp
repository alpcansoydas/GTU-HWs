#include <iostream>
#include "embedded.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	setlocale(LC_ALL,"Turkish");
	Motor first(15,"stepper");
	Motor second(15,"dc");
	Motor third(45,"dc");
	Motor fourth(15,"stepper");
	Sensor sensor1(25.0,72.0); //sýcaklýk sensörü
	Sensor sensor2(25.0,72.0); //nem sensörü
	char replay;
	
	print_to_screen();
	do{
		power_on();
	
	int mod;
	cin>>mod;
	
	try{           // EXCEPTION HANDLING
		throw mod;
		
	}catch(int mod){
		if(mod>3) cout<<"ERROR!"<<endl;
		if(mod<=0) cout<<"ERROR!"<<endl;
	}
	if(mod==1){    //cool 
			double temperature=sensor1.getTemperature();
			double humidity=sensor2.getHumidity();
			third.motor_on();
		while(temperature!=17){
			cout<<"Sýcaklýk:"<<temperature<<endl<<"Nem:%"<<humidity<<endl<<"..."<<endl;
			temperature--;
			for(int i=0;i<2000000000;i++){
			}
		}
		
	}
	Sensor sensor3(18.0,65.0);
	if(mod==2){
		double temperature=sensor3.getTemperature();
			double humidity=sensor2.getHumidity();
			second.motor_on();
		while(temperature!=22){
			cout<<"Sýcaklýk:"<<temperature<<endl<<"Nem:%"<<humidity<<endl<<"..."<<endl;
			temperature++;
			for(int i=0;i<2000000000;i++){
			}
		}
	}
	if(mod==3){
		double temperature=sensor1.getTemperature();
		double humidity=sensor1.getHumidity();
		first.motor_on();
		while(humidity!=65){
			cout<<"Sýcaklýk:"<<temperature<<endl<<"Nem:%"<<humidity<<endl<<"..."<<endl;
			humidity--;
			for(int i=0;i<2000000000;i++){
			}
		}
	}
	cout<<"Sýcaklýk ve nem deðeri yeterli. Tekrar baþlatmak istiyor musunuz? (Y/N)"<<endl;
	replay=getche();
	}while(replay=='Y' || replay=='y');
	power_off();
	
	return 0;
}
