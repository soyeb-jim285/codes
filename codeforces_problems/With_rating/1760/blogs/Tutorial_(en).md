# Tutorial_(en)

We hope you enjoyed the contest! Sorry for the late editorial.

[1760A - Medium Number](../problems/A._Medium_Number.md "Codeforces Round 835 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1760A - Medium Number](../problems/A._Medium_Number.md "Codeforces Round 835 (Div. 4)")

Here are two ways to implement what's given in the problem:

1. Take input as an array [a1,a2,a3], and sort it. Output the middle element.
2. Write two if-statements. The first: if (a>b and a<c) or (a<b and a>c), output a. Else, if (b>a and b<c) or (b<a and b>c), output b. Else, output c.
 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << a[1] << 'n';	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1760B - Atilla's Favorite Problem](../problems/B._Atilla's_Favorite_Problem.md "Codeforces Round 835 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Candidate Master SlavicG")

 **Tutorial**
### [1760B - Atilla's Favorite Problem](../problems/B._Atilla's_Favorite_Problem.md "Codeforces Round 835 (Div. 4)")

To solve the problem we need to find the character with the highest alphabetical order in our string, since Atilla will need at least that alphabet size and won't need more. To do this iterate through the string and find the character with the highest alphabetical order. Output the maximum alphabetical order found. The solution can be done in O(n).

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

void solve() {
    int n; string s; cin >> n >> s;
    sort(all(s));
    cout << s.back() - 'a' + 1 << "n";
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
[1760C - Advantage](../problems/C._Advantage.md "Codeforces Round 835 (Div. 4)")

Idea: [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto")

 **Tutorial**
### [1760C - Advantage](../problems/C._Advantage.md "Codeforces Round 835 (Div. 4)")

Make a copy of the array s: call it t. Sort t in non-decreasing order, so that t1 is the maximum strength and t2 — the second maximum strength.

Then for everyone but the best person, they should compare with the best person who has strength t1. So for all i such that si≠t1, we should output si−t1. Otherwise, output si−t2 — the second highest strength, which is the next best person.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
        vector<int> b(a);
        sort(b.begin(), b.end());
        forn(i, n) {
            if (a[i] == b[n - 1])
                cout << a[i] - b[n - 2] << " ";
            else
                cout << a[i] - b[n - 1] << " ";
        }
        cout << endl;
   }
}
```
[1760D - Challenging Valleys](../problems/D._Challenging_Valleys.md "Codeforces Round 835 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1760D - Challenging Valleys](../problems/D._Challenging_Valleys.md "Codeforces Round 835 (Div. 4)")

One possible solution is to represent a range of equal element as a single element with that value. Construct this array b and loop through it and check how many element bi satisfy the conditions i=0 or bi−1<bi and i=n−1 or bi>bi+1. If exactly one index satisfies these conditions, print "YES" and othewise "NO".

Complexity: O(n)

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(i == 0 || x != a.back())
        {
            a.push_back(x);
        }
    }
    int num_valley = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if((i == 0 || a[i-1] > a[i]) && (i == a.size()-1 || a[i] < a[i+1]))
        {
            num_valley++;
        }
    }
    if(num_valley == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1760E - Binary Inversions](../problems/E._Binary_Inversions.md "Codeforces Round 835 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Candidate Master SlavicG")

 **Tutorial**
### [1760E - Binary Inversions](../problems/E._Binary_Inversions.md "Codeforces Round 835 (Div. 4)")

Let's find out how to count the number of binary inversions, without flips. This is the number of 1s that appear before a 0. To do this, iterate through the array and keep a running total k of the number of 1s seen so far. When we see a 0, increase the total inversion count by k, since this 0 makes k inversions: one for each of the 1s before it.

Now let's see how to maximize the inversions. Consider the flip 0→1. We claim that it is best to always flip the earliest 0 in the array. It's never optimal to flip a later 0, since we have strictly fewer 0s after it to form inversions. Similarly, we should flip the latest 1 in the array.

Now recalculate the answer for these two choices for flipping, and pick the maximum. The complexity is O(n).

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

ll calc(vector<int>& a) {
    ll zeroes = 0, ans = 0;
    for(int i = sz(a) - 1; i >= 0; --i) {
        if(a[i] == 0) ++zeroes;
        else ans += zeroes;
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    ll ans = calc(a);
    forn(i, n) {
        if(a[i] == 0) {
            a[i] = 1;
            ans = max(ans, calc(a));
            a[i] = 0;
            break;
        }
    }
    for(int i = n - 1; i >= 0; --i) {
        if(a[i] == 1) {
            a[i] = 0;
            ans = max(ans, calc(a));
            a[i] = 1;
            break;
        }
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
[1760F - Quests](../problems/F._Quests.md "Codeforces Round 835 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1760F - Quests](../problems/F._Quests.md "Codeforces Round 835 (Div. 4)")

Let's fix k and find the maximum number of coins we can get. Here we can do a greedy solution: at every step, we should always take the most rewarding quest. (Intuitively, it makes sense, since doing more rewarding quests earlier allows us to do them again later.) If no quests are available, we do nothing. 

To implement this, sort the quests in decreasing order, and 0-index them. On day i we should do quest imodk, provided that this value is less than n. This is because after every k days, we cycle back to the first quest. Thus we solved the problem for a fixed k in O(d) with O(nlogn) precomputation to sort the array.

Now to solve the problem, we can binary search on the answer, since if some k works, then all smaller k work. The minimum value of k is 0, and the maximum value is n (for larger k, we won't be able to do the same quest multiple times anyways, so it's useless to consider them). 

If we find that k always goes towards the smaller end of our binary search and k=0 still fails, we output Impossible. If we find that k always goes towards the larger end of our binary search and k=n still fails, we output Infinity. Otherwise, just output k.

The overall time complexity is O(nlogn+dlogn).

Remark. It is not hard to improve the solution to O(nlogn). Originally, I proposed the problem this way, but we ended up removing this part of the problem because the implementation of this solution was tricky enough.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, d;
	long long c;
	cin >> n >> c >> d;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<long long>());
	int l = 0, r = d + 2;
	while (l < r) {
		int m = l + (r - l + 1) / 2;
		long long tot = 0;
		int curr = 0;
		for (int i = 0; i < d; i++) {
			if (i % m < n) {tot += a[i % m];}
		}
		if (tot >= c) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	if (l == d + 2) {cout << "Infinityn"; return;}
	if (l == 0) {cout << "Impossiblen"; return;}
	cout << l - 1 << 'n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1760G - SlavicG's Favorite Problem](../problems/G._SlavicG's_Favorite_Problem.md "Codeforces Round 835 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Candidate Master SlavicG")

 **Tutorial**
### [1760G - SlavicG's Favorite Problem](../problems/G._SlavicG's_Favorite_Problem.md "Codeforces Round 835 (Div. 4)")

Let's ignore the teleporting, and decide how to find the answer. Note that we don't need to ever go over an edge more than once, since going over an edge twice cancels out (since a XOR a=0 for all a). In other words, the only possible value of x equals the XOR of the edges on the unique path from a to b. We can find it through a BFS from a, continuing to keep track of XORs as we move to each adjacent node, and XORing it by the weight of the corresponding edge as we travel across it.

Now let's include the teleport. It means that we travel from a→c, then teleport to d, and go from d→b, for some nodes c and d. Also, we cannot pass b on the path from a→c.

Again, note that the value of x is fixed on each of the paths from a→c and d→b, since there is a unique path between them. Let x1 be the XOR of the first path and x2 be the XOR of the second. Then we need x1 XOR x2=0⟹x1=x2. So we need to find if there are two nodes c, d such that the XORs from a and b to those nodes are the same. To do this, we can do our BFS from before, but instead run one BFS from a and another from b, and check if any two values are the same.

Make sure not to include nodes past b while we look for c on our BFS from a.

The time complexity is O(nlogn).

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

const int N = 1e5 + 10;
vector<pair<int, int>> adj[N];
set<int> s;
bool ok = true;
int n, a, b;
void dfs1(int u, int par, int x) {
    if(u == b) return;
    s.insert(x);
    for(auto e: adj[u]) {
        int v = e.first, w = e.second;
        if(v == par) continue;
        dfs1(v, u, x ^ w);
    }
}

bool dfs2(int u, int par, int x) {
    if(u != b && s.count(x)) return true;
    for(auto e: adj[u]) {
        int v = e.first, w = e.second;
        if(v == par) continue;
        if(dfs2(v, u, w ^ x)) return true;
    } 
    return false;
}

void solve() {
    s.clear();
    cin >> n >> a >> b; --a, --b;
    forn(i, n) adj[i].clear();
    for(int i = 0; i < n - 1; ++i) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs1(a, -1, 0);
    if(dfs2(b, -1, 0)) cout << "YESn";
    else cout << "NOn";
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
