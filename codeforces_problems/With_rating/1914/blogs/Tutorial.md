# Tutorial

[1914A - Problemsolving Log](../problems/A._Problemsolving_Log.md "Codeforces Round 916 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1914A - Problemsolving Log](../problems/A._Problemsolving_Log.md "Codeforces Round 916 (Div. 3)")

For each problem, we will calculate the total number of minutes Monocarp spent on it. Then we will compare it to the minimum required time for solving the problem.

One of the possible implementations is as follows. Create a string t="ABC ... Z" in the program. Then problem ti can be solved in i+1 minutes. We can compare s.count(t[i]) to i+1.

We can also use the ASCII table to convert the problem number to a letter. In Python, there are functions chr and ord for this purpose. For example, the letter for the i-th problem is chr(ord('A') + i). In C++, you can directly obtain a char from an int using char('A' + i).

It is also possible to solve this problem in linear time of the length of the string, but it was not required.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    n = int(input())
    s = input()
    print(sum([s.count(chr(ord('A') + i)) >= i + 1 for i in range(26)]))
```
[1914B - Preparing for the Contest](../problems/B._Preparing_for_the_Contest.md "Codeforces Round 916 (Div. 3)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1914B - Preparing for the Contest](../problems/B._Preparing_for_the_Contest.md "Codeforces Round 916 (Div. 3)")

The examples give a pretty big hint to the solution: to get k=0, we have to order all problems from the hardest to the easiest one, and to get k=n−1, we have to order them from the easiest to the hardest problem. Let's try to combine them for the general case.

Let's start by placing the problems from the hardest to the easiest one: [n,n−1,…,2,1]. If k=1, we can just swap two last problems and make solving the last problem exciting. If k=2, we can reverse the order of the last 3 problems, so 2 of them excite Monocarp, and so on; generally, reversing (k+1) last problems ensures that exactly k last problems will excite Monocarp.

There are also other methods to sovle this problem, but this is one of the easiest.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) a[i] = n - i;
	reverse(a.end() - k - 1, a.end());
	for(int i = 0; i < n; i++)
	{
		if(i) cout << " ";
		cout << a[i];
	}
	cout << endl;
}
 
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
		solve();
	return 0;
}
```
[1914C - Quests](../problems/C._Quests.md "Codeforces Round 916 (Div. 3)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1914C - Quests](../problems/C._Quests.md "Codeforces Round 916 (Div. 3)")

Let's iterate over the number of quests that have been completed at least once (denote it as i). It remains to complete k−i quests more, and we are allowed to complete any of the first i quests again. It is obvious that we would like to complete quests with the largest value of bi among the first i of them. So the answer to the problem is the maximum of i∑j=1aj+imaxj=1bj⋅(k−i) over all values of i from 1 to min(n,k). Note that the value of n is too large to calculate sums and maximums in the aforementioned formula every time (for each i independently), so you have to maintain these values as the value for i grows.

 **Solution (Neon)**
```cpp
fun main() = repeat(readLine()!!.toInt()) {
  val (n, k) = readLine()!!.split(" ").map { it.toInt() }
  val a = readLine()!!.split(" ").map { it.toInt() }
  val b = readLine()!!.split(" ").map { it.toInt() }
  var (res, sum, mx) = intArrayOf(0, 0, 0)
  for (i in 0 until minOf(n, k)) {
    sum += a[i]
    mx = maxOf(mx, b[i])
    res = maxOf(res, sum + mx * (k - i - 1))
  }
  println(res)
}
```
[1914D - Three Activities](../problems/D._Three_Activities.md "Codeforces Round 916 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1914D - Three Activities](../problems/D._Three_Activities.md "Codeforces Round 916 (Div. 3)")

The main idea of the problem is that almost always you can take the maximum in each array. And when you can't, you don't need to look at a lot of smaller numbers. In particular, it is enough to consider the three largest numbers from each array.

Let's show the correctness of this for the first array. There always exists an optimal answer in which one of the three largest numbers is taken from array a. Let's fix some taken elements in arrays b and c. Then at least one of the three positions of the largest elements in a is different from both fixed position.

The argument is generalized to all three arrays similarly.

Thus, the solution looks as follows. Find the positions of the three maximums in each array and iterate over the answer in 33. Finding three maximums can be done using sorting or in one linear time pass over the array.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	c = list(map(int, input().split()))
	
	def get_best3(a):
		mx1, mx2, mx3 = -1, -1, -1
		for i in range(len(a)):
			if mx1 == -1 or a[i] > a[mx1]:
				mx3 = mx2
				mx2 = mx1
				mx1 = i
			elif mx2 == -1 or a[i] > a[mx2]:
				mx3 = mx2
				mx2 = i
			elif mx3 == -1 or a[i] > a[mx3]:
				mx3 = i
		return (mx1, mx2, mx3)
	
	ans = 0
	for x in get_best3(a):
		for y in get_best3(b):
			for z in get_best3(c):
				if x != y and x != z and y != z:
					ans = max(ans, a[x] + b[y] + c[z])
	print(ans)
```
[1914E1 - Game with Marbles (Easy Version)](../problems/E1._Game_with_Marbles_(Easy_Version).md "Codeforces Round 916 (Div. 3)")

[1914E2 - Game with Marbles (Hard Version)](../problems/E2._Game_with_Marbles_(Hard_Version).md "Codeforces Round 916 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1914E2 - Game with Marbles (Hard Version)](../problems/E2._Game_with_Marbles_(Hard_Version).md "Codeforces Round 916 (Div. 3)")

Let's change the game in the following way: 

* Firstly, we'll let Bob make all moves. It means that for each color i Bob discarded one marble, while Alice discarded all her marbles. So the score S will be equal to 0−∑i(bi−1).
* Alice makes the first move by choosing some color i and "takes back color i". In means that we cancel Bob's move on color i and Alice makes that move instead. How score S will change? Initially, we had −(bi−1) contribution to the score, but now contribution becomes +(ai−1). In other words, choosing color i gives score S′=S+(ai+bi−2). Note that, the greater (ai+bi) the greater S′ becomes.
* Bob makes the second move by "saving some color i", i. e. he forbids Alice to choose color i. It doesn't change score S but now Alice can't choose color i on her turns.
* Alice and Bob continue playing, by "taking" and "saving" colors, until Alice will take all non-forbidden colors.

 The result of the game is score S. Note that this game is equivalent to the initial game, but Alice and Bob strategies much more obvious: each turn Alice should "take" non-prohibited color i with maximum ai+bi. And each turn Bob should "save" non-prohibited color with maximum ai+bi, otherwise Alice will "take" it.As a result, we showed that optimum strategy in the initial game is the same: sort colors by ai+bi in decreasing order. Alice chooses 1-st, 3-rd, 5-th and so on colors, while Bob chooses 2-nd, 4-th, 6-th and so on colors.

The resulting complexity is O(nlogn).

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
 
typedef long long li;
 
// S = sum a_i - sum b_i
// if Bob made all steps: then S = 0 - sum (b_i - 1)
// each Alice step: S += (a_i - 1) + (b_i - 1) i. e. the bigger (a_i + b_i) the better
 
int n;
vector<int> a, b;
 
inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	b.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	fore (i, 0, n)
		cin >> b[i];
	return true;
}
 
inline void solve() {
	vector<int> ids(n);
	iota(ids.begin(), ids.end(), 0);
	
	sort(ids.begin(), ids.end(), [&](int i, int j) {
		return a[i] + b[i] > a[j] + b[j];
	});
	
	li S = 0;
	fore (i, 0, n) {
		if (i & 1)
			S -= b[ids[i]] - 1;
		else
			S += a[ids[i]] - 1;
	}
	cout << S << endl;
}
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
//	ios_base::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	}
	return 0;
}
```
[1914F - Programming Competition](../problems/F._Programming_Competition.md "Codeforces Round 916 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1914F - Programming Competition](../problems/F._Programming_Competition.md "Codeforces Round 916 (Div. 3)")

Note that the problem basically states the following: you are given a rooted tree; you can pair two vertices x and y if neither x is an ancestor of y nor y is an ancestor of x. Each vertex can be used in at most one pair. Calculate the maximum possible number of pairs you can make.

Let's look at subtrees of child nodes of the root. If two vertices belong to different subtrees, we can pair them up. So we can slightly rephrase the problem: given m types of objects, with counts sz1,sz2,…,szm, find the maximum number of pairs that can be formed using objects of different types.

This is a well-known problem with the following solution. Let tot be the total number of objects and mx be the type that has the maximum number of objects (maximum value of sz). If the number of objects of type mx is at most the number of all other objects (i. e. szmx≤tot−szmx), then we can pair all objects (except 1 if the total number of objects is odd). Otherwise, we can create tot−szmx pairs of the form (mx,i) for all i except mx.

Now we can return to the original problem. If the first aforementioned option is met for the root, then we know the answer to the problem is tot2. Otherwise, we can create tot−szmx pairs, but some nodes from the mx-th child's subtree are left unmatched (there are not enough vertices outside that subtree). So we can recursively look at the mx-th child subtree and solve the same problem. The only difference is that some number of vertices from that subtree are already matched. To solve this issue, we can add the parameter k — how many vertices in the current subtree are already matched (we care only about the number of them). From the second paragraph, we know that the best situation (we can pair all objects) appears when the maximum value is at most the number of all other objects. Using this fact, we can say that k matched vertices belong to the mx-th child's subtree. So we have to modify our check formula from szmx≤tot−szmx to szmx−k≤tot−szmx. This process goes on until the current vertex (subtree) is a leaf or the condition is met.

This solution works in O(n) if we precalculate the sizes for all the subtrees with a DFS before running it.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 222222;
 
int n;
int sz[N];
vector<int> g[N];
 
void init(int v) {
  sz[v] = 1;
  for (int u : g[v]) {
    init(u);
    sz[v] += sz[u];
  }
}
 
int calc(int v, int k) {
  int tot = 0, mx = -1;
  for (int u : g[v]) {
    tot += sz[u];
    if (mx == -1 || sz[mx] < sz[u]) mx = u;
  }
  if (tot == 0) return 0;
  if (sz[mx] - k <= tot - sz[mx])
    return (tot - k) / 2;
  int add = tot - sz[mx];
  return add + calc(mx, max(0, k + add - 1));
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
      int p; cin >> p;
      g[p - 1].push_back(i);
    }
    init(0);
    cout << calc(0, 0) << 'n';
  }
}
```
[1914G1 - Light Bulbs (Easy Version)](../problems/G1._Light_Bulbs_(Easy_Version).md "Codeforces Round 916 (Div. 3)")

[1914G2 - Light Bulbs (Hard Version)](../problems/G2._Light_Bulbs_(Hard_Version).md "Codeforces Round 916 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1914G2 - Light Bulbs (Hard Version)](../problems/G2._Light_Bulbs_(Hard_Version).md "Codeforces Round 916 (Div. 3)")

Let's call a contiguous segment of lamps closed if the number of lamps for each color is either 0 or 2 in this segment. For example, a segment of lamps [3,2,1,2,1,3] is closed. Furthermore, let's say that a closed segment of lamps is minimal if it is impossible to split it into multiple closed segments. For example, [3,2,1,2,1,3] is minimal, but [3,3,2,1,2,1] is not since it can be split into [3,3] and [2,1,2,1] (which are closed).

Each closed segment has the following property: if you start with any lamp in this segment, you cannot "leave" this segment; i. e. you cannot use the lamps from this segment to light any lamps outside. To prove this, let's suppose the opposite: we started in the closed segment and managed to turn a lamp of color x outside that segment on (and this was the first lamp outside of the segment we turned on). We could not do it with the operation of the first type, since it would mean that the other lamp of color x is in the segment (so it is not closed); and we could not do it with the operation of the second type, since for every color present in the closed segment, both lamps of that color (and the segment they can light up) belong to the closed segment.

For every minimal closed segment, we can light it up using just one lamp (for example, the first lamp). So, to calculate the minimum possible size of a set of lamps S we initially turn on, we can just split the given sequence of colors into minimal closed segments.

Unfortunately, calculating the number of possible sets of lamps S is trickier. For every minimal closed segment we got, we can calculate the number of "starting" lamps that allow us to light the whole segment, and multiply them. However, not every lamp from a minimal closed segment can be a "starting" lamp: for example, in the segment [3,2,1,2,1,3], any lamp of color 3 can be used, but no lamp of other color can be used.

To deal with this, let us find all minimal closed segments in the sequence of colors. In the example above, we have to find out that both the segments [3,2,1,2,1,3] and [2,1,2,1] are closed; and since lamps of colors 1 and 2 belong to the "inner" closed segment, they cannot be used to light the whole "outer" closed segment. So, if a lamp belongs to any of the "inner" closed segments, it cannot be used as a starting lamp. Let's mark all such lamps.

We can also show that if a lamp is not marked, it can be used as a starting lamp. It is because if we start with some lamp and try to turn on everything we can with the operations given in the statement, we will get precisely the shortest closed segment that lamp belongs to. Proving it is not that hard: suppose we stopped before turning the whole shortest closed segment on; either we got multiple segments of lamps (and we can turn on everything in between them), or we got a segment which is not closed (and for at least one color, there is exactly one lamp in it; so we can light the other lamp of that color).

Okay, let's recap. Our solution consists of the following steps:

* find all minimal closed segments of lamps;
* for every "inner" segment, mark all lamps in it to show they cannot be used as the starting lamps;
* split the given sequence of colors into the minimum number of segments;
* for each segment we got from the split, calculate the number of unmarked lamps and multiply those values.

The most difficult part is finding all minimal closed segments of lamps. To get a solution in something like O(n2), we can do it naively: iterate on the left border of the segment, add the first lamp in the segment, and keep adding next lamps until the number of lamps of each color becomes either 0 or 2. That's how the easy version of the problem is solved.

For the hard version, this is too slow. We have to find the closed segments faster. In order to do this, we can use hashing. Many hashing methods can help, but in my opinion, the most elegant one is XOR hashing, which works as follows:

For each color, generate a random 64-bit integer and replace both occurrences of that color with the generated number. Then, if the segment is closed, the XOR of all numbers in the segment is equal to 0 (each color occurs either 0 or 2 times, thus each integer is taken either 0 or 2 times, and all integers taken twice cancel out).

This allows us to find all minimal closed segments in O(nlogn) as follows: iterate on the array of colors from left to right, maintaining the XOR on the current prefix and a map where, for each XOR we encountered, we store the longest prefix which has that value of XOR. Then, after we process the i-th element, we can quickly find the left border of the segment ending in the i-th element by looking for the current XOR in the map. Don't forget to update the map after that.

That way, we arrive at a solution which works in O(nlogn), which is enough to solve the hard version.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
const int MOD = 998244353;
 
int add(int x, int y)
{
	return (((x + y) % MOD) + MOD) % MOD;
}
 
int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}
 
mt19937_64 rnd(98275314);
 
long long gen()
{
	long long x = 0;
	while(x == 0)
		x = rnd();
	return x;
}
 
vector<int> c;
vector<int> g;
 
int process_block(int l, int r)
{
	int ans = 0;
	while(l < r)
	{
		if(g[l] != -1 && g[l] < r)
			l = g[l];
		else
		{
			ans++;
			l++;
		}
	}
	return ans;
}
 
void solve()
{
	int n;
	scanf("%d", &n);
	int size = 0, cnt = 1;
	c.resize(n * 2);
	g.resize(n * 2, -1);
	for(int i = 0; i < 2 * n; i++)
	{
		scanf("%d", &c[i]);
		--c[i];
	}
	
	vector<long long> val(n);
	for(int i = 0; i < n; i++) val[i] = gen();
	
	map<long long, int> last;
	long long cur = 0;
	last[0] = 0;
	for(int i = 0; i < n * 2; i++)
	{
		cur ^= val[c[i]];
		if(cur == 0)
		{
			size++;
			cnt = mul(cnt, process_block(last[0], i + 1));
			last.clear();
		}
		else if(last.count(cur))
		{
			g[last[cur]] = i + 1;
		}
		last[cur] = i + 1;
	}
	
	printf("%d %dn", size, cnt);
	c.clear();
	g.clear();
}
 
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) solve();
}
```
