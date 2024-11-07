# Tutorial


### Short information

Sorry for another delayed editorial, I know I promised that it will come out sooner the previous time, but I wasn't feeling well today, so the work was slower than usual.

**About problem F:**

I am once again sorry for the inconveniences caused by tight ML in this problem. It was not the intended behavior since we relied too much on the main solution and didn't assume most of the solutions using DFS will fail. In this editorial I attach the code of the main solution that we expected from the beginning, it uses ~75MB of memory.

I guess, Div. 3 Rounds are not only for participants to learn but also can serve as educational for authors as well. I'll try not to repeat the same mistakes the next time :) Thanks to everyone for participating and hope to see you again!

### The editorial

[1607A - Linear Keyboard](../problems/A._Linear_Keyboard.md "Codeforces Round 753 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1607A - Linear Keyboard](../problems/A._Linear_Keyboard.md "Codeforces Round 753 (Div. 3)")

Since it does not take time to place your hand over the first letter, you need to calculate the sum of the distances between the keyboard keys corresponding to each pair of adjacent letters of the word, that is $$\sum\limits_{i=2}^n |\mathtt{pos}(s_i) - \mathtt{pos}(s_{i-1})|$$ where $\mathtt{pos}(c)$ is the position of the keyboard key corresponding to the letter $c$.

In order to calculate this sum, let's just iterate through the word $s$ with the for loop and find the differences between the positions of $s_i$ and $s_{i-1}$ on the keyboard. 

To find the position of a character on the keyboard, you could either use the built-in strings functions (such as str.index in Python or string::find in C++) or precalculate each letter's position on the keyboard into a separate array using another loop over a keyboard.

 **Solution**
```cpp
t = int(input())
for _ in range(t):
    k, s = input(), input()
    res = 0
    for i in range(1, len(s)):
        res += abs(k.index(s[i]) - k.index(s[i - 1]))
    print(res)
```
[1607B - Odd Grasshopper](../problems/B._Odd_Grasshopper.md "Codeforces Round 753 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**
### [1607B - Odd Grasshopper](../problems/B._Odd_Grasshopper.md "Codeforces Round 753 (Div. 3)")

Consider the first four actions that the grasshopper will perform, starting at a point with coordinate $0$: 

1. coordinate $0$ is even, jumping left to $1$ leads to $-1$
2. coordinate $-1$ is odd, jumping right to $2$ leads to $2$
3. coordinate $1$ is odd, jumping right to $3$ leads to $4$
4. coordinate $4$ is even, jumping left to $4$ leads to $0$

If you look closely at the next four jumps, they follow the same pattern: jump to the left, two jumps to the right, jump to the left. In general, making jumps with numbers $4k + 1 \ldots 4k + 4$, the grasshopper will start from coordinate $0$ and move as $$0 \underset{\ ^{-(4k+1)}}{\longrightarrow} -(4k + 1) \underset{\ ^{+(4k+2)}}{\longrightarrow} 1 \underset{\ ^{+(4k+3)}}{\longrightarrow} 4k + 4 \underset{\ ^{-(4k+4)}}{\longrightarrow} 0$$

Thus, if $x_0$ were always zero, the answer would be 

1. $-n$ if $n \equiv 1 \bmod 4$
2. $1$ if $n \equiv 2 \bmod 4$
3. $n + 1$ if $n \equiv 3 \bmod 4$
4. $0$ if $n$ is divisible by $4$

Let's find an answer for the cases when $x_0 \neq 0$. But if $x_0$ is even, then all steps will follow the same directions, and the answer will be $x_0 + D$, where $D$ is the answer for the same $n$ and starting point $0$ (described above). And if $x_0$ is odd, then all steps will have opposite directions, and the answer will be $x_0 - D$.

 **Solution**
```cpp
t = int(input())
maps = [
    lambda x: 0,
    lambda x: x,
    lambda x: -1,
    lambda x: -x - 1
]

for _ in range(t):
    x0, n = map(int, input().split())
    d = maps[n % 4](n)
    print(x0 - d if x0 % 2 == 0 else x0 + d)
```
[1607C - Minimum Extraction](../problems/C._Minimum_Extraction.md "Codeforces Round 753 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**
### [1607C - Minimum Extraction](../problems/C._Minimum_Extraction.md "Codeforces Round 753 (Div. 3)")

Note that the order of numbers in the array does not affect anything. If you swap two elements in the original array, the set of elements at each step will not change in any way. Let's sort the original array $a$ and denote it by $a^0$.

We denote by $a^i$ the state of array $a^0$ after applying $i$ operations of minimum extraction. The minimum element in $a^0$ is $a^0_1$, so the elements of array $a^1$ will be equal to $a^1_i = a^0_{i+1} - a^0_1$, and therefore the minimum of them will be $a^0_2 - a^0_1$.

Constructing an array $a^2$, we can notice that its elements are equal to $a^2_i = a^1_{i+1} - a^1_1$. We know that the elements of $a^1$ are the difference between corresponding elements of the array $a^0$ and $a^0_1$, so $$a^2_i = a^1_{i+1} - a^1_1 = (a^0_{i+2} - a^0_1) - (a^0_2 - a^0_1) = a^0_{i+2} - a^0_2$$

Thus, the elements of the array $a^2$ are the differences between elements of $a^0$ starting with third and $a^0_2$, the minimum of which is $a^0_3 - a^0_2$. It is not difficult to show in a similar way (for example by induction) that the elements of $a^c$ are equal to $a^c_i = a^0_{i+c} - a^0_c$, the minimum of which is $a^0_{c+1} - a^0_c$.

So the "candidates" for the answer are simply differences of adjacent elements of the array $a^0$. Indeed, if we look at $a^0 = [1, 4, 6, 12, 13]$, it will undergo changes as follows: $[\color{blue}{1}, 4, 6, 12, 15] \to [\color{blue}{3}, 5, 11, 14] \to [\color{blue}{2}, 8, 11] \to [\color{blue}{6}, 9] \to [\color{blue}{3}]$. You can notice that the minimum elements starting with after the first operation are exactly $4 - 1$, $6 - 4$, $12 - 6$ and $15 - 12$, respectively.

Thus, to solve the problem, it was sufficient to sort the array in ascending order, then take the maximum of the original first element and the differences of all adjacent elements $$\max\left(a^0_1, \max\limits_{i=2}^n \left(a^0_i - a^0_{i-1}\right) \right)$$

 **Solution**
```cpp
t = int(input())

for _ in range(t):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    res = a[0]
    for i in range(n - 1):
        res = max(res, a[i + 1] - a[i])
    print(res)
```
[1607D - Blue-Red Permutation](../problems/D._Blue-Red_Permutation.md "Codeforces Round 753 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1607D - Blue-Red Permutation](../problems/D._Blue-Red_Permutation.md "Codeforces Round 753 (Div. 3)")

Note the following fact: if a number $x$ in a permutation was obtained from a blue number and a number $y$ in a permutation was obtained from a red number, and $x > y$, then by decreasing the blue number and increasing the red number exactly $x - y$ times each, we will obtain the same permutation in which the two numbers have swapped places. Thus, if a permutation can be obtained at all, some permutation can be obtained by making all the red numbers equal to $n, n - 1, \ldots, n - k + 1$, and the blue ones equal to $1, 2, \ldots, n - k$, where $k$ is the total count of red numbers.

Now consider separately two red numbers $a_i$ and $a_j$ such that $a_i > a_j$. If $x$ is produced by increasing $a_i$ and $y$ is produced by increasing $a_j$, and in the same time $x < y$ then $y > x \geqslant a_i > a_j$, and the following is also true: $x > a_j$ and $y > a_i$. So we just showed that if an answer exists, it also exists if greater numbers are produced by greater values from the input. The same holds for the blue numbers.

Let us sort all elements $a_i$ by the key $(c_i, a_i)$, where $c_i$ the color of $i$-th element (and blue comes before red). It remains to check that for any $t$ from $1$ to $n$ we can get the number $t$ from the $t$-th element of the obtained sorted array. To do this, we iterate through it and check that either $c_t = \,$'B' and $a_t \geqslant t$ so it can be reduced to $t$, or, symmetrically, $c_t = \,$'R' and $a_t \leqslant t$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];

        string c;
        cin >> c;

        vector<int> l, r;
        forn(i, n)
            (c[i] == 'B' ? l : r).push_back(a[i]);
        sort(l.begin(), l.end());
        sort(r.begin(), r.end(), greater<int>());

        bool ok = true;
        forn(i, l.size())
            if (l[i] < i + 1)
                ok = false;
        forn(i, r.size())
            if (r[i] > n - i)
                ok = false;

        cout << (ok ? "YES" : "NO") << 'n';
    }
}
```
[1607E - Robot on the Board 1](../problems/E._Robot_on_the_Board_1.md "Codeforces Round 753 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1607E - Robot on the Board 1](../problems/E._Robot_on_the_Board_1.md "Codeforces Round 753 (Div. 3)")

Let's look at the answer $(r, c)$. Let's see how many commands the robot can execute. Since the robot breaks as soon as goes outside the field, if any command causes it to break, it either leads to its total shift relative to $(r, c)$ of exactly $c$ to the left or exactly $m - c + 1$ to the right, or, similarly, of exactly $r$ up or exactly $n - r + 1$ down.

Denote by $d[\leftrightarrow]$ and $d[\updownarrow]$ the sum of the maximum positive (right, down) and maximum negative (left, up) shifts in the corresponding direction. By adding up the above constraints, we get the fact that the robot will not fall off the board only if $d[\leftrightarrow] \leqslant (c - 1) + ((m - c + 1) - 1) = m - 1$ and $d[\updownarrow] \leqslant (r - 1) + ((n - r + 1) - 1) = n - 1$.

Note that the reverse is also true: if both these conditions are satisfied, then starting from the point $(\max[\leftarrow] + 1, \max[\uparrow] + 1)$ where $\max[\mathtt{dir}]$ is the maximum shift along the direction $\mathtt{dir}$, the robot will not pass any of the board's edges. Thus, it is sufficient to find the number of commands which, when executed, hold the following invariant: $$d[\leftrightarrow] \leqslant m - 1 \land d[\updownarrow] \leqslant n - 1$$

The horizontal shift can be calculated as the difference between the number of letters 'R' and the number of letters 'L' encountered. Similarly, the vertical shift — as the difference of the numbers of 'D' and 'U'. Let's iterate over the sequence of commands, maintaining relevant values of $\max[\mathtt{dir}]$ for all $\mathtt{dir} \in [\leftarrow, \rightarrow, \uparrow, \downarrow]$. After executing each command, if the robot goes farther in some direction than ever before, we update the corresponding $\max$.

Either we reach the end of $s$, or we meet a command after which either $d[\leftrightarrow] = \max[\leftarrow] + \max[\rightarrow]$ becomes equal to $m$, or $d[\updownarrow] = \max[\uparrow] + \max[\downarrow]$ becomes equal to $n$ and the robot breaks, so the previous command was the last one successfully executed. The possible answer is $(\max[\leftarrow] + 1, \max[\uparrow] + 1)$, where the $\max$ values are calculated one command before the robot broke.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        int bx = 0, by = 0;
        int min_bx = 0, max_bx = 0, min_by = 0, max_by = 0;
        for (char c: s) {
            if      (c == 'L') min_by = min(min_by, --by);
            else if (c == 'R') max_by = max(max_by, ++by);
            else if (c == 'U') min_bx = min(min_bx, --bx);
            else               max_bx = max(max_bx, ++bx);

            if (max_bx - min_bx >= n) {
                if (bx == min_bx) min_bx++;
                break;
            }
            if (max_by - min_by >= m) {
                if (by == min_by) min_by++;
                break;
            }
        }

        cout << 1 - min_bx << ' ' << 1 - min_by << 'n';
    }
}
```
[1607F - Robot on the Board 2](../problems/F._Robot_on_the_Board_2.md "Codeforces Round 753 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> dir(n);
        for (int i = 0; i < n; i++)
            cin >> dir[i];

        vector<vi> res(n, vi(m, 0));
        int opt = 0, optr = 0, optc = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (res[r][c] > 0)
                    continue;

                int nr = r, nc = c;
                int depth = 0;
                vector<pii> path;
                auto ok = [&n, &m](int row, int col) {
                    return row > -1 && row < n && col > -1 && col < m;
                };

                do {
                    res[nr][nc] = --depth;
                    path.emplace_back(nr, nc);
                    if (dir[nr][nc] == 'L')
                        nc--;
                    else if (dir[nr][nc] == 'R')
                        nc++;
                    else if (dir[nr][nc] == 'U')
                        nr--;
                    else
                        nr++;
                } while (ok(nr, nc) && res[nr][nc] == 0);

                int start = 1;
                if (ok(nr, nc)) {
                    if (res[nr][nc] < 0) {
                        int cycle = res[nr][nc] - depth + 1;
                        for (int i = 0; i < cycle; i++) {
                            auto p = path.back();
                            path.pop_back();
                            res[p.first][p.second] = cycle;
                        }
                    }
                    start = res[nr][nc] + 1;
                }
                while (!path.empty()) {
                    auto p = path.back();
                    path.pop_back();
                    res[p.first][p.second] = start++;
                }

                if (res[r][c] > opt) {
                    opt = res[r][c];
                    optr = r;
                    optc = c;
                }
            }
        }

        cout << optr + 1 << ' ' << optc + 1 << ' ' << opt << 'n';
    }
}
```
[1607G - Banquet Preparations 1](../problems/G._Banquet_Preparations_1.md "Codeforces Round 753 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**
### [1607G - Banquet Preparations 1](../problems/G._Banquet_Preparations_1.md "Codeforces Round 753 (Div. 3)")

Let's find how much meat and fish a taster can eat at most. Note that a taster can eat no more than $\min(a_i, m)$ of fish from the $i$-th dish (since he can't eat more than $m$ or more than there is at all). Similarly, he can eat no more than $\min(b_i, m)$ of meat. Let's sum the obtained values over all $i$ and denote the resulting sums by $A$ and $B$ —the maximum total amount of fish and meat that can be eaten.

Let's denote by balance* $T$ the value $\sum\limits_{i=1}^n a_i - \sum\limits_{i=1}^n b_i$, that is the balance without module. If the taster eats as much fish as possible, he will eat $A$ of fish and $nm - A$ of meat, and change the balance* by $-A + (nm - A) = nm - 2A$. Similarly, if he eats the maximum amount of meat, the balance* will change by $2B - nm$. Note that the taster can achieve any balance* between $2B - nm$ and $nm - 2A$ of the same oddity as both of these numbers. To do this, just take the way of eating the maximum fish and substitute eating a gram of fish for a gram of meat several times.

Thus, the final balance $T_\mathtt{res}$ can be found as $\min |x|$ over all $x$ between $T + (2B - nm)$ and $T + (nm - 2A)$ with same oddity. To do this, just check the boundaries of the resulting segment — if they have the same sign, then it's the boundary with the smallest absolute value, otherwise we can take one of the numbers $-1$, $0$, $1$ present in said set (depending on the parity of $nm$).

All that remains is to find how much of what type to eat from each dish. Having obtained the answer in the previous paragraph (the final balance), we can reconstruct how much fish and how much meat the taster has to eat to achieve it. The expected amount of fish to be eaten can be found as $e_A = \frac{T + nm - T_\mathtt{res}}{2}$. 

Note that the taster must eat $\max(m - b_i, 0)$ of fish from the $i$-th dish, since if meat $b_i < m$, then at least $m - b_i$ of fish is guaranteed to be eaten. Let's break down $e_A$ into the sum of $nm - B$ (how much total fish will have to be eaten anyway) and the remaining value $g_A = e_A - (nm - B)$. Let's go through all the dishes and collect the first summand as just the sum of $\max(m - b_i, 0)$ over all $i$, and the second summand with greedy algorithm, each time giving the taster as much fish beyond what he must eat anyway until the sum of such "additions" reaches $g_A$. And knowing for each dish how much fish will be eaten from it, the amount of meat eaten can be calculated by subtracting the fish eaten from $m$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pii> dishes(n);
        ll balance = 0;
        ll max_a = 0, max_b = 0;
        ll total_eat = static_cast<long long>(n) * m;

        for (int i = 0; i < n; i++) {
            cin >> dishes[i].first >> dishes[i].second;
            balance += dishes[i].first - dishes[i].second;
            max_a += min(m, dishes[i].first);
            max_b += min(m, dishes[i].second);
        }
        ll max_delta = 2 * max_a - total_eat, min_delta = total_eat - 2 * max_b;
        ll min_a = total_eat - max_b;

        ll eat_a;
        if (balance < 0) {
            eat_a = min_a;
            if (balance - min_delta >= 0)
                eat_a = min(max_a, (total_eat + balance + 1) / 2);
        } else {
            eat_a = max_a;
            if (balance - max_delta <= 0)
                eat_a = min(max_a, (total_eat + balance + 1) / 2);
        }
        ll ans = abs(balance - 2 * eat_a + total_eat);

        cout << ans << 'n';
        ll rest_a = eat_a - min_a;
        for (int i = 0; i < n; i++) {
            ll cur_a = 0;
            if (dishes[i].second < m)
                cur_a += m - dishes[i].second;
            ll add = min(rest_a, min(m - cur_a, dishes[i].first - cur_a));
            cur_a += add;
            rest_a -= add;
            cout << cur_a << ' ' << m - cur_a << 'n';
        }
    }
}
```
[1607H - Banquet Preparations 2](../problems/H._Banquet_Preparations_2.md "Codeforces Round 753 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1607H - Banquet Preparations 2](../problems/H._Banquet_Preparations_2.md "Codeforces Round 753 (Div. 3)")

Note that dishes can become equal if and only if they have equal values of $a_i + b_i - m_i$, that is, how much fish and meat remain in them in total after "tasting". Let's calculate this value for each dish and group all the dishes with equal calculated values.

The minimum amount of fish that can remain in the $i$-th dish is $a_i^\mathtt{min} = \max(0, a_i - m_i)$ in case where the maximum possible mass of fish is eaten. Similarly, the maximum amount of fish that can remain is $a_i^\mathtt{max} = a_i + \min(0, b_i - m_i)$ in case where the maximum possible mass of meat is eaten. 

Consider one of the groups $g$ in which there are all the dishes with equal values $G = a_i + b_i - m_i$. We sill assign each dish a corresponding segment on the coordinate line between $a_i^{\mathtt{min}}$ and $a_i^{\mathtt{max}}$. This segment specifies all possible values of the remaining mass of fish in the dish; any value on it is achievable by replacing eating some mass of fish with the same mass of meat. And since $G$ is common, the same amount of remaining fish will imply the same amount of remaining meat, thus, equality.

Let us solve the problem for each group independently. Within a group, the problem is reduced to choosing as few points as possible that "cover" all the segments described in the last paragraph (that is, that there should be a point inside each segment). Each selected point will correspond to the resulting dish, and it being inside a segment will mean that such a resulting dish can be obtained from the corresponding starting one. Such a problem is solved as follows: 

1. we choose a segment with the minimal right end; because it must contain at least one chosen point we'll greedily choose it equal to its right end;
2. there's no point in choosing a point to the left from it, since it will not cover more segments than the right end of the segment in question;
3. we'll mark all segments containing this point as covered, and repeat the algorithm for the next unprocessed segment with the minimal right end.

For this algorithm, it is sufficient to sort the segments by their right ends within each group and iterate through the segments, greedily selecting points in the manner described above. The set of points obtained at the end will be the answer, and its size and the information about the point selected within each segment should be printed in the output. If for a dish $(a_i, b_i, m_i)$ a point $x$ is chosen inside its corresponding segment, then there should be exactly $x$ of fish left in it, that is, you should output the numbers $a_i - x$ and $m_i - (a_i - x)$ in the answer.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

struct seg {
    int a, b, m;
    int index;
};

int n, ans;
vector<seg> segments;
map<int, vector<seg>> diags;

void erase(multiset<pair<pair<int,int>, int>>& lr, int l, int r, int index) {
    pair<pair<int,int>,int> plr = make_pair(make_pair(l, r), index);
    auto i = lr.find(plr);
    assert(i != lr.end());
    lr.erase(i);
}

void erase(multiset<pair<pair<int,int>, int>>& lr, multiset<pair<pair<int,int>, int>>& rl, int l, int r, int index) {
    erase(lr, l, r, index);
    erase(rl, r, l, index);
}

map<int, pair<int,int>> dd;

void setup_dd(int index, int value) {
    assert(dd.count(index) == 0);
    int x = segments[index].a - value;
    int y = segments[index].m - x;
    assert(segments[index].a - x >= 0);
    assert(segments[index].b - y >= 0);
    assert(x + y == segments[index].m);
    dd[index] = make_pair(x, y);
}

int solve(vector<seg> s) {
    int n = s.size();
    multiset<pair<pair<int,int>, int>> lr;
    multiset<pair<pair<int,int>, int>> rl;
    forn(i, n) {
        int min_d = max(s[i].m - s[i].b, 0);
        int max_d = min(s[i].a, s[i].m);
        lr.insert(make_pair(make_pair(s[i].a - max_d, s[i].a - min_d), s[i].index));
        rl.insert(make_pair(make_pair(s[i].a - min_d, s[i].a - max_d), s[i].index));
    }

    int result = 0;
    while (!rl.empty()) {
        result++;
        auto min_r_iterator = rl.begin();
        int r = min_r_iterator->first.first;
        int l = min_r_iterator->first.second;
        int index = min_r_iterator->second;
        erase(lr, rl, l, r, index);
        setup_dd(index, r);

        while (!lr.empty()) {
            auto min_l_iterator = lr.begin();
            int ll = min_l_iterator->first.first;
            int rr = min_l_iterator->first.second;
            int ii = min_l_iterator->second;
            if (ll <= r) {
                erase(lr, rl, ll, rr, ii);
                setup_dd(ii, r);
            } else
                break;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        cin >> n;
        diags.clear();
        dd.clear();
        segments = vector<seg>(n);
        forn(i, n) {
            seg s;
            s.index = i;
            cin >> s.a >> s.b >> s.m;
            diags[s.a + s.b - s.m].push_back(s);
            segments[i] = s;
        }
        int sum = 0;
        for (auto p: diags)
            sum += solve(p.second);
        cout << sum << 'n';
        forn(i, n)
            cout << dd[i].first << " " << dd[i].second << 'n';
    }
}
```
