#include <bits/stdc++.h>
using namespace std;

ifstream in("fortificatii.in");
ofstream out("fortificatii.out");

const int maxn = 1e5 + 5;

bool barbar[maxn];
vector<vector<pair<int, int>>> v(maxn);
const long long infll = 9e18;
typedef long long ll;


vector<ll> dist(maxn, infll);
priority_queue<pair<ll, ll>> q;
vector<ll> routes;


void dijkstra(int root){
    dist[root] = 0;
    q.push({0, root});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        for(auto i : v[u]){
            if(dist[i.second] > dist[u] + i.first){
                dist[i.second] = dist[u] + i.first;
                if (!barbar[i.second]) {
                    q.push({-dist[i.second], i.second});
                }
            }
        }
    }
    return;
}

bool check(ll need, ll k) {
    for (auto u : routes) {
        if (u >= need) return 1;
        ll have = need - u;
        if (k >= have) {
            k -= have;
        }
        else {
            return 0;
        }
    }
    return 1;
}


int main() {

    int n, m, k, b;
    in >> n >> m >> k;
    in >> b;
    for (int i = 1; i <= b; ++i) {
        int x;
        in >> x;
        barbar[x] = 1;
    }

    for (int i = 1; i <= m; ++i) {
        int x, y, cost;
        in >> x >> y >> cost;
        v[x].push_back({cost, y});
        v[y].push_back({cost, x});
    }
    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        if (!barbar[i])continue;
        for (auto u : v[i]) {
            if (barbar[u.second])continue;
            routes.push_back(dist[u.second] + u.first);
        }
    }
    sort(routes.begin(), routes.end());
    ll left = 0, right = 1e15, answer = 0;;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid, k)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    out << answer << '\n';

    return 0;
}