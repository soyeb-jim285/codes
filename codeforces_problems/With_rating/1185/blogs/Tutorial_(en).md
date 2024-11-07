# Tutorial_(en)

Tutorial is loading...Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov") and [geranazavr555](https://codeforces.com/profile/geranazavr555 "Эксперт geranazavr555")

 **Authors' solution**
```cpp
def solve(a, b, c, d):
    return max(0, d - (b - a)) + max(0, d - (c - b))

def main():
    a, b, c, d = map(int, input().split())
    a, b, c = sorted((a, b, c))
    print(solve(a, b, c, d))

main()
```
 Tutorial is loading...Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov")

 **Authors' solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

vector<pair<char,int>> split(string s) {
    char c = s[0];
    int cnt = 1;
    vector<pair<char,int>> result;
    auto ss = s.c_str();
    for (int i = 1; i <= int(s.length()); i++) {
        if (ss[i] != c) {
            result.push_back({c, cnt});
            c = s[i];
            cnt = 1;
        } else
            cnt++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    forn(tt, n) {
        string s, t;
        cin >> s >> t;
        auto sa(split(s)), ta(split(t));
        bool ok = sa.size() == ta.size();
        if (ok)
            forn(i, sa.size())
                if (sa[i].first != ta[i].first || sa[i].second > ta[i].second)
                    ok = false;
        cout << (ok ? "YES" : "NO") << endl;
    }
}
```
 Tutorial is loading...Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov"), [cannor147](https://codeforces.com/profile/cannor147 "Специалист cannor147") and [geranazavr555](https://codeforces.com/profile/geranazavr555 "Эксперт geranazavr555")

 **Authors' solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int T = 100;

int main() {
	int n, m;
	cin >> n >> m;
	
	int sum = 0;
	vector<int> t(n), count(T + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	
	for (int i = 0; i < n; i++) {
		int d = sum + t[i] - m, k = 0;
		if (d > 0) {
		    for (int j = T; j > 0; j--) {
				int x = j * count[j];
				if (d <= x) {
					k += (d + j - 1) / j;
					break;
				}
				k += count[j];
				d -= x;
			}
		}
		sum += t[i];
		count[t[i]]++;
		cout << k << " ";
	}
}
```
 Tutorial is loading...Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov"), [cannor147](https://codeforces.com/profile/cannor147 "Специалист cannor147") and [geranazavr555](https://codeforces.com/profile/geranazavr555 "Эксперт geranazavr555")

 **Authors' solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int T = 100;

int main() {
	int n, m;
	cin >> n >> m;
	
	int sum = 0;
	vector<int> t(n), count(T + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	
	for (int i = 0; i < n; i++) {
		int d = sum + t[i] - m, k = 0;
		if (d > 0) {
		    for (int j = T; j > 0; j--) {
				int x = j * count[j];
				if (d <= x) {
					k += (d + j - 1) / j;
					break;
				}
				k += count[j];
				d -= x;
			}
		}
		sum += t[i];
		count[t[i]]++;
		cout << k << " ";
	}
}
```
 Tutorial is loading...Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov")

 **Authors' solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> b(n);
	for (int i = 0; i < n; i++) {
	    int x;
	    cin >> x;
	    b[i] = {x, i};
	}
	sort(b.begin(), b.end());
	
	vector<int> d(n - 1);
	for (int i = 1; i < n; i++) {
		d[i - 1] = b[i].first - b[i - 1].first;
	}
	
	bool f = true;
	for (int i = 2; i < n - 1; i++) {
		f &= d[i] == d[1];
	}
	if (f) {
		cout << b[0].second + 1;
		return 0;
	}
	
	f = true;
	for (int i = 2; i < n - 1; i++) {
		f &= d[i] == b[2].first - b[0].first;
	}
	if (f) {
		cout << b[1].second + 1;
		return 0;
	}
	
	int answer;
	f = false;
	for (int i = 1; i < n - 1; i++) {
		if (d[i] == d[0]) continue;
		if (f) {
			cout << -1;
			return 0;
		} else {
			if (i == n - 2) {
				cout << b[n - 1].second + 1;
				return 0;
			} else {
				if (b[i + 2].first - b[i].first == d[0]) {
					answer = b[i + 1].second;
					f = true;
					i++;
				} else {
					cout << -1;
					return 0;
				}
			}
		}
	}
	
	if (f) {
        cout << answer + 1;
	} else {
	    cout << b[n - 1].second + 1;
	}
}
```
 Tutorial is loading...Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov"), [cannor147](https://codeforces.com/profile/cannor147 "Специалист cannor147") and [geranazavr555](https://codeforces.com/profile/geranazavr555 "Эксперт geranazavr555")

 **Authors' solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
	
int min(int a, int b) {
	return (a < b) ? a : b;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int t;
	cin >> t;
	
	vector<string> lines(2000, "");
	vector<int> vertical_min(26, 2001), vertical_max(26, -1);
	vector<int> horizontal_min(26, 2001), horizontal_max(26, -1);
		
	for (int k = 0; k < t; k++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> lines[i];
		}
		
		for (int b = 0; b < 26; b++) {
			vertical_min[b] = 2001;
			horizontal_min[b] = 2001;
			vertical_max[b] = -1;
			horizontal_max[b] = -1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (lines[i][j] != '.') {
					int b = (int) (lines[i][j] - 'a');
					vertical_min[b] = min(vertical_min[b], i);
					vertical_max[b] = max(vertical_max[b], i);
					horizontal_min[b] = min(horizontal_min[b], j);
					horizontal_max[b] = max(horizontal_max[b], j);
				}
			}
		}
		
		bool f = true, q = false;
		int count = 26;
		for (int b = 25; b >= 0; b--) {
			if (vertical_max[b] == -1) {
				if (!q) {
					count--;
					continue;
				} else {
					vertical_min[b] = vertical_min[b + 1];
					vertical_max[b] = vertical_max[b + 1];
					horizontal_min[b] = horizontal_min[b + 1];
					horizontal_max[b] = horizontal_max[b + 1];
					continue;
				}
			}
			
			q = true;
			if (vertical_max[b] == vertical_min[b]) {
				for (int j = horizontal_min[b]; j <= horizontal_max[b]; j++) {
					if (lines[vertical_max[b]][j] == 'a' + b || (q && lines[vertical_max[b]][j] == '*')) {
						lines[vertical_max[b]][j] = '*';
					} else {
						f = false;
						break;
					}
				}
			} else if (horizontal_max[b] == horizontal_min[b]) {
				for (int i = vertical_min[b]; i <= vertical_max[b]; i++) {
					if (lines[i][horizontal_max[b]] == 'a' + b || (q && lines[i][horizontal_max[b]] == '*')) {
						lines[i][horizontal_max[b]] = '*';
					} else {
						f = false;
						break;
					}
				}
			} else {
				f = false;
			}
			if (!f) {
				break;
			}
		}
		
		if (f) {
			cout << "YES" << endl;
			cout << count << endl;
			for (int i = 0; i < count; i++) {
				cout << vertical_min[i] + 1 << " " << horizontal_min[i] + 1 << " " << vertical_max[i] + 1 << " " << horizontal_max[i] + 1 << endl;
			}
		} else {
			cout << "NO" << endl;
		}
	}
}
```
 Tutorial is loading...Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov"), [cannor147](https://codeforces.com/profile/cannor147 "Специалист cannor147") and [geranazavr555](https://codeforces.com/profile/geranazavr555 "Эксперт geranazavr555")

 **Authors' solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)

template<class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out <<  "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream& out, const vector<A> &a) {
	out << "[";
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it != a.begin())
			out << ", ";
		out << *it;
	}
	return out << "]";
}

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = 1e9;
const li INF64 = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9;

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

const int N = 100 * 1000 + 11;
const int MSK = 1 << 9;

int n, m;
int cnt[MSK];
vector<pt> pz[N];

bool read() {
	if (scanf("%d %d", &n, &m) != 2)
		return false;
	forn(i, n) {
		int k;
		scanf("%d", &k);
		int msk = 0;
		forn(j, k) {
			int pos;
			scanf("%d", &pos);
			--pos;
			msk |= (1 << pos);
		}
		++cnt[msk];
	}
	return true;
}

void solve() {
	forn(i, m) {
		int c;
		scanf("%d", &c);
		int msk = 0;
		int k;
		scanf("%d", &k);
		forn(j, k) {
			int pos;
			scanf("%d", &pos);
			--pos;
			msk |= (1 << pos);
		}
		pz[msk].pb(mp(c, i));
		sort(all(pz[msk]));
		while (sz(pz[msk]) > 2) pz[msk].pop_back();
	}
	int ans = 0, cost = 2 * INF + 1;
	pt res = mp(-1, -1);
	forn(p1, MSK) forn(p2, MSK) {
		int curcost = 0;
		int pos1, pos2;
		if (p1 == p2) {
			if (sz(pz[p1]) < 2) continue;
			curcost = pz[p1][0].x + pz[p1][1].x;
			pos1 = pz[p1][0].y;
			pos2 = pz[p1][1].y;
		} else {
			if (sz(pz[p1]) == 0 || sz(pz[p2]) == 0) continue;
			curcost = pz[p1][0].x + pz[p2][0].x;
			pos1 = pz[p1][0].y;
			pos2 = pz[p2][0].y;
		}
		int curans = 0;
		int curmask = p1 | p2;
		forn(pp, MSK) {
			if ((curmask & pp) == pp) {
				curans += cnt[pp];
			}
		}
		if (curans > ans || (curans == ans && curcost < cost)) {
			ans = curans;
			cost = curcost;
			res = mp(pos1, pos2);
		}
	}
	cout << res.x + 1 << " " << res.y + 1 << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int tt = clock();
#endif

	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(10);

#ifdef _DEBUG
	while (read()) {
#else
	if (read()) {
#endif
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();	
#endif
	}
}
```
 Tutorial is loading...Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov"), [cannor147](https://codeforces.com/profile/cannor147 "Специалист cannor147") and [geranazavr555](https://codeforces.com/profile/geranazavr555 "Эксперт geranazavr555")

 **Authors' solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int M = 1000000007;
const int N = 16;

int d[1 << N][4];

int main() {
    int n, T;
    cin >> n >> T;
    vector<int> durs(n), types(n);
    forn(i, n) {
        cin >> durs[i] >> types[i];
        types[i]--;
    }

    int result = 0;
    d[0][3] = 1;
    forn(mask, 1 << n)
        forn(lst, 4) {
            forn(j, n)
                if (types[j] != lst && ((mask & (1 << j)) == 0))
                    d[mask ^ (1 << j)][types[j]] = (d[mask ^ (1 << j)][types[j]] + d[mask][lst]) % M;
            int sum = 0;
            forn(i, n)
                if (mask & (1 << i))
                    sum += durs[i];
            if (sum == T)
                result = (result + d[mask][lst]) % M;
        }

    cout << result << endl;
}
```
 Tutorial is loading...Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov"), [cannor147](https://codeforces.com/profile/cannor147 "Специалист cannor147") and [geranazavr555](https://codeforces.com/profile/geranazavr555 "Эксперт geranazavr555")

 **Authors' solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int M = 1000000007;
const int N = 51;
const int S = 2501;

void inc(int& a, int d) {
    a += d;
    if (a >= M)
        a -= M;
}

int a[N][S];
int bc[N][N][S];
int ways[N][N][N][4];

int main() {
    int n, T;
    cin >> n >> T;

    vector<int> cnts(4);
    vector<int> durs(4);

    a[0][0] = bc[0][0][0] = 1;
    forn(i, n) {
        int dur, type;
        cin >> dur >> type;
        type--;
        if (type == 0) {
            for (int cnts0 = cnts[0]; cnts0 >= 0; cnts0--)
                forn(durs0, durs[0] + 1)
                    inc(a[cnts0 + 1][durs0 + dur], a[cnts0][durs0]);
        } else {
            for (int cnts1 = cnts[1]; cnts1 >= 0; cnts1--)
                for (int cnts2 = cnts[2]; cnts2 >= 0; cnts2--)
                    forn(durs12, durs[1] + durs[2] + 1)
                        inc(bc[cnts1 + (type == 1)][cnts2 + (type == 2)][durs12 + dur],
                            bc[cnts1][cnts2][durs12]);
        }
        cnts[type]++;
        durs[type] += dur;
    }

    ways[0][0][0][3] = 1;
    vector<int> c(3);
    for (c[0] = 0; c[0] <= cnts[0]; c[0]++)
        for (c[1] = 0; c[1] <= cnts[1]; c[1]++)
            for (c[2] = 0; c[2] <= cnts[2]; c[2]++)
                forn(lst, 4)
                    if (ways[c[0]][c[1]][c[2]][lst] != 0) {
                        forn(nxt, 3)
                            if (nxt != lst && c[nxt] + 1 <= cnts[nxt]) {
                                vector<int> cn(c);
                                cn[nxt]++;
                                inc(ways[cn[0]][cn[1]][cn[2]][nxt], ways[c[0]][c[1]][c[2]][lst]);
                            }
                    }

    vector<int> f(N + 1, 1);
    forn(i, N)
        f[i + 1] = ((long long) f[i]) * (i + 1) % M;

    int result = 0;
    for (c[0] = 0; c[0] <= cnts[0]; c[0]++)
        forn(durs0, durs[0] + 1)
            if (T - durs0 >= 0)
                for (c[1] = 0; c[1] <= cnts[1]; c[1]++)
                    for (c[2] = 0; c[2] <= cnts[2]; c[2]++) {
                        long long extra = (long long)(a[c[0]][durs0]) * bc[c[1]][c[2]][T - durs0] % M;
                        forn(i, 3)
                            extra = extra * f[c[i]] % M;
                        forn(lst, 3)
                            if (c[lst] > 0)
                                inc(result, extra * ways[c[0]][c[1]][c[2]][lst] % M);
                    }
    
    cout << result << endl;
}
```
