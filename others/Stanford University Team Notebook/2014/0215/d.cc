#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		vector<bool> used_char (27, false);
		vector<vector<bool> > adj(27, vector<bool>(27, false));
		vector<double> expr(26, 0);

		for(int i = 0; i < n; i ++) {
			int x;
			string s; cin >> s; x = s[0] - 'A';
			used_char[x] = true;
			cin >> expr[x];
			cin >> s;
			for(int j = 0; j < s.size(); j ++) {
				if(s[j] == '*') {
					adj[x][26] = true;
					adj[26][x] = true;
				}
				else {
					int y = s[j] - 'A';
					adj[y][x] = true;
					adj[x][y] = true;
				}
			}
		}

		vector<int> dist(27, -1);
		queue<int> q;
		q.push(26);
		dist[26] = 0;

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for(int i = 0; i < 27; i ++) {
				if(adj[i][x] && dist[i] == -1) {
					q.push(i);
					dist[i] = dist[x] + 1;
				}
			}
		}
		double best = -1;
		int from = -1;
		for(int i = 0; i < 26; i ++) {
			if(dist[i] != -1) {
				expr[i] = expr[i] * pow(0.95, dist[i] - 1);
				if(best < expr[i]) {
					best = expr[i]; from = i;
				}
			}
		}

		cout << "Import from " << (char)('A' + from) << endl;


	}
}
