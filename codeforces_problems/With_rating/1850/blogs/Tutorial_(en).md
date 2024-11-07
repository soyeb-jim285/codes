# Tutorial_(en)

Thank you for participating!

[1850A - To My Critics](../problems/A._To_My_Critics.md "Codeforces Round 886 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1850A - To My Critics](../problems/A._To_My_Critics.md "Codeforces Round 886 (Div. 4)")

One way to solve the problem is to check if $a + b + c - min(a, b, c) \geq 10$ using an if statement.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a+b+c-min({a,b,c}) >= 10 ? "YESn" : "NOn");
    
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
[1850B - Ten Words of Wisdom](../problems/B._Ten_Words_of_Wisdom.md "Codeforces Round 886 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1850B - Ten Words of Wisdom](../problems/B._Ten_Words_of_Wisdom.md "Codeforces Round 886 (Div. 4)")

Let's iterate through all responses: if it has $> 10$ words, ignore it. Otherwise, keep track of the maximum quality and its index, and update it as we go along. Then output the index with maximum quality. The time complexity is $\mathcal{O}(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
	int n;
	cin >> n;
	int winner = -1, best_score = 0;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		if (b > best_score && a <= 10) {winner = i; best_score = b;}
	}
	cout << winner << 'n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}


```
[1850C - Word on the Paper](../problems/C._Word_on_the_Paper.md "Codeforces Round 886 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1850C - Word on the Paper](../problems/C._Word_on_the_Paper.md "Codeforces Round 886 (Div. 4)")

You can iterate through the grid and then once you find a letter, iterate downwards until you get the whole word.

However there is an approach that is even faster to code: just input each character, and output it if it is not a dot. This works because we will input the characters in the same order from top to bottom. The complexity is $\mathcal{O}(1)$ regardless.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			char x;
			cin >> x;
			if (x != '.') {cout << x;}
		}
	}	
	cout << 'n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}


```
[1850D - Balanced Round](../problems/D._Balanced_Round.md "Codeforces Round 886 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1850D - Balanced Round](../problems/D._Balanced_Round.md "Codeforces Round 886 (Div. 4)")

Let's calculate the maximum number of problems we can take, and the answer will be $n$ subtracted by that count.

An arrangement that always minimizes the absolute difference between adjacent pairs is the array in sorted order. What we notice, is that if the array is sorted, we will always take a subarray (all taken elements will be consecutive). 

So, the problem converts to finding the largest subarray for which $a_i - a_{i-1} \leq k$. It's easy to see that all the subarrays are totally different (don't share any intersection of elements), thus, we can maintain a count variable of the current number of elements in the current subarray, and iterate through array elements from left to right. If we currently are at $i$ and $a_i - a_{i-1} > k$ then we just set the count to $1$ since we know a new subarray starts, otherwise, we just increase our count by $1$. The answer will be $n$ subtracted by the largest value that our count has achieved.

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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];    
    sort(all(a));
    int cnt = 1, ans = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i] - a[i - 1] > k) {
            cnt = 1;
        } else {
            ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << n - ans << 'n';
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
[1850E - Cardboard for Pictures](../problems/E._Cardboard_for_Pictures.md "Codeforces Round 886 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1850E - Cardboard for Pictures](../problems/E._Cardboard_for_Pictures.md "Codeforces Round 886 (Div. 4)")

The key idea is to binary search on the answer. If you don't know what that is, you should read [this Codeforces EDU article](https://codeforces.com/edu/course/2/lesson/6/2). Let's make a function $f(x)$, which tells us the total area of cardboard if we use a width of $x$. Then you can see that we can calculate $f(x)$ in $\mathcal{O}(n)$ time as $(a_1 + 2x)^2 + (a_2 + 2x)^2 + \dots + (a_n + 2x)^2$, because the side length of the $i$-th cardboard is $a_i + 2x$.

So this means that now we can binary search on the answer: let's find the largest $w$ so that $f(w) \leq c$. The maximum theoretical value of $w$ can be seen not to exceed $10^9$, since $c$ is not more than $10^{18}$ (you can set an even lower bound).

A quick note about implementation: the value of $f(x)$ can exceed 64-bit numbers, so you need to exit the function as soon as you get a value greater than $c$, or else you risk overflow.

So the time complexity is $\mathcal{O}(n \log(10^9))$ per test case, which is equal to $\mathcal{O}(n)$ with some constant factor. It's not that big to make it fail.

You can also use the quadratic formula, but be careful about implementation of square root and precision issues.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
 
#define int long long
 
void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int l = 1, r = 1e9;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int sumall = 0;
        for(int i = 0; i < n; ++i) {
            sumall += (a[i] + 2 * mid) * (a[i] + 2 * mid);
            if(sumall > c) break;
        }
        if(sumall == c) {
            cout << mid << "n";
            return;
        }
        if(sumall > c) {
            r = mid - 1;
        } else {
            l = mid + 1;
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
[1850F - We Were Both Children](../problems/F._We_Were_Both_Children.md "Codeforces Round 886 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu") & [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1850F - We Were Both Children](../problems/F._We_Were_Both_Children.md "Codeforces Round 886 (Div. 4)")

We disregard any $a_i$ larger than $n$ since we can't catch them anyway. We keep in $cnt_i$ how many frogs we have for each hop distance. We go through each $i$ from $1$ to $n$ and add $cnt_i$ to every multiple of $i$ smaller or equal to $n$. This action is a harmonic series and takes $O(nlogn)$ time. We go through all from $1$ to $n$ and take the maximum.

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
    int n; cin >> n;
    vector<ll> cnt(n + 1, 0), mx(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x <= n) ++cnt[x];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; j += i) mx[j] += cnt[i];
    }
    cout << *max_element(all(mx)) << "n";
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
[1850G - The Morning Star](../problems/G._The_Morning_Star.md "Codeforces Round 886 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1850G - The Morning Star](../problems/G._The_Morning_Star.md "Codeforces Round 886 (Div. 4)")

Let's look at four directions of the line connecting the compass and morning star: vertical, horizontal, with slope $1$ (looks like /), and with slope $-1$ (looks like \). 

* vertical: the two points need to have the same $y$-coordinate. If there are $k$ points with the same $y$-coordinate, then how many pairs are possible for the morning star and compass? Well, there are $k$ possibilities for the compass, and $k-1$ for the morning star, so there are a total of $k(k-1)$ valid pairs. In this case, we can use a data structure like a C++ map to count the number of points at each $y$-coordinate, and add $k(k-1)$ to the total for each $k$ in the map.
* horizontal: the two points need to have the same $x$-coordinate. Similarly, we count pairs with the same $x$-coordinate using a map.
* slope $1$: note that all lines of this form can be written as $x-y=c$ for a constant $c$. (Draw some examples out for $c=-1, 0, 1$.) So we can use a map to count values of $x-y$, and add to the total.
* slope $-1$: similarly, all such lines can be written as $x+y=c$ for a constant $c$.

 The time complexity is $\mathcal{O}(n \log n)$. **Solution**
```cpp
#include <bits/stdc++.h>
#define startt ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long  ll;
using namespace std;
#define vint vector<int>
#define all(v) v.begin(), v.end()
#define int long long
 
void solve()
{
    int n;
    cin >> n;
    map<int, int> up, side, diag1, diag2;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        up[x]++;
        side[y]++;
        diag1[x-y]++;
        diag2[x+y]++;
    }
    for(auto x : up)
    {
        ans+=x.second*(x.second-1);
    }
    for(auto x : side)
    {
        ans+=x.second*(x.second-1);
    }
    for(auto x : diag1)
    {
        ans+=x.second*(x.second-1);
    }for(auto x : diag2)
    {
        ans+=x.second*(x.second-1);
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
[1850H - The Third Letter](../problems/H._The_Third_Letter.md "Codeforces Round 886 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1850H - The Third Letter](../problems/H._The_Third_Letter.md "Codeforces Round 886 (Div. 4)")

We can view the conditions and soldiers as a directed graph. The soldiers represent nodes and the conditions represent directed edges. Saying $a_i$ should be $d_i$ meters in front of $b_i$ is equivalent to adding two weighted directed edges: 

* An edge from $a_i$ to $b_i$ with weight $d_i$.
* An edge from $b_i$ to $a_i$ with weight $-d_i$.

Now, we iterate over all $n$ soldiers, and do a standard dfs whenever we encounter an unvisited soldier, assigning coordinates respecting the weights of the edges. That is, for the first soldier in the set we can just set his coordinate to $0$, then for every neighbor we visit we set it's coordinate to the coordinate of the current node added by the weight of the edge between it and its neighbor.

Finally, we check at the end if all of the $m$ conditions are satisfied.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
 
#define int long long
const int N = 2e5 + 5;
vector<pair<int, int>> adj[N];
int val[N], vis[N];
void dfs(int u) {
    vis[u] = 1;
    for(auto x: adj[u]) {
        int v = x.first, w = x.second;
        if(!vis[v]) {
            val[v] = val[u] + w;
            dfs(v);
        }
    }
}
void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        adj[i].clear();
        vis[i] = 0, val[i] = 0;
    }
    vector<array<int, 3>> c;
    for(int i = 1; i <= m; ++i) {
        int a, b, d; cin >> a >> b >> d;
        adj[a].pb({b, d});
        adj[b].pb({a, -d}); 
        c.pb({a, b, d});  
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= m; ++i) {
        int a = c[i - 1][0], b = c[i - 1][1], d = c[i - 1][2];
        if(val[a] + d != val[b]) {
            cout << "NOn";
            return;
        }
    }
    cout << "YESn";
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
