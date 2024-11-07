# Tutorial

[1455A - Strange Functions](../problems/A._Strange_Functions.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1455A - Strange Functions](../problems/A._Strange_Functions.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Let's analyze which values can the function g(x) have. It can be proven that the value of g(x) is equal to 10k, where k is the number of zero-digits at the end of the number x, because f(f(x)) is the same number as x except for the fact that it doesn't have any trailing zeroes.

Okay, now let's analyze when we reach the new value of g(x). 1 is the first value of x such that g(x)=1, 10 is the first value of x such that g(x)=10, 100 is the first value of x such that g(x)=100, and so on. We have to calculate the maximum number that has the form 10k and is not greater than n, and the answer is exactly k+1.

It can be done with a mathematical solution, but the most simple way to do it is read n as a string instead, and calculate its length.

 **Solution (Ne0n25)**
```cpp
for i in range(int(input())):
	print(len(input()))
```
[1455B - Jumps](../problems/B._Jumps.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1455B - Jumps](../problems/B._Jumps.md "Educational Codeforces Round 99 (Rated for Div. 2)")

At first, let's jump with +k while x is still greater than the current position. Now we finished in some position pos=1+2+⋯+steps=steps(steps+1)2≥x. Note that 0≤pos−x<steps otherwise, we wouldn't make the last step.

If pos=x then we are lucky to finish right in point x. Otherwise, let's look at what happens if we replace one +k with −1. Basically, we'll finish in pos′=pos−(k+1). And since k∈[1,steps] then pos′∈[pos−steps−1,pos−2].

We know that pos−step<x so if x<pos−1 then we can choose the corresponding k=pos−x−1 and replace +k with −1 and get straight to the point x. But if x+1=pos then we need one extra operation −1.

To calculate steps fast we can note we need at least steps=2⋅x−−−−√−1 since steps(steps+1)≤(steps+1)2≤2x and then we can increase steps while steps(steps+1)<2x.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		
		int steps = 0;
		while (steps * (steps + 1) < 2 * x)
			steps++;
		
		if (steps * (steps + 1) / 2 == x + 1)
			steps++;
		cout << steps << endl;
	}
}
```
[1455C - Ping-pong](../problems/C._Ping-pong.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1455C - Ping-pong](../problems/C._Ping-pong.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Let's find an answer for a little different version of the game. Let's say that f(x,y) is the final score if the first player has x stamina and the second has y stamina. The first player can either hit the ball or can give up and lose the play.

How to calculate f(x,y)? Obviously, f(0,x)=(0,x) and f(x,0)=(x,0). Otherwise, the first player can 

* either hit the ball: then the player spent 1 stamina and now it's to the second player to decide — hit or lose. So basically, we moved to the state f(y,x−1) and the answer in this case is rev(f(y,x−1)) where rev(a,b)=(b,a);
* or lose the play: then the player doesn't spend any stamina, but the opponent has to serve the ball. He serves the ball, spend 1 stamina and return to the state, where the first player decides — hit or lose. Formally, the answer in this case is f(x,y−1)+(0,1).

Looking at f(0,x)=(0,x), f(x,0)=(x,0) and one of transitions f(x,y−1)+(0,1) we can guess that f(x,y)=(x,y) and prove it by induction: f(x,y) is either rev(f(y,x−1)) or f(x,y−1)+(0,1), but rev(f(y,x−1))=rev(y,x−1)=(x−1,y) and f(x,y−1)+(0,1)=(x,y−1)+(0,1)=(x,y) and (x,y) is better than (x−1,y), so f(x,y)=(x,y).

The final step is to note that since Alice starts the first play and has to serve ball — the answer is rev(f(y,x−1))=rev(y,x−1)=(x−1,y).

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	cout << x - 1 << " " << y << endl;	
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
```
[1455D - Sequence and Swaps](../problems/D._Sequence_and_Swaps.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1455D - Sequence and Swaps](../problems/D._Sequence_and_Swaps.md "Educational Codeforces Round 99 (Rated for Div. 2)")

The main fact that allows us to solve this problem is that the value of x always increases after swaps, and since the resulting sequence should be sorted, the indices of elements we swap with x also increase.

This observation is actually enough for us to implement a dynamic programming solution of the form "dp_{i, j} is the minimum number of actions we have to perform to reach the following situation: the last integer we swapped with x was ai, and the current value of ai is j". Depending on your implementation, it works either in O(n3) or in O(n2).

But there exists a much simpler to code greedy solution: scan the array from left to right until it is sorted, and find the first element such that we can apply the operation to it (and apply that operation to it). Implementing it in O(n2) or even in O(n) is easy, but proving it is a bit harder. The key fact that is required to prove it is that if we can apply an operation to some position, but don't do it and instead apply this operation to some position to the right of that one, the elements on these two positions are no longer sorted (if we can apply the operation to some position i, then ai>x, but if we apply the operation to position j instead, then after it ai>aj). Since we can't go backward, the resulting array cannot be sorted by any means — that's why we can't skip elements in this greedy solution.

 **Solution 1 (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        if(is_sorted(a.begin(), a.end()))
        {
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> dp(n, vector<int>(501, int(1e9)));
        for(int i = 0; i < n; i++)
        {
            if(a[i] > x && (i == 0 || a[i - 1] <= x))
                dp[i][x] = 1;
            if(i < n - 1 && a[i] > a[i + 1])
                break;
        }
        int ans = int(1e9);
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= 500; j++)
            {
                if(dp[i][j] == int(1e9))
                    continue;
                if(i == n || (j <= a[i + 1] && is_sorted(a.begin() + i + 1, a.end())))
                    ans = min(ans, dp[i][j]);
                bool good = true;
                for(int k = i + 1; k < n; k++)
                {
                    int pr = k == i + 1 ? j : a[k - 1];
                    if(good && a[i] >= pr && a[i] < a[k])
                        dp[k][a[i]] = min(dp[k][a[i]], dp[i][j] + 1);
                    good &= a[k] >= pr;
                }
            }
        if(ans == int(1e9))
            ans = -1;
        cout << ans << endl;
        
    }   
}
```
 **Solution 2 (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	out << "[";
	fore(i, 0, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, x;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> x))
		return false;
	a.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	return true;
}

inline void solve() {
	vector<int> sf(n + 1, 0);
	sf[n] = sf[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] <= a[i + 1])
			sf[i] = sf[i + 1];
	}
	
	int ans = 0;
	int uk = 0;
	while (true) {
		int np = uk;
		while (np < n && a[np] <= x)
			np++;
		fore (i, uk, np) {
			if (i == 0) continue;
			if (a[i - 1] > a[i]) {
				cout << -1 << endl;
				return;
			}
		}
		if (sf[np])
			break;
		
		assert(a[np] > x);
		swap(a[np], x);
		ans++;
		uk = np;
	}
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int t; cin >> t;
	
	while(t--) {
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1455E - Four Points](../problems/E._Four_Points.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1455E - Four Points](../problems/E._Four_Points.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Let's discuss two approaches to this problem. Firstly, let's think that we choose not four destination points but four lines on which sides of the square lie. It's two vertical lines with coordinates x1 and x2 and two horizontal lines y1 and y2 (of course, |x1−x2|=|y1−y2|).

The first approach is to note that 

* either both x1 and x2 coincide with some (pi.x)-s and y1 coincide with one of (pi.y)
* or both y1 and y2 coincide with some (pi.y)-s and x1 coincide with one (pi.x).

 Since we know the side of the square (from |x1−x2| or |y1−y2|) and one point (x1,y1) It's easy to construct other points of the square and find the minimum total distance by iterating all permutations. This approach needs around 2(two cases)⋅(42)⋅4⋅2y2=y1±|x1−x2|⋅4!⋅4≈104 operations and work around one second if written accurately.The second approach is more clever and faster. Let's assign a role for each point pi — which vertex of the final square this pi will be: left-bottom, left-top, right-bottom or right-top. There will be 4! such assignments. For simplicity let's say that the left-bottom vertex is a, left-top is b, right-bottom is c and right-top is d.

If we rewrite our total distance formulas, we can note that instead of summing the distance between points, we can sum the distance from lines to the points which should lie on it. In other words, we can calculate the answer as (|ax−x1|+|bx−x1|)+(|cx−x2|+|dx−x2|)++(|ay−y1|+|cy−y1|)+(|by−y2|+|dy−y2|).

Let's look at the left side x1. If min(ax,bx)≤x1≤max(ax,bx) then the total distance is always max(ax,bx)−min(ax,bx) and x1 has it's optimal segment of values. Analogically, x2 also has it's optimal segment of values min(cx,dx)≤x2≤max(cx,dx).

Since we can choose x1 as any value in its segment and x2 as any value in its segment then the possible distance |x1−x2| (the side of the square) also forms a segment of possible values (let's name it as [xSeg.l,xSeg.r]) and can be calculated with pretty easy formula.

On the other hand, we can do the same with horizontal sides and compute the segment of optimal side length [ySeg.l,ySeg.r] in the same manner.

Now, if xSeg and ySeg intersects then we can choose such side length k that lies in both xSeg and ySeg and optimal for both vertical sides and horizontal sides. 

Otherwise, without loss of generality, xSeg.r<ySeg.l and if we choose k=ySeg.l we need to pay extra "fee" since we out of xSeg — it means that the chosen k is greater than optimal xSeg.r, so we need to choose, for example, x1 outside [min(ax,bx),max(ax,bx)]. And we need to pay +2 for each step outside of this segment.

In other words, the answer for a fixed permutation is (max(ax,bx)−min(ax,bx))+(max(cx,dx)−min(cx,dx))++(max(ax,cx)−min(ax,cx))+(max(bx,dx)−min(bx,dx))++2⋅max(0,max(xSeg.l,ySeg.l)−min(xSeg.r,ySeg.r)).

 **Solution 1 (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<li, li> pt;

const li INF64 = li(1e18);

pt p[4];

inline bool read() {
	fore (i, 0, 4) {
		if(!(cin >> p[i].x >> p[i].y))
			return false;
	}
	return true;
}

inline void solve() {
	li ans = INF64;
	fore (st, 0, 2) {
		fore (idx1, 0, 4) fore (idx2, 0, 4) fore (idy1, 0, 4) {
			li x1 = p[idx1].x;
			li x2 = p[idx2].x;
			li y1 = p[idy1].y;
			
			if (x1 > x2)
				continue;
			
			for (int k = -1; k <= 1; k += 2) {
				li y2 = y1 + k * abs(x1 - x2);
				
				vector<pt> fp = { {x1, y1}, {x2, y1}, {x2, y2}, {x1, y2} };
				sort(fp.begin(), fp.end());
				
				do {
					li cur = 0;
					fore (i, 0, 4)
						cur += abs(fp[i].x - p[i].x) + abs(fp[i].y - p[i].y);
						
					ans = min(ans, cur);
				} while(next_permutation(fp.begin(), fp.end()));
			}
		}
		
		fore (i, 0, 4)
			swap(p[i].x, p[i].y);
	}
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int t;
	cin >> t;
	
	while(t--) {
		assert(read());
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
 **Solution 2 (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<li, li> pt;

const li INF64 = li(1e18);

pt p[4];

inline bool read() {
	fore (i, 0, 4) {
		if(!(cin >> p[i].x >> p[i].y))
			return false;
	}
	return true;
}

li len(const pt &a) {
	assert(a.y >= a.x);
	return a.y - a.x;
}
pt getSeg(li a, li b) {
	return { min(a, b), max(a, b) };
}
pt getOpt(const pt &a, const pt &b) {
	return {
		max({ a.x - b.y, b.x - a.y, 0LL }),
		max({ b.y - a.x, a.y - b.x, 0LL })
	};
}

inline void solve() {
	li ans = INF64;
	
	vector<int> id = { 0, 1, 2, 3 };
	do {
		li cur = 0;
		auto x1 = getSeg(p[id[0]].x, p[id[3]].x);
		auto x2 = getSeg(p[id[1]].x, p[id[2]].x);
		
		cur += len(x1) + len(x2);
		pt xSeg = getOpt(x1, x2);
		
		auto y1 = getSeg(p[id[0]].y, p[id[1]].y);
		auto y2 = getSeg(p[id[2]].y, p[id[3]].y);
		
		cur += len(y1) + len(y2);
		pt ySeg = getOpt(y1, y2);
		
		li is = min(xSeg.y, ySeg.y) - max(xSeg.x, ySeg.x);
		cur += 2 * max(0LL, -is);
		
		ans = min(ans, cur);
	}
	while (next_permutation(id.begin(), id.end()));
	
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int t;
	cin >> t;
	
	while(t--) {
		assert(read());
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1455F - String and Operations](../problems/F._String_and_Operations.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1455F - String and Operations](../problems/F._String_and_Operations.md "Educational Codeforces Round 99 (Rated for Div. 2)")

The crucial observation that we have to make is that the character that initially occupied the position i cannot occupy the positions to the left of i−2: we can shift some character two positions to the left using a combination of operations RL, but we can't go any further. So, the prefix of the first i characters of the resulting string can only be affected by the prefix of the first i+2 characters of the initial string.

Let's use the following dynamic programming to solve the problem: let dpi be the lexicographically minimum string that we can obtain by applying operations to the first i characters (that is, dpi is the answer to the problem if we consider only i first characters of the original string).

The transitions here are a bit tricky. If we apply the operation U or D to the character i+1, then dpi+1=dpi+c′, where c′ is the character we get when we apply the aforementioned operation to that character. L is a bit more complicated: we have to insert the character si+1 just before the last character of dpi.

Modeling that we can apply the operation R is likely the most complex transition in our dynamic programming. First of all, we can't just make an update to dpi+1 or dpi+2, since it leads us to a situation where we can still apply some operations to the prefix we have built. Instead, we have to consider the operation we will be able to do with the character si+2. Using another operation R is useless since the result is like performing no operations with those two characters at all, so we have to consider two options for operation with the (i+2)-th character — D or U (whichever is better), or L. In the first case, we update dpi+2 by appending the resulting two characters to dpi (the one that we get when we change si+2, and the one that initially was si+1). In the second case, things are a bit trickier, but still not very complicated: the character that was si+2 moves two positions backward, so it is inserted right before the last character of dpi, and then we append si+1 to the string we get.

So, there are four transitions we have to make:

* a transition from dpi to dpi+1 that models the case when we apply U or D to the (i+1)-th character;
* a transition from dpi to dpi+1 that models the case when we apply L to the (i+1)-th character;
* a transition from dpi to dpi+2 to model the operations RD or RU;
* a transition from dpi to dpi+2 to model the operations RL.

Overall complexity is O(n2) but it can be improved to O(nlogn) with some complicated data structures like persistent segment tree with hashes to compare strings and append characters to them in O(logn).

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, k;
string s;
string dp[N];

void solve() {
	cin >> n >> k >> s;
	for (int i = 1; i <= n; i++)
		dp[i] = char('z' + 1);
	for (int i = 0; i < n; i++) {
		int c = s[i] - 'a';
		int nc = min({c, (c + 1) % k, (c + k - 1) % k});
		dp[i + 1] = min(dp[i + 1], dp[i] + char('a' + nc));
		if (i > 0) {
			dp[i + 1] = min(dp[i + 1], dp[i - 1] + char('a' + nc) + s[i - 1]);
			dp[i + 1] = min(dp[i + 1], dp[i].substr(0, i - 1) + s[i] + dp[i].back());
		}
		if (i > 1) {
			dp[i + 1] = min(dp[i + 1], dp[i - 1].substr(0, i - 2) + s[i] + dp[i - 1].back() + s[i - 1]);
		}
	}
	cout << dp[n] << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
```
[1455G - Forbidden Value](../problems/G._Forbidden_Value.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Idea: [MrPaul_TUser](https://codeforces.com/profile/MrPaul_TUser "Candidate Master MrPaul_TUser") и [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1455G - Forbidden Value](../problems/G._Forbidden_Value.md "Educational Codeforces Round 99 (Rated for Div. 2)")

Consider the following dynamic programming. dpij — the minimum cost to make x have value j after the i-th line. The transitions here are pretty easy: on set you just consider two options of skipping or not skipping the instructions and on if you either go to the next line or to the end of the block depending on the value.

There are a lot of possible values, so that dp works in O(n2). First, let's notice that all the values that don't appear in the input won't matter, so you can keep only the existing values in the dp.

Next, let's consider the following modification to it. What happens when you enter an if block? It's actually the same dp but the only starting value is not 0 with cost 0 as in the beginning of the whole program but some value y with some cost c. So let's calculate this dp separately from the outer one and just merge the values together. Notice that if some value doesn't appear inside the if block then its cost can not decrease exiting out of it. Thus, it's enough to calculate the inner dp only for values that appear inside the if block.

Okay, the transitions for if became easier. The set transitions are still slow, though. Examine the nature of them. All the values besides the y written on the set instruction increase their cost by v. As for the y, its cost becomes equal to the cost of the cheapest value before the instruction.

Thus, let's maintain the dp in some data structure that allows to add the same integer to all elements and take the minimum of its elements. That can be done with a set and a single integer that stores the current shift that should be applied to all elements. Surely, you'll also need a map to retrieve the current cost of particular values.

The final part is fast merging of the if block dp and the outer one. It might not appear obvious but if you do that in a straightforward manner of adding all the costs from if one by one it can become O(n2) in total. So we can apply small-to-large and swap these dp's based on their sizes.

Overall complexity: O(nlog2n).

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first
#define y second

using namespace std;

const long long INF = 1e18;

struct op{
	string tp;
	int y, v, to;
};

struct addmap{
	long long add;
	map<int, long long> val;
	multiset<long long> mn;
};

void reset(addmap &a, int x, long long val){
	if (a.val.count(x))
		a.mn.erase(a.mn.find(a.val[x]));
	a.val[x] = val - a.add;
	a.mn.insert(val - a.add);
}

int main() {
	int n, s;
	scanf("%d%d", &n, &s);
	static char buf[10];
	op a;
	vector<addmap> st;
	st.push_back({});
	st.back().val[0] = 0;
	st.back().add = 0;
	st.back().mn.insert(0);
	forn(i, n){
		scanf("%s", buf);
		a.tp = buf;
		if (a.tp == "set"){
			scanf("%d%d", &a.y, &a.v);
			assert(!st.back().mn.empty());
			long long mn = st.back().add + *st.back().mn.begin();
			st.back().add += a.v;
			if (a.y != s) reset(st.back(), a.y, mn);
		}
		else if (a.tp == "if"){
			scanf("%d", &a.y);
			long long val = INF;
			if (st.back().val.count(a.y)){
				val = st.back().val[a.y] + st.back().add;
				st.back().mn.erase(st.back().mn.find(st.back().val[a.y]));
				st.back().val.erase(a.y);
			}
			st.push_back({});
			reset(st.back(), a.y, val);
			st.back().add = 0;
		}
		else{
			if (st[int(st.size()) - 1].val.size() > st[int(st.size()) - 2].val.size())
				swap(st[int(st.size()) - 1], st[int(st.size()) - 2]);
			addmap& v = st[int(st.size()) - 2];
			for (auto it : st.back().val){
				if (!v.val.count(it.x) || v.val[it.x] + v.add > it.y + st.back().add){
					if (v.val.count(it.x))
						v.mn.erase(v.mn.find(v.val[it.x]));
					v.val[it.x] = it.y + st.back().add - v.add;
					v.mn.insert(it.y + st.back().add - v.add);
				}
			}
			st.pop_back();
		}
	}
	printf("%lldn", *st.back().mn.begin() + st.back().add);
	return 0;
}
```
