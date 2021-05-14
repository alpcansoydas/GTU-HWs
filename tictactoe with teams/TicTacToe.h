#ifndef TICTACTOE_H
#define TICTACTOE_H
	#include <iostream>
	#include <conio.h>
	using namespace std;

	class TicTacToe{
		private:
			string board[4][4];
			string mark;
			int turn;
			int won;
			int input;
			int count_x,count_o,diagonal_x,diagonal_o;
		public:
			TicTacToe():board{"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"}{     // constructor init list
			turn=1;
			mark="O";
			won=0;
			input=0;
			count_x=0;
			count_o=0;
			diagonal_x=0;
			diagonal_o=0;
		}
			void Play();
			void Result(int);
			int getResult();
			void Input();
			void PrintBoard();
			int AddMark();
			int Check();
			void analyze();
			void Reset();		
			bool operator==(TicTacToe oth){     //operator overloading func
				return(this->count_o==oth.count_o && this->count_x==oth.count_x && this->diagonal_o==oth.diagonal_o && this->diagonal_x==oth.diagonal_o);
}
};






#endif
