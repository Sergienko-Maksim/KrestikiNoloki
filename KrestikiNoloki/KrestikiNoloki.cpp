#include <iostream>
using namespace std;
bool Iswin(int map[3][3], int turn) {
	bool Win = false;
	for (int i = 0; i < 3; i++) {
		for (int r = 0; r < 3; r++) {
			if (map[r][i] != turn) {
				Win = false;
				break;
			}
			else {
				Win = true;
			}
		}
		if (Win) {
			return true;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int r = 0; r < 3; r++) {
			if (map[i][r] != turn) {
				Win = false;
				break;
			}
			else {
				Win = true;
			}
		}
		if (Win) {
			return true;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (map[i][i] != turn) {
			Win = false;
			break;
		}
		else {
			Win = true;
		}
	}
		if (Win) {
			return true;
		}
	
		for (int i = 2; i >= 0; i--) {
			if (map[i][2 - i] != turn) {
				Win = false;
				break;
			}
			else {
				Win = true;
			}
		}
			return Win;
		}
bool Nichaia(int map[3][3]) {
	bool result = false;
	for (int i = 0; i < 3; i++) {
		for (int r = 0; r < 3; r++) {
			if (map[i][r] != 0) {
				result = true;
			}
			else {
				return false;
			}
		}
	}
	return result;
}
int main(){
	setlocale(0, "rus");
	int turn=2;
	int x, y;
	int map[3][3] = { 0,0,0,
	0,0,0,
	0,0,0 };
	while (true){
		for (int i = 0; i < 3; i++) {
			for (int r = 0; r < 3; r++) {
				if (map[i][r] == 0) {
					cout << " |";
				}
				else if(map[i][r]==1) {
					cout << "X|";
				}
				else {
					cout << "0|";
				}
			}
			cout << endl;
		}
			if (Iswin(map, turn)) {
				if (turn == 1) {
					cout << "Выиграл крестик";
				}
				else {
					cout << "Выиграл нолик";
				}
				break;
		}
			if (Nichaia(map)) {
				cout << "Ничья!";
				break;
			}
		if (turn == 2) {
			cout << "Ходит крестик" << endl;
			cin >> x >> y;
			while (x < 0 || x>2 || y < 0 || y>2 || map[x][y] != 0) {
				cout << "Вы ввели некорректные координаты, повторите попытку" << endl;
				cin >> x >> y;
			}
			map[x][y] = 1;
			turn = 1;
		}
		else {
			cout << "Ходит нолик" << endl;
			cin >> x >> y;
			while (x < 0 || x>2 || y < 0 || y>2 || map[x][y] != 0) {
				cout << "Вы ввели некорректные координаты, повторите попытку" << endl;
				cin >> x >> y;
			}
			map[x][y] = 2;
			turn = 2;

		}
	}
}
