#include <iostream>
using namespace std;

// bottom-up
// LIS(Longest Increasing Subsequence) Problem Extended -> Decreasing
// 가장 긴 감소 부분 수열

int a[1001];
int t[1001];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[n-i+1]);
	}

	t[0] = 0;

	for (int j = 1; j <= n; j++){
		t[j] = 1;
		for (int k = j - 1; k >= 1; k--){
			if ((a[k] < a[j]) && (t[j] < t[k] + 1)) t[j] = t[k] + 1;
		}
	}

	int max = t[1];

	for (int i = 2; i <= n; i++){
		max = (t[i] > max) ? t[i] : max;
	}

	cout << max << endl;

	return 0;

}
