#include <iostream>
#include <conio.h>
#include "TicTacToe.h"
using namespace std;

		void TicTacToe::Play(){
			for(int i=0;i<4;i++){          
					for(turn=1;turn<=4;turn++){
						system("cls");
				PrintBoard();
				Input();
				
				int validInput = AddMark();
				if(!validInput){         //geçersiz bir sayý girerse i'yi bir azaltýp devam et.
					i--;
					continue; 
				}
				if((input==1 || input==6 || input==11 || input==16 || input==4 || input==7 || input==10 || input==13)&& (mark=="O" || mark=="o")) diagonal_o++;
				else if((input==1 || input==6 || input==11 || input==16 || input==4 || input==7 || input==10 || input==13)&& (mark=="X" || mark=="x")) diagonal_x++;
				if(turn==2) count_x++;
				else if(turn==1) count_o++;
				else if(turn==3) count_o++;
				else if(turn==4) count_x++;
				Result(i);
				if(won!=0) { analyze(); return;	}
					}
			} 
		}
		void TicTacToe::Result(int i){
			if(Check()){
				system("cls");
				PrintBoard();
				if(turn==1 || turn==3){
					cout<<endl<<"*** Team Oo - You Won ***";
					won=1;
					return;
				}
				else{
					cout<<endl<<"*** Team Xx - You Won ***";
					won=2;
					return;
				}
			}
			if(i==8){
				system("cls");
				PrintBoard();
				cout<<endl<<"*** Match Draw ***";
				won=3;	
				return;
			}
			won=0;
		}
		int TicTacToe::getResult(){
			return won;
		}
		void TicTacToe::Input(){
			cin>>input;
			while(input<0 || input>16){
				cout<<"Invalid input. Please re-enter: ";
				cin>>input;
			}
			if(turn==1) mark ="O";
			else if(turn==2) mark="X";
			else if(turn==3) mark="o";
			else if(turn==4) mark="x";
		}
		void TicTacToe::PrintBoard(){
			cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" | "<<board[0][3]<<" "<<endl;
			
			cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" | "<<board[1][3]<<" "<<endl;
			
			cout<<" "<<board[2][0]<<" | "<<board[2][1]<<"| "<<board[2][2]<<"| "<<board[2][3]<<" "<<endl;
			
			cout<<" "<<board[3][0]<<"| "<<board[3][1]<<"| "<<board[3][2]<<"| "<<board[3][3]<<" "<<endl;
			
			if(turn==1) cout<<"O - Player 1: ";
			else if(turn==2) cout<<"X - Player 2: ";
			else if(turn==3) cout<<"o - Player 3: ";
			else if(turn==4) cout<<"x - Player 4: ";
		}
		int TicTacToe::AddMark(){
			for(int i=0,k=1;i<4;i++){
				for(int j=0;j<4;j++,k++){
					if(k==input){
						if(board[i][j]!="O" && board[i][j]!="X" && board[i][j]!="x" && board[i][j]!= "o"){
							board[i][j]=mark;
						}
						else{
							return 0;
						}
					}
				}
			}
		}
		int TicTacToe::Check(){
			//rows
			if((board[0][0]=="o" || board[0][0]=="O") && (board[0][1]=="O" || board[0][1]=="o") && (board[0][2]=="o" || board[0][2]=="O") && (board[0][3]=="o" || board[0][3]=="O"))
			return 1;
			if((board[0][0]=="x" || board[0][0]=="X") && (board[0][1]=="x" || board[0][1]=="X") && (board[0][2]=="X" || board[0][2]=="x") && (board[0][3]=="x" || board[0][3]=="X"))
			return 1;
			if((board[1][0]=="O" || board[1][0]=="o") && (board[1][1]=="O" || board[1][1]=="o") && (board[1][2]=="O" || board[1][2]=="o") && (board[1][3]=="O" || board[1][3]=="o"))
			return 1;
			if((board[1][0]=="x" || board[1][0]=="X") && (board[1][1]=="x" || board[1][1]=="X") && (board[1][2]=="x" || board[1][2]=="X") && (board[1][3]=="x" || board[1][3]=="X"))
			return 1;
			if((board[2][0]=="O" || board[2][0]=="o") && (board[2][1]=="o" || board[2][1]=="O") && (board[2][2]=="o" || board[2][2]=="O") && (board[2][3]=="o" || board[2][3]=="O"))
			return 1;
			if((board[2][0]=="X" || board[2][0]=="x") && (board[2][1]=="x" || board[2][1]=="X") && (board[2][2]=="x" || board[2][2]=="X") && (board[2][3]=="x" || board[2][3]=="X"))
			return 1;
			if((board[3][0]=="o" || board[3][0]=="O") && (board[3][1]=="o" || board[3][1]=="O") && (board[3][2]=="o" || board[3][2]=="O") && (board[3][3]=="o" || board[3][3]=="O"))
			return 1;
			if((board[3][0]=="x" || board[3][0]=="X") && (board[3][1]=="x" || board[3][1]=="X") && (board[3][2]=="x" || board[3][2]=="X") && (board[3][3]=="x" || board[3][3]=="X"))
			return 1;
			//columns
			if((board[0][0]=="o" || board[0][0]=="O") && (board[1][0]=="O" || board[1][0]=="o") && (board[2][0]=="o" || board[2][0]=="O") && (board[3][0]=="o" || board[3][0]=="O"))
			return 1;
			if((board[0][0]=="x" || board[0][0]=="X") && (board[1][0]=="x" || board[1][0]=="X") && (board[2][0]=="X" || board[2][0]=="x") && (board[3][0]=="x" || board[3][0]=="X"))
			return 1;
			if((board[0][1]=="O" || board[0][1]=="o") && (board[1][1]=="O" || board[1][1]=="o") && (board[2][1]=="O" || board[2][1]=="o") && (board[3][1]=="O" || board[3][1]=="o"))
			return 1;
			if((board[0][1]=="x" || board[0][1]=="X") && (board[1][1]=="x" || board[1][1]=="X") && (board[2][1]=="x" || board[2][1]=="X") && (board[3][1]=="x" || board[3][1]=="X"))
			return 1;
			if((board[0][2]=="O" || board[0][2]=="o") && (board[1][2]=="o" || board[1][2]=="O") && (board[2][2]=="o" || board[2][2]=="O") && (board[3][2]=="o" || board[3][2]=="O"))
			return 1;
			if((board[0][2]=="X" || board[0][2]=="x") && (board[1][2]=="x" || board[1][2]=="X") && (board[2][2]=="x" || board[2][2]=="X") && (board[3][2]=="x" || board[3][2]=="X"))
			return 1;
			if((board[0][3]=="o" || board[0][3]=="O") && (board[1][3]=="o" || board[1][3]=="O") && (board[2][3]=="o" || board[2][3]=="O") && (board[3][3]=="o" || board[3][3]=="O"))
			return 1;
			if((board[0][3]=="x" || board[0][3]=="X") && (board[1][3]=="x" || board[1][3]=="X") && (board[2][3]=="x" || board[2][3]=="X") && (board[3][3]=="x" || board[3][3]=="X"))
			return 1;
			//diagonals
			if((board[0][0]=="O" || board[0][0]=="o") && (board[1][1]=="o" || board[1][1]=="O") && (board[2][2]=="o" || board[2][2]=="O") && (board[3][3]=="o" || board[3][3]=="O"))
			return 1;
			if((board[0][0]=="X" || board[0][0]=="x") && (board[1][1]=="x" || board[1][1]=="X") && (board[2][2]=="x" || board[2][2]=="X") && (board[3][3]=="X" || board[3][3]=="X"))
			return 1;
			if((board[0][3]=="o" || board[0][3]=="O") && (board[1][2]=="o" || board[1][2]=="O") && (board[2][2]=="o" || board[2][2]=="O") && (board[3][0]=="o" || board[3][0]=="O"))
			return 1;
			if((board[0][3]=="x" || board[0][3]=="X") && (board[1][2]=="x" || board[1][2]=="X") && (board[2][2]=="x" || board[2][2]=="X") && (board[3][0]=="x" || board[3][0]=="X"))
			return 1;
		}
		void TicTacToe::analyze(){
			float column_x,rows_x,column_o,rows_o;
				column_x=(float)count_x/16;
				rows_x=(float)count_x/16;
				column_o=(float)count_o/16;
				rows_o=(float)count_o/16;
				cout<<"\nTeam Xx column=%"<<column_x*100<<" row=%"<<rows_x*100<<" diagonal=%"<<(float)diagonal_x*12.5<<endl;
				cout<<"Team Oo column=%"<<column_o*100<<" row=%"<<rows_o*100<<" diagonal=%"<<(float)diagonal_o*12.5<<endl;
		}
		void TicTacToe::Reset(){
			
			board[0][0]="1"; board[0][1]="2"; board[0][2]="3"; board[0][3]="4";
			board[1][0]="5"; board[1][1]="6"; board[1][2]="7"; board[1][3]="8";
			board[2][0]="9"; board[2][1]="10"; board[2][2]="11"; board[2][3]="12";
			board[3][0]="13"; board[3][1]="14"; board[3][2]="15"; board[3][3]="16";
				turn=1;
				mark="O";
				won=0;
				input=0;
		}		
