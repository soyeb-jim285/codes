# Good_Bye_2020_Editorial_(en)

[1466A - Bovine Dilemma](../problems/A._Bovine_Dilemma.md "Good Bye 2020")

 * Author: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* Developer: [Anadi](https://codeforces.com/profile/Anadi "International Grandmaster Anadi")
* First solve: [mip182](https://codeforces.com/profile/mip182 "International Master mip182")

 **Tutorial**
### [1466A - Bovine Dilemma](../problems/A._Bovine_Dilemma.md "Good Bye 2020")

The solution is to iterate over all possible triangles, find their areas, and compute how many of these areas are distinct. So the problem is to calculate the area of a given triangle efficiently. There are many possible ways to do it; I will describe the most straightforward method.

Recall the formula for the triangle's area: area=base⋅height2area=base⋅height2

As we want to count distinct areas we can forget about dividing by 22 and focus on calculating base⋅heightbase⋅height. Note that all triangles are of form (x1,0)(x1,0), (x2,0)(x2,0) and (0,1)(0,1). Thanks to this, if we pick a side (x1,0)(x1,0), (x2,0)(x2,0) as a base, then the height is equal to 11! As a result, base⋅height=|x1−x2|base⋅height=|x1−x2|. Final complexity is O(n2)O(n2) per test case.

 **Solution 1**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);

	vector <int> in(n);
	vector <int> is(N);

	for(auto &p: in)
		scanf("%d", &p);
	
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			is[in[j] - in[i]] = true;
	
	int ans = 0;
	for(auto &v: is)
		ans += v;
	printf("%dn", ans);
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
```
 **Solution 2**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);

	vector <int> in(n);
	for(auto &p: in)
		scanf("%d", &p);
	
	set <int> S;
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			S.insert(in[j] - in[i]);

	printf("%dn", (int)S.size());
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
```
 **Challenge**Try to solve it for n,xi≤105n,xi≤105.

[1466B - Last minute enhancements](../problems/B._Last_minute_enhancements.md "Good Bye 2020")

 * Author: [Anadi](https://codeforces.com/profile/Anadi "International Grandmaster Anadi")
* Developer: [Anadi](https://codeforces.com/profile/Anadi "International Grandmaster Anadi")
* First solve: [zscoder](https://codeforces.com/profile/zscoder "International Grandmaster zscoder")

 **Tutorial**
### [1466B - Last minute enhancements](../problems/B._Last_minute_enhancements.md "Good Bye 2020")

We describe two solutions. 

The first focuses on maximal contiguous intervals of values. We notice that for each such interval [l,r][l,r] it can either remain unchanged or get increased to [l,r+1][l,r+1] (other possibilities won't increase the number of different elements; thus, we don't need to consider them). From this observation, we conclude that the result is the number of different elements in the input increased by the number of intervals containing at least one duplicate.

The second is based on a simple, greedy approach, where we analyze the elements in nondecreasing order. While analyzing, we keep the set of elements for which we have already decided its value. When we want to add the next element, then we check if it is in the set. If it is, we increase it by 11; otherwise, we keep it as it is.

 **Solution 1**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	
	int ans = 0;
	int prv = 0, ok = 0;
	
	for(int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		
		ans += (a != prv);
		ok |= (a == prv);
		
		if(prv + 1 < a)
			ans += ok, ok = 0;
		prv = a;
	}
	
	ans += ok;
	printf("%dn", ans);
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
```
 **Solution 2**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);

	set <int> S;
	for(int i = 1; i <= n; ++i) {
		int v;
		scanf("%d", &v);

		if(S.count(v))
			v++;
		S.insert(v);
	}
	
	printf("%dn", (int)S.size());
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}

```
 **Challenge**Can you solve it if we can increase note xixi by any integer in [0,ki][0,ki], for given kiki?

[1466C - Canine poetry](../problems/C._Canine_poetry.md "Good Bye 2020")

 * Author: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* Developer: [Anadi](https://codeforces.com/profile/Anadi "International Grandmaster Anadi")
* First solve: [thenymphsofdelphi](https://codeforces.com/profile/thenymphsofdelphi "Grandmaster thenymphsofdelphi")

 **Tutorial**
### [1466C - Canine poetry](../problems/C._Canine_poetry.md "Good Bye 2020")

The main observation is that if there exists a palindrome of length larger than 33, then there exists a palindrome of length 22 or 33. This observation allows us to simplify the task to erasing all palindromes of length 22 or 33. We can also notice that each character will be replaced at most once.

From now on, there are a few possible solutions. The easiest one is to iterate over a word from left to right. When we encounter a palindrome (of length 22 or 33) ending on the current position, consisting of unmarked elements, we greedily mark this character as the one we want to replace. The number of marked characters is the answer, as it turns out that we can obtain a valid palindrome-less sequence by replacing only the letters on the marked positions. The complexity is O(n)O(n).

The sketch of proof is as follows: it is sufficient to ensure that each marked character does not coincide with 44 neighboring characters, so we are still left with 2222 remaining possibilities.

We can try different approaches too. One of these is a dpdp-based solution, where the state dp[i][ca][cb]dp[i][ca][cb] denotes the minimal result after analyzing first ii elements, where characters sisi and si−1si−1 are equal to caca and cbcb respectively. This dpdp can be implemented in O(n⋅262)O(n⋅262), which should pass, but is pretty messy to implement, so we want to improve it.

We can notice that we are not interested in the last 22 characters' exact values, but only if these were changed or not (the same observation as in the greedy solution). Thanks to this, our state changes to dp[i][ci][ci−1]dp[i][ci][ci−1], where cici encodes whether ii-th character was changed. This dpdp can be cleanly implemented in linear time.

 **Solution 1**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 7;

int n;
char in[N];
bool used[N];

void solve(){
	scanf("%s", in + 1);
	n = strlen(in + 1);
	
	for(int i = 1; i <= n; ++i)
		used[i] = false;
	
	int ans = 0;
	for(int i = 2; i <= n; ++i){
		bool use_need = false;
		if(in[i] == in[i - 1] && !used[i - 1])
			use_need = true;

		if(i > 2 && in[i] == in[i - 2] && !used[i - 2])
			use_need = true;

		used[i] = use_need;
		ans += used[i];
	}
	
	printf("%dn", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
```
 **Solution 2**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int n;
char in[N];
int dp[N][2][2];

void solve(){
	scanf("%s", in + 1);
	n = strlen(in + 1);

	for(int ta = 0; ta < 2; ++ta)
		for(int tb = 0; tb < 2; ++tb)
			dp[0][ta][tb] = 0;

	for(int i = 1; i <= n; ++i)
		for(int ta = 0; ta < 2; ++ta)
			for(int tb = 0; tb < 2; ++tb)
				dp[i][ta][tb] = N;
	
	for(int i = 1; i <= n; ++i){
		if(in[i] != in[i - 1]){
			if(in[i] != in[i - 2])
				dp[i][0][0] = min(dp[i][0][0], dp[i - 1][0][0]);
			dp[i][0][0] = min(dp[i][0][0], dp[i - 1][0][1]);
		}
		
		if(in[i] != in[i - 2])
			dp[i][0][1] = min(dp[i][0][1], dp[i - 1][1][0]);
		dp[i][0][1] = min(dp[i][0][1], dp[i - 1][1][1]);
		
		dp[i][1][0] = min(dp[i][1][0], min(dp[i - 1][0][0], dp[i - 1][0][1]) + 1);
		dp[i][1][1] = min(dp[i][1][1], min(dp[i - 1][1][0], dp[i - 1][1][1]) + 1);
	}
	
	int ans = N;
	for(int ta = 0; ta < 2; ++ta)
		for(int tb = 0; tb < 2; ++tb)
			ans = min(ans, dp[n][ta][tb]);
	printf("%dn", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
```
 **Challenge**What if letters can change, and you need the calculate the result after each change?

[1466D - 13th Labour of Heracles](../problems/D._13th_Labour_of_Heracles.md "Good Bye 2020")

 * Author: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* Developer: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* First solve: [w4p3r](https://codeforces.com/profile/w4p3r "Master w4p3r")

 **Tutorial**
### [1466D - 13th Labour of Heracles](../problems/D._13th_Labour_of_Heracles.md "Good Bye 2020")

Description of the algorithm

For simplicity, I will describe the partition of edges into colors in terms of modifying the graph. After the modifications, each connected component will correspond to edges in the given color (different color for every component). I will add colors to the coloring one by one. Initially, we have only one color and the whole graph (one connected component). We add the next color in the following way:

1. Let vertex vv be a vertex with maximum weight among the vertices with degree greater than 11. Let uu be any neighbor of vv.
2. Add vertex v′v′ to the graph with weight equal to the weight of vv. Add edge (u,v′)(u,v′) and remove the (u,v)(u,v) edge.

 For k=1k=1 the result is ∑nv=1wi∑v=1nwi. When the new color is added, the result increases by the maximum possible wiwi with the restriction that a vertex can be in at most as many components as its degree. Such a solution is the best possible, satisfying the conditions proven below. This algorithm can be simulated in complexity O(nlogn)O(nlog⁡n). We process vertices in the order of nonincreasing weights and add wiwi di−1di−1 times, where wiwi is a weight of a vertex and didi its degree in the initial graph.

Proof

Note that there exists an optimal solution in which all edges assigned to the same color form a single connected component. From this moment on, I will consider only such colorings.

Proof: Consider a color such that edges in that color don't form a single connected component. We can change the color of all of them apart from those in a connected component with a maximal value because they don't contribute to the result. So reassigning them to the same colors as adjacent edges will not decrease the value of the coloring.

The result equals the sum over all vertices of products of weight (wiwi) of a vertex and number of distinct colors of edges incident to it (cici):

∑v=1nwi⋅ci∑v=1nwi⋅ci

Note that cici is always between 11 and the degree of ii-th vertex. Furthermore, for a coloring using exactly kk colors, the following holds:

∑v=1nci=n+k−1∑v=1nci=n+k−1

Proof: Consider any coloring CC, it can be obtained the following way: 

1. Initially all edges are in the first color, thus all ci=1ci=1.
2. Until not all colors have been processed:
	* Consider the connected component in the first color. Let me define a leaf edge as an edge incident to a vertex of degree one in the graph containing only edges in the first color. There must exist at least one leaf edge which has color x≠1x≠1 in the coloring CC (a leaf edge currently has the first color, but has to be repainted).
	* Process color xx: set the color of all edges, which color in CC is xx, to xx.
	* Only cici of vertices belonging to both connected components of the fist and xx-th color have changed (they have increased by 1). Since edges in color xx form a single connected component and the same holds for the first color, there is exactly one such vertex.

This proves ∑nv=1ci≤n+k−1∑v=1nci≤n+k−1, which is enough to see that the algorithm above yields an optimal solution. The inequality ∑nv=1ci≥n+k−1∑v=1nci≥n+k−1 stems from the fact, that there are kk connected components in a kk-coloring.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 100 * 1000 + 7;

int n;
int w[N];
int deg[N];

void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
		deg[i] = 0;
	}
	
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		deg[u]++; deg[v]++;
	}
	
	LL ans = 0;
	vector <int> to_sort;

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < deg[i]; ++j)
			to_sort.push_back(w[i]);
		ans += w[i];
	}
	
	sort(to_sort.begin(), to_sort.end());
	reverse(to_sort.begin(), to_sort.end());
	
	for(auto &v: to_sort) {
		printf("%lld ", ans);
		ans += v;
	}
	
	printf("%lldn", ans);
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
```
[1466E - Apollo versus Pan](../problems/E._Apollo_versus_Pan.md "Good Bye 2020")

 * Author: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* Developer: [Anadi](https://codeforces.com/profile/Anadi "International Grandmaster Anadi")
* First solve: [dengyipeng](https://codeforces.com/profile/dengyipeng "International Master dengyipeng")

 **Tutorial**
### [1466E - Apollo versus Pan](../problems/E._Apollo_versus_Pan.md "Good Bye 2020")

The formula given in this task looks difficult to calculate, so we can rewrite it: ∑i=1n∑j=1n∑k=1n(xi&xj)⋅(xj|xk)=∑j=1n∑i=1n(xi&xj)∑k=1n(xj|xk)=∑j=1n[∑i=1n(xi&xj)]⋅[∑k=1n(xj|xk)]∑i=1n∑j=1n∑k=1n(xi&xj)⋅(xj|xk)=∑j=1n∑i=1n(xi&xj)∑k=1n(xj|xk)=∑j=1n[∑i=1n(xi&xj)]⋅[∑k=1n(xj|xk)]

We fix the element xjxj. Now the task is to calculate two sums ∑i(xi&xj)∑i(xi&xj) and ∑k(xj|xk)∑k(xj|xk), and multiply them by each other.

Let's define function f(x,c)f(x,c) as the value of cc-th bit in xx. For example f(13,1)=0f(13,1)=0, because 13=110–1213=110_12, and f(12,2)=1f(12,2)=1, because 12=11–00212=11_002. Additionally, define MM as the smallest integer such that ∀ixi<2M∀ixi<2M. Note that in this task M≤60M≤60.

We can rewrite our sums using function ff: ∑i(xi&xj)=∑c=0M2c∑if(xi,c)⋅f(xj,c)=∑c=0M2cf(xj,c)∑if(xi,c)∑i(xi&xj)=∑c=0M2c∑if(xi,c)⋅f(xj,c)=∑c=0M2cf(xj,c)∑if(xi,c) ∑k(xj|xk)=∑c=0M2c∑k1−(1−f(xj,c))⋅(1−f(xk,c))=∑c=0M2c[n−(1−f(xj,c))∑k(1−f(xk,c))]∑k(xj|xk)=∑c=0M2c∑k1−(1−f(xj,c))⋅(1−f(xk,c))=∑c=0M2c[n−(1−f(xj,c))∑k(1−f(xk,c))]

In other words, we just split elements xi,xj,xkxi,xj,xk into the powers of two.

If we memorize the values of ∑if(xi,c)∑if(xi,c), for each c∈{0,1,…,M}c∈{0,1,…,M}, then we can calculate the desired sums in O(M)O(M) for fixed xjxj using the above equations.

So the final solution is to iterate over all elements in the array and fix them as xjxj, and sum all of the results obtained. Complexity is O(nM)=O(nlogmaxi(xi))O(nM)=O(nlog⁡maxi(xi))

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 500 * 1000 + 7;
const int P = 60;
const int MX = 1e9 + 7;

int n;
LL in[N];
int cnt[P];

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < P; ++i)
		cnt[i] = 0;
	
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &in[i]);
		for(int j = 0; j < P; ++j)
			cnt[j] += in[i] >> j & 1;
	}
	
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		LL exp_or = 0, exp_and = 0;
		for(int j = 0; j < P; ++j){
			if(in[i] >> j & 1){
				exp_or += (1LL << j) % MX * n;
				exp_and += (1LL << j) % MX * cnt[j];
			}
			else
				exp_or += (1LL << j) % MX * cnt[j];
		}
		
		exp_and %= MX, exp_or %= MX;
		ans = (ans + 1LL * exp_or * exp_and) % MX;
	}
	
	printf("%dn", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
```
[1466F - Euclid's nightmare](../problems/F._Euclid's_nightmare.md "Good Bye 2020")

 * Author: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* Developer: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* First solve: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist")

 **Tutorial**
### [1466F - Euclid's nightmare](../problems/F._Euclid's_nightmare.md "Good Bye 2020")

We start by simplifying the task. Increase the length of all vectors by 11, i.e., add additional dimension. For the vectors from SS, the m+1m+1-th character will be 11 in those with exactly one character 11. This way, all the vectors in SS will have 11s on precisely two positions.

When we have some items and some subsets of these items of size exactly 22, it is intuitive to create a graph on these items. Thus we create a graph where vertices represent dimensions of our space, and edges are vectors given in the input.

Consider a sum of a subset of vectors in the input. Notice that each such vector contributes 11 to the sum at exactly 22 positions. Thus the resulting vector has an even number of 11. 

Moreover, consider any connected component in the constructed graph. Note that our vector needs to have an even number of 11 in each connected component for the same reason. It turns out that we can represent any vector fulfilling this condition.

From these observations, we conclude that all we care about are connected components of the graph. Thus the answer is the MST of this graph, where the value of an edge is its index. The number of achievable vectors is 2|S′|2|S′|. Complexity is O((n+m)log(n+m))O((n+m)log⁡(n+m)) or faster depending on the algorithm to find the MST.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 5e5 + 7;
const int MX = 1e9 + 7;

int n, m;
int rep[N];

int Find(int a) {
	if(rep[a] == a)
		return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	
	rep[a] = b;
	return a != b;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m + 1; ++i)
		rep[i] = i;
	
	vector <int> ans;
	for(int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		
		int fa, fb = m + 1;
		scanf("%d", &fa);
		
		if(k > 1)
			scanf("%d", &fb);
		
		if(Union(fa, fb))
			ans.push_back(i);
	}
	
	int res = 1;
	for(int i = 0; i < (int)ans.size(); ++i)
		res = (res + res) % MX;

	printf("%d %dn", res, (int)ans.size());
	for(auto v: ans)
		printf("%d ", v);
	puts("");
	return 0;
}
```
[1466G - Song of the Sirens](../problems/G._Song_of_the_Sirens.md "Good Bye 2020")

 * Author: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* Developer: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* First solve: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist")

 **Tutorial**
### [1466G - Song of the Sirens](../problems/G._Song_of_the_Sirens.md "Good Bye 2020")

We define f(n,w)f(n,w) as the number of occurrences of ww in snsn. Moreover, we define g(n,w),n>0g(n,w),n>0 as the number of occurrences of ww in snsn which contain character tn−1tn−1. With these definitions, we write the formula for f(n,w)f(n,w) with n>0n>0: f(n,w)=2⋅f(n−1,w)+g(n,w)=f(0,w)⋅2n+∑k=1ng(k,w)⋅2n−kf(n,w)=2⋅f(n−1,w)+g(n,w)=f(0,w)⋅2n+∑k=1ng(k,w)⋅2n−k

Let sksk be the shortest song, such that |w|≤|sk||w|≤|sk|. Notice that |sk|≤2⋅|w|+|s0||sk|≤2⋅|w|+|s0|. We can further reformulate the formula for f(n,w)f(n,w): f(n,w)=f(k,w)⋅2n−k+∑i=k+1ng(i,w)⋅2n−if(n,w)=f(k,w)⋅2n−k+∑i=k+1ng(i,w)⋅2n−i

The length of sksk is more or less the same as the length of ww, so we can brute-force all occurrences of ww in sksk with, for example, the KMP algorithm. 

The key observation to calculate the latter part of the formula is that g(i,w)g(i,w) = g(j,w)g(j,w) if ti−1=tj−1ti−1=tj−1, and k<i,jk<i,j. To prove that we note that si,sjsi,sj can be represented as: si=aiskti−1skbisj=ajsktj−1skbjsi=aiskti−1skbisj=ajsktj−1skbj

As |w|≤|sk||w|≤|sk|, and we are interested only in occurrences containing the middle character, we can see that for equal ti−1ti−1, tj−1tj−1, values of gg are the same.

We calculate the value of the gg function for each letter of the alphabet (we can use KMP for this). Using prefix sums we can calculate ∑ni=k+1g(i,w)⋅2n−i∑i=k+1ng(i,w)⋅2n−i in O(|Σ|)O(|Σ|), where |Σ||Σ| denotes the length of the alphabet.

The whole algorithm works in O(n+q⋅(|Σ|+|s0|)+S)O(n+q⋅(|Σ|+|s0|)+S), where SS denotes the total length of all queries. It can be improved to O(n+q+S)O(n+q+S), but it was not needed to get accepted.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 1e6 + 7;
const int MOD = 1e9 + 7;

int n, q;
string s, t;
vector <string> songs;

vector <int> pw;
vector <int> sum[26];

void read(string &p) {
	static char input[MAXLEN];
	scanf("%s", input);
	p = input;
}

void prepare_songs() {
	songs = {s};
	for(auto c: t) {
		if(songs.back().size() >= MAXLEN)
			break;
		
		auto p = songs.back();
		auto nxt = p + string(1, c) + p;
		songs.push_back(nxt);
	}
}

void prepare_sum() {
	for(int i = 0; i < 26; ++i) {
		char c = 'a' + i;
		sum[i].resize(n + 1, 0);
		
		for(int j = 0; j < n; ++j)
			sum[i][j + 1] = (sum[i][j] * 2 + (t[j] == c)) % MOD;
	}
	
	pw.resize(n + 1, 0);
	pw[0] = 1;
	
	for(int i = 1; i <= n; ++i)
		pw[i] = 2LL * pw[i - 1] % MOD;
}

void init() {
	scanf("%d %d", &n, &q);
	read(s), read(t);

	prepare_songs();
	prepare_sum();
}

vector <int> kmp(string &in) {
	int m = in.size(), cpref = 0;
	vector <int> dp(m, 0);
	
	for(int i = 1; i < (int)in.size(); ++i) {
		while(cpref > 0 && in[cpref] != in[i])
			cpref = dp[cpref - 1];
		
		if(in[cpref] == in[i])
			++cpref;
		dp[i] = cpref;
	}
	
	return dp;
}

/* Get all borders based on dp from kmp */
vector <bool> get(vector <int> &dp, int m) {
	vector <bool> ret(m + 1, false);
	int cur = dp.back();
	
	while(cur) {
		ret[cur] = true;
		cur = dp[cur - 1];
	}
	
	ret[cur] = true;
	return ret;
}

int answer(int k, string &w) {
	int id = 0;
	while(songs[id].size() < w.size())
		++id;
	
	if(id > k)
		return 0;
	
	int m = w.size();
	string s_pref = w + '#' + songs[id];
	string s_suf = songs[id] + '#' + w;
	
	auto dp_pref = kmp(s_pref);
	auto dp_suf = kmp(s_suf);
	
	auto pref = get(dp_pref, m);
	auto suf = get(dp_suf, m);
	
	/* Compute all internal occurences */
	int ret = 0;
	for(auto &v: dp_pref)
		ret += (v == m);
	ret = 1LL * ret * pw[k - id] % MOD;
	
	/* Compute the remaining occurences */
	for(int i = 0; i < m; ++i) {
		if(!pref[i] || !suf[m - i - 1])
			continue;
		
		int c = w[i] - 'a';
		ret = (ret + sum[c][k] - 1LL * sum[c][id] * pw[k - id]) % MOD;
	}
	
	ret = (ret + MOD) % MOD;
	return ret;
}

void solve() {
	while(q--) {
		int k;
		string w;
		
		scanf("%d", &k);
		read(w);
		printf("%dn", answer(k, w));
	}
}

int main() {
	init();
	solve();
	return 0;
}
```
[1466H - Finding satisfactory solutions](../problems/H._Finding_satisfactory_solutions.md "Good Bye 2020")

 * Authors: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut"), [Anadi](https://codeforces.com/profile/Anadi "International Grandmaster Anadi")
* Developer: [Okrut](https://codeforces.com/profile/Okrut "Grandmaster Okrut")
* First solve: [maroonrk](https://codeforces.com/profile/maroonrk "Legendary Grandmaster maroonrk")

 **Tutorial**
### [1466H - Finding satisfactory solutions](../problems/H._Finding_satisfactory_solutions.md "Good Bye 2020")

We start with presenting the algorithm for finding the unique optimal good assignment. It treats agents as vertices in a graph and works in the following way:

* For every ii from 11 to nn create a vertex (a single vertex will represent both the agent and his good)
* Until there are agents left, perform a round of an algorithm in the following way:
	1. For every agent, create a unidirectional edge from his vertex to the vertex of the good most desired by him that is still unassigned (present in the graph).
	2. For every agent lying on a cycle, assign his most desirable, available good to him. Then erase all the vertices lying on these cycles.

 Any valid assignment is a permutation, which can be partitioned into cycles. Those are the same cycles that appeared in the above algorithm while calculating the given optimal assignment.So the task is to find the number of preference profiles that will generate the cycles present in the given optimal assignment. Note that cycles of the same length are equivalent. We can find this number by simulation of the above algorithm.

To simulate, we use dynamic programming. The state contains: 

* For each cycle length, the number of such cycles left.
* The number of already processed agents
* The number of agents processed in the previous round of the algorithm
* The number of agents processed in the current round of the algorithm
* The length of the cycle we currently analyze

The state's value is the number of ways to assign preferences to all the agents on the already processed cycles.

There are two types of transitions: 

* Iterate over the number of cycles of the current length to pick in the current round
* Finish processing the current round, and start the next round

Let p(n)p(n) be the maximal product of natural numbers with sum equal to nn. Then the number of transitions between can be bounded by O(p(n)⋅n3)O(p(n)⋅n3).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 60;
const int MX = 1e9 + 7;

struct state {
	int sum_picked = 0;
	int last_picked = 0, cur_picked = 0;
	int iterator = 0;
	vector <PII> lengths;
	
	state(vector <PII> _lengths) {
		lengths = _lengths;
	}
	
	/* operators for map comparisons */
	bool operator<(const state &s) const {
		if(lengths != s.lengths)			return lengths < s.lengths;
		if(last_picked != s.last_picked)	return last_picked < s.last_picked;
		if(cur_picked != s.cur_picked)		return cur_picked < s.cur_picked;
		return iterator < s.iterator;
	}
	
	bool operator==(const state &s) const {
		if(last_picked != s.last_picked)	return false;
		if(cur_picked != s.cur_picked)		return false;
		if(iterator != s.iterator)			return false;
		if(lengths != s.lengths)			return false;
		return true;
	}
};

int n;
vector <PII> cycles;
map <state, int> dp;

int sil[N], rv[N];
int pre[N][N][N];

int fast(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1)
			ret = 1LL * ret * a % MX;
		
		b >>= 1;
		a = 1LL * a * a % MX;
	}
	
	return ret;
}

int newt(int a, int b) {
	if(b < 0 || a < b)
		return 0;
	return 1LL * sil[a] * rv[b] % MX * rv[a - b] % MX;
}

PII get_ways(int a, int b) {
	if(a == 0 && b == 0)
		return {sil[n - 1], 0};

	int ret = 0, ret2 = 0;
	int c = n - a - 1;
	
	for(int t = 1; t + c <= n; ++t) {
		ret = (ret + 1LL * newt(n - t, c) * sil[c] % MX * newt(n - c - 1, b) % MX * sil[b] % MX * sil[a - b]) % MX;
		ret2 = (ret2 + 1LL * newt(n - t, c) * sil[c] % MX * newt(n - t - c, b) % MX * sil[b] % MX * sil[a - b]) % MX;
	}

	return {ret, ret2};
}

void precalc() {
	sil[0] = 1;
	for(int i = 1; i <= n; ++i)
		sil[i] = 1LL * sil[i - 1] * i % MX;
	
	rv[n] = fast(sil[n], MX - 2);
	for(int i = n; i >= 1; --i)
		rv[i - 1] = 1LL * rv[i] * i % MX;
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= i; ++j) {
			if(i && j == 0)
				continue;
			
			auto [val, val2] = get_ways(i, j);
			pre[i][j][0] = 1;

			int res = 1, res2 = 1;
			for(int k = 1; k <= n; ++k) {
				res = 1LL * res * val % MX;
				res2 = 1LL * res2 * val2 % MX;
				pre[i][j][k] = (res + MX - res2) % MX;
			}
		}
}

void read() {
	scanf("%d", &n);
	precalc();

	vector <int> input(n);
	for(auto &v: input) {
		scanf("%d", &v);
		v--;
	}
	
	vector <bool> vis(n);
	vector <int> cycle_lengths;

	for(int i = 0; i < n; ++i) {
		if(vis[i])
			continue;
		
		int cur = i;
		int cycle_length = 0;
		
		while(!vis[cur]) {
			++cycle_length;
			vis[cur] = true;
			cur = input[cur];
		}
		
		cycle_lengths.push_back(cycle_length);
	}
	
	sort(cycle_lengths.begin(), cycle_lengths.end());
	for(auto v: cycle_lengths) {
		if(cycles.size() && cycles.back().st == v)
			cycles.back().nd++;
		else
			cycles.push_back({v, 1});
	}
}

int solve(state &cur) {
	if(cur.sum_picked == n)
		return 1;
	
	if(dp.count(cur))
		return dp[cur];
	
	if(cur.iterator == (int)cur.lengths.size()) {
		if(cur.cur_picked == 0)
			return dp[cur] = 0;
		
		state nxt = cur;
		nxt.sum_picked += nxt.cur_picked;
		nxt.last_picked = nxt.cur_picked;
		nxt.cur_picked = 0;
		nxt.iterator = 0;
		return dp[cur] = solve(nxt);
	}
	
	state nxt = cur;
	nxt.iterator++;
	
	int ret = 0, tmp = 1;
	auto [length, count] = cur.lengths[cur.iterator];

	for(int i = 0; i <= count; ++i) {
		nxt.cur_picked = cur.cur_picked + i * length;
		nxt.lengths[cur.iterator].nd = count - i;
		ret = (ret + 1LL * solve(nxt) * tmp % MX * newt(count, i)) % MX;
		tmp = 1LL * tmp * pre[cur.sum_picked][cur.last_picked][length] % MX;
	}
	
	return dp[cur] = ret;
}

int main() {
	read();
	state start = state(cycles);
	int ans = solve(start);
	printf("%dn", ans);
	return 0;
}
```
[1466I - The Riddle of the Sphinx](../problems/I._The_Riddle_of_the_Sphinx.md "Good Bye 2020")

 * Authors: [gawry](https://codeforces.com/profile/gawry "Grandmaster gawry"), [Anadi](https://codeforces.com/profile/Anadi "International Grandmaster Anadi")
* Developer: [Anadi](https://codeforces.com/profile/Anadi "International Grandmaster Anadi")
* First solve: [fivedemands](https://codeforces.com/profile/fivedemands "International Grandmaster fivedemands")

 **Tutorial**
### [1466I - The Riddle of the Sphinx](../problems/I._The_Riddle_of_the_Sphinx.md "Good Bye 2020")

First, we start with a slightly suboptimal solution using 5⋅(n+b)5⋅(n+b) queries. We investigate the elements in order from 11 to nn. While doing so, we will keep the stack with some of these elements. Moreover, we will keep a prefix of the maximum we found till now. We keep the following conditions:

* The prefix of the maximum will have precisely the same length as the number of the elements on the stack
* kk-th element on the stack (counting from the lowest element) will match at exactly kk bits with the current prefix.

Now, we describe how to add an element while keeping previous conditions. Assume that number of elements on the stack is m<bm<b. If the current element is:

* smaller on the first mm bits than the current prefix, then delete it and proceed to the next element
* equal on the first mm bits to the current prefix, then find the value of m+1m+1 bit using the current number and add this element to the top of the stack
* larger on the first mm bits than the current prefix, then remove the last element of the stack and last bit of the prefix and try again to add the current element to the stack

Queries on the first mm bits can be done by filling the number with 00s or 11s on the remaining positions (depending on the type of query).

After we finish analyzing the sequence, we have mm elements on the stack and prefix of length mm, a candidate for maximum. Now we want to find out if this is truly the prefix of the maximum, or maybe there is an element with a larger prefix.

To do this, we analyze the stack from its top. We take the top element, check if this larger on the first mm bits than the maximum, and if not, we remove it and proceed. Otherwise, if it is a kk-th element on the stack, then we know it matches the current prefix on the first kk bits, so we keep only these first kk bits of the current prefix.

At the very end, we are left with some prefix of the maximum. If this prefix has length bb, then the task is solved. Otherwise, we find all elements with the same prefix and recursively solve the task for smaller bb and nn.

We quickly analyze the outlined solution. In the first phase, we ask at most 33 queries per element when we add it and precisely one when we remove it. In the second phase, we ask as many queries as the stack's size (we can say that this is the query for removal). In the third phase, we use precisely nn queries, so in summary, we use 5⋅n5⋅n queries. It can be proven that if we achieve the prefix of k<bk<b elements, then there are at most kk elements with such prefix. Using some potential, we can easily prove that the sum of the number of queries used in the algorithm is at most 5⋅(n+b)5⋅(n+b).

Unfortunately, this is not enough. We optimize two parts of the solution. It is easy to observe that we can skip the third phase – if we get the prefix of length kk, only the lowest kk elements from the stack can have this prefix. Some of them might be smaller on these bits, but this does not matter, as if we ever query them later, we will receive no as an answer. This is enough to achieve 4⋅(n+b)4⋅(n+b) solution.

The second optimization is that we do not need elements on the stack to match the appropriate prefix exactly. It is enough to fulfill the following conditions instead: 

* kk-th element on the stack cannot be larger than the first kk bits of the prefix
* There is an element on the stack, which is at least as large as the current prefix.

This observation allows us to drop one query we used previously to determine if an element is smaller than the current prefix. This way, we achieve the demanded number of queries equal to 3⋅(n+b)3⋅(n+b).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

int n, b;

void write(int i, string y){
	printf("%d ", i);
	for(auto p: y)
		printf("%c", p);
	puts("");
	fflush(stdout);
}

bool ask(int i, string y){
	write(i, y);
	string ans;
	cin >> ans;
	return ans == "yes";
}

void solve(vector <int> cur, string pref){
	if(pref.size() == b){
		write(0, pref);
		return;
	}

	stack <pair <int, string> > S;
	S.push({0, pref});
	
	for(auto v: cur){
		while(S.size() > 1){
			auto prv = S.top().nd;
			while(prv.size() < b)
				prv.push_back('1');

			if(!ask(v, prv))
				break;
			S.pop();
		}
		
		if(S.top().nd.size() == b)
			continue;
		
		auto prv = S.top().nd;
		prv.push_back('0');

		while(prv.size() < b)
			prv.push_back('1');

		if(ask(v, prv)){
			prv = S.top().nd + "1";
			S.push({v, prv});
		}
		else{
			prv = S.top().nd + "0";
			S.push({v, prv});
		}
	}
	
	vector <int> nxt;
	string ans = S.top().nd;
	
	while(S.size() > 1){
		auto p = S.top();
		S.pop();
		
		string tmp = ans;
		while(tmp.size() < b)
			tmp.push_back('1');
		
		if(ask(p.st, tmp)){
			nxt.clear();
			ans = p.nd;
		}
		
		nxt.push_back(p.st);
	}
	
	solve(nxt, ans);
}

int main(){
	scanf("%d %d", &n, &b);
	vector <int> all_ids;
	for(int i = 0; i < n; ++i)
		all_ids.push_back(i + 1);
	solve(all_ids, "");
	return 0;
}
```
I am really interested in solving this task using fewer queries or proving that 3⋅(n+b)3⋅(n+b) is optimal. Does anyone have any idea how to answer these questions?

**UPD:** There are challenges added to some tasks.

