# Tutorial_(en)

We hope you enjoyed the contest!

[1915A - Odd One Out](../problems/A._Odd_One_Out.md "Codeforces Round 918 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1915A - Odd One Out](../problems/A._Odd_One_Out.md "Codeforces Round 918 (Div. 4)")

You can write three if-statements to find the equal pair, and output the correct answer.

A shorter solution: output the bitwise XOR of a, b, and c. It works, since any number XORed with itself is 0, so the two equal numbers will "cancel" and you will be left with the odd number out.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200'007;
const int MOD = 1'000'000'007;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a ^ b ^ c) << 'n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1915B - Not Quite Latin Square](../problems/B._Not_Quite_Latin_Square.md "Codeforces Round 918 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1915B - Not Quite Latin Square](../problems/B._Not_Quite_Latin_Square.md "Codeforces Round 918 (Div. 4)")

There are many solutions. For example, look at the row with the question mark, and write some if statements to check the missing letter.

A shorter solution: find the count of each letter. The one that appears only twice is the missing one.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200'007;
const int MOD = 1'000'000'007;

void solve() {
	int cnt[3] = {};
	for (int i = 0; i < 9; i++) {
		char c;
		cin >> c;
		if (c != '?') {cnt[c - 'A']++;}
	}	
	for (int i = 0; i < 3; i++) {
		if (cnt[i] < 3) {cout << (char)('A' + i) << 'n';}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1915C - Can I Square?](../problems/C._Can_I_Square_.md "Codeforces Round 918 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Master SlavicG")

 **Tutorial**
### [1915C - Can I Square?](../problems/C._Can_I_Square_.md "Codeforces Round 918 (Div. 4)")

You should add up all the values to get the sum s. Then we just need to check if s is a perfect square. There are many ways, for example you can use inbuilt sqrt function or binary search. Be careful with precision errors, since sqrt function might return a floating-point type.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

bool is_square(ll x) {
    ll l = 1, r = 1e9;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if(mid * mid == x) return true;
        if(mid * mid > x) r = mid - 1;
        else l = mid + 1;
    }      
    return false;  
}
void solve() {
    ll n; cin >> n;
    ll s = 0;
    for(int i = 0, x; i < n; ++i) {
        cin >> x; s += x;
    }
    if(is_square(s)) cout << "YESn";
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
[1915D - Unnatural Language Processing](../problems/D._Unnatural_Language_Processing.md "Codeforces Round 918 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1915D - Unnatural Language Processing](../problems/D._Unnatural_Language_Processing.md "Codeforces Round 918 (Div. 4)")

There are many solutions. Below is the simplest one:

Go through the string in reverse (from right to left). If the last character is a vowel, it must be part of CV syllable — else, CVC syllable. So we can go back 2 or 3 characters appropriately, insert ., and continue.

The complexity is O(n) if implemented well.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200'007;
const int MOD = 1'000'000'007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string res = "";
	while (!s.empty()) {
		int x;
		if (s.back() == 'a' || s.back() == 'e') {x = 2;}
		else {x = 3;}
		
		while (x--) {
			res += s.back();
			s.pop_back();
		}
		res += '.';
	}
	res.pop_back();
	reverse(res.begin(), res.end());
	cout << res << 'n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1915E - Romantic Glasses](../problems/E._Romantic_Glasses.md "Codeforces Round 918 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1915E - Romantic Glasses](../problems/E._Romantic_Glasses.md "Codeforces Round 918 (Div. 4)")

Let's rewrite the given equation: al+al+2+al+4+⋯+ar=al+1+al+3+⋯+ar−1 as al−al+1+al+2−al+3+al+4+⋯−ar−1+ar=0. From here, it's clear that we need to find if there is a subarray with alternating sum equal to 0.

How to check this? Let's flip all elements on even indices a2→−a2,a4→−a4,…. Then alternating sums of [a1,a2,a3,a4,…] are the same as subarray sums on [a1,−a2,a3,−a4,…].

So we just need to check if there is a subarray with sum 0. This is a standard problem with prefix sums: if two prefix sums are equal, then the subarray between them has sum 0; otherwise, no subarray has sum 0.

The complexity is O(n) or O(nlogn) depending on how you check if two elements of an array are equal. Be careful about using hash tables, as they can be hacked.

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
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    map<ll, ll> m;
    ll s = 0;
    m[0] = 1;
    for(int i = 0; i < n; ++i) {
        a[i] *= ((i % 2) ? -1 : 1);
        s += a[i];
        if(m[s]) {
            cout << "YESn";
            return;
        }
        ++m[s];
    }
    cout << "NOn";
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
[1915F - Greetings](../problems/F._Greetings.md "Codeforces Round 918 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1915F - Greetings](../problems/F._Greetings.md "Codeforces Round 918 (Div. 4)")

Let's consider two persons 1 and 2. When do they meet each other?

We can treat a person traveling from point a to point b as a segment [a,b]. Notice that they meet when a1<a2 and b2<b1, or a2<a1 and b1<b2; or in other words, when one segment contains another.

We can count the number of pairs when one fully contains another, which is a quite classic problem, and can be solved by iterating over the segments in increasing order of the b position and for each of them adding the number of segments that we have already passed that have an a value larger than the one of the current segment.

The time complexity is O(nlogn).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
int t, n;
 
vector<pair<int, int>> arr;
 
long long ans;
 
ordered_set st;
 
void solve(){
    cin >> n;
 
    arr.assign(n, {});
 
    for(auto &p : arr) cin >> p.second >> p.first;
 
    sort(arr.begin(), arr.end());
 
    ans = 0;
    st.clear();
 
    for(auto p : arr){
        ans += st.size() - st.order_of_key(p.second);
 
        st.insert(p.second);
    }
 
    cout << ans << "n";
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    cin >> t;
 
    while(t--){
        solve();
    }
}
```
[1915G - Bicycles](../problems/G._Bicycles.md "Codeforces Round 918 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Master SlavicG")

 **Tutorial**
### [1915G - Bicycles](../problems/G._Bicycles.md "Codeforces Round 918 (Div. 4)")

We can build a graph with n⋅1000 nodes, where each node is responsible for the pair (i,s), where i is the index of the city and s is the speed we have when we are at this city. Then, we can use Dijkstra's algorithm to compute the shortest path on this graph by considering all edges of node i (when we are at a pair which has i as the city), and the new s would be the minimum value of si and sj where j is the neighboring city we are considering.

After computing all shortest paths from node (1,s1), we just find the minimum value of (n,j) for all j from 1 to 1000, and that will be our answer.

 **Solution**
```cpp
#include "bits/stdc++.h"

const int64_t inf = 1e18;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<std::pair<int, int>> adj[n];
    for(int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w; --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    std::vector<int> s(n);
    for(int& i: s) std::cin >> i;

    std::vector<std::vector<int64_t>> dist(n, std::vector<int64_t>(1001, inf));
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(1001, false));
    
    dist[0][s[0]] = 0;
    std::priority_queue<std::array<int64_t, 3>> q;
    q.push({0, 0, s[0]});
    while(!q.empty()) {
        int u = q.top()[1], k = q.top()[2];
        q.pop();
        if(vis[u][k] || dist[u][k] == inf) continue;
        vis[u][k] = true;
        for(auto x: adj[u]) {
            int v = x.first, w = x.second;
            int c = std::min(s[v], k);
            if(dist[v][c] > dist[u][k] + 1LL * w * k) {
                dist[v][c] = dist[u][k] + 1LL * w * k;
                q.push({-dist[v][c], v, c});
            }
        }
    }
    int64_t ans = inf;
    for(int k = 1; k <= 1000; ++k) 
        ans = std::min(ans, dist[n - 1][k]);
    std::cout << ans << "n";
}   
 
int main() {
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    int t = 1; std::cin >> t;
    while(t--) {
        solve();
    }
}
```
