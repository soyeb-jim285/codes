# Tutorial

[988A - Diverse Team](../problems/A._Diverse_Team.md "Codeforces Round 486 (Div. 3)")

 **Tutorial**
### [988A - Diverse Team](../problems/A._Diverse_Team.md "Codeforces Round 486 (Div. 3)")

Let's write our "unique" function. Keep the array of the taken elements used. Iterate over all elements in the array a and if the current element is not used (used[ai]=false) then add its index i to the answer and set used[ai]:=true. When finished, check the number of distinct values (that is the size of answer array). If it is less than k, print "NO". Otherwise print "YES" and output the first k elements of the answer.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	set<int> el;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (!el.count(x)) {
			ans.push_back(i);
			el.insert(x);
		}
	}
	
	if (int(ans.size()) < k) {
		cout << "NOn";
	} else {
		cout << "YESn";
		for (int i = 0; i < k; ++i)
			cout << ans[i] + 1 << " ";
		cout << endl;
	}
	
	return 0;
}
```
[988B - Substrings Sort](../problems/B._Substrings_Sort.md "Codeforces Round 486 (Div. 3)")

 **Tutorial**
### [988B - Substrings Sort](../problems/B._Substrings_Sort.md "Codeforces Round 486 (Div. 3)")

Firstly, sort all the strings by their lengths (if there are several strings of the same length, their order does not matter because if the answer is "YES" then all the strings of the same length should be equal). Then for each i∈[1..n−1] check that si is a substring of si+1. If it doesn't hold for some i then the answer is "NO". Otherwise the answer is "YES" and the sorted array is the correct order of strings.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i)
		cin >> s[i];
		
	sort(s.begin(), s.end(), [&] (const string &s, const string &t) {
		return s.size() < t.size();
	});
	
	for (int i = 0; i < n - 1; ++i) {
		if (s[i + 1].find(s[i]) == string::npos) {
			cout << "NOn";
			return 0;
		}
	}
	
	cout << "YESn";
	for (auto it : s)
		cout << it << endl;
	
	return 0;
}
```
[988C - Equal Sums](../problems/C._Equal_Sums.md "Codeforces Round 486 (Div. 3)")

 **Tutorial**
### [988C - Equal Sums](../problems/C._Equal_Sums.md "Codeforces Round 486 (Div. 3)")

Let's calculate the array of triples t. Triple ti=(sumi,seqi,eli) means that the sum of the sequence seqi without the element at position eli will be equal to sumi. Triples can be easily calculated in a following manner: for each sequence find its sum, then iterate over all its elements and subtract each of them one after another. Now sort array t with the standard compare function. Finally the answer is "YES" if and only if there exist two adjacent elements with equal sums and different sequences (it is very easy to see). So if we find such a pair, then the answer will be "YES", otherwise the answer will be "NO".

Time complexity of the solution is O(k−1∑i=0ni⋅logk−1∑i=0ni).

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int k;
	cin >> k;
	vector<pair<int, pair<int, int>>> a;
	for (int i = 0; i < k; ++i) {
		int n;
		cin >> n;
		vector<int> x(n);
		for (int j = 0; j < n; ++j)
			cin >> x[j];
		int sum = accumulate(x.begin(), x.end(), 0);
		for (int j = 0; j < n; ++j)
			a.push_back(make_pair(sum - x[j], make_pair(i, j)));
	}
	
	stable_sort(a.begin(), a.end());
	for (int i = 0; i < int(a.size()) - 1; ++i) {
		if (a[i].first == a[i + 1].first && (a[i].second.first != a[i + 1].second.first)) {
			cout << "YES" << endl;
			cout << a[i + 1].second.first + 1 << " " << a[i + 1].second.second + 1 << endl;
			cout << a[i].second.first + 1 << " " << a[i].second.second + 1 << endl;
			return 0;
		}
	}
	
	cout << "NOn";
	
	return 0;
}
```
[988D - Points and Powers of Two](../problems/D._Points_and_Powers_of_Two.md "Codeforces Round 486 (Div. 3)")

 **Tutorial**
### [988D - Points and Powers of Two](../problems/D._Points_and_Powers_of_Two.md "Codeforces Round 486 (Div. 3)")

Firstly, let's prove that the size of the answer is not greater than 3. Suppose that the answer equals to 4. Let a,b,c,d be coordinates of the points in the answer (and a<b<c<d). Let dist(a,b)=2k and dist(b,c)=2l. Then dist(a,c)=dist(a,b)+dist(b,c)=2k+2l=2m (because of the condition). It means that k=l. Conditions must hold for a triple b,c,d too. Now it is easy to see that if dist(a,b)=dist(b,c)=dist(c,d)=2k then dist(a,d)=dist(a,b)∗3 that is not a power of two. So the size of the answer is not greater than 3.

Firstly, let's check if the answer is 3. Iterate over all middle elements of the answer and over all powers of two from 0 to 30 inclusively. Let xi be the middle element of the answer and j — the current power of two. Then if there are elements xi−2j and xi+2j in the array then the answer is 3. 

Now check if the answer is 2. Do the same as in the previous solution, but now we have left point xi and right point xi+2j.

If we did not find answer of lengths 3 or 2 then print any element of the array.

The solution above have time complexity O(n⋅logn⋅log109) (because of we can check if the element is in the array with some data structure in O(logn)).

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	
	sort(x.begin(), x.end());
	vector<int> res = { x[0] };
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 31; ++j) {
			int lx = x[i] - (1 << j);
			int rx = x[i] + (1 << j);
			bool isl = binary_search(x.begin(), x.end(), lx);
			bool isr = binary_search(x.begin(), x.end(), rx);
			if (isl && isr && int(res.size()) < 3) {
				res = { lx, x[i], rx };
			}
			if (isl && int(res.size()) < 2) {
				res = { lx, x[i] };
			}
			if (isr && int(res.size()) < 2) {
				res = { x[i], rx };
			}
		}
	}
	
	cout << int(res.size()) << endl;
	for (auto it : res)
		cout << it << " ";
	cout << endl;
	
	return 0;
}
```
[988E - Divisibility by 25](../problems/E._Divisibility_by_25.md "Codeforces Round 486 (Div. 3)")

 **Tutorial**
### [988E - Divisibility by 25](../problems/E._Divisibility_by_25.md "Codeforces Round 486 (Div. 3)")

Let's iterate over all pairs of digits in the number. Let the first digit in the pair be at position i and the second at position j. Let's place these digits to the last two positions in the number. The first greedily goes to the last position and then the second goes to the position next to that. Now the number can contain a leading zero. Find the leftmost non-zero digit and move it to the first position. Then if the current number is divisible by 25 try to update the answer with the number of swaps. It is easy to show that the number of swaps is minimal in this algorithm. The only difference we can introduce is the number of times digit i, digit j and the leftmost non-zero digit swap among themselves. And that is minimized. You can also notice that the order of swaps doesn't matter and you can rearrange them in such a way that no leading zero appears on any step.

This solution has time complexity O(log3n). You can also solve this problem with O(logn) complexity because you have to check only four options of the two last digits (25, 50, 75, 00). It is always optimal to choose both rightmost occurrences of the corresponding digits. You can show that even if you are required to swap the chosen ones, there will be no other pair with smaller total amount of moves.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	long long n;
	cin >> n;
	
	string s = to_string(n);
	
	int ans = INF;
	
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (i == j) continue;
			string t = s;
			int cur = 0;
			for (int k = i; k < len - 1; ++k) {
				swap(t[k], t[k + 1]);
				++cur;
			}
			
			for (int k = j - (j > i); k < len - 2; ++k) {
				swap(t[k], t[k + 1]);
				++cur;
			}
			
			int pos = -1;
			for (int k = 0; k < len; ++k) {
				if (t[k] != '0') {
					pos = k;
					break;
				}
			}
			
			for (int k = pos; k > 0; --k) {
				swap(t[k], t[k - 1]);
				++cur;
			}
			
			long long nn = atoll(t.c_str());
			if (nn % 25 == 0)
				ans = min(ans, cur);
		}
	}
	
	if (ans == INF)
		ans = -1;
		
	cout << ans << endl;
	
	return 0;
}
```
[988F - Rain and Umbrellas](../problems/F._Rain_and_Umbrellas.md "Codeforces Round 486 (Div. 3)")

 **Tutorial**
### [988F - Rain and Umbrellas](../problems/F._Rain_and_Umbrellas.md "Codeforces Round 486 (Div. 3)")

Any experienced contestant can easily guess that the problem can be solved with dynamic programming. Coordinates are not really large so you can precalculate the array rain0,rain1,…,raina−1, where raini is a boolean value — True if there exists some segment of rain to cover the segment between positions i and i+1 and False otherwise. This can be done in O(n⋅a) with the most straightforward algorithm. You can also precalculate another array umb0,umb1,…,umba, where umbi is the index of the umbrella of minimal weight at position i or −1 if there is no such umbrella.

Now let dp[i][j] be the minimal total fatigue you can take if you are holding umbrella number j on the end of the walk up to position i. If j=0 then you hold no umbrella. Initially all the values are ∞ and dp[0][0] is 0. You can either hold your umbrella, drop it or pick up the best one lying there (and drop the current one if any) when going from some position i to i+1. So here are the transitions for these cases:

* dp[i+1][j]=min(dp[i+1][j],dp[i][j]+weightj) if j>0;
* dp[i+1][0]=min(dp[i+1][0],dp[i][j]) if rain[i]=False;
* dp[i+1][umbi]=min(dp[i+1][umbi],dp[i][j]+weight[umbi]) if umbi≠−1.

The answer is equal to min. If it is \infty then there is no answer.

So you have a \cdot m states and all the transitions are O(1).

Overall complexity: O(a \cdot (n + m)).

There is also a solution in O(a \log^2 a) with Convex Hull Trick using Li Chao tree. You can probably even achieve (n + m) \log^2 (n + m) with some coordinate compression. Obviously this wasn't required for the problem as the constraints are small enough.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int a, n, m;
	cin >> a >> n >> m;
	vector<int> rain(a + 1);
	vector<pair<int, int>> umb(a + 1, make_pair(INF, -1));
	vector<int> costs(m);
	
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		for (int j = l; j < r; ++j)
			rain[j] = 1;
	}
	
	for (int i = 0; i < m; ++i) {
		int x, p;
		cin >> x >> p;
		costs[i] = p;
		umb[x] = min(umb[x], make_pair(p, i));
	}
	
	vector<vector<int>> dp(a + 1, vector<int>(m + 1, INF));
	dp[0][m] = 0;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (dp[i][j] == INF)
				continue;
			if (rain[i] == 0)
				dp[i + 1][m] = min(dp[i + 1][m], dp[i][j]);
			if (j < m)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + costs[j]);
			if (umb[i].first != INF)
				dp[i + 1][umb[i].second] = min(dp[i + 1][umb[i].second], dp[i][j] + umb[i].first);
		}
	}
	
	int ans = INF;
	for (int i = 0; i <= m; ++i)
		ans = min(ans, dp[a][i]);
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
	
	return 0;
}
```
 **Solution (step_by_step)**
```cpp
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
 
#include <stdio.h>
#include <bits/stdc++.h>
 
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
 
using namespace std;
 
inline void setmin(int &x, int y) { if (y < x) x = y; }
inline void setmax(int &x, int y) { if (y > x) x = y; }
inline void setmin(ll &x, ll y) { if (y < x) x = y; }
inline void setmax(ll &x, ll y) { if (y > x) x = y; }
 
const int N = 2001;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

struct Line
{
    ll k, b;
    Line() {}
    Line(ll k, ll b) : k(k), b(b) {}
    ll val(ll x) { return k * x + b; }
};

int cnt_v;
Line tree[N * 4];

void build(int n)
{
    cnt_v = 1;
    while (cnt_v < n)
        cnt_v <<= 1;
    rep(i, 0, cnt_v * 2 - 1)
        tree[i] = Line(0, inf);
}

void upd(int x, int lx, int rx, int l, int r, Line line)
{
    if (lx >= r || l >= rx)
        return;
    else if (lx >= l && rx <= r)
    {
        int m = (lx + rx) / 2;
        if (line.val(m) < tree[x].val(m))
            swap(tree[x], line);
        if (rx - lx == 1)
            return;
        if (line.val(lx) < tree[x].val(lx))
            upd(x * 2 + 1, lx, (lx + rx) / 2, l, r, line);
        else
            upd(x * 2 + 2, (lx + rx) / 2, rx, l, r, line);
    }
    else
    {
        upd(x * 2 + 1, lx, (lx + rx) / 2, l, r, line);
        upd(x * 2 + 2, (lx + rx) / 2, rx, l, r, line);
    }
}

ll get(ll p)
{
    int x = p + cnt_v - 1;
    ll res = tree[x].val(p);
    while (x > 0)
    {
        x = (x - 1) / 2;
        setmin(res, tree[x].val(p));
    }
    return res;
}

int add[N];
int best[N];

ll dp[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    int L, n, m;
    cin >> L >> n >> m;

    rep(i, 0, n)
    {
        int l, r;
        cin >> l >> r;
        add[l]++;
        add[r]--;
    }
    rep(i, 1, L + 1)
        add[i] += add[i - 1];

    fill(best, best + L + 1, inf);
    rep(i, 0, m)
    {
        int x, p;
        cin >> x >> p;
        setmin(best[x], p);
    }

    // dp[i] + best[i] * (j - i) = best[i] * j + (dp[i] - best[i] * i)
    build(L + 1);
    fill(dp, dp + L + 1, inf);
    dp[0] = 0;
    upd(0, 0, cnt_v, 0 + 1, cnt_v, Line(best[0], dp[0] - best[0] * 0));
    rep(i, 1, L + 1)
    {
        dp[i] = get(i);
        if (add[i - 1] == 0)
            setmin(dp[i], dp[i - 1]);
        upd(0, 0, cnt_v, i + 1, cnt_v, Line(best[i], dp[i] - best[i] * i));
    }
    cout << (dp[L] != inf ? dp[L] : -1) << "n";
    return 0;
}
```
