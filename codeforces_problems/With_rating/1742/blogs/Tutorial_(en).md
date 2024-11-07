# Tutorial_(en)

Thanks for participating!

[1742A - Sum](../problems/A._Sum.md "Codeforces Round 827 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1742A - Sum](../problems/A._Sum.md "Codeforces Round 827 (Div. 4)")

You only need to write an if statement and check if any of these are true: $a+b=c$, $b+c=a$, $c+a=b$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((a + b == c || c + a == b || b + c == a) ? "YESn" : "NOn");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1742B - Increasing](../problems/B._Increasing.md "Codeforces Round 827 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1742B - Increasing](../problems/B._Increasing.md "Codeforces Round 827 (Div. 4)")

If there are two elements with the same value, then the answer is NO, because neither of these values is less than the other.

Otherwise, the answer is YES, since we can just sort the array.

The time complexity is $\mathcal{O}(n \log n)$ or $\mathcal{O}(n)$ depending on the implementation.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int x[n];
    set<int> a;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(a.find(x[i]) != a.end())
        {
            cout << "NO" << endl;
            return;
        }
        a.insert(x[i]);
    }
    cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
```
[1742C - Stripes](../problems/C._Stripes.md "Codeforces Round 827 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1742C - Stripes](../problems/C._Stripes.md "Codeforces Round 827 (Div. 4)")

Note that if a stripe is painted last, then the entire stripe appears in the final picture (because no other stripe is covering it).

Since rows are only painted red and columns are only painted blue, we can just check if any row contains 8 Rs. If there is such a row, then red was painted last; otherwise, blue was painted last.

 **Bonus**How do you write a validator for this problem? (Given a grid, check if it is a valid input.)

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	char g[8][8];
	vector<int> r;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'R') {r.push_back(i);}
		}
	}
	for (int i : r) {
	    bool ok = true;
	    for (int j = 0; j < 8; j++) {
	        if (g[i][j] != 'R') {ok = false; break;}
	    }
	    if (ok) {cout << "Rn"; return;}
	}
	cout << "Bn";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1742D - Coprime](../problems/D._Coprime.md "Codeforces Round 827 (Div. 4)")

Idea: [badlad](https://codeforces.com/profile/badlad "Expert badlad"), [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1742D - Coprime](../problems/D._Coprime.md "Codeforces Round 827 (Div. 4)")

Note that the array has at most $1000$ distinct elements, since $a_i \leq 1000$. For each value, store the largest index it is in. Then we can brute force all pairs of values, and find the coprime pair with largest sum of indices.

The time complexity is $\mathcal{O}(a_i^2 \log a_i + n)$ per testcase.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

vector<int> pairs[1001];
void solve() {
    int n; cin >> n;
    vector<int> id[1001];
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        id[x].push_back(i);
    }
    int ans = -1;
    for(int i = 1; i <= 1000; ++i) {
        for(int j: pairs[i]) {
            if(!id[i].empty() && !id[j].empty()) {
                ans = max(ans, id[i].back() + id[j].back());
            }
        }
    }
    cout << ans << "n";
}   
 
int32_t main() {
    for(int i = 1; i <= 1000; ++i) {
        for(int j = 1; j <= 1000; ++j) {
            if(__gcd(i, j) == 1) {
                pairs[i].push_back(j);
            }
        }
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
```
[1742E - Scuza](../problems/E._Scuza.md "Codeforces Round 827 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1742E - Scuza](../problems/E._Scuza.md "Codeforces Round 827 (Div. 4)")

Let's compute the prefix sums of the array $a$: let $b_i = a_1 + \dots + a_i$. Rephrasing the problem: for each question containing an integer $k$, we need to find the largest $a_i$ such that $a_1, \dots, a_i$ are all at most $k$, and then output $b_i$. In other words, $\max(a_1, \dots, a_i) \leq k$.

Let's make the prefix maximums of the array: let $m_i = \max(a_1, \dots, a_i)$. Then we need to find the largest $i$ such that $m_i \leq k$, which is doable using binary search, since the array $m$ is non-decreasing. Once we find the index $i$, we simply need to output $b_i$.

The time complexity is $\mathcal{O}(n \log n)$ per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<long long> pref;
    pref.push_back(0);
    vector<int> prefmax;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pref.push_back(pref.back()+x);
        if(i == 0)
        {
            prefmax.push_back(x);
        }
        else
        {
            prefmax.push_back(max(prefmax.back(), x));
        }
    }
    for(int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        int ind = upper_bound(prefmax.begin(), prefmax.end(), k)-prefmax.begin();
        cout << pref[ind] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
```
[1742F - Smaller](../problems/F._Smaller.md "Codeforces Round 827 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1742F - Smaller](../problems/F._Smaller.md "Codeforces Round 827 (Div. 4)")

First of all, let's think about how we should rearrange the two strings in such a way that $a < b$ (if that is ever possible). It's always optimal to arrange $a$'s characters increasingly in lexicographic order and $b$'s characters decreasingly.

Since initially both $a$ and $b$ contain a character "a", the first time $b$ receives any other letter than "a" the answer will always be "YES", because that character will always be lexicographically larger than $a$'s first character which should be "a".

In the other case, we know that $b$ doesn't have any other characters than "a", so we can compare the string $a$ with multiple "a" characters and we know that $a$ will be smaller if and only if it's only formed of "a"s and has a smaller size than $b$.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

void solve() {
    int q; cin >> q;
    bool otherA = false, otherB = false;
    ll cntA = 0, cntB = 0;
    while(q--) {
        ll d, k; string x; cin >> d >> k >> x;
        for(auto c: x) {
            if(d == 1) {
                if(c != 'a') otherA = 1;
                else cntA += k;
            } else {
                if(c != 'a') otherB = 1;
                else cntB += k;
            } 
        }
        if(otherB) {
            cout << "YESn";
        } else if(!otherA && cntA < cntB) {
            cout << "YESn";
        } else {
            cout << "NOn";
        }
    }
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
[1742G - Orray](../problems/G._Orray.md "Codeforces Round 827 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1742G - Orray](../problems/G._Orray.md "Codeforces Round 827 (Div. 4)")

Note that in this context $maxval$ denotes $10^9$.

We can make the observation that only the first $log_2(maxval)$ elements matter, since after placing them optimally we can be sure all bits that could be set in the prefix OR would have already been set. So, we can brute force the optimal choice $log_2(maxval)$ times (we choose to add an element if it provides the largest new prefix OR value among all unused elements) and then just add the rest of the unused elements. 

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    //we care at most about first log2(a) values
    int cur_or = 0;
    vector<bool> vis(n, false);
    for(int i = 0; i < min(31, n); ++i) {
        int mx = 0, idx = -1;
        for(int j = 0; j < n; ++j) {
            if(vis[j]) continue;
            if((cur_or | a[j]) > mx) {
                mx = (cur_or | a[j]);
                idx = j;
            }
        }
        vis[idx] = true;
        cout << a[idx] << " ";
        cur_or |= a[idx];
    }
    forn(i, n) if(!vis[i]) cout << a[i] << " ";
    cout << 'n';
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
