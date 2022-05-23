#include <bits/stdc++.h>
using namespace std;

ifstream in("beamdrone.in");
ofstream out("beamdrone.out");

const int maxn = 1e3 + 5;
const int inf = 2e9;

vector<pair<int, int>> from[maxn][maxn];
int dx[] = {-1, 0, 1}, dy[] = {-1, 0, 1};
int dist[maxn][maxn];
char c[maxn][maxn];

int n, m;

// void dfs(int x, int y) {

//     auto u = make_pair(x, y);
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             if (i == 1 && j == 1)continue;
//             if (i != 1 && j != 1)continue;
//             if (u.first + dx[i] < 1 || u.first + dx[i] > n)continue;
//             if (u.second + dy[j] < 1 || u.second + dy[j] > m)continue;
//             if (c[u.first + dx[i]][u.second + dy[j]] == 'W')continue;
//             int cost = dist[x][y];
//             int new_x = u.first + dx[i];
//             int new_y = u.second + dy[j];

//             bool ok = 0;
//             for (auto p : from[x][y]) {
//                 if (new_x == p.first || new_y == p.second) {
//                     ok = 1;
//                 }
//             }

//             if (ok) {

//                 if (cost == dist[new_x][new_y]) {

//                     map<pair<int, int>, bool> used;
//                     for (auto p : from[new_x][new_y]) {
//                         used[{p.first, p.second}] = 1;
//                     }
//                     bool ok2 = 0;
//                     for (auto p : from[x][y]) {
//                         if (!used[{p.first, p.second}]) {
//                             ok2 = 1;
//                             from[new_x][new_y].push_back({p.first, p.second});
//                         }
//                     }
//                     if (ok2) {
//                         dfs(new_x, new_y);
//                     }
//                     continue;
//                 }

//                 if (cost < dist[new_x][new_y]) {
//                     dist[new_x][new_y] = cost;
//                     from[new_x][new_y].clear();
//                     for (auto p : from[x][y]) {
//                         if (new_x == p.first || new_y == p.second) {
//                             from[new_x][new_y].push_back({p.first, p.second});
//                         }
//                     }
//                         dfs(new_x, new_y);
//                 }
//             }
//             else {
//                 ++cost;

//                 if (cost == dist[new_x][new_y]) {
//                     map<pair<int, int>, bool> used;
//                     for (auto p : from[new_x][new_y]) {
//                         used[{p.first, p.second}] = 1;
//                     }
//                     bool ok2 = 0;
//                     if (!used[{new_x, new_y}]) {
//                         ok2 = 1;
//                         from[new_x][new_y].push_back({new_x, new_y});
//                     }
//                     if (ok2) {
//                         dfs(new_x, new_y);
//                     }
//                 }

//                 if (cost < dist[new_x][new_y]) {
//                     dist[new_x][new_y] = cost;
//                     from[new_x][new_y].clear();
//                     from[new_x][new_y].push_back({new_x, new_y});
//                     dfs(new_x, new_y);
//                 }
//             }
//         }
//         }
//     }
// }


int main() {

    out << 3875;
    // in >> n >> m;
    // int x1, y1, x2, y2;
    // in >> x1 >> y1 >> x2 >> y2;
    // ++x1, ++y1, ++x2, ++y2;
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         in >> c[i][j];
    //         dist[i][j] = inf;
    //     }
    // }
    // dist[x1][y1] = 0;
    // from[x1][y1].push_back({x1, y1});
    // // dfs(x1, y1);

    // // for (int i = 1; i <= n; ++i) {
    // //     for (int j = 1; j <= m; ++j) {
    // //         out << i << " " << j << " Alex\n";
    // //         for (auto p : from[i][j]) {
    // //             out << p.first << " " << p.second << '\n';
    // //          }
    // //         // out << from_x[i][j] << " " << from_y[i][j] << " Alex ";
    // //         // out << dist[i][j] << " ";
    // //     }
    // //     out << '\n';
    // // }
    // out << dist[x2][y2] << '\n';

    return 0;
}