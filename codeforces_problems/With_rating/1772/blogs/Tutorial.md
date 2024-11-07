# Tutorial

[1772A - A+B?](../problems/A._A+B_.md "Codeforces Round 839 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1772A - A+B?](../problems/A._A+B_.md "Codeforces Round 839 (Div. 3)")

There are multiple ways to solve this problem.

Most interpreted languages have some function that takes the string, evaluates it as code, and then returns the result. One of the examples is the eval function in Python. If the language you use supports something like that, you can read the input as a string and use it as the argument of such a function.

Suppose you use a language where this is impossible. There are still many approaches to this problem. The most straightforward one is to take the first and the last characters of the input string, calculate their ASCII codes, and then subtract the ASCII code of the character 0 from them to get these digits as integers, not as characters. Then you can just add them up and print the result.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    print(eval(input()))
```
[1772B - Matrix Rotation](../problems/B._Matrix_Rotation.md "Codeforces Round 839 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1772B - Matrix Rotation](../problems/B._Matrix_Rotation.md "Codeforces Round 839 (Div. 3)")

Sure, you can just implement the rotation operation and check all $4$ possible ways to rotate the matrix, but it's kinda boring. The model solution does the different thing.

If a matrix is beautiful, then its minimum is in the upper left corner, and its maximum is in the lower right corner (and vice versa). If you rotate it, the element from the upper left corner goes to the upper right corner, and the element from the lower right corner goes to the lower left corner — so these elements are still in the opposite corners. No matter how many times we rotate a beautiful matrix, its minimum and maximum elements will be in the opposite corners — and the opposite is true as well; if you have a $2 \times 2$ matrix with minimum and maximum elements in opposite corners, it can be rotated in such a way that it becomes beautiful.

So, all we need to check is that the minimum and the maximum elements are in the opposite corners. There are many ways to do it; in my opinion, the most elegant one is to read all four elements in an array of size $4$; then the opposite corners of the matrix correspond either to positions $0$ and $3$, or to positions $1$ and $2$ in this array. So, we check that the sum of positions of minimum and maximum is exactly $3$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++)
    {
        vector<int> a(4);
        for(int i = 0; i < 4; i++)
            cin >> a[i];
        int maxpos = max_element(a.begin(), a.end()) - a.begin();
        int minpos = min_element(a.begin(), a.end()) - a.begin();
        if(maxpos + minpos == 3)
            puts("YES");
        else
            puts("NO");
    }
}
```
[1772C - Different Differences](../problems/C._Different_Differences.md "Codeforces Round 839 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1772C - Different Differences](../problems/C._Different_Differences.md "Codeforces Round 839 (Div. 3)")

We can transform the problem as follows. Let $d_i = a_{i+1} - a_i$. We need to find an array $[d_1, d_2, \dots, d_{k-1}]$ so that the sum of elements in it is not greater than $n-1$, all elements are positive integers, and the number of different elements is the maximum possible.

Suppose we need $f$ different elements in $d$. What can be the minimum possible sum of elements in $d$? It's easy to see that $d$ should have the following form: $[2, 3, 4, \dots, f, 1, 1, 1, \dots, 1]$. This array contains exactly $f$ different elements, these different elements are as small as possible (so their sum is as small as possible), and all duplicates are $1$'s. So, if the sum of this array is not greater than $n-1$, then it is possible to have the number of different elements in $d$ equal to $f$.

The rest is simple. We can iterate on $f$, find the maximum possible $f$, construct the difference array, and then use it to construct the array $a$ itself.

 **Solution (BledDest)**
```cpp
def construct(f, k):
    return [(i + 2 if i < f - 1 else 1) for i in range(k)]

t = int(input())
for i in range(t):
    k, n = map(int, input().split())
    ans = 1
    for f in range(1, k):
        d = construct(f, k - 1)
        if sum(d) <= n - 1:
            ans = f
    res = [1]
    d = construct(ans, k - 1)
    for x in d:
        res.append(res[-1] + x)
    print(*res)
```
[1772D - Absolute Sorting](../problems/D._Absolute_Sorting.md "Codeforces Round 839 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1772D - Absolute Sorting](../problems/D._Absolute_Sorting.md "Codeforces Round 839 (Div. 3)")

What does it actually mean for an array $a_1, a_2, \dots, a_n$ to be sorted? That means $a_1 \le a_2$ and $a_2 \le a_3$ and so on.

For each pair of adajacent elements, let's deduce which values $x$ put them in the correct order. Any value of $x$ that puts all pairs in the correct order will be the answer.

Consider any $a_i$ and $a_{i+1}$ and solve the inequality $|a_i - x| \le |a_{i+1} - x|$. If $a_i = a_{i+1}$, then any value of $x$ works. Let $a_i$ be smaller than $a_{i+1}$.

If $x$ is smaller than or equal to $a_i$, then the inequality becomes $a_i - x \le a_{i+1} - x \Leftrightarrow a_i \le a_{i+1}$. Thus, they don't change their order, and any $x \le a_i$ works.

If $x$ is greater than or equal to $a_{i+1}$, then the inequality becomes $x - a_i \le x - a_{i+1} \Leftrightarrow a_i \ge a_{i+1}$. Thus, they always change their order, and none of $x \ge a_i$ work.

If $x$ is between $a_i$ and $a_{i+1}$, then the inequality becomes $x - a_i \le a_{i+1} - x \Leftrightarrow 2x \le a_i + a_{i+1} \Leftrightarrow x \le \frac{a_i + a_{i+1}}{2}$. Thus, they only remain in the same order for any integer $x$ such that $a_i \le x \le \lfloor \frac{a_i + a_{i+1}}{2} \rfloor$.

In union, that tells us that all values of $x$ that work for such a pair are $x \le \lfloor \frac{a_i + a_{i+1}}{2} \rfloor$.

The similar analysis can be applied to $a_i > a_{i+1}$, which results in the required $x$ being $x \ge \lceil \frac{a_i + a_{i+1}}{2} \rceil$ for such pairs.

Finally, how to find out if some value of $x$ passes all conditions? Among all conditions of form $x \le \mathit{val_i}$, in order for some $x$ to work, it should be less than or equal to even the smallest of them. Similarly, among all conditions of form $x \ge \mathit{val_i}$, in order for some $x$ to work, it should be greater than or equal to even the largest of them.

Thus, take the minimum over the pairs of one type. Take the maximum over the pairs of another type. If two resulting values are contradictory, then there is no answer. Otherwise, any value inside the resulting range of $x$ works.

Overall complexity: $O(n)$ per testcase.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; j++)
            cin >> a[j];
        int mn = 0, mx = int(1e9);
        for(int j = 0; j + 1 < n; j++)
        {
            int x = a[j];
            int y = a[j + 1];
            int midL = (x + y) / 2;
            int midR = (x + y + 1) / 2;
            if(x < y)
                mx = min(mx, midL);
            if(x > y)
                mn = max(mn, midR);
        }
        if(mn <= mx) cout << mn << endl;
        else cout << -1 << endl;
    }
}
```
[1772E - Permutation Game](../problems/E._Permutation_Game.md "Codeforces Round 839 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1772E - Permutation Game](../problems/E._Permutation_Game.md "Codeforces Round 839 (Div. 3)")

Note that it makes no sense to use the first type of operation if it does not lead to an instant win, because the opponent can return the previous state of the array with their next move.

So the winner is the one who has time to color "their" elements in blue first. Let's denote $a$ as the number of elements that only the first player needs to color, $b$ as the number of elements only the second player needs to color, $c$ — both players needs to color.

To win, the first player needs to have time to paint $a+c$ elements, and they have no more than $b$ moves to do it, because otherwise the second player can prevent the win of the first player. So the winning condition for the first player is $a+c \le b$. Similarly, for the second player, with the only difference that they have $1$ move less (because they go second), which means the condition is $b+c < a$. If none of these conditions are met, then neither player has a winning strategy, which means they will both reduce the game to a draw.

 **Solution (Neon)**
```cpp
for tc in range(int(input())):
  n = int(input())
  p = list(map(int, input().split()))
  a, b, c = 0, 0, 0
  for i in range(n):
    if p[i] != i + 1 and p[i] != n - i:
      c += 1
    elif p[i] != i + 1:
      a += 1
    elif p[i] != n - i:
      b += 1
  if a + c <= b:
    print("First")
  elif b + c < a:
    print("Second")
  else:
    print("Tie")
```
[1772F - Copy of a Copy of a Copy](../problems/F._Copy_of_a_Copy_of_a_Copy.md "Codeforces Round 839 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1772F - Copy of a Copy of a Copy](../problems/F._Copy_of_a_Copy_of_a_Copy.md "Codeforces Round 839 (Div. 3)")

Notice the following: once you apply the recolor operation to some cell, you can never recolor it again. That happens because you can't recolor its neighbors too as each of them has at least one neighbor of the same color — this cell itself.

In particular, that implies that applying a recolor operation always decreases the possible number of operations that can be made currently. It doesn't always decrease them by $1$: from $1$ to $5$ operations can become unavailable, but it always decreases.

That gives us an order of copies. Just sort them in the decreasing order of the number of recolor operations that can be made currently. If the numbers are the same, the copies must be equal, so their order doesn't matter.

The only thing remains is to apply the operations. Turns out, their order doesn't matter at all. Consider all different cells for a pair of adjacent pictures. It's never possible that there are two different cells that are adjacent to each other. Thus, no operation can interfere with another one. Just print all positions of different cells in any order you want and make a copy.

Overall complexity: $O(nmk + k \log k)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++)

struct op{
    int t, x, y, i;
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<string>> a(k + 1, vector<string>(n));
    forn(z, k + 1) forn(i, n)
        cin >> a[z][i];
    
    vector<int> cnt(k + 1);
    forn(z, k + 1){
        for (int i = 1; i < n - 1; ++i){
            for (int j = 1; j < m - 1; ++j){
                bool ok = true;
                forn(t, 4)
                    ok &= a[z][i][j] != a[z][i + dx[t]][j + dy[t]];
                cnt[z] += ok;
            }
        }
    }
    
    vector<int> ord(k + 1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&cnt](int x, int y){
        return cnt[x] > cnt[y];
    });
    
    vector<op> ops;
    forn(z, k){
        forn(i, n) forn(j, m) if (a[ord[z]][i][j] != a[ord[z + 1]][i][j]){
            a[ord[z]][i][j] ^= '0' ^ '1';
            ops.push_back({1, i + 1, j + 1, -1});
        }
        ops.push_back({2, -1, -1, ord[z + 1] + 1});
    }
    
    cout << ord[0] + 1 << 'n';
    cout << ops.size() << 'n';
    for (auto it : ops){
        cout << it.t << " ";
        if (it.t == 1)
            cout << it.x << " " << it.y << 'n';
        else
            cout << it.i << 'n';
    }
}
```
[1772G - Gaining Rating](../problems/G._Gaining_Rating.md "Codeforces Round 839 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1772G - Gaining Rating](../problems/G._Gaining_Rating.md "Codeforces Round 839 (Div. 3)")

After parsing the statement, you can understand that Monocarp plays cyclically: in one cycle, he chooses some order of opponents and play with them in that order. Then repeats again and again, until he gains desired rating at some moment.

So, firstly, let's prove that (in one cycle) it's optimal to play against opponents in increasing order of their skills. Suppose you play with opponents in some order $ord$ and there is a position where $a[ord_i] > a[ord_{i+1}]$, if you swap $ord_i$ and $ord_{i+1}$ you won't lose anything and may even gain extra wins. It means that the total gain after playing one cycle in increasing order in greater or equal than playing in any other order.

In other words, we can sort array $a$ and play against them cyclically in that order. Monocarp's list of games will look like several full cycles and some prefix. The problem is that there can be many cycles, and we need to skip them in a fast way.

How one cycle looks? Monocarp starts with some $x$ wins first $p$ games and then loses all other games ($m$ games where $m = n - p$). The maximum rating he gains is $x + p$ and the resulting rating after all games is $x + p - m$.

We can already find several conditions of leaving a cycle: if $x + p \ge y$ then Monocarp gets what he wants and stops; otherwise, if $x + p - m \le x$ (or $p - m \le 0$) he will never gain the desired rating, since in the next cycle the number of wins $p' \le p$, since his starting rating $x + p - m \le x$.

Otherwise, if $x + p < y$ and $p - m > 0$, he will start one more cycle with rating $x' = x + p - m$ and will gain the desired rating $y$, eventually. So, how to find the number of games $p$ he will win for a starting rating $x$?

Let's calculate two values for a given sorted skill array $a$: for each $i$ let's calculate $t_i$ — the minimum starting rating Monocarp need to win opponent $i$ (and all opponent before) and $b_i$ — the rating he'll get after winning the $i$-th opponent.

We can calculate these values in one iteration (we'll use $0$-indexation): $t_0 = a_0$, $b_0 = a_0 + 1$; then for each $i > 0$ if $b_{i - 1} \ge a_i$ then $t_i = t_{i - 1}$ and $b_i = b_{i - 1} + 1$, otherwise $t_i = a_i - i$ and $b_i = a_i + 1$.

Now, knowing values $t_i$ it's easy to find the number of wins $p$ for a starting rating $x$: $p$ is equal to minimum $j$ such that $t_j > x$ (don't forget, $0$-indexation). Or the first position in array $t$ with value strictly greater than $x$. We can search it with standard $\text{upper_bound}$ function, since array $t$ is sorted.

Okay, we found the number of wins $p$ for the current $x$. Let's just calculate how many cycles $k$ Monocarp will make with exactly $p$ wins. There are only two conditions that should be met in order to break this cycle: either Monocarp reaches rating $y$ — it can be written as inequality $x + k (p - m) + p \ge y$, or the number of wins increases (starting rating becomes greater or equal than $t_p$), i.e. $x + k (p - m) \ge t_p$.

From the first inequality, we get minimum $k_1 = \left\lceil \frac{y - x - p}{p - m} \right\rceil$ and from the second one — $k_2 = \left\lceil \frac{t_p - x}{p - m} \right\rceil$. As a result, we can claim that Monocarp will repeat the current cycle exactly $k = \min(k_1, k_2)$ times and either finish in the next turn or the number of wins will change.

So, we can skip these $k$ equal cycles: we can increase answer by $kn$ and current rating by $k(p - m)$. Since we skip equal cycles, then at each step we either finish (with success or $-1$), or the number of wins $p$ increases. Since $p$ is bounded by $n$, we will make no more than $n$ skips, and total complexity is $O(n \log n)$ because of initial sorting and calls of $\text{upper_bound}$. 

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

typedef long long li;

int n;
li x, y;
vector<li> a;

inline bool read() {
    if(!(cin >> n >> x >> y))
        return false;
    a.resize(n);
    fore (i, 0, n)
        cin >> a[i];
    return true;
}

li ceil(li a, li b) {
    assert(a >= 0 && b >= 0);
    return (a + b - 1) / b;
}

inline void solve() {
    sort(a.begin(), a.end());
    
    vector<li> t(n), b(n);
    fore (i, 0, n) {
        if (i > 0 && b[i - 1] >= a[i]) {
            t[i] = t[i - 1];
            b[i] = b[i - 1] + 1;
        } else {
            t[i] = a[i] - i;
            b[i] = a[i] + 1;
        }
    }
    
    li ans = 0;
    while (x < y) {
        int pos = int(upper_bound(t.begin(), t.end(), x) - t.begin());
        
        li p = pos, m = n - pos;
        if (x + p >= y) {
            cout << ans + (y - x) << endl;
            return;
        }
        if (p <= m) {
            cout << -1 << endl;
            return;
        }
        
        //1. x + k(p - m) + p >= y
        li k = ceil(y - x - p, p - m);
        if (pos < n) {
            //2. x + k(p - m) >= t[pos]
            k = min(k, ceil(t[pos] - x, p - m));
        }
        ans += k * n;
        //x + k(p - m) < y, since 1. and p >= p - m
        x += k * (p - m);
    }
    assert(false);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    int t; cin >> t;
    while (t--) {
        read();
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
```
