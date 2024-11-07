# Tutorial_(en)

Thanks for taking part in the round. I hope you enjoyed the round. It happens that the statements were really easy to understand (thanks to testers). We've got only 38 questions during a round!

 Tutorial is loading... **Code**
```cpp
int n, m;
cin >> n >> m;
int result = -1;
if (m % n == 0) {
    result = 0;
    int d = m / n;
    while (d % 2 == 0)
        d /= 2, result++;
    while (d % 3 == 0)
        d /= 3, result++;
    if (d != 1)
        result = -1;
}
cout << result << endl;
```
 Tutorial is loading... **Code**
```cpp
int n;
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++)
    cin >> a[i];
int result = 0;
int len = 0;
for (int i = 0; i < 2 * n; i++) {
    if (a[i % n] == 1) {
        len++;
        result = max(result, len);
    } else {
        len = 0;
    }
}
cout << result << endl;
```
 Tutorial is loading... **Code**
```cpp
int n;
cin >> n;
vector<int> q(n - 1);
long long sum = 0;
long long min_val = 0;
for (int i = 0; i + 1 < n; i++) {
    cin >> q[i];
    sum += q[i];
    if (sum < min_val)
        min_val = sum;
}
vector<long long> p(n);
p[0] = 1 - min_val;
forn(i, n - 1)
    p[i + 1] = p[i] + q[i];
bool ok = true;
for (int i = 0; i < n; i++)
    if (p[i] < 1 || p[i] > n)
        ok = false;
if (ok)
    ok = set<long long>(p.begin(), p.end()).size() == n;
if (ok) {
    forn(i, n)
        cout << p[i] << " ";
} else
    cout << -1 << endl;
```
 Tutorial is loading... **Code**
```cpp
#define forn(i, n) for (int i = 0; i < int(n); i++)
const int A = 26;
...
int n;
cin >> n;
string l;
cin >> l;
vector<vector<int>> left(A);
vector<int> wl;
forn(i, n)
    if (l[i] != '?')
        left[l[i] - 'a'].push_back(i);
    else
        wl.push_back(i);
string r;
cin >> r;
vector<vector<int>> right(A);
vector<int> wr;
forn(i, n)
    if (r[i] != '?')
        right[r[i] - 'a'].push_back(i);
    else
        wr.push_back(i);
vector<pair<int,int>> p;
vector<int> cl(A), cr(A);
forn(i, A) {
    forn(j, min(left[i].size(), right[i].size()))
        p.push_back(make_pair(left[i][j] + 1, right[i][j] + 1));
    cl[i] = cr[i] = min(left[i].size(), right[i].size());
}
forn(i, A)
    while (cl[i] < left[i].size() && !wr.empty()) {
        p.push_back(make_pair(left[i][cl[i]] + 1, wr[wr.size() - 1] + 1));
        cl[i]++;
        wr.pop_back();
    }
forn(i, A)
    while (cr[i] < right[i].size() && !wl.empty()) {
        p.push_back(make_pair(wl[wl.size() - 1] + 1, right[i][cr[i]] + 1));
        wl.pop_back();
        cr[i]++;
    }
forn(j, min(wl.size(), wr.size()))
    p.push_back(make_pair(wl[j] + 1, wr[j] + 1));
cout << p.size() << endl;
for (auto pp: p)
    cout << pp.first << " " << pp.second << endl;
```
 Tutorial is loading... **Code**
```cpp
long long H;
int n;
cin >> H >> n;
vector<long long> a(n);
long long sum = 0;
long long gap = 0;
long long h = H;
for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum -= a[i];
    h += a[i];
    if (h <= 0) {
        cout << i + 1 << endl;
        return 0;
    }
    gap = max(gap, sum);
}
if (sum <= 0) {
    cout << -1 << endl;
    return 0;
}

long long whole = (H - gap) / sum;
H -= whole * sum;
long long result = whole * n;

for (int i = 0;; i++) {
    H += a[i % n];
    result++;
    if (H <= 0) {
        cout << result << endl;
        break;
    }
}
```
 Tutorial is loading... Tutorial is loading... **Code**
```cpp
int n;
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++)
    cin >> a[i];
map<int, vector<pair<int,int>>> segs;
for (int r = 0; r < n; r++) {
    int sum = 0;                              
    for (int l = r; l >= 0; l--) {
        sum += a[l];
        segs[sum].push_back({l, r});
    }
}
int result = 0;
vector<pair<int,int>> best;
for (const auto& p: segs) {
    const vector<pair<int,int>>& pp = p.second;
    int cur = 0;
    int r = -1;
    vector<pair<int,int>> now;
    for (auto seg: pp)
        if (seg.first > r) {
            cur++;
            now.push_back(seg);
            r = seg.second;
        }
    if (cur > result) {
        result = cur;
        best = now;
    }
}
cout << result << endl;
for (auto seg: best)
    cout << seg.first + 1 << " " << seg.second + 1 << endl;
```
 Tutorial is loading... **Code**
```cpp
int n, k, r;
vector<vector<pair<int,int>>> g;
int D;
vector<int> col;

void dfs(int u, int p, int f) {
    int color = 0;
    for (auto e: g[u])
        if (p != e.first) {
            if (color == f) {
                color = (color + 1) % D;
                f = -1;
            }
            col[e.second] = color;
            dfs(e.first, u, color);
            color = (color + 1) % D;
        }         
}

int main() {
    cin >> n >> k;
    g.resize(n);
    vector<int> d(n);
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back({y, i});
        g[y].push_back({x, i});
        d[x]++, d[y]++;
    }
    map<int,int> cnt;
    for (int dd: d)
        cnt[dd]++;
    
    int kk = n;
    D = 0;
    for (auto p: cnt)
        if (kk > k)
            D = p.first,
            kk -= p.second;
        else
            break;
    col = vector<int>(n - 1);
    dfs(0, -1, -1);    
    cout << D << endl;
    for (int i = 0; i + 1 < n; i++)
        cout << col[i] + 1 << " ";
}
```
