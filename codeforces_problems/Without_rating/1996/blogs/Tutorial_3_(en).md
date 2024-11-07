# Tutorial_3_(en)

[1996A - Legs](../problems/A._Legs.md "Codeforces Round 962 (Div. 3)")

Problem Credits: [cry](https://codeforces.com/profile/cry "International Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "International Master cry")

 **Solution** If n is a multiple of 4, then you can have n4 cows. Otherwise, you must have at least one chicken, so you can have n−24 cows and 1 chicken. 

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--){
        int n;
        cin >> n;

        cout << (n + 2) / 4 << "n";
    }
}
```
[1996B - Scale](../problems/B._Scale.md "Codeforces Round 962 (Div. 3)")

Problem Credits: [sum](https://codeforces.com/profile/sum "Master sum")   
 Analysis: [cry](https://codeforces.com/profile/cry "International Master cry")

 **Solution** Let's define every k by k block of cells by its value in the top left corner, since all cells in the block must have the same value. So, we can just print out the value of the cell in every k'th row and every k'th column.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--){
        int n, k;
        cin >> n >> k;

        char A[n][n];
        
        for (auto &row : A)
            for (char &c : row)
                cin >> c;
        
        for (int i = 0; i < n; i += k){
            for (int j = 0; j < n; j += k){
                cout << A[i][j];
            }
            cout << "n";
        }
    }
}
```
[1996C - Sort](../problems/C._Sort.md "Codeforces Round 962 (Div. 3)")

Problem Credits: [cry](https://codeforces.com/profile/cry "International Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "International Master cry")

 **Solution** For two strings to be the same after sorting, they must have the same occurrences of every possible lowercase letter. To answer the query for a range [l,r], we must ensure that after the operations, cntc=cnt2c must where cntc is the number of times character c occurs in the range for a and cnt2c is defined similarly for b. Both cntc and cnt2c can be obtained by doing prefix sums for character c specifically. Note that since there are only 26 possible c, you can afford to create 26 length n prefix sum arrays.

In one operation, you can replace one occurrence of a character c with another character c2. Essentially, you are subtracting one from cntc and adding one to cntc2. Obviously, you must choose c and c2 such that cntc>cnt2c and cntc2<cnt2c2. So, we only have to focus on c or c2 since one decreasing will automatically lead to the other increase. The answer is just the sum of cntc−cnt2c if cntc>cnt2c over all possible lowercase characters c.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pre1(n + 1, vector<int>(26, 0));
    vector<vector<int>> pre2(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre1[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre1[i][j] += pre1[i - 1][j];
    }
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre2[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre2[i][j] += pre2[i - 1][j];
    }
    while (q--){
        int l, r;
        cin >> l >> r;

        int dif = 0;

        for (int c = 0; c < 26; c++){
            int v1 = pre1[r][c] - pre1[l - 1][c];
            int v2 = pre2[r][c] - pre2[l - 1][c];

            dif += abs(v1 - v2);
        }
        cout << dif / 2 << "n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
[1996D - Fun](../problems/D._Fun.md "Codeforces Round 962 (Div. 3)")

Problem Credits: [sum](https://codeforces.com/profile/sum "Master sum")   
 Analysis: [cry](https://codeforces.com/profile/cry "International Master cry")

 **Solution** There are several solutions to this problem, The easiest way is to just fix either a, b or c. Let's fix a. Since ab+ac+bc≤n, we know at the minimum, ab≤n. Divide on both sides to get b≤na. When a=1, there are n choices for b. When a=2, there are n2 choices for b. So in total, there are n+n2+n3+...+nn total choices for b. This is just the harmonic series, so over all possible a, there are about nlogn choices for b. Therefore, we can afford to loop through both a and b.

Now that we have a and b, all that's left is to solve for c. Let's solve for c in both equations. In the first equation, we can factor c out to obtain ab+c(a+b)≤n. So, c≤n−aba+b. In the second equation, c≤x−a−b. Since we want the c to satisfy both inequalities, we must choose the stricter one. So, the number of possible c is min(n−aba+b,x−a−b).

The answer is the sum of number of possible c over all possible a and b.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;

    while (tc--){
        int n, x;
        cin >> n >> x;

        long long ans = 0;
        
        for (int a = 1; a <= min(n, x); a++){
            for (int b = 1; a * b <= n and a + b <= x; b++){
                int highestC = min((n - a * b) / (a + b), x - (a + b));
                ans += highestC;
            }
        }
        cout << ans << "n";
    }
}
```
[1996E - Decode](../problems/E._Decode.md "Codeforces Round 962 (Div. 3)")

Problem Credits: [cry](https://codeforces.com/profile/cry "International Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "International Master cry")

 **Solution** How can we efficiently check if a range contains the same amount of zeroes and ones? Let's create an array a where ai=−1 if si=0 and ai=1 if si=1. Let's denote p as the prefix sum array of a. We want the contribution of −1 by the zeroes to cancel out with the ones, so if pr−pl−1=0, then the range [l,r] contain equal amounts of zeroes and ones. We can rephrase the problem as the following: for each subrange [l,r], count the number of pairs (x,y) such that px−1=py.

Let's fix px−1 and keep track of all potential y such that y>x and px−1=py. How many subarrays will cover [x,y]? Well, we have x+1 options as l and n−y+1 options as r, so the range [x,y] contributes to (x+1)⋅(n−y+1) subarrays. We just need to calculate this expression for all potential y now. Let's denote the all possible y as y1,y2,...yk. We are asked to find the sum of (x+1)⋅(n−y1+1)+(x+1)⋅(n−y2+1)+⋯+(x+1)⋅(n−yk+1). Let's factor (x+1) out, and we have (x+1)⋅((n−y1+1)+(n−y2+1)+⋯+(n−yk+1)). Since, the second part of the expression is just the sum of all (n−yi+1), we can first precalculate that sum and since y>x, subtract as we sweep from left to right. 

 **Code 1 (C++)**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
 
template<ll M>
struct modint {
 
    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }
 
    ll v; modint(ll n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }
 
    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }
 
    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }
 
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};
 
using mint = modint<int(MOD)>;
 
 
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.size();
		vector<int> p(n+1);
		for(int i = 1; i <= n; i++){
			p[i] = p[i-1] + (s[i-1] == '0' ? -1 : 1);
		}
		vector<vector<ll>> sums(2 * n + 1);
		for(int i = 0; i <= n; i++){
			sums[p[i] + n].push_back(i);
		}
		mint ans = 0;
		for(auto& v: sums){
			int N = v.size();
			vector<ll> j_sum(N+1);
			for(int i = N - 1; i >= 0; i--){
				j_sum[i] = j_sum[i+1] + v[i];
			}
			for(int i = 0; i < N - 1; i++){
				ll left = N - i - 1;
				ans += v[i] * n * left;
				ans -= v[i] * j_sum[i+1];
				ans += v[i] * left;
				ans += n * left;
				ans -= j_sum[i+1];
				ans += left;
			}
		}
		cout << ans << "n";
	}
}
```
 **Code 2 (A Little Different) (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std; 

#define ll long long

const int MOD = 1e9 + 7;

void solve(){
    string S;
    cin >> S;

    int n = S.size();
    S = " " + S;

    vector<int> P(n + 1, 0);

    for (int i = 1; i <= n; i++){
        P[i] = (S[i] == '1' ? 1 : -1) + P[i - 1];
    }

    map<int, ll> cnt;
    ll ans = 0;

    for (int i = 0; i <= n; i++){
        ans = (ans + (n - i + 1) * cnt[P[i]]) % MOD;
        cnt[P[i]] = (cnt[P[i]] + (i + 1)) % MOD;
    }
    cout << ans << "n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
[1996F - Bomb](../problems/F._Bomb.md "Codeforces Round 962 (Div. 3)")

Problem Credits: [sum](https://codeforces.com/profile/sum "Master sum")   
 Analysis: [cry](https://codeforces.com/profile/cry "International Master cry")

 **Solution** Let's first solve the problem in O(k). One possible solution is to loop through each operation and take the largest ai each time, and set ai=max(0,ai−bi). This can be done with a set or a priority queue.

With that in mind, let's binary search for the largest x such that every value we add to our score has been greater or equal to x for all k operations. Define f(x) as the number of operations required for every ai to be less than x. Specifically, f(x)=∑ni=1⌈ai−xbi⌉. We are searching for the smallest x such that f(x)≤k. Once we've found x, we can subtract f(x) from k. Note that now, k must be less than to n (otherwise we can another operation on all ai). So, it suffices to run the slow solution for these remaining operations (as long as ai>0). Alternatively, we can notice that the remaining operations will all add x−1 to our answer (assuming x>0).

To obtain the sum of all ai we collected when calculating f(x), we can use the arithmetic sequence sum formula. For each i, the number of terms in the sequence is t=⌈ai−xbi⌉. The first term of the sequence is f=ai−bi⋅(t−1). The last term is ai. Using the formula, we can add t2(f+ai) to the answer.

 **Code 1 (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int ok = 0, ng = 1e9+1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;

            long long sum = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] >= mid)
                    sum += (a[i] - mid) / b[i] + 1;
            }

            if (sum >= k) ok = mid;
            else ng = mid;
        }

        long long ans = 0;
        int s = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] >= ok) {
                int m = (a[i] - ok) / b[i] + 1;
                ans += 1LL * m * a[i] - 1LL * m * (m - 1) / 2 * b[i];
                s += m;
            }
        }

        ans -= 1LL * ok * (s - k);

        cout << ans << "n";
    }

    return 0;
}
```
 **Code 2 (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std; 

#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);
    
    for (int &i : A)
        cin >> i;
    for (int &i : B)
        cin >> i;

    auto getInfo = [&](int cutoff){
        ll ops = 0;
        ll sum = 0;

        for (int i = 0; i < n; i++){
            ll a = A[i];
            ll b = B[i];

            if (cutoff > a)
                continue;

            // a - uses * b >= cutoff
            ll uses = (a - cutoff) / b;
            sum += (uses + 1) * a - b * uses * (uses + 1) / 2; 
            ops += uses + 1;

            sum = min(sum, 2 * (ll)1e18);
        }
        return make_pair(sum, ops);
    };

    int L = 0, H = 1e9 + 5;

    while (L < H){
        int M = (L + H) / 2;
        getInfo(M).second <= k ? H = M : L = M + 1;
    }

    auto [ans, opsUse] = getInfo(L);
    cout << ans + (k - opsUse) * max(L - 1, 0) << "n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
[1996G - Penacony](../problems/G._Penacony.md "Codeforces Round 962 (Div. 3)")

Problem Credits: [cry](https://codeforces.com/profile/cry "International Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "International Master cry"), [awesomeguy856](https://codeforces.com/profile/awesomeguy856 "Master awesomeguy856")

 **Solution - Segment Tree**There are two configurations to satisfy every friendship (a,b): activate all the roads from a→a+1→⋯→b or b←⋯←n←1←⋯←a. Let's fix a road we deactivate. Say it goes from i→i+1. Observe that the configuration for all friendships is fixed to one of the two cases. For example, if a≤i<b, then we must use the second configuration. 

We can try fixing every road and taking the minimum of number of roads. This can be done with sweep line. Once we reach i=a for any friendship, we toggle to the second configuration. Once we reach b, we toggle back to the first. We can track maintained roads by performing a range addition on a lazy propagated segment tree for each point covered by the current configuration. The number of roads required is n minus the number of occurrences of zeroes in the segment tree, which can be tracked with [Counting Minimums in a Segment Tree](https://codeforces.com/https://usaco.guide/adv/count-min).

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
    struct Node {
        int min_val;
        int count;
        int lazy;
    };

    std::vector<Node> tree;
    int n;

    void buildTree(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = {0, 1, 0};
        } else {
            int tm = (tl + tr) / 2;
            buildTree(v*2, tl, tm);
            buildTree(v*2+1, tm+1, tr);
            merge(v);
        }
    }

    void apply(int v, int tl, int tr, int val) {
        tree[v].min_val += val;
        tree[v].lazy += val;
    }

    void push(int v, int tl, int tr) {
        if (tree[v].lazy != 0) {
            int tm = (tl + tr) / 2;
            apply(v*2, tl, tm, tree[v].lazy);
            apply(v*2+1, tm+1, tr, tree[v].lazy);
            tree[v].lazy = 0;
        }
    }

    void merge(int v) {
        if (tree[v*2].min_val < tree[v*2+1].min_val) {
            tree[v].min_val = tree[v*2].min_val;
            tree[v].count = tree[v*2].count;
        } else if (tree[v*2].min_val > tree[v*2+1].min_val) {
            tree[v].min_val = tree[v*2+1].min_val;
            tree[v].count = tree[v*2+1].count;
        } else {
            tree[v].min_val = tree[v*2].min_val;
            tree[v].count = tree[v*2].count + tree[v*2+1].count;
        }
    }

    void updateRange(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) return;
        if (l == tl && r == tr) {
            apply(v, tl, tr, addend);
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            updateRange(v*2, tl, tm, l, std::min(r, tm), addend);
            updateRange(v*2+1, tm+1, tr, std::max(l, tm+1), r, addend);
            merge(v);
        }
    }

    std::pair<int, int> queryRange(int v, int tl, int tr, int l, int r) {
        if (l > r) return {INT_MAX, 0};
        if (l <= tl && tr <= r) {
            return {tree[v].min_val, tree[v].count};
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        auto left = queryRange(v*2, tl, tm, l, std::min(r, tm));
        auto right = queryRange(v*2+1, tm+1, tr, std::max(l, tm+1), r);
        if (left.first < right.first) {
            return left;
        } else if (left.first > right.first) {
            return right;
        } else {
            return {left.first, left.second + right.second};
        }
    }

public:
    LazySegmentTree(int _n) {
    	n = _n;
        tree.resize(4*n);
        buildTree(1, 0, n-1);
    }

    void updateRange(int l, int r, int addend) {
        updateRange(1, 0, n-1, l, r, addend);
    }

    std::pair<int, int> queryRange(int l, int r) {
        return queryRange(1, 0, n-1, l, r);
    }
    
    int get_maintained(){
    	pair<int, int> res = queryRange(0, n-1);
    	assert(res.first == 0);
    	return n - res.second;
    };
};


void solve() {
	int n, m; cin >> n >> m;
	vector<pair<int, int>> p(m);
	for(int i = 0; i < m; i++){
		cin >> p[i].first >> p[i].second;
		p[i].first--; p[i].second--;
	}
	LazySegmentTree st(n);
	for(pair<int, int> i: p){
		st.updateRange(i.first, i.second - 1, 1);
	}
	int ans = st.get_maintained();
	vector<vector<int>> start(n), end(n);
	for(int i = 0; i < m; i++){
		start[p[i].first].push_back(i);
		end[p[i].second].push_back(i);
	}
	for(int i = 0; i < n; i++){
		for(int j: start[i]){
			st.updateRange(p[j].first, p[j].second - 1, -1);
			st.updateRange(p[j].second, n - 1, 1);
			st.updateRange(0, p[j].first - 1, 1);
		}
		for(int j: end[i]){
			st.updateRange(p[j].second, n - 1, -1);
			st.updateRange(0, p[j].first - 1, -1);
			st.updateRange(p[j].first, p[j].second - 1, 1);
		}
		ans = min(ans, st.get_maintained());
	}
	cout << ans << "n";
}

signed main() {
	int t = 1;
	cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}

/*   /_/
*   (= ._.)
*   / >  >
*/
```
 **Solution - XOR Hashing (by awesomeguy856)**Consider the n-gon formed by the houses, with each road becoming an edge of the polygon. We draw diagonals between houses if they are friends. Let each diagonal arbitrarily "cover" one side of the polygon, where every road contained within one section split by the diagonal is covered by the diagonal. 

We claim that two roads can both be deleted if and only if they are covered by the same set of diagonals. First, this is equivalent to saying that when we draw a line between these two roads, they do not intersect any of our drawn diagonals. (This is since if any diagonal covers one road and not another, then they must be on opposite sides of the diagonal, so drawing a line between the two roads must intersect that diagonal. The converse also holds.)

Now note that if two roads are on opposite sides of a diagonal, they cannot both be deleted, as then there is no path along maintained roads that connects the two endpoints of the diagonals, or the two houses that are friends. 

So it suffices to count the most frequent set of covered diagonals over all roads. 

We can represent a diagonal cover for some road using a xor hashing, where each diagonal is assigned a random number, and the roads that are covered by that diagonal are xor'd by this number. 

By using 64-bit integers, the probability of collision is negligible, as each 64-bit integer has equal probability of representing a unique set of diagonals, and we have at most n represented sets. 

For each pair of friends, we want to xor all values in a range by some random number. This can be done with a prefix xor array in O(1) per pair of friends. Counting the most frequent value at the end will take O(nlogn) time if a map is used or O(n) if an unordered map is used. In all, this solution runs in O(nlogn+m) or O(n+m) time.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,a,b,k,t; 

void solve() {
	cin >> n >> m;
	vector<int> v(n); 
	while (m--) {
		k=rng(); cin >> a >> b;
		v[a-1]^=k;
		v[b-1]^=k;
	}
	map<int,int> c;
	for (int r:v) m=max(m,c[a^=r]++); 
	cout << n-m-1 << "n"; 
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) solve();
}
```
