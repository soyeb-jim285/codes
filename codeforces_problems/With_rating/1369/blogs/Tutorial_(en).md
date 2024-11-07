# Tutorial_(en)


#### [A. FashionabLee :](../problems/A._FashionabLee.md)

Invented by [DeadlyCritic](https://codeforces.com/profile/DeadlyCritic "Master DeadlyCritic").

 **Brief Solution**BriefSolution:

A n-regular convex polygon is beautiful if and only if n%4=0. (% is the modular arithmetic symbol)

 **Complete Proof**
### [1369A - FashionabLee](../problems/A._FashionabLee.md "Codeforces Round 652 (Div. 2)")

$\mathcal Complete\;\mathcal Proof :$

Proof by contradiction :

One can prove that if two edges in a regular polygon make a $x < 180$ degrees angle, then for each edge $a$ there exist two another edges $b$ and $c$ such that $a$ and $b$ make a $x$ degrees angle as well as $a$ and $c$. (proof is left as an exercise for the reader)

Consider a rotation such that an edge $a$ is parallel to $OX$-axis and an edge $b$ is parallel to $OY$-axis, then $a \perp b$ ($a$ and $b$ are perpendicular, i. e. the angle between them is $90$ degrees), we can see that there exist a third edge $c$ such that it's also parallel to $OX$-axis and a forth edge $d$ such that it's also parallel to $OY$-axis, so $a \perp d$ and $b \perp c$ and $c \perp d$. 

Our polygon is regular so all the angles are equal, so that the number of angles between $a$ and $b$ is equal to the number of angles between $b$ and $c$ and so on, also we know that a regular $n$-sided convex polygon has $n$ angles, so $n$ is divisible by $4$, contradiction!

 **Python solution**
```cpp
t = int(input())
for testcase in range(t):
    n = int(input())
    if(n%4 == 0) :
        print("Yes")
    else :
        print("No")

```
 **C++ solution**
```cpp
#include <iostream>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 4 == 0){
            cout << "YESn";
        }
        else cout << "NOn";
    }
}

```
#### [B. AccurateLee :](../problems/B._AccurateLee.md)

Invented by [DeadlyCritic](https://codeforces.com/profile/DeadlyCritic "Master DeadlyCritic").

 **Brief Solution**BriefSolution:

If the string s is non-decreasing, then the answer is s itself, otherwise the answer is x+1 zeroes and y ones, where x is the number of leading zeroes of the string s, and y is the number of trailing ones of the string s.

 **Complete Proof**
### [1369B - AccurateLee](../problems/B._AccurateLee.md "Codeforces Round 652 (Div. 2)")

$\mathcal Complete\; \mathcal Proof$ :

Realize that the answer is always non-descending, and we can't perform any operations on non-descending strings.

First we know that we can't perform any operations on non-descending strings, so the answer to a non-descending string is itself. From now we consider our string $s$ to not to be non-descending. (i.e. there exist index $i$ such that $1 \le i \le n-1$ and $s_i > s_{i+1}$)

Also realize that the remaining string wont be empty, so "0" is the cleanest possible answer, but we can't reach it probable.

Now realize that leading zeroes and trailing ones can't be present in any operation. So they have to be in the answer, erase them from $s$, and add them to the answer for the modified $s$. From now we know that the string $s$ has no leading zeroes and/or trailing ones, and is not non-descending, so it starts with $1$ and ends with $0$. (why?)

With some small paperwork, we will realize that the answer to a string that starts with $1$ and ends with $0$ is a single $0$(proof is bellow). So if the string $s$ is non-descending and it has $x$ leading zeroes and $y$ trailing ones($x$ and $y$ can be equal to zero), then the answer is $\underbrace{0\,0\dots0}_{x}\,0\,\underbrace{1\,1\dots1}_{y}$ (its $x+1$ zeroes and $y$ ones in order)

$\mathcal The\;\mathcal Small\;\mathcal Paperwork:$

We will randomly perform operations until we can't do any more or the string's length is equal to $2$, but we wont erase the first $1$ and the last $0$, we want to prove that the remaining string's length is exactly $2$ after the process ends, proof by contradiction :

So it's length is at least $3$, so we have at least two $1$ or at least two $0$. If we had two or more $0$ then the string $[s_1\,s_2\dots s_{n-1}]$ will not be non-descending(so we can perform more operations as we proved in STAR, but the process have ended, contradiction!) and if we had two or more $1$ then the string $[s_2\,s_3\dots s_n]$ will not be non-descending. So the length of the remaining string is exactly $2$, and we haven't erased first '1' and last '0', so the string is equal to "10", now erase '1' to get the cleanest string.

Sorry if the proof seems too long and hard, i wanted to explain it accurately. ^-^

 **Python solution**
```cpp
t = int(input())
for testcase in range(t):
    n = int(input())
    s = input()
    lef, rig, sw = 1, 1, 0
    for i in range(n-1):
        if(s[i] > s[i+1]):
            sw = 1
            break
    if(sw == 0):
        print(s)
        continue
    for i in range(n):
        if (s[i] == '1'):
            lef = i
            break
    for i in range(n-1, 0, -1):
        if (s[i] == '0'):
            rig = i
            break
    st = s[:lef] + '0' + s[rig+1:]
    print(st)

```
 **C++ solution**
```cpp
#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sw = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] < s[i-1])sw = 0;
        }
        if(sw){
            cout << s << 'n';
            continue;
        }
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1')break;
            ans.push_back('0');
        }
        ans.push_back('0');
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '0')break;
            ans.push_back('1');
        }
        cout << ans << 'n';
    }
}

```
#### [C. RationalLee :](../problems/C._RationalLee.md)

Invented by [DeadlyCritic](https://codeforces.com/profile/DeadlyCritic "Master DeadlyCritic") and [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic").

 **Brief Solution**BriefSolution :

Give greatest elements to friends with wi=1. For the rest sort the elements in non-descending order of ai and sort the friends in non-ascending order of wi then give first w1−1 elements to friend 1, next w2−1 elements to friend 2 and so on, also give k−i+1-th greatest element to friend i (1≤i≤k).

 **Complete Proof**
### [1369C - RationalLee](../problems/C._RationalLee.md "Codeforces Round 652 (Div. 2)")

$\mathcal Complete\; \mathcal Proof$ :

First if $w_i = 1$ for some $i$, then assign the greatest element to $i$-th friends, it's always better obviously.

Sort the elements in non-descending order and sort the friends in non-ascending order of $w_i$. Define $v_i$ the set of indices of elements to give to $i$-th friend. Also define $l_i$ the minimum element to give to $i$-th friend and $r_i$ the maximum element to give to $i$-th friend, and define $m = \max\limits_{1\,\le\,i\,\le\,k} w_i$.

Now it's easy to see that the first element of $a$(the smallest element) is always equal to $l_i$ for some $i$, Indeed it's better to have the rest of $v_i$ equal to a small number except one of them, which should be equal to a very large number. So we can greedily assign $a_1$, $a_2$ ... $a_{{w_i}-1}$ to $v_i$, and then assign $a_n$ to it, also it's better to have $w_i = m$. One can prove that there exist an optimal distributing such that the set($\{a_1, a_2 \ldots a_{m-1}, a_n\}$) is equal to one of $v_i$-s(proof is blow). So add $a_1 + a_n$ to the answer for remaining elements of $a$(excluding the set) and remaining friends(excluding one of the friends with maximum $w_i$) and so, it will be optimal.

Look at an optimal distributing (which maximizes sum of happiness), first element of $a$ is in $v_i$ for example, we want to prove that in at least one of the optimal distributings $w_i-1$ smallest elements of $a$ are in $v_i$ (including the first element), proof by contradiction:

If at least one of the smallest $w_i-1$ elements is not in $v_i$, then call the smallest of them $x$, lets say it's in $v_j$, now add $x$ to $v_i$(and erase it from $v_j$), instead add a greater number than $x$ in $v_i$ to $v_j$ (it's at least two of them, and one of them is $r_i$, so there exist another one, erase it from $v_i$ and add it to $v_j$), it's easy to see that sum of happiness won't decrease that way, continue the process until all $w_i-1$ smallest elements are in $v_i$, so we have an optimal answer which has all $w_i-1$ smallest elements in $v_i$, contradiction!

As we proved above, we have an optimal distributing such that all $w_i-1$ smallest elements are in $v_i$(for some $i$), now we want to prove that the greatest element is in $v_i$ in at least one of the optimal distributings, again proof by contradiction.

Lets say it's not that way, so look at an optimal distributing such that first $w_i-1$ elements are in $v_i$ and $r_i$ is not equal to the greatest element(for some $i$), if there exist such $j$ that $r_i < l_j$, then swap $r_i$ and $l_j$, the resulting distributing has the same happiness, continue it until no such $j$ exist, now lets say the greatest element of $a$ is in $v_j$ for some $j$, also we know that $r_j$ is equal to the greatest element of $a$ and $l_j \le r_i$(if $r_i < l_j$ then the process of swapping is not finished, which is contradiction). So now we can swap $r_i$ and $r_j$, again the resulting distributing has happiness greater than or equal to the happiness of the optimal distributing(the one we chose in the beginning), and so, its also an optimal distributing, and $r_i$ is equal to the greatest element, we have found an optimal distributing such that first $w_i-1$ elements of $a$ and $a_n$ are in $v_i$(for some $i$), contradiction!

Now we have proved that there exist an optimal distributing such that first $w_i-1$ elements of $a$ and $a_n$ are in $v_i$(for some $i$), call such optimal distributing STAR, and now the only remaining part is to prove that there exist an optimal distributing such that first $m-1$ elements of $a$ and $a_n$ are in $v_i$(for some $i$). See the whole algorithm, its like "we choose a permutation of friends then we do that greedy assignment to them one by one from left to right", now we want to prove that there exist an optimal distributing such that it's STAR and it's permutation is sorted in non-descending order of $w$, call them GOOD distributings. Again, proof by contradiction :

Choose a distributing such that it's a STAR, it's permutation(called $p$) is not sorted in non-descending order of $w$(otherwise it's a GOOD distributing, contradiction!), so there exist an $i$ such that $w_{p_i} > w_{p_{i+1}}$, now swap them(i. e. swap $p_i$ and $p_{i+1}$ and then do the same greedy assignment using the modified permutation of friends), it's easy to see that happiness of friends after $i+1$ in permutation $p$ wont change, also happiness of friends before $i$ in the permutation wont change as well.

Now look at the happiness of $p_i$ and $p_{i+1}$, you can realize that sum of happiness will increase.

You really don't need to prove it like that, it's not time friendly at all. ^-^

 **Python solution**
```cpp
t = int(input())
for tc in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    w = list(map(int, input().split()))
    a.sort(reverse = True)
    w.sort()
    ii, l, r = k, 0, n-1
    ans = 0
    for i in range(k):
        if(w[i] > 1):
            ii = i
            break
        ans = ans+a[l]*2
        l = l+1
    for u in range(k-1, ii-1, -1):
        i = w[u]
        ans = ans + a[l] + a[r]
        r = r-i+1
        l = l+1
    print(ans)

```
 **C++ solution**
```cpp
#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define int ll

using namespace std;
const int MN = 2e5+7;

vector<int> v[MN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 0; i <= n; i++)v[i].clear();
        ll a[n], w[k];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < k; i++){
            cin >> w[i];
        }
        sort(w, w+k);
        sort(a, a+n);
        for(int i = 0; i < k/2; i++)swap(w[i], w[k-i-1]);
        int po = 0;
        for(int i = 0; i < n-k; i++){
            while(w[po] == v[po].size()+1)po++;
            v[po].push_back(a[i]);
        }
        ll ans = 0;
        int qf = 1;
        for(int i = 0; i < k; i++){
            ans += a[n-i-1];
            if(v[i].size())ans += v[i][0];
            else ans += a[n-qf], qf++;
        }
        
        cout << ans << 'n';
    }
}

```
#### [D. TediousLee :](../problems/D._TediousLee.md)

Invented by [DeadlyCritic](https://codeforces.com/profile/DeadlyCritic "Master DeadlyCritic").

 **Brief Solution**BriefSolution :

Realize that a RDB of level i is consisted of a vertex (the root of the RDB of level i) connected to the roots of two RDBs of level i−2 and a RDB of level i−1. 

Run a DP and calculate the answer for each level i (3≤i≤2⋅106), then dpi=2⋅dpi−2+dpi−1+(i%3==0?4:0).

 **Complete Proof**
### [1369D - TediousLee](../problems/D._TediousLee.md "Codeforces Round 652 (Div. 2)")

$\mathcal Complete \mathcal Proof$ :

First realize that a RDB of level $i$ is consisted of a vertex (the root of the RDB of level $i$) connected to the roots of two RDBs of level $i-2$ and a RDB of level $i-1$. 

Now define $dp_i$ equal to the answer for a RDB of level $i$. Also define $r_i$ equal to $1$ if Lee can achieve $dp_i$ yellow vertices in a RDB of level $i$ such that the root is green, and $0$ otherwise. It's easy to see that $dp_i$ is equal to either $2 \cdot dp_{i-2} + dp_{i-1}$ or $2 \cdot dp_{i-2} + dp_{i-1} + 4$. If both $r_{i-1}$ and $r_{i-2}$ are equal to $1$, then we can color the claw rooted at the root of the RDB, then $r_i = 0$ and $dp_i = 2 \cdot dp_{i-2} + dp_{i-1} + 4$. Also if either $r_{i-2}$ or $r_{i-1}$ is equal to $0$ then $r_i = 1$ and $dp_i = 2 \cdot dp_{i-2} + dp_{i-1}$.

 **Python solution**
```cpp
v = []
v.append(0)
v.append(0)
v.append(0)
v.append(4)
v.append(4)
mod = int(1e9+7)
for i in range (5, 2000010):
    v.append(max(((2*v[i-2])+v[i-1])%mod,((4*v[i-4])+4*v[i-3]+v[i-2]+4)%mod))
t = int(input())
for _ in range(t):
    print(v[int(input())])

```
 **C++ solution**
```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = int(1e9+7);
const int MN = int(2e6+7);

int dp[MN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    dp[0] = dp[1] = 0;
    dp[2] = 4;
    for(int i = 3; i < MN; i++){
        long long w = dp[i-1];
        w += 2*dp[i-2] + (i % 3 == 2)*4;
        w %= mod;
        dp[i] = w;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n--;
        cout << dp[n]%mod << 'n';
    }
}

```
Challenge : Try solving problem D for n≤1018n≤1018. (no matrix-multiplication)

#### [E. DeadLee :](../problems/E._DeadLee.md)

Invented by [DeadlyCritic](https://codeforces.com/profile/DeadlyCritic "Master DeadlyCritic").

 **Hints**Hints :

 1. Find some greedy approaches. Its guessable that the problem is greedy.
2. Define si for food i equal to the number of guys who likes food i. Then find some condition which is enough to be sure that no answer exist.
3. See the last friend in a suitable permutation. What food will he eat?
4. Its easy to see that if ∀1≤i≤m⇒si>wi, then no answer exist.
5. If a food i exist such that si≤wi, then what will happen to the friends who like this food? They can always eat this food no matter what happens, so lets call them as late as possible(so its less likely for them to eat more than one plate). Now continue the process with rest of the friends and foods.
 **Brief Solution**BriefSolution :

Define si equal to the number of friends who likes food i. If for some i, si≤wi then place all the friends who likes food i in the end of the permutation and erase them and continue doing the same thing for the rest of the friends and foods

It's easy to see that if the set of friends became empty then the permutation we constructed is suitable(and no one would eat Lee), otherwise Lee has to buy more food!!

 **Complete Proof**
### [1369E - DeadLee](../problems/E._DeadLee.md "Codeforces Round 652 (Div. 2)")

$\mathcal Complete\;\mathcal Solution$ :

Define $s_i$ equal to the number of friends who likes food $i$. We want to proof that if $\forall 1 \le i \le m \Rightarrow s_i > w_i\, \text{or} \, s_i = 0$ then no answer exist, it can be proved easily by contradiction, just look at the last friend in any suitable permutation, he will eat Lee as there is no food for him.

So if it was the case, then print Dead and terminate, otherwise place all the guys who likes food $i$ in the end of the permutation, they wont eat Lee as they can always eat food $i$, also it's always better to place them in the end, as if we place them in the end, then they wont eat two plates. Continue the process until no friends exist or no $i$ exist such that $w_i \ge s_i > 0$.

Note that when we erase the friends, we have to update $s_i$, also if $s_i = 0$ we should erase food $i$ from the set of foods.

$\mathcal Implementation\;\mathcal Details$ :

Instead of erasing friends/foods, just remember if a friend/food is erased or not using another array. Also updating $s$ should not be that much hard(when marking $i$-th friend, decrease $s_{x_i}$ and $s_{y_i}$ by one, if there exist any), also you can have the food $i$ with maximum $w_i-s_i$ with a priority queue, or any other data structure in $O(\log_2{n})$.

The whole solution will work in $O((n+m)\cdot \log_2{(n+m)}$ time, you can also try achieving $O(n+m)$ and then show-off it in the comment section ^_^.

 **Python solution**
```cpp
import sys
import heapq

inputarray = [int(x) for x in sys.stdin.read().split()]

n, m = inputarray[0], inputarray[1]

s, w = [], []
for i in range(2, n+2):
    w.append(inputarray[i])

g, eg, foodm, friendm, x, y = [], [], [], [], [], []

for i in range(n):
    s.append(0)
    foodm.append(0)
    g.append([])

for i in range(m):
    friendm.append(0)
    x.append(0)
    y.append(0)
    
inppo = n+2
for i in range(m):
    x[i], y[i] = inputarray[inppo], inputarray[inppo+1]
    inppo = inppo+2
    x[i] = x[i]-1
    y[i] = y[i]-1
    u = x[i]
    v = y[i]
    s[u] = s[u]+1
    s[v] = s[v]+1
    g[u].append(i)
    g[v].append(i)
    eg.append((v, u))

myq = []

ans = []

for i in range(n):
    heapq.heappush(myq, (-w[i]+s[i], i))

while len(myq): 
    u = myq[0]
    heapq.heappop(myq)
    if u[0] != -w[u[1]]+s[u[1]]:
        continue
    if(u[0] > 0):
        print("DEAD")
        sys.exit()
    foodm[u[1]] = 1
    sw = 1
    for i in g[u[1]]:
        if friendm[i] == 0:
            friendm[i] = 1
            if y[i] == u[1]:
                x[i], y[i] = y[i], x[i]
            s[x[i]] = s[x[i]]-1
            s[y[i]] = s[y[i]]-1
            heapq.heappush(myq, (-w[y[i]]+s[y[i]], y[i]))
            ans.append(i)
            if(len(ans) == m):
                sw = 0
                break;
    if(sw == 0):
        break
print("ALIVE")
for i in ans[::-1]:
    print(i+1, end=" ")

```
 **C++ solution**
```cpp
#include <bits/stdc++.h>

#define ll long long
#define fr first
#define sc second
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;
const int MN = 2e5+7;

int x[MN], y[MN], s[MN], w[MN], mark[MN], colmark[MN];

vector<int> v[MN], a;
vector<pii> f;

priority_queue<pii, vector<pii>, greater<pii>> pq;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> w[i];
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
        s[x[i]]++;
        s[y[i]]++;
        v[x[i]].push_back(i);
        v[y[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        if(s[i])pq.push({max(0, s[i]-w[i]), i});
        else colmark[i] = 1;
    }

    while(pq.size()){
        auto q = pq.top();
        pq.pop();
        if(q.fr != max(0, s[q.sc]-w[q.sc]))continue;
        if(q.fr > 0){
            cout << "DEADn";
            exit(0);
        }
        int id = q.sc;
        vector<int> wt;
        for(auto u : v[id]){
            if(mark[u])continue;
            a.push_back(u);
            if(x[u] == id)
                swap(x[u], y[u]);
            if(!colmark[x[u]])wt.push_back(x[u]);
            mark[u] = 1;
        }
        sort(all(wt));
        for(int i = 0; i < wt.size(); i++){
            s[wt[i]]--;
            if(i == wt.size()-1 || wt[i+1] != wt[i]){
                if(s[wt[i]]){
                    if(max(0, s[wt[i]]-w[wt[i]]) == 0)colmark[wt[i]] = 1;
                    pq.push({max(0, s[wt[i]]-w[wt[i]]), wt[i]});
                }
            }
        }
    }
    cout << "ALIVEn";
    for(int i = 0; i < a.size()/2; i++)swap(a[i], a[a.size()-i-1]);
    for(auto u : a){
        cout << u+1 << ' ';
    }
    cout << 'n';
}

```
#### [F. BareLee :](../problems/F._BareLee.md)

Invented by [DeadlyCritic](https://codeforces.com/profile/DeadlyCritic "Master DeadlyCritic") and [AS.82](https://codeforces.com/profile/AS.82 "Candidate Master AS.82").

 **Brief Solution**BriefSolution :

Define wins,e (s≤e) equal to 1 if Lee can win the game when s is written on the board, and equal to 0 otherwise, also define loses,e the same way.

Win :

If e is odd then if s is odd Lee loses otherwise Lee wins. So if e is even then :

 * if e2<s≤e then if s is odd then Lee wins, otherwise Lee loses;
* if e4<s≤e2 then Lee wins;
* if s≤e4 then the answer is equal to wins,⌊e4⌋.

Lose :

If e<2⋅s, then Lee can immediately lose, otherwise the answer is equal to wins,⌊e2⌋.

 **Complete Proof**
### [1369F - BareLee](../problems/F._BareLee.md "Codeforces Round 652 (Div. 2)")

$\mathcal Complete \mathcal Proof$ :

Define $w_{s,\,e}$ ($s \le e$) equal to $1$ if Lee can win the game when $s$ is written on the board, and equal to $0$ otherwise, also define $l_{s,\,e}$ the same way. This leads to a simple dp. Forget $l$ for now.

Recall that a state ${i,\,j}$ of our dp is a losing state if $w_{i,\,j} = 0$, and is a winning state otherwise.

You can guess $w_{s,\,e}$ for all $s$ in range $\frac e 4 < s \le e$ in $O(1)$, you don't have to store them :

If $e$ is odd then it will be $w_{1,\,e} = 1, w{2,\,e} = 0, w{3,\,e} = 1 \dots w{e,\,e} = 0$, in other words if $e$ is odd, then if $s$ is odd too $w{s,\,e} = 0$, otherwise $w{s,\,e} = 1$. Prove it by induction, for $s = e$ it's correct, assume that for an integer $i$ ($1 \le i < e$) we have proved that the statement is correct for all $j$ where $i < j \le e$, now we want to prove the statement for $i$ :

If $i$ is odd then both $i + 1$ and $2 \cdot i$ are winning states (as they are even), also if $i$ is even then $i + 1$ is odd, $i+1$ is smaller than $e$ so it's a losing state(induction assumption).

From now we consider $e$ to be even. Also $\times 2$ operation is replacing $a$, the number on the board, with $2 \cdot a$, and $+ 1$ operation is the other move.

For $\frac e 2 < s \le e$ whoever uses $\times 2$ operation will lose. So they all have to use $+ 1$ operation, so for ${e \over 2} < s \le e$ if $w$ is odd, then $w_{s,\,e} = 1$, otherwise $w_{s,\,e} = 0$. (it's obvious, it can be proved with a simple induction like the one in previous part)

For ${e \over 4} < s \le {e \over 2}$, Lee can do a $\times 2$ operation in the first turn and he will win because his opponent is starting a losing state.

For $s \le {e \over 4}$, $w_{s,\,e}$ is equal to $\displaystyle w_{s,\,\lfloor {e \over 4} \rfloor}$. (why?)

Now it's time to calculate $l_{s,\,e}$.

Remember, whoever writes an integer greater than $e$ will lose, so if $e < 2 \cdot s$ then the first guy can immediately lose. So $l_{s,\,e}$ for ${e \over 2} < s \le e$ is equal to $1$. And $l_{s,\,e}$ for $s \le {e \over 2}$ is equal to $\displaystyle w_{s,\,{\lfloor {e \over 2} \rfloor}}$. (why?)

 **Python solution**
```cpp
import sys

inpy = [int(x) for x in sys.stdin.read().split()]

def win(s, e) :
    if e == s :
        return False
    if e == s+1 :
        return True
    if e % 2 == 1 :
        if s % 2 == 1 :
            return False
        return True
    q = e//4
    
    if s <= q :
        return win(s, q)
    q = e//2
    if(s > q) :
        return (e-s) % 2 == 1
    return True

def lose(s, e) :
    q = e//2
    if(s > q) :
        return True
    else :
        return win(s, q)

t = inpy[0]
start = (True, False)
inpo = 1
v = (True, True)

for tc in range(t):
    if(inpo+1 >= len(inpy)) :
        print('wtf')
    s, e = inpy[inpo], inpy[inpo+1]
    inpo = inpo+2
    v = ((win(s, e), lose(s, e)))
    if start[0] and start[1] :
        break
    if (not start[0]) and (not start[1]) :
        break
    if start[1] :
        v = (not v[0], not v[1])
    start = (v[1], v[0])

if((start[0] != True and start[0] != False) or (start[1] != True and start[1] != False)) :
    print('wtf')
sw = 2
if start[1] :
    sw = sw-1
    print(1, end = ' ')
else :
    sw = sw-1
    print(0, end = ' ')
if start[0] :
    print(1)
    sw = sw-1
else :
    print(0)
    sw = sw-1
if sw :
    print(wtf)

```
 **C++ solution**
```cpp
#include <iostream>
#include <vector>
#include <string>
#define fr first
#define sc second
#define ll long long
#define int ll

using namespace std;

const int MN = 1e5+7;

pair<int, int> c[MN];

int chk(ll s, ll e){
    if(e == s)return 0;
    if(e == s+1)return 1;
    if(e & 1){
        if(s & 1)return 0;
        return 1;
    }
    if(s <= e/4)
        return chk(s, e/4);
    if(s > (e/4)*2)return ((e-s)&1);
    else return 1;
}

int lck(ll s, ll e){
    if(s*2 > e)return 1;
    int w = e/2 + 3;
    while(w*2 > e)w--;
    return chk(s, w);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        c[i] = {chk(x, y), lck(x, y)};
    }

    int f = 1;
    int s = 0;
    for(int i = 0; i < n; i++){
        if(f == 1 && s == 1)break;
        if(f == 0 && s == 0)break;
        if(s == 1) c[i].fr^=1, c[i].sc^=1;
        f = c[i].sc;
        s = c[i].fr;
    }
    cout << s << ' ' << f << 'n';
}

```
