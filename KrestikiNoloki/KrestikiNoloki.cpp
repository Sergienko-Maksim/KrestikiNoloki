#include <iostream>
using namespace std;
bool CheckColForWin(int map[3][3], int turn, int i) {
	for (int r = 0; r < 3; r++) {
		if (map[r][i] != turn) {
			return false;
		}
	}
	return true;
}
bool CheckRowForWin(int map[3][3], int turn, int i) {
	for (int r = 0; r < 3; r++) {
		if (map[i][r] != turn) {
			return false;
		}
	}
	return true;
}
bool Iswin(int map[3][3], int turn) {
	bool Win = false;
	for (int i = 0; i < 3; i++) {
		if (CheckColForWin(map, turn, i) || CheckRowForWin(map, turn, i)) {
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
	for (int i = 0; i < 3; i++)
		for (int r = 0; r < 3; r++)
			if (map[i][r] == 0)
				return false;
	return true;
}
void Turn(int map[3][3], int* turn) {
	int x, y;
	cout << "Ходит " << (*turn == 2 ? "крестик" : "нолик") << endl;
	cin >> x >> y;
	while (x < 1 || x>3 || y < 1 || y>3 || map[y-1][x-1] != 0) {
		cout << "Вы ввели некорректные координаты, повторите попытку" << endl;
		cin >> x >> y;
	}
	y -= 1;
	x -= 1;
	map[y][x] = 3 - *turn;
	*turn = 3 - *turn;
}
void Draw(int map[3][3]) {
	cout <<  "  1 2 3" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "|";
		for (int r = 0; r < 3; r++) {
			if (map[i][r] == 0) {
				cout << " |";
			}
			else if (map[i][r] == 1) {
				cout << "X|";
			}
			else {
				cout << "0|";
			}
		}
		cout << endl;
	}
}
int main() {
	setlocale(0, "rus");
	int turn = 2;
	int map[3][3] = { 0,0,0,
	0,0,0,
	0,0,0 };
	while (true) {
		Draw(map);
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
		Turn(map, &turn);
	}
}
