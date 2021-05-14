#include "embedded.h"


void power_on(){
	cout<<"|__________AIR CONDITIONER_________|"<<endl;
	cout<<"|KLÝMA AÇIK!                       |"<<endl;
	cout<<"|MOD(1):COOL                       |"<<endl;
	cout<<"|MOD(2):HEAT                       |"<<endl;
	cout<<"|MOD(3):DRY                        |"<<endl;
	cout<<"|                                  |"<<endl;
	cout<<"|__________________________________|"<<endl;
}
void print_to_screen(){
	for(int i=0;i<36;i++){
		cout<<"*";
		for(int i=0;i<100000000;i++){ //delay için
	}
	}
	cout<<endl<<"              WELCOME"<<endl;
	
}

void power_off(){
	system("cls");
	cout<<"|__________AIR CONDITIONER_________|"<<endl;
	cout<<"|KLÝMA KAPALI!                     |"<<endl;
	cout<<"|__________________________________|"<<endl;
}
//-------------------
Motor::Motor(float motor_speed=0.0,string motor_type="noname"){   //constructor
	motor_speed=this->motor_speed;
	motor_type=this->motor_type;
}

Motor::~Motor(){	//destructor
	
}

void Motor::motor_on(){
	cout<<"Calisiyor.."<<endl;
}

void Motor::motor_off(){
	cout<<motor_type<<"kapali."<<endl;
}


//-----------------
Sensor::Sensor(double temperature=0,double humidity=0){    //constructor
	this->temperature=temperature;
	this->humidity=humidity;
}
Sensor::~Sensor(){   //destructor
	
}
double Sensor::getHumidity(){ return humidity;}
double Sensor::getTemperature(){ return temperature; }

