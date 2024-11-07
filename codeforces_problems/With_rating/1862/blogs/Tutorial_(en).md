# Tutorial_(en)

**We would like to thank all the participants who helped us and Codeforces to overcome the 40.000 registered users for the first time**

[1862A - Gift Carpet](../problems/A._Gift_Carpet.md "Codeforces Round 894 (Div. 3)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Candidate Master diskoteka")

 **Tutorial**
### [1862A - Gift Carpet](../problems/A._Gift_Carpet.md "Codeforces Round 894 (Div. 3)")

Note that if the answer is «YES», then there exists a reading of the word «vika» in which the leftmost letter «v» is included. Among such readings, we can also consider the one in which the leftmost letter «i» is included, which is located to the right of the first occurrence of «v». Similarly, we can do the same for the remaining letters. Therefore, it is sufficient to greedily search for the characters in order.

Let's store the input data in a 2D array and process it by going through the columns from left to right. First, we will search for the character «v» by iterating through all the characters in each processed column. Once we find the character «v», we will similarly search for the character «i» and so on.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        vector<string> carpet(n);
        for (int i = 0; i < n; ++i) {
            cin >> carpet[i];
        }
        string vika = "vika";
        int fnd = 0;
        for (int i = 0; i < m; ++i) {
            bool check = false;
            for (int j = 0; j < n; ++j) {
                if (carpet[j][i] == vika[fnd]) {
                    check = true;
                }
            }
            if (check) {
                ++fnd;
                if (fnd == 4) {
                    break;
                }
            }
        }
        if (fnd == 4) {
            cout << "YESn";
        } else {
            cout << "NOn";
        }
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 


[*43*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*148*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*331*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*88*](https://codeforces.com/data/like?action=like "I like this")
[1862B - Sequence Game](../problems/B._Sequence_Game.md "Codeforces Round 894 (Div. 3)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Candidate Master diskoteka")

 **Tutorial**
### [1862B - Sequence Game](../problems/B._Sequence_Game.md "Codeforces Round 894 (Div. 3)")

Let's compare each pair of adjacent numbers. If the left number is smaller than the right number, then the right number is at least $2$. We will insert $1$ between them.

Now, for each pair of numbers, it is true that either these two numbers were originally in the sequence, or one of them is $1$. In this case, if two numbers were originally in the sequence, then the left number is not smaller than the right number. If the left number is $1$, then it is smaller than the right number, since the right number was at least $2$. If the right number is $1$, then the left number in the pair is not smaller than the right number.

We have checked all cases. It is evident that such a sequence is valid, as Vika would have only removed all the $1$ we added and nothing more.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (i && a.back() > x) {
                a.push_back(1);
            }
            a.push_back(x);
        }
        cout << a.size() << "n";
        for (int el : a)
            cout << el << " ";
        cout << "n";
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*24*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*354*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*99*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*39*](https://codeforces.com/data/like?action=like "I like this")
[1862C - Flower City Fence](../problems/C._Flower_City_Fence.md "Codeforces Round 894 (Div. 3)")

Idea: [playerr17](https://codeforces.com/profile/playerr17 "Expert playerr17")

 **Tutorial**
### [1862C - Flower City Fence](../problems/C._Flower_City_Fence.md "Codeforces Round 894 (Div. 3)")

Obviously, if $a_1 \neq n$, then this fence is not symmetric, because the fence $a$ has a length of $n$, while the horizontally laid fence has a length of $a_1 \neq n$.

Now let's build a fence $b$ using horizontal boards that would match the original fence $a$. And let's check if the arrays $a$ and $b$ are equal. If they are equal, then the fence is symmetric; otherwise, it is not. There won't be any memory issues since all $a_i \le n$, which means the length of array $b$ does not exceed $n$.

 **Solution**
```cpp
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (a[1] != n) {
            cout << "NO" << 'n';
            continue;
        }
        vector<int> b;
        for (int i = n; i >= 1; i--) {
            while (b.size() < a[i]) {
                b.push_back(i);
            }
        }
        bool meow = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i - 1]) {
                cout << "NO" << 'n';
                meow = false;
                break;
            }
        }
        if (meow) {
            cout << "YES" << 'n';
        }
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*128*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*516*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*49*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*125*](https://codeforces.com/data/like?action=like "I like this")
[1862D - Ice Cream Balls](../problems/D._Ice_Cream_Balls.md "Codeforces Round 894 (Div. 3)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Candidate Master diskoteka"), [Ivang](https://codeforces.com/profile/Ivang "Master Ivang")

 **Tutorial**
### [1862D - Ice Cream Balls](../problems/D._Ice_Cream_Balls.md "Codeforces Round 894 (Div. 3)")

First, let's note that having more than two balls of the same type is meaningless.

Let's denote $x$ as the number of flavours of balls represented by two instances of each ball. Let $y$ denote the number of flavours represented by a single instance.

Let's calculate the number of different ways to make an ice cream from these balls: we can make $x$ ice creams from balls of the same flavour and $\dfrac{(x + y) \cdot (x + y - 1)}{2}$ ice creams from balls of different flavours. In the problem, we are asked to select balls in such a way that $x + \dfrac{(x + y) \cdot (x + y - 1)}{2} = n$.

Note that for a fixed sum of $x + y$, we can uniquely determine $x$ and therefore $y$ (or determine that there is no solution for that sum).

Let's assume we have found an answer with a minimum sum of $x + y = k$. This means $\dfrac{k \cdot (k - 1)}{2} \leq n \leq \dfrac{k \cdot (k - 1)}{2} + k$. Moreover, if we find an answer with a sum of $x + y = k + 1$, then $k + \dfrac{k \cdot (k - 1)}{2} \leq n \leq k + \dfrac{k \cdot (k - 1)}{2} + k + 1$. From this, we can see that this is only possible when $n = k + \dfrac{k \cdot (k - 1)}{2}$. It is also evident that there are no answers with a sum greater than $k + 2$.

Now, all we need to do is perform a binary search on the sum of $x + y$ and then determine $x$ and $y$. And don't forget to consider the case when two sums of $x + y$ may be suitable, in order to choose the one with the fewest number of balls.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int l = 0, r = min<int>(2e9, 2 * n);
        while (r - l > 1) {
            int m = (l + r) >> 1;
            // m = x + y, answer = x + 2 * y
            if (m * (m - 1) / 2 + m < n) {
                l = m;
            } else {
                r = m;
            }
        }
        int y = n - r * (r - 1) / 2;
        if ((r + 1) * r / 2 <= n) {
            cout << min(r + y, r + 1 + n - (r + 1) * r / 2) << "n";
        } else {
            cout << r + y << "n";
        }
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*74*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*296*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*83*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*249*](https://codeforces.com/data/like?action=like "I like this")
[1862E - Kolya and Movie Theatre](../problems/E._Kolya_and_Movie_Theatre.md "Codeforces Round 894 (Div. 3)")

Idea: [pavlekn](https://codeforces.com/profile/pavlekn "Master pavlekn")

 **Tutorial**
### [1862E - Kolya and Movie Theatre](../problems/E._Kolya_and_Movie_Theatre.md "Codeforces Round 894 (Div. 3)")

Let's notice that if we visit the cinema on days with numbers $i_1, i_2, \ldots, i_k$, the total entertainment value of the visited movies will be equal to $(a_{i_1} - d \cdot i_1) + (a_{i_2} - d \cdot (i_2 - i_1)) + \ldots + (a_{i_k} - d \cdot (i_k - i_{k-1})) = (a_{i_1} + a_{i_2} + \ldots + a_{i_k}) - d \cdot i_k$.

Thus, it is sufficient to iterate over the day when Kolya will visit the cinema for the last time — $i_k$, and maintain the maximum $m - 1$ non-negative elements on the prefix $[1, i_k - 1]$. This can be done, for example, using std::multiset. The total complexity of the solution will be $O(n \log{n})$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        set<pair<int, int>> s;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int cur = sum + a[i] - d * (i + 1);
            ans = max(ans, cur);
            if (a[i] > 0) {
                s.insert({a[i], i});
                sum += a[i];
                if (s.size() >= m) {
                    sum -= (s.begin()->first);
                    s.erase(s.begin());
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*87*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*397*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")
[1862F - Magic Will Save the World](../problems/F._Magic_Will_Save_the_World.md "Codeforces Round 894 (Div. 3)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Candidate Master diskoteka")

 **Tutorial**
### [1862F - Magic Will Save the World](../problems/F._Magic_Will_Save_the_World.md "Codeforces Round 894 (Div. 3)")

First, let's note that Vika can defeat all the monsters at once, in the last second. There is no point in spending mana gradually.

Now, let's say we know how many seconds Vika will accumulate mana before spending it. Then we also know how much mana she will have accumulated by that time. How should she spend it?

Note that the total strength of the monsters is given to us. Therefore, it is enough for us to spend as much of the available water mana as possible, so that there is enough fire mana left for the remaining monsters. This is a well-known knapsack problem.

Finally, let's note that we don't need to iterate over the number of seconds and build the knapsack each time. It is enough to build it initially, and then iterate over how much water mana we will spend and whether we will have enough fire mana left for the rest.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        int w, f, n;
        cin >> w >> f >> n;
        vector<int> s(n);
        int sum_s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            sum_s += s[i];
        }
        vector<bool> dp(sum_s + 1);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int w = sum_s; w - s[i] >= 0; --w) {
                dp[w] = dp[w] || dp[w - s[i]];
            }
        }
        int ans = 2e9;
        for (int i = 0; i <= sum_s; ++i) {
            if (dp[i]) {
                ans = min(ans, max((i + w - 1) / w, (sum_s - i + f - 1) / f));
            }
        }
        cout << ans << "n";
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*75*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*314*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*37*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")
[1862G - The Great Equalizer](../problems/G._The_Great_Equalizer.md "Codeforces Round 894 (Div. 3)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Candidate Master diskoteka")

 **Tutorial**
### [1862G - The Great Equalizer](../problems/G._The_Great_Equalizer.md "Codeforces Round 894 (Div. 3)")

Let's take a look at the maximum difference between adjacent numbers in a sorted sequence. Each cycle it decreases by $1$. This helps us understand the main observation: the answer for the sequence is the maximum number in it + the maximum difference between adjacent numbers in sorted order.

To answer queries, it is sufficient to maintain these two values.

To maintain the maximum number, we will store the numbers in std::multiset. And to maintain the maximum difference, we will maintain std::multiset of differences. When replacing a number, we will remove the old number and replace the difference between it and its neighbors with the difference between the neighbors. Then we will add the new number and replace the difference between its neighbors with the difference between the added number and each of the neighbors.

All of this is implemented through working with std::multiset, which you can see, for example, in the author's solution.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        if (n == 1) {
            int q;
            scanf("%d", &q);
            while (q--) {
                int pos, val;
                scanf("%d %d", &pos, &val);
                cout << val << " ";
            }
            cout << "n";
            continue;
        }
        multiset<int> aset;
        for (int i = 0; i < n; ++i) {
            aset.insert(a[i]);
        }
        multiset<int> deltas;
        for (auto it = ++aset.begin(); it != aset.end(); ++it) {
            auto prev = it;
            --prev;
            deltas.insert(*it - *prev);
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int pos, val;
            scanf("%d %d", &pos, &val);
            auto it = aset.find(a[pos - 1]);
            auto nxt = it, prev = it;
            ++nxt; --prev;
            if (it == aset.begin()) {
                deltas.erase(deltas.find(*nxt - *it));
            } else if (it == --aset.end()) {
                deltas.erase(deltas.find(*it - *prev));
            } else {
                deltas.erase(deltas.find(*nxt - *it));
                deltas.erase(deltas.find(*it - *prev));
                deltas.insert(*nxt - *prev);
            }
            aset.erase(it);
            aset.insert(val);
            it = aset.find(val);
            nxt = it, prev = it;
            ++nxt; --prev;
            if (it == aset.begin()) {
                deltas.insert(*nxt - *it);
            } else if (it == --aset.end()) {
                deltas.insert(*it - *prev);
            } else {
                deltas.insert(*nxt - *it);
                deltas.insert(*it - *prev);
                deltas.erase(deltas.find(*nxt - *prev));
            }
            a[pos - 1] = val;
            cout << *--aset.end() + *--deltas.end() << " ";
        }
        cout << "n";
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*67*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*122*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*19*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")
