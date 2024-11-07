# Tutorial_(en)

[1935A - Entertainment in MAC](../problems/A._Entertainment_in_MAC.md "Codeforces Round 932 (Div. 2)")

Idea: [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Expert i_love_penguins")   
 Preparation: [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Expert i_love_penguins")   
 Editorial: [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Expert i_love_penguins")

 **Hints****Hint 1**The answer will always have either the prefix s, or the reversed string s.

 **Hint 2**Adding the string to the end is required no more than once.

 **Solution**Let t be the reversed string s. Notice that it is advantageous for us to use operation 1 (adding the reversed string at the end) no more than once. Indeed, having obtained some string, we will simply spend the remaining operations on flipping the string. Thus, we will get the original string or the reversed one, depending on the parity of the number of remaining operations.

It is easy to see that the answer will always have either the prefix s, or t. Then, we find two lexicographically minimal strings with the prefix s and t. These will be strings:

s, flip the string n times (since n is even, every 2 operations we return the string to its original) t+s, initially flip the string, add the reversed string to the end, then flip the string n−2 times. The answer will be the lexicographically minimal string out of s and t+s.

 **Implementation on C++**
```cpp
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        std::string t = s;
        reverse(t.begin(), t.end());
        std::cout << std::min(s, t + s) << "n";
    }

    return 0;
}
```
 **Implementation on Python**
```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    t = s[::-1]
    print(min(s, t + s))

```
[1935B - Informatics in MAC](../problems/B._Informatics_in_MAC.md "Codeforces Round 932 (Div. 2)")

Idea: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Candidate Master AndreyPavlov")   
 Preparation: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Candidate Master AndreyPavlov"), [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Expert i_love_penguins")   
 Editorial: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Candidate Master AndreyPavlov")

 **Hints****Hint 1**What is the minimum k that can be in a division?

 **Hint 2**Suppose MEX(x,y)=MEX(y+1,z), what can be said about MEX(x,z)?

 **Tutorial**Suppose we correctly divided the array into k>2 segments — (1,r1),(l2,r2),…,(lk,rk). Then, note that we can merge first two subsegments, as the numbers from 0 to mex−1 are encountered in these two segments and the number mex is not encountered in them. Therefore, if there is a division into k>2 segments, then there is also for k−1 segments.

Therefore, it is sufficient to check whether there is a division of the array into k=2 segments, which can be done in O(n) by precalcing MEX on the prefixes and suffixes, then we need to find some i for which MEX(1,i)=MEX(i+1,n).

 **Implementation on C++**
```cpp
/* Includes */
#include <bits/stdc++.h>
 
/* Using libraries */
using namespace std;

/* Defines */
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
 
void solve () {
    int n;
    cin >> n;
    vc <int> a(n);
    vc <int> cnt1(n + 1), cnt2(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt2[a[i]]++;
    }
    int mex1 = 0, mex2 = 0;
    while (cnt2[mex2])
        ++mex2;
    for (int i = 0; i < n; ++i) {
        cnt1[a[i]]++;
        if (--cnt2[a[i]] == 0 && mex2 > a[i]) {
            mex2 = a[i];
        }
        while (mex2 && !cnt2[mex2 - 1])
            --mex2;
        while (cnt1[mex1])
            ++mex1;
        if (mex1 == mex2) {
            cout << "2n";
            cout << 1 << " " << i + 1 << "n";
            cout << i + 2 << " " << n << "n";
            return;
        }
    }
    cout << "-1n";
}

signed main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```
 **Implementation on Python**
```cpp
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    cur_mex = 0
    cur_have = [0] * (n + 1)
    for el in a:
        cur_have[el] += 1
    while cur_have[cur_mex]:
        cur_mex += 1

    another_mex = 0
    another_have = [0] * (n + 1)
    for i in range(n):
        cur_have[a[i]] -= 1
        if cur_have[a[i]] == 0 and cur_mex > a[i]:
            cur_mex = a[i]

        another_have[a[i]] += 1
        while another_have[another_mex]:
            another_mex += 1

        if cur_mex == another_mex:
            print(2)
            print("1 " + str(i + 1))
            print(str(i + 2) + " " + str(n))
            return

    print(-1)


t = int(input())
for _ in range(t):
    solve()
```
[1935C - Messenger in MAC](../problems/C._Messenger_in_MAC.md "Codeforces Round 932 (Div. 2)")

Idea: [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Expert i_love_penguins")   
 Preparation: [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Expert i_love_penguins")   
 Editorial: [i_love_penguins](https://codeforces.com/profile/i_love_penguins "Expert i_love_penguins")

 **Hints****Hint 1**Try to find the answer to the problem by hand. How can changing the order of the messages reduce time?

 **Hint 2**Let the order in the response be p1,p2,…,pk. It is always advantageous for the response to satisfy bp1≤bp2≤…≤bpk.

 **Hint 3**Greedy?

 **Solution**Let the order in the response be p1,p2,…,pk. Note that in the optimal response, it will hold that bp1≤bp2≤…≤bpk. It's not hard to prove that such an order minimizes the sum of the absolute differences of adjacent elements in the array b. Then, this sum will turn into bpk−bp1, that is, the difference between the highest and lowest value of b in the set of messages.

Let's sort the pairs (ai,bi) in ascending order of bi. Fix the minimum value in the set of messages bl and the maximum value br. Note that the sum of the absolute differences of b in the response will not change if taking values bl≤bi≤br. Thus, the task reduces to finding the maximum number of messages so that ∑a≤L−(br−bl).

Iterate over bl and br. Apply a greedy algorithm, sort all values of ai (l≤i≤r), and keep adding values until the time exceeds L. This solution works in O(n3logn), which is too slow.

To speed up the solution, while iterating over br, maintain a data structure that allows adding an element, removing the maximum, getting the maximum (in C++, there are multiset and priority_queue). In this data structure, maintain the minimum values of a, so the sum of times does not exceed L. Then, if the current time exceeds L, remove from the structure until the current time becomes no more than L. There will be no more than n such removals. We have obtained a solution in O(n2logn), which is feasibly fast.

 **Implementation on C++**
```cpp
#include <bits/stdc++.h>

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        int n, L;
        std::cin >> n >> L;
        std::vector<std::pair<int, int>> v(n);
        for (int i = 0 ; i < n ; i++) {
            std::cin >> v[i].second >> v[i].first;
        }
        std::sort(v.begin(), v.end());

        int ans = 0;
        for (int l = 0 ; l < n ; l++) {
            std::multiset<int> s;
            int cur = 0;
            for (int r = l ; r < n ; r++) {
                s.insert(v[r].second);
                cur += v[r].second;
                while (!s.empty() && v[r].first - v[l].first + cur > L) {
                    int max_value = *s.rbegin();
                    cur -= max_value;
                    s.extract(max_value);
                }
                ans = std::max(ans, (int) s.size());
            }
        }

        std::cout << ans << "n";
    }

    return 0;
}
```
 **Implementation on Python**
```cpp
import heapq
import sys

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, L = map(int, input().split())
    v = []
    for i in range(n):
        a, b = map(int, input().split())
        v.append((b, a))
    v.sort()

    ans = 0
    for l in range(n):
        pq = []
        heapq.heapify(pq)
        cur = 0
        size = 0
        for r in range(l, n):
            heapq.heappush(pq, -v[r][1])
            size += 1
            cur += v[r][1]
            while size and v[r][0] - v[l][0] + cur > L:
                maxx = -heapq.heappop(pq)
                cur -= maxx
                size -= 1
            ans = max(ans, size)

    print(ans)
```
[1935D - Exam in MAC](../problems/D._Exam_in_MAC.md "Codeforces Round 932 (Div. 2)")

Idea: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")   
 Preparation: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")   
 Editorial: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")

 **Hints****Hint 1**The principle of inclusion-exclusion.

 **Hint 2**The equation x+y=si, y−x=sj has 0 or 1 solutions with integers x,y.

 **Tutorial**Applying the formula of inclusion-exclusion, the answer to the problem will be: cnt(x,y)−cnt(x,y:x+y∈s)−cnt(x,y:y−x∈s)+cnt(x,y:x+y,y−x∈s). Let's calculate each value separately.

The number of possible pairs x,y is (c+1)⋅(c+2)2.

The number of pairs x,y:x+y∈s. We iterate over the sum value si, let x+y=si, then for 0≤x≤⌊si2⌋ there will correspond exactly one y, i.e., the number of pairs with such a sum is ⌊si2⌋+1.

The number of pairs x,y:y−x∈s. We iterate over the difference value si, let y−x=si, then for si≤y≤c there will correspond exactly one x, i.e., the number of pairs with such a difference is c−si+1.

The number of pairs x,y:x+y,y−x∈s. Let x+y=si, y−x=sj, then x=si−sj2, and y=si+sj2. If si,sj have different parities, then such x,y will not be suitable because they will be non-integers; otherwise, such x,y are suitable, and we need to add this pair. Then, let's calculate the number of even and odd numbers in s — even and odd respectively. Thus, the number of such pairs is even⋅(even+1)2+odd⋅(odd+1)2.

With all these quantities, we can calculate the answer. The final complexity is O(n). The problem can also be solved in O(n⋅logn) or O(n) using other methods.

 **Implementation on C++**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve_case() {
    int n, c;
    cin >> n >> c;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int odd = 0, even = 0;
    ll ans = 1ll * (c + 1) * (c + 2) / 2;
    for (int i = 0; i < n; i++) {
        ans -= s[i] / 2 + 1;
        ans -= c - s[i] + 1;
        if (s[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    ans += 1ll * even * (even + 1) / 2;
    ans += 1ll * odd * (odd + 1) / 2;
    cout << ans << "n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve_case();
    }
}
```
 **Implementation on Python**
```cpp
def solve_case() :
    n, c = map(int, input().split())
    s = list(map(int, input().split()))
    ans = (c + 1) * (c + 2) // 2
    even, odd = 0, 0
    for i in range(n):
        ans -= s[i] // 2 + 1
        ans -= c - s[i] + 1
        if s[i] % 2 == 0:
            even += 1
        else:
            odd += 1
    ans += even * (even + 1) // 2
    ans += odd * (odd + 1) // 2
    print(ans)

t = int(input())
for test in range(t):
    solve_case()
```
[1935E - Distance Learning Courses in MAC](../problems/E._Distance_Learning_Courses_in_MAC.md "Codeforces Round 932 (Div. 2)")

Idea: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")   
 Preparation: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Candidate Master AndreyPavlov")   
 Editorial: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Candidate Master AndreyPavlov")

 **Hints****Hint 1**Try to solve the problem if xi=0 for each i.

 **Hint 2**What will be the answer for two segments (0,2i),(0,2i)?

 **Hint 3**Which bits will definitely be included in the answer?

 **Tutorial**Let's solve the problem when x=0. Then we will iterate over the bits from the most significant to the least significant and try to include them in the answer. Suppose we are iterating over bit i, then if such a bit occurs c times in y numbers there are several cases:

 * c=0 — this bit cannot be included in the answer
* c=1 — this bit will be included in the answer, we add it
* c>1 — a special case, because for one number where bit x is present, we can set it, and for another number, we can set all bits j<i.

Therefore, if we encounter some bit i that occurs more than once, then all bits j≤i will also be included in the answer. Now let's solve the original problem, for this we take a pair (xi,yi) and find the bitwise largest common prefix — let it be number w. Then it is clear that all bits from w will be included in the answer, then we make a new pair (x′i,y′i) = (xi−w,yi−w), and remember the number wi. Now note that the number y′i−1≥x′i. Why do we need this fact? Remember, in the case when some bit occurred more than once, we added it and all smaller bits to the answer. For this, we would set at this position a number equal to 2i−1 (and other larger bits i), but if y′i−1≥x′i, then we can always add all such bits.

Therefore, the solution algorithm for request j is as follows:

 * Take the Bitwise OR of all wi for lj≤i≤rj, let this be number W
* Iterate over bit i and similarly to the case x=0 consider the same cases, but for the array y′. Also, take into account that the bit occurs in W.

This solution can be implemented in O(n⋅logn) using prefix sums for each bit. There is also a solution using a segment tree, so the problem can be solved with modification requests as well.

 **Implementation on C++**
```cpp
/* Includes */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
 
/* Using libraries */
using namespace std;
 
/* Defines */
template <class T>
using vc = vector <T>;
using ll = long long;
using ld = long double;
using pii = pair <int, int>;
 
template<class T>
void output(T &a) {
    for (auto i : a)
        cout << i << ' ';
    cout << 'n';
}
 
template<class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
const int N = 2e5;
const int bit = 30;
 
struct segtree {
    vc <int> t; int n;
    segtree (int n) : n(n) {
        t.resize(n * 2);
    }
    void upd (int i, int x) {
        for (t[i += n] = x; i > 1; i >>= 1) {
            t[i >> 1] = t[i] | t[i ^ 1];
        }
    }
    int get (int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res |= t[l++];
            if (r & 1)
                res |= t[--r];
        }
        return res;
    }
};
 
int n;
int l[N], r[N];
int w[N];
void fix () {
    for (int i = 0; i < n; ++i) {
        if (l[i] == r[i]) {
            w[i] = l[i];
            l[i] = r[i] = 0;
            continue;
        }
        int pref = (1 << (__lg(l[i] ^ r[i]) + 1)) - 1;
        w[i] = r[i] - (r[i] & pref);
        r[i] &= pref;
        l[i] &= pref;
    }
}
 
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    fix();
    segtree t(n);
    vc <vc <int>> bits(bit, vc <int> (n + 1));
    for (int i = 0; i < n; ++i) {
        t.upd(i, w[i]);
        for (int j = 0; j < bit; ++j) {
            bits[j][i + 1] = bits[j][i];
            if (r[i] >> j & 1) {
                bits[j][i + 1]++;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y; --x;
        int ans = t.get(x, y);
        for (int j = bit - 1; j >= 0; --j) {
            int cnt = bits[j][y] - bits[j][x] + (ans >> j & 1);
            if (cnt > 1) {
                ans |= (2 << j) - 1;
                break;
            } else if (cnt == 1) {
                ans |= 1 << j;
            }
        }
        cout << ans << ' ';
    }
    cout << "n";
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1935F - Andrey's Tree](../problems/F._Andrey's_Tree.md "Codeforces Round 932 (Div. 2)")

Idea: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Candidate Master AndreyPavlov")   
 Preparation: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")   
 Editorial: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")

 **Hints****Hint 1**What different values can the answer for a vertex take?

 **Hint 2**Edges with a weight of 1 can connect all vertices [1,v−1] and all vertices [v+1,n].

 **Hint 3**Consider the edges of the form (mnu,mnu−1), (mxu,mxu+1), where mnu, mxu are the minimum and maximum in the subtree of vertex u with respect to v.

 **Tutorial**Let's fix some vertex v for which the answer is being calculated. Suppose the degree of the vertex v in the tree is degv, then it's clear that it's necessary to add degv−1 edges. Consider the components that appear after removing v. Then, the goal is to use the new edges to unite all the components into one, using the minimum total cost. This is the same as finding the minimum spanning tree in a graph, where the vertices are the components that resulted from removing v, and for every a,b, an edge with a weight of |a−b| is drawn between the components containing a and b.

Let's simulate Kruskal's algorithm for this graph. Consider all the single-weight edges in this graph: (1,2),(2,3),...,(v−2,v−1),(v+1,v+2),...,(n−1,n). It's clear that using the single-weight edges, the vertices with numbers [1,v−1] will definitely end up in one component, and the vertices with numbers [v+1,n] will also end up in one component. To unite these two components, it would be optimal to add an edge (v−1,v+1).

It turns out that it's sufficient to consider only all the single-weight edges and the edge (v−1,v+1). Let's limit the number of single-weight edges to O(degv). For this, in each component u, calculate mnu and mxu — the minimum and maximum in the component, respectively. Claim: among the single-weight edges, it's sufficient to consider edges of the form (mnu,mnu−1), (mxu,mxu+1).

 **Proof**First, understand when it's necessary to add the edge (v−1,v+1). Note that if there's at least one component u such that mnu<v<mxu, then the edge (v−1,v+1) won't be needed; otherwise, it will be. This is quite easy to show by simulating Kruskal's algorithm.

Let v=1. We'll show that using edges (mnu,mnu−1), all components will unite. Go through the vertices x from 2 to n and maintain the invariant that all vertices from 2 to x are in one component. At x=2, this holds. When x is the minimum in some component, then the edge (x−1,x) will be added, and since x−1 is in one component with 2, x will now also be. When x is not the minimum in some component, then mn — the minimum in the component x will be in one component with 2 (mn<x, the invariant holds), meaning x will also be in one component with 2. Thus, it turns out that all will be in one component.

Now consider an arbitrary v. Separately consider the prefix of vertices [1,v−1] and the suffix [v+1,n]. Then, similarly to v=1, it can be shown that for the prefix of vertices [1,v−1], using edges of the form (mnu,mnu−1), you can unite [1,v−1]. Similarly, for the suffix of vertices [v+1,n], using edges of the form (mxu,mxu+1), you can unite [v+1,n].

Now, if the edge (v−1,v+1) is necessary, then add it to the answer. Otherwise, there's at least one component u such that mnu<v<mxu, meaning the prefix of vertices [1,v−1] and the suffix [v+1,n] will unite into one component.

Finding mnu, mxu for each component is straightforward; what remains is to determine which components are connected by the edges (mnu,mnu−1), (mxu,mxu+1). This can be done with binary search through the Euler tour of the tree. After that, Kruskal's algorithm can be initiated to calculate the answer.

Let's estimate the time complexity. For a specific vertex v, the time complexity will be degv⋅logn, so the total time complexity is O(n⋅logn).

Depending on the implementation of the last step, the problem can be solved in O(n), O(n⋅α(n)), where α(n) is the inverse Ackermann function relative to n.

 **Implementation on C++**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
 
struct DSU {
    vector<int> p, r;
    int comp;
    DSU(int n) : p(n), r(n) {
        iota(p.begin(), p.end(), 0);
        comp = n;
    }
    int find(int v) {
        return (p[v] == v) ? v : p[v] = find(p[v]);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        comp--;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> tin(n), tout(n), l0(n), r0(n);
        vector<int> lup(n), rup(n);
        int timer = 0;
        vector<int> ord;
        function<void(int, int)> dfs = [&](int v, int p) {
            l0[v] = r0[v] = v;
            tin[v] = timer++;
            ord.push_back(v);
            for (int u : g[v]) {
                if (u == p) continue;
                dfs(u, v);
                l0[v] = min(l0[v], l0[u]);
                r0[v] = max(r0[v], r0[u]);
            }
            tout[v] = timer - 1;
        };
        dfs(0, 0);
        function<bool(int, int)> ancestor = [&](int v, int u) {
            return tin[v] <= tin[u] && tin[u] <= tout[v];
        };
        vector<int> pref_min_ord(n + 1, n), suf_min_ord(n + 1, n);
        vector<int> pref_max_ord(n + 1, -1), suf_max_ord(n + 1, -1);
        for (int i = 0; i < n; i++) {
            pref_min_ord[i + 1] = min(pref_min_ord[i], ord[i]);
            pref_max_ord[i + 1] = max(pref_max_ord[i], ord[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suf_min_ord[i] = min(suf_min_ord[i + 1], ord[i]);
            suf_max_ord[i] = max(suf_max_ord[i + 1], ord[i]);
        }
        for (int id = (int)ord.size() - 1; id >= 0; id--) {
            int v = ord[id];
            lup[v] = min(pref_min_ord[tin[v]], suf_min_ord[tout[v] + 1]);
            rup[v] = max(pref_max_ord[tin[v]], suf_max_ord[tout[v] + 1]);
        }
        vector<vector<pair<int, int>>> ans(n);
        vector<int> weight(n);
        function<void(int, int)> dfs2 = [&](int v, int p) {
            vector<int> all_id, all_tin;
            int idpar = -1;
            for (int id = 0; id < g[v].size(); id++) {
                int u = g[v][id];
                if (u != p) {
                    dfs2(u, v);
                    all_id.push_back(id);
                    all_tin.push_back(tin[u]);
                } else {
                    idpar = id;
                }
            }
            function<int(int)> get_subtree = [&](int u) {
                if (!ancestor(v, u)) return idpar;
                return all_id[upper_bound(all_tin.begin(), all_tin.end(), tin[u]) - all_tin.begin() - 1];
            };
            DSU dsu(g[v].size());
            function<void(int, int)> try_add = [&](int x, int y) {
                if (x == -1 || y == n || x == v || y == v) return;
                if (dsu.join(get_subtree(x), get_subtree(y))) {
                    ans[v].push_back({x, y});
                    weight[v] += abs(x - y);
                }
            };
            for (int u : g[v]) {
                if (u != p) {
                    try_add(l0[u] - 1, l0[u]);
                    try_add(r0[u], r0[u] + 1);
                } else {
                    try_add(lup[v] - 1, lup[v]);
                    try_add(rup[v], rup[v] + 1);
                }
            }
            if (dsu.comp != 1) {
                try_add(v - 1, v + 1);
            }
            assert(dsu.comp == 1);
        };
        dfs2(0, 0);
        for (int i = 0; i < n; i++) {
            cout << weight[i] << " " << ans[i].size() << "n";
            for (auto [a, b] : ans[i]) {
                cout << a + 1 << " " << b + 1 << "n";
            }
            cout << "n";
        }
    }
}
```
We hope you liked our problems!

