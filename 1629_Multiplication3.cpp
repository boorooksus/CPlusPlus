#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long long multi(string x, string y, long long c) {
	long long res = 0;

	for (int i = 0; x[i] != '\0'; i++) {
		long long temp = 0;
		for (int j = 0; y[j] != '\0'; j++) {
			temp = ((temp * 10) % c + (long long)((x[i] - 48) * (y[j] - 48))) % c;
		}
		res = ((res * 10) % c + temp) % c;
	}

	return res;
}


int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	string a_str = to_string(a);


	if (b == 1) {
		// == 1 ==========================================================
		cout << a % c << "\n";
	}
	else {
		long long save = 1;
		long long ans = a;
		while (b > 1) {
			string ans_str = to_string(ans);
			if (b % 2 == 1) {
				string save_str = to_string(save);
				save = multi(save_str, ans_str, c);
			}
			ans = multi(ans_str, ans_str, c);
			b /= 2;
		}
		if (save != 1) {
			string save_str = to_string(save);
			string ans_str = to_string(ans);
			ans = multi(save_str, ans_str, c);
		}

		cout << ans << "\n";
	}
}

//분할 정복
// 1 : 여기서 c로 나눈 나머지 안구했다가 틀림