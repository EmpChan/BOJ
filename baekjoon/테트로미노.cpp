#include <iostream>

using namespace std;

int maxi;
int map[500][500];
int n, m;

void searchA() { //  ㅡ 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-3; j++) {
			int k = 0;
			for (int l = 0; l < 4; l++) {
				k += map[i][j + l];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}

void searchB() { // I
	for (int i = 0; i < n-3; i++) {
		for (int j = 0; j < m; j++) {
			int k = 0;
			for (int l = 0; l < 4; l++) {
				k += map[i+l][j];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}

void searchC() { // ㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = 0;
			for (int l = 0; l < 2; l++) {
				for (int o = 0; o < 2; o++) {
					k += map[i + l][j+o];
				}
			}
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchD() { // L
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = 0;
			for (int l = 0; l < 3; l++) {
				if (l == 2)
					k += map[i + l][j] + map[i + l][j + 1];
				else
					k += map[i + l][j];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchE() { // L other side
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = 0;
			for (int l = 0; l < 3; l++) {
				if (l == 2)
					k += map[i + l][j] + map[i + l][j + 1];
				else
					k += map[i + l][j+1];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}

void searchF() { // r
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int k = 0;
			for (int l = 0; l < 3; l++) {
				if (l == 0)
					k += map[i][j+l] + map[i + 1][j + l];
				else
					k += map[i][j + l];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}

void searchG() { // r other side
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int k = 0;
			for (int l = 0; l < 3; l++) {
				if (l == 2)
					k += map[i][j + l] + map[i + 1][j + l];
				else
					k += map[i][j + l];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}

void searchH() { // ㄴ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int k = 0;
			for (int l = 0; l < 3; l++) {
				if (l == 0)
					k += map[i][j + l] + map[i + 1][j + l];
				else
					k += map[i + 1][j + l];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}

void searchI() { // ㄴ other side
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int k = 0;
			for (int l = 0; l < 3; l++) {
				if (l == 2)
					k += map[i][j + l] + map[i + 1][j + l];
				else
					k += map[i + 1][j + l];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}

void searchJ() { // ㄱ other side
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = 0;
			for (int l = 0; l < 3; l++) {
				if (l == 0)
					k += map[i + l][j] + map[i + l][j + 1];
				else
					k += map[i + l][j];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchK() { // r
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = 0;
			for (int l = 0; l < 3; l++) {
				if (l == 0)
					k += map[i + l][j] + map[i + l][j + 1];
				else
					k += map[i + l][j + 1];
			}
			if (k > maxi)
				maxi = k;
		}
	}
}

void searchL() { // N
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = 0;
			k += map[i][j + 1];
			k += map[i + 1][j] + map[i + 1][j + 1];
			k += map[i + 2][j];
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchM() { // N other side
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = 0;
			k += map[i][j];
			k += map[i + 1][j] + map[i + 1][j + 1];
			k += map[i + 2][j + 1];
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchN() { // Z
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int k = 0;
			k += map[i][j];
			k += map[i][j+1] + map[i + 1][j + 1];
			k += map[i + 1][j + 2];
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchO() { // Z other side
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int k = 0;
			k += map[i+1][j];
			k += map[i][j+1] + map[i + 1][j + 1];
			k += map[i][j + 2];
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchP() { // ㅗ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int k = 0;
			k += map[i + 1][j];
			k += map[i][j + 1] + map[i + 1][j + 1];
			k += map[i+1][j + 2];
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchQ() { // ㅜ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int k = 0;
			k += map[i][j];
			k += map[i][j + 1] + map[i + 1][j + 1];
			k += map[i][j + 2];
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchR() { // ㅓ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = 0;
			k += map[i][j+1];
			k += map[i+1][j] + map[i + 1][j + 1];
			k += map[i + 2][j + 1];
			if (k > maxi)
				maxi = k;
		}
	}
}
void searchS() { // ㅏ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = 0;
			k += map[i][j];
			k += map[i + 1][j] + map[i + 1][j + 1];
			k += map[i + 2][j];
			if (k > maxi)
				maxi = k;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	searchA();searchB(); // I
	searchC(); // ㅁ
	searchD();searchE();searchF();searchG();
	searchH();searchI();searchJ();searchK(); // ㄴ
	searchL();searchM();searchN();searchO(); // Z
	searchP(); searchQ(); searchR(); searchS();//ㅗ
	cout << maxi;
	return 0;
}