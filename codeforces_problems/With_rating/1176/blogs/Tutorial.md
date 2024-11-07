# Tutorial

[1176A - Divide it!](../problems/A._Divide_it!.md "Codeforces Round 565 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1176A - Divide it!](../problems/A._Divide_it!.md "Codeforces Round 565 (Div. 3)")

What if the given number $n$ cannot be represented as $2^{cnt_2} \cdot 3^{cnt_3} \cdot 5^{cnt_5}$? It means that the answer is -1 because all actions we can do are: remove one power of two, remove one power of three and add one power of two, and remove one power of five and add two powers of two. So if the answer is not -1 then it is $cnt_2 + 2cnt_3 + 3cnt_5$. If this formula isn't pretty clear for you, you can just simulate the process, performing actions from third to first.

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
		long long n;
		cin >> n;
		int cnt2 = 0, cnt3 = 0, cnt5 = 0;
		while (n % 2 == 0) {
			n /= 2;
			++cnt2;
		}
		while (n % 3 == 0) {
			n /= 3;
			++cnt3;
		}
		while (n % 5 == 0) {
			n /= 5;
			++cnt5;
		}
		if (n != 1) {
			cout << -1 << endl;
		} else {
			cout << cnt2 + cnt3 * 2 + cnt5 * 3 << endl;
		}
	}
	
	return 0;
}
```
[1176B - Merge it!](../problems/B._Merge_it!.md "Codeforces Round 565 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

int t, n;
int cnt[3];

int main(){
    cin >> t;
    for(int tc = 0; tc < t; ++tc){
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            ++cnt[x % 3];
        }
    	
    	int res = cnt[0];
        int mn = min(cnt[1], cnt[2]);
        res += mn;
        cnt[1] -= mn, cnt[2] -= mn;
        res += (cnt[1] + cnt[2]) / 3;
        cout << res << endl;
    }
    return 0;
}
```
[1176C - Lose it!](../problems/C._Lose_it!.md "Codeforces Round 565 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	vector<int> p({4, 8, 15, 16, 23, 42});

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
	}
	
	vector<int> seq(6);
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			++seq[0];
		} else {
			if (seq[a[i] - 1] > 0) {
				--seq[a[i] - 1];
				++seq[a[i]];
			}
		}
	}
	
	cout << n - seq[5] * 6 << endl;
	
	return 0;
}
```
[1176D - Recover it!](../problems/D._Recover_it!.md "Codeforces Round 565 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 3 * 1000 * 1000 + 13;

int lst[N];
int num[N];

void sieve(){
	forn(i, N) lst[i] = i;
	for (int i = 2; i < N; ++i){
		if (lst[i] != i){
			lst[i] = i / lst[i];
			continue;
		}
		for (long long j = i * 1ll * i; j < N; j += i)
			lst[j] = min(lst[j], i);
	}
	int cur = 0;
	for (int i = 2; i < N; ++i) if (lst[i] == i)
		num[i] = ++cur;
}

int cnt[N];

int main() {
	int n;
	scanf("%d", &n);
	forn(i, 2 * n){
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	
	sieve();
	
	vector<int> res;
	for (int i = N - 1; i >= 0; --i){
		while (cnt[i] > 0){
			if (lst[i] == i){
				--cnt[num[i]];
				res.push_back(num[i]);
			}
			else{
				--cnt[lst[i]];
				res.push_back(i);
			}
			--cnt[i];
		}
	}
	
	for (auto it : res)
		printf("%d ", it);
	return 0;
}
```
[1176E - Cover it!](../problems/E._Cover_it!.md "Codeforces Round 565 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1176E - Cover it!](../problems/E._Cover_it!.md "Codeforces Round 565 (Div. 3)")

Firstly, let's run bfs on the given graph and calculate distances for all vertices. In fact, we don't need distances, we need their parities. The second part is to find all vertices with an even distance, all vertices with and odd distance, and print the smallest by size part. Why is it always true? Firstly, it is obvious that at least one of these sizes will not exceed ⌊n2⌋. And secondly, because we are checking just parities of distances, it is obvious that each vertex of some parity is connected with at least one vertex of the opposite parity (because it has this parity from some vertex of the opposite parity).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;
vector<int> d;
vector<vector<int>> g;

void bfs(int s) {
	d = vector<int>(n, INF);
	d[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		for (auto to : g[v]) {
			if (d[to] == INF) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	
	for (int tc = 0; tc < t; ++tc){
		cin >> n >> m;
		g = vector<vector<int>>(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
	
		bfs(0);
		vector<int> even, odd;
		for (int i = 0; i < n; ++i) {
			if (d[i] & 1) odd.push_back(i);
			else even.push_back(i);
		}
	
		if (even.size() < odd.size()) {
			cout << even.size() << endl;
			for (auto v : even) cout << v + 1 << " ";
		} else {
			cout << odd.size() << endl;
			for (auto v : odd) cout << v + 1 << " ";
		}
		cout << endl;
	}
	
	return 0;
}
```
[1176F - Destroy it!](../problems/F._Destroy_it!.md "Codeforces Round 565 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1176F - Destroy it!](../problems/F._Destroy_it!.md "Codeforces Round 565 (Div. 3)")

The first (and crucial) observation is that we don't need all the cards that we get during each turn. In fact, since the total cost is limited to $3$, we may leave three best cards of cost $1$, one best card of cost $2$ and one best card of cost $3$, and all other cards may be discarded. So, the problem is reduced: we get only $5$ cards each turn.

The problem may be solved with dynamic programming: $dp_{x, y}$ is the maximum damage we may deal if we played $x$ turns and the last card we played had remainder $y$ modulo $10$. Processing each turn may be done with auxiliary dp: $z_{c, f}$ — the maximum damage we can deal during the turn if we play $c$ cards, and $f$ denotes whether some card (there will be only one such card, obviously) deals double damage. To calculate this auxiliary dp, we may do almost anything since we are limited to $5$ cards during each turn. It is possible to calculate it in a fast way using some casework, but it is easier, for example, to try all possible permutations of $5$ cards and play some prefix of a fixed permutation.

By combining these two techniques, we get a solution.

 **Solution**
```cpp
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long li;

const li INF64 = li(1e18);

const int N = 200043;
vector<int> cards[N][4];
li dp[N][10];
int n;
li dp2[4][2];

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for(int i = 0; i < N; i++)
		for(int j = 0; j < 10; j++)
			dp[i][j] = -INF64;
	dp[0][0] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int c, d;
			scanf("%d %d", &c, &d);
			cards[i][c].push_back(d);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			int s = (j == 1 ? 3 : 1);
			sort(cards[i][j].begin(), cards[i][j].end());
			reverse(cards[i][j].begin(), cards[i][j].end());
			while (cards[i][j].size() > s)
				cards[i][j].pop_back();
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 2; k++)
				dp2[j][k] = -INF64;
		dp2[0][0] = 0;
		vector<pair<int, int> > cur;
		for (int j = 1; j <= 3; j++)
			for (auto x : cards[i][j])
				cur.push_back(make_pair(j, x));
		sort(cur.begin(), cur.end());
		do
		{
			int mana = 3;
			li score = 0;
			li mx = 0;
			int cnt = 0;
			for (auto x : cur)
			{
				cnt++;
				if (mana < x.first)
					break;
				mana -= x.first;
				mx = max(mx, li(x.second));
				score += x.second;
				dp2[cnt][0] = max(dp2[cnt][0], score);
				dp2[cnt][1] = max(dp2[cnt][1], score + mx);
			}
		} while (next_permutation(cur.begin(), cur.end()));
		for(int j = 0; j < 10; j++)
			for (int k = 0; k <= 3; k++)
			{
				int nxt = (j + k) % 10;
				int f = (j + k >= 10 ? 1 : 0);
				dp[i + 1][nxt] = max(dp[i + 1][nxt], dp[i][j] + dp2[k][f]);
			}
	}
	li ans = 0;
	for (int i = 0; i <= 9; i++)
		ans = max(ans, dp[n][i]);
	printf("%lldn", ans);
	return 0;
}
```
