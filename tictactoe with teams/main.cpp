#include "TicTacToe.h"

int main(int argc, char** argv) {
	
	char replay;
	TicTacToe t;
	TicTacToe k;
	do{
		t.Play();
		t.Reset();
		if(k==t) cout<<"(==overloaded)Equal"<<endl;  // == overloaded 
		else cout<<"(==overloaded)Not equal"<<endl; // overloade
		cout<<endl<<endl<<"Do you want to play again (Y/N): ";
		replay=getche();  //conio.h'dan gelen fonksiyon entera basmadan baþlatmak için
	}while(replay=='y' || replay=='Y');
	
	getch();   //coni.h'dan gelen fonksiyon konsolun hemen kapanmamasý için
	return 0;
	
}
