#include <iostream>
#include <queue>
using namespace std;

int main() {
	int s, d;
	int dist[100001] = { 0 };
	bool check[100001] = { false };

	cin >> s >> d;

	queue <int> q;
	q.push(s);
	dist[s] = 0;
	check[s] = true;

	while (!q.empty()){
		int x = q.front();

		q.pop();

		// 여기서 x값을 destination과 비교해서 바로 dist값을 출력하면 시간복잡도를 줄일 수 있다.
		// 굳이 모든 값에 대한 dist값을 계산하지 않고 원하는 값의 dist 값을 찾으면 끝내기 때문에
		if (x == d) {
			cout << dist[x] << endl;
			break;
		}
		int s_1 = x + 1;
		if (s_1 >= 0 && s_1 <= 100000 && check[s_1] == false){
			q.push(s_1);
			dist[s_1] = dist[x] + 1;
			check[s_1] = true;
			
		}
		int s_2 = x - 1;
		if (s_2 >= 0 && s_2 <= 100000 && check[s_2] == false){
			q.push(s_2);
			dist[s_2] = dist[x] + 1;
			check[s_2] = true;
		}
		int s_3 = 2 * x;
		if (s_3 >= 0 && s_3 <= 100000 && check[s_3] == false){
			q.push(s_3);
			dist[s_3] = dist[x] + 1;
			check[s_3] = true;
		}

	}
	return 0;
}
