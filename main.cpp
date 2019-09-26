#include <iostream>
using namespace std;

int a[100001];
int f[100001];
int b[100001];

int main() {
	int n;
	cin >> n;
	int total = 0;

	for (int i = 1; i <= n; i++){
		scanf_s("%d", &a[i]);
		total += a[i];
	}

	// 앞에서부터 연속합 구하기
	f[1] = a[1]; f[0] = 0;

	for (int j = 1; j <= n; j++){
		f[j] = a[j];
		if (f[j - 1] + a[j] > f[j]) f[j] = f[j - 1] + a[j];
	}

	// 뒤에서부터 연속합 구하기
	b[n] = a[n]; b[0] = 0;

	for (int k = n - 1; k >= 1; k--){
		b[k] = a[k];
		if (b[k + 1] + a[k] > b[k]) b[k] = b[k + 1] + a[k];
	}

	// 맨 앞을 뺀 경우와 맨 뒤를 뺸 경우 중 전체합이 더 큰 것으로 초기화
	int temp = ((total - a[1]) > (total - a[n])) ? total - a[1] : total - a[n];

	// 전체합에서 아무 숫자도 빼지 않는 경우
	temp = (total > temp) ? total : temp;

	// 연속합에서 아무것도 빼지 않는 경우
	int max = f[1];

	for (int i = 2; i <= n - 1; i++){
		temp = (f[i - 1] + b[i + 1] > temp) ? f[i - 1] + b[i + 1] : temp;
		max = (f[i] > max) ? f[i] : max;
	}

	max = (f[n] > max) ? f[n] : max;

	temp = (max > temp) ? max : temp;

	cout << temp << endl;

	return 0;
}