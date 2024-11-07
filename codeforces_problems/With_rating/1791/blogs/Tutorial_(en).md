# Tutorial_(en)

We hope you enjoyed the contest!

[1791A - Codeforces Checking](../problems/A._Codeforces_Checking.md "Codeforces Round 849 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1791A - Codeforces Checking](../problems/A._Codeforces_Checking.md "Codeforces Round 849 (Div. 4)")

You need to implement what is written in the statement. You can either use an if-statement for each of the characters $\{\texttt{c}, \texttt{o}, \texttt{d}, \texttt{e}, \texttt{f}, \texttt{r}, \texttt{s}\}$, or you can iterate through the string $\texttt{codeforces}$ check if the current character equals $c$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const string s = "codeforces";

void solve() {
	char c;
	cin >> c;
	for (char i : s) {
		if (i == c) {cout << "YESn"; return;}
	}
	cout << "NOn";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1791B - Following Directions](../problems/B._Following_Directions.md "Codeforces Round 849 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1791B - Following Directions](../problems/B._Following_Directions.md "Codeforces Round 849 (Div. 4)")

We can keep track of our current point $(x,y)$ as we iterate over the string: 

* if $s_i = \texttt{L}$, then decrement $x$ (set $x \leftarrow x-1$);
* if $s_i = \texttt{R}$, then increment $x$ (set $x \leftarrow x+1$);
* if $s_i = \texttt{U}$, then increment $y$ (set $y \leftarrow y+1$);
* if $s_i = \texttt{D}$, then decrement $y$ (set $y \leftarrow y-1$).

 Initially, set $x=y=0$. If $x=y=1$ is ever true, then we should output YES; otherwise, we output NO.The time complexity is $\mathcal{O}(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {x--;}
		if (s[i] == 'R') {x++;}
		if (s[i] == 'D') {y--;}
		if (s[i] == 'U') {y++;}
		if (x == 1 && y == 1) {cout << "YESn"; return;}
	}	
	cout << "NOn";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1791C - Prepend and Append](../problems/C._Prepend_and_Append.md "Codeforces Round 849 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1791C - Prepend and Append](../problems/C._Prepend_and_Append.md "Codeforces Round 849 (Div. 4)")

Let's perform the process in reverse: we will remove the first and last character of the string, if these two characters are different. We should do this as long as possible, since we need to find the shortest initial string. 

So the algorithm is straightfoward: keep track of the left and right characters, and if they are different, remove both. Otherwise, output the length of the current string (or output $0$ if the string became empty).

There are a few ways to implement this. For example, you can keep two pointers, one at the beginning of the string and one at the end, say, $l=1$ and $r=n$, and check if $s_l=s_r$. If it's true, then we increment $l$ and decrement $r$. Otherwise, we output $r-l+1$. We stop when $l \geq r$.

Alternatively, you can use deque to simulate the operations directly. The time complexity is $\mathcal{O}(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = 0, r = n - 1, ans = n;
	while (s[l] != s[r] && ans > 0) {l++; r--; ans -= 2;}
	cout << ans << 'n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1791D - Distinct Split](../problems/D._Distinct_Split.md "Codeforces Round 849 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Candidate Master SlavicG")

 **Tutorial**
### [1791D - Distinct Split](../problems/D._Distinct_Split.md "Codeforces Round 849 (Div. 4)")

Let's check all splitting points $i$ for all ($1 \leq i \leq n - 1$). We denote a splitting point as the last index of the first string we take (and all the remaining characters will go to the second string). We need to keep a dynamic count of the number of distinct characters in both strings $a$ (the first string) and $b$ (the second string). We can do this using two frequency arrays (and adding one to the distinct count of either string $a$ or $b$ when the frequency of a character is greater than zero. 

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long

#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

void solve() {
    int n; string s; cin >> n >> s;
    vector<int> cnt(26, 0), p(26, 0);
    for(auto x: s) cnt[x - 'a']++;
    int ans = 0;
    for(auto x: s) {
        --cnt[x - 'a'];
        ++p[x - 'a'];
        int cur = 0;
        for(int i = 0; i < 26; ++i) {
            cur += min(1, cnt[i]) + min(1, p[i]);
        }
        ans = max(ans, cur);
    }
    cout << ans << "n";
}   
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
```
[1791E - Negatives and Positives](../problems/E._Negatives_and_Positives.md "Codeforces Round 849 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Candidate Master SlavicG")

 **Tutorial**
### [1791E - Negatives and Positives](../problems/E._Negatives_and_Positives.md "Codeforces Round 849 (Div. 4)")

We can notice that by performing any number of operations, the parity of the count of negative numbers won't ever change. Thus, if the number of negative numbers is initially even, we can make it equal to $0$ by performing some operations. So, for an even count of negative numbers, the answer is the sum of the absolute values of all numbers (since we can make all of them positive). And if the count of negative numbers is odd, we must have one negative number at the end. We will choose the one smallest by absolute value and keep the rest positive (for simplicity, we consider $-0$ as a negative number).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        long long sum = 0;
        int negs = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] < 0) {
                ++negs;
                a[i] = -a[i];
            }
            sum += a[i];
        }
        sort(a.begin(), a.end());
        if(negs & 1) sum -= 2 * a[0];
        cout << sum << "n";
    }
}
```
[1791F - Range Update Point Query](../problems/F._Range_Update_Point_Query.md "Codeforces Round 849 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1791F - Range Update Point Query](../problems/F._Range_Update_Point_Query.md "Codeforces Round 849 (Div. 4)")

Let $S(n)$ denote the sum of the digits of $n$. The key observation is the following: after the operation is applied to index $i$ thrice, it won't change after any further operations. The proof$^{\dagger}$ is provided at the bottom of the editorial.

So we only need to update $a_i$ if it's been updated at most $2$ times so far; otherwise, we can ignore it. This allows us to do the following solution: store the current "active" indices (that is, indices that have been updated $\leq 2$ times) in a sorted list (for example, set in C++). Then: 

* $1$ $l$ $r$ — search for the smallest active index at least $l$ (since the list is sorted, we can do it in $\mathcal{O}(\log n)$). Afterwards, update that index (replace $a_i$ with $S(a_i)$), remove it if it's no longer active, and binary search for the next largest active index in the sorted list, until we pass $r$.
* $2$ $x$ — just output $a_x$.

 Although it looks like we take $O((r-l+1) \log (r-l+1))$ time for each update, we actually only ever update each element of the array at most $3$ times, so we will do no more than $3n \log n$ binary searches.Therefore the time complexity is amortized $\mathcal{O}(q + n \log n)$.

$^{\dagger}$ To show this, note that initially $1 \leq a_i \leq 10^9$. The maximum possible value of the sum of the digits of $a_i$ is $81$, achieved when $a_i = 999{,}999{,}999$. So $1 \leq S(a_i) \leq 81$.

Now considering the numbers from $1$ to $81$, the one with maximum sum of digits is $79$, with $S(79)=16$. Hence $1 \leq S(S(a_i)) \leq 16$. Finally, considering the numbers from $1$ to $16$, the one with maximum sum of digits is $9$, so $1 \leq S(S(S(a_i))) \leq 9$. That is, after three operations, $a_i$ becomes a single digit. Any further operations, and it won't change any more.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n) {
    int ret = 0;
    while(n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    set<int> s;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] > 9) s.insert(i);
    }
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int l, r; cin >> l >> r; --l, --r;
            int lst = l;
            while(!s.empty()) {
                auto it = s.lower_bound(lst);
                if(it == s.end() || *it > r) break;
                a[*it] = digit_sum(a[*it]);
                int paiu = *it;
                s.erase(it);
                if(a[paiu] > 9) s.insert(paiu);
                lst = paiu + 1;
            }
        } else {
            int x; cin >> x; --x;
            cout << a[x] << "n";
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	int t; cin >> t;
	while(t--) {
	    solve();
	}
}
```
[1791G1 - Teleporters (Easy Version)](../problems/G1._Teleporters_(Easy_Version).md "Codeforces Round 849 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1791G1 - Teleporters (Easy Version)](../problems/G1._Teleporters_(Easy_Version).md "Codeforces Round 849 (Div. 4)")

It's easy to see that it's optimal to only move right or to use a portal once we are at it. We can notice that when we teleport back, the problem is independent of the previous choices. We still are at point $0$ and have some portals left. Thus, we can just find out the individual cost of each portal, sort portals by individual costs, and take them from smallest to largest by cost as long as we can. The cost of portal $i$ is $i + a_i$ (since we pay $a_i$ to use it and need $i$ moves to get to it).

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long

#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

void solve() {
    int n, c, ans = 0; cin >> n >> c;
    priority_queue<int> q;
    for(int i = 1, x; i <= n; ++i) {
        cin >> x;
        q.push(-x - i);
    }
    while(!q.empty()) {
        int x = -q.top(); q.pop();
        if(x > c) break;
        ++ans;
        c -= x;
    }
    cout << ans << "n";
}   
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
```
[1791G2 - Teleporters (Hard Version)](../problems/G2._Teleporters_(Hard_Version).md "Codeforces Round 849 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1791G2 - Teleporters (Hard Version)](../problems/G2._Teleporters_(Hard_Version).md "Codeforces Round 849 (Div. 4)")

Please also refer to the tutorial for the easy version.

If we are not at the first taken portal, the problem is still independent for each portal, but this time the cost of a portal is $min(a_i + i, a_i + n + 1 - i)$ (since we can come to a portal either from point $0$ or point $n+1$). So, we again sort the portals by their costs. But this time, we need to make sure that the first taken portal is taken from point $0$, so we will iterate over all portals and check the maximum amount of portals we can take if we use it as the first one. We can check this using prefix sums over the minimum cost array and binary searching, checking if the amount of considered portals taken doesn't exceed the number of coins we initially have (we also have to deal with the case when the portal we are considering is included both times as the initial portal and in the minimum cost prefix).

 **Solution**
```cpp
#include <bits/stdc++.h>
#define startt ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long  ll;
using namespace std;
#define vint vector<int>
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define MOD2 998244353
#define MX 1000000000
#define MXL 1000000000000000000
#define PI (ld)2*acos(0.0)
#define pb push_back
#define sc second
#define fr first
#define int long long
#define endl 'n'
#define ld long double
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
int ceildiv(int one, int two) {if (one % two == 0) {return one / two;}else {return one / two + 1;}} int power(int n, int pow, int m) {if (pow == 0) return 1;if (pow % 2 == 0) {ll x = power(n, pow / 2, m);return (x * x) % m;}else return (power(n, pow - 1, m) * n) % m;} int gcd(int a, int b) { if (!b)return a; return gcd(b, a % b);} int factorial(int n, int mod) {if (n > 1)return (n * factorial(n - 1, mod)) % mod; else return 1;} int lcm(int a, int b) {return (a * b) / gcd(a, b);} vector<int> read(int n) {vector<int> a; for (int i = 0; i < n; i++) { int x; cin >> x; a.pb(x);} return a;}struct prefix_sum{vint pref;void build(vint a){pref.pb(0);for(int i = 0; i < a.size(); i++){pref.pb(pref.back()+a[i]);}}int get(int l, int r){return pref[r]-pref[l-1];}};//mesanu

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.pb({x+min(i+1, n-i), x+i+1});
    }
    sort(all(a));
    vector<int> pref;
    pref.pb(0);
    for(int i = 0; i < n; i++)
    {
        pref.pb(pref.back()+a[i].fr);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int new_c = c-a[i].sc;
        int l = 0, r = n;
        int mx = 0;
        while(l <= r)
        {
            int mid = l+r>>1;
            // Calculate price
            int price = pref[mid];
            int now = mid+1;
            if(mid > i)
            {
                price-=a[i].fr;
                now--;
            }
            if(price <= new_c)
            {
                mx = max(now, mx);
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        ans = max(ans, mx);
    }
    cout << ans << endl;
}

int32_t main(){
    startt
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
