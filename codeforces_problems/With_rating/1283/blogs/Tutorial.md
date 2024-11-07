# Tutorial

All problems were proposed by Mikhail [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") Mirzayanov.

[1283A - Minutes Before the New Year](../problems/A._Minutes_Before_the_New_Year.md "Codeforces Round 611 (Div. 3)")

 **Tutorial**
### [1283A - Minutes Before the New Year](../problems/A._Minutes_Before_the_New_Year.md "Codeforces Round 611 (Div. 3)")

In this problem we just need to print $1440 - 60h - m$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int h, m;
		scanf("%d %d", &h, &m);
		printf("%dn", 1440 - h * 60 - m);
	}
	
	return 0;
}
```
[1283B - Candies Division](../problems/B._Candies_Division.md "Codeforces Round 611 (Div. 3)")

 **Tutorial**
### [1283B - Candies Division](../problems/B._Candies_Division.md "Codeforces Round 611 (Div. 3)")

Firstly, we can notice that we always can distribute $n - n \% k$ (where $\%$ is the modulo operation) candies between kids. In this case $a=\lfloor\frac{n}{k}\rfloor$ and the answer is at least $ak$. And then we can add the value $min(n \% k, \lfloor\frac{k}{2}\rfloor)$ to the answer. Why? Because there is only $n \% k$ candies remain and the maximum number of kids to whom we can give one more candy is $\lfloor\frac{k}{2}\rfloor$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, k;
		cin >> n >> k;
		int full = n - n % k;
		full += min(n % k, k / 2);
		cout << full << endl;
	}
	
	return 0;
}
```
[1283C - Friends and Gifts](../problems/C._Friends_and_Gifts.md "Codeforces Round 611 (Div. 3)")

 **Tutorial**
### [1283C - Friends and Gifts](../problems/C._Friends_and_Gifts.md "Codeforces Round 611 (Div. 3)")

In this problem, we need to print the permutation without fixed points (without values $p_i = i$) but some values are known in advance. Let's consider the permutation as a graph. We know that the permutation is the set of non-intersecting cycles. In this problem, we are given such a graph but some edges are removed. How to deal with it?

Firstly, let's find isolated vertices in the graph. Let its number be $cnt$. If $cnt=0$ then all is ok and we skip the current step. If $cnt=1$ then let's pin this isolated vertex to any vertex to which we can pin it. Otherwise, $cnt>1$ and we can create the chine consisting of all isolated vertices.

Now $cnt=0$ and we can finally construct the remaining part of the graph. We can notice that we have the same number of vertices with zero incoming and zero outcoming degrees. And because we got rid of all possible loops in the graph, we can match these vertices as we want.

Time complexity: $O(n)$.

 **Solution**
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
	vector<int> f(n);
	vector<int> in(n), out(n);
	for (int i = 0; i < n; ++i) {
		cin >> f[i];
		--f[i];
		if (f[i] != -1) {
			++out[i];
			++in[f[i]];
		}
	}
	
	vector<int> loops;
	for (int i = 0; i < n; ++i) {
		if (in[i] == 0 && out[i] == 0) {
			loops.push_back(i);
		}
	}
	if (loops.size() == 1) {
		int idx = loops[0];
		for (int i = 0; i < n; ++i) {
			if (in[i] == 0 && i != idx) {
				f[idx] = i;
				++out[idx];
				++in[i];
				break;
			}
		}
	} else if (loops.size() > 1) {
		for (int i = 0; i < int(loops.size()); ++i) {
			int cur = loops[i];
			int nxt = loops[(i + 1) % int(loops.size())];
			f[cur] = nxt;
			++out[cur];
			++in[nxt];
		}
	}
	loops.clear();
	vector<int> ins, outs;
	for (int i = 0; i < n; ++i) {
		if (in[i] == 0) ins.push_back(i);
		if (out[i] == 0) outs.push_back(i);
	}
	assert(ins.size() == outs.size());
	for (int i = 0; i < int(outs.size()); ++i) {
		f[outs[i]] = ins[i];
	}
	
	for (int i = 0; i < n; ++i) {
		cout << f[i] + 1 << " ";
	}
	cout << endl;
	
	return 0;
}
```
[1283D - Christmas Trees](../problems/D._Christmas_Trees.md "Codeforces Round 611 (Div. 3)")

 **Tutorial**
### [1283D - Christmas Trees](../problems/D._Christmas_Trees.md "Codeforces Round 611 (Div. 3)")

In this problem, we first need to consider all points adjacent to at least one Christmas tree, then all points at the distance two from the nearby Christmas tree and so on... What it looks like? Yes, well-known multi-source bfs.

Let's maintain a queue of positions and the set of used positions (and the distance to each vertex, of course). In the first step, we add all positions of the Christmas tree with a zero distance as initial vertices. Let the current vertex is $v$. If $d_v = 0$ (this is the Christmas tree) then just add $v-1$ and $v+1$ to the queue (if these vertices aren't added already) and continue. Otherwise, increase the answer by $d_v$ and add $v$ to the array of positions of people. When the length of this array reaches $m$, interrupt bfs and print the answer.

Don't forget about some special cases as using Arrays.sort in Java or using std::unordered_map in C++ because this can lead to the quadratic complexity.

Time complexity: $O(n \log n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(NULL));

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	queue<int> q;
	map<int, int> d;
	for (int i = 0; i < n; ++i) {
		d[x[i]] = 0;
		q.push(x[i]);
	}
	long long ans = 0;
	vector<int> res;
	while (!q.empty()) {
		if (int(res.size()) == m) break;
		int cur = q.front();
		q.pop();
		if (d[cur] != 0) {
			ans += d[cur];
			res.push_back(cur);
		}
		if (!d.count(cur - 1)) {
			d[cur - 1] = d[cur] + 1;
			q.push(cur - 1);
		}
		if (!d.count(cur + 1)) {
			d[cur + 1] = d[cur] + 1;
			q.push(cur + 1);
		}
	}
	cout << ans << endl;
	shuffle(res.begin(), res.end(), rnd);
	for (auto it : res) cout << it << " ";
	cout << endl;
	
	return 0;
}
```
[1283E - New Year Parties](../problems/E._New_Year_Parties.md "Codeforces Round 611 (Div. 3)")

 **Tutorial**
### [1283E - New Year Parties](../problems/E._New_Year_Parties.md "Codeforces Round 611 (Div. 3)")

At first treat the two subtasks as completely independent problems.

For both solutions the array of frequences is more convinient to use, so let's build it ($cnt_i$ is the number of friends living in house $i$).

1) Minimum

Collect the answer greedily from left to right. If $cnt_i = 0$ then proceed to $i+1$, otherwise add $1$ to the answer and proceed to $i+3$.

To prove that let's maximize the number of merges of houses instead of minimizing the actual count of them. It's easy to show that the final number of houses is the initial one minus the number of merges.

So if there are people in all $3$ consecutive houses starting from $i$, then $2$ merges is the absolute best you can do with them, skipping any of the merges won't get the better answer. For only $2$ of them occupied $1$ merge is the best and we can achieve that $1$ merge. And a single occupied house obviously will do $0$ merges.

2) Maximum

Also greedy but let's process the houses in segments of consecutive positions with positive $cnt$. Take a look at the sum of some segment of houses. If the sum is greater than the length then you can enlarge that segment $1$ house to the left or to the right. If the sum is greater by at least $2$, than you can enlarge it both directions at the same time.

Thus the following greedy will work. Let's update the segments from left to right. For each segments check the distance to the previous one (if it was enlarged to the right then consider the new right border). If you can enlarge the current segment and there is space on the left, then enlarge it. And if you still have possibility to enlarge the segment then enlarge it to the right.

Notice that it doesn't matter which of any pair of consecutive segments will take the spot between them as the answer changes the same.

The initial segments can be obtained with two pointers.

Overall complexity: $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n;
vector<int> a, cnt;

int solvemin(){
	int res = 0;
	forn(i, n){
		if (!cnt[i]) continue;
		++res;
		i += 2;
	}
	return res;
}

int solvemax(){
	int res = 0;
	int dist = 2;
	bool right = false;
	forn(i, n){
		if (!cnt[i]){
			++dist;
			continue;
		}
		int j = i - 1;
		int sum = 0;
		while (j + 1 < n && cnt[j + 1]){
			++j;
			sum += cnt[j];
		}
		res += (j - i + 1);
		if (sum > j - i + 1 && (!right || dist > 1)){
			--sum;
			++res;
		}
		right = false;
		if (sum > j - i + 1){
			right = true;
			++res;
		}
		i = j;
		dist = 0;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	a.resize(n);
	cnt.resize(n + 1);
	forn(i, n){
		scanf("%d", &a[i]);
		++cnt[a[i] - 1];
	}
	printf("%d %dn", solvemin(), solvemax());
	return 0;
}
```
[1283F - DIY Garland](../problems/F._DIY_Garland.md "Codeforces Round 611 (Div. 3)")

 **Tutorial**
### [1283F - DIY Garland](../problems/F._DIY_Garland.md "Codeforces Round 611 (Div. 3)")

First of all, we don't like the fact that importance values can be integers up to $2^n$ (it is kinda hard to work with them). Let's rephrase the problem.

The highest bit set to $1$ in the importance value denotes the maximum in the subtree rooted at the auxiliary lamp for the wire. So, we sort the wires according to the maximums in their subtrees. To break ties, we could consider the second maximum, then the third maximum — but that's not convenient. We can use something much easier: suppose there are two vertices with the same maximum in their subtrees; these vertices belong to the path from the root to the maximum in their subtrees, and the one which is closer to the root has the greater importance value. So, to get the order described in the problem statement, we could sort the vertices according to the maximum in their subtrees, and use depth as the tie-breaker.

What does this imply? All vertices of some prefix are ancestors of vertex $n$, so some prefix denotes the path from the root to $n$ (excluding $n$ itself). Then there are some values describing the path from some already visited vertex to $n - 1$ (if $n - 1$ was not met before), then to $n - 2$, and so on.

How can we use this information to restore the original tree? $a_1$ is the root, obviously. Then the sequence can be separated into several subsegments, each representing a vertical path in the tree (and each vertex is the parent of the next vertex in the sequence, if they belong to the same subsegment). How can we separate these vertices into subsegments, and how to find the parents for vertices which did not appear in the sequence at all? Suppose some vertex appears several times in our sequence. The first time it appeared in the sequence, it was in the middle of some vertical path, so the previous vertex is its parent; and every time this vertex appears again, it means that we start a new path — and that's how decomposition into paths is done.

Determining the parents of vertices that did not appear in the sequence is a bit harder, but can also be done. Let's recall that our sequence is decomposed into paths from root to $n$, from some visited vertex to $n - 1$, from some visited vertex to $n - 2$, and so on; so, each time the path changes, it means that we have found the maximum vertex (among unvisited ones). So we should keep track of the maximum vertex that was not introduced in the sequence while we split it into paths, and each time a path breaks, it means that we found the vertex we were keeping track of.

Overall, this solution can be implemented in $O(n)$.

 **Solution**
```cpp
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
	}
	int root = a[0];
	int last = -1;
	vector<int> used(n, 0);
	printf("%dn", root + 1);
	int cur = n - 1;
	for (int i = 0; i < n - 1; i++)
	{
		used[a[i]] = 1;
		while (used[cur])
			cur--;
		if (i == n - 2 || used[a[i + 1]])
		{
			printf("%d %dn", a[i] + 1, cur + 1);
			used[cur] = 1;
		}
		else
			printf("%d %dn", a[i + 1] + 1, a[i] + 1);
	}
	return 0;
}
```
