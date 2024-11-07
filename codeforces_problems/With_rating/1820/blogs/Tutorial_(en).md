# Tutorial_(en)

[1820A - Yura's New Name](../problems/A._Yura's_New_Name.md "Codeforces Round 866 (Div. 2)")

Author: [FairyWinx](https://codeforces.com/profile/FairyWinx "Grandmaster FairyWinx")

Preparation: [FairyWinx](https://codeforces.com/profile/FairyWinx "Grandmaster FairyWinx")

 **Editorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s == "^") {
            cout << 1 << 'n';
            continue;
        }
        int ans = 0;
        if (s[0] == '_')
            ++ans;
        if (s.back() == '_')
            ++ans;
        for (int i = 0; i < (int) s.size() - 1; ++i) {
            if (s[i] == '_' && s[i + 1] == '_')
                ++ans;
        }
        cout << ans << 'n';
    }
}
```
[1820B - JoJo's Incredible Adventures](../problems/B._JoJo's_Incredible_Adventures.md "Codeforces Round 866 (Div. 2)")

Author: [golikovnik](https://codeforces.com/profile/golikovnik "Grandmaster golikovnik")

Preparation: [teraqqq](https://codeforces.com/profile/teraqqq "International Grandmaster teraqqq")

 **Editorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s; s += s;
        int k = 0, z = 0;
        for (char c : s) {
            z = c == '1' ? z+1 : 0;
            k = max(k, z);
        }
        const int n = s.size() / 2;

        if (k > n) {
            cout << (ll)n*n << 'n';
        } else {
            const ll side_a = (k+1)/2;
            const ll side_b = (k+2)/2;
            cout << side_a * side_b << 'n';
        }
    }
}
```
[1819A - Constructive Problem](https://codeforces.com/contest/1819/problem/A "Codeforces Round 866 (Div. 1)")

Author: [TeaTime](https://codeforces.com/profile/TeaTime "Master TeaTime")

Preparation: [golikovnik](https://codeforces.com/profile/golikovnik "Grandmaster golikovnik")

 **Editorial**Tutorial is loading... **Solution**
```cpp
//  Nikita Golikov, 2023

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A& x, B&& y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A& x, B&& y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

template <class T>
int calcMex(vector<T> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int n = int(v.size());
  for (int i = 0; i < n; ++i) if (v[i] != i) return i;
  return n;
}

bool solveTest() {
  int n; cin >> n;
  vector<int> a(n);
  map<int, int> leftOcc, rightOcc;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    rightOcc[a[i]] = i;
    if (!leftOcc.count(a[i])) leftOcc[a[i]] = i;
  }
  int mex = calcMex(a);
  if (leftOcc.count(mex + 1)) {
    int L = leftOcc[mex + 1], R = rightOcc[mex + 1];
    for (int i = L; i <= R; ++i) {
      a[i] = mex;
    }
    int mx = calcMex(a);
    assert(mx <= mex + 1);
    return mx == mex + 1;
  }
  for (int i = 0; i < n; ++i) {
    assert(a[i] != mex);
    if (a[i] > mex || (leftOcc[a[i]] != rightOcc[a[i]])) {
      return true;
    }
  }
  return false;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    cout << (solveTest() ? "Yes" : "No") << 'n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}
```
[1819B - The Butcher](https://codeforces.com/contest/1819/problem/B "Codeforces Round 866 (Div. 1)")

Author: [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

Preparation: [Kon567889](https://codeforces.com/profile/Kon567889 "Master Kon567889")

 **Editorial**Tutorial is loading... **Solution**
```cpp
//#pragma GCC target("trapv")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iostream>
#include <list>
#include <stack>
#include <cassert>
using namespace std;

typedef long long ll;
typedef long double ld;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll INF = 1e9 * 1e9 + 100, SZ = 1100;

ll n;
vector<pair<ll, ll>> vec;
map<ll, pair<ll, ll>> blocks;

pair<ll, ll> solve() {
	set<pair<ll, ll>> widest, longest;

	for (size_t i = 0; i < vec.size(); i++) {
		widest.insert({ vec[i].first, i });
		longest.insert({ vec[i].second, i });

		blocks[i] = vec[i];
	}

	pair<ll, ll> ans = { -1, -1 };
	bool mode = 0;
	ll prevw = INF, prevh = INF, prv = -1;
	bool cringe = 0;
	while (widest.size() != 0) {
		if (mode == 0) {
			ll cur = (*widest.rbegin()).first, sum = 0;
			if (ans.second == -1) ans.second = cur;
			prv = blocks[(*widest.rbegin()).second].second;

			while (widest.size() > 0 && (*widest.rbegin()).first == cur) {
				auto it = (--widest.end());
				longest.erase({blocks[it->second].second, it->second });
				sum += blocks[it->second].second;
				widest.erase(it);
			}

			if (!cringe) ans.first = sum;
			prv = sum;
			if (prevw == INF) {
				prevh = cur;
			} else {
				prevw -= sum;
				if (prevh != cur) return { -1, -1 };
			}
		} else {
			ll cur = (*longest.rbegin()).first, sum = 0;
			if (!cringe) {
				ans.first = cur + prv;
				cringe = 1;
			}

			while (longest.size() > 0 && (*longest.rbegin()).first == cur) {
				auto it = (--longest.end());
				widest.erase({ blocks[it->second].first, it->second });
				sum += blocks[it->second].first;
				longest.erase(it);
			}

			if (prevw == INF) {
				prevw = cur;
				prevh -= sum;
				if (prevw != cur) return { -1, -1 };
			} else {
				prevh -= sum;
				if (prevw != cur) return { -1, -1 };
			}
		}

		mode ^= 1;
	}

	if (prevh == 0 || prevw == 0 || prevh == INF || prevw == INF) {
		return ans;
	} else {
		return { -1, -1 };
	}
}

signed main() {
	fastInp;

    ll t;
    cin >> t;
    
    while (t--) {
        vec.clear();
        blocks.clear();
    	cin >> n;
    
    	vec.resize(n);
    	for (auto& c : vec) cin >> c.first >> c.second;
    
    	vector<pair<ll, ll>> ans;
    
    	ans.push_back(solve());
    	swap(ans.back().first, ans.back().second);
    	if (ans.back().first == -1) ans.pop_back();
    
    	for (auto& c : vec) swap(c.first, c.second);
    
    	ans.push_back(solve());
    	if (ans.back().first == -1) ans.pop_back();
    
    	if (ans.size() == 2 && ans[0] == ans[1]) {
    		ans.pop_back();
    	}
    	cout << ans.size() << "n";
    
    	for (auto c : ans) cout << c.first << " " << c.second << "n";
    }
    
	return 0;
}
```
[1819C - The Fox and the Complete Tree Traversal](https://codeforces.com/contest/1819/problem/C "Codeforces Round 866 (Div. 1)")

Author: [golikovnik](https://codeforces.com/profile/golikovnik "Grandmaster golikovnik")

Preparation: [DishonoredRighteous](https://codeforces.com/profile/DishonoredRighteous "Grandmaster DishonoredRighteous")

 **Editorial**Tutorial is loading... **Solution**
```cpp
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":t" << (x) << std::endl
#else
    #define debug(x) 238
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 200100;

std::vector<int> g[N];
int d[N], par[N];
bool onDiameter[N];

void dfs(int v, int p, int depth) {
	d[v] = depth;
	par[v] = p;

	for (auto to : g[v]) {
		if (to != p) {
			dfs(to, v, depth + 1);
		}
	}
}

void run() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; ++i) {
		int from, to;
		scanf("%d%d", &from, &to);
		g[from - 1].push_back(to - 1);
		g[to - 1].push_back(from - 1);
	}    

	dfs(0, 0, 0);
	int v1 = 0;
	for (int i = 0; i < n; ++i) {
		if (d[i] > d[v1]) {
			v1 = i;
		}
	}

	dfs(v1, v1, 0);
	int v2 = v1;
	for (int i = 0; i < n; ++i) {
		if (d[i] > d[v2]) {
			v2 = i;
		}
	}

	std::vector<int> diameter;
	for (int v = v2; v != v1; v = par[v]) {
		onDiameter[v] = true;
		diameter.push_back(v);
	}
	onDiameter[v1] = true;
	diameter.push_back(v1);
	std::reverse(diameter.begin(), diameter.end());

	for (int i = 0; i < n; ++i) {
		if (onDiameter[i]) {
			continue;
		}
		if (!onDiameter[par[i]]) {
			printf("Non");
			return;
		}
	}

	printf("Yesn");
	std::vector<int> ans;
	for (int i = 0; i < (int)diameter.size(); i += 2) {
		ans.push_back(diameter[i]);
		if (i + 1 != (int)diameter.size()) {
			for (auto to : g[diameter[i + 1]]) {
				if (!onDiameter[to]) {
					ans.push_back(to);
				}
			}
		}
	}

	if (diameter.size() % 2 == 0) {
		for (int i = (int)diameter.size() - 1; i > 0; i -= 2) {
			ans.push_back(diameter[i]);
			if (i - 1 >= 0) {
				for (auto to : g[diameter[i - 1]]) {
					if (!onDiameter[to]) {
						ans.push_back(to);
					}
				}
			}
		}
	} else {
		for (int i = (int)diameter.size() - 1; i > 0; i -= 2) {
			ans.push_back(diameter[i - 1]);
			if (i - 2 >= 0) {
				for (auto to : g[diameter[i - 2]]) {
					if (!onDiameter[to]) {
						ans.push_back(to);
					}
				}
			}
		}
	}

	assert((int)ans.size() == n);
	for (auto i : ans) {
		printf("%d ", i + 1);
	}
	printf("n");
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    #ifdef PERVEEVM_LOCAL
        auto start = std::chrono::high_resolution_clock::now();
    #endif

    run();

    #ifdef PERVEEVM_LOCAL
        auto end = std::chrono::high_resolution_clock::now();
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}
```
[1819D - Misha and Apples](https://codeforces.com/contest/1819/problem/D "Codeforces Round 866 (Div. 1)")

Author: [Um_nik](https://codeforces.com/profile/Um_nik "Legendary Grandmaster Um_nik")

Preparation: [dshindov](https://codeforces.com/profile/dshindov "Candidate Master dshindov")

 **Editorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

#include <exception>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> apples(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            apples[i].push_back(x);
        }
    }
    // vector<int> last(m + 1, -1);
    unordered_map<int, int> last;
    auto get_last = [&](int i) {
        if (!last.count(i)) {
            return -1;
        } else {
            return last[i];
        }
    };
    vector<char> can_zero(n + 1, false);
    vector<int> prev(n + 1, 0);
    can_zero[0] = true;
    int oops = -1;
    for (int i = 0; i < n; ++i) {
        if (apples[i].empty()) {
            can_zero[i + 1] = true;
            last[0] = i;
        } else {
            int nearest_pair = get_last(0);
            int new_oops = oops;
            for (int x : apples[i]) {
                nearest_pair = max(nearest_pair, get_last(x));
                new_oops = max(new_oops, get_last(x));
                last[x] = i;
            }
            if (nearest_pair != -1) {
                int nearest_zero = prev[nearest_pair];
                if (oops < nearest_zero) {
                    can_zero[i + 1] = true;
                }
            }
            oops = new_oops;
        }
        if (can_zero[i + 1]) {
            prev[i + 1] = i + 1;
        } else {
            prev[i + 1] = prev[i];
        }
    }
    // vector<char> used(m + 1, false);
    unordered_set<int> used;
    vector<int> max_cnt(n + 1, 0);
    int current_cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        bool fail = false;
        if (apples[i].empty()) {
            used.insert(0);
        }
        for (int x : apples[i]) {
            if (used.count(x)) {
                fail = true;
                break;
            }
            used.insert(x);
            ++current_cnt;
        }
        if (fail) {
            break;
        }
        if (used.count(0)) {
            max_cnt[i] = m;
        } else {
            max_cnt[i] = current_cnt;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (can_zero[i]) {
            ans = max(ans, max_cnt[i]);
        }
    }
    cout << ans << 'n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
```
[1819E - Roads in E City](https://codeforces.com/contest/1819/problem/E "Codeforces Round 866 (Div. 1)")

Author: [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

Preparation: [grphil](https://codeforces.com/profile/grphil "Master grphil")

 **Editorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

mt19937 rnd;

struct solve {

vector<pair<int, int>> r;

vector<vector<pair<int, int>>> s;

vector<int> ans;

int n, m;

static constexpr int rep = 45;

int dfs(int a, int p, int b) {
	for (auto i : s[a]) {
		if (i.x == b) {
			return i.y;
		}
		if (i.x == p) {
			continue;
		}

		int x = dfs(i.x, a, b);

		if (x != -1) {
			return x;
		}
	}
	return -1;
}

solve() {
	cin >> n >> m;
	r.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> r[i].x >> r[i].y;
		r[i].x--;
		r[i].y--;
	}

	s.resize(n);
	ans.resize(m, -1);
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		rem(i);
		for (int j = 0; j < rep; j++) {
			if (!ask_end(i)) {
				ans[i] = 1;
				break;
			}
		}
		if (ans[i] == 1) {
			add(i);
			cnt++;
			s[r[i].x].emplace_back(r[i].y, i);
			s[r[i].y].emplace_back(r[i].x, i);
		}
	}

	assert(cnt == n - 1);

	for (int i = 0; i < m; i++) {
		if (ans[i] != -1) continue;
		ans[i] = 1;

		int c = dfs(r[i].x, -1, r[i].y);
		rem(c);
		add(i);
		for (int j = 0; j < rep; j++) {
			if (!ask_end(i)) {
				ans[i] = 0;
				break;
			}
		}
		rem(i);
		add(c);
	}
	cout << "!";
	for (int i = 0; i < m; i++) {
		cout << ' ' << ans[i];
	}
	cout << endl;
	int x;
	cin >> x;
	if (x != 1) {
		exit(1);
	}
}

void rem(int x) {
	cout << "- " << x + 1 << endl;
}

void add(int x) {
	cout << "+ " << x + 1 << endl;
}

bool ask(int a) {
	cout << "? " << a + 1 << endl;
	// cerr << "? " << a + 1 << endl;
	int x;
	cin >> x;
	return x == 1;
}

bool ask_end(int i) {
	// cerr << "ask_end " << i << endl;
	int a = r[i].x;
	if (rnd() % 2) {
		a = r[i].y;
	}
	return ask(a);
}

};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}
```
[1819F - Willy-nilly, Crack, Into Release!](https://codeforces.com/contest/1819/problem/F "Codeforces Round 866 (Div. 1)")

Author: [teraqqq](https://codeforces.com/profile/teraqqq "International Grandmaster teraqqq")

Preparation: [teraqqq](https://codeforces.com/profile/teraqqq "International Grandmaster teraqqq")

 **Editorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ll = long long;

const int Q = 1e5;
const int N = 20;
const int V = N*Q;

const ll LINF = 1e18;

struct MinMaxValue {
    ll min_value;
    ll max_value;

    MinMaxValue operator * (const MinMaxValue& x) const {
        if (x.max_value < 0 || max_value < 0) {
            return MinMaxValue { 0, -1 };
        }

        return MinMaxValue {
            .min_value = x.min_value + min_value,
            .max_value = x.max_value + max_value
        };
    }

    MinMaxValue operator + (const MinMaxValue& x) const {
        if (x.max_value == -1) return *this;
        if (max_value == -1) return x;

        return MinMaxValue {
            .min_value = min(x.min_value, min_value),
            .max_value = max(x.max_value, max_value)
        };
    }

    MinMaxValue& operator += (const MinMaxValue& x) {
        return *this = *this + x;
    }

    void Reset() {
        min_value = 0;
        max_value = -1;
    }
};

struct {
    MinMaxValue dig, ver, hor;
    int cnt;
    int go[4];
} nd[V];
int vc = 0;
MinMaxValue dig[N+1], ver[N+1], hor[N+1];

std::set<ll> words;

int NewVertex(int h) {
    int* go = nd[vc].go;
    go[0] = go[1] = go[2] = go[3] = -1;
    nd[vc].dig = dig[h];
    nd[vc].hor = hor[h];
    nd[vc].ver = ver[h];
    nd[vc].cnt = 0;
    return vc++;
}

tuple<const MinMaxValue&, const MinMaxValue&, const MinMaxValue&, int> GetState(int v, int h) {
    return v == -1 ? make_tuple(cref(dig[h]), cref(ver[h]), cref(hor[h]), 0)
                   : make_tuple(cref(nd[v].dig), cref(nd[v].ver), cref(nd[v].hor), nd[v].cnt);
}

void Calculate(int v, int h, int corner) {
    auto [dig0, ver0, hor0, cnt0] = GetState(nd[v].go[corner^0], h-1);
    auto [dig1, ver1, hor1, cnt1] = GetState(nd[v].go[corner^1], h-1);
    auto [dig2, ver2, hor2, cnt2] = GetState(nd[v].go[corner^2], h-1);
    auto [dig3, ver3, hor3, cnt3] = GetState(nd[v].go[corner^3], h-1);

    nd[v].cnt = cnt0 + cnt1 + cnt2 + cnt3;

    nd[v].dig.Reset();
    if (cnt0 == 0) nd[v].dig += hor2 * dig3 * ver1;
    if (cnt3 == 0) nd[v].dig += ver2 * dig0 * hor1;

    nd[v].hor = ver0 * dig2 * dig3 * ver1;
    if (cnt2 + cnt3 == 0) nd[v].hor += hor0 * hor1;

    nd[v].ver = hor0 * dig1 * dig3 * hor2;
    if (cnt1 + cnt3 == 0) nd[v].ver += ver0 * ver2;
}

void UpdateCount(int v, int h, int corner, ll msk, ll msk_save) {
    if (h == 0) {
        if (nd[v].cnt == 0) {
            words.insert(msk_save);
        } else {
            words.erase(msk_save);
        }
        nd[v].cnt ^= 1;
    } else {
        UpdateCount(nd[v].go[msk & 3], h-1, msk & 3, msk >> 2, msk_save);
        Calculate(v, h, corner);
    }
}

bool near_symbols[256][256];

MinMaxValue GetAnswer(int h) {
    int v = 0;

    if (nd[v].cnt == 0) {
        return MinMaxValue { .min_value = 2, .max_value = 4 * dig[h-1].max_value };
    }

    MinMaxValue res; res.Reset();

    bool cycle_len2 = false;
    if (nd[v].cnt <= 1) cycle_len2 = true;
    if (nd[v].cnt == 2) {
        string s, t;

        for (ll msk =       *words.begin(); s.size() < h; msk >>= 2) s.push_back("abdc"[msk & 3]);
        for (ll msk = *next(words.begin()); t.size() < h; msk >>= 2) t.push_back("abdc"[msk & 3]);
        auto flag = near_symbols[s.back()][t.back()];

        if (s.substr(0, h-1) == t.substr(0, h-1) && flag) {
            cycle_len2 = true;
        }

        int s_suf = 0, t_suf = 0;
        while (s_suf < h && s[h - s_suf - 1] == s.back()) ++s_suf;
        while (t_suf < h && t[h - t_suf - 1] == t.back()) ++t_suf;

        if (s_suf == t_suf && s_suf < h && flag && s.substr(0, h-s_suf-1) == t.substr(0, h-t_suf-1)
                && s.back() == t[h - s_suf - 1]
                && t.back() == s[h - t_suf - 1]) cycle_len2 = true;
    }

    if (cycle_len2) {
        res.min_value = 2;
        res.max_value = 2;
    }

    while (h != 0) {
        const int v0 = nd[v].go[0], v1 = nd[v].go[1], v2 = nd[v].go[2], v3 = nd[v].go[3];
        const auto& dig0 = get<0>(GetState(v0, h-1));
        const auto& dig1 = get<0>(GetState(v1, h-1));
        const auto& dig2 = get<0>(GetState(v2, h-1));
        const auto& dig3 = get<0>(GetState(v3, h-1));

        if(dig0.max_value > 0 && dig1.max_value > 0 && dig2.max_value > 0 && dig3.max_value > 0) {
            res += dig0 * dig1 * dig2 * dig3;
        }

        --h;
        if (v0 != -1 && nd[v0].cnt == nd[v].cnt) { v = v0; continue; }
        if (v1 != -1 && nd[v1].cnt == nd[v].cnt) { v = v1; continue; }
        if (v2 != -1 && nd[v2].cnt == nd[v].cnt) { v = v2; continue; }
        if (v3 != -1 && nd[v3].cnt == nd[v].cnt) { v = v3; continue; }
        break;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<ll> v(q);

    for (int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;
        near_symbols['a' + i]['a' + j] = true;
        near_symbols['a' + j]['a' + i] = true;
    }

    dig[0] = ver[0] = hor[0] = { 1, 1 };
    for (int i = 1; i <= n; ++i) {
        dig[i] = hor[i-1] * dig[i-1] * ver[i-1];
        hor[i] = ver[i] = hor[i-1] * hor[i-1] + ver[i-1] * ver[i-1] * dig[i-1] * dig[i-1];
    }

    int m_root = NewVertex(n); // make_root
    assert(m_root == 0);

    for (int i = 0; i < q; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i] += (s[j] == 'b' || s[j] == 'c' ? 1ll : 0) << (2*j);
            v[i] += (s[j] == 'c' || s[j] == 'd' ? 2ll : 0) << (2*j);
        }

        int w = 0;
        for (int j = 0; j < n; ++j) {
            int& next = nd[w].go[(v[i] >> (2*j)) & 3];
            if (next == -1) next = NewVertex(n-j-1);
            w = next;
        }
    }

    for (ll msk : v) {
        UpdateCount(0, n, 0, msk, msk);
        auto [a, b] = GetAnswer(n);

        if (a > b) {
            cout << -1 << 'n';
        } else {
            cout << a << " " << b << 'n';
        }
    }
}
```
