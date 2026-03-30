#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Node {
	int x, y, dir;
};

int N;
int classroom[15][15];
string moving;
Node Ahri;
vector<Node> zombies;
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

bool isInClassroom(int nx, int ny) {
	return nx >= 0 && ny >= 0 && nx < N && ny < N;
}

bool checkZombies() {
	if (classroom[Ahri.x][Ahri.y] != 0) return false;
	for (Node& zombie : zombies) {
		if (Ahri.x == zombie.x && Ahri.y == zombie.y)
			return true;
	}
	return false;
}

void moveZombies() {
	for (Node& zombie : zombies) {
		int nx = zombie.x + zombie.dir;
		int ny = zombie.y;

		if (!isInClassroom(nx, ny)) 
			zombie.dir = -zombie.dir;
		else {
			zombie.x = nx;
			zombie.y = ny;
		}
	}
}

void lightOn(int x, int y) {
	if (classroom[x][y] == 2) {
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInClassroom(nx, ny)) 
				if (classroom[nx][ny] == 0) classroom[nx][ny] = 1;
		}
	}
}

void moveAhri(char move) {
	int nx = 0, ny = 0;
	switch (move) {
		case 'F':
			nx = Ahri.x + dx[Ahri.dir];
			ny = Ahri.y + dy[Ahri.dir];
			if (isInClassroom(nx, ny)) {

				Ahri.x = nx;
				Ahri.y = ny;
			}
			break;
		case 'L': Ahri.dir = (Ahri.dir + 1) % 4;
			break;
		case 'R': Ahri.dir = (Ahri.dir + 3) % 4;
			break;
	}
}

string solve() {
	Ahri = { 0, 0, 0 };

	for (int idx = 0; idx < moving.size(); idx++) {
		moveAhri(moving[idx]);
		if (checkZombies()) return "Aaaaaah!";

		lightOn(Ahri.x, Ahri.y);
		moveZombies();
		if (checkZombies()) return "Aaaaaah!";
	}
	
	return "Phew...";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> moving;

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			if (input[j] == 'S') classroom[i][j] = 2;
			else if (input[j] == 'Z') zombies.push_back({ i, j, 1 });
		}
	}

	cout << solve() << '\n';
	return 0;
}
