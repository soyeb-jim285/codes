# Tutorial

[1749A - Cowardly Rooks](../problems/A._Cowardly_Rooks.md "Educational Codeforces Round 138 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1749A - Cowardly Rooks](../problems/A._Cowardly_Rooks.md "Educational Codeforces Round 138 (Rated for Div. 2)")

First, note that m is always less than or equal to n. If there were at least n+1 rooks on the board, at least two of them would share a row or a column (by pigeonhole principle).

If m<n, then there is always at least one free row and at least one free column. You can move any rook into that row or column.

Otherwise, all rows and columns are taken, so any move will make two rooks share a row or a column, which is prohibited.

Thus, if m=n, then it's "NO". Otherwise, it's "YES".

Overall complexity: O(1) per testcase.

Alternatively, you could check every rook and every possible move.

Overall complexity: O(m2⋅n2) per testcase.

 **Solution 1 (awoo)**
```cpp
for _ in range(int(input())):
    n, m = map(int, input().split())
    for _ in range(m):
        input()
    print("NO" if n == m else "YES")
```
 **Solution 2 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    forn(_, t){
        int n, m;
        scanf("%d%d", &n, &m);
        vector<pair<int, int>> a(m);
        forn(i, m){
            scanf("%d%d", &a[i].first, &a[i].second);
            --a[i].first, --a[i].second;
        }
        bool ans = false;
        forn(i, m) forn(x, n) forn(y, n) if ((x == a[i].first) ^ (y == a[i].second)){
            bool ok = true;
            forn(j, m) if (i != j){
                ok &= x != a[j].first && y != a[j].second;
            }
            ans |= ok;
        }
        puts(ans ? "YES" : "NO");
    }
}
```
[1749B - Death's Blessing](../problems/B._Death's_Blessing.md "Educational Codeforces Round 138 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toLong() }
        val b = readLine()!!.split(' ').map { it.toLong() }

        println(a.sum() + b.sum() - b.maxOrNull()!!)
    }
}
```
[1749C - Number Game](../problems/C._Number_Game.md "Educational Codeforces Round 138 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int ans = 0;
    for (int k = 1; k <= n; ++k) {
      multiset<int> s(a.begin(), a.end());
      for (int i = 0; i < k; ++i) {
        auto it = s.upper_bound(k - i);
        if (it == s.begin()) break;
        s.erase(--it);
        if (!s.empty()) {
          int x = *s.begin();
          s.erase(s.begin());
          s.insert(x + k - i);
        }
      }
      if (s.size() + k == n) ans = k;
    }
    cout << ans << 'n';
  }
}
```
[1749D - Counting Arrays](../problems/D._Counting_Arrays.md "Educational Codeforces Round 138 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}   

int sub(int x, int y)
{
    return add(x, -y);
}   

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

bool prime(int x)
{
    for(int i = 2; i * 1ll * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;    
}

int main()
{
    int n;
    long long m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = add(ans, binpow(m % MOD, i));
    long long cur = 1;
    int cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        if(cur > m) continue;
        if(prime(i)) cur *= i;
        cnt = mul(cnt, (m / cur) % MOD);
        ans = sub(ans, cnt);
    }
    cout << ans << endl;
}
```
[1749E - Cactus Wall](../problems/E._Cactus_Wall.md "Educational Codeforces Round 138 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &it : s) cin >> it;
    
    auto in = [&](int x, int y) {
      return 0 <= x && x < n && 0 <= y && y < m;
    };
    
    auto can = [&](int x, int y) {
      if (!in(x, y)) return false;
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (in(nx, ny) && s[nx][ny] == '#')
          return false;
      }
      return true;
    };
    
    vector<vector<int>> d(n, vector<int>(m, INF)), p(n, vector<int>(m));
    deque<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (s[i][0] == '#') {
          d[i][0] = 0;
          q.push_front({i, 0});
        } else if (can(i, 0)) {
          d[i][0] = 1;
          q.push_back({i, 0});
        }
    }
    
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop_front();
      for (int i = 4; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!can(nx, ny)) continue;
        int w = (s[nx][ny] != '#');
        if (d[nx][ny] > d[x][y] + w) {
          d[nx][ny] = d[x][y] + w;
          p[nx][ny] = i;
          if (w) q.push_back({nx, ny});
          else q.push_front({nx, ny});
        }
      }
    }
    
    int x = 0, y = m - 1;
    for (int i = 0; i < n; ++i) if (d[x][y] > d[i][y])
      x = i;
    if (d[x][y] == INF) {
      cout << "NOn";
      continue;
    }
    while (true) {
      s[x][y] = '#';
      int i = p[x][y];
      if (!i) break;
      x -= dx[i];
      y -= dy[i];
    }
    cout << "YESn";
    for (auto it : s) cout << it << 'n';
  }
}
```
[1749F - Distance to the Path](../problems/F._Distance_to_the_Path.md "Educational Codeforces Round 138 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") и [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);

const int N = int(2e5) + 55;
const int LOG = 18;

int n;
vector<int> g[N];

inline bool read() {
    if(!(cin >> n))
        return false;
    fore (i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return true;
}

int p[LOG][N];
int tin[N], tout[N], T = 0;

void build(int v, int pr) {
    tin[v] = T++;
    p[0][v] = pr;
    fore (pw, 1, LOG)
        p[pw][v] = p[pw - 1][p[pw - 1][v]];
    
    for (int to : g[v]) {
        if (to == pr)
            continue;
        build(to, v);
    }
    tout[v] = T;
}

bool inside(int l, int v) {
    return tin[l] <= tin[v] && tout[v] <= tout[l];
}

int lca(int u, int v) {
    if (inside(u, v))
        return u;
    if (inside(v, u))
        return v;
    
    for (int pw = LOG - 1; pw >= 0; pw--) {
        if (!inside(p[pw][u], v))
            u = p[pw][u];
    }
    return p[0][u];
}

const int D = 21;
struct Fenwick {
    int n;
    vector<int> F;
    void init(int nn) {
        n = nn;
        F.assign(n, 0);
    }
    
    void add(int pos, int val) {
        for (; pos < n; pos |= pos + 1)
            F[pos] += val;
    }
    int sum(int pos) {
        int ans = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
            ans += F[pos];
        return ans;
    }
    int getSum(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }
};

struct DS {
    Fenwick f;
    void init(int n) {
        f.init(n);
    }
    
    void addPath(int v, int l, int k) {
        f.add(tin[v], +k);
        f.add(tin[l], -k);
    }
    int getVertex(int v) {
        return f.getSum(tin[v], tout[v]);
    }
    
    void addVertex(int v, int k) {
        f.add(tin[v], +k);
        if (p[0][v] != v)
            f.add(tin[p[0][v]], -k);
    }
};

DS t[D];

inline void solve() {
    fore (i, 0, D) {
        g[n - 1 + i].push_back(n + i);
        g[n + i].push_back(n - 1 + i);
    }
    int root = n + D - 1;
    
    build(root, root);
    fore (i, 0, D)
        t[i].init(root + 1);
    
    int m; cin >> m;
    fore(_, 0, m) {
        int tp; cin >> tp;
        if (tp == 1) {
            int v; cin >> v;
            v--;
            
            int ans = 0;
            for (int i = 0, cur = v; i < D; i++, cur = p[0][cur])
                ans += t[i].getVertex(cur);
            cout << ans << endl;
        } 
        else {
            assert(tp == 2);

            int u, v, k, d;
            cin >> u >> v >> k >> d;
            u--, v--;
            
            int l = lca(u, v);
            
            if (u != l)
                t[d].addPath(u, l, k);
            if (v != l)
                t[d].addPath(v, l, k);
            
            for (int i = 0; i <= d; i++, l = p[0][l]) {
                t[d - i].addVertex(l, k);
                if (d - i > 0)
                    t[d - i - 1].addVertex(l, k);
            }
        }
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    if(read()) {
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
```
