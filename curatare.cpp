#include <bits/stdc++.h>
using namespace std;

ifstream in("curatare.in");
ofstream out("curatare.out");

const int maxn = 1e3 + 5;
const int inf = 2e9;

char c[maxn][maxn];
int vis[maxn][maxn];

map<pair<pair<int, int>, pair<int, int>>, int> dist;
int dx[] = {-1, 0, 1}, dy[] = {-1, 0, 1};
int n, m;

void bfs(int x, int y) {

    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j < maxn; ++j) {
            vis[i][j] = inf;
        }
    }
    queue<pair<int, int>> q;
    vis[x][y] = 0;
    q.push({x, y});
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (c[u.first][u.second] == 'R' || c[u.first][u.second] == 'S') {
            dist[{{x, y}, {u.first, u.second}}] = vis[u.first][u.second];
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == 1 && j == 1)continue;
                if (i != 1 && j != 1)continue;
                if (u.first + dx[i] < 1 || u.first + dx[i] > n)continue;
                if (u.second + dy[j] < 1 || u.second + dy[j] > m)continue;
                if (vis[u.first + dx[i]][u.second + dy[j]] == inf && c[u.first + dx[i]][u.second + dy[j]] != 'X') {
                    vis[u.first + dx[i]][u.second + dy[j]] = vis[u.first][u.second] + 1;
                    q.push({u.first + dx[i], u.second + dy[j]});
                }
            }
        }
    }
}

vector<pair<int, int>> s, r;
vector<int> robot[10];
int perm[10];
int ans = inf;

void bkt(int step, int len) {
    if (step > len) {

        for (int i = 0; i < r.size(); ++i) {
            robot[i].clear();
        }
        for (int i = 1; i <= s.size(); ++i) {
            robot[perm[i]].push_back(i - 1);
        }
        int sum = 0;
        for (int i = 0; i < r.size(); ++i) {

            int perm2[10];
            int k = 1;
            for (auto u : robot[i]) {
                perm2[k] = u;
                ++k;
            }
            --k;
            if (k == 0)continue;
            int res = inf;
            do {

                int cost = 0;
                int x, y;
                x = r[i].first;
                y = r[i].second;
                for (int j = 1; j <= k; ++j) {
                    cost += dist[{{x, y}, {s[perm2[j]].first, s[perm2[j]].second}}];
                    x = s[perm2[j]].first;
                    y = s[perm2[j]].second; 
                }
                res = min(res, cost);

            }while (next_permutation(perm2 + 1, perm2 + k + 1));

            sum = max(sum, res);
        }
        ans = min(ans, sum);

        return;
    }

    for (int j = 0; j < r.size(); ++j) {
        perm[step] = j;
        bkt(step + 1, len);
    }
    return;
}

int main() {

    
    in >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            in >> c[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (c[i][j] == 'R' || c[i][j] == 'S') {
                bfs(i, j);
            }
            if (c[i][j] == 'R') {
                r.push_back({i, j});
            }
            if (c[i][j] == 'S') {
                s.push_back({i, j});
            }
        }
    }

    bkt(1, s.size());

    out << ans << '\n';

    return 0;
}