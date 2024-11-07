# Tutorial

Thanks for the participation!

[1379A - Acacius and String](../problems/A._Acacius_and_String.md "Codeforces Round 657 (Div. 2)") was authored by [ch_egor](https://codeforces.com/profile/ch_egor "International Grandmaster ch_egor"), [meshanya](https://codeforces.com/profile/meshanya "Grandmaster meshanya") and prepared by [ch_egor](https://codeforces.com/profile/ch_egor "International Grandmaster ch_egor"), [vintage_Vlad_Makeev](https://codeforces.com/profile/vintage_Vlad_Makeev "International Grandmaster vintage_Vlad_Makeev")

[1379B - Dubious Cyrpto](../problems/B._Dubious_Cyrpto.md "Codeforces Round 657 (Div. 2)") was authored by jury and prepared by [DebNatkh](https://codeforces.com/profile/DebNatkh "Candidate Master DebNatkh")

[1379C - Choosing flowers](../problems/C._Choosing_flowers.md "Codeforces Round 657 (Div. 2)") was authored and prepared by [grphil](https://codeforces.com/profile/grphil "Master grphil")

[1379D - New Passenger Trams](../problems/D._New_Passenger_Trams.md "Codeforces Round 657 (Div. 2)") was authored by Helen Andreeva and prepared by [KiKoS](https://codeforces.com/profile/KiKoS "Master KiKoS")

[1379E - Inverse Genealogy](../problems/E._Inverse_Genealogy.md "Codeforces Round 657 (Div. 2)") was authored and prepared by [voidmax](https://codeforces.com/profile/voidmax "International Grandmaster voidmax") and [I_love_myself](https://codeforces.com/profile/I_love_myself "Master I_love_myself")

[1379F2 - Chess Strikes Back (hard version)](../problems/F2._Chess_Strikes_Back_(hard_version).md "Codeforces Round 657 (Div. 2)") was authored by [300iq](https://codeforces.com/profile/300iq "Legendary Grandmaster 300iq") and prepared by [isaf27](https://codeforces.com/profile/isaf27 "Grandmaster isaf27")

 
### [1379A - Акакий и строка](../problems/A._Acacius_and_String.md "Codeforces Round 657 (Div. 2)")

At first, we will check if some string of length $n$ contains exactly one occurrence of "abacaba".

Lemma 1. This check can be done in $O(n)$ time.

Proof. We can try all the possible positions $i$ of a string $s$ and check whether $i$ is a starting position for a substring "abacaba". This check can be performed in a $O(1)$ time by checking if $s_{i + j} = t_j$ for all $j \in [0; 6]$ where string $t$ is "abacaba". So, overall complexity of such a check works in $n \cdot O(1) = O(n)$ time.

To solve the problem we will iterate over all positions $i$ and check whether there exists a valid string such that its single occurrence of a substring "abacaba" starts from position $i$. String $s$ has a single occurrence $i$ of a substring "abacaba" if and only if two following criteria are satisfied.

* $i$ is a occurrence of a substring "abacaba" in $s$.
* There are no occurrence $j$ of a substring "abacaba" in $s$ such that $i \neq j$.

First criterion can be checked directly. $i$ can be an occurrence of a substring "abacaba" in a resulting string if and only if for all $j \in [0; 6]$ $s_{i + j} = t_j$ or $s_{i + j} = '?'$.

To check the second criterion we need the following lemma.

Lemma 2. Question marks in string $s$ can be replaced with lowercase English letters in such a way that no new occurrences of "abacaba" will appear.

Proof. Let's replace all the questing marks with "z" letter. Any substring of $s$ that contained question mark will not become a occurrence of "abacaba" since "abacaba" does not contain "z".

So after fixing position of a single occurrence $i$ resulting string can be constructed directly.

This leads to a $O(n^2)$ solution. Refer to author's solution code for more details.

 **vintage_Vlad_Makeev code**
```cpp
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

const string T = "abacaba";

int count(const string& s) {
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s.substr(i, T.size()) == T) {
            ++cnt;
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool F = false;

        for (int i = 0; i + T.size() <= n; ++i) {
            string ss = s;
            bool ok = true;
            for (int j = 0; j < T.size(); j++) {
                if (ss[i + j] != '?' && ss[i + j] != T[j]) {
                    ok = false;
                    break;
                }
                ss[i + j] = T[j];
            }
            if (ok && count(ss) == 1) {
                for (int j = 0; j < n; j++) {
                    if (ss[j] == '?') {
                        ss[j] = 'd';
                    }
                }
                F = true;
                cout << "Yesn";
                cout << ss << "n";
                break;
            }
        }
        if (!F) {
            cout << "Non";
        }
    }

    return 0;
}
```
 
### [1379B - Dubious Cyrpto](../problems/B._Dubious_Cyrpto.md "Codeforces Round 657 (Div. 2)")

The task is to solve equation $n\cdot a + b - c = m$ in integers, where $n$ — is some natural number, and $a, b, c \in [l; r]$. Note that the expression $b - c$ can take any value from $[l-r; r-l]$ and only these values. Indeed, if $0 \leq x \leq r-l$, then if we denote $ b = x + l$, $c = l$, we get $b - c = x$. A similar statement is true for $l - r \leq x \leq 0$.

So, since it was necessary to solve the equation $n\cdot a + b - c = m$, this is equivalent to solving the equation $n \cdot a \in [m - (r - l); m + (r - l)]$, where $a \in [l; r]$, $n \in \mathbb N$. Let's fix some arbitrary $a$. Then we find the maximum $n$ for which $n\cdot a \leq m + (r - l)$ — this $n$ will be equal to $n' = \lfloor \frac{m + r - l}{a} \rfloor$. Let's check whether it is true that $n' > 0$ and $n' \cdot a \in [m- (r-l); m + (r - l)]$. If this is the case, then restore $b$ and $c$ as indicated above.

This solution iterates over all possible values of $a$, and checks if such $a$ can be used in answer if the manner described above. Thus, this solution has complexity $\mathcal O (r - l)$

 
### [1379C - Выбор цветов для букета](../problems/C._Choosing_flowers.md "Codeforces Round 657 (Div. 2)")

Let's look at sorts, for which there is more than one flower in the bouquet. We can prove, that there can be only one such sort. Let's assume that there are sorts $x$ and $y$ with $b_x \ge b_y$, such that for both sorts there are at least 2 flowers. Let's exclude flower of sort $y$ from bouquet and add flower of sort $x$. The total happiness will change by $b_x - b_y$, so it will not decrease. Repeating this, we can leave bouquet with only one flower of sort $y$ without decreasing the total happiness. So, there always exists an answer where there is only one sort with multiple flowers.

Using this fact, we can solve the problem the following way. Let's iterate over each sort of flowers and for every $x$ suppose that there are multiple flowers of sort $x$. It is obvious, that if some sort $y$ has $a_y > b_x$, then we should take one flower of such sort, and if $a_y \le b_x$, then we would better take another flower of sort $x$. So, we need to know sum of $a_i$ for all flowers that have $a_i > b_x$. To do it in $O(\log m)$, we can sort all flowers by $a_y$ in decreasing order, calculate prefix sums on that array, and using binary search find maximum $k$, such that $a_k > b_x$ and get prefix sum of $a_i$ for first $k$ sorts. All the rest $n - k$ flowers will be of the sort $x$.

Also we should take into account the case when for each sort only one flower of that sort is taken. In that case we should take $n$ sorts with largest $a_i$.

That way we can get the answer in $O(m \log m)$ time.

 
### [1379D - Новые электрички](../problems/D._New_Passenger_Trams.md "Codeforces Round 657 (Div. 2)")

Let's look what happens if we fix $t$ for answer. Start time leads to canceling every train, which has $m_i$ in one of ranges $[t - k + 1, t - 1],\ [t + \frac{m}{2} - k + 1, t + \frac{m}{2} - 1]$. Some borders may be either negative or greater than $m$, but values must be count modulo $m$. We may imagine them as segments on a circle with length m.

Now let's look at every train. If train departs at $m_i$ then it must be canceled if we choose $t$ in segments $[m_i + 1, m_i + k - 1],\ [m_i + \frac{m}{2} + 1, m_i + \frac{m}{2} + k - 1]$. Otherwise it shouldn't be canceled. So, we need to find such point $t$ in $[0, \frac{m}{2} - 1]$, that $t$ is covered by minimal number of segments.

Note that we block two simmetrical segments — difference between their borders is equal to half of circle's length. Cause we need only segments in first half of the cycle, we can look at these segments modulo $\frac{m}{2}$, where they collapse into one segment.

Now we need to sort segment's borders. Segments are placed on circle, so some of them should be split in two — one ends in $\frac{m}{2} - 1$, another starts at $0$. Now we need to find point, which is covered by minimal number of segments. For that we will keep a variable counting current number of open segments, and change it from one coordinate to another. We can skip coordinates with no events on them, so all solution will take $O(n \log n)$ time to solve.

 
### [1379E - Перевернутые родословные](../problems/E._Inverse_Genealogy.md "Codeforces Round 657 (Div. 2)")

Let's rephrase the statement. Critical node — a non-leaf node with subtrees, where one $2$ or more times smaller than another. We need to find an example of the binary tree with $n$ nodes there $k$ of them are critical. 

First of all, let's count number of nodes if we know that there $m$ leafs. Because of the fact, that tree is binary, size of the tree should be $2m - 1$. So for even $n$ there is no answer. 

A number of critical nodes can't be more than $max\left(0, \frac{n - 3}{2}\right)$. It is obvious that caterpillar tree have maximum number of critical nodes.

Let's say that $n$ is almost a power of two then $n + 1$ is a power of two. 

If there $0$ critical nodes, then $n$ is almost a power of two (example full binary tree). Suppose exist trees that don't satisfy the condition. Let's look on the smallest one. Left and right subtrees satisfy the condition. If they are different, then one of them $2$ times bigger than another and root is critical. If they are have equal sizes, then our tree satisfied the condition.

If there $1$ critical nodes, then $n$ isn't almost a power of two. Suppose there exist trees that don't satisfy the condition. Let's look on the smallest one. One of the subtrees is almost a power of two. If both subtrees are almost a power of two, then they are equal and there is no critical nodes. In other case, the root isn't critical. Then second subtree isn't almost a power of two. If we write two inequalities with the size of the tree and the size of the first subtree, then it becomes clear that size of the tree can't be almost a power of two. 

How to construct an example with $1$ critical node? Let $m$ be some integer that: $2^m < n < 2^{m + 1}$. It can be shown that one subtree in answer can be equals $2^{m} - 1$ or $2^{m - 1} - 1$. 

And finally, what we should do when $k \geq 2$? Let's go from $(n, k)$ to $(n - 2, k - 1)$. If $n \geq 13$ we can just make one subtree size of $1$. In other cases we should precalculate answers. 

So we have solution with complexity $O(n)$.

The easy way to write a solution is make a function $can(n, k)$ that return True if there exists needed tree and else False. Then we can find the smallest subtree with simple brute force. In this case complexity is $O(n \log n)$.

 
### [1379F1 - Шахматные баталии (простая версия)](../problems/F1._Chess_Strikes_Back_(easy_version).md "Codeforces Round 657 (Div. 2)")

Let's divide the grid into $nm$ squares of size $2 \times 2$. Each square contains exactly two white cells. So, we should put exactly one king into one square.

Let's mark a square L, if its left upper cell is banned and R if its right down cell is banned. Square can be L and R at the same time.

If there exists some L-square $(x_1, y_1)$ and R-square $(x_2, y_2)$, such that:

* $x_1 \leq x_2$
* $y_1 \leq y_2$

the answer is NO. It's easy to prove because if such pair of cells exists we can consider path from $(x_1, y_1)$ to $(x_2, y_2)$. In this path, there will be two neighboring cells.

If no such pairs of cells exist the answer is YES.

Note that in this version of the problem cells cannot become available againg. This means that for some prefix of queries the answer is YES and for the remaining suffix the answer is NO. Let's do a binary search to find position of the last YES.

How to check that the answer is YES fast enough?

Let's calculate the values:

* $a_x = $ minimal $y$, such that $(x, y)$ is L-square
* $b_x = $ maximal $y$, such that $(x - 1, y)$ is R-square

After that, we should check, that $a_i > b_j$ for all $i > j$. We can easily do this using prefix maximums for $a$ and suffix minimums for $b$

Total complexity is $O((n+q) \log{q})$.

 
### [1379F2 - Шахматные баталии (сложная версия)](../problems/F2._Chess_Strikes_Back_(hard_version).md "Codeforces Round 657 (Div. 2)")

Let's divide the grid into $nm$ squares of size $2 \times 2$. Each square contains exactly two white cells. So, we should put exactly one king into one square.

Let's mark a square L, if its left upper cell is banned and R if its right down cell is banned. Square can be L and R at the same time.

If there exists some L-square $(x_1, y_1)$ and R-square $(x_2, y_2)$, such that:

* $x_1 \leq x_2$
* $y_1 \leq y_2$

the answer is NO. It's easy to prove because if such pair of cells exists we can consider path from $(x_1, y_1)$ to $(x_2, y_2)$. In this path, there will be two neighboring cells.

If no such pairs of cells exist the answer is YES.

So, after each query, we should check this condition.

Let's maintain the values:

* $a_x = $ minimal $y$, such that $(x, y)$ is L-square
* $b_x = $ maximal $y$, such that $(x - 1, y)$ is R-square

These values can be maintained using $O(n)$ sets in $O(\log{q})$ time.

After that, we should check, that $a_i > b_j$ for all $i > j$.

Let's make a segment tree with values:

* minimal $a_i$ on segment
* maximal $b_i$ on segment
* the flag, that for all $i > j$ from the segment it is true, that $a_i > b_j$

It is easy to merge two such segments, to calculate the flag, we should check, that $min_{left} > max_{right}$.

So, the total time to answer the query is $O(\log{n}+\log{q})$.

Total complexity is $O((n+q)(\log{n}+\log{q}))$.

