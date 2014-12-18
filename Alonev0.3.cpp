#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <windows.h>

void title();
void about();

int main(){
	string Menu[3] = {"PLAY DEMO", "ABOUT", "EXIT"};
	int aux = 0, menuspeed = 100;
	while(true){
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		/*+ info: http://msdn.microsoft.com/en-us/library/windows/desktop/ms686047(v=vs.85).aspx
				  http://msdn.microsoft.com/es-es/library/windows/desktop/ms683231%28v=vs.85%29.aspx */
		title();
		for(int i = 0; i < 3; i++){
			if (i == aux){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //4 = Red. On CMD, color /help
				cout << Menu[i] << endl;
			}else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Menu[i] << endl;
			}
		}
		while(true){
			if(GetAsyncKeyState(VK_UP) != 0){
			/*+info: http://msdn.microsoft.com/es-es/library/windows/desktop/ms646293%28v=vs.85%29.aspx*/
				aux -= 1;
				if(aux == -1)aux = 2;
				break;
			}else if (GetAsyncKeyState(VK_DOWN) != 0){
				aux += 1;
				if(aux == 3)aux = 0;break;
			}else if (GetAsyncKeyState(VK_RETURN) != 0){
				switch(aux){
					case 0:{
						system("CLS");
						cout << "Game should start here...\n";
						system("pause");
						main();
					}break;
					case 1:{
						system("CLS");
						about();
						system("pause");
						main();
					}break;
					case 2:{
						system("CLS");
						cout << "Thanks for playing! See you soon :)\n";
						system("pause");
						return 0;
					}break;
				}
			}
		}
		Sleep(menuspeed); /*http://msdn.microsoft.com/en-us/library/windows/desktop/ms686298%28v=vs.85%29.aspx*/
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
