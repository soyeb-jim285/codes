# Tutorial

[1373A - Donut Shops](../problems/A._Donut_Shops.md "Educational Codeforces Round 90 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1373A - Donut Shops](../problems/A._Donut_Shops.md "Educational Codeforces Round 90 (Rated for Div. 2)")

At first notice that if there exists a value for the second shop, then the value divisible by $b$ also exists. For any $x$ you can round it up to the nearest multiple of $b$. That won't change the price for the second shop and only increase the price for the first shop.

You can also guess that if there exists a value for the first shop, then the value with $1$ modulo $b$ also exists (exactly $1$ donut on top of some number of full boxes). Following the same logic — the second shop needs an entire new box and the first shop needs only an extra donut.

So let's take a look at the smallest values of two kinds: 

* $x = b$: this value is valid for the second shop if one box is cheaper than $b$ donuts in the first shop. Otherwise, no matter how many boxes will you take, they will never be cheaper than the corresponding number of donuts.
* $x = 1$: this value is valid for the first shop if one donut is cheaper than one box in the second shop. Apply the same idea — otherwise no value for the first shop is valid.

Overall complexity: $O(1)$ per testcase.

 **Solution (pikmike)**
```cpp
for tc in range(int(input())):
	a, b, c = map(int, input().split())
	print(1 if a < c else -1, end=" ")
	print(b if c < a * b else -1)
```
[1373B - 01 Game](../problems/B._01_Game.md "Educational Codeforces Round 90 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1373B - 01 Game](../problems/B._01_Game.md "Educational Codeforces Round 90 (Rated for Div. 2)")

If there is at least one character 0 and at least one character 1, then current player can always make a move. After the move the number of character 0 decreases by one, and the number of character 1 decreases by one too. So the number of moves is always min(c0,c1), where c0 is the number of characters 0 in string s, and c1 is the number of characters 1 in string s.

So if min(c0,c1) is odd then Alice wins, otherwise Bob wins. 

 **Solution (Roms)**
```cpp
for _ in range(int(input())):
    s = input()
    print('DA' if min(s.count('0'), s.count('1')) % 2 == 1 else 'NET')
```
[1373C - Pluses and Minuses](../problems/C._Pluses_and_Minuses.md "Educational Codeforces Round 90 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1373C - Pluses and Minuses](../problems/C._Pluses_and_Minuses.md "Educational Codeforces Round 90 (Rated for Div. 2)")

Let's replace all + with 1, and all - with -1. After that let's create a preffix-sum array $p$ ($p_i = \sum\limits_{j=1}^{i} s_j$). Also lets create array $f$ such that $f_i$ is equal minimum index $j$ such that $p_j = -i$ (if there is no such index $p_i = -1$).

Let's consider the first iteration of loop $for ~ init ~ = ~ 0 ~ to ~ inf$. If $f_1 = -1$ then process ends and $res = |s|$. Otherwise the condition $if ~ cur ~ < ~ 0$ fulfilled then the value of $i$ will be equal to $f_1$. So, the value of $res$ is equal to $f_1$ after first iteration.

Now, let's consider the second iteration of loop $for ~ init ~ = ~ 0 ~ to ~ inf$. If $f_2 = -1$ then process ends and $res = f_1 + |s|$. Otherwise the condition $if ~ cur ~ < ~ 0$ fulfilled then the value of $i$ will be equal to $f_2$. So, the value of $res$ is equal to $f_1 + f_2$ after second iteration.

In this way we can calculate the value of $res$ after the process ends.

 **Solution (Roms)**
```cpp
for _ in range(int(input())):
    s = input()
    cur, mn, res = 0, 0, len(s)
    for i in range(len(s)):
        cur += 1 if s[i] == '+' else -1
        if cur < mn:
            mn = cur
            res += i + 1
        
    print(res)
```
[1373D - Maximum Sum on Even Positions](../problems/D._Maximum_Sum_on_Even_Positions.md "Educational Codeforces Round 90 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1373D - Maximum Sum on Even Positions](../problems/D._Maximum_Sum_on_Even_Positions.md "Educational Codeforces Round 90 (Rated for Div. 2)")

Firstly, we can notice that the reverse of of odd length subarray does nothing because it doesn't change parities of indices of affected elements. Secondly, we can consider the reverse of the subarray of length $2x$ as $x$ reverses of subarrays of length $2$ (i.e. it doesn't matter for us how exactly the subarray will be reversed, we can only consider changing parities).

Now, there are two ways: the first one is smart and the second one is dynamic programming.

Consider the first way. Calculate the initial sum of elements on even positions $sum$. Then let's create two arrays $v_1$ and $v_2$. There $v_1[i]$ is $a[2i+1] - a[2i]$ for all $i$ from $0$ to $\lfloor\frac{n}{2}\rfloor - 1$ and $v_2[i]$ is $a[2i] - a[2i+1]$ for all $i$ from $0$ to $\lfloor\frac{n}{2}\rfloor - 1$. Elements of the first array deonte the profit if we reverse the subarray tarting from the even position, and elemnts of the second array denote the profit if we reverse the subarray starting from the odd position. Now we need to find the subarray with the maximum sum in both arrays (this will maximize overall profit) and add this value to $sum$ to get the answer. This problem can be solved easily: consider the sum of the subarray $[l; r]$ as the difference of two prefix sums $pref_{r} - pref_{l-1}$. To maximize it, consider all right borders and minimize the value $pref_{l-1}$. Iterate over all positions of the array, maintaining the current prefix sum $csum$ and the minimum prefix sum we meet $msum$. Update $csum := csum + a_i$, then update $msum := min(msum, csum)$ and then update the answer with the value $csum - msum$.

And the second way is author's solution and it is dynamic programming. This idea can be transformed to solve such problems in which you need to apply some function to some small number of subsegments (of course, under some constraints on functions). State of our dynamic programming is $dp_{i, j}$ where $i \in [0; n]$ and $j \in [0; 2]$. $dp_{i, 0}$ denotes the answer on the prefix of length $i$ if we didn't start reversing the subarray, $dp_{i, 1}$ denotes the answer if we started reversing the subarray but didn't end it and $dp_{i, 2}$ denotes the answer if we ended reversing the subarray. Transitions are pretty easy:

* $dp_{i + 1, 0} = max(dp_{i + 1, 0}, dp_{i, 0} + [i \% 2 == 0? a_i : 0])$;
* $dp_{i + 2, 1} = max(dp_{i + 2, 1}, max(dp_{i, 0}, dp_{i, 1}) + [i \% 2 == 0 ? a_{i + 1} : a_i])$;
* $dp_{i + 1, 2} = max(dp_{i + 1, 2}, max(dp_{i, 0}, dp_{i, 1}, dp_{i, 2}) + [i \% 2 == 0? a_i : 0])$.

The value $x ? y : z$ is just a ternary if statement. If $x$ is true then return $y$ otherwise return $z$.

The answer is $max(dp_{n, 0}, dp_{n, 1}, dp_{n, 2})$.

Time complexity with both approaches is $O(n)$.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		vector<vector<long long>> dp(n + 1, vector<long long>(3));
		for (int i = 0; i < n; ++i) {
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i & 1 ? 0 : a[i]));
			if (i + 2 <= n) dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + (i & 1 ? a[i] : a[i + 1]));
			dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1 ? 0 : a[i]));
		}
		cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
	}
	
	return 0;
}
```
[1373E - Sum of Digits](../problems/E._Sum_of_Digits.md "Educational Codeforces Round 90 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1373E - Sum of Digits](../problems/E._Sum_of_Digits.md "Educational Codeforces Round 90 (Rated for Div. 2)")

There are many ways to solve this problem (including precalculating all answers), but the model solution is based on the following:

In most cases, $f(x + 1) = f(x) + 1$. It is not true only when the last digit of $x$ is $9$ (and if we know the number of $9$-digits at the end of $x$, we can easily derive the formula for $f(x + 1)$). And since $k \le 9$, there will be at most one number with last digit equal to $9$ in $[x, x + 1, \dots, x + k]$.

Let's iterate on the last digit of $x$ and the number of $9$-digits before it. Suppose the fixed $x$ has no other digits other than the last one and several $9$-digits before it. Let's calculate $s = f(x) + f(x + 1) + f(x + 2) \dots + f(x + k)$.

Here goes the trick. If we prepend $x$ with several digits such that the last of them is not $9$, and the sum of those digits is $d$, then $f(x) + f(x + 1) + f(x + 2) \dots + f(x + k) = s + d(k + 1)$. So we can easily derive the value of $d$ we need and construct the smallest number with sum of digits equal to $d$ (don't forget that the last digit should not be $9$).

 **Solution 1 (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n, k;

bool decimalLess(const string& s, const string& t)
{
	if(s.size() != t.size())
		return s.size() < t.size();
	for(int i = 0; i < s.size(); i++)
		if(s[i] != t[i])
			return s[i] < t[i];
	return false;
}

void upd(string& ans, const string& cur)
{
	if(ans == "-1" || decimalLess(cur, ans))
		ans = cur;
}

void read()
{
	cin >> n >> k;
}

void solve()
{
	string ans = "-1";
	for(int i = 0; i <= 9; i++)
	{
		int cnt9 = n / 9;
		if(i + k < 10)
			cnt9 = 0;
		for(int j = 0; j <= cnt9; j++)
		{
		    if(i + k >= 10 && j == 0)
		        continue;
			int curSum = (i + (i + k)) * (k + 1) / 2;
			if(j != 0)
			{
				int cntBefore = 10 - i;
				int cntAfter = k + 1 - cntBefore;
				curSum = (i + 9) * cntBefore / 2 + cntBefore * 9 * (j - 1) + (1 + cntAfter) * cntAfter / 2;
			}
			curSum = n - curSum;
			if(curSum < 0 || curSum % (k + 1) != 0)
				continue;
			string curNum = {char('0' + i)};
			for(int z = 0; z < j - 1; z++)
				curNum += "9";
			int maxNum = 9;
			if(i + k >= 10)
				maxNum = 8;
			curSum /= (k + 1);
			while(curSum != 0)
			{
				int d = min(curSum, maxNum);
				maxNum = 9;
				curSum -= d;
				curNum.push_back(char('0' + d));
			}
			reverse(curNum.begin(), curNum.end());
			upd(ans, curNum);
		}
	}
	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		read();
		solve();
	}
}
```
 **Solution 2 (pikmike)**
```cpp
def get(s):
	return str(s % 9) + '9' * (s // 9)

for tc in range(int(input())):
	n, k = map(int, input().split())
	k += 1
	bst = 10**100
	for d in range(10):
		ends = 0
		for i in range(k):
			ends += (d + i) % 10
		if ends > n:
			continue
		if d + k > 10:
			for cnt in range(12):
				s = 9 * cnt * (10 - d)
				if s > n - ends:
					break
				for nd in range(9):
					ns = s + (10 - d) * nd + (k - (10 - d)) * (nd + 1)
					if ns > n - ends:
						break
					if (n - ends - ns) % k == 0:
						bst = min(bst, int(get((n - ends - ns) // k) + str(nd) + '9' * cnt + str(d)))
		elif (n - ends) % k == 0:
			bst = min(bst, int(get((n - ends) // k) + str(d)))
	print(-1 if bst == 10**100 else bst)
```
[1373F - Network Coverage](../problems/F._Network_Coverage.md "Educational Codeforces Round 90 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1373F - Network Coverage](../problems/F._Network_Coverage.md "Educational Codeforces Round 90 (Rated for Div. 2)")

There are plenty of different solutions to this problem. Here is one that doesn't use Hall's theorem.

Let's look at pair $(a_i, b_i)$ as fuction $f_i(in) = out$: how many connections $out$ will be left for the $(i + 1)$-th city if we take $in$ connections from the $(i - 1)$-th station. This function has the following structure: there is a minimum required $in$ (let's name it $minx_i$) to meet the needs of the $i$-th city and with $minx_i$ borrowed connections there will be $f_i(minx_i) = mink_i$ free connections to the $(i + 1)$-th city. Increasing $minx_i$ by some $x$ we can get $f_i(minx_i + x) = mink_i + x$ free connections, but there is upper bound to number of free connections $maxk_i$. In other words, the function $f_i(minx_i + x) = \min(mink_i + x, maxk_i)$ where $x \ge 0$.

For example, let's calculate the corresponding coefficients for the $i$-th function: 

* if $a_i \le b_i$ then $minx_i = 0$, $mink_i = b_i - a_i$ and $maxk_i = b_i$;
* if $a_i > b_i$ then $minx_i = a_i - b_i$, $mink_i = 0$ and $maxk_i = b_i$.

Why did we define such functions? If we can calculate result function $f_{[1,n]}(in) = f_n(f_{n - 1}(\dots f_2(f_1(in))\dots))$ then we can check the possibility of meeting all needs by checking that this fuction exists and $minx_{[1,n]} \le mink_{[1,n]}$, i. e. the minimum free $mink_{[1,n]}$ can be used as borrowed $minx_{[1,n]}$.

Fortunately, it turns out that the superposition $f_{i+1}(f_i(in))$ is either don't exists (if, for example, $maxk_i < minx_{i + 1}$) or it has the same structure as any function $f_i$. So we can calculate $f_{[1,n]}$ in one pass and find the answer.

We will skip the detailed formulas to calculate $f_{i+1}(f_i(in))$: you can either find them by yourself or look at function $merge()$ in author's solution.

The resulting complexity is $O(n)$.

 **Solution 1 (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
vector<int> a, b;

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	fore(i, 0, n)
		cin >> a[i];
	b.resize(n);
	fore(i, 0, n)
		cin >> b[i];
	return true;
}

struct func {
	int minx, mink, maxk;
	func() : minx(0), mink(0), maxk(0) {}
	func(int minx, int mink, int maxk) : minx(minx), mink(mink), maxk(maxk) {}
};

func getFunc(int a, int b) {
	if (a <= b)
		return func(0, b - a, b);
	else
		return func(a - b, 0, b);
}

func merge(func a, func b) {
	if (a.minx == -1 || b.minx == -1)
		return func(-1, -1, -1);
	
	if (a.maxk < b.minx)
		return func(-1, -1, -1);
	if (a.mink >= b.minx)
		return func(a.minx, min(b.maxk, b.mink + (a.mink - b.minx)), min(b.maxk, b.mink + (a.maxk - b.minx)));
	else {
		int add = b.minx - a.mink;
		return func(a.minx + add, b.mink, min(b.maxk, b.mink + (a.maxk - b.minx)));
	}
}

inline void solve() {
	func total = getFunc(a[0], b[0]);
	fore(i, 1, n)
		total = merge(total, getFunc(a[i], b[i]));
	
	if (total.minx != -1 && total.minx <= total.mink)
		cout << "YESn";
	else
		cout << "NOn";
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	
	while(tc--) {
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
 **Solution 2 (Ne0n25)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

typedef long long li;
const int N = 1000 * 1000 + 13;

int n;
int a[N], b[N];
 
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	
	li need = 0, add = 0, extra = 2e9;
	for (int i = n - 1; i >= 0; --i) {
		if (b[i] < need) {
			puts("NO");
			return;
		}
		
		li val = b[i] - a[i];
		li to_add = min(extra, max(0LL, val - need));
		add += to_add;
		extra = min(extra - to_add, b[i] - need - to_add);
		need = max(0LL, need - val);
	}
	
	puts(add >= need ? "YES" : "NO");
}
 
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
		solve();
}

```
[1373G - Pawns](../problems/G._Pawns.md "Educational Codeforces Round 90 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1373G - Pawns](../problems/G._Pawns.md "Educational Codeforces Round 90 (Rated for Div. 2)")

For each pawn with initial position $(x, y)$ there exists a minimum index of row $i$ such that the pawn can reach the cell $(k, i)$, but cannot reach the cell $(k, i - 1)$. It's easy to see that $i = |k - x| + y$. In the resulting configuration, this pawn can occupy the cell $(k, i)$, $(k, i + 1)$, $(k, i + 2)$ or any other cell $(k, j)$ having $j \ge i$.

Suppose the board consists of $r$ rows. For each row, the number of rows above it should be not less than the number of pawns that occupy the cells above it (that is, having $i$ greater than the index of that row) — because, if this condition is not fulfilled, we can't assign each pawn a unique cell. If we denote the number of pawns that should go strictly above the $j$-th row as $f(j)$, then for every row, the condition $f(j) \le r - j$ must be met.

To prove that this condition is sufficient, we may, for example, use Hall's theorem. Okay, now what about finding the minimum $r$ satisfying it? Let's initially set $r$ to $n$, and for each row maintain the value of $j + f(j) - n$ — the minimum number of rows we have to add to our board so that the condition for the row $j$ is met (we also have to maintain this value for $n - 1$ auxiliary rows from $n + 1$ to $2n - 1$, since some pawns cannot fit in the initial board at all). Finding the minimum value we have to add to $r$ equals finding the maximum of all these values on some prefix (we don't need to look at the values on some rows with large indices, if there are no pawns after them, so we need a maximum query on the segment $[1, \max_i]$, where $\max_i$ is the maximum index $i$ among all pawns); and when a pawn is added or removed, we should add $+1$ or $-1$ to all values on some suffix. A segment tree with lazy propagation will do the trick, solving the problem for us in $O(m \log n)$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 9;

int n, k;
int m;
int t[8 * N];
int add[8 * N];
int cnt[2 * N];

void push(int v, int l, int r) {
    if (r - l != 1 && add[v] != 0) {
        t[v * 2 + 1] += add[v];
        t[v * 2 + 2] += add[v];
        add[v * 2 + 1] += add[v];
        add[v * 2 + 2] += add[v];
        add[v] = 0;
    }
}

void upd(int v, int l, int r, int L, int R, int x) {
    if (L >= R) return;
    if(l == L && r == R) {
        t[v] += x;
        add[v] += x;
        return;
    } 
    
    push(v, l, r);
    int mid = (l + r) / 2;
    upd(v * 2 + 1, l, mid, L, min(R, mid), x);
    upd(v * 2 + 2, mid, r, max(L, mid), R, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

void upd(int l, int r, int x) {
    upd(0, 0, n + n, l, r, x);
}

int get(int v, int l, int r, int L, int R) {
    if (L >= R) return 0;
    if (l == L && r == R) return t[v];
    
    push(v, l, r);
    int mid = (l + r) >> 1;
    return max(get(v * 2 + 1, l, mid, L, min(R, mid))
    		 , get(v * 2 + 2, mid, r, max(L, mid), R));
}

int get(int l, int r) {
    return get(0, 0, n + n, l, r);
}

int getAns(set <int> &smx) {
    if (smx.empty()) return 0;
    return max(0, get(0, *smx.rbegin() + 1) - n);
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        t[v] = l;
        return;
    }
    
    int mid = (l + r) >> 1;
    build(v * 2 + 1, l, mid);
    build(v * 2 + 2, mid, r);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

int main(){
    scanf("%d %d %d", &n, &k, &m);
    
    build(0, 0, n + n);
    set <pair<int, int> > s;
    set <int> smx;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        int pos = abs(x - k) + y - 1;
        pair <int, int> p = make_pair(x, y);
        if (s.count(p)) {
            --cnt[pos];
            if (cnt[pos] == 0) smx.erase(pos);
            upd(0, pos + 1, -1);
            s.erase(p);
        } else {
            ++cnt[pos];
            if (cnt[pos] == 1) smx.insert(pos);
            upd(0, pos + 1, 1);
            s.insert(p);
        }
        
        printf("%dn", getAns(smx));
    }
    return 0;
}
```
