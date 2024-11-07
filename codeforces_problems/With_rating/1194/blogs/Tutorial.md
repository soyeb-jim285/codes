# Tutorial

[1194A - Remove a Progression](../problems/A._Remove_a_Progression.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1194A - Remove a Progression](../problems/A._Remove_a_Progression.md "Educational Codeforces Round 68 (Rated for Div. 2)")

After some simulation of the given algorithm (in your head, on paper or on a computer) we can realize that exactly all odd numbers are erased. So, all even numbers remain, and the answer is $2x$.

 **Solution (adedalic)**
```cpp
fun main(args: Array<String>) {
    val T = readLine()!!.toInt()
    for (t in 1..T) {
        val (n, x) = readLine()!!.split(' ').map { it.toLong() }
        println(x * 2)
    }
}
```
[1194B - Yet Another Crosses Problem](../problems/B._Yet_Another_Crosses_Problem.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1194B - Yet Another Crosses Problem](../problems/B._Yet_Another_Crosses_Problem.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Let's consider each cell as a center of a cross and take the fastest one to paint. Calculating each time naively will take $O(nm(n + m))$ overall, which is too slow. Notice how the answer for some cell $(x, y)$ can be represented as $cnt_{row}[x] + cnt_{column}[y] -$ ($1$ if $a[x][y]$ is white else $0$), where $cnt_{row}[i]$ is the number of white cells in row $i$ and $cnt_{column}[i]$ is the same for column $i$. The first two terms can be precalculated beforehand.

Overall complexity: $O(nm)$ per query.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
	int q;
	cin >> q;
	forn(_, q){
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		forn(i, n)
			cin >> s[i];
		vector<int> cntn(n), cntm(m);
		forn(i, n) forn(j, m){
			cntn[i] += (s[i][j] == '.');
			cntm[j] += (s[i][j] == '.');
		}
		int ans = n + m;
		forn(i, n) forn(j, m){
			ans = min(ans, cntn[i] + cntm[j] - (s[i][j] == '.'));
		}
		cout << ans << "n";
	}
	return 0;
}
```
[1194C - From S To T](../problems/C._From_S_To_T.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1194C - From S To T](../problems/C._From_S_To_T.md "Educational Codeforces Round 68 (Rated for Div. 2)")

If the answer exists then each element of string $s$ matches with some element of string $t$. Thereby string $s$ must be a subsequence of string $t$.

Let $f(str, a)$ equal to the number of occurrences of the letter $a$ in the string $str$. Then for any letter $a$ condition $f(s, a) + f(p, a) \ge f(t, a)$ must be hold.

So the answer to the query is YES if following conditions hold: 

1. string $s$ is subsequence of string $t$;
2. $f(s, a) + f(p, a) \ge f(t, a)$ for any Latin latter $a$.
 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int q;
string s, t, p;
int cnt[30];

int main() {
	cin >> q;
	for(int iq = 0; iq < q; ++iq){
		cin >> s >> t >> p;
		memset(cnt, 0, sizeof cnt);
		for(auto x : p)
			++cnt[x - 'a'];

		bool ok = true;
		int is = 0, it = 0;
		while(is < s.size()){
			if(it == t.size()){
				ok = false;
				break;
			}
			
			if(s[is] == t[it]){
				++is, ++it;
				continue;
			}
			
			--cnt[t[it] - 'a'];
			++it;
		}
        while(it < t.size()){
            --cnt[t[it] - 'a'];
			++it;
        }
        
		if(*min_element(cnt, cnt + 30) < 0)
			ok = false;

		if(ok) cout << "YESn";
		else cout << "NOn";
	}		
	return 0;
}                             	



}                             	



```
[1194D - 1-2-K Game](../problems/D._1-2-K_Game.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int n, k;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	return true;
}

void solve() {
	bool win = true;
	if(k % 3 == 0) {
		int np = n % (k + 1);
		if(np % 3 == 0 && np != k)
			win = false;
	} else {
		int np = n % 3;
		if(np == 0)
			win = false;
	}
	
	puts(win ? "Alice" : "Bob");
}

int main(){
	int T; cin >> T;
	while(T--) {
		read();
		solve();
	}
	return 0;
}
```
[1194E - Count The Rectangles](../problems/E._Count_The_Rectangles.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1194E - Count The Rectangles](../problems/E._Count_The_Rectangles.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Let's iterate over the lower horizontal segment. Denote its coordinates as ($xl, yh$) and ($xr, yh$), where $xl < xr$. 

We call vertical segment ($x_{i, 1}$, $y_{i, 1}$), ($x_{i, 2}$, $y_{i, 2}$) good, if followings conditions holds:

1. $xl \le x_{i, 1} = x_{i, 2} \le xr$;
2. $min(y_{i, 1}, y_{i, 2}) \le yh$.

Now let's use the scanline method. At first, for each good vertical segment $i$ we increment the value of element in position $x_{i, 1}$ in some data structure (for example, Fenwick Tree). Next we will process two types of queries in order of increasing their y-coordinate:

1. horizontal segments with coordinates ($x_{i, 1}$, $y_{i, 1}$), ($x_{i, 2}$, $y_{i, 2}$);
2. upper point of some vertical segment with coordinates $(x_i, y_i)$.

And if two events of different types have the same y-coordinate then the event of first type must be processed first.

For event of first type we need to find sum on range $[x_{i, 1}, x_{i, 2}]$ ($x_{i, 1} < x_{i, 2}$) in our data structure. Let's denote this sum as $s$. Then we need to add $\frac{s (s - 1)}{2}$ to the answer (because we have $s$ vertical segments which intersect with both fixed horizontal segments and we can choose two of them in so many ways).

For event of second type we just need decrement the value of element in position $x_i$ in our data structure.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

const int N = 10009;
const int INF = 1000000009;
 
int n;
vector <pair<int, int> > vs[N], hs[N];
int f[N];
vector <int> d[N];

void upd(int pos, int x){
	for(; pos < N; pos |= pos + 1)
		f[pos] += x;
}

int get(int pos){
	int res = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

int get(int l, int r){
	return get(r) - get(l - 1);
}

const int D = 5000;

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += D, y1 += D, x2 += D, y2 += D; 
		if(y1 == y2) 
			hs[y1].push_back( mp(min(x1, x2), max(x1, x2)) );	
		else 
			vs[x1].push_back( mp(min(y1, y2), max(y1, y2)) );	
	}

	long long res = 0;
	for(int y = 0; y < N; ++y) for(auto s : hs[y]){
		for(int i = 0; i < N; ++i) d[i].clear();
		memset(f, 0, sizeof f);

		int l = s.first, r = s.second;
		for(int x = l; x <= r; ++x) for(auto s2 : vs[x])
			if(s2.first <= y && s2.second > y) {
				d[s2.second].push_back(x);
				upd(x, 1);
			}

		for(int y2 = y + 1; y2 < N; ++y2){
			for(auto s2 : hs[y2]){			
				int cur = get(s2.first, s2.second);
				res += cur * (cur - 1) / 2;
			}
			for(auto x : d[y2]) upd(x, -1);
		}
	}

	cout << res << endl;
	return 0;
}                             	




```
[1194F - Crossword Expert](../problems/F._Crossword_Expert.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1194F - Crossword Expert](../problems/F._Crossword_Expert.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Let's use (as usual) linearity of an expected value. $E = \sum\limits_{i = 1}^{n}{E(I(i))}$ where $I(i)$ is an indicator function and equal to $1$ iff Adilbek will be able to solve the $i$-th crossword.

How to calculate $I(i)$? If $\sum\limits_{j = 1}^{i}{t_i} > T$ then $I(i)$ is always $0$. On the other hand, if $\sum\limits_{j = 1}^{i}{(t_i + 1)} = \sum\limits_{j = 1}^{i}{t_i} + i \le T$ — $I(i)$ is always $1$. Otherwise, we need to calculate $E(I(i)) = P(i)$ — the needed probability.

To calculate $P(i)$ we can iterate over $k$ — the number of crosswords among first $i$ ones which will require extra time. Obviously, if $k > T - \sum\limits_{j = 1}^{i}{t_i}$ then we don't have enough time to solve the $i$-th crossword, also $k \le i$. Let's denote $m_i = \min(T - \sum\limits_{j = 1}^{i}{t_i}, i)$. There are $\binom{i}{k}$ ways to choose crosswords with extra time among all $2^i$ variants. So the final formula is following: $$P(i) = \frac{1}{2^i}\sum\limits_{k = 0}^{m_i}{\binom{i}{k}}.$$

The only problem is the efficiency. But we can find out several interesting properties. At first, $m_{i + 1} \le m_i + 1$. The other one: since $\binom{n}{k} + \binom{n}{k + 1} = \binom{n + 1}{k + 1}$, then $2 \cdot \sum\limits_{k = 0}^{x}{\binom{n}{k}} + \binom{n}{x + 1} = \sum\limits_{k = 0}^{x + 1}{\binom{n + 1}{k}}$. And this exactly the efficient way to transform $P(i) \cdot 2^i$ to $P(i + 1) \cdot 2^{i + 1}$: by multiplying and adding one coefficient we can transform the prefix sum of the $i$-th row to the prefix sum of the $i + 1$ row. And to reduce the length of the prefix sum we can just subtract unnecessary coefficients.

In result, the total complexity is $O(n)$ (maybe with extra $\log$ factor because of modular arithmetic).

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    fore(i, 0, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out;
}

const int MOD = int(1e9) + 7;

inline int norm(int a) {
    if(a >= MOD) a -= MOD;
    if(a < 0) a += MOD;
    return a;
}
inline int mul(int a, int b) {
    return int(a * 1ll * b % MOD);
}
inline int binPow(int a, int k) {
    int ans = 1;
    while(k > 0) {
        if(k & 1) ans = mul(ans, a);
        a = mul(a, a);
        k >>= 1;
    }
    return ans;
}
inline int inv(int a) {
    return binPow(a, MOD - 2);
}

int n;
li T;
vector<li> t;

inline bool read() {
    if(!(cin >> n >> T))
        return false;
    t.resize(n);
    fore(i, 0, n)
        cin >> t[i];
    return true;
}

vector<int> f, inf;

int C(int n, li k) {
    if(k > n || k < 0)
        return 0;
    return mul(f[n], mul(inf[k], inf[n - k]));
}

inline void solve() {
    f.resize(n + 5);
    inf.resize(n + 5);
    f[0] = inf[0] = 1;
    fore(i, 1, sz(f)) {
        f[i] = mul(i, f[i - 1]);
        inf[i] = mul(inf[i - 1], inv(i));
    }

    int sumC = 1;
    li bd = T;
    int pw2 = 1, i2 = (MOD + 1) / 2;

    vector<int> p(n + 1, 0);
    fore(i, 0, n) {
        pw2 = mul(pw2, i2);

        sumC = norm(mul(2, sumC) - C(i, bd));
        li need = t[i];
        if(bd > i + 1) {
            li sub = min(bd - i - 1, need);
            bd -= sub, need -= sub;
        }
        li rem = min(bd + 1, need);
        fore(k, 0, rem)
            sumC = norm(sumC - C(i + 1, bd - k));
        bd -= rem;

        p[i] = mul(sumC, pw2);
    }

    int ans = int(accumulate(p.begin(), p.end(), 0ll) % MOD);
    cout << ans << endl;
//    cerr << mul(ans, binPow(2, n)) << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
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
[1194G - Another Meme Problem](../problems/G._Another_Meme_Problem.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1194G - Another Meme Problem](../problems/G._Another_Meme_Problem.md "Educational Codeforces Round 68 (Rated for Div. 2)")

Let's fix an irreducible fraction $\frac{X}{Y}$ such that $1 \le X, Y \le 9$. Obviously, each good fraction is equal to exactly one of such irreducible fractions. So if we iterate on $X$ and $Y$, check that $gcd(X, Y) = 1$ and find the number of good fractions that are equal to $\frac{X}{Y}$, we will solve the problem.

Okay, suppose we fixed $X$ and $Y$. Any good fraction can be represented as $\frac{zX}{zY}$, where $z$ is some positive integer. Let's try all possible values of $z$, and for them check whether they correspond to a good fraction.

How do we try all values of $z$ without iterating on them? Let's construct the decimal representation of $z$ from the least significant digit to the most. As soon as we fix $k$ least significant digits of $z$, we know $k$ least significant digits of $zX$ and $zY$. So let's try to use digit DP to try all possible values of $z$.

Which states do we have to consider? Of course, we need to know the number of digits we already placed, so that will be the first state. After we placed $k$ digits, we know first $k$ digits of the numerator of the fraction; but to get the value of digit $k + 1$, knowing only the value of the corresponding digit in $z$ is not enough: there could be some value carried over after multiplying already placed digits by $X$. For example, if $X = 3$, and we placed the first digit of $z$ and it is $7$, we know that the first (least significant) digit of $zX$ is $1$, and we know that after fixing the second digit of $z$ we should add $2$ to it to get the value of this digit in $zX$, since $2$ is carried over from the first digit. So, the second state of DP should represent the number that is carried over from the previous digit in the numerator, and the third state should do the same for the denominator.

Okay, in order to know whether the fraction is good, we have to keep track of some digits in the numerator and denominator. If $\frac{x'}{y'} = \frac{X}{Y}$, $1 \le x' \le 9$ and $1 \le y' \le 9$, then we have to keep track of the digit representing $x'$ in the numerator and the digit representing $y'$ in the denominator. So we have two additional states that represent the masks of "interesting" digits we met in the numerator and in the denominator.

The only thing that's left to check is that both $zX$ and $zY$ are not greater than $n$. Let's construct the decimal representation of $n$ and prepend it with some leading zeroes; and keep constructing the numerator and the denominator until they have the same number of digits as the decimal representation as $n$. Then we can compare the representation of, for example, numerator with the representation of $n$ as strings. Comparing can be done with the following technique: let's keep a flag denoting whether the number represented by the least significant digits of the numerator is less or equal than the number represented by the same digits from $n$. When we place another digit of the numerator, we can get the new value of this flag as follows: if new digit of the numerator is not equal to the corresponding digit of $n$, then the value of the flag is defined by comparing this pair of digits; otherwise the value of the flag is the same as it was without this new digit. Of course, we should do the same for the denominator.

Okay, now we can actually start coding this DP: $dp[k][carry1][carry2][comp1][comp2][mask1][mask2]$ is the number of possible ways to put $k$ least significant digits in $z$ in such a way that:

* the value carried over to the next digit of the numerator is $carry1$ (and $carry2$ for the denominator);
* $comp1$ denotes whether the current numerator is less or equal to the number represented by $k$ least significant digits of $n$ ($comp2$ does the same for the denominator);
* $mask1$ denotes which "interesting" digits we already met in the numerator (of course, $mask2$ does the same for the denominator).

If you are feeling confident in your programming abilities, you can just start implementing this DP on a seven-dimensional array. I was too afraid to do it (but, looking at participants' solutions, I realize that it sounds much more scary than it looks in the code), so I decided to write the model solution using a structure representing each state, and a map to store all these structures. This is a common technique: when a dynamic programming solution you come up with has some really complex states and transitions, it is sometimes better to use some self-implemented structures to define these states and store them in a map or a hashmap. Some advantages of this technique are:

* it's sometimes much easier to code (the code may be longer than the same solution with regular DP stored in a multi-dimensional array, but it's easier to write and understand this code);
* if most states are unreachable, they won't even appear in our map, so we skip them altogether;
* it is easy to add some optimizations related to reducing the number of states. For example, the number of different values for $mask1$ and $mask2$ may be too much, so we can use the following optimization: as soon as we find some pair of numbers in $mask1$ and $mask2$ that can represent $x'$ and $y'$, we can change these masks to some values that will mark that they are "finished" and stop updating them at all.
 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];
int n;
int numPos[10], denPos[10];
int num, den;
const int MOD = 998244353;

struct halfState
{
	int carry;
	int mask;
	bool comp;
	
	halfState() {};
	halfState(int carry, int mask, bool comp) : carry(carry), mask(mask), comp(comp) {};
};

bool operator <(const halfState& x, const halfState& y)
{
	if(x.carry != y.carry) return x.carry < y.carry;
	if(x.mask != y.mask) return x.mask < y.mask;
	return x.comp < y.comp;
}

bool operator ==(const halfState& x, const halfState& y)
{
	return x.carry == y.carry && x.mask == y.mask && x.comp == y.comp;
}

bool operator !=(const halfState& x, const halfState& y)
{
	return x.carry != y.carry || x.mask != y.mask || x.comp != y.comp;
}

halfState go(const halfState& s, int pos, int digit, bool isNum)
{
	int newDigit = digit * (isNum ? num : den) + s.carry;
	int newCarry = newDigit / 10;
	newDigit %= 10;
	int newMask = s.mask;
	int maskPos = (isNum ? numPos[newDigit] : denPos[newDigit]);
	if(maskPos != -1) newMask |= (1 << maskPos);
	bool newComp = (newDigit < a[pos]) || (newDigit == a[pos] && s.comp);
	return halfState(newCarry, newMask, newComp);
}

struct state
{
	halfState numState;
	halfState denState;
	
	state() {};
	state(halfState numState, halfState denState) : numState(numState), denState(denState) {};
	
	void norm()
	{
		if(numState.mask & denState.mask)
			numState.mask = denState.mask = 1;
	};
	
	bool valid()
	{
		return bool(numState.mask & denState.mask) && numState.comp && denState.comp && (numState.carry == 0) && (denState.carry == 0);
	};
};

bool operator <(const state& x, const state& y)
{
	if(x.numState != y.numState) return x.numState < y.numState;
	return x.denState < y.denState;
}

state go(const state& s, int pos, int digit)
{
	halfState newNum = go(s.numState, pos, digit, true);
	halfState denNum = go(s.denState, pos, digit, false);
	state res(newNum, denNum);
	res.norm();
	return res;
}

int add(int x, int y)
{
	return (x + y) % MOD;
}

int ans = 0;

void calcFixed(int x, int y)
{
	num = x;
	den = y;
	for(int i = 0; i <= 9; i++)
		numPos[i] = denPos[i] = -1;
	int cnt = 0;
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 9; j++)
			if(i * y == j * x)
			{
				numPos[i] = denPos[j] = cnt++;
			}
	vector<map<state, int> > dp(102);
	dp[0][state(halfState(0, 0, true), halfState(0, 0, true))] = 1;
	for(int i = 0; i <= 100; i++)
		for(auto x : dp[i])
		{
			state curState = x.first;
			int curCount = x.second;
			for(int j = 0; j <= 9; j++)
			{
				state newState = go(curState, i, j);
				dp[i + 1][newState] = add(dp[i + 1][newState], curCount);
			}
		}
	for(auto x : dp[101])
	{
		state curState = x.first;
		int curCount = x.second;
		if(curState.valid())
			ans = add(ans, curCount);
	}
}

int main()
{
	string s;
	cin >> s;
	int len = s.size();
	reverse(s.begin(), s.end());
	for(int i = 0; i < len; i++)
	{
		a[i] = s[i] - '0';
 	}
 	for(int i = 1; i <= 9; i++)
 		for(int j = 1; j <= 9; j++)
 			if(__gcd(i, j) == 1)
 				calcFixed(i, j);
 	cout << ans << endl;
}
```
