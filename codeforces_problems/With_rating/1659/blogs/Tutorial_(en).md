# Tutorial_(en)

Thank you everyone for your participation. Do vote under the Feedback section, and feel free to give your review of the problems in the comments.

 

---

[1659A - Red Versus Blue](../problems/A._Red_Versus_Blue.md "Codeforces Round 782 (Div. 2)")   


Idea: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Expert TimeWarp101")   
 Editorial: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Expert TimeWarp101")

 **Hints****Hint 1**Is it a good idea to have consecutive `B`'s?

 **Hint 2**If you space out all the `B`'s, how many regions do you have to place the `R`'s into?

 **Hint 3**What is the best way of placing the `R`'s into b+1 regions such that the maximum number of `R`'s in a region is minimum?

 **Solution**
### [1659A - Red Versus Blue](../problems/A._Red_Versus_Blue.md "Codeforces Round 782 (Div. 2)")

We have b B's which divide the string into b+1 regions and we have to place the R's in these regions. By the strong form of the pigeonhole principle, at least one region must have at least ⌈rb+1⌉ R's. This gives us a lower bound on the answer.

Now, we will construct a string whose answer is exactly equal to the lower bound.

We place the B's so that they are not adjacent. Then we equally distribute the R's in the b+1 regions.

Let p=⌊rb+1⌋ and q=rmod(b+1).

We place p R's in each region and an extra R in any q regions. Hence, our answer for the construction is ⌈rb+1⌉, which is equal to the lower bound.

Importantly, r>b, so none of the B's will be consecutive.

Time complexity: O(n).

 **Implementation (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "n"
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
cin>>_;
while(_--)
{
    int n,r,b;
    cin>>n>>r>>b;
    int p=r/(b+1),q=r%(b+1);
    for(int i=0;i<q;i++)    cout<<string(p+1,'R')<<'B';
    for(int i=q;i<b;i++)    cout<<string(p,'R')<<'B';
    cout<<string(p,'R');
    cout<<endl;
}
return 0;
}
```
 **Implementation (Python)**
```cpp
t = int(input())
for i in range(t):
    n, r, b = map(int, input().split())
    p = r % (b + 1)
    y = ""
    for j in range(int(r / (b + 1))):
        y = y + "R"
    ans = ""
    for i in range(b + 1):
        if i > 0:
            ans = ans + "B"
        ans = ans + y
        if p > 0:
            ans = ans + "R"
            p = p - 1
    print(ans)
```
 **Feedback*** Good problem: 


[*338*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*61*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*297*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*39*](https://codeforces.com/data/like?action=like "I like this")
[1659B - Bit Flipping](../problems/B._Bit_Flipping.md "Codeforces Round 782 (Div. 2)")   


Idea: [Newtech66](https://codeforces.com/profile/Newtech66 "Expert Newtech66")   
 Editorial: [Newtech66](https://codeforces.com/profile/Newtech66 "Expert Newtech66")

 **Hints****Hint 1**Let's say you don't ever pick a bit. How many times will it get flipped?

 **Hint 2**If you do pick a bit once at some point, it will get flipped 1 less time overall.

 **Hint 3**To get the lexicographically largest string, you need to make bits 1 starting from the left. What is the minimum number of times you have to select a bit to ensure it gets flipped, or stays the same?

 **Solution**
### [1659B - Bit Flipping](../problems/B._Bit_Flipping.md "Codeforces Round 782 (Div. 2)")

Let's see how many times a given bit will get flipped. Clearly, a bit gets flipped whenever it is not selected in an operation. Therefore, the i-th bit gets flipped k−fi times. We want to select a bit as few times as possible. Now we can handle a few cases.

1. k is even, bit i is 1 ⇒ fi=0 (even number of flips don't change the bit)
2. k is even, bit i is 0 ⇒ fi=1 (odd number of flips toggle the bit from 0 to 1)
3. k is odd, bit i is 1 ⇒ fi=1 (even number of flips don't change the bit)
4. k is odd, bit i is 0 ⇒ fi=0 (odd number of flips toggle the bit from 0 to 1)

Process the string from left to right until you can't anymore. If you still have some remaining moves at the end, you can just give them all to the last bit. Then you can construct the final string by checking the parity of k−fi.

Time complexity: O(n)

 **Implementation (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "n"
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
cin>>_;
while(_--)
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> f(n,0);
    int tmpk=k;
    for(int i=0;i<n && tmpk>0;i++)
    {
        if(k%2==s[i]-'0')
        {
            f[i]=1;
            tmpk--;
        }
    }
    f[n-1]+=tmpk;
    for(int i=0;i<n;i++)
    {
        if((k-f[i])%2==1)   s[i]='1'-(s[i]-'0');
    }
    cout<<s<<endl;
    for(auto& e:f)  cout<<e<<" ";
    cout<<endl;
}
return 0;
}
```
 **Implementation (Python)**
```cpp
t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    kc = k
    s = input()
    f = [0] * n
    ans = ""
    for i in range(n):
        if k == 0:
            break
        if kc % 2 == 1 and s[i] == '1':
            f[i] = f[i] + 1
            k = k - 1
        elif kc % 2 == 0 and s[i] == '0':
            f[i] = f[i] + 1
            k = k - 1
    f[n - 1] = f[n - 1] + k
    for i in range(n):
        flip = kc - f[i]
        if flip % 2 == 0:
            ans = ans + s[i]
        else:
            if s[i] == '1':
                ans = ans + '0'
            else:
                ans = ans + '1'
    print(ans)
    for i in range(n):
        print(f[i], end = ' ')
    print()
```
 **Feedback*** Good problem: 

 
[*367*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*33*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*86*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*41*](https://codeforces.com/data/like?action=like "I like this")
[1659C - Line Empire](../problems/C._Line_Empire.md "Codeforces Round 782 (Div. 2)")   


Idea: [Newtech66](https://codeforces.com/profile/Newtech66 "Expert Newtech66")   
 Editorial: [Newtech66](https://codeforces.com/profile/Newtech66 "Expert Newtech66")

 **Hints****Hint 1**Try to analyze the cost of each operation separately. Is there some linearity you can exploit?

 **Hint 2**Try to make greedy decisions. Can we say that it is always better to move right whenever possible?

 **Hint 3**Let's say you fix the final position of your capital. Now think about Hint 2.

 **Solution**
### [1659C - Line Empire](../problems/C._Line_Empire.md "Codeforces Round 782 (Div. 2)")

Clearly, we should always move from left to right. Also, assume x0=0 for simplicity.

Let us analyze what our cost would look like. It will be composed of a part due to moving capitals, and a part due to conquering kingdoms. If we shift our capital from xi to xj, the cost is a⋅(xj−xi). If we conquer kingdoms from (i,j] with capital xi, the cost is b⋅((xi+1−xi)+(xi+2−xi)+…+(xj−xi)), which can be written as b⋅(pj−pi−(j−i)⋅xi), where pi=x0+x1+…+xi.

Now, notice that xj−xi and pj−pi are linear. Also, if we isolate the parts involving xj−xi, the sum will be like (xj1−x0)+(xj2−xj1)+…+(xjf−xjf−1)=xjf−x0. This means we can simply write the final sum of this part as a⋅xf, where xf is the final position of the capital. We can say the same thing about pj−pi, except that the final kingdom conquered is always xn. So the final sum of this part is always b⋅pn (x0=p0=0, so they weren't written explicitly).

Our final cost, then, looks like T=a⋅xf+b⋅(pn−C), where C is composed of terms like (j−i)⋅xi. If we want to minimise T, we want to maximise C. That is achieved if we always increase xi! Then we can write C=x0+x1+…+xf−1+xf+…+xf⏟n−f times=pf+(n−f−1)⋅xf We cannot increase beyond xf since that is the final position of our capital.

Hence, our final answer is given by minf∈[0,n](a⋅xf+b⋅(pn−pf−(n−f−1)⋅xf))

Time complexity: O(n)

 **Implementation (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "n"
const lol inf=1e18+8;
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
cin>>_;
while(_--)
{
    int n;
    lol a,b;
    cin>>n>>a>>b;
    vector<lol> x(n+1),p(n+1);
    x[0]=0;
    for(int i=1;i<=n;i++)   cin>>x[i];
    partial_sum(x.begin(),x.end(),p.begin());
    lol ans=inf;
    for(int i=0;i<=n;i++)
    {
        ans=min(ans,(a+b)*(x[i]-x[0])+b*(p[n]-p[i]-(n-i)*x[i]));
    }
    cout<<ans<<endl;
}
return 0;
}
```
 **Feedback*** Good problem: 

 
[*390*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*48*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*35*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*43*](https://codeforces.com/data/like?action=like "I like this")
[1659D - Reverse Sort Sum](../problems/D._Reverse_Sort_Sum.md "Codeforces Round 782 (Div. 2)")   


Idea: [Newtech66](https://codeforces.com/profile/Newtech66 "Expert Newtech66")   
 Editorial: [Newtech66](https://codeforces.com/profile/Newtech66 "Expert Newtech66")

 **Hints****Hint 1**Is there any way to tell how many 1s were in A?

 **Hint 2**Can you tell what an was by looking at just cn?

 **Hint 3**Try to simulate removing each Bi starting from Bn.

 **Solution**
### [1659D - Reverse Sort Sum](../problems/D._Reverse_Sort_Sum.md "Codeforces Round 782 (Div. 2)")

The first thing to notice is that any 1 in the initial array A, will contribute to the sum of elements of array C exactly n times. That means, if S=c1+c2+...+cn, S must be divisible by n.

Let k=Sn be the number of 1s in the initial array A.

Observation: The 1s in Bn form a suffix of it.

We'll process the array C from right to left.

Assume an was 1. Then, it is clear that cn=n. Then, we can place a 1 there. Now assume an was 0. Then, it is clear that if there were any 1s in A (in other words, if k>0), then cn=1. Otherwise cn=0. If this is the case, we can place a 0 there and move on. Finally, we must subtract 1 from each of the last k elements provided k>0. Decrement k if a 1 was placed. In essence, we simulated removing Bn from the elementwise sum.

Once we've processed cn, we can forget about it and continue solving the problem assuming there are n−1 elements, and so on.

The last thing is to handle subtracting 1 from the last k elements. It is possible to do it using a segment tree/BIT, but that is overkill for this problem. A simpler way is to maintain a left border for the suffix, and keep track of when the border crosses an element (say ti) and when we reach it. Then we can get a simple formula for the value of the element that looks something like ci−(ti−i).

Time complexity: O(n) or O(nlogn)

 **Implementation (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "n"
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
cin>>_;
while(_--)
{
    int n;
    cin>>n;
    vector<lol> v(n);
    for(auto& e:v)  cin>>e;
    int k=accumulate(v.begin(),v.end(),0ll)/n;
    vector<int> b(n),ans(n,0);
    int lf=n-k;
    for(int i=lf;i<n;i++)   b[i]=n-1;
    for(int i=n-1;i>=0 && lf<=i;i--)
    {
        int cur=v[i]-(b[i]-i);
        if(cur==i+1)    ans[i]=1;
        else if(cur==1)
        {
            ans[i]=0;
            lf--;
            b[lf]=i-1;
        }
    }
    for(auto& e:ans)    cout<<e<<" ";
    cout<<endl;
}
return 0;
}
```
 **Feedback*** Good problem: 

 
[*244*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*12*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*24*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*31*](https://codeforces.com/data/like?action=like "I like this")
 **Challenge**Try to solve this problem if it is possible for invalid C to be given as input. This was the original version of the problem, but testers struggled a lot with it. The solution to this is still used in the validator.

[1659E - AND-MEX Walk](../problems/E._AND-MEX_Walk.md "Codeforces Round 782 (Div. 2)")   


Idea: [Newtech66](https://codeforces.com/profile/Newtech66 "Expert Newtech66")   
 Editorial: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Expert TimeWarp101")

 **Hints****Hint 1**Can the MEX ever be >2?

 **Hint 2**For the MEX to be 0, the AND of the walk should be >0. This implies that some bit is on for all the edges of the walk. How can you check this efficiently?

 **Hint 3**Make 30 graphs, with each graph only containing edges where the i-th bit is on. You can use disjoint sets on these graphs to solve the above problem.

 **Hint 4**When MEX is 1, we know 0 exists in the sequence. We need to avoid 1 and jump from some other number to 0. We need to get rid of the 0-th bit while some other bit stays on to ensure we don't get 1 in our sequence. This basically means that we need to walk to a node which has an even edge and ensure our AND so far is >1. Travelling through the even edge would guarantee that our answer is 1.

 **Hint 5**Again, make 29 graphs, with each graph only containing edges where the 0-th and i-th (i≥1) bits are on. Use disjoint sets on these graphs. For each vertex you can note if it is adjacent to an even edge and then store this information in the disjoint set data structure.

 **Solution**
### [1659E - AND-MEX Walk](../problems/E._AND-MEX_Walk.md "Codeforces Round 782 (Div. 2)")

Observation: The MEX can only be 0, 1, or 2.

Proof: Suppose the MEX is greater than 2. We know that on using the bitwise AND function, some on bits will turn off and the sequence will be non-increasing.

This would imply that we have 2, 1 and 0 in our sequence. However, going from 2 (10) to 1 (01) is not possible as an off bit gets turned on. Hence, 2 and 1 can't both be in our sequence.

Case 1: MEX is 0.

For MEX to be 0, there must be a walk from u to v such that the bitwise AND of the weights of all the edges in that walk is non-zero. This implies that there exists some bit which is on in all the edges of that walk.

To check this, we can loop over all possible bits, i.e. i goes from 0 to 29, and construct a new graph for each bit while only adding the edges which have the i-th bit on. We can use DSU on this new graph and form connected components. This can be processed before taking the queries.

In a query, we can go through all bits from 0 to 29 and if we get u and v in the same component for some bit, then we're done and our answer is 0.

Case 2: MEX is 1.

If we didn't get the MEX to be 0, then we know that 0 is in our sequence.

Now, in our walk, if we ever get a node which has an even edge (let's say this is the first even edge so far) and our bitwise AND so far is greater than 1 (it would also be an odd number since there's no even edges), then including this edge in our walk would guarantee a MEX of 1 since the even edge has the 0-th bit off. Taking the bitwise AND with this edge guarantees that the last bit stays off until the end of our walk and we never get 1 in the sequence. Let us call this node x. For a given u, if an x exists, then an answer of 1 is possible.

This also shows us that the value of v is not relevant, since after we get the even edge, our MEX is guaranteed to be 1 and the subsequent weights do not matter.

For the bitwise AND of the walk to be an odd number greater than 1, all edges on the walk from u to x must have the 0-th bit on and the i-th bit on for some i in [1,29].

Similar to the previous case, we now loop i from 1 to 29 and make a new graph for each bit while only adding edges which have the 0-th and the i-th bits on, and use DSU to form connected components. Within a component, if any node has an even edge, then every node in that component can be the starting point of a walk to get the answer as 1. Then, we go through all the nodes. If the current node, say, y has an even edge, then we can mark the parent node of y's component indicating that this component has an even edge. 

In the queries, we can go through all the 29 graphs and if the parent of u in a graph has been marked, then we know that it's possible to have the MEX as 1.

If not, the answer must be 2 since MEX cannot exceed 2.

Time complexity: O(nlogw+(m+q)α(n)logw)

 **Implementation (C++)**
```cpp
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;
 
struct dsu {
    vi d;
    dsu(int n) : d(n, -1) {}
    int find(int x) {return d[x] < 0 ? x : d[x] = find(d[x]);}
    void join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y]; d[y] = x;
    }
    bool is_joined(int x, int y) {
        return find(x) == find(y);
    }
};
 
int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    rep(i, m) {
        int u, v, w; cin >> u >> v >> w;
        edges.eb(--u, --v, w);
    }
    vector<dsu> zero(30, n), one(30, n);
    rep(j, 30) {
        for(auto& [u, v, w]: edges) if(w >> j & 1) {
            zero[j].join(u, v);
        }
    }
    vb even(n);
    rep1(j, 29) {
        for(auto& [u, v, w]: edges) if((w >> j & 1)) {
            one[j].join(u, v);
        }
        vb vis(n);
        for(auto& [u, v, w]: edges) if(!(w & 1)) {
            vis[one[j].find(u)] = 1;
            vis[one[j].find(v)] = 1;
        }
        rep(i, n) if(vis[one[j].find(i)]) even[i] = 1;
    }
    auto check = [&](int u, int v) -> int {
        rep(j, 30) if(zero[j].is_joined(u, v)) return 0;
        if(even[u]) return 1;
        rep1(j, 29) if(one[j].is_joined(u, v)) return 1;
        return 2;
    };
    int q; cin >> q;
    while(q--) {
        int u, v; cin >> u >> v; --u, --v;
        cout << check(u, v) << endl;
    }
}
```
 **Feedback*** Good problem: 

 
[*112*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*8*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*8*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*24*](https://codeforces.com/data/like?action=like "I like this")
 **Challenge**Try to solve this problem if the queries were for **longest** walk instead.

[1659F - Tree and Permutation Game](../problems/F._Tree_and_Permutation_Game.md "Codeforces Round 782 (Div. 2)")   


Idea: [Newtech66](https://codeforces.com/profile/Newtech66 "Expert Newtech66")   
 Editorial: [Newtech66](https://codeforces.com/profile/Newtech66 "Expert Newtech66")

[Bench0310](https://codeforces.com/profile/Bench0310 "Grandmaster Bench0310") has written another proof for the solution to this problem [here](Announcement_(en).md?#comment-904422) and [here](Announcement_(en).md?#comment-904443). Many thanks to him!   
   
 

 **Hints****Hint 1**Notice that as long as there are ≥3 elements not in their correct place, Alice can always put at least 1 element into the correct place.

 **Hint 2**Intuitively, Alice should win if the tree is "big enough", because Bob won't be able to reach some places quickly enough. How to define this sense of "big enough"?

 **Hint 3**Try to solve this problem on a line graph.

 **Hint 4**It is actually possible to force a sequence of moves to get the 2 remaining elements onto the diameter of the tree. Given this, use the answer to Hint 3.

 **Hint 5**Prove that Alice always wins on trees with diameter ≥3.

 **Hint 6**A tree of diameter 2 is a star graph. This case has a number of edge cases. This time, try to look at permutation cycles. Can you define some kind of invariant?

 **Solution**
### [1659F - Tree and Permutation Game](../problems/F._Tree_and_Permutation_Game.md "Codeforces Round 782 (Div. 2)")

Let us call all such i that satisfy pi≠i as marked. If pi=i, it is called unmarked. Also, a notation like XY means "swap X and Y in the permutation".

We are going to show that it is always possible for Alice to win if the diameter of the tree is ≥3.

First of all, it should be obvious that no matter what moves are made, we will eventually end up at a state where we have just 2 marked vertices and the token is either on one of them or neither of them (with Alice having to move). In the latter case we have a trivial win.

Proof:

As long as there are >2 marked numbers, you can always find a pair of numbers to swap that will unmark one of the numbers. One can imagine this in terms of the cycle decomposition of the permutation.

—————

Next, let us show that from the former state, we can also force a state where the two marked vertices are adjacent to each other (with Alice having to move).

Proof:

If the two marked vertices are already adjacent, we don't need to do anything. Else, let's say we have A and B where B is the vertex with the token on it. Now, consider two cases. If A is at distance ≥3 from B, we can choose any adjacent vertex to B. Let it be C. Swap C and A. Now Bob has the option of moving the token onto C or not. It wouldn't be optimal to move it away from C, because then we can force the sequence BC CA and Bob won't be able to cover any vertex with his token. So Bob must move his token onto C. Swap A and B, which puts A in its right place. Now Bob must move this token onto B, so we did it. If A is instead at distance 2 from B, pick the vertex between B and A as C, and we can repeat the same analysis as above.

—————

Now, let's say we have A and B with B being the vertex with the token on it. Let us show that, if possible, we can always move A over B and B over A (effectively "jumping" over the opposite vertex).

Proof:

For the first one, pick some vertex adjacent to B (not A). Let it be C. Swap A and C. Now Bob has the option of moving to either C or A. If he moves to A, we can force BC CA and win. If he moves to C, we swap AB (putting A in the right place) and Bob has to move his token to B. Now we can see that the marked vertex which was A, "jumped" over B to reach C.

For the second one, pick some vertex adjacent to A (not B). Let it be C. Bob must move his token to A. Swap B and C (putting B in the right place). Bob must move his token to C. Now we can see that the marked vertex with a token which was B, "jumped" over A to reach C.

—————

Like this, we can move all over the tree. Now let's move such that both of the marked vertices lie on a diameter of the tree and one of them is at one end of it.

Consider a tree with diameter ≥3. That means we have a line of at least 4 vertices taking the two marked vertices at one end. Let's consider just the first 4 vertices, and show that we can always win here.

Proof:

Say we have a configuration like A-B-C-D where A and B are marked and A has the token on it. If B has the token on it instead, we can use the moving strategy explained before to first move A to C and then B to D and then it is equivalent to the first configuration. Swap B and D. Now Bob must move his token to B. Swap A and D (putting A in its right place). Now no matter where Bob moves, after his turn no vertex will be covered and we can force BD and win.

—————

Therefore, if the diameter of the tree is ≥3, we always win.

If the diameter of the tree is 2, it is a star graph, and this is a more problematic case.

First of all, we must check if the permutation is already sorted, or we can win in the first move. We can only win in the first move if only 1 swap is required to sort the permutation, and the token is on neither of the numbers we need to swap.

If the above is not possible, several cases follow.

Let us make the following observation first. If Bob is at the center of the star and the center is a marked vertex, Bob can infinitely stall Alice.

Proof:

Let's call the center A, and suppose we need to swap the number B with it to put it in its right place. B is definitely at a leaf and 1 vertex away because of the structure of the star graph. So when Bob's turn comes he can simply move the token to where B is and alternate this way between A and B, infinitely stalling Alice. Obviously, even if we try swapping B with a different number C, we can just move to where C is next until there are just two vertices left, the center and a leaf. So Bob wins.

—————

In light of this, it never makes sense to mark the center in our turn if it is unmarked and not covered by the token.

So we have 4 cases to think of now:

- Token on center and center is marked vertex: As explained before, Alice loses here.

Before discussing the rest of the cases, let us define d as the minimum number of swaps required to sort the permutation and x is 0 if the token is on the center and 1 if it is on a leaf.

Now I claim that the parity of d+x is invariant. The magnitude of x changes by exactly 1 every turn and we can say the same about d. So considering all possible changes (−1,−1) (−1,+1) (+1,−1) (+1,+1) we can see the sum of the changes is always 0mod2. Hence proved.

Consider the possible end states for the game: (all with 2 marked vertices and with Alice having to move)

1. Token at center, center marked
2. Token at unmarked leaf, center marked
3. Token at marked leaf, center marked
4. Token at center, center unmarked
5. Token at unmarked leaf, center unmarked
6. Token at marked leaf, center unmarked

Observe that end states 2 and 5 will never occur if the game lasts longer than 1 turn because if you go back by 1 turn, Bob would have a more optimal move. Therefore, in states 2 and 5 we can win in the very first move. Further observe that states 1 and 2 will never occur if the center was initially unmarked or we could unmark it in the first move. The only other possibility would be us being unable to unmark the center in the first move, which is a losing state. So we only care about states 4 and 6 now.

Observe that state 4 is a winning position while state 6 is a losing position. Also observe that state 4 has d+x odd but state 6 has d+x even. Now let us continue with the cases and use these facts.

- Token at center and center is unmarked vertex: Check the parity of d+x here. If it is odd, we win, otherwise we lose (follows from the invariance of d+x).

- Token at leaf and center is marked vertex: If we cannot unmark the center vertex in our very first move, we'll reach a losing position. If we can, check parity of d+x. Odd is win, even is lose. When can we not unmark the center vertex? Only if the token is on pcenter. Otherwise it is always possible.

- Token at leaf and center is unmarked vertex: Check parity of d+x. Odd is win, even is lose.

This completes the solution.

Time complexity: O(n) or O(nlogn) (depending on whether you use cycles or inversions to find the parity of d)

 **Implementation (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "n"
 
pair<int,int> dfs(int u,const vector<vector<int>>& g,int p=-1) //returns {node with max dist,max dist}
{
    pair<int,int> res{u,0};
    int mx=0;
    for(auto v:g[u])
    {
        if(v==p)    continue;
        pair<int,int> cur=dfs(v,g,u);
        cur.second++;
        if(mx<cur.second)
        {
            res=cur;
            mx=cur.second;
        }
    }
    return res;
}
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
cin>>_;
while(_--)
{
    int n,x;
    cin>>n>>x;
    vector<vector<int>> g(n+1);
    vector<int> p(n+1),deg(n+1,0);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    //find diameter of tree with 2 DFSes
    int diam=dfs(dfs(1,g).first,g).second;
    //if diam>=3, Alice always wins
    //if diam=1, n=2, have to check if p=[1,2]
    //otherwise we have a star graph and cases follow
    if(diam>=3) cout<<"Alice";
    else if(diam==1)    cout<<((p[1]==1)?"Alice":"Bob");
    else
    {
        //we need to check if we have already won or can win in the first move
        //this is possible if the permutation is already sorted
        //or if there are two marked elements and the chip is on neither of them
        vector<int> marked;
        for(int i=1;i<=n;i++)
        {
            if(p[i]!=i) marked.push_back(i);
        }
        if((int)marked.size()==0)
        {
            cout<<"Alice";
        }else if((int)marked.size()==2 && (x!=marked[0] && x!=marked[1]))
        {
            cout<<"Alice";
        }else
        {
            //we haven't won yet and it is not possible to win in one move
            //cases follow
            //first find center, it will have deg>1
            int center;
            for(int i=1;i<=n;i++)
            {
                if(deg[i]>1)
                {
                    center=i;
                    break;
                }
            }
            //is chip on center?
            bool chiponcenter=(x==center);
            //is center marked?
            bool centerismarked=(find(marked.begin(),marked.end(),x)!=marked.end());
            //list the cycles
            vector<int> vis(n+1,false);
            vector<vector<int> > cycles;
            for(int i=1;i<=n;i++)
            {
                if(vis[i])  continue;
                int j=i;
                cycles.push_back({j});
                vis[j]=true;
                while(!vis[p[j]])
                {
                    cycles.back().push_back(p[j]);
                    vis[p[j]]=true;
                    j=p[j];
                }
            }
            //min number of swaps
            int swapcnt=0;
            for(auto& cycle:cycles) swapcnt+=(int)cycle.size()-1;
            //parity
            int parity=(swapcnt+!chiponcenter)%2;
            //cases
            if(!centerismarked)    cout<<(parity?"Alice":"Bob");
            else if(chiponcenter && centerismarked)  cout<<"Bob";
            else    //chip not on center and center is marked
            {
                //need to check if we can unmark center on first move
                //it is impossible if x is on p[center] (since we need to move p[center] to get center
                //to the right place, but p[center] is blocked)
                bool cannotunmarkcenter=(p[center]==x);
                if(cannotunmarkcenter)  cout<<"Bob";
                else    cout<<(parity?"Alice":"Bob");
            }
        }
    }
    cout<<endl;
}
return 0;
}
```
 **Feedback*** Good problem: 

 
[*17*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*3*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*10*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*31*](https://codeforces.com/data/like?action=like "I like this")
