# Tutorial_(en)


### [1330A - Dreamoon and Ranking Collection](../problems/A._Dreamoon_and_Ranking_Collection.md "Codeforces Round 631 (Div. 2) - Thanks, Denis aramis Shitov!")

The total number of rounds this person participates after $x$ more rated contests is $n+x$. So the number of places this person collects cannot exceed $n + x$. Then we can iterate $k$ from $n+x$ to $1$. In each iteration, let $r$ be the number of integers from $1$ to $k$ which doesn't appear in $a_i$. This person can collect all places from $1$ to $k$ if only if $r \le x$. So the answer is the first $k$ meeting the condition $r \le x$ when iterating. The solution can be implemented in time complexity $O((n+x)^2)$ as a reference solution.

There are also many $O(n)$ solutions that can solve this problem. But in the experience of author and testers, it's easy to make some mistake in the detail when writing $O(n)$ solution : ) Please try it by yourself.

 **author's code:**
```cpp
#include<cstdio>
const int MAX_V = 201;
bool achieve[MAX_V];
void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n + x; i++) {
        achieve[i] = false;
    }
    for(int i = 1; i <= n; i++) {
        int ranking;
        scanf("%d", &ranking);
        achieve[ranking] = true;
    }
    for(int k = n + x; k > 0; k--) {
        int v = 0;
        for(int i = 1; i <= k; i++) {
            if(!achieve[i]) v++;
        }
        if(v <= x) {
            printf("%dn", k);
            return;
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
```
 
### [1330B - Dreamoon Likes Permutations](../problems/B._Dreamoon_Likes_Permutations.md "Codeforces Round 631 (Div. 2) - Thanks, Denis aramis Shitov!")

Let $ma$ be the maximum value of all elements in $a$ . 

If you can recover the the array $a$ to two permutations $p1$ abd $p2$, then $ma$ must be $\max(len1, len2)$. 

So there are at most two case: 

1. $len1 = ma, len2 = n - ma$, 

2. $len1 = n - ma, len2 = ma$. 

We can check the two cases separately with time complexity $O(n)$. Please see the example code for detail. 

 **author's code**
```cpp
#include<cstdio>
const int SIZE = 200000;
int p[SIZE];
int ans[SIZE][2];
int ans_cnt;
bool judge(int a[], int n){
    static int used[SIZE+1];
    for(int i = 1; i <= n; i++) used[i] = 0;
    for(int i = 0; i < n; i++) used[a[i]] = 1;
    for(int i = 1; i <= n; i++) {
        if(!used[i]) return 0;
    }
    return 1;
}
bool judge(int len1, int n){
    return judge(p, len1) && judge(p + len1, n - len1);
}
int main() {
    int t = 0;
    scanf("%d", &t);
    while(t--) {
        ans_cnt = 0;
        int n;
        scanf("%d", &n);
        int ma=0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            if(ma < p[i]) ma = p[i];
        }
        if(judge(n - ma,n)) {
            ans[ans_cnt][0] = n - ma;
            ans[ans_cnt++][1] = ma;
        }
        if(ma * 2 != n && judge(ma,n)) {
            ans[ans_cnt][0] = ma;
            ans[ans_cnt++][1] = n - ma;
        }
        printf("%dn", ans_cnt);
        for(int i = 0; i < ans_cnt; i++) {
            printf("%d %dn", ans[i][0], ans[i][1]);
        }
    }
    return 0;
}
```
 
### [1329A - Dreamoon Likes Coloring](https://codeforces.com/contest/1329/problem/A "Codeforces Round 631 (Div. 1) - Thanks, Denis aramis Shitov!")

After reading the statement, you may find this is a problem that will be tagged as "constructive algorithms" in Codefores. And you also can find this problem is just problem A in Div. 1. So basically we can expect there exist some simple methods to solve it.

If a "constructive algorithms" problem asks you to determine whether the solution exists or not, usually they have a common pattern(especially in problem hardness which is before Div. 1 B(inclusive)), this is, there are some simple constraints can divide test data into "Yes", and "No". Therefore, the first thing to solve this problem is finding some trivial conditions that cannot achieve Dreamoon's hope. 

After some try, you may find there are two trivial conditions that achieving Dreamoon's hope is impossible. The two conditions are listed as follows:

1. Sum of $l_i$ is less than $n$. In this condition, there always is at least one empty grid.

2. There exists some $i$ such that $l_i + i - 1 > n$. If $n - l_i < i - 1$, it means after you do $i$-th operation, there only $n - l_i$ grid is not colored by $i$-th color. So at least one of previous $i-1$ color will disapear after this operation. 

Now I want to talk about another feature of some "constructive algorithms" first. 

Sometimes, the condition given by the problem is to "open", this is to say that if we added some more strict constraint, the problem is still can be solved. And when the constraint it more strict, we can deduce the solution more easily.

One of common "strict constraint" is "sorted". I believe you have ever seen many problems that the first step is sorting something. Now, we also want to apply "sorted" in the problem.

After applying "sort", we firstly consider the edge cases of above two impossible conditions. The first case is "sum of $l_i$ is equal to $n$". In this case, we have a unique solution after applying "sort", $p_i = m - \sum\limits_{j=i+1}^{m} l_j + 1$. The second case is $l_i + i - 1 = n$ is hold for all $i$. In this case, there is also a unique solution that $p_i = i$. The two cases coressond to $n$ is largest and $n$ is smallest among all $n$ that exist solutions for same $l_i$. And for same $l_i$, when we decrase $n$ from the largest possible value, we can just change $p_i$ from $m - \sum\limits_{j=i+1}^{m} l_j + 1$ to $i$ for some smallest indices $i$ to get solution. To sum it up, finally, we get the answer. The answer is just $p_i = \max(i, n - suffix\\_sum[i] + 1)$, for each $i$.

There exist many other methods to construct solutions. I believe the construction method one can think out is relative to the study experience.

 **author's code**
```cpp
#include<bits/stdc++.h>
const int SIZE = 100002;
int len[SIZE];
long long suffix_sum[SIZE];
void err() {puts("-1");}
void solve() {
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; i++) {
        scanf("%d", &len[i]);
        if(len[i] + i - 1 > N) {
            err();
            return;
        }
    }
    for(int i = M; i > 0; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + len[i];
    }
    if(suffix_sum[1] < N) {
        err();
        return;
    }
    for(int i = 1; i <= M; i++) {
        printf("%lld", std::max((long long)i, N - suffix_sum[i] + 1));
        if(i < M) putchar(' ');
        else puts("");
    }
}
int main() {
    solve();
    return 0;
}
```
 
### [1329B - Dreamoon Likes Sequences](https://codeforces.com/contest/1329/problem/B "Codeforces Round 631 (Div. 1) - Thanks, Denis aramis Shitov!")

Firstly, we define a function $h(x)$ as the position of the highest bit which is set to 1 in a positive integer $x$. For example, $h(1) = 0, h(2) = h(3) = 1$, and $h(4) = h(7) = 2$.

If the constraints in this problem is satisfied, there is some observations, $h(a_i) = h(b_i)$ and $h(a_i)$ must less than $h(a_{i+1})$. And luckily, if $h(a_i) < h(a_{i+1})$ is always hold, the constraints in this problem will also be satisfied (Please prove them by yourself or wait for someone prove it in comments : ) P.S. the link of proof written by someone is int the end. )

In other words, for each non-negative integer $v$, there is at most one $i$ such that $h(a_i) = v$. This is, at most one of the positive numbers in range $[2^v, min(2^{(v+1)}-1,d)]$ can occur in $a_i$. In each non-empty range, we can choose one integer in it or don't choose anyone. So for each of them we have $min(2^{(v+1)}-1,d) - 2^v + 2$ different choice. Then according to the rule of product, we can multiply all number of choices for different $v$ and minus the value by one to get the answer. For example, when d = 6, there are $2$ choices for $v = 0$, $3$ choices for $v=1$, $4$ choices for $v=2$. So the answer for $d = 6$ is $2 \times 3 \times 4 - 1 = 23$. 

**UPD: [onthefloor](https://codeforces.com/profile/onthefloor "Master onthefloor") provides proof for what I mention** [here](Tutorial_(en).md?#comment-597742).

 **author's code**
```cpp
#include<bits/stdc++.h>
void solve(){
    int d, m;
    scanf("%d%d",&d, &m);
    long long answer=1;
    for(int i = 0; i < 30; i++) {
        if(d < (1 << i)) break;
        answer = answer * (std::min((1 << (i+1)) - 1, d) - (1 << i) + 2) % m;
    }
    answer--;
    if(answer < 0) answer += m;
    printf("%lldn",answer);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}
```
 
### [1329C - Drazil Likes Heap](https://codeforces.com/contest/1329/problem/C "Codeforces Round 631 (Div. 1) - Thanks, Denis aramis Shitov!")

The property of heap we concern in this problem mainly are: 

1. The tree is a binary tree, each node has a weight value.

2. The weight of a node is always larger than the weight of its children.

3. We use $a[I]$ to record the weight of vertex $i$, and the number of its children are $2 \times i$ and vertex $2 \times i + 1$ (if exist). 

Another key point we should consider seriously is before all operations and after all operations, the tree must be a perfect binary tree. Many contestants didn't notice the constraint during the contest. 

I think there are two different thinking directions for this problem. One is considering node from bottom to top. Another one is considering node from top to bottom. For me, from bottom to top is more intuitive.

Now we talk about "from bottom to top" first, it means we consider node from larger index to smaller index in the tree after all operations (call it final tree after). For the leaves in the final tree, it's not hard to know, the minimum possible final weight of each leaf is the minimum weight of nodes in its subtree before all operations (call it beginning tree after). For the other nodes in the final tree, its weight must satisfy two constraints, one is it should be larger than the final weight of his children, another is the weight should exist in its subtree of the beginning tree. Luckily, these lower bounds are all constraints we should consider to get the answer. For each leaf in the final tree, we maintain a data structure that stores all weight of its subtree in the beginning tree. Then the minimum value in this data structure is its final weight. For other nodes in the final tree, we merge the two data structures of its children. the remove all value which is less than the final weight of his children. There are many data structure can do these operations, such as min heap(author's code) or sorted array(isaf27's code). 

With the above method, we get the minimum possible sum of the remaining $2^g-1$ elements. But we still don't know how to construct it. All we know is which weight values are reaming in the final tree. Now I want to prove that no matter how the order I call the function $f$, if the remaining weight values set is the same, the final shape of the final tree will be the same. 

This time I prove it from top to bottom. We only know which weight values set to remain in the final, Then We iterate node from smallest index to the larger one. We always can determine the weight value of the iterated node, because the weight value only can be the maximum value in its subtree. This trait also can let us know that the final tree we get in our method is a perfect binary tree.

Conclude all things above. after we can apply the function $f$ from bottom to top on these nodes with weight value doesn't exist in the final tree.

In the "from bottom to top" method, it has some thinking level difference between calculating the minimum sum and constructing a list of possible operations. So I determine let competitors output the operations. 

- - -

Now we talk about the "from top to bottom" method. The main idea of this method is iterating index from $1$ to $2^g-1$ and in each iteration, applying the function $f$ on $i$-th node until the shape of the final tree is impossible to become a perfect binary tree. The method is quite easy to write and almost has no difference when asking you to output the operations. But I think it's hard to prove. Evenly, I think the solution should be wrong until I write this solution and test it.

Firstly I want to prove the minimum possible final weight value of node $1$ is the same as the above "from top to bottom" method get. We call the value as $mi_1$. If some algorithm $B$ can get more small weight value in the final tree, It means all weight values which are not smaller than $mi_1$ disappear. But according to the conclusion "if the remaining weight values set is the same, the final shape of the final tree will be the same.". the final tree generated by $B$ can also get with firstly applying the function $f$ on node $1$ at least one more time than above "from top to bottom" algorithm, and do some other operations. But it will make the final tree is impossible to be the perfect binary tree. Now we disprove it.

Now we want to prove the final weight value of node $i$($i>1$) is the same as the above "from top to bottom" method get. Only when applying function $f$ on ancestors and descendants of node $i$ will affect the final weight value of node $i$. And when we apply on its ancestors, the $f$ may recursively apply $f$ on $it$ at most once. So each time $f$ applies on its ancestors is equivalent to apply on itself once or do nothing. Therefore, The proof can be don as what we do on node $1$ just by only considering the subtree of node $i$. 

Now, we have proved the "top to bottom" algorithm can make each node of the final tree has the minimum possible weight value. 

When I found the "top to bottom" algorithm during preparing the contest, I ever consider changing the problem to something else because the method is too easy to guess and to write. But I have no other more proper problem that can be used. It's a little pity for me.

[a super simple solution which is differet to this blog](Tutorial_(en).md?#comment-597934) provided by [Swistakk](https://codeforces.com/profile/Swistakk "Legendary Grandmaster Swistakk").

 **author's code (from bottom to top with min heap)**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1<<20;
int INF = 1000000001;
pair<int, int> a[SIZE];
int final_v[SIZE];
bool used[SIZE];
int h, g;
void pull(int id) {
    while(a[id] > min(a[id<<1], a[(id<<1)|1])) {
        if(a[id<<1] < a[(id << 1) | 1]) {
            swap(a[id<<1], a[id]);
            id <<= 1;
        }
        else {
            swap(a[(id<<1)|1], a[id]);
            id = (id << 1) | 1;
        }
        if(id >= (1 << h)) return;
    }
}
void solve() {
    scanf("%d%d", &h, &g);
    long long an = 0;
    for(int i = 1; i < (1 << h); i++) {
        used[i] = 0;
        scanf("%d", &a[i].first);
        a[i].second = i;
        final_v[i] = 0;
    }
    h--;
    for(int lv = h - 1; lv >= 0; lv--) {
        int ll = 1 << lv;
        int rr = 1 << (lv + 1);
        for(int i = ll; i < rr; i++) {
            pair<int, int> tmp = a[i];
            int bot = i << (h - lv);
            a[i] = a[bot];
            a[bot] = make_pair(INF, 0);
            pull(i);
            if(lv < g) {
                int need_mi = max(final_v[i * 2], final_v[i * 2 + 1]);
                while(a[i].first < need_mi) {
                    a[i] = make_pair(INF, 0);
                    pull(i);
                }
                an += final_v[i] = a[i].first;
                used[a[i].second] = 1;
                a[i] = tmp;
                pull(i);
            }
            else {
                a[bot] = tmp;
            }
        }
    }
    printf("%lldn", an);
    bool first_time = true;
    for(int i = (1 << (h + 1)) - 1; i > 0; i--) {
        if(!used[i]) {
            if(!first_time) printf(" ");
            else first_time = false;
            printf("%d", i);
        }
    }
    puts("");
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
```
 **isaf27's code(from bottom to top with sorted array)**
```cpp
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7; //

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 35;
const int T2 = 2 * T;

int h, g, a[T2], n;
bool mark[T];
int id[T], buf[T], timer;

bool cmp(int i, int j)
{
    return (a[i] < a[j]);
}

int pos;

void dfs_write(int p)
{
    id[pos++] = p;
    if (2 * p + 1 <= n)
    {
        dfs_write(2 * p);
        dfs_write(2 * p + 1);
    }
}

int dfs(int p, int sz)
{
    if ((1 << (g - 1)) <= p && p < (1 << g))
    {
        int l = timer;
        timer += sz;
        pos = l;
        dfs_write(p);
        sort(id + l, id + l + sz, cmp);
        mark[id[l]] = true;
        return id[l];
    }
    int l = timer;
    int new_sz = ((sz - 1) / 2);
    int s1 = dfs(2 * p, new_sz);
    int s2 = dfs(2 * p + 1, new_sz);
    merge(id + l, id + l + new_sz, id + l + new_sz, id + l + new_sz + new_sz, buf, cmp);
    buf[sz - 1] = p;
    for (int i = 0; i < sz; i++)
        id[i + l] = buf[i];
    timer++;
    if (cmp(s1, s2))
        s1 = s2;
    for (int i = 0; i < sz; i++)
        if (cmp(s1, id[i + l]))
        {
            mark[id[i + l]] = true;
            return id[i + l];
        }
    return 0;
}

void rm(int i)
{
    if (a[2 * i] == 0 && a[2 * i + 1] == 0)
    {
        a[i] = 0;
        mark[i] = false;
        return;
    }
    if (a[2 * i] > a[2 * i + 1])
    {
        a[i] = a[2 * i];
        mark[i] = mark[2 * i];
        rm(2 * i);
    }
    else
    {
        a[i] = a[2 * i + 1];
        mark[i] = mark[2 * i + 1];
        rm(2 * i + 1);
    }
}

void dfs_ans(int p)
{
    while (a[p] != 0 && !mark[p])
    {
        cout << p << " ";
        rm(p);
    }
    if (a[p] == 0)
        return;
    dfs_ans(2 * p);
    dfs_ans(2 * p + 1);
}

void solve()
{
    cin >> h >> g;
    n = (1 << h) - 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        mark[i] = false;
    timer = 0;
    dfs(1, n);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        if (mark[i])
            ans += a[i];
    cout << ans << "n";
    dfs_ans(1);
    cout << "n";
    for (int i = 0; i <= n; i++)
        a[i] = 0;
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
```
 **author's code (from top to bottom)**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1<<20;
int INF = 1000000001;
int a[SIZE], ops[SIZE];
int h, g;
int qq[24], qn;
int pull(int id) {
    int tmp = a[id];
    a[id] = 0;
    qn = 0;
    qq[qn++] = id;
    while(id * 2 < (1 << h) && a[id] < max(a[id<<1], a[(id<<1)|1])) {
        if(a[id<<1] > a[(id << 1) | 1]) {
            swap(a[id<<1], a[id]);
            id <<= 1;
        }
        else {
            swap(a[(id<<1)|1], a[id]);
            id = (id << 1) | 1;
        }
        qq[qn++] = id;
    }
    if(id < (1 << g)) {
        for(int i = qn - 1; i > 0; i--) {
            a[qq[i]] = a[qq[i - 1]];
        }
        a[qq[0]] = tmp;
        return 0;
    }
    return tmp;
}
void solve() {
    scanf("%d%d", &h, &g);
    long long an = 0;
    for(int i = 1; i < (1 << h); i++) {
        scanf("%d", &a[i]);
        an += a[i];
    }
    int need = 0;
    for(int i = 1; i < (1 << g); i++) {
        while(1) {
            int v = pull(i);
            if(v) {
                an -= v;
                ops[need++] = i;
            }
            else break;
        }
    }
    printf("%lldn", an);
    for(int i = 0; i < need; i++) printf("%d%c", ops[i], " n"[i == need - 1]);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
```
 
### [1329D - Dreamoon Likes Strings](https://codeforces.com/contest/1329/problem/D "Codeforces Round 631 (Div. 1) - Thanks, Denis aramis Shitov!")

Denoting a string of length two which contains two $i$-th letter as $t_i$. For example, $t_0$ is "aa", $t_1$ is "bb" . 

And let $c_i$ be the occurrence count of $t_i$ as a substring in $a$. For example, when $a =$ "aaabbcaa", $c_0 = 3, c_1 = 1$, and for other $i$, $c_i = 0$.

In this problem, if only asking contestants output the smallest number of steps to make $a$ empty, the answer is simple. You just need to output $\max(\left \lceil\frac{\sum c_i}{2} \right\rceil,\max_{0 \le i \le 25}\limits{c_i})+1$. (I will call this fomula for a given string $a$ as $f(a)$ behind.)

Firstly, let's see how the value of all $c_i$ change in one step. There are only four kinds of possible change for all $c_i$.

1. For some $i$, $c_i$ is decreased by one. For example, deleting the first two letters of "abb".

2. For two different values $i$ and $j$. $c_i$ and $c_j$ are both decrease by one. For example, deleting the second and third letter of "aabb".

3. Nothing changes for all $c_i$. For example, deleting the first letter from "abb".

4. For some $i$, $c_i$ is added by one. For example, deleting the second letter from "aba".

Now, Let's consider how will these changes affect the $f(a)$. Amazing! All possible changes will decrease the value of $f(a)$ at most one! So if we can construct an algorithm to achieve it, then we solve it.

Now I introduce an algorithm of which time complexity is $O(n)$.

The algorithm can be divided into three phases.

1.

In this phase, we maintain a stack that stores the position of substring $t_i$ in the current string from left to right. When we iterate to a string $t_i$, there are two cases. Assum the top element in the stack is $t_j$. When $i$ is equal to $j$, we just add t_i into the stack. But if $i \ne j$, we do a step that removing all letters from the second letter of $t_j$ to the first letter of $t_i$. and pop $t_j$ from the stack. If there is any moment that $\left \lceil\frac{\sum c_i}{2} \right\rceil \le \max_{0 \le i \le 25}\limits{c_i})+1$ is hold (So maybe you won't do anything in this phase), the phase will be terminated.

2. 

In this phase, there must be an unique $x$ satisifying $c_x \ge \left \lceil\frac{\sum c_i}{2} \right\rceil$.

we also maintain a stack that stores the position of substring $t_i$ in the current string from left to right. But when we iterate to a string $t_i$, the action we should do are different from the first phase. 

Assum the top element in the stack is $t_j$. When there is exactly one number among $i$ and $j$ is $x$, we do a step that removing all letters from the second letter of $t_j$ to the first letter of $t_i$. and pop $t_j$ from the stack. Otherwise, we just add $t_i$ into the stack.

3. 

When the algorithm enters the phase, for all $i$ except $x$, $c_i$ will be $0$. So we can use all occurrence of $t_x$ to divide the string into $c_x+1$ segment and remove each segment one by on. After that the string will become empty.

Please see the reference code for the implementation detail.

 **author's code**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int SIZE = 2e5+10;
char s[SIZE];
int cnt[SIZE];
int cc[26];
int all_cnt;
int ma;
void update_ma() {
    while(ma > 0 && !cnt[ma]) ma--;
}
void dec1(int id) {
    cnt[cc[id]]--;
    cc[id]--;
    cnt[cc[id]]++;
}
pair<int, int> stk[SIZE];
int sn;
int m;
int now;
int last_len;
void add(int i, bool flag) {
    if(flag) {
        dec1(stk[sn - 1].second);
        dec1(stk[i].second);
        all_cnt -= 2;
        printf("%d %dn",now + 1, now + stk[i].first);
        update_ma();
        sn--;
        now -= stk[sn].first;
        if(i + 1 < m) {
            stk[i + 1].first += stk[sn].first;
        }
        else{
            last_len += stk[sn].first;
        }
    }
    else {
        stk[sn++] = stk[i];
        now += stk[i].first;
    }
}
void solve(){
    scanf("%s", s);
    int n = strlen(s);
    all_cnt = 0;
    int lt = 0;
    m = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            cc[s[i] - 'a']++;
            all_cnt++;
            stk[m++] = make_pair(i - lt, (int)(s[i] - 'a'));
            lt = i;
        }
    }
    last_len = n - lt;
    ma = 0;
    for(int i = 0; i < 26; i++) {
        cnt[cc[i]]++;
        ma = max(ma, cc[i]);
    }
    printf("%dn", 1 + max(ma, (all_cnt + 1) / 2));
    if(ma * 2 < all_cnt) {
        sn = now = 0;
        for(int i = 0; i < m; i++) {
            add(i, sn && stk[sn - 1].second != stk[i].second && ma * 2 < all_cnt);
        }
        m = sn;
    }
    int main_id = -1;
    for(int i = 0; i < 26; i++) {
        if(cc[i] == ma) main_id = i;
    }
    sn = now = 0;
    for(int i = 0; i < m; i++) {
        add(i, sn && ((stk[sn - 1].second == main_id) ^ (stk[i].second == main_id)));
    }
    for(int i = 0; i < sn; i++) {
        printf("%d %dn",1 ,stk[i].first);
    }
    printf("%d %dn", 1, last_len);
    memset(cc, 0, sizeof(cc));
    memset(cnt, 0, sizeof(int) * (ma + 1));
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) solve();
    return 0;
}
```
 
### [1329E - Dreamoon Loves AA](https://codeforces.com/contest/1329/problem/E "Codeforces Round 631 (Div. 1) - Thanks, Denis aramis Shitov!")

The idea of this problem comes to my brain when I recall that I'm cooking and I want to cut a carrot into many pieces and make the size of each piece as evenly as possible. I think this problem is very interesting. So that's why I determine to prepare a Codeforces contest after so many years. I hope I can share this problem with as many people as possible. 

There are some methods to solve this problem. I only show the most beautiful one below. This method is given by isaf27 (And most AC users solve it with this method. I admire them very much).

Firstly, we translate the problem into a more convenient model. 

Let $p_{m+1} = n$, $a_i = p_i - p_{i-1}$ ($1 \le i \le m+1$), $M = m + 1$, and $K = m + 1 + k$. Then the problem is equivalent to we want to do integer partition on $M$ integers $a_1, a_2, \ldots, a_M$, such that $a_i$ is divided into $d_i$ positive integers where $\sum d_i = K$. Our target is to minimize the difference between the largest integer and smallest integer after division.

An important observation is, we always can achieve our target by making the difference of the largest integer and the smallest integer that is divided from the same integer is at most one. So our target is minimizing $\max_{1 \le i \le M}\limits{(\left\lceil \frac{a_i}{d_i} \right \rceil)} - \min_{1 \le i \le M}\limits{(\left\lfloor \frac{a_i}{d_i} \right \rfloor)}$ where $1 \le d_i$ and $\sum_{i=1 \sim M}\limits d_i = K$.

There are two key values under the constraints $1 \le d_i$ and $\sum_{i=1 \sim M}\limits d_i = K$, one is the minimum value of $\max_{1 \le i \le M}\limits{(\left\lceil \frac{a_i}{d_i} \right \rceil)}$ (Let's call it $U$ after), another is the maximum value of $\min_{1 \le i \le M}\limits{(\left\lfloor \frac{a_i}{d_i} \right \rfloor)}$ (Let's call it $D$ after). $L$ and $U$ can be calculated by binary searching with time complexity $O(M log M)$. (This part is relatively easy so I won't mention it here.)

There are two conditions after calculating $L$ and $U$. One is, for all valid $i$, there exists at least one positive integer $d_i$ such that $L \le \left\lfloor \frac{a_i}{d_i} \right \rfloor \le \left\lceil \frac{a_i}{d_i} \right \rceil \le U$. In this case, the answer is just $U - L$. proof is as below.

Let $du_i$ as the largest positive integer such that $L \le \left\lfloor \frac{a_i}{d_i} \right \rfloor$ and $dl_i$ as the smallest positive integer such that $\left\lceil \frac{a_i}{d_i} \right \rceil \le U$. By the define of $L$ and $U$, we can get $\sum\limits_{i=1 \sim M} du_i \ge K$ and $\sum\limits_{i=1 \sim M} dl_i \le K$. So we always can choose some d_i where $d_l \le d_i \le d_u$ such that $\sum\limits_{i=1 \sim M} d_i = K$ and $L \le \left\lfloor \frac{a_i}{d_i} \right \rfloor \le \left\lceil \frac{a_i}{d_i} \right \rceil \le U$.

Now the essential condition is resolved. Another condition is there are some indices $i$ that we cannot find any positive integer $d_i$ such that $L \le \left\lfloor \frac{a_i}{d_i} \right \rfloor \le \left\lceil \frac{a_i}{d_i} \right \rceil \le U$. Let's call the set of these indices as $I$. For each element $j \in I$, let's calculate another two key values for index $j$. That is, we want to know the closest two values of $\frac{a_j}{d_j}$ near to range $[L, U]$ (one is above $[L,U]$ another is below $[L,U]$). Formulaically say, let $v$ be the smallest $d_j$ such that $\left\lfloor \frac{a_j}{d_j} \right \rfloor < L$ and call $\left\lfloor \frac{a_j}{v} \right \rfloor$ as $x_j$. And let $u$ be the largest $d_j$ such that $\left\lceil \frac{a_j}{d_j} \right \rceil > U$ and call $\left\lceil \frac{a_j}{u} \right \rceil$ as $y_j$. Imaging we have a set $S$ initially contains two positive integer $L$ and $U$. Now for each $j \in I$, we want to choose either $x_i$ or $y_i$ to add to $S$. Then the minimum possbile value of difference between largest element and smallest element in $S$ is the answer in this condition. The minimum possible value can be calculated as below.

Initially, for all $j \in I$, we choose $y_j$ to add to the set $S$. Then iterate from largest $y_j$ to smallest $y_j$. In each iteration, we remove $y_j$ from $S$ and add $x_j$ to $S$. The minimum possible value will exist during the process. These steps can also be done in time complexity $O(M log M)$.

The proof of correctness of the second condition is almost same as the first condition. We always can adjust $d_i$ such that $\sum\limits_{i=1 \sim M} d_i$ equal to $K$ for constructed result.

The overall time complexity is $O(m log m)$ for the above method.

In the end, I want to thanks everyone who takes part in this contest. The worth of the contest will reveal on you, when you learn thing from these problems. Thanks a lot.

 **isaf27's solution**
```cpp
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7; //

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(4e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 210;

ll up(ll a, ll b)
{
    return (a + b - 1) / b;
}

ll down(ll a, ll b)
{
    return a / b;
}

int m;
ll l[M], n, k;

void solve()
{
    cin >> n >> m >> k;
    ll pr = 0;
    for (int i = 0; i < m; i++)
    {
        ll p;
        cin >> p;
        l[i] = p - pr;
        pr = p;
    }
    l[m++] = n - pr;
    //for (int i = 0; i < m; i++)
    //    cerr << l[i] << " ";
    //cerr << "n";
    ll sum = k + m;
    ll bl = 1;
    ll br = n + 1;
    while (br - bl > 1)
    {
        ll h = (bl + br) >> 1LL;
        ll cur = 0;
        for (int i = 0; i < m; i++)
            cur += down(l[i], h);
        if (sum <= cur)
            bl = h;
        else
            br = h;
    }
    ll MIN = bl;
    bl = 0;
    br = n + 1;
    while (br - bl > 1)
    {
        ll h = (bl + br) >> 1LL;
        ll cur = 0;
        for (int i = 0; i < m; i++)
            cur += up(l[i], h);
        if (sum >= cur)
            br = h;
        else
            bl = h;
    }
    ll MAX = br;
    vector<pair<ll, ll>> ban;
    for (int i = 0; i < m; i++)
    {
        if (up(l[i], MAX) <= down(l[i], MIN))
            continue;
        ll bl = 0;
        ll br = MIN;
        while (br - bl > 1)
        {
            ll h = (bl + br) >> 1LL;
            if (down(l[i], h) == down(l[i], MIN))
                br = h;
            else
                bl = h;
        }
        ll first = MIN - br;
        bl = MAX;
        br = INF;
        while (br - bl > 1)
        {
            ll h = (bl + br) >> 1LL;
            if (up(l[i], MAX) == up(l[i], h))
                bl = h;
            else
                br = h;
        }
        ll second = bl - MAX;
        ban.push_back(make_pair(first, second));
    }
    ll add = MAX - MIN;
    if (ban.empty())
    {
        cout << add << "n";
        return;
    }
    sort(ban.begin(), ban.end());
    vector<pair<ll, ll>> a;
    for (int i = 0; i < (int)ban.size(); i++)
    {
        while (!a.empty() && a.back().second <= ban[i].second)
            a.pop_back();
        a.push_back(ban[i]);
    }
    ll ans = INF;
    ans = min(a[0].second + 1, ans);
    ans = min(a.back().first + 1, ans);
    for (int i = 0; i + 1 < (int)a.size(); i++)
        ans = min(ans, a[i].first + a[i + 1].second + 2);
    cout << ans + add << "n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

```
 **author's solution**
```cpp
/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : 'n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("
# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
LL a[SIZE],num[SIZE];
bool done[SIZE],be_added[SIZE];
int n;
LL K;
LL get_upper_bound(int i){
    LL v=a[i]/num[i];
    if(v*num[i]!=a[i])v++;
    return v;
}
LL get_next_upper_bound(int i){
    LL v=a[i]/(num[i]-1);
    if(v*(num[i]-1)!=a[i])v++;
    return v;
}
LL go(){
    if(K==n){
        return a[n-1]-a[0];
    }
    LL ll=1,rr=a[n-1];
    while(ll<rr){
        LL mm=(ll+rr)/2;
        LL need=0;
        REP(i,n){
            if(a[i]>mm)need+=a[i]/mm;
            else need++;
        }
        if(need>=K)ll=mm+1;
        else rr=mm;
    }
    LL low=ll;
    VPLL pp;
    LL need=0;
    REP(i,n){
        if(a[i]>=low){
            num[i]=a[i]/low;
            pp.PB({a[i]/(num[i]+1),i});
        }
        else {
            num[i]=1;
        }
        need+=num[i];
    }
    {
        bool fail=0;
        REP(i,n){
            if(get_upper_bound(i)>=low){
                fail=1;
                break;
            }
        }
        if(!fail) return low-1-min(low-1,a[0]);
    }
    REP(i,n){
        if(a[i]>=low&&a[i]/(num[i]+1)==low-1){
            LL v=a[i]/(low-1);
            LL mi=min(v-num[i],K-need);
            num[i]+=mi;
            need+=mi;
            if(need==K)break;
        }
    }
    priority_queue<PLL,VPLL,greater<PLL>>added;
    priority_queue<PLL>top;
    LL mi=a[0];
    REP(i,n){
        if(num[i]>1){
            added.push(MP(get_next_upper_bound(i),i));
        }
        top.push(MP(get_upper_bound(i),i));
        mi=min(mi,a[i]/num[i]);
    }
    LL an=top.top().F-mi;
    REP(i,n)be_added[i]=done[i]=0;
    LL ma=low-1;
    while(!top.empty()&&!added.empty()){
        int id=top.top().S;
        if(be_added[id])break;
        done[id]=1;
        top.pop();
        num[id]++;
        mi=min(mi,a[id]/num[id]);
        auto tmp=added.top();
        added.pop();
        if(done[tmp.S])break;
        be_added[tmp.S]=1;
        num[tmp.S]--;
        if(num[tmp.S]>1)added.push({get_next_upper_bound(tmp.S),tmp.S});
        ma=max(ma,tmp.F);
        an=min(an,(top.empty()?ma:max(ma,top.top().F))-mi);
    }
    return an;
}
void solve(){
    LL L;
    //R(n,K,L);
    R(L,n,K);
    K+=n+1;
    LL lt=0;
    REP(i,n){
        LL x;
        R(x);
        a[i]=x-lt;
        lt=x;
    }
    a[n++]=L-lt;
    sort(a,a+n);
    W(go());
}
int main(){
    CASET{
        solve();
    }
    return 0;
}
```
