# Tutorial_(en)


### [1694A - Creep](https://codeforces.com/contest/1694/problem/A "Codeforces Round 800 (Div. 2)")

Idea: [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ")

 **Solution**
### [1694A - Creep](https://codeforces.com/contest/1694/problem/A "Codeforces Round 800 (Div. 2)")

Define the minimum possible creepiness of the string as $ans$. We want to show that $ans$ is equal to $max(1, |a - b|)$.

* Creepiness of $S[1 \ldots 1]$ is equal to $1$ and creepiness of $S[1 \ldots n]$ is equal to $|a - b|$ so $max(1, |a - b|) \le ans$.
* The way to make a string with creepiness equal to $max(1, |a - b|)$:while $0 < a, b$ holds, add 01 to the end of the string. After that, add the remaining character to the end of the string. Now we know $ans \le max(1, |a - b|)$.
* So $ans = max(1, |a - b|)$.

complexity: $\mathcal{O}(a + b)$

 **Implementation**
```cpp
# include <bits/stdc++.h>

using namespace std;

int t, A, B;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t --){
		cin >> A >> B;
		for (int i = 0; i < min(A, B); ++ i)
			cout << "01";
		for (int i = 0; i < abs(A - B); ++ i)
			cout << (A < B ? 1 : 0);
		cout << 'n';
	}

	return 0;
}
```
### [1694B - Paranoid String](https://codeforces.com/contest/1694/problem/B "Codeforces Round 800 (Div. 2)")

Idea: [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ")

 **Solution**
### [1694B - Paranoid String](https://codeforces.com/contest/1694/problem/B "Codeforces Round 800 (Div. 2)")

We want to show that a binary string $T$ of length $m$ is paranoid if and only if $m = 1$ or ($1 < m$ and $S[m] \neq S[m - 1]$).

* In the case of $S[m - 1] = S[m]$: We can never delete the last two characters because they will always remain equal. So $S$ is not paranoid.
* In the case of $S[m - 1] \neq S[m]$: If $m = 2$, we can reach our goal by one operation. Otherwise assume that the last character is 0. Now the last three characters are either 010 or 110. In the first case perform the operation on $[S_{m-2},S_{m-1}]$ and in the second case perform the operation on $[S_{m-1},S_m]$. Then the last two characters will be 10 and we can continue this algorithm on the new string until we reach $m = 1$.

The number of paranoid substrings of length $1$ is equal to $n$. To count the number of longer substrings, we can fix $r$ from index $2$ to $n$. if $S[r] \neq S[r - 1]$ holds, we should add $r - 1$ to the answer.

complexity: $\mathcal{O}(n)$

 **Implementation**
```cpp
# include <bits/stdc++.h>

using namespace std;

int t, n;
string S;
long long ans;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t --){
		cin >> n >> S, ans = n;
		for (int i = 1; i < n; ++ i)
			if (S[i] != S[i - 1])
				ans += i;
		cout << ans << 'n';
	}

	return 0;
}
```
### [1693A - Directional Increase](../problems/A._Directional_Increase.md "Codeforces Round 800 (Div. 1)")

Idea: [alireza_kaviani](https://codeforces.com/profile/alireza_kaviani "Grandmaster alireza_kaviani")

 **Solution**
### [1693A - Directional Increase](../problems/A._Directional_Increase.md "Codeforces Round 800 (Div. 1)")

First of all the sum of the elements has to be $0$ because the pointer has to end up on the first element.

Denote the number of times you do the first operation while the pointer is on the $i$-th element as $b_i$. And the number of times you do the second operation while the pointer is on the $i$-th element as $c_i$.

$a_i = b_i - c_i$ and $c_i = b_{i - 1}$ because the pointer has to end up on the first element.

So $a_i = b_i - b_{i - 1} \to b_i = a_i + b_{i - 1}$ and $b_1 = a_1$.

Now that we have calculated $b$, we need to determine whether it's possible to perform the operations like so.

There are two conditions.

* $b_i \geq 0$ ($1 \leq i \leq n$).
* If $b_i = 0$ for each $j$, $i < j$, $b_j = 0$. Because the pointer couldn't reach the $j$-th element.

You can always construct $a$ if these two conditions hold.

Proof by induction. Perform the first operation and the second operation $b_1 - 1$ times in a row. Then perform the first operation. Construct the rest by induction and then perform the second operation.

Time complexity: $\mathcal{O}(n)$

 **Implementation**
```cpp
//In the name of God
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 100;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, t, a[maxn];
long long ps[maxn];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			ps[i] = ps[i - 1] + a[i];
		}
		if(ps[n] != 0){
			cout << "Non";
			continue;
		}
		bool ok = 1;
		for(int i = 1; i <= n; i++){
			if(ps[i] < 0) ok = 0;
		}
		bool visited_zero = 0;
		for(int i = 1; i <= n; i++){
			if(ps[i] == 0) visited_zero = 1;
			else if(visited_zero) ok = 0;
		}
		if(ok) cout << "Yesn";
		else cout << "Non";
	}
	
	return 0;
}

```
### [1693B - Fake Plastic Trees](../problems/B._Fake_Plastic_Trees.md "Codeforces Round 800 (Div. 1)")

Idea: [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ"), [alireza_kaviani](https://codeforces.com/profile/alireza_kaviani "Grandmaster alireza_kaviani")

 **Solution**Tutorial is loading... **Implementation**
```cpp
# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int t, n, l[N], r[N], ans;
vector <int> adj[N];

ll DFS(int v){
	ll sum = 0;
	for (int u : adj[v]){
		sum += DFS(u);
	}
	if (sum < ll(l[v])){
		++ ans;
		return r[v];
	}
	return min(ll(r[v]), sum);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t --){
		cin >> n;
		for (int i = 2; i <= n; ++ i){
			int par;
			cin >> par;
			adj[par].push_back(i);
		}
		for (int i = 1; i <= n; ++ i){
			cin >> l[i] >> r[i];
		}
		ans = 0;
		DFS(1);
		cout << ans << "n";
		for (int i = 1; i <= n; ++ i){
			adj[i].clear();
		}
	}

	return 0;
}

```
### [1693C - Keshi in Search of AmShZ](../problems/C._Keshi_in_Search_of_AmShZ.md "Codeforces Round 800 (Div. 1)")

Idea: [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ")

 **Solution**
### [1693C - Keshi in Search of AmShZ](../problems/C._Keshi_in_Search_of_AmShZ.md "Codeforces Round 800 (Div. 1)")

Define disv as the minimum number of days needed to reach city n from city v. disn=0.

We have to assume that Keshi will always choose the worst reachable city, that is the city with maximum dis.

For each node v we kind of have to choose nxtv and block all neighbors(outgoing edges) with a distance more than disnxtv.

We will use Dijkstra's algorithm.

Note that in Dijkstra's algorithm we mark the nodes in increasing order of dis.

At each step get the node v with the minimum dis. For each node u that there is an edge from u to v, calculate disu if nxtu was v. You know the number of edges you have to block since the neighbors with greater dis are the ones that are not marked yet.

Time complexity: O(nlogn)

 **Implementation**
```cpp
# include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, d[N], dist[N];
priority_queue <pair <int, int> > pq;
vector <int> adj[N];
bool mark[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	fill(dist, dist + n + 1, m);
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[u].push_back(v);
		++ d[v];
	}
	dist[n] = 0;
	pq.push({0, n});
	while (!pq.empty()){
		int v = pq.top().second;
		pq.pop();
		if (mark[v])
			continue;
		mark[v] = true;
		for (int u : adj[v]){
			if (dist[v] + d[u] < dist[u]){
				dist[u] = dist[v] + d[u];
				pq.push({- dist[u], u});
			}
			-- d[u];
		}
	}
	cout << dist[1] << 'n';

	return 0;
}

```
### [1693D - Decinc Dividing](../problems/D._Decinc_Dividing.md "Codeforces Round 800 (Div. 1)")

Idea: [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ")

 **Solution 1**
### [1693D - Decinc Dividing](../problems/D._Decinc_Dividing.md "Codeforces Round 800 (Div. 1)")

Let's solve the problem for a single subarray.

Assume the i-th element belongs to the increasing subsequence. Define dpl,i for the interval [l,i] as the maximum value the last element of the decreasing subsequence can have. It's +∞ in case the decreasing subsequence is empty. It's −∞ if the array is not possible.

Assume the i-th element belongs to the decreasing subsequence. Define pdl,i for the interval [l,i] as the minimum value the last element of the increasing subsequence can have. It's −∞ in case the increasing subsequence is empty. It's +∞ if the array is not possible.

The interval [l,r] is not Decinc if and only if dpl,r=−∞ and pdl,r=+∞.

Iterate over l from n to 1 and keep the dp and pd values updated (shown in the implementation).

We claim that each dp or pd value will change at most three times throughout the algorithm.

For some index i assume j is the largest index smaller than i such that aj>aj+1.

dpi can only be one of these four values: −∞,+∞,aj,aj+1.

Because the last element of the decreasing subsequence can't be before the j-th element. And if it's some k that lies on the interval [j+2,i−1] you can simply move it to the increasing subsequence since both (k−1)-th and (k+1)-th elements belong to the increasing subsequence. 

The same applies for pdi.

So the upd function is called O(n) times in total.

Time complexity: O(n)

Thanks to [Koosha_Mv](https://codeforces.com/profile/Koosha_Mv "Grandmaster Koosha_Mv")

 **Solution 2**It can be proven that a permutation is **Decinc** if and only if it's 3412-avoiding and 2143-avoiding.

 **Implementation 1**
```cpp
# include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 10;
 
int n, a[N], dp[N], pd[N], f[N];
long long ans;
 
inline void upd(int i){
	if (n < i)
		return;
	int inc = 0, dec = n + 1;
	if (pd[i - 1] < a[i])
		inc = max(inc, a[i - 1]);
	if (a[i - 1] < a[i])
		inc = max(inc, dp[i - 1]);
	if (a[i] < dp[i - 1])
		dec = min(dec, a[i - 1]);
	if (a[i] < a[i - 1])
		dec = min(dec, pd[i - 1]);
	if (inc == dp[i] && dec == pd[i])
		return;
	dp[i] = inc, pd[i] = dec;
	f[i] = 0;
	if (dec <= n || inc){
		upd(i + 1);
		f[i] = f[i + 1] + 1;
	}
	return;
}
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = n; 1 <= i; -- i){
		dp[i] = n + 1;
		pd[i] = 0;
		upd(i + 1);
		f[i] = f[i + 1] + 1;
		ans += f[i];
	}
	cout << ans << 'n';
 
	return 0;
}

```
 **Implementation 2**
```cpp
# include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, a[N], min_r[N], fen[N];
long long ans;
stack <int> sk;
vector <int> vec[2][N];

void mofen(int pos, int val){
	for (pos += 5; pos < N; pos += pos & - pos)
		fen[pos] = min(fen[pos], val);
}
int gefen(int pos){
	int res = n + 1;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res = min(res, fen[pos]);
	return res;
}

void find_3412(){
	fill(fen, fen + n + 10, n + 1);
	while (!sk.empty())
		sk.pop();
	for (int i = 1; i <= n; ++ i){
		while (!sk.empty() && a[i] < a[sk.top()])
			sk.pop();
		if (!sk.empty())
			vec[0][sk.top()].push_back(i);
		sk.push(i);
	}
	while (!sk.empty())
		sk.pop();
	for (int i = n; 1 <= i; -- i){
		while (!sk.empty() && a[sk.top()] < a[i])
			sk.pop();
		if (!sk.empty())
			vec[1][sk.top()].push_back(i);
		sk.push(i);
	}
	for (int i = n; 1 <= i; -- i){
		for (int ind : vec[0][i])
			mofen(a[ind], ind);
		for (int ind : vec[1][i])
			min_r[ind] = min(min_r[ind], gefen(a[ind] - 1));
		vec[0][i].clear(), vec[1][i].clear();
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	fill(min_r, min_r + n + 2, n + 1);
	find_3412();
	for (int i = 1; i <= n; ++ i)
		a[i] = n + 1 - a[i];
	find_3412();
	for (int i = n; 1 <= i; -- i){
		min_r[i] = min(min_r[i], min_r[i + 1]);
		ans += min_r[i] - i;
	}
	cout << ans << 'n';

	return 0;
}
```
### [1693E - Outermost Maximums](../problems/E._Outermost_Maximums.md "Codeforces Round 800 (Div. 1)")

Idea: [Keshi](https://codeforces.com/profile/Keshi "Grandmaster Keshi")

 **Solution**
### [1693E - Outermost Maximums](../problems/E._Outermost_Maximums.md "Codeforces Round 800 (Div. 1)")

Let's calculate for each element of the array, the minimum number of times it needs to change throughout the process.

Let's take a look at the first time the i-th element is changing. We know that ai is the maximum number and the elements smaller than ai haven't changed yet.

Denote the maximum element on its left as l and the maximum element on its right as r.

So l is equal to the largest number among a1,a2,…,ai−1 that is smaller than ai. Likewise for r.

We can change ai to either l or r. It's better to change it to the smaller one. (We'll get into the details of why this is correct later.)

Let ci be the minimum number of times the i-th element needs to change. The following greedy algorithm works in ∑ci operations.

Let x be the number the leftmost maximum becomes if we do the first operation and y be the number the rightmost maximum becomes if we do the second operation.

Do the first operation if x≤y and do the second operation otherwise. If x≤y then for the leftmost maximum, the maximum element on its left is smaller than the maximum element on its right. That means we are making the right choice for this element.

Let's assume the array is a permutation of numbers from 1 through n for simplicity.

For some element ai make string S of length n such that

* Sai = "O".
* for any j<i, Saj = "L".
* for any j>i, Saj = "R".

Imagine Yeri is initially standing on the ai-th character of S (which is "O") and she is facing the beginning of the string.

In each step she either jumps to the nearest "L" or jumps to the nearest "R". And her goal is to jump out of the string in minimum number of jumps. We know it's always better to jump to the further one, but we won't need this fact.

We will use a segment tree. For each node maintain 4 values. What is the minimum possible number of jumps made in this interval in case 

* we enter it looking for an "L" and leave it looking for an "L"
* we enter it looking for an "L" and leave it looking for an "R"
* we enter it looking for an "R" and leave it looking for an "L"
* we enter it looking for an "R" and leave it looking for an "R"

It's easy to update this. Just fix which character you are looking for when moving from the node's one child to the other. And you can find these values for intervals of length 1.

Now if you iterate over i from 1 to n. At each step at most 2 characters of the string are changing, hence you can keep your segment tree updated.

But there are still some details we need to sort out. The array is not necessarily a permutation. To fix this, first get rid of the "O". Then for each number see if it appears on the left side and see if it appears on the right side. Now there are 4 different states for each number but the same segment tree can handle this too. We just need to find the 4 values for each of the 4 states of a single number.

Time complexity: O(nlogn)

 **Implementation**
```cpp
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define lc (id << 1)
#define rc (lc | 1)

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

struct cost{
	int c[2][2];
	cost(){
		memset(c, 0, sizeof c);
	}
};

cost cst[2][2];

int n, a[maxn], dp[maxn], cnl[maxn], cnr[maxn];
ll s, ans, ans2;
cost seg[maxn << 2];

inline cost mrg(cost l, cost r){
	cost mid;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			mid.c[i][j] = min(r.c[i][0] + l.c[0][j], r.c[i][1] + l.c[1][j]);
		}
	}
	return mid;
}

void bld(int id, int s, int e){
	if(e - s == 1){
		seg[id] = cst[int(cnl[s] > 0)][int(cnr[s] > 0)];
		return;
	}
	int mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	seg[id] = mrg(seg[lc], seg[rc]);
	return;
}

void upd(int id, int s, int e, int l, int r){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = cst[int(cnl[s] > 0)][int(cnr[s] > 0)];
		return;
	}
	int mid = (s + e) >> 1;
	upd(lc, s, mid, l, r);
	upd(rc, mid, e, l, r);
	seg[id] = mrg(seg[lc], seg[rc]);
	return;
}
cost get(int id, int s, int e, int l, int r){
	if(r <= s || e <= l) return cost();
	if(l <= s && e <= r) return seg[id];
	int mid = (s + e) >> 1;
	return mrg(get(lc, s, mid, l, r), get(rc, mid, e, l, r));
}

int main(){
	fast_io;
	srand(time(NULL));
	
	cst[0][0].c[0][0] = cst[0][0].c[1][1] = 0;
	cst[0][0].c[0][1] = cst[0][0].c[1][0] = inf;
	
	cst[0][1].c[1][0] = cst[0][1].c[1][1] = 1;
	cst[0][1].c[0][0] = 0;
	cst[0][1].c[0][1] = inf;
	
	cst[1][0].c[0][1] = cst[1][0].c[0][0] = 1;
	cst[1][0].c[1][1] = 0;
	cst[1][0].c[1][0] = inf;
	
	cst[1][1].c[0][0] = cst[1][1].c[1][1] = 1;
	cst[1][1].c[0][1] = cst[1][1].c[1][0] = 1;
	
	cin >> n;
	cnr[0] = cnl[0] = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnr[a[i]]++;
		s += a[i];
	}
	bld(1, 0, n + 1);
	for(int i = 1; i <= n; i++){
		cost cs = get(1, 0, n + 1, 0, a[i]);
		cnr[a[i]]--;
		cnl[a[i]]++;
		upd(1, 0, n + 1, a[i], a[i] + 1);
		dp[i] = min({cs.c[0][0], cs.c[0][1], cs.c[1][0], cs.c[1][1]});
		ans += dp[i];
	}
	
	cout << ans << "n";
	
	return 0;
}

```
Check out [this](Tutorial_(en).md?#comment-923531) solution by [ecnerwala](https://codeforces.com/profile/ecnerwala "Legendary Grandmaster ecnerwala")

### [1693F - I Might Be Wrong](../problems/F._I_Might_Be_Wrong.md "Codeforces Round 800 (Div. 1)")

Idea: [AmShZ](https://codeforces.com/profile/AmShZ "Grandmaster AmShZ")

Thanks to [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "International Grandmaster antontrygubO_o") for proof

 **Solution**
### [1693F - I Might Be Wrong](../problems/F._I_Might_Be_Wrong.md "Codeforces Round 800 (Div. 1)")

- It's trivial that we only sort with segments with balance 0.

Proof: Imagine we have sorted interval [l,r] and it has d more zeros than it has ones. So this operation costs d+1 coins. Sl has to be 1 otherwise we could just sort [l+1,r] with d coins.

Now that we know Sl is 1 there exists some k≤r that the interval [l,k] has equal number of zeros and ones. Because the interval [l,l] has more ones but the interval [l,r] has more zeros.

Sort [l,k] with cost 1 and then sort [l+1,r] with cost d. And we know we can sort [l+1,r] such that we only sort segments with balance 0.

- If everything is sorted cool. Suppose now the number of ones is greater than the number of zeros.

- Replace 0 by −1, 1 by 1, draw prefix sums. We have n+1 points (i,ai), (initially ai=prefi), where a0=0, an>0, and the operation is: choosing i, j such that ai=aj and making points between them first decrease then increase.

Denote by AmShZ strategy the following procedure: while S isn't sorted, 

* Let i be the smallest such that numbers from ai to an increase.
* If ai≤0, we sort in 1 operation.
* Otherwise, let j be the smallest such that aj=ai. Apply operation to [j,i].

 We have to show that AmShZ strategy is optimal.Let's denote by f(S) the smallest number of operations required for the current configuration. We will prove that AmShZ strategy ends in f(S) iterations by induction over n and over number of inversions in S. (Clearly any non-identical operation decreases number of inversions so that's useful).

Denote by Sk string S in which suffix of length k is sorted.

Lemma 1: If k1>k2, then AmShZ strategy for Sk1 uses at most as many operations as for Sk2. Proof: trivial

Suppose now that we have proved our statement for all strings with the number of inversions less than in S.

Now, let i be the smallest such that numbers from ai to an increase and j be the smallest such that aj=ai. 

Suppose that there is a sorting sequence that uses fewer operations than AmShZ strategy. Let's denote its first operation by [l,r].

Consider several cases: 

1. r≥i. This means that we basically end up in string Sn−l. But we could have ended up in string Sn−j, which uses at most the same number of operations
2. r≤j. Clearly, after operation [l,r] ai can only decrease, so j will still be the smallest index with aj=ai. By induction hypothesis, AmShZ strategy is optimal for resulting string, so the next operation in resulting string will be opertion [j,i]. But then we could have done [j,i] first and then [l,r].
3. j≤l. As r<i, the smallest index i such that ai… an are increasing hasn't changed. Numbers from a0 to aj also haven't changed, so j remains the same. So the next move according to AmShZ strategy will be operation [j,i], so operation [l,r] was useless
4. Last case. l<j<r<i. Note that all numbers up to ar will be strictly smallest then ai now. So we will have some new smallest j1>r such that aj1=ai. Then according to AmShZ strategy in the next move we will do operation [j1,i].

But then we could instead do [j1,i] first, and then [l,r]. But this is not optimal, as AmShZ strategy sorts Sn−j1 at least as fast as Sn−i.

 **Implementation by Um_nik**
```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
 
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
 
const int N = 200200;
int n;
char s[N];
int bal[N];
int pos[N];
 
void solve() {
	scanf("%d %s", &n, s);
	int b = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			b++;
		else
			b--;
	}
	if (b < 0) {
		for (int i = 0; i < n; i++)
			s[i] ^= 1;
		reverse(s, s + n);
		b *= -1;
	}
	bal[0] = (n + b) / 2;
	for (int i = 0; i < n; i++)
		bal[i + 1] = bal[i] + (s[i] == '0' ? -1 : 1);
	assert(bal[n] == (n - b) / 2);
	for (int i = 0; i <= n; i++)
		pos[i] = -1;
	for (int i = 0; i <= n; i++)
		pos[bal[i]] = i;
	int ans = 0;
	int l = 0;
	while(l < (n + b) / 2) {
		if (bal[l + 1] < bal[l]) {
			l++;
			continue;
		}
		if (bal[l] <= (n - b) / 2) {
			ans++;
			break;
		}
		int r = pos[bal[l]];
		assert(r > l);
		ans++;
		for (int i = l + 1; i < r; i++) {
			if (2 * i > l + r) {
				bal[i] = bal[l] - (r - i);
			} else {
				bal[i] = bal[l] - (i - l);
			}
			pos[bal[i]] = max(pos[bal[i]], i);
		}
	}
	printf("%dn", ans);
}
 
int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();
 
	return 0;
}

```
Thanks to [Um_nik](https://codeforces.com/profile/Um_nik "Legendary Grandmaster Um_nik")

