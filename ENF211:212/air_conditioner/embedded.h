#ifndef EMBEDDED_H
#define EMBEDDED_H
#include <iostream>
#include<conio.h>
#include <locale.h>
using namespace std;

	void power_on();
	void power_off();
	void print_to_screen();

class Sensor{
	private:
		double temperature;
		double humidity;
	public:
		Sensor(double,double);
		~Sensor();
		double getTemperature();
		double getHumidity();
		
};

class Motor{
	private:
		float motor_speed;
		string motor_type;
	public:
		Motor(float,string);
		~Motor();
		void motor_on();
		void motor_off();
		
};

#endif

