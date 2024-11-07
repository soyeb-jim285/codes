# Tutorial

[1931A - Recovering a Small String](../problems/A._Recovering_a_Small_String.md "Codeforces Round 925 (Div. 3)")

Idea: [myav](https://codeforces.com/profile/myav "Pupil myav") Prepared by: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1931A - Recovering a Small String](../problems/A._Recovering_a_Small_String.md "Codeforces Round 925 (Div. 3)")

The problem can be solved by simply going through all the 3 letter combinations and searching for the lexicographically minimal one among them.

It is also possible to consider a string consisting of three letters "a", and, going through it from the end until the value of n is greater than zero, increase the letters to the maximum possible value and subtract the corresponding difference from n.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
 
 
void solve(){
    int n, sz = 26;
    cin >> n;
    string mins = "zzz", cur;
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            for(int k = 0; k < sz; k++){
                if(i + j + k + 3 == n){
                    cur += char(i + 'a');
                    cur += char(j + 'a');
                    cur += char(k + 'a');
                    mins = min(cur, mins);
                }
            }
        }
    }
    cout << mins << "n";
 
}
int main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
```
[1931B - Make Equal](../problems/B._Make_Equal.md "Codeforces Round 925 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") Prepared by: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1931B - Make Equal](../problems/B._Make_Equal.md "Codeforces Round 925 (Div. 3)")

Since the number of operations does not matter, let's find any suitable sequence of operations.

Each vessel should contain k=∑ain units of water. Water can only be poured to the right, so we will iterate over i from 1 to n−1 and pour all the excess water from the i-th vessel to the (i+1)-th. If at some point there is not enough water in the i-th vessel, the answer is NO.

 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    k = sum(a) // n
    for i in range(n - 1):
        if a[i] < k:
            print('NO')
            return
        a[i + 1] += a[i] - k
        a[i] = k
    print('YES')
    
    
for _ in range(int(input())):
    solve()
```
[1931C - Make Equal Again](../problems/C._Make_Equal_Again.md "Codeforces Round 925 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin") Prepared by: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1931C - Make Equal Again](../problems/C._Make_Equal_Again.md "Codeforces Round 925 (Div. 3)")

If all the elements of the arrays are equal, then nothing additional needs to be done, and the answer is 0. Otherwise, you need to apply the assignment operation on the segment alone.

Our goal is to choose the shortest possible segment, which means to exclude as many elements as possible from the beginning and end of the segment. Note that we can exclude only equal elements, and then assign a value equal to the excluded elements on the segment. Let's find the lengths of the maximum prefix and suffix consisting of equal elements. Let's denote by k the number of excluded elements, by k1 — the length of the maximum suitable prefix, by k2 — the maximum suitable suffix. Then if a0=an−1, then k=k1+k2 (exclude both prefix and suffix), otherwise k=max(k1,k2) (exclude the longer one).

The answer is n−k — all non-excluded elements must be replaced so that they become equal to the excluded one.

 **Solution**
```cpp
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    i1 = 0
    i2 = 0
    while i1 < n and a[i1] == a[0]:
        i1 += 1
    while i2 < n and a[n - i2 - 1] == a[n - 1]:
        i2 += 1
    res = n
    if a[0] == a[n - 1]:
        res -= i1
        res -= i2
    else:
        res -= max(i1, i2)
    print(max(0, res))
 
 
t = int(input())
 
 
for i in range(t):
    solve()
```
[1931D - Divisible Pairs](../problems/D._Divisible_Pairs.md "Codeforces Round 925 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") Prepared by: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1931D - Divisible Pairs](../problems/D._Divisible_Pairs.md "Codeforces Round 925 (Div. 3)")

Let's consider a good pair.

Since (ai+aj)modx=0, it follows that (aimodx+ajmodx)modx=0, which implies that aimodx+ajmodx is either x or 0. Therefore, for some j, this holds true if aimodx=(x−ajmodx)modx.

Since (ai−aj)mody=0, it follows that aimody−ajmody=0, which implies that aimody=ajmody.

Thus, for some fixed aj, all ai will fit the following criteria:

* i<j;
* aimodx=(x−ajmodx)modx;
* aimody=ajmody.

We will iterate through j from left to right and maintain the count of elements with specific pairs ⟨aimodx,aimody⟩ using a map on the prefix.

 **Solution**
```cpp
def solve():
    n, x, y = map(int, input().split())
    a = [int(x) for x in input().split()]
    cnt = dict()
    ans = 0
    for e in a:
        xx, yy = e % x, e % y
        ans += cnt.get(((x - xx) % x, yy), 0)
        cnt[(xx, yy)] = cnt.get((xx, yy), 0) + 1
    print(ans)
    
    
for _ in range(int(input())):
    solve()
```
[1931E - Anna and the Valentine's Day Gift](../problems/E._Anna_and_the_Valentine's_Day_Gift.md "Codeforces Round 925 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40") Prepared by: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1931E - Anna and the Valentine's Day Gift](../problems/E._Anna_and_the_Valentine's_Day_Gift.md "Codeforces Round 925 (Div. 3)")

If the decimal representation of a number x has exactly c digits, then x≥10c−1. From this, it can be concluded that Sasha is not required to maximize the final number; it is sufficient for him to maximize the number of digits in it.

During his turn, Sasha does not change the total number of digits, but Anna can change it. It is easy to understand that the total number of digits cannot increase, but it can decrease if Anna removes trailing zeros from a number (1200→21).

Now the optimal strategy for Sasha and Anna can be formulated. Anna should choose a number with the largest number of trailing zeros and remove them. Sasha should find a number with the largest number of trailing zeros and concatenate it with any other number. Thus, since 1≤ai, he will preserve the zeros of this number (100500,2007→1005002007).

Implementing such a solution in O(nlogn) can be done using sorting and linear traversal or by using std::set. If desired, counting sort can be used to improve the asymptotic complexity to linear.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
#define all(arr) arr.begin(), arr.end()
 
using namespace std;
 
const int MAXN = 200200;
 
int n, m;
string arr[MAXN];
int len[MAXN], zrr[MAXN];
 
void build() {
    memset(zrr, 0, sizeof(*zrr) * n);
    for (int i = 0; i < n; ++i) {
        len[i] = arr[i].size();
        for (auto it = arr[i].rbegin(); it != arr[i].rend() && *it == '0'; ++it) {
            ++zrr[i];
        }
    }
}
 
string solve() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += len[i] - zrr[i];
    }
    sort(zrr, zrr + n);
    reverse(zrr, zrr + n);
    for (int i = 0; i < n; ++i) {
        if (i & 1) ans += zrr[i];
    }
    return (ans - 1 >= m ? "Sasha" : "Anna");
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        build();
        cout << solve() << 'n';
    }
}
```
[1931F - Chat Screenshots](../problems/F._Chat_Screenshots.md "Codeforces Round 925 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin") Prepared by: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1931F - Chat Screenshots](../problems/F._Chat_Screenshots.md "Codeforces Round 925 (Div. 3)")

The author of the screenshot is always in the first position, so based on his screenshot, nothing can be said about his first position. The rest of the chat participants are ordered based on the real order. 

Let's build a graph of n vertices. For each screenshot, add n−2 edges. For all 2≤i<n, add an edge between the vertices aji and aji+1, where j is the number of the current screenshot.

If there is an order that satisfies all screenshots, then topological sorting will exist in this graph, which means there will be no cycles in it. So our goal is to check the graph for acyclicity.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
int timer = 0;
 
void dfs(int v, vector<vector<int>> &g, vector<bool> &vis, vector<int> &tout) {
    vis[v] = true;
    for (int u: g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis, tout);
        }
    }
    tout[v] = timer++;
}
 
void solve() {
    timer = 0;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k, vector<int>(n));
    vector<int> authors(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i][j]--;
        }
        authors[i] = a[i][0];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j + 1 < n; ++j) {
            int i1 = a[i][j], i2 = a[i][j + 1];
            g[i1].push_back(i2);
        }
    }
    vector<int> tout(n, -1);
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (tout[i] == -1) {
            dfs(i, g, vis, tout);
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j + 1 < n; ++j) {
            int i1 = a[i][j], i2 = a[i][j + 1];
            if (tout[i1] < tout[i2]) {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}
 
int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
        cout << "n";
    }
}
```
[1931G - One-Dimensional Puzzle](../problems/G._One-Dimensional_Puzzle.md "Codeforces Round 925 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin") Prepared by: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1931G - One-Dimensional Puzzle](../problems/G._One-Dimensional_Puzzle.md "Codeforces Round 925 (Div. 3)")

Note that the elements of the 3 and 4 types on the right have a connection type opposite to that on the left. This means that what type of connection should be at the end of the chain to attach an element of any of these types will remain the same. Therefore, elements of these types can be combined into separate chains consisting only of elements of the same type. Joining such a chain will not change the type of connection at the end. Therefore, the basis of the chain consists of elements of the 1 and 2 types. First, you need to make the basis of a chain of only them, and then insert an arbitrary set of chains of elements of the 3 and 4 types.

In order to make the basis of the chain possible, it is necessary that |c1−c2|≤1 be executed. Otherwise, there will be extra elements left, and the answer is 0. The basis of the chain can start with an element of type i (1≤i≤2) if ci≥cj, where j=3−i — an element of the opposite type (1 for 2 and vice versa). If c1=c2, then there are 2 options for the basis of the chain, and they need to be counted separately.

To find the number of combinations at a fixed base of the chain, we calculate two values independently, and then multiply them:

* x1 — the number of ways to arrange chains of 3-type elements after 1-type elements.
* x2 — the number of ways to arrange chains of 4-type elements after 2-type elements.

x1 and x2 are calculated using the same formula, also known as the formula of balls and partitions. We want to arrange m elements (m is equal to x3 or x4, depending on which value we calculate). To arrange them, we have n=n0+add positions, where n0 is the number of elements of type 1 or 2 (similar to m), and add is the value required to process an additional position equal to 1 if the basis of the chain begins with an element of another type (then we can put the chain in front of it, for example, several elements of the 4 type in front of the 1 type element), and 0 otherwise.

The number of ways to arrange m indistinguishable elements in n positions is Cmn+m−1, where Ckn is the number of combinations.

To calculate the answer, multiply the values of x1 and x2, and in the case when c1=c2 — sum the resulting products.

 **Solution**
```cpp
  
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int mod = 998244353;
 
ll pow_mod(ll x, ll p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        ll y = pow_mod(x, p / 2);
        return (y * y) % mod;
    }
    return (x * pow_mod(x, p - 1)) % mod;
}
 
ll inv(ll x) {
    return pow_mod(x, mod - 2);
}
 
vector<ll> fact = {1};
 
ll cnk(ll n, ll k) {
    ll res = fact[n];
    res = (res * inv(fact[k])) % mod;
    res = (res * inv(fact[n - k])) % mod;
    return res;
}
 
ll calc(int n1, int n2, int n3, int n4) {
    return (cnk(n1 + n3 - 1, n3) * cnk(n2 + n4 - 1, n4)) % mod;
}
 
void solve() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    if (n1 + n2 == 0) {
        cout << (n3 == 0 || n4 == 0 ? 1 : 0) << 'n';
        return;
    }
    if (abs(n1 - n2) > 1) {
        cout << "0n";
        return;
    }
    ll res = 0;
    if (n1 <= n2) {
        res += calc(n1 + 1, n2, n3, n4);
    }
    if (n2 <= n1) {
        res += calc(n1, n2 + 1, n3, n4);
    }
    cout << res % mod << 'n';
}
 
int main() {
    for (ll i = 1; i <= 4e6; ++i) {
        fact.push_back((fact.back() * i) % mod);
    }
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
}
```
