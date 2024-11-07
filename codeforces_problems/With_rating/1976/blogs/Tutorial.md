# Tutorial

[1976A - Verify Password](../problems/A._Verify_Password.md "Educational Codeforces Round 166 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1976A - Verify Password](../problems/A._Verify_Password.md "Educational Codeforces Round 166 (Rated for Div. 2)")

There's no real idea in the problem, the main difficulty is the implementation.

Many programming languages have functions to check if a character is a digit or if it's a letter. They can be used to check that no digit follows a letter.

How does the order check work? Well, most languages allow you to compare characters with inequality signs (so, we have to check that si≤si+1 for all corresponding i — separately for digits and letters). How does that work? Inside the language, every character is assigned a code. That's called an ASCII table. It contains digits, letters and lots of other characters. And the less or equal check uses that table.

If you look at the table carefully, you'll notice that the digits come before the lowercase Latin letters. Digits have codes from 48 to 57 and the lowercase letters have codes from 97 to 122. Thus, you can ignore the check that the digits come before the letters and just make sure that all characters of the string (regardless of their types) and sorted in a non-decreasing order.

For example, you can sort the string and compare the result with the original string. If they are the same, then the answer is "YES". Alternatively, you can use function is_sorted if your language has it.

Overall complexity: O(n) or O(nlogn) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	s = input()
	print("YES" if list(s) == sorted(s) else "NO")
```
[1976B - Increase/Decrease/Copy](../problems/B._Increase_Decrease_Copy.md "Educational Codeforces Round 166 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1976B - Increase/Decrease/Copy](../problems/B._Increase_Decrease_Copy.md "Educational Codeforces Round 166 (Rated for Div. 2)")

Let's fix the index of the element to be copied (denote it as i). For all other elements of the array, the number of required operations is |aj−bj| for all j≠i.

Consider the case when ai≤bi (similar to the case when ai≥bi). There are three possible relative location of the desired element bn+1: 

* if bn+1<ai, you can proceed as follows: copy i-th element, increase an+1 to bn+1 and increase ai to bi, then the number of operations is equal to 1+(bn+1−ai)+(bi−ai);
* if ai≤bn+1≤bi, you can proceed as follows: increase ai to bn+1, copy it, and keep increasing to bi, then the number of operations is equal to (bn+1−ai)+1+(bi−bn+1)=(bi−ai)+1;
* if bi<bn+1, you can proceed as follows: increase ai to bi, copy i-th element, and increase an+1 to bn+1, then the number of operations is equal to (bi−ai)+1+(bn+1−bi).

As you can see, regardless of the case, |bi−ai| is also added to the answer. So the answer looks like this: n∑j=1|bj−aj| plus some extra operations to get bn+1. That extra value is equal to the minimum value of f(i) over all indices i, where f(i) is equal to 1+|bn+1−ai| or 1 or 1+|bn+1−bi| depending on the cases described above.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
using li = long long;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<li> a(n), b(n + 1);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    li sum = 0, ext = 1e18;
    for (int i = 0; i < n; ++i) {
      sum += abs(a[i] - b[i]);
      ext = min(ext, abs(a[i] - b[n]));
      ext = min(ext, abs(b[i] - b[n]));
      if (min(a[i], b[i]) <= b[n] && b[n] <= max(a[i], b[i]))
        ext = 0;
    }
    cout << sum + ext + 1 << 'n';
  }
}
```
[1976C - Job Interview](../problems/C._Job_Interview.md "Educational Codeforces Round 166 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1976C - Job Interview](../problems/C._Job_Interview.md "Educational Codeforces Round 166 (Rated for Div. 2)")

Let's naively calculate the answer for the (n+m+1)-th candidate. While calculating it, let's store two values: typei — the type of job the i-th candidate was hired for; bad — the index of the first candidate who was hired for a suboptimal role.

We can show that this first candidate bad who was hired for a suboptimal role is the only possible candidate who can change his role if another candidate doesn't show up. So, for all other candidates among the first n+m candidates, their roles are fixed.

To prove this, we can consider the following cases: 

* if the candidate who doesn't show up has an index bad or greater, then for all candidates after them, there is only one possible job (when we consider that candidate bad, all positions on one of the job are already filled);
* if the index who doesn't show up has index less than bad, then the candidate bad will take the same job as that candidate has taken, and in any case, all positions of the optimal job of the candidate bad will be filled after we take that candidate.

Now we can use the (n+m+1)-th candidate's answer to calculate the answer for the i-th candidate as follows: 

* if i<bad and typei≠typebad, we can "move" the bad-th candidate to the role typei and the (n+m+1)-th candidate to the role typebad, this will change the answer by (abad−ai)+(bn+m+1−bbad) in case of the i-th candidate was hired as programmer (similarly for tester);
* otherwise, we can simply "move" the (n+m+1)-th candidate to the role typei, this will change the answer by (an+m+1−ai) in case of the i-th candidate was hired as programmer (similarly for tester).
 **Solution (BledDest)**
```cpp
for _ in range(int(input())):
    n, m = map(int, input().split())
    bounds = [n, m]
    a = []
    a.append(list(map(int, input().split())))
    a.append(list(map(int, input().split())))
    
    bad = -1
    badType = -1
    cur = [0, 0]
    ans = 0
    types = [0 for i in range(n + m + 1)]
    for i in range(n + m):
        curType = 0
        if a[0][i] < a[1][i]:
            curType = 1
        if cur[curType] == bounds[curType]:
            curType = 1 - curType
            if bad == -1:
                bad = i
                badType = 1 - curType
        types[i] = curType
        ans += a[types[i]][i]
        cur[types[i]] += 1
        
    res = []
    for i in range(n + m):
        val = ans - a[types[i]][i]
        if bad != -1 and i < bad and types[i] == badType:
            val = val + a[badType][bad] - a[1 - badType][bad] + a[1 - badType][n + m]
        else:
            val = val + a[types[i]][n + m]
        res.append(val)
    res.append(ans)
    print(*res)
```
[1976D - Invertible Bracket Sequences](../problems/D._Invertible_Bracket_Sequences.md "Educational Codeforces Round 166 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1976D - Invertible Bracket Sequences](../problems/D._Invertible_Bracket_Sequences.md "Educational Codeforces Round 166 (Rated for Div. 2)")

Let's define bali as the number of characters '(' minus the number of characters ')' if we consider a prefix of length i.

The bracket sequence is regular if both of the following conditions holds: 

* there is no index i such that bali<0;
* baln=0, where n is the length of the sequence.

Using that fact, we can say that the substring [l,r] is "good" if both of the following conditions holds: 

* ball−1≥bali−ball−1 should hold for all i in [l,r], otherwise that would lead to the negative balance after inverting the substring;
* ball−1=balr, otherwise that would lead to baln≠0 after inverting substring.

There are many solutions that are based on these two facts. Let's consider one of them.

Let's iterate over the right bound of the substring (denote it as r). According to the second condition, ball−1=balr, therefore, we can maintain a map that stores the number of positions for each balance value. But, unfortunately, not all such left borders form a good substring because of the first condition. Luckily, it is easy to fix, if the current balance balr and there is balance x in the map such that x<balr−x, we can remove all its occurrences from the map (i. e. remove the key x from the map). This fix works because the current position lies between the left border (which we store in the map) and the potential right border, and the current balance is too high (which violates the first condition).

So, we get a solution that works in O(nlogn).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<int, int> cnt;
    int b = 0;
    ++cnt[b];
    long long ans = 0;
    for (auto& c : s) {
      b += (c == '(' ? +1 : -1);
      ans += cnt[b];
      ++cnt[b];
      while (cnt.begin()->first * 2 < b)
        cnt.erase(cnt.begin());
    }
    cout << ans << 'n';
  }
}
```
[1976E - Splittable Permutations](../problems/E._Splittable_Permutations.md "Educational Codeforces Round 166 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1976E - Splittable Permutations](../problems/E._Splittable_Permutations.md "Educational Codeforces Round 166 (Rated for Div. 2)")

First, let's deal with the case q=n−1. In this case, after all operations are performed, all arrays have only one element each, and can no longer be split. We can show that the initial order of elements can be restored uniquely in this case. For example, we can start with n arrays consisting of single elements (one array for each integer from 1 to n), and "undo" the operations to restore the initial order. "Undoing" the operations means linking two arrays together, and we don't have any choice which arrays and in which order we link, so the result of each operation is uniquely determined. So, in the case q=n−1, the answer is 1.

What about the case q<n−1? Let's divide all integers from 1 to n into two groups: the integers from the sequences l and/or r, and all other integers. We can use the same process to show that the order of elements from the first group (the ones which were present in at least one of the given sequences) is unique, and we can restore their order using something like DSU (performing operations from the last to the first) or a double-linked list (performing operations from the first to the last).

So, suppose we restored the order of elements which are present in the input; we need to insert all of the remaining integers and don't make the sequence of operations invalid. We have an array of q+1 elements, the order of which is fixed; and there are q+2 "buckets" where we can insert the remaining elements (before the first element, between the first and the second, and so on).

For each of these "buckets", let's consider the maximum between the elements on the borders of the bucket (the fixed elements between which we insert the remaining elements). It's quite easy to see that each element we insert in a "bucket" should be less than this maximum: suppose the fixed element on the left border is y, the fixed element on the right border is z, and there was an element x>max between them. After we performed all operations, x is either in the same array as y or in the same array as z; so when we "made" that array during an operation, we would have written the integer x (or some even greater integer) instead of y or z.

And we can also show the opposite: if each element in each "bucket" is less than the maximum of the two elements bordering the bucket, the operation sequence is valid. To prove it, let's merge every bucket with the greater of the elements on its borders, and then again "undo" all operations to restore the original order of elements.

So, for each remaining element, there are some buckets where we can put it, and some buckets where we can't. However, we also have to consider the relative order of the elements we insert in the same bucket.

Let's start with the sequence of "fixed" elements, and insert the remaining elements one by one from the greatest integer to the smallest integer. We can show that every time we insert an element in this order, the number of places where it can go does not depend on where we inserted the previous elements. Suppose we insert an element which "fits" into b buckets, and before inserting it, we also inserted k other elements. Then there are exactly b+k places where this element can fit, because every element we inserted earlier went into one of those same b buckets and split that bucket into two. So, maintaining these two numbers (the number of available buckets and the number of elements we already inserted) is enough, and the positions of elements we inserted does not matter.

This allows us to count the number of possible permutations in O(n).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 300043;
const int MOD = 998244353;
 
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
 
int nxt[N], prv[N];
bool exists[N];
 
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) nxt[i] = prv[i] = -1;
	exists[n] = true;
	vector<int> l(q), r(q);
	for(int i = 0; i < q; i++) scanf("%d", &l[i]);
	for(int i = 0; i < q; i++) scanf("%d", &r[i]);
	for(int i = 0; i < q; i++)
	{
		int L = l[i], R = r[i];
		if(exists[L])
		{
			exists[R] = true;
			nxt[R] = nxt[L];
			if(nxt[R] != -1) prv[nxt[R]] = R;
			prv[R] = L;
			nxt[L] = R;
		}
		else
		{
			exists[L] = true;
			prv[L] = prv[R];
			if(prv[L] != -1) nxt[prv[L]] = L;
			nxt[L] = R;
			prv[R] = L;
		}
	}
	vector<int> seq;
	int start = -1;
	for(int i = 1; i <= n; i++)
		if(prv[i] == -1 && exists[i])
			start = i;
	seq.push_back(start);
	while(nxt[start] != -1)
	{
		start = nxt[start];
		seq.push_back(start);
	}
	vector<int> cnt_segments(n + 1);
	cnt_segments[seq[0]]++;
	cnt_segments[seq[q]]++;
	for(int i = 0; i < q; i++)
		cnt_segments[max(seq[i], seq[i + 1])]++;
	int ans = 1;
	int places = 0;
	for(int i = n; i >= 1; i--)
	{
		if(exists[i])
			places += cnt_segments[i];
		else
		{
			ans = mul(ans, places);
			places++;
		}
	}
	printf("%dn", ans);
}
```
[1976F - Remove Bridges](../problems/F._Remove_Bridges.md "Educational Codeforces Round 166 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1976F - Remove Bridges](../problems/F._Remove_Bridges.md "Educational Codeforces Round 166 (Rated for Div. 2)")

What does an extra edge change in the configuration of the bridges? Well, all tree edges on the path between the two vertices that an extra edge connects, stop being bridges.

So, the task can be restated as follows: choose k pairs of distinct vertices such that: 

* a root is present in at least one pair;
* the number of edges in the union of the paths between the vertices of all pairs is as large as possible;
* there is no vertex covered by at least one path such that an edge to its parent is not a part of any path.

The next idea is quite intuitive. It only makes sense to choose a root or the leaves of the tree into the pairs. If any pair has a non-leaf vertex, you can safely prolong the path until any of the leaves in its subtree, and the union of the paths will not become smaller.

Now for the tricky idea. Instead of choosing k pairs of root/leaves, you can actually just take a root and 2k - 1 leaves, and there will always be a way to split them into pairs to satisfy all conditions.

Let's show that. Traverse the tree with a DFS and record the order you visit the leaves. Pair up a root with the middle leaf in that order. Then pair up leaves 1 and 2k-1, 2 and 2k-2 and so on. This way, the path for every pair includes a vertex on the path of the first pair (the one that includes the root). Thus, the union of the paths is the same as the union of all vertical paths from the leaves to the root. That obviously satisfies the condition on the connectedness of the bridges.

Notice how that union of the paths is also the largest possible on that set of leaves. Every path between the leaves can be viewed at as two vertical paths from each leaf. The longest vertical path from each leaf is the one going to the root. And we have exactly the union of these vertical paths as our solution.

Thus, the task actually becomes as follows: choose 2k - 1 leaves in such a way that the union of their paths to the root is as large as possible.

That can actually be done greedily. Take a leaf with the longest path to the root. Then keep taking leaves that add as many new edges into the union as possible.

That idea can be implemented as follows. For every vertex, calculate the longest path that starts in it and ends in some leaf. Can be done with a single DFS. Maintain a set of all vertices sorted by their longest paths. On each step, take a vertex with the largest value and remove all vertices on that path (any path of the maximum length if there are multiple) from the set.

Overall complexity: O(n \log n) per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
vector<int> h;
vector<vector<int>> g;
 
void dfs(int v, int p = -1){
	for (int u : g[v]) if (u != p){
		dfs(u, v);
		h[v] = max(h[v], h[u] + 1);
	}
}
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		g.assign(n, {});
		forn(i, n - 1){
			int v, u;
			cin >> v >> u;
			--v, --u;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		h.assign(n, 0);
		dfs(0);
		set<pair<int, int>> cur;
		forn(i, n) cur.insert({h[i], i});
		vector<int> ans;
		int tmp = n;
		while (!cur.empty()){
			int v = cur.rbegin()->second;
			while (v != -1){
				--tmp;
				cur.erase({h[v], v});
				int pv = -1;
				for (int u : g[v]) if (h[u] == h[v] - 1){
					pv = u;
					break;
				}
				v = pv;
			}
			ans.push_back(tmp);
		}
		for (int i = 0; i < int(ans.size()); i += 2){
			cout << ans[i] << ' ';
		}
		for (int i = (int(ans.size()) + 1) / 2; i < n - 1; ++i){
			cout << 0 << ' ';
		}
		cout << 'n';
	}
	return 0;
}
```
