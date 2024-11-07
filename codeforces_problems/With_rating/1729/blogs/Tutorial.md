# Tutorial

[1729A - Two Elevators](../problems/A._Two_Elevators.md "Codeforces Round 820 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1729A - Two Elevators](../problems/A._Two_Elevators.md "Codeforces Round 820 (Div. 3)")

You had to to calculate the time that each elevator would need and compare them. Let the time required by the first elevator be $d_1 = |a - 1|$, and the time required by the second one be $d_2 = |b - c| + |c - 1|$. Then the answer is $1$ if $d_1 < d_2$, $2$ if $d_1 > d_2$ and $3$ if $d_1 = d_2$

 **Solution**
```cpp
t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    d1 = a - 1
    d2 = abs(b - c) + c - 1
    ans = 0
    if d1 <= d2:
        ans += 1
    if d1 >= d2:
        ans += 2
    print(ans)
```
[1729B - Decode String](../problems/B._Decode_String.md "Codeforces Round 820 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1729B - Decode String](../problems/B._Decode_String.md "Codeforces Round 820 (Div. 3)")

The idea is as follows: we will go from the end of the string $t$ and get the original string $s$.

Note that if the current digit is $0$, then a letter with a two-digit number has been encoded. Then we take a substring of length three from the end, discard $0$ and get the number of the original letter.

Otherwise, the current number $\neq 0$, then a letter with a one-digit number was encoded. We easily reconstruct the original letter.

Next, discard the already processed characters and repeat the process until the encoded string is complete.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

char get(int i) {
    return 'a' + i - 1;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int i = n - 1;
    string res;
    while (i >= 0) {
        if (s[i] != '0') {
            res += get(s[i] - '0');
            i--;
        } else {
            res += get(stoi(s.substr(i - 2, 2)));
            i -= 3;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << 'n';
}

int main() {
    int t = 1;
    cin >> t;
    for (int it = 0; it < t; ++it) {
        solve();
    }
    return 0;
}
```
[1729C - Jumping on Tiles](../problems/C._Jumping_on_Tiles.md "Codeforces Round 820 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [Aris](https://codeforces.com/profile/Aris "Expert Aris")

 **Tutorial**
### [1729C - Jumping on Tiles](../problems/C._Jumping_on_Tiles.md "Codeforces Round 820 (Div. 3)")

It's worth knowing that ways like ('a' -> 'e') and ('a' -> 'c' -> 'e') have the same cost. That is, first you need to understand the letter on the first tile and the last one (conditionally, the letters $first$ and $last$).

Then you just need to find all such tiles on which the letters are between the letters $first$ and $last$ inclusive.

We go through each letter from $first$ to $last$ and for each letter we visit every tile that has a given letter (but we must not forget to start exactly at tile $1$ and end at tile $n$).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; i < int(n); i++)

void solve() {

    string s;
    cin >> s;

    int n = s.size();
    map<char, vector<int>> let_to_ind;

    for (int i = 0; i < n; ++i) {
        let_to_ind[s[i]].push_back(i);
    }

    int direction = (s[0] < s[n - 1]) ? 1 : -1;
    vector<int> ans;

    for (char c = s[0]; c != s[n - 1] + direction; c += direction) {
        for (auto now : let_to_ind[c]) {
            ans.push_back(now);
        }
    }

    int cost = 0;
    for (int i = 1; i < ans.size(); i++)
        cost += abs(s[ans[i]] - s[ans[i - 1]]);

    cout << cost << " " << ans.size() << 'n';
    for (auto now : ans) {
        cout << now + 1 << " ";
    }
    cout << 'n';
}
int main() {
    int tests;
    cin >> tests;
    forn(tt, tests) {
        solve();
    }
}
```
[1729D - Friends and the Restaurant](../problems/D._Friends_and_the_Restaurant.md "Codeforces Round 820 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [Aris](https://codeforces.com/profile/Aris "Expert Aris"), [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1729D - Friends and the Restaurant](../problems/D._Friends_and_the_Restaurant.md "Codeforces Round 820 (Div. 3)")

First, we sort the friends in descending order of $y_i - x_i$. Now for each friend we know the amount of money he lacks, or vice versa, which he has in excess.

In order to maximize the number of days, it is most advantageous for friends to break into pairs. It is the number of groups that matters, not the number of people in the group, so adding a third person to the pair won't improve the answer in any way.

Let's solve the problem using two pointers: for the richest friend, find the first friend from the end such that the sum of their values $y$ exceeds the sum of their values $x$. Then repeat this for all subsequent friends until the pointers meet.

If no pair could be formed, or none of the friends has a value $x$ greater than $y$, then the answer is -1.

Otherwise, print the number of pairs formed.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll>x(n), y(n);
    vector<pair<ll, int>>dif(n);

    for(auto &i : x) cin >> i;
    for(auto &i: y) cin >> i;
    for(int i = 0; i < n; i++){
        dif[i].first = y[i] - x[i];
        dif[i].second = i;
    }
    sort(dif.begin(), dif.end());
    reverse(dif.begin(), dif.end());

    int j = n - 1, cnt = 0;

    for(int i = 0; i < n; i++){
        while(j > i && dif[i].first + dif[j].first < 0) j--;
        if(j <= i) break;
        cnt++; j--;
    }
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
```
[1729E - Guess the Cycle Size](../problems/E._Guess_the_Cycle_Size.md "Codeforces Round 820 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1729E - Guess the Cycle Size](../problems/E._Guess_the_Cycle_Size.md "Codeforces Round 820 (Div. 3)")

The implication was that the solution works correctly with some high probability. So we tried to give such constraints so that the solution probability is very high.

The idea: we will output queries of the form $(1, n)$ and $(n, 1)$, gradually increasing $n$ from $2$. If we get an answer to query $-1$ the first time, then the size of the graph is exactly $n-1$.

Otherwise, let the answer to the first query be $x$ and the answer to the second query be $y$. 

With probability $\frac{1}{2}, x \neq y$. In this case, we can output the answer: $x+y$, since there are a total of two different paths from vertex $1$ to $n$ and we recognized them. Accordingly the total length of paths will be the size of the cyclic graph.

But with probability $\frac{1}{2}, x = y$. In this case we must continue the algorithm. At most we can make $25$ of such attempts. 

Let's calculate the probability of finding the correct graph size: $p = 1 - (\frac{1}{2})^{25}$. That is, we "lucky" on one test with probability $p \approx 0.99999997$. But we should have "lucky" on $50$ tests. We get: $P = p^{50} \approx 0.99999851$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

long long ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    long long x; cin >> x;
    return x;
}

long long solve() {
    for (int i = 2; i <= 26; i++) {
        long long x = ask(1, i);
        long long y = ask(i, 1);
        if (x == -1) return i-1;
        if (x != y) return x + y;
    }
    assert(false);
}

int main() {
    long long ans = solve();
    cout << "! " << ans << endl;
}
```
[1729F - Kirei and the Linear Function](../problems/F._Kirei_and_the_Linear_Function.md "Codeforces Round 820 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1729F - Kirei and the Linear Function](../problems/F._Kirei_and_the_Linear_Function.md "Codeforces Round 820 (Div. 3)")

Note that the remainder of dividing a number by $9$ is equal to the remainder of dividing its sum of digits by $9$. This is easy to check, because the number $a$ of $n$ digits is representable as a polynomial $a_0 + a_1\cdot 10 + a_2\cdot 100 + \dots + a_{n-1}\cdot 10^{n-1} + a_n\cdot 10^n$, and $10^k$ gives a remainder of $1$ when divided by $9$ for any $k$.

Let's count an array of prefix sums of digits for the string $s$.

Now, knowing $w$, we can pre-calculate for each remainder modulo $9$ all possible $L$.

Also, for each query, we can easily find the remainder of dividing $v(l,r)$ by $9$ using all the same prefix sums.

Let's iterate over the remainder of the number $a$ when dividing by $9$. Knowing it, we can easily find the remainder of the number $b$ when divided by $9$, as $k - a\cdot v(l,r)$ modulo $9$.

Now, using each pair of remainers $(a, b)$, let's try to update the answer: 

* $a = b$, then the minimum index from the pre-calculated array will act as $L_1$, and the next largest will act as $L_2$ (if such exist);
* $a\neq b$, then the minimum indexes from the pre-calculated array will act as $L_1$ and $L_2$.

This solution works for $9\cdot(n+m)$ or for $O(n + m)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define endl 'n'

using namespace std;

typedef pair<int, int> ipair;

const int MAXSZ = 200200;
const int INF = 2e9;

inline int add(int a, int b) {
	return (a + b >= 9 ? a + b - 9 : a + b);
}

inline int sub(int a, int b) {
	return (a < b ? a + 9 - b : a - b);
}

inline int mul(int a, int b) {
	return a * b % 9;
}

int sz, n, m;
string s;
int ps[MAXSZ];
vector<int> D[9];

void build() {
	sz = s.size();
	for (int md = 0; md < 9; ++md)
		D[md].clear();
	for (int i = 0; i < sz; ++i)
		ps[i + 1] = ps[i] + (s[i] - '0');
	for (int i = 0; i + n <= sz; ++i)
		D[(ps[i + n] - ps[i]) % 9].push_back(i);
}

ipair solve(int l, int r, int k) {
	int x = (ps[r] - ps[l]) % 9;
	ipair ans {INF, INF};
	for (int a = 0; a < 9; ++a) {
		int b = sub(k, mul(a, x));
		if (D[a].empty() || D[b].empty()) continue;
		if (a != b)
			ans = min(ans, make_pair(D[a].front(), D[b].front()));
		else if (D[a].size() >= 2)
			ans = min(ans, make_pair(D[a].front(), D[a][1]));
	}
	if (ans == make_pair(INF, INF))
		return {-2, -2};
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> s >> n >> m;
		build();
		for (int i = 0; i < m; ++i) {
			int l, r, k; cin >> l >> r >> k, --l;
			auto [ans1, ans2] = solve(l, r, k);
			cout << ++ans1 << ' ' << ++ans2 << endl;
		}
	}
}
```
[1729G - Cut Substrings](../problems/G._Cut_Substrings.md "Codeforces Round 820 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1729G - Cut Substrings](../problems/G._Cut_Substrings.md "Codeforces Round 820 (Div. 3)")

First, find all occurrences of $t$ in $s$ as substrings. This can be done using the prefix function.

To find the minimum number of times we need to cut substrings, consider all indexes of occurrences. Having considered the index of the occurrence, we cut out the rightmost occurrence that intersects with it. After that, we find the leftmost occurrence that does not intersect with the cut one. If it doesn't, we end the loop.

The number of optimal sequences of moves will be calculated using dynamic programming.

For each occurrence, we can count how many ways we can cut out all occurrences of $t$ in the suffix $s$ starting with this occurrence in the minimum number of moves. Considering the occurrence, we find the leftmost occurrence that does not intersect with it, and then iterate over the occurrences with which we can remove it.

 **Solution**
```cpp
#include<cstdio>
#include<cstring>
const int N=505;
const int Mod=1e9+7;
char s[N],t[N];
int n,m;
int f[N],g[N];
int p[N],tot;
inline void Init(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	tot=0;
	for(int i=1;i+m-1<=n;i++){
		bool flg=1;
		for(int j=1;j<=m;j++)
			if(s[i+j-1]!=t[j]) flg=0;
		if(flg) p[++tot]=i;
	}
	return ;
}
inline int addv(int x,int y){
	int s=x+y;
	if(s>=Mod) s-=Mod;
	return s;
}
inline int subv(int x,int y){
	int s=x-y;
	if(s<0) s+=Mod;
	return s;
}
inline void add(int&x,int y){
	x=addv(x,y);
	return ;
}
inline void sub(int&x,int y){
	x=subv(x,y);
	return ;
}
inline void Solve(){
	memset(f,0x3f,sizeof(f));
	memset(g,0,sizeof(g));
	p[0]=-N;
	f[0]=0;
	g[0]=1;
	p[++tot]=n+m;
	for(int i=0;i<tot;i++){
		int j=i+1;
		while(j<=tot&&p[j]<=p[i]+m-1) j++;
		for(int k=j;p[j]+m-1>=p[k]&&k<=tot;k++){
			if(f[i]+1<f[k]){
				f[k]=f[i]+1;
				g[k]=g[i];
			}
			else if(f[i]+1==f[k]) add(g[k],g[i]);
		}
	}
	printf("%d %dn",f[tot]-1,g[tot]);
	return ;
}
int T;
int main(){
	for(scanf("%d",&T);T;T--){
		Init();
		Solve();
	}
	return 0;
}
```
