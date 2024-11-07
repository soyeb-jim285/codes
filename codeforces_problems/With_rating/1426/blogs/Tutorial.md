# Tutorial

[1426A - Floor Number](../problems/A._Floor_Number.md "Codeforces Round 674 (Div. 3)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1426A - Floor Number](../problems/A._Floor_Number.md "Codeforces Round 674 (Div. 3)")

If $n \le 2$ then the answer is $1$. Otherwise, you can "remove" the first floor and then the answer is $\left\lfloor\frac{n - 3}{x}\right\rfloor + 2$.

 **Solution**
```cpp
for i in range(int(input())):
    n, x = map(int, input().split())
    print(1 if n <= 2 else (n - 3) // x + 2)
```
[1426B - Symmetric Matrix](../problems/B._Symmetric_Matrix.md "Codeforces Round 674 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1426B - Symmetric Matrix](../problems/B._Symmetric_Matrix.md "Codeforces Round 674 (Div. 3)")

Firstly, if $m$ is odd then the answer is "NO" by obvious reasons. Otherwise, we can notice that the top left and the bottom right values of the tile do not matter (since we can place tiles symmetrically). So we only need to check that there is some tile that its top right value equals its bottom left value (because this is how we get main diagonal symmetry).

 **Solution**
```cpp
for i in range(int(input())):
	n, m = map(int, input().split())
	a = []
	for i in range(n):
		a.append([[int(x) for x in input().split()] for i in range(2)])
	ok = False
	for i in range(n):
		ok |= a[i][0][1] == a[i][1][0]
	ok &= m % 2 == 0
	print("YES" if ok else "NO") 
```
[1426C - Increase and Copy](../problems/C._Increase_and_Copy.md "Codeforces Round 674 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1426C - Increase and Copy](../problems/C._Increase_and_Copy.md "Codeforces Round 674 (Div. 3)")

It is pretty intuitive that we firstly need to do all increments and only then copy numbers (because otherwise we can swap the order of moves and the sum will not decrease). You could notice that the answer does not exceed $O(\sqrt{n})$ so we can just iterate from $1$ to $\left\lfloor\sqrt{n}\right\rfloor$ and fix the number we will copy. Let it be $x$. Then we need $x-1$ moves to obtain it and also need $\left\lceil\frac{n-x}{x}\right\rceil$ moves to get the enough number of copies. So, we can update the answer with this number of moves.

Time complexity: $O(\sqrt{n})$ per test case.

Actually, the required number is always pretty near to $\left\lfloor\sqrt{n}\right\rfloor$ so it is enough to try a few options in range $[\left\lfloor\sqrt{n}\right\rfloor - 5; \left\lfloor\sqrt{n}\right\rfloor + 5]$ to get the optimal answer. This is $O(1)$ solution.

 **Solution**
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
		int ans = 1e9;
		for (int x = 1; x * x <= n; ++x) {
			ans = min(ans, x - 1 + ((n - x) + x - 1) / x);
		}
		cout << ans << endl;
	}
	
	return 0;
}

```
 **Solution 2**
```cpp
#include<bits/stdc++.h>

using namespace std;

const long double EPS = 1e-9;

long long f(long long x)
{                                                        
	long long z = sqrtl(x);
	long long ans = 1e18;
	for(int i = -5; i <= 5; i++)
	{
	 	long long z2 = z - i;
	 	if(z2 > x || z2 < 1)
	 		continue;
	 	ans = min(ans, z2 - 2 + (x + z2 - 1) / z2);
	}
	return ans;
}

int main()
{
 	int t;
 	cin >> t;
 	for(int i = 0; i < t; i++)
 	{
 	 	long long x;
 	 	cin >> x;
 	 	cout << f(x) << endl;
 	}
}
```
[1426D - Non-zero Segments](../problems/D._Non-zero_Segments.md "Codeforces Round 674 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1426D - Non-zero Segments](../problems/D._Non-zero_Segments.md "Codeforces Round 674 (Div. 3)")

Firstly, let's understand that the sum of the segment $[l; r]$ is zero if $p_r - p_{l - 1}$ is zero (in other words, $p_{l - 1} = p_r$), where $p_i$ is the sum of the first $i$ elements ($p_0 = 0$).

Let's iterate over elements from left to right and add all prefix sums in the set. If we get the sum that is already in the set, we get some segment with sum $0$, and we need to fix it somehow. Let's insert some huge number before the current element in such a way that all prefix sums starting from the current element to the end will be significantly bigger than all prefix sums to the left. In words of implementation, we just get rid of all prefix sums to the left (clear the set) and continue doing the same process starting from the current element (so we just cut off the prefix of the array).

This way is optimal because we remove all segments with sum $0$ ending at the current element using only one insertion (and we need to use at least one insertion to do that).

Time complexity: $O(n \log{n})$.

 **Solution**
```cpp
n = int(input())
a = [int(x) for x in input().split()]
d = set()
d.add(0)
cur = 0
ans = 0
for i in range(n):
	cur += a[i]
	if cur in d:
		ans += 1
		d = set()
		d.add(0)
		cur = a[i]
	d.add(cur)
print(ans)
```
[1426E - Rock, Paper, Scissors](../problems/E._Rock,_Paper,_Scissors.md "Codeforces Round 674 (Div. 3)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1426E - Rock, Paper, Scissors](../problems/E._Rock,_Paper,_Scissors.md "Codeforces Round 674 (Div. 3)")

The maximum number of rounds Alice can win is pretty easy to calculate greedily: $min(a_1, b_2) + min(a_2, b_3) + min(a_3, b_1)$. What about the minimum number of rounds?

It can be shown that if we started using some combination we are better to end it before using the other one. There are six possible combinations to not win the round:

* $a_1$ and $b_1$.
* $a_2$ and $b_2$.
* $a_3$ and $b_3$.
* $a_1$ and $b_3$.
* $a_2$ and $b_1$.
* $a_3$ and $b_2$.

We can iterate over all permutations of these combinations (there are $6! = 720$ possible permutations) and greedily apply them. Use the first while it is possible, then the second, and so on, and find the best answer.

It is also possible that the order of these combinations does not matter, but we didn't prove that fact.

Time complexity: $O(1)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define ft first
#define sc second

using namespace std;

int n;
vector<int> a, b;

inline void read() {
	cin >> n;
	a.resize(3);
	b.resize(3);
	for (int i = 0; i < 3; i++) cin >> a[i];
	for (int i = 0; i < 3; i++) cin >> b[i];
}
	
inline void solve() {
	int ans1 = INT_MAX;
	vector<pair<int, int> > ord;
	ord.pb({0, 0});
	ord.pb({0, 2});
	ord.pb({1, 1});
	ord.pb({1, 0});
	ord.pb({2, 2});
	ord.pb({2, 1});
	sort(all(ord));
	do {
		vector<int> a1 = a, b1 = b;
		for (int i = 0; i < sz(ord); i++) {
			int cnt = min(a1[ord[i].ft], b1[ord[i].sc]);
			a1[ord[i].ft] -= cnt;
			b1[ord[i].sc] -= cnt;			
		}
		int cur = min(a1[0], b1[1]) + min(a1[1], b1[2]) + min(a1[2], b1[0]);
		ans1 = min(ans1, cur);
	} while(next_permutation(all(ord)));
	int ans2 = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
	cout << ans1 << ' ' << ans2 << endl;
}

int main () {
    read();
    solve();
}
```
[1426F - Number of Subsequences](../problems/F._Number_of_Subsequences.md "Codeforces Round 674 (Div. 3)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1426F - Number of Subsequences](../problems/F._Number_of_Subsequences.md "Codeforces Round 674 (Div. 3)")

There are several more or less complicated combinatorial solutions to this problem, but I will describe a dynamic programming one which, I think, is way easier to understand and to implement.

Suppose we have fixed the positions of a, b and c that compose the subsequence (let these positions be $p_a$, $p_b$ and $p_c$). How many strings contain the required subsequence on these positions? Obviously, if some of these characters is already not a question mark and does not match the expected character on that position, the number of strings containing the subsequence on that position is $0$. Otherwise, since we have fixed three characters, all question marks on other positions can be anything we want — so the number of such strings is $3^x$, where $x$ is the number of question marks on positions other than $p_a$, $p_b$ and $p_c$. It allows us to write an $O(n^3)$ solution by iterating on $p_a$, $p_b$ and $p_c$, and for every such triple, calculating the number of strings containing the required subsequence on those positions.

But that's too slow. Let's notice that, for every such subsequence, the number of strings containing it is $3^{k - qPos({p_a, p_b, p_c})}$, where $qPos({p_a, p_b, p_c})$ is the number of positions from ${p_a, p_b, p_c}$ that contain a question mark. So, for each integer $i$ from $0$ to $3$, let's calculate the number of subsequences matching abc that contain exactly $i$ question marks — and that will allow us to solve the problem faster.

How can we calculate the required number of subsequences for every $i$? In my opinion, the simplest way is dynamic programming: let $dp_{i, j, k}$ be the number of subsequences of $s$ that end up in position $i$, match $j$ first characters of abc and contain $k$ question marks. The transitions in this dynamic programming are quadratic (since we have to iterate on the next/previous position from the subsequence), but can be sped up to linear if we rewrite $dp_{i, j, k}$ as the number of subsequences of $s$ that end up in position not later than $i$, match $j$ first characters of abc and contain $k$ question marks. Each transition is either to take the current character or to skip it, so they can be modeled in $O(1)$, and overall this dynamic programming solution works in $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
                            
using namespace std;

const int MOD = int(1e9) + 7;
const int N = 200043;
const int K = 4;

int add(int x, int y)
{
 	x += y;
 	while(x >= MOD) x -= MOD;
 	while(x < 0) x += MOD;
 	return x;
}

int mul(int x, int y)
{
 	return (x * 1ll * y) % MOD;
}

int n;
string s;
int dp[N][K][K];
char buf[N];
int pow3[N];

int main() {
	scanf("%d", &n);
	scanf("%s", buf);
	s = buf;
	int cntQ = 0;
	for(auto c : s)
		if(c == '?')
			cntQ++;
	pow3[0] = 1;
	for(int i = 1; i < N; i++)
		pow3[i] = mul(pow3[i - 1], 3);
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= 3; j++)
			for(int k = 0; k <= 3; k++)
			{
			 	if(!dp[i][j][k]) continue;
			 	dp[i + 1][j][k] = add(dp[i + 1][j][k], dp[i][j][k]);
			 	if(j < 3 && (s[i] == '?' || s[i] - 'a' == j))
			 	{
			 	 	int nk = (s[i] == '?' ? k + 1 : k);
			 	 	dp[i + 1][j + 1][nk] = add(dp[i + 1][j + 1][nk], dp[i][j][k]);
			 	}
		   	}
	int ans = 0;
	for(int i = 0; i <= 3; i++)
		if(cntQ >= i)
			ans = add(ans, mul(dp[n][3][i], pow3[cntQ - i]));
	printf("%dn", ans);
}
```
