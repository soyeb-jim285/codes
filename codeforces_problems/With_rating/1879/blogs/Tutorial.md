# Tutorial

[1879A - Rigged!](../problems/A._Rigged!.md "Educational Codeforces Round 155 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1879A - Rigged!](../problems/A._Rigged!.md "Educational Codeforces Round 155 (Rated for Div. 2)")

Let's figure out the optimal value of $w$. If $w > s_1$, then Polycarp cannot lift the barbell. If $w < s_1$, then some athletes having less strength than Polycarp might be able to lift the barbell. So the optimal value of $w$ is $s_1$. 

All that's left to do is check that there are such athletes who are able to lift weight $w$ greater than or equal to $e_1$ times. If such athletes exist, then the answer is $-1$. Otherwise, the answer is $s_1$.

 **Solution (Roms)**
```cpp
  
#include <bits/stdc++.h>
 
using namespace std;

const int N = 109;

int t;
int n;
int s[N], e[N];
 
int main() {
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s[i] >> e[i];
        }
        
        bool ok = true;
        for (int i = 1; i < n; ++i) 
            if (s[i] >= s[0] && e[i] >= e[0])
                ok = false;
        
        if (!ok) {
            puts("-1");
            continue;
        }
        
        cout << s[0] << endl;
    }
    return 0;
}


```
[1879B - Chips on the Board](../problems/B._Chips_on_the_Board.md "Educational Codeforces Round 155 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
  
#include <bits/stdc++.h>
 
using namespace std;

using li = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<li> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    li mnA = *min_element(a.begin(), a.end());
    li sA = accumulate(a.begin(), a.end(), 0LL);
    li mnB = *min_element(b.begin(), b.end());
    li sB = accumulate(b.begin(), b.end(), 0LL);
    li ans = min(mnA * n + sB, mnB * n + sA);
    cout << ans << 'n';
  }
}

```
[1879C - Make it Alternating](../problems/C._Make_it_Alternating.md "Educational Codeforces Round 155 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**Tutorial is loading... **Solution (Roms)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998'244'353;

void upd(int &a, int b) {
    a = (a * 1LL * b) % MOD;
}


int t;
string s;

int main() {
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {
	    cin >> s;
	    int res = 1;
	    int k = s.size();
	    int n = s.size();
	    for (int l = 0; l < n; ) {
	        int r = l + 1;
	        while(r < n && s[l] == s[r])
	            ++r;
            upd(res, r - l);
            --k;
            l = r;
	    }
	    
	    for (int i = 1; i <= k; ++i)
	        upd(res, i);
        cout << k << ' ' << res << endl;
	}
}

```
[1879D - Sum of XOR Functions](../problems/D._Sum_of_XOR_Functions.md "Educational Codeforces Round 155 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**Tutorial is loading... **Solution (Roms)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
const int MOD = 998244353;
int n;
int a[N];

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int sum(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    int res = 0;    
    for (int b = 0; b < 30; ++b) {
        int cur = 0;
        vector <int> cnt(2);
        vector <int> sumOfL(2);
        cnt[0] = 1;
        int x = 0;
        for (int i = 0; i < n; ++i) {
            x ^= ((a[i] >> b) & 1);
            int sumOfR = mul(cnt[x ^ 1], i + 1);
            add(cur, sum(sumOfR, -sumOfL[x ^ 1]));
            
            ++cnt[x];
            add(sumOfL[x], i + 1);
        }
        
        add(res, mul(1 << b, cur));
    }
    
    cout << res << endl;
}

```
[1879E - Interactive Game with Coloring](../problems/E._Interactive_Game_with_Coloring.md "Educational Codeforces Round 155 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (BledDest)**
```cpp
  
#include<bits/stdc++.h>

using namespace std;

const int N = 123;

int n;
int color[N];
int countColors[N][N];
int p[N];
vector<int> g[N];
int deg[N];

void add_edge(int x, int y)
{
	g[x].push_back(y);
	g[y].push_back(x);
}

bool tryTwoColors()
{
	int v1 = n + 1;
	int v2 = n + 2;
	for(int i = 2; i <= n; i++)
	{
		if(p[i] != 1)
		{
			add_edge(i, p[i]);
		}
	}
	for(int i = 2; i <= n; i++)
	{
		if(deg[i] == 1)
			add_edge(i, v1);
	}
	for(int i = 2; i <= n; i++)
	{
		if(p[i] != 1 && deg[p[i]] == 1)
			add_edge(i, v2);
	}
	add_edge(v1, v2);
	bool bad = false;
	for(int i = 2; i <= n + 2; i++)
		if(color[i] == 0)
		{
			color[i] = 1;
			queue<int> q;
			q.push(i);
			while(!q.empty())
			{
				int k = q.front();
				q.pop();
				for(auto y : g[k])
				{
					if(color[y] == 0)
					{
						color[y] = 3 - color[k];
						q.push(y);
					}
					else if(color[y] == color[k])
						bad = true;
				}
			}
		}
	if(bad)
		for(int i = 2; i <= n + 2; i++)
			color[i] = 0;
	return !bad;
}

void tryThreeColors()
{
	for(int i = 2; i <= n; i++)
		if(p[i] == 1)
			color[i] = 1;
		else
			color[i] = (color[p[i]] % 3) + 1;
}

int findVertex(const vector<int>& colors)
{
	int s = colors.size();
	for(int i = 2; i <= n; i++)
	{
		if(vector<int>(countColors[i], countColors[i] + s) == colors)
			return i;
	}
	return -1;
}

int main()
{
	cin >> n;
	for(int i = 2; i <= n; i++)
	{
		cin >> p[i];
		deg[p[i]]++;
	}
	
	if(*max_element(p + 2, p + n + 1) == 1)
	{
		for(int i = 2; i <= n; i++)
			color[i] = 1;
	}
	else if (!tryTwoColors())
		tryThreeColors();
	
	int colorsUsed = *max_element(color + 2, color + n + 1);
	
	cout << colorsUsed << endl;
	for(int i = 2; i <= n; i++)
	{
		cout << color[i];
		if(i == n) cout << endl;
		else cout << " ";
	}
	cout.flush();
	
	for(int i = 2; i <= n; i++)
	{
		countColors[i][color[i]]++;
		countColors[p[i]][color[i]]++;
	}
	
	while(true)
	{
		int resp;
		cin >> resp;
		if(resp == -1 || resp == 1)
			exit(0);
		vector<int> counts(colorsUsed + 1);
		for(int i = 1; i <= colorsUsed; i++)
			cin >> counts[i];
		int v = findVertex(counts);
		assert(v != -1);
		cout << color[v] << endl;
		cout.flush();
	}
}


```
[1879F - Last Man Standing](../problems/F._Last_Man_Standing.md "Educational Codeforces Round 155 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (awoo)**
```cpp
  
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		vector<int> h(n), a(n);
		forn(i, n) scanf("%d", &h[i]);
		forn(i, n) scanf("%d", &a[i]);
		int mxa = *max_element(a.begin(), a.end()) + 1;
		
		int l = mxa == 1 ? 0 : (__lg(mxa - 1) + 1);
		vector<vector<pair<int, int>>> st(l, vector<pair<int, int>>(mxa, make_pair(0, -1)));
		vector<vector<int>> st2(l, vector<int>(mxa));
		forn(i, n){
			if (h[i] > st[0][a[i]].first){
				st2[0][a[i]] = st[0][a[i]].first;
				st[0][a[i]] = {h[i], i};
			}
			else if (h[i] > st2[0][a[i]]){
				st2[0][a[i]] = h[i];
			}
		}
		
		auto combine = [&st, &st2](int i, int x, int y){
			int mx = max(st[i][x].first, st[i][y].first);
			if (mx == st[i][x].first)
				return max(st2[i][x], st[i][y].first);
			return max(st[i][x].first, st2[i][y]);
		};
		
		for (int j = 1; j < l; ++j) forn(i, mxa){
			if (i + (1 << (j - 1)) < mxa){
				st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
				st2[j][i] = combine(j - 1, i, i + (1 << (j - 1)));
			}
			else{
				st[j][i] = st[j - 1][i];
				st2[j][i] = st2[j - 1][i];
			}
		}
		vector<int> pw(mxa + 1);
		for (int i = 2; i <= mxa; ++i) pw[i] = pw[i / 2] + 1;
		
		auto getmx = [&st, &pw](int l, int r){
			int len = pw[r - l];
			return max(st[len][l], st[len][r - (1 << len)]);
		};
		auto getmx2 = [&st, &st2, &pw, &combine](int l, int r){
			int len = pw[r - l];
			if (st[len][l].second != st[len][r - (1 << len)].second)
				return combine(len, l, r - (1 << len));
			return max(st2[len][l], st2[len][r - (1 << len)]);
		};
		
		vector<long long> svmx(mxa), svmx2(mxa);
		vector<int> svwho(mxa, -1);
		for (int x = 1; x < mxa; ++x){
			for (int l = 1; l < mxa; l += x){
				int r = min(mxa, l + x);
				int ac = (l - 1) / x + 1;
				auto tmp = getmx(l, r);
				long long mx = tmp.first * 1ll * ac;
				int who = tmp.second;
				long long mx2 = getmx2(l, r) * 1ll * ac;
				if (who == -1) continue;
				if (mx > svmx[x]){
					svmx2[x] = svmx[x];
					svmx[x] = mx;
					svwho[x] = who;
				}
				else if (mx > svmx2[x]){
					svmx2[x] = mx;
				}
				svmx2[x] = max(svmx2[x], mx2);
			}
		}
		
		vector<long long> ans(n);
		forn(i, mxa) if (svwho[i] != -1)
			ans[svwho[i]] = max(ans[svwho[i]], svmx[i] - svmx2[i]);
		
		forn(i, n) printf("%lld ", ans[i]);
		puts("");
	}
	return 0;
}


```
