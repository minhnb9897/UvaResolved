// UVA-129-Krypton-Factor.cpp : Bài toán sử dụng Thuật toán quay lui
// author : Minh Nguyen Binh
//
#include <iostream>
#include <string>
using namespace std;
int n, m, cnt;
string s;
bool check_hard(int cur) {
	if (cnt++ == n) {// cnt ghi số lần, luôn chạy đệ quy n lần
		for (int i = 0;i < cur;i++) {
			if (i && i % (16 * 4) == 0) cout << endl;
			else if (i && i % 4 == 0)cout << " ";
			cout << s[i];
		}
		cout << endl << cur << endl;
		return true;
	}
	for (int i = 0;i < m;i++) {
		bool ok = true;
		s[cur] = char('A' + i);
		for (int j = 1;2 * j <= cur + 1;j++) {// mỗi lần so sánh một chuỗi có độ dài bằng j
			bool equal = true;
			for (int k = 0;k < j;k++)
				if (s[cur - k] != s[cur - k - j]) { equal = false; break; }
			if (equal) { ok = false; break; }
		}
		if (ok && check_hard(cur + 1)) return true;
	}
	return false;
}


int main(int argc, char** argv) {
	while (cin >> n >> m && (n || m)) {
		cnt = 0;
		s.resize(n);
		check_hard(0);
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
