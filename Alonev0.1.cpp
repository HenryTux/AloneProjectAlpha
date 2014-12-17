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

int main(){
	menu();
	system("CLS");
	cout << "Thanks for playing! See you soon :)\n";
	system("pause");
	return 0;
}

void menu(){
	char op;
	bool exit = false;
	while(!exit){
		system("CLS");
		title();
		cout << "(P)LAY DEMO\n";
		cout << "(A)BOUT\n";
		cout << "(E)XIT\n";
		cin >> op;
		switch(op){
			case 'p':{}
			case 'P':{
				system("CLS");
				cout << "Game should start here...\n";
				system("pause");
			}break;
			case 'a':{}
			case 'A':{
				system("CLS");
				about();
				system("pause");
			}break;
			case 'e':{}
			case 'E':{
				exit = true;
			}break;
			default:
				system("CLS");
				menu();
		}
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
