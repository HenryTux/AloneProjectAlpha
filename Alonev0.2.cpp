#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <windows.h>

void menu();
void title();
void about();
bool fexit(bool exit);

int main(){
	menu();
	system("CLS");
	cout << "Thanks for playing! See you soon :)\n";
	system("pause");
	return 0;
}

void menu(){
	string op;
	int s;
	bool exit = false;
	while(!exit){
		system("CLS");
		title();
		cout << "(P)LAY DEMO\n";
		cout << "(A)BOUT\n";
		cout << "(E)XIT\n";
		do{
			getline(cin, op);
			s=op.length();
			if(s > 1 || s < 1)menu();
		}while(s > 1 || s < 1);
		if(op == "p" || op == "P"){
			system("CLS");
			cout << "Game should start here...\n";
			system("pause");
		}else if(op == "a" || op == "A"){
			system("CLS");
			about();
			system("pause");
		}else if(op == "e" || op == "E"){
			if(fexit(exit) == true)exit = true;
		}else menu();
	}
}

void title(){
    string line, sentry = "XXX";
    ifstream gameIntro;
    gameIntro.open("title.txt");
	getline (gameIntro,line);
    if(gameIntro.is_open()){
        while (line != sentry){
            cout << line << endl;
            getline (gameIntro,line);
        }
        gameIntro.close();
    }
}

void about(){
	string line, sentry = "XXX";
    ifstream gameInfo;
    gameInfo.open("about.txt");
	getline (gameInfo,line);
    if(gameInfo.is_open()){
        while (line != sentry){
            cout << line << endl;
            getline (gameInfo,line);
        }
        gameInfo.close();
    }
}

bool fexit(bool exit){
	string op;
	int s;
	system("CLS");
	cout << "Exit game? (Y)es / (N)o : ";
	do{
		getline(cin, op);
		s=op.length();
		if(s > 1 || s < 1)fexit(exit);
	}while(s > 1 || s < 1);
	if(op == "y" || op == "Y")exit = true;
	else if(op == "n" || op == "N")exit = false;
	else fexit(exit);
	return exit;
}
	
