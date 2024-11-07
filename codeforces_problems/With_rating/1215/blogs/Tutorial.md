# Tutorial

[1215A - Yellow Cards](../problems/A._Yellow_Cards.md "Codeforces Round 585 (Div. 2)")

 **Editorial**
### [1215A - Yellow Cards](../problems/A._Yellow_Cards.md "Codeforces Round 585 (Div. 2)")

At first, if $k_1 > k_2$, then we swap $k_1$ with $k_2$ and $a_1$ with $a_2$, so the number of yellow cards required to send a player of the first team off is not greater than the same value for the second team. 

If all players from the first team receive $k_1 - 1$ cards each and all players from the second team receive $k_2 - 1$ cards each, we will minimize the number of players who left the game. Let $cnt = a_1 \cdot (k_1 - 1) + a_2 \cdot (k_2 - 1)$. If $cnt \le 0$, then the minimum number of players who left the game is equal to $0$. In the other case, if any player receivse one more yellow card, he leaves the game. So the minimum number of players who left the game is $(n - cnt)$.

When we maximize the number of players who left the game, at first we should give cards to players in the first team, and then give cards to players in the second team. So, if $n \le a_1 \cdot k_1$, the answer is $\lfloor \frac{n}{k_1} \rfloor$. In the other case, the answer is $a_1 + \lfloor \frac{n - a_1 \cdot k_1}{k_2} \rfloor$. 

 **Solution (fcspartakm)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int a1, a2, k1, k2, n;

inline void read() {
	cin >> a1 >> a2 >> k1 >> k2 >> n;	
}

inline void solve() {
	if (k1 > k2) {
		swap(k1, k2);
		swap(a1, a2);
	}
	int minCnt = max(0, n &mdash; a1 * (k1 &mdash; 1) &mdash; a2 * (k2 &mdash; 1));
	int maxCnt = 0;
	if (n <= a1 * k1) {
		maxCnt = n / k1;
	} else {
		maxCnt = a1 + (n &mdash; a1 * k1) / k2;
    }    
    cout << minCnt << ' ' << maxCnt << endl;
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    cerr << setprecision(10) << fixed;
    
    read();
    solve();
 
    //cerr << "TIME: " << clock() << endl;
}
```
[1215B - The Number of Products](../problems/B._The_Number_of_Products.md "Codeforces Round 585 (Div. 2)")

 **Editorial**
### [1215B - The Number of Products](../problems/B._The_Number_of_Products.md "Codeforces Round 585 (Div. 2)")

At first, let's calculate the value of $ans_p$ — the number of subsegments with positive product. We should iterate through the array and store $bal$ — the number of negative elements. Also we should store $cnt_1$ and $cnt_2$ — the number of elements such that there is an even number of negative elements before them ($cnt_1$) or an odd number of negative elements before them ($cnt_2$). If for the current element $bal$ is even, we should increase $cnt_1$ by one, else we should increase $cnt_2$ by one. Then if the current element is negative, we should increase $bal$ by one. Then we should add the number of subsegments ending in the current element and having positive product to $ans_p$. If $bal$ is even, then any subsegment ending in the current element and containing even number of negative elements should begin in a position where $bal$ was even too, so we should add $cnt_1$ to $ans_p$. If $bal$ is odd, we should add $cnt_2$ to $ans_p$ (we use similar reasoning).

The number of segments having negative product can be calculated, for example, by subtracting $ans_p$ from the total number of subsegments, which is $\frac{n \cdot (n + 1)}{2}$.

 **Solution (fcspartakm)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 13;

int n;
int a[N];

inline void read() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

inline void solve() {
	int pos = -1;
	li ans0 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			pos = i;
		}
		if (pos != -1) {
			ans0 += pos + 1;
		}
	}	
	int cnt1 = 0, cnt2 = 0;
	int bal = 0;
	li ansP = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cnt1 = 0, cnt2 = 0, bal = 0;
			continue;
		}
		if (bal % 2 == 0) {	
			cnt1++;
		} else {
			cnt2++;
		}
		if (a[i] < 0) {
			bal++;
		}
		if (bal % 2 == 0) {
			ansP += cnt1;
		} else {
			ansP += cnt2;
		}
	}
	cout << n * 1ll * (n + 1) / 2 - ans0 - ansP << ' ' << ansP << endl;
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    cerr << setprecision(10) << fixed;
    
    read();
    solve();
 
    //cerr << "TIME: " << clock() << endl;
}
```
[1215C - Swap Letters](../problems/C._Swap_Letters.md "Codeforces Round 585 (Div. 2)")

 **Editorial**
### [1215C - Swap Letters](../problems/C._Swap_Letters.md "Codeforces Round 585 (Div. 2)")

Let's calculate two vectors $pos_{01}$ and $pos_{10}$. $pos_{01}$ will contain all positions $x$ such that $s[x] = 0$ и $t[x] = 1$. Analogically, $pos_{10}$ will contain all positions $x$ such that $s[x] = 1$ и $t[x] = 0$. If the sizes of these vectors are not equal modulo $2$, the answer does not exist, because the total number of letters "a" and "b" should be even.

In the other case, we should perform operations in a greedy way. In one operation we can make $s[a]$ equal to $t[a]$ and $s[b]$ equal to $t[b]$, if both $a$ and $b$ belong to $pos_{01}$, or if both these positions belong $pos_{10}$.

If the sizes of $pos_{01}$ and $pos_{10}$ are even, we need only $(\frac{|pos_{01}|}{2} + \frac{|pos_{10}|}{2})$ operation. In the other case, there are two positions $x$ and $y$ such that $s[x] = 0$, $s[y] = 1$, $t[x] = 1$, $t[y] = 0$. We need two operations to make $s[x] = t[x]$ and $s[y] = t[y]$: at first we perform the operation $(x, x)$, and then the operation $(x, y)$. After that, strings $s$ and $t$ will be equal to each other.

 **Solution (fcspartakm)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n;
string s, t;

inline void read() {	
	cin >> n >> s >> t;
}

inline void solve() {
	vector<int> pos01, pos10;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (s[i] == 'a') {
				pos01.pb(i);
			} else {
				pos10.pb(i);
			}
		}
	}
	if (sz(pos01) % 2 != sz(pos10) % 2) {
		cout << -1 << endl;
		return;
	}
	vector<pair<int, int> > ans;
	for (int i = 0; i + 1 < sz(pos01); i += 2) {
		ans.pb(mp(pos01[i], pos01[i + 1]));
	}
	for (int i = 0; i + 1 < sz(pos10); i += 2) {
		ans.pb(mp(pos10[i], pos10[i + 1]));
	}
	if (sz(pos01) % 2) {
		int x = pos01.back();
		int y = pos10.back();
		ans.pb(mp(x, x));
		ans.pb(mp(x, y));
	}
	cout << sz(ans) << endl;
	for (int i = 0; i < sz(ans); i++) {
		cout << ans[i].ft + 1 << ' ' << ans[i].sc + 1 << endl;
	}
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    cerr << setprecision(10) << fixed;
    
    read();
    solve();
 
    //cerr << "TIME: " << clock() << endl;
}
```
[1215D - Ticket Game](../problems/D._Ticket_Game.md "Codeforces Round 585 (Div. 2)")

 **Editorial**
### [1215D - Ticket Game](../problems/D._Ticket_Game.md "Codeforces Round 585 (Div. 2)")

Let's denote the balance as the difference between the sum of digits in the left half and the sum of digits in the right half. Also let $L$ be the minimum possible balance (it can be calculated if we replace all question marks in the left half with $0$'s and all the question marks in the right half with $9$'s), and let $R$ be the maximum possible balance.

The second player wins if and only if $\frac{L + R}{2} = 0$. Let's prove it by induction on the number of question marks left in the ticket.

If all characters are digits, the second player wins only if the ticket is happy, and that is when $\frac{L + R}{2} = 0$.

Okay, now suppose the number of question marks is even, and now it's first player's turn. Each turn decreases the value of $R - L$ by $9$, and may set $L$ to any number from current $L$ to $L + 9$. If $L + R > 0$, then the first player can make $L$ as large as possible, and set it to $L + 9$. The best thing the second player can do on his turn is to set $R$ to $R - 9$ (and leave $L$ as it is), and the value of $L + R$ will be the same as it was two turns earlier. The case $L + R < 0$ can be analyzed similarly. And in the case $L + R = 0$ the second player has a symmetric strategy.

 **Solution (fcspartakm)**
```cpp
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

int main() {
    cin >> n;
    long double sum1 = 0, sum2 = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            if (i < n / 2) {
                sum1 += (long double)(s[i] - '0');
            } else {
                sum2 += (long double)(s[i] - '0');
            }
        } else {
            if (i < n / 2) {
                sum1 += (long double)4.5;
            } else {
                sum2 += (long double)4.5;   
            }
        }
    }
    if (fabsl(sum1 - sum2) < 1e-9) {
        cout << "Bicarp" << endl;
    } else {
        cout << "Monocarp" << endl;
    }
}
```
[1215E - Marbles](../problems/E._Marbles.md "Codeforces Round 585 (Div. 2)")

 **Editorial**
### [1215E - Marbles](../problems/E._Marbles.md "Codeforces Round 585 (Div. 2)")

The main fact is that the number of colors is less than 20, which allows us to use exponential solutions. 

For each pair of colors (i,j), we can calculate cnt[i][j] — the number of swaps required to place all marbles of color i before all marbles of color j (if we consider only marbles of these two colors). We can store a sorted vector for each color, and calculate this information for a fixed pair with two pointers.

Then let's use subset DP to fix the order of colors. Let d[mask] be the minimum number of operations to correctly order all marbles from the mask of colors. Let's iterate on the next color we consider — it should be a position in binary representation of mask with 0 in it. We will place all marbles of this color after all marbles we already placed. If we fix a new color i, let's calculate the sum (the additional number of swaps we have to make) by iterating on the bit j equal to 1 in the mask, and increasing sum by cnt[j][i] for every such bit. The new state of DP can be calculated as nmask=mask|(1«i). So the transition can be implemented as d[nmask]=min(d[nmask],d[mask]+sum).

The answer is the minimum number of swaps required to place all the colors, and that is d[220−1].

 **Solution (fcspartakm)**
```cpp
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000 * 1000 + 13;
const int M = 20 + 1;
const long long INF = 1000 * 1000 * 1000 * 1ll * 1000 * 1000 * 1000;

int n;
long long d[(1 << M)];
long long cnt[M][M];
vector<int> col[M];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        col[x].push_back(i);
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == j) {
                continue;
            }
            if ((int)col[i].size() == 0 || (int)col[j].size() == 0) {
                continue;
            }
            int pos2 = 0;
            for (int pos1 = 0; pos1 < (int)col[i].size(); pos1++) {
                while (true) {
                    if (pos2 == (int)col[j].size() - 1 || col[j][pos2 + 1] > col[i][pos1]) {
                        break;
                    }
                    pos2++;
                }
                if (col[i][pos1] > col[j][pos2]) {
                    cnt[i][j] += pos2 + 1;
                }
            }
        }
    }

    for (int mask = 0; mask < (1 << 20); mask++) {
        d[mask] = INF;
    }
    d[0] = 0;
    for (int mask = 0; mask < (1 << 20); mask++) {
        vector<int> was;
        for (int i = 0; i < 20; i++) {
            if (mask & (1 << i)) {
                was.push_back(i);
            }
        }
        for (int i = 0; i < 20; i++) {
            if (mask & (1 << i)) {
                continue;
            }
            long long sum = 0;
            for (int j = 0; j < (int)was.size(); j++) {
                sum += cnt[was[j]][i];
            }
            int nmask = mask | (1 << i);
            d[nmask] = min(d[nmask], d[mask] + sum);
        }
    }
    cout << d[(1 << 20) - 1] << endl;
}
```
[1215F - Radio Stations](../problems/F._Radio_Stations.md "Codeforces Round 585 (Div. 2)")

 **Editorial**
### [1215F - Radio Stations](../problems/F._Radio_Stations.md "Codeforces Round 585 (Div. 2)")

Let's try to solve the problem without any constraints on $f$ (we just need to choose a set of stations that satisfies all the complaints and contains no forbidden pair). We can see that this is an instance of 2-SAT: we can convert it into a logical expression that is a conjunction of some clauses, and each clause contains exactly two variables (maybe negated), we have to assign some values to all variables so that this expression is true. The $i$-th variable $true$ if we include the $i$-th station in our answer, or $false$ otherwise. We can solve this problem in linear time by building an implication graph and finding strongly connected components in it.

If the constraints were lower, we could iterate on $f$ and initially set all variables corresponding to stations we can't use with fixed $f$ to $false$. But this solution is quadratic, so we have to include $f$ into our original 2-SAT problem.

Let's introduce $M$ additional variables, the $i$-th of them corresponding to the fact "$f \ge i$". Add $M - 1$ clause of the form "$f \ge i$ OR NOT $f \ge i + 1$" into our conjunction. The prefix of additional variables which are equal to $true$ can be transformed into the value or $f$ we should use, and vice versa. If we introduce these variables, the constraints on $f$ that are implied by some station can be modeled with two additiona clauses: "$f \ge l_i$ OR station $i$ is not used" and "NOT $f \ge r_i + 1$ OR station $i$ is not used". So we get a linear solution (though with a noticeable constant factor).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 1600043;

vector<int> g[N];
vector<int> gt[N];
int used[N];
vector<int> order;
int comp[N];
vector<int> result;
int v;

void add_edge(int v1, int v2)
{
	g[v1].push_back(v2);
	gt[v2].push_back(v1);
}

void add_disjunction(int v1, int v2)
{
	add_edge(v1 ^ 1, v2);
	add_edge(v2 ^ 1, v1);
}

void dfs1(int v)
{
	if(used[v]) return;
	used[v] = 1;
	for(auto u : g[v])
		dfs1(u);
	order.push_back(v);
}

void dfs2(int v, int cc)
{
	if(comp[v]) return;
	comp[v] = cc;
	for(auto u : gt[v])
		dfs2(u, cc);
}

bool solve2SAT()
{
	for(int i = 0; i < v * 2; i++)
		dfs1(i);
	reverse(order.begin(), order.end());
	int cc = 0;
	for(auto x : order)
	{
		if(comp[x] == 0)
		{
			cc++;
			dfs2(x, cc);
		}
	}
	for(int i = 0; i < v; i++)
	{
		if(comp[i * 2] == comp[i * 2 + 1])
			return false;
		else if(comp[i * 2] > comp[i * 2 + 1])
			result.push_back(i);
	}
	return true;
}

int main()
{
	int n, p, M, m;
	scanf("%d %d %d %d", &n, &p, &M, &m);
	v = p + M - 1;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		add_disjunction(x * 2, y * 2);
	}
	for(int i = 0; i < p; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		if(l != 1)
			add_disjunction((l - 2 + p) * 2, i * 2 + 1);
		if(r != M)
			add_disjunction((r - 1 + p) * 2 + 1, i * 2 + 1);
	}
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		add_disjunction(x * 2 + 1, y * 2 + 1);
	}
	for(int i = 2; i <= M - 1; i++)
	{
	    int f1 = i - 2 + p;
	    int f2 = f1 + 1;
	    add_disjunction(f1 * 2, f2 * 2 + 1);
	}
	if(!solve2SAT())
	{
		puts("-1");
		return 0;
	}
	int k = 1;
	vector<int> stations;
	for(auto x : result)
		if(x < p)
			stations.push_back(x);
		else
			k = max(k, x - p + 2);
	printf("%d %dn", int(stations.size()), k);
	for(auto x : stations)
		printf("%d ", x + 1);
	return 0;
}
```
