# Tutorial

Thank you for participating! We hope you enjoyed the problems!

[1805A - We Need the Zero](../problems/A._We_Need_the_Zero.md "Codeforces Round 862 (Div. 2)")  
 Idea and preparation: [Alexdat2000](https://codeforces.com/profile/Alexdat2000 "Master Alexdat2000")

  **Hint 1**  Recall the basic properties of the ⊕ operation: A⊕0=A, A⊕A=0, A⊕B=B⊕A.   **Hint 2**  Consider the cases of even and odd array lengths.   **Editorial**  
### [1805A - We Need the Zero](../problems/A._We_Need_the_Zero.md "Codeforces Round 862 (Div. 2)")

Note that $(a_1 \oplus x) \oplus (a_2 \oplus x) \oplus ...$ equals $a_1 \oplus a_2 \oplus \ldots \oplus a_n$ if $n$ is even, or $a_1 \oplus a_2 \oplus \ldots \oplus a_n \oplus x$ if $n$ is odd. Then, if the length of the array is odd, you must print $\oplus$ of the whole array. And if the length is even, we can't change the value of the expression with our operation. It turns out that if $\oplus$ of the whole array is $0$, we can output any number, but otherwise there is no answer.

 **Solution**
```cpp
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    xor = 0
    for x in a:
        xor ^= x
    if xor == 0:
        print(0)
    else:
        if n % 2 == 1:
            print(xor)
        else:
            print(-1)
```
 **Rate the problem*** Didn't solve 


[*58*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*436*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*102*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*36*](https://codeforces.com/data/like?action=like "I like this")
[1805B - The String Has a Target](../problems/B._The_String_Has_a_Target.md "Codeforces Round 862 (Div. 2)")  
 Idea and preparation: [Alexdat2000](https://codeforces.com/profile/Alexdat2000 "Master Alexdat2000") 

 **Hint 1**  What should be the first character if we are trying to make the string lexicographically minimal?   **Hint 2**  Consider the string «baba». If you choose i=2, you get the string «abba», and if you choose i=4 you get «abab». Try to generalize this reasoning to any string.   **Editorial**  
### [1805B - The String Has a Target](../problems/B._The_String_Has_a_Target.md "Codeforces Round 862 (Div. 2)")

At first, note that the operation should be applied only to the position of the minimal element of the string (since the 1st position in the final string should always contain the minimal letter). 

Next, let the positions of the minimum letter are $a_1, a_2, \ldots, a_k$. Then we must apply the operation to the last position ($a_k$). Indeed, let us apply the operation to another occurrence: then the prefixes will coincide, and after that there will be a character that is equal to the minimal one if we applied the operation to $a_k$ and will not be equal to it otherwise, which contradicts the minimal string.

  **Solution**
```cpp
for _ in range(int(input())):
    n = int(input())
    s = input()
    ind = s.rfind(min(s))  
# Find the last ind such that s[ind] = min(s)
    print(s[ind] + s[:ind] + s[ind + 1:])
```
 **Rate the problem*** Didn't solve 

 
[*15*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*273*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*112*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")
[1805C - Place for a Selfie](../problems/C._Place_for_a_Selfie.md "Codeforces Round 862 (Div. 2)")  
 Idea and preparation: [Alexdat2000](https://codeforces.com/profile/Alexdat2000 "Master Alexdat2000")

  **Hint 1**  Note that the distance between the line and the parabola will also be a parabola. Then what is the condition that the line and the parabola have no common points?   **Hint 2**  Recall the discriminant formula from school: If a parabola ax2+bx+c is given, then calculate D=b2−4ac (discriminant). Then, if D>0, the parabola has 2 roots, if D=0, it has one root, if D<0, it has no roots.  **Hint 3**  If we choose the parabola ax2+bx+c, then the lines with such coefficient k that (b−k)2<4ac have no common points with it. How can we find such k among the given lines?   **Editorial**  
### [1805C - Place for a Selfie](../problems/C._Place_for_a_Selfie.md "Codeforces Round 862 (Div. 2)")

Let's find the answers for the parabolas one at a time. Suppose we are given a parabola $ax^2+bx+c$ and a line $kx$. Then their difference is the parabola $ax^2+(b-k)x+c$. In order for the line and the parabola not to intersect, the difference must never equal $0$, that is, the parabola $ax^2+(b-k)x+c$ must have no roots. And this is true only when the discriminant is less than $0$, that is, $(b-k)^2<4ac$. In this case, $a, b$ and $c$ are given to us, and we need to choose $k$. $(b-k)^2<4ac \Longrightarrow |b - k| < \sqrt{4ac} \Longrightarrow b - \sqrt{4ac} < k < b+\sqrt{4ac}$.

Now let us have a list of straight line coefficients sorted in increasing order. We need to check if there is a coefficient that belongs to $[b - \sqrt{4ac}; b + \sqrt{4ac}]$. To do this, check the smallest number greater than $b$, and the largest number less than $b$. If one of these numbers satisfies the condition, then we have found the answer. If not, then there are definitely no suitable coefficients, because we took $2$ closest coefficients to the center of the segment.

Note that in this solution, we don't need to use non-integer numbers, which is good for both the time and the absence of errors due to precision.

  **Solution**
```cpp
#include <bits/stdc++.h>
#define int long long

using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i];
    }
    sort(lines.begin(), lines.end());

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int ind = lower_bound(lines.begin(), lines.end(), b) - lines.begin();
        if (ind < n && (lines[ind] - b) * (lines[ind] - b) < 4 * a * c) {
            cout << "YESn" << lines[ind] << "n";
            continue;
        }
        if (ind > 0 && (lines[ind - 1] - b) * (lines[ind - 1] - b) < 4 * a * c) {
            cout << "YESn" << lines[ind - 1] << "n";
            continue;
        }
        cout << "NOn";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*62*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*497*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*63*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*280*](https://codeforces.com/data/like?action=like "I like this")
[1805D - A Wide, Wide Graph](../problems/D._A_Wide,_Wide_Graph.md "Codeforces Round 862 (Div. 2)")  
 Idea: [FairyWinx](https://codeforces.com/profile/FairyWinx "Grandmaster FairyWinx"), preparation: [Alexdat2000](https://codeforces.com/profile/Alexdat2000 "Master Alexdat2000") 

 **Hint 1**  At what maximal k does the graph Gk not decompose into single components? What happens if we decrease k by 1?   **Hint 2**  Consider some diameter of a tree (the path of the longest length). If in the graph Gk a vertex has a neighbor, then it is also connected by an edge to one of the ends of the diameter. How can we use this fact to find the answer for k if we know the components of graph Gk+1?   **Editorial**  
### [1805D - A Wide, Wide Graph](../problems/D._A_Wide,_Wide_Graph.md "Codeforces Round 862 (Div. 2)")

Find the diameter (the longest path) in the original tree. Now if the number $k$ is greater than the length of the diameter, then there will be no edges in the graph. Otherwise, the ends of this diameter are connected to each other, and possibly to other vertices as well. Then we can pre-calculate the answer for each $k$ in descending order. Let's maintain the set of vertices already reachable. Then for updating the answer for $k=x$ only vertices at a distance $x$ from one end of the diameter can be added to the answer.

  **Solution**
```cpp
#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const int N = 1e5 + 228;

vector<int> G[N];

void dfs(int v, int par, int h, vector<int> &d) {
    d[v] = h;
    for (int i : G[v]) {
        if (i != par) {
            dfs(i, v, h + 1, d);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    vector<int> d1(n), d2(n);
    dfs(0, -1, 0, d1);
    int a = max_element(all(d1)) - d1.begin();
    dfs(a, -1, 0, d1);
    int b = max_element(all(d1)) - d1.begin();
    dfs(b, -1, 0, d2);
    for (int i = 0; i < n; ++i) {
        d2[i] = max(d2[i], d1[i]);
    }
    sort(all(d2));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (ans < n && d2[ans] < i) {
            ++ans;
        }
        cout << min(n, ans + 1) << ' ';
    }
    cout << 'n';
}
```
 **Rate the problem*** Didn't solve 

 
[*112*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*575*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*25*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*35*](https://codeforces.com/data/like?action=like "I like this")
[1805E - There Should Be a Lot of Maximums](../problems/E._There_Should_Be_a_Lot_of_Maximums.md "Codeforces Round 862 (Div. 2)")  
 Idea and preparation: [Alexdat2000](https://codeforces.com/profile/Alexdat2000 "Master Alexdat2000")

  **Hint 1**  Let M — MAD of the whole tree. What is the answer if there are many vertices with value M in the tree?   **Hint 2**  Note that for many edges the answer is M. And for which edges is it not so?   **Hint 3**  Let the tree have only two vertices with value M. Then for the edges not on the path between them we know the answer. What about the path between two vertices of M? Can we walk along it by calculating the answer for all vertices?   **Editorial**  
### [1805E - There Should Be a Lot of Maximums](../problems/E._There_Should_Be_a_Lot_of_Maximums.md "Codeforces Round 862 (Div. 2)")

First, find $MAD$ of the initial tree. If each number in the tree occurs no more than once, then for each query the answer is $0$. Then, if $MAD$ occurs at least $3$ times in the tree, then for each query the answer will be $MAD$, because by pigeonhole principle there will be at least $2$ $MAD$ in one of the two trees.

At last, in the case where $MAD$ occurs exactly $2$ times in the tree: if the deleted edge is not on the path between two occurrences of $MAD$, then the answer — $MAD$ of the whole tree. And for edges between entries, you need to maintain sets of values in each tree and traverse the edges, changing the sets accordingly.

  **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 100;
vector <pair <int, int>> g[N];
int val[N];

vector <int> ans;
map <int, int> cnt1, cnt2;
set <int> mad1, mad2;

vector <int> path, path_ind;
bool used[N];


bool dfs(int v, int tar) {
    used[v] = true;
    path.push_back(v);
    if (v == tar) {
        return true;
    }
    for (auto [i, ind] : g[v]) {
        if (!used[i]) {
            path_ind.push_back(ind);
            if (dfs(i, tar)) {
                return true;
            }
            path_ind.pop_back();
        }
    }
    path.pop_back();
    return false;
}


int mad() {
    int mx = 0;
    if (!mad1.empty()) {
        mx = max(mx, *mad1.rbegin());
    }
    if (!mad2.empty()) {
        mx = max(mx, *mad2.rbegin());
    }
    return mx;
}


void recalc(int v, int ban1, int ban2) {
    cnt1[val[v]]++;
    if (cnt1[val[v]] == 2) {
        mad1.insert(val[v]);
    }
    cnt2[val[v]]--;
    if (cnt2[val[v]] == 1) {
        mad2.erase(val[v]);
    }
    for (auto [i, _] : g[v]) {
        if (i != ban1 && i != ban2) {
            recalc(i, v, -1);
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }

    map <int, vector <int>> ind;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        ind[val[i]].push_back(i);
        cnt2[val[i]]++;
        if (cnt2[val[i]] == 2) {
            mad2.insert(val[i]);
        }
    }

    while (!ind.empty() && ind.rbegin() -> second.size() == 1) {
        ind.erase(prev(ind.end()));
    }
    if (ind.empty()) {
        for (int i = 0; i < n - 1; i++) {
            cout << "0n";
        }
        return 0;
    } else if (ind.rbegin()->second.size() > 2) {
        for (int i = 0; i < n - 1; i++) {
            cout << ind.rbegin() -> first << "n";
        }
        return 0;
    }

    int a = ind.rbegin()->second[0], b = ind.rbegin()->second[1];
    dfs(a, b);

    ans.assign(n - 1, ind.rbegin() -> first);
    recalc(path[0], path[1], -1);
    ans[path_ind[0]] = mad();

    for (int i = 1; i + 1 < path.size(); i++) {
        recalc(path[i], path[i - 1], path[i + 1]);
        ans[path_ind[i]] = mad();
    }

    for (int i : ans) {
        cout << i << "n";
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*60*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*212*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*25*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*16*](https://codeforces.com/data/like?action=like "I like this")
[1805F2 - Survival of the Weakest (hard version)](../problems/F2._Survival_of_the_Weakest_(hard_version).md "Codeforces Round 862 (Div. 2)")  
 Idea and preparation: [sevlll777](https://codeforces.com/profile/sevlll777 "Grandmaster sevlll777")

Hints for the simple version: 

 **Hint 1**  Figure out how to implement the function F in O(nlogn)   **Hint 1.1**  You'll need std::priority_queue or std::set   **Hint 2**  If you run F for O(nlogn) n−1 times, we'll get the solution in O(n2logn). However, the numbers in the array can grow very fast. Can you somehow modify the numbers in the array so that F changes in a predictable way?  **Hint 2.2**  F([a1,a2,…,an])=F([a1−x,a2−x,…,an−x])+x⋅2n−1 Hints for the hard version: 

 **Hint 3**  How to solve the problem if ai≤1? ≤2? Can you notice anything about these solutions?   **Hint 4**  If n is large enough, then F(F(…F([a1,a2,…,an])…))=F(F(…F([a1,a2,…,an−1,X])…)) where X any number ≥an−1, in other words: the largest element is useless for the final answer   **Hint 5**  Only a small number of the smallest elements of the original array will affect the answer   **Editorial**  
### [1805F2 - Survival of the Weakest (hard version)](../problems/F2._Survival_of_the_Weakest_(hard_version).md "Codeforces Round 862 (Div. 2)")

Firstly, we will sort the array $a_1, a_2, \ldots, a_n$, and in the future we will always assume that all arrays in this problem are sorted.

Let's solve the problem for $n \leq 200$.

It may seem that with such constraints, the problem is solved quite trivially: we implement the function $F$ for $\mathcal{O}(n^2 \log n)$, and run it $n - 1$ times to get an answer. But there is one nuance, with each iteration of $F$, the numbers in the array can increase by $2$ times (for example, if the array consists entirely of identical numbers), which means that after only $40$ operations, we may have an overflow. Note that it is impossible to take the numbers by modulo in the function $F$ itself, since then the sorted order will be lost, and it will be impossible (or very difficult) to restore it using the remainder when dividing by $10^9 + 7$ instead of the numbers themselves.

To avoid this, we note an important property of the function $F$:

$F([a_1, a_2, \ldots, a_n]) = F([a_1 - x, a_2 - x, \ldots, a_n - x]) + x \cdot 2^{n-1}$

The intuition of this property is that if you subtract the same number from all the elements, then the relative order of the elements will not change, and will not change when using the $F$ function. Just after the first iteration of $F$, $2x$ will be subtracted from all the numbers, then $4x$, $8x$, etc., in the end, the original answer will be minus $x\cdot 2^{n-1}$. This property can be proved more strictly by induction on $n$.

What does this wonderful property give us? Now we can subtract the same number $x$ from all the elements by first adding $x \cdot 2^{n-1}$ to the answer. It would be logical enough in any situation to subtract the minimum of the array from all its elements. Thanks to this, the minimum of the array will always be $0$, and now we can work only with arrays whose minimum element is $0$, which greatly simplifies our life. This is one of the two key ideas in this problem.

So let's notice something interesting about the array $F([0, a_1, a_2, \ldots, a_n])$.

Observation: $(F([0, a_1, a_2, \ldots, a_n]))_1 = a_1$. The proof is obvious (let me remind you that the array is sorted).

Observation: $(F([0, a_1, a_2, \ldots, a_n]))_n \leq a_n$.

Proof: since $[0, a_1, a_2, \ldots, a_n]$ has length $n + 1$, $F([0, a_1, a_2, \ldots, a_n])$ has length $n$. Among all pairs of array elements $[0, a_1, a_2, \ldots, a_n]$ there are $n$ pairs of the form $0 + a_i$, and $a_1 \leq a_2 \leq \ldots \leq a_n$. This means that the original array has $n$ pairs in which the sum is $\leq a_n$. So, observation is proved.

These two observations give us that $F([0, a_1, a_2, \ldots, a_n]) = [a_1, \ldots, \leq a_n]$. And after subtracting the minimum $(a_1)$ $\rightarrow [0, \ldots, \leq a_n - a_1]$.

Thus, if we always subtract the minimum, each time after applying the $F$ function, the maximum in the array will be not increase. Which allows us to work only with arrays of numbers from $0$ to $10^9$, where there naturally can be no problems with overflow.

So, we got the solution for $\mathcal{O}(n^3 \log n)$. Let's improve it to $\mathcal{O}(n^2 \log n)$.

The cornerstone in our previous solution is that we implement the function $F$ for $\mathcal{O}(n^2 \log n)$, which is pretty slow. Let's learn how to implement it for $\mathcal{O}(n \log n)$. This is a fairly standard problem.

Note that if some pair of the form $a_i + a_j$ is included in the array $F([a_1, a_2, \ldots, a_n])$, then all pairs $a_i + a_{i+1}, a_i + a_{i+2}, \ldots, a_i + a_{j-1}$ will also be included in the array $F([a_1, a_2, \ldots, a_n])$, since the sum in these pairs is no more than $a_i + a_j$.

We will build the array $F([a_1, a_2, \ldots, a_n])$ one element at a time, starting with the smallest. Let's denote the array in which we will add these numbers for $B$, initially $B$ is empty. For each index $i$, we will store the minimum index $j_i > i$ such that the pair $a_i + a_j$ is still not taken in $B$. Initially, $j_i = i+1$.

We will mantain all numbers of the form $a_i + a_{j_i}$ in std::priority_queue. Then to add the next element to $B$, we will remove the minimum element from the queue, then increase the corresponding $j_i$ by one and add the element $a_i + a_{j_i}$ to the queue again. After $n - 1$ of such iteration we will get $F([a_1, a_2, \ldots, a_n])$. Each iteration takes $\mathcal{O}(\log n)$, which means that the asymptotics of finding the function $F$ is $\mathcal{O}(n \log n)$.

In total, we learned how to solve the problem in $\mathcal{O}(n^2 \log n)$.

Now we move on to the full solution, for $n \leq 2 \cdot 10^5$.

First we will show what the solution looks like and intuition behind it, and a more strict proof will be at the end.

Let's ask ourselves: when does the last element of the array $0, a_1, a_2, \ldots, a_n$ affect the answer to the problem?

Very often we will lose any mention of the $a_n$ element after the first transition: $[0, a_1, \ldots, a_n] \rightarrow F([0, a_1, \ldots, a_n])$.

The minimum sum of a pair of elements including $a_n$ is $0 + a_n$. And there is an $n - 1$ pair with not bigger sum: $0 + a_1$, $0 + a_2$, ..., $0 + a_{n-1}$.

So the only case when $a_n$ will enter the array $F([0, a_1, \ldots, a_n])$ is if $a_1 + a_2 \geq a_n$, because otherwise the pair $a_1 + a_2$ will be less than $0 + a_n$, and there will be $n$ pairs with a sum less than $a_n$ — $n-1$ pairs of the form $0 + a_i$ and the pair $a_1 + a_2$.

Well, let's assume it really happened that $a_1 + a_2 \geq a_n$. Then $F([0, a_1, \ldots, a_n]) = [0 + a_1, 0 + a_2, \ldots, 0 + a_n]$.

After subtracting the minimum: $[0, a_2 - a_1, a_3 - a_1, \ldots, a_n - a_1]$.

If we run $F$ on this array again, we get: $[a_2 - a_1, \ldots, \le a_n - a_1]$. After subtracting the minimum: $[0, \ldots, \le a_n - a_2]$.

But remember that $a_1 + a_2 \geq a_n$. Which means $2 \cdot a_2 \geq a_n$. Which means $a_n - a_2 \leq \frac{a_n}{2}$.

It turns out that if $a_n$ somehow remains in the array after two applications of the $F$ functions, then the last element of the array will be reduced by at least half!

This means that after just $2 \cdot \log_2{a_n}$ iterations of the $F$ function, either the $a_n$ element will be completely evicted from the array, or the array will shrink into $[0, 0, \ldots, 0]$! In both cases, the original element $a_n$ in no way will be taken into account in the final answer. In no way!

The total number of times when the maximum is halved is no more than $\log_2{a_n}$, which means intuitively it is approximately clear that elements with indexes greater than $2 \cdot \log_2{a_n}$ will not affect the answer in any way.

Therefore, the full solution would be to leave the first $K = 64$ elements of the array $a$. (a little more than $2 \cdot \log_2{10^9}$).

Then apply the function $F$ to this array $n - K$ times, but writing out $K$ minimal elements, not $K - 1$.

After that, the length of the real array will also be equal to $K$, and it remains only to run the function $F$ $K - 1$ times to get the final answer.

Final asymptotics: $\mathcal{O}(n \cdot (K \log K))$, where $K = 2 \log_2{a_n} + 2 \leq 64$.

Now let's give a strict proof that this solution works.

We are following $K$ minimal elements —$[0, a_1, \ldots, a_{K-1}]$.

Technically, there are also $[a_K, \ldots, a_{len}]$ elements in the array. But we have no information about their values. However, we know that all these elements are $\geq a_{K-1}$ since we maintain sorted order. This means that the minimum sum of a pair of elements about which we have no information is also $\geq a_{K-1}$. The whole proof is based on this simple observation.

Firstly, it is not difficult to understand that $K$ minimum elements are exactly enough to recalculate $K - 1$ minimum element in $F(a)$. Since we have pairs of elements $0 + a_1$, $0 + a_2$, ..., $0 + a_{K-1}$. And the sum in each of these pairs is no more than $a_{K-1}$, which means no more than the sum in any pair about which we have no information.

Therefore, in any incomprehensible situation, we can recalculate with the loss of one of the elements. Let's see when it is possible to recalculate all $K$ minimal elements.

Again, the minimum element about which we have no information from $[0, a_1, \ldots, a_{K-1}]$ is $0 + a_K \geq 0 + a_{K-1}$. So if we find $K$ elements that $\leq a_{K-1}$, then we can recalculate $K$ minimal elements of $F(a)$ through $K$ minimal elements of $a$. We have a $K - 1$ pair of the form $0 + a_i$, as well as a pair $a_1 + a_2$. So if $a_1 + a_2 < a_{K-1}$, then we can recalculate all $K$ minimal elements.

And if recalculation is not possible, then $a_1 + a_2 \geq a_{K-1}$ is executed. Then, having encountered such a situation, we will recalculate twice with the loss of the last element, thus reducing $K$ by $2$. After such a recalculation, the last element will be at least half as small as it was before (this is part of the main tutorial). So after $2 \log_2(A)$ of such element removals, the array will slide into $[0, 0, \ldots, 0]$ and everything is clear. And if the number of removals is less than $2 \log_2(A)$, then one of the $K$ elements will certainly live to the end, and will be the answer to the problem. Thus, the correctness of the solution has been successfully proved.

Bonus for those who are still alive: find a more accurate estimate for $K$ and build a test on which this solution, but keeping track of the $K - 1$ minimum element (one less than necessary), will give the wrong answer.

  **Solution**
```cpp
#include <bits/stdc++.h>
#define all(x) x.begin(), (x).end()

using namespace std;

const int M = 1000000007;
long long ans = 0;
int real_len = 0;


long long binpow(long long a, int x) {
    long long ans0 = 1;
    while (x) {
        if (x % 2) {
            ans0 *= a;
            ans0 %= M;
        }
        a *= a;
        a %= M;
        x /= 2;
    }
    return ans0;
}


void chill(vector<int> &b) {
    int mn = b[0];
    ans += (int) ((long long) mn * binpow(2, real_len - 1) % M);
    if (ans >= M) {
        ans -= M;
    }
    for (auto &x : b) {
        x -= mn;
    }
}


void F(vector<int> &b, int sub = 0) {
    --real_len;
    vector<int> cnd;
    for (int i = 0; i < b.size(); i++) {
        for (int j = i + 1; j < b.size(); j++) {
            if (i * j >= b.size()) break;
            cnd.push_back(b[i] + b[j]);
        }
    }
    sort(all(cnd));
    vector<int> b2((int) b.size() - sub);
    for (int i = 0; i < (int) b.size() - sub; i++) {
        b2[i] = cnd[i];
    }
    chill(b2);
    b = b2;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int L = 64;
    vector<int> b(min(n, L));
    for (int i = 0; i < min(n, L); i++) {
        b[i] = a[i];
    }
    real_len = n;
    chill(b);
    while (b.size() < real_len) {
        if (b[1] + b[2] > b.back()) {
            F(b, 1);
            F(b, 1);
        } else {
            F(b);
        }
    }
    while (real_len > 1) {
        F(b, 1);
    }
    ans += b[0];
    ans %= M;
    cout << ans << 'n';
}
```
 **Rate the problem*** Didn't solve 

 
[*95*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*94*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*3*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*3*](https://codeforces.com/data/like?action=like "I like this")
