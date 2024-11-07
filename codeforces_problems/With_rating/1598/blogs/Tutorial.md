# Tutorial

[1598A - Computer Game](../problems/A._Computer_Game.md "Educational Codeforces Round 115 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1598A - Computer Game](../problems/A._Computer_Game.md "Educational Codeforces Round 115 (Rated for Div. 2)")

At first glance, it seems like a graph problem. And indeed, this problem can be solved by explicitly building a graph considering cells as the vertices and checking that there is a safe path from start to finish via DFS/BFS/DSU/any other graph algorithm or data structure you know. But there's a much simpler solution.

Since there are only two rows in a matrix, it's possible to move from any cell in the column i to any cell in column i+1 (if they are both safe, of course). It means that as long as there is at least one safe cell in each column, it is possible to reach any column of the matrix (and the cell (2,n) as well).

It's easy to see that if this condition is not met, there exists a column with two unsafe cells — and this also means that this column and columns to the right of it are unreachable. So, the problem is reduced to checking if there is a column without any unsafe cells. To implement this, you can read both rows of the matrix as strings (let these strings be s1 and s2) and check that there is a position i such that both s1[i] and s2[i] are equal to 1.

 **Solution (BledDest)**
```cpp
def solve():
	n = int(input())
	s1 = input()
	s2 = input()
	bad = False
	for i in range(n):
		bad |= s1[i] == '1' and s2[i] == '1'
	if bad:
		print('NO')
	else:
		print('YES')

t = int(input())
for i in range(t):
	solve()
```
[1598B - Groups](../problems/B._Groups.md "Educational Codeforces Round 115 (Rated for Div. 2)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1598B - Groups](../problems/B._Groups.md "Educational Codeforces Round 115 (Rated for Div. 2)")

Since there are only five days, we can iterate over the two of them that will be the answer.

Now we have fixed a pair of days a and b and want to check if it can be the answer.

All students can be divided into four groups: marked neither of days a and b, marked only day a, marked only day b and marked both days.

Obviously, if the first group is non-empty, days a and b can't be the answer.

Let's call the number of students, who only marked day a, cnta and the number of students, who only marked day b, cntb.

If either of cnta or cntb exceed n2, then days a and b can't be the answer as well. Otherwise, we can always choose n2−cnta students from the ones who marked both days and send them to day a. The rest of the students can go to day b.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    a = [[] for i in range(n)]
    for j in range(n):
        a[j] = list(map(int, input().split()))
    ans = False
    for j in range(5):
        for k in range(5):
            if k != j:
                cnt1 = 0
                cnt2 = 0
                cntno = 0
                for z in range(n):
                    if a[z][j] == 1:
                        cnt1 += 1
                    if a[z][k] == 1:
                        cnt2 += 1
                    if a[z][j] == 0 and a[z][k] == 0:
                        cntno += 1
                if cnt1 >= n // 2 and cnt2 >= n // 2 and cntno == 0:
                    ans = True
    if ans:
        print('YES')
    else:
        print('NO')
```
[1598C - Delete Two Elements](../problems/C._Delete_Two_Elements.md "Educational Codeforces Round 115 (Rated for Div. 2)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1598C - Delete Two Elements](../problems/C._Delete_Two_Elements.md "Educational Codeforces Round 115 (Rated for Div. 2)")

First of all, instead of the mathematic mean, let's consider the sum of elements. If the mathematic mean is k, then the sum of elements of the array is k⋅n. Let's denote the sum of elements in the original array as s. Note s is always an integer.

If we remove two elements from the array, the resulting sum of elements should become k⋅(n−2)=s⋅(n−2)n. So, the sum of the elements we remove should be exactly 2sn.

If 2sn is not an integer, the answer is 0 (to check that, you can simply compare (2s)modn with 0). Otherwise, we have to find the number of pairs (i,j) such that i<j and ai+aj=2sn. This is a well-known problem.

To solve it, you can calculate the number of occurrences of each element and store it in some associative data structure (for example, map in C++). Let cntx be the number of occurrences of element x. Then, you should iterate on the element ai you want to remove and check how many elements match it, that is, how many elements give exactly 2sn if you add ai to them. The number of these elements is just cnt2sn−ai. Let's sum up all these values for every element in the array.

Unfortunately, this sum is not the answer yet. We need to take care of two things:

* if for some index i, 2⋅ai=2sn, then ai matches itself, so you have to subtract the number of such elements from the answer;
* every pair of elements is counted twice: the first time when we consider the first element of the pair, and the second time — when we consider the second element of the pair. So, don't forget to divide the answer by 2.
 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int, int> cnt;
    for (auto &x : a) {
      scanf("%d", &x);
      cnt[x] += 1;
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if ((2 * sum) % n != 0) {
      puts("0");
      continue;
    }
    long long need = (2 * sum) / n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int a1 = a[i];
      int a2 = need - a1;
      if (cnt.count(a2)) ans += cnt[a2];
      if (a1 == a2) ans -= 1;
    }
    printf("%lldn", ans / 2);
  }
}
```
[1598D - Training Session](../problems/D._Training_Session.md "Educational Codeforces Round 115 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1598D - Training Session](../problems/D._Training_Session.md "Educational Codeforces Round 115 (Rated for Div. 2)")

There are many different ways to solve this problem, but, in my opinion, the easiest one is to count all possible triples and subtract the number of bad triples.

The first part is easy — the number of ways to choose 3 elements out of n is just n⋅(n−1)⋅(n−2)6. The second part is a bit tricky.

What does it mean that the conditions in the statements are not fulfilled? There is a pair of problems with equal difficulty, and there is a pair of problems with the same topic. Since all problems in the input are different, it means that every bad triple has the following form: [(xa,ya),(xb,ya),(xa,yb)] — i. e. there exists a problem such that it shares the difficulty with one of the other two problems, and the topic with the remaining problem of the triple.

This observation allows us to calculate the number of bad triples as follows: we will iterate on the "central" problem (the one that shares the topic with the second problem and the difficulty with the third problem). If we pick (xa,ya) as the "central" problem, we need to choose the other two. Counting ways to choose the other problems is easy if we precalculate the number of problems for each topic/difficulty: let cntTx be the number of problems with topic x, and cntDy be the number of problems with difficulty y; then, if we pick the problem (x,y) as the "central one", there are cntTx−1 ways to choose a problem that shares the topic with it, and cntDy−1 ways to choose a problem that has the same difficulty — so, we have to subtract (cntTx−1)(cntDy−1) from the answer for every problem (x,y).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), ca(n + 1), cb(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      ca[a[i]]++; cb[b[i]]++;
    }
    long long ans = n * 1LL * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; ++i) 
      ans -= (ca[a[i]] - 1) * 1LL * (cb[b[i]] - 1);
    cout << ans << 'n';
  }
} 
```
[1598E - Staircases](../problems/E._Staircases.md "Educational Codeforces Round 115 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1598E - Staircases](../problems/E._Staircases.md "Educational Codeforces Round 115 (Rated for Div. 2)")

The solution consist of two main parts: calculate the initial number of staircases and recalculate the number of staircases on query.

The constraints were pretty loose, so we'll do the first part in O(nm) and the second part in O(n+m) per query.

However, it's worth mentioning that faster is possible. The first part can surely be done in O(n+m) and can probably be done in O(1). The second part can be done in O(logn) per query.

It's important to notice is that the only staircase that satisfy the requirements for both types is the staircase that consists of a single cell. Thus, staircases of both types can be calculated almost separately.

Let's define "base" staircases as the staircases that can't be prolonged further in any direction. There are O(n+m) of them on the grid.

If a staircase consists of at least two cells, it's a part of exactly one base staircase. At the same time, every segment of a base staircase is a valid staircase by itself.

Thus, the main idea of calculating the initial answer is the following. Isolate each base staircase and determine its length len (possibly, in O(n+m)). Add \binom{len-1}{2} (the number of segments of length at least 2) to the answer. Add extra nm one cell staircases afterwards.

If you draw the base staircases on the grid, you can easily determine their starting cell. The base staircases, that start by going one cell to the right, start from the first row. The base staircases, that start by going one cell to the bottom, start from the first column. Notice that both types can start from cell (1, 1).

The updates can be handled the following way. The answer always changes by the number of staircases that pass through cell (x, y) (if you ignore its state). If the cell becomes free, then these staircases are added to the answer. Otherwise, they are subtracted from it.

That can be calculated for two cases as well. Go first down, then right, as far as possible. Let it be cnt_1 steps. Go first left, then up, as far as possible. Let it be cnt_2 steps. Then cnt_1 \cdot cnt_2 staircases are added to the answer. Then change the order of steps in both directions to calculate the other type of staircases. Beware of one cell staircases again.

To achieve O(n + m) for precalc, you can calculate the length of each base staircase with a formula. To achieve O(\log n) per query, you can first enumerate cells in each base staircase separately, then maintain the set of segments of adjacent free cells in it.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	vector<vector<int>> a(n, vector<int>(m, 1));
	long long ans = 0;
	forn(x, n) forn(y, m){
		if (x == 0){
			for (int k = 1;; ++k){
				int nx = x + k / 2;
				int ny = y + (k + 1) / 2;
				if (nx == n || ny == m) break;
				ans += k;
			}
		}
		if (y == 0){
			for (int k = 1;; ++k){
				int nx = x + (k + 1) / 2;
				int ny = y + k / 2;
				if (nx == n || ny == m) break;
				ans += k;
			}
		}
	}
	ans += n * m;
	forn(i, q){
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		forn(c, 2){
			int l = 1, r = 1;
			while (true){
				int nx = x + (l + c) / 2;
				int ny = y + (l + !c) / 2;
				if (nx == n || ny == m || a[nx][ny] == 0) break;
				++l;
			}
			while (true){
				int nx = x - (r + !c) / 2;
				int ny = y - (r + c) / 2;
				if (nx < 0 || ny < 0 || a[nx][ny] == 0) break;
				++r;
			}
			if (a[x][y] == 0){
				ans += l * r;
			}
			else{
				ans -= l * r;
			}
		}
		ans += a[x][y];
		a[x][y] ^= 1;
		ans -= a[x][y];
		printf("%lldn", ans);
	}
}
```
[1598F - RBS](../problems/F._RBS.md "Educational Codeforces Round 115 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1598F - RBS](../problems/F._RBS.md "Educational Codeforces Round 115 (Rated for Div. 2)")

The constraint n \le 20 is a clear hint that we need some exponential solution. Of course, we cannot try all n! permutations. Let's instead try to design a solution with bitmask dynamic programming.

A string is an RBS if its balance (the difference between the number of opening and closing brackets) is 0, and the balance of its each prefix is non-negative. So, let's introduce the following dynamic programming: dp_{m,b,f} is the greatest number of RBS-prefixes of a string if we considered a mask m of strings s_i, the current balance of the prefix is b, and f is a flag that denotes whether there already has been a prefix with negative balance. We can already get rid of one of the states: the current balance is uniquely determined by the mask m. So, this dynamic programming will have O(2^{n+1}) states.

To perform transitions, we need to find a way to recalculate the value of f and the answer if we append a new string at the end of the current one. Unfortunately, it's too slow to simply simulate the process. Instead, for every string s_i, let's precalculate the value go(s_i, f, x) — how does the flag and the answer change, if the current flag is f, and the current balance is x.

The resulting flag will be true in one of the following two cases: 

* it is already true;
* the string we append creates a new prefix with non-positive balance.

The second case can be checked as follows: let's precalculate the minimum balance of a prefix of s_i; let it be c. If x + c < 0, the flag will be true.

Calculating how the answer changes is a bit trickier. If the current flag is already true, the answer doesn't change. But if it is false, the answer will increase by the number of new RBS-prefixes. If the balance before adding the string s_i is b, then we get a new RBS-prefix for every prefix of s_i such that:

* its balance is exactly (-b) (to compensate the balance we already have);
* there is no prefix with balance (-b-1) in s_i before this prefix.

To quickly get the number of prefixes meeting these constraints, we can create a data structure that stores the following information: for every balance j, store a sorted vector of positions in s_i with balance equal to j. Then, to calculate the number of prefixes meeting the constraints, we can find the first position in s_i with balance equal to (-b-1) by looking at the beginning of the vector for (-b-1), and then get the number of elements less than this one from the vector for balance (-b) by binary search.

These optimizations yield a solution in O(2^n \log A + A \log A), although it's possible to improve to O(2^n + A \log A) if you precalculate each value of go(s_i, f, x) for every string s_i. 

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int INF = int(1e9);

const int N = 20;
const int M = (1 << N);

struct BracketSeqn
{
 	int balance;
 	int lowestBalance;
 	vector<int> queryAns;

 	pair<int, bool> go(int x, bool f)
 	{
     	if(f)
     		return make_pair(0, true);
       	else
       		return make_pair(x < queryAns.size() ? queryAns[x] : 0, x + lowestBalance < 0);
    }

	BracketSeqn() {};
	BracketSeqn(string s)
	{
		vector<int> bal;
		int cur = 0;
		int n = s.size();
		for(auto x : s)
		{
		 	if(x == '(')
		 		cur++;
		 	else	
		 		cur--;
		 	bal.push_back(cur);	
		}
		balance = bal.back();
		lowestBalance = min(0, *min_element(bal.begin(), bal.end()));
		vector<vector<int>> negPos(-lowestBalance + 1);
		for(int i = 0; i < n; i++)
		{
		 	if(bal[i] > 0) continue;
		 	negPos[-bal[i]].push_back(i);
		}
		queryAns.resize(-lowestBalance + 1);
		for(int i = 0; i < queryAns.size(); i++)
		{
		 	int lastPos = int(1e9);
		 	if(i != -lowestBalance)
		 		lastPos = negPos[i + 1][0];
		 	queryAns[i] = lower_bound(negPos[i].begin(), negPos[i].end(), lastPos) - negPos[i].begin();
		}
	};
};

int dp[M][2];
char buf[M];
int total_bal[M];

int main()
{
	int n;
	scanf("%d", &n);
	vector<BracketSeqn> bs;
	for(int i = 0; i < n; i++)
	{
	 	scanf("%s", buf);
	 	string s = buf;
	 	bs.push_back(BracketSeqn(s));
	}
	for(int i = 0; i < (1 << n); i++)               
	 	for(int j = 0; j < n; j++)
	 		if(i & (1 << j))
	 			total_bal[i] += bs[j].balance;
	for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j < 2; j++)
			dp[i][j] = -int(1e9);
	dp[0][0] = 0;
	for(int i = 0; i < (1 << n); i++)
		for(int f = 0; f < 2; f++)
		{
		 	if(dp[i][f] < 0) continue;
		 	for(int k = 0; k < n; k++)
		 	{
		 	 	if(i & (1 << k)) continue;
		 	 	pair<int, bool> res = bs[k].go(total_bal[i], f);
		 	 	dp[i ^ (1 << k)][res.second] = max(dp[i ^ (1 << k)][res.second], dp[i][f] + res.first);
		 	}
		}
	printf("%dn", max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]));
}
```
[1598G - The Sum of Good Numbers](../problems/G._The_Sum_of_Good_Numbers.md "Educational Codeforces Round 115 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1598G - The Sum of Good Numbers](../problems/G._The_Sum_of_Good_Numbers.md "Educational Codeforces Round 115 (Rated for Div. 2)")

Let's denote a as the largest of the terms of the sum, and b is the smaller one.

Consider 2 cases: |a| =|x| - 1 or |a|=|x|.

If |a| =|x| - 1, then |b| =|x| - 1. So we need to find two consecutive substrings of length |x| - 1 such that if we convert these substrings into integers, their sum is equal to x.

If |a| = |x|, let \mathit{lcp} be the largest common prefix of a and x if we consider them as strings. Then |b| = |x| - \mathit{lcp} or |b| =|x| - \mathit{lcp} - 1. So it is necessary to check only these two cases, and whether b goes before or after a (in the string s).

Thus, we have reduced the number of variants where the substrings for a and b are located to O(n). It remains to consider how to quickly check whether the selected substrings are suitable. To do this, you can use hashes (preferably with several random modules).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int MOD[] = { 597804841, 618557587, 998244353 };
const int N = 500 * 1000 + 13;
const int K = 3;

using hs = array<int, K>;

int add(int x, int y, int mod) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
  return x;
}

int mul(int x, int y, int mod) {
  return x * 1LL * y % mod;
}

hs get(const int& x) {
  hs c;
  forn(i, K) c[i] = x;
  return c;
}

hs operator +(const hs& a, const hs& b) { 
  hs c;
  forn(i, K) c[i] = add(a[i], b[i], MOD[i]);
  return c;
}

hs operator -(const hs& a, const hs& b) {
  hs c;
  forn(i, K) c[i] = add(a[i], -b[i], MOD[i]);
  return c; 
}

hs operator *(const hs& a, const hs& b) {
  hs c;
  forn(i, K) c[i] = mul(a[i], b[i], MOD[i]);
  return c; 
}

int n, m;
string s, sx;
hs sum[N], pw[N];

hs get(int l, int r) {
  return sum[r] - sum[l] * pw[r - l];
}

vector<int> zfunction(const string& s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  
  cin >> s >> sx;
  n = s.size();
  m = sx.size();
  
  pw[0] = get(1);
  forn(i, N - 1) pw[i + 1] = pw[i] * get(10); 
  sum[0] = get(0);
  forn(i, n) sum[i + 1] = sum[i] * get(10) + get(s[i] - '0'); 
  hs x = get(0);
  forn(i, m) x = x * get(10) + get(sx[i] - '0');
  
  if (m > 1) for (int i = 0; i + 2 * (m - 1) <= n; ++i) {
    if (get(i, i + m - 1) + get(i + m - 1, i + 2 * (m - 1)) == x) {
      cout << i + 1 << ' ' << i + m - 1 << 'n';
      cout << i + m << ' ' << i + 2 * (m - 1) << 'n';
      return 0;
    }
  }
  
  auto z = zfunction(sx + "#" + s);
  
  for (int i = 0; i + m <= n; ++i) {
    int lcp = z[m + i + 1];
    for (int len = m - lcp - 1; len <= m - lcp; ++len) {
      if (len < 1) continue;
      if (i + m + len <= n && get(i, i + m) + get(i + m, i + m + len) == x) {
        cout << i + 1 << ' ' << i + m << 'n';
        cout << i + m + 1 << ' ' << i + m + len << 'n';
        return 0;
      }
      if (i >= len && get(i - len, i) + get(i, i + m) == x) {
        cout << i - len + 1 << ' ' << i << 'n';
        cout << i + 1 << ' ' << i + m << 'n';
        return 0;
      }
    }
  }
  
  assert(false);
}
```
