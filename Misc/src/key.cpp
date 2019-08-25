#include <iostream>
#include <conio.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 77
#define KEY_RIGHT 75

int main(){
	while (1){
	 switch((getch())) {
        case KEY_UP:
            cout << endl << "Up" << endl;//key up
            break;
        case KEY_DOWN:
            cout << endl << "Down" << endl;   // key down
            break;
        case KEY_LEFT:
            cout << endl << "Right" << endl;  // key right
            break;
        case KEY_RIGHT:
            cout << endl << "Left" << endl;  // key left
            break;
        default: // not arrow
            break;
        }
    }
	return 0;
}
