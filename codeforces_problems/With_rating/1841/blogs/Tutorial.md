# Tutorial

[1841A - Game with Board](../problems/A._Game_with_Board.md "Educational Codeforces Round 150 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1841A - Game with Board](../problems/A._Game_with_Board.md "Educational Codeforces Round 150 (Rated for Div. 2)")

Let's try to find a winning strategy for Alice. We can force Bob into a situation where his only action will be to make a move that leaves Alice without any legal moves, so she will win. For example, Alice can start by merging $n-2$ ones, so the board will be $\{1, 1, n-2\}$ after her move. The only possible move for Bob is to merge the remaining $1$'s, and the board becomes $\{2, n-2\}$, and Alice wins.

Unfortunately, this works only for $n \ge 5$. Cases $n=2$, $n=3$, $n=4$ should be analyzed separately:

* if $n=2$, the only possible first move for Alice is to merge two $1$'s, and the board becomes $\{2\}$, so Bob wins;
* if $n=3$, Alice can transform the board either to $\{3\}$ or to $\{1,2\}$; in both cases, Bob instantly wins;
* if $n=4$, Alice can transform the board to $\{4\}$, $\{1,3\}$, or $\{1,1,2\}$. In the first two cases, Bob instantly wins. In the third case, the only possible response for Bob is to merge two $1$'s; the board becomes $\{2,2\}$. It's easy to see that after the only possible move for Alice, the board becomes $\{4\}$, and Bob wins.

So, when $n \ge 5$, Alice wins, and when $n \le 4$, Bob wins.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    print('Alice' if n >= 5 else 'Bob')
```
[1841B - Keep it Beautiful](../problems/B._Keep_it_Beautiful.md "Educational Codeforces Round 150 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1841B - Keep it Beautiful](../problems/B._Keep_it_Beautiful.md "Educational Codeforces Round 150 (Rated for Div. 2)")

First, notice that the given operation is a cyclic shift of the array. So we can treat the array as cyclic, meaning element $n$ is a neighbor of element $1$.

Let's try to rephrase the condition for the beautiful array. What does it mean for the array to be sorted? For all $j$ from $1$ to $n-1$, $a_j \le a_{j+1}$ should hold. If they do, then you can choose $i=0$ (leave the array as is).

What if there are such $j$ that $a_j > a_{j+1}$? If there is only one such $j$, then we might still be able to fix the array: choose $i = j$. However, that will make a pair $a_n$ and $a_1$ cyclically shift into the array. So $a_n \le a_1$ should hold.

If there are at least two such $j$ or just one but $a_n > a_1$, then we can show that it's impossible to make the array sorted. Since there are at least two pairs of neighboring elements that are not sorted, at least one of them will still be in the array after any cyclic shift.

Thus, we can maintain the number of such $j$ that $a_j > a_{j+1}$ and check if $a_n > a_1$ every time if the count is exactly $1$.

Overall complexity: $O(q)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	q = int(input())
	a = []
	cnt = 0
	for x in map(int, input().split()):
		nw_cnt = cnt + (len(a) > 0 and a[-1] > x)
		if nw_cnt == 0 or (nw_cnt == 1 and x <= a[0]):
			a.append(x)
			cnt = nw_cnt
			print('1', end="")
		else:
			print('0', end="")
	print()
```
[1841C - Ranom Numbers](../problems/C._Ranom_Numbers.md "Educational Codeforces Round 150 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1841C - Ranom Numbers](../problems/C._Ranom_Numbers.md "Educational Codeforces Round 150 (Rated for Div. 2)")

There are two main solutions to this problem: dynamic programming and greedy.

DP approach

Reverse the string we were given, so that the sign of each digit depends on the maximum digit to the left of it (not to the right). Then, run the following dynamic programming: $dp_{i,j,k}$ is the maximum value of the number if we considered $i$ first characters, applied $k$ changes to them ($k$ is either $0$ or $1$), and the maximum character we encountered so far was $j$ ($j$ can have $5$ possible values). The transitions are fairly simple: when we consider the state $dp_{i,j,k}$, we can either leave the current character as it is, or, if $k = 0$, iterate on the replacement for the current character and use the replacement instead (then we go to the state with $k=1$). Note that this solution can also work if we can make more than one operation. This dynamic programming has $O(n \cdot A \cdot m)$ states (where $A$ is the number of different characters, and $m$ is the maximum number of changes we can make), and each state has no more than $A+1$ outgoing transitions. In this problem, $A = 5$ and $m = 1$, so this solution easily passes.

Greedy approach

Of course, we can try to iterate on every character and check all possible replacements for it, but quickly calculating the answer after replacement can be a bit difficult. Instead, we claim the following: it is optimal to consider at most $10$ positions to replace — the first and the last position of A, the first and the last position of B, and so on. That way, we have only $50$ different candidates for the answer, and we can check each of them in $O(n)$.

How to prove that this is enough? When we replace a character, we either increase or decrease it. If we increase a character, it's easy to see why it's optimal to try only the first occurrence of each character — increasing a character may affect some characters to the left of it (turn them from positive to negative), and by picking the first occurrence of a character, we make sure that the number of characters transformed from positive to negative is as small as possible. Note that if the string has at least one character different from E, we can replace the first such character with E and increase the answer by at least $9000$ (this will be useful in the second part of the proof).

Now suppose it's optimal to decrease a character, let's show that it's always optimal to choose the last occurrence of a character to decrease. Suppose we decreased a character, and it was not the last occurrence. This means that this character will be negative after replacement, so it should be negative before the replacement. The maximum value we can add to the answer by replacing a negative character with another negative character is $999$ (changing negative D to negative A), and we have already shown that we can add at least $9000$ by replacing the first non-E character in the string with E. So, if we decrease a character and it was not the last occurrence of that character, it's suboptimal.

 **Solution 1 (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int val[] = {1, 10, 100, 1000, 10000};
const int INF = 1e9;

string s;
int dp[2][5][2];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    reverse(s.begin(), s.end());
    for (int j = 0; j < 5; ++j)
      dp[0][j][0] = dp[0][j][1] = -INF;
    dp[0][0][0] = 0;
    for (auto c : s) {
      int x = c - 'A';
      for (int j = 0; j < 5; ++j)
        dp[1][j][0] = dp[1][j][1] = -INF;
      for (int j = 0; j < 5; ++j) {
      	for (int t = 0; t < 2; ++t) {
      	  for (int y = 0; y < 5; ++y) {
      	  	int nj = max(j, y);
      	  	int nt = t + (x != y);
      	  	if (nt < 2) dp[1][nj][nt] = max(dp[1][nj][nt], dp[0][j][t] + (y < nj ? -val[y] : val[y]));
      	  }	
      	}
      }
      swap(dp[0], dp[1]);
    }
    int ans = -INF;
    for (int j = 0; j < 5; ++j)
      ans = max(ans, max(dp[0][j][0], dp[0][j][1]));
    cout << ans << 'n';
  }
}
```
 **Solution 2 (BledDest)**
```cpp
def replace_char(s, i, c):
    return s[:i] + c + s[i + 1:]
    
def id(c):
    return ord(c) - ord('A')
    
def evaluate(s):
    t = s[::-1]
    ans = 0
    max_id = -1
    for x in t:
        i = id(x)
        if max_id > i:
            ans -= 10 ** i
        else:
            ans += 10 ** i
        max_id = max(max_id, i)
    return ans

t = int(input())
for i in range(t):
    s = input()
    candidates = []
    for x in ['A', 'B', 'C', 'D', 'E']:
        for y in ['A', 'B', 'C', 'D', 'E']:
            if not (x in s):
                continue
            candidates.append(replace_char(s, s.find(x), y))
            candidates.append(replace_char(s, s.rfind(x), y))
    print(max(map(evaluate, candidates)))
```
[1841D - Pairs of Segments](../problems/D._Pairs_of_Segments.md "Educational Codeforces Round 150 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1841D - Pairs of Segments](../problems/D._Pairs_of_Segments.md "Educational Codeforces Round 150 (Rated for Div. 2)")

The resulting array should consist of pairs of intersecting segments, and no segments from different pairs should intersect.

Let's suppose that segments $[l_1, r_1]$ and $[l_2, r_2]$ intersect, and segments $[l_3, r_3]$ and $[l_4, r_4]$ intersect. How to check that no other pair of these four segments intersects? Instead of pairs of segments, let's work with the union of segments in each pair; no point should belong to more than one of these unions. Since segments $[l_1, r_1]$ and $[l_2, r_2]$ intersect, their union is also a segment, and its endpoints are $[\min(l_1, l_2), \max(r_1, r_2)]$. So, if we transform each pair into a union, then the union-segments we got should not intersect.

Thus, we can solve the problem as follows: for each pair of intersecting segments in the input, generate their union segment, and pick the maximum number of unions we can (these unions represent the pairs in the answer). It's quite easy to see that we won't pick a segment in two pairs simultaneously (the corresponding unions will intersect).

Okay, now we have $O(n^2)$ union segments, how to pick the maximum number of them without having an intersection? This is a somewhat classical problem, there are many methods to solve it. The one used in the model solution is a greedy algorithm: sort the union segments according to their right border (in non-descending order), and pick segments greedily in sorted order, maintaining the right border of the last segment we picked. If the union segment we consider is fully after the right border of the last union we picked, then we add it to the answer; otherwise, we skip it. This approach works in $O(n^2 \log n)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

void solve()
{
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> s(n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &s[i].first, &s[i].second);
	
	vector<pair<int, int>> pairs;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(max(s[i].first, s[j].first) <= min(s[i].second, s[j].second))
				pairs.push_back(make_pair(min(s[i].first, s[j].first), max(s[i].second, s[j].second)));
			
	int cnt_pairs = 0;
	sort(pairs.begin(), pairs.end(), comp);
	int last_pos = -1;
	for(auto x : pairs)
		if(x.first > last_pos)
		{
			cnt_pairs++;
			last_pos = x.second;
		}
		
	printf("%dn", n - cnt_pairs * 2);
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) solve();
}
```
[1841E - Fill the Matrix](../problems/E._Fill_the_Matrix.md "Educational Codeforces Round 150 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1841E - Fill the Matrix](../problems/E._Fill_the_Matrix.md "Educational Codeforces Round 150 (Rated for Div. 2)")

Notice that the rows of the matrix are basically independent. When we fill the matrix with integers, the values from the rows are just added together. Moreover, in a single row, the segments of white cells separated by black cells are also independent in the same way.

And how to solve the problem for one segment of white cells? Obviously, put the numbers one after another. Placing a non-zero amount of integers $k$ will yield the result of $k-1$. Thus, the answer is $\sum_\limits{i=1}^s k_i - 1$, where $s$ is the number of used segments. We know that the sum of $k_i$ is just $m$. So it becomes $m + \sum_\limits{i=1}^s -1 = m - s$. So, the problem asks us to minimize the number of used segments.

In order to use the smallest number of segments, we should pick the longest ones. We only have to find them.

In the worst case, there are $O(n^2)$ segments of white cells in the matrix. However, we can store them in a compressed form. Since their lengths are from $1$ to $n$, we can calculate how many segments of each length there are.

Look at the matrix from the bottom to the top. First, there are some fully white rows. Then some black cell appears and splits the segment of length $n$ into two segments. Maybe more if there are more black cells in that row. After that the split segments behave independently of each other.

Let's record these intervals of rows each segment exists at. So, let some segment exist from row $l$ to row $r$. What does that mean? This segment appeared because of some split at row $r$. At row $l$, some black cell appeared that split the segment in parts. If we knew the $r$ for the segment, we could've saved the information about it during the event at row $l$.

So, we need a data structure that can support the following operations: 

* find a segment that covers cell $x$;
* erase a segment;
* insert a segment.

Additionally, that data structure should store a value associated with a segment. Thus, let's use a map. For a segment, which is a pair of integers, store another integer — the bottommost row this segment exists.

Make events $(a_i, i)$ for each column $i$. Sort them and process in a non-increasing order. During the processing of the event, find the segment this black cell splits. Save the information about this segment. Then remove it and add two new segments (or less if some are empty): the one to the left and the one to the right.

At the end, for each length from $1$ to $n$, we will have the number of segments of such length. In order to fill them with $m$ integers, start with the longest segments and use as many of each length as possible. So, while having $m$ more integers to place and $\mathit{cnt}$ segments of length $\mathit{len}$, you can use $\min(\lfloor \frac{m}{\mathit{len}} \rfloor, cnt)$ of segments. 

Overall complexity: $O(n \log n)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct seg{
	int l, r;
};

bool operator <(const seg &a, const seg &b){
	return a.l < b.l;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		forn(i, n) scanf("%d", &a[i]);
		long long m;
		scanf("%lld", &m);
		map<seg, int> used;
		used[{0, n}] = n;
		vector<int> ord(n);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&a](int x, int y){
			return a[x] > a[y];
		});
		long long ans = 0;
		int j = 0;
		vector<long long> cnt(n + 1);
		for (int i = n; i >= 0; --i){
			while (j < n && a[ord[j]] >= i){
				auto it = used.upper_bound({ord[j], -1});
				--it;
				auto tmp = it->first;
				cnt[tmp.r - tmp.l] += it->second - i;
				used.erase(it);
				if (tmp.l != ord[j])
					used[{tmp.l, ord[j]}] = i;
				if (tmp.r != ord[j] + 1)
					used[{ord[j] + 1, tmp.r}] = i;
				++j;
			}
		}
		for (int i = n; i > 0; --i){
			long long t = min(cnt[i], m / i);
			ans += t * 1ll * (i - 1);
			m -= t * 1ll * i;
			if (t != cnt[i] && m > 0){
				ans += m - 1;
				m = 0;
			}
		}
		printf("%lldn", ans);
	}
	return 0;
}
```
[1841F - Monocarp and a Strategic Game](../problems/F._Monocarp_and_a_Strategic_Game.md "Educational Codeforces Round 150 (Rated for Div. 2)")

Idea: [TheWayISteppedOutTheCar](https://codeforces.com/profile/TheWayISteppedOutTheCar "Grandmaster TheWayISteppedOutTheCar") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1841F - Monocarp and a Strategic Game](../problems/F._Monocarp_and_a_Strategic_Game.md "Educational Codeforces Round 150 (Rated for Div. 2)")

Let's denote $a, b, c, d$ as the total number of humans, orcs, elves, and dwarves taken respectively. We calculate the contribution of humans and orcs to the final score. It will be $a(a-1) + b(b-1) - 2ab + a + b$, where $a(a-1) + b(b-1)$ is the contribution to the total happiness (and thus to the final score) for an increase of $1$ happiness point per inhabitant of the same race, $-2ab$ is the contribution to the total happiness decrease by $1$ point for each inhabitant of the hostile race, and the last two terms $a + b$ is the total number of humans and orcs, which contributes to the total score. Notice that $a(a-1) + b(b-1) - 2ab + a + b = (a-b)^2$.

Similarly for the contribution of elves and dwarves. So we need to maximize the expression $(a-b)^2+(c-d)^2$. Let's say we have $n$ vectors, the $i$-th of which is equal to $(x_i; y_i) = (a_i - b_i; c_i - d_i)$. Then note that we want to select some subset of vectors among the $n$ vectors $(x_i; y_i)$, a subset $A$ such that the value of the function $x^2+y^2$ is maximum for the vector $(x, y)$ equal to the sum of the vectors of subset $A$.

For each subset of vectors, we get a vector equal to the sum of the elements of the subset (vectors), let's denote the set of all such vectors as $S$.

Then consider the $n$ line segments at the vertices $(0; 0)$ and $(x_i; y_i)$ and calculate their Minkowski sum. We get a convex polygon. Notice that all elements of $S$ are in it by the definition of the Minkowski sum. Also, each vertex of the resulting convex polygon is in $S$, which is also known from the properties of the sum. Note that due to the upward convexity of the function we want to maximize, it is enough for us to only consider the vertices of the resulting polygon, not all vectors from $S$.

Thus, using a standard algorithm for calculating the Minkowski sum, we obtain the polygon of interest and calculate the values of the function at its vertices. We take the maximum from them. The total asymptotic time complexity is $O(n\ln{n})$.

 **Solution (TheWayISteppedOutTheCar)**
```cpp
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define x first
#define y second
const int MAXN = 2e6 + 16;
int a[MAXN], b[MAXN];
pair<int, int> v[MAXN];
int section(pair<int, int> a) {
    if (a.x > 0 && a.y >= 0)
        return 0;
    else if (a.x <= 0 && a.y > 0)
        return 1;
    else if (a.x < 0 && a.y <= 0)
        return 2;
    else
        return 3;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (section(a) != section(b))
        return section(a) < section(b);
    else
        return (__int128)a.x * (__int128)b.y - (__int128)a.y * (__int128)b.x > 0;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
signed main() {
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
		vector<int> t(4);
		for(int j = 0; j < 4; j++)
			cin >> t[j];
		a[i] = t[0] - t[1];
		b[i] = t[2] - t[3];
	}
    int it = 0;
    __int128 sx = 0, sy = 0;
    for (int i = 0; i < n; ++i) {
        v[i << 1].x = a[it];
        v[i << 1].y = b[it];
        ++it;
        v[i << 1 ^ 1].x = -v[i << 1].x;
        v[i << 1 ^ 1].y = -v[i << 1].y;
        if (!v[i << 1].x && !v[i << 1].y) {
            --i, --n;
            continue;
        }
        if (v[i << 1].y < 0 || (!v[i << 1].y && v[i << 1].x < 0))
            sx += v[i << 1].x, sy += v[i << 1].y;
    }
    sort(v, v + 2 * n, cmp);
    __int128 ans = sx * sx + sy * sy;
    for (int i = 0; i < 2 * n; ++i) {
        sx += v[i].x;
        sy += v[i].y;
        ans = std::max(ans, sx * sx + sy * sy);
    }
    print(ans);

    return 0;
}
```
