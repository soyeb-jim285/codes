# Tutorial

Thank you all for participating, I hope you enjoyed the problems! You can rate the problems of the round in the corresponding spoilers.

[1798A - Showstopper](../problems/A._Showstopper.md "Codeforces Round 860 (Div. 2)")  


  **Hint 1**  For each index i, it makes no sense to perform the operation ≥2 once, since applying the operation with the same index twice does not change anything.   **Hint 2**  Condition an=max(a1,a2,…,an) is equivalent to ai≤an for all i. So for each index i there are only 2 conditions: ai≤an and bi≤bn.   **Tutorial**  
### [1798A - Showstopper](../problems/A._Showstopper.md "Codeforces Round 860 (Div. 2)")

The first solution: Fix the position of the numbers $a_n, b_n$. And for each other index $i$, let's check whether the conditions $a_i \leq a_n$ and $b_i \leq b_n$ are met. If not, swap $a_i$ and $b_i$ and check again. If the conditions are not met for some index in both variants — the answer is "No", otherwise "Yes".

The second solution: Let $M$ be the maximum of all the numbers $a_1, a_2, \ldots, a_n, b_1, b_2, \ldots, b_n$. Then if $a_n < M$ and $b_n < M$ the answer is — "No", since in the one of the arrays where the number $M$ appears after the operations, the maximum will be $M$, which is greater than $a_n$ and $b_n$. Otherwise, either $a_n = M$ or $b_n = M$. If $a_n = M$, then swap $a_n$ and $b_n$, now $b_n = M$. So the condition $b_n = \max(b_1, b_2, \ldots, b_n)$ will always be met, regardless of the numbers $b_1, b_2, \ldots, b_{n-1}$. Therefore, it would be best to put in $b_i$ the maximum of the numbers $a_i, b_i$ for each $i$. After that, it remains to check the condition for the array $a_1, a_2, \ldots, a_n$, and if it is met, the answer is —"Yes", otherwise —"No"

 **Solution**
```cpp
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(n):
        if a[i] > b[i]:
            a[i], b[i] = b[i], a[i]
    if a[-1] == max(a) and b[-1] == max(b):
        print("YES")
    else:
        print("NO")
```
 **Rate the problem*** Didnt solve 


[*69*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*511*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*137*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*43*](https://codeforces.com/data/like?action=like "I like this")
[1798B - Three Sevens](../problems/B._Three_Sevens.md "Codeforces Round 860 (Div. 2)")  


  **Hint 1**  Let the participant with the number X participate in the lottery in days i1<i2<…<ik. On what days could the participant X be chosen as the winner so as not to break the conditions?   **Hint 2**  If there are several candidates for the lottery winner on the day of i (who did not participate in the days from i+1 to m), does it matter which of them we choose as a winner?   **Tutorial**  
### [1798B - Three Sevens](../problems/B._Three_Sevens.md "Codeforces Round 860 (Div. 2)")

Let's calculate the array $last$, where $last_X$ is the last day of the lottery in which the person $X$ participated. Then the only day when $X$ could be a winner is the day $last_X$. Then on the day of $i$, only the person with $last_X = i$ can be the winner. It is also clear that if there are several such participants for the day $i$, you can choose any of them as the winner, since these participants cannot be winners on any other days. In total, we need to go through all the days, if for some day there are no participants with $last$ equal to this day, then the answer is $-1$. Otherwise, we choose any participant with $last_X = i$ as the winner on the day of $i$.

 **Solution**
```cpp
MAX = 50000
last = [0] * (MAX + 777)
for _ in range(int(input())):
    m = int(input())
    a_ = []
    for day in range(m):
        n = int(input())
        a = list(map(int, input().split()))
        for x in a:
            last[x] = day
        a_.append(a)
    ans = [-1] * m
    for day in range(m):
        for x in a_[day]:
            if last[x] == day:
                ans[day] = x
        if ans[day] == -1:
            print(-1)
            break
    else:
        print(*ans)
```
 **Rate the problem*** Didnt solve 

 
[*84*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*559*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*117*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*57*](https://codeforces.com/data/like?action=like "I like this")
[1798C - Candy Store](../problems/C._Candy_Store.md "Codeforces Round 860 (Div. 2)")  


  **Hint 1**  In which case 1 price tag is enough?   **Hint 1.1**  For any positive integers x,y,z, the statement ``x is divisible by y'' equivalent to the statement ``xz is divisible by yz'   **Hint 1.2**  Let's denote the total cost of all packs of candies for cost. Rewrite all the conditions given in the problem so that they become conditions only for the number cost. Hint1.1 will help in this.   **Hint 2**  If one price tag is enough for a set of candies, then if you remove any type of candy from this set, one price tag will still be enough. This is a reason to think about greedy.   **Tutorial**  
### [1798C - Candy Store](../problems/C._Candy_Store.md "Codeforces Round 860 (Div. 2)")

To begin with, let's understand when 1 price tag will be enough.

Let the total cost of all packs of candies be $cost$. Two conditions are imposed on $cost$:

The first condition: $cost$ must be divided by each of the numbers $b_i$, because $cost = b_i \cdot d_i$. This is equivalent to the fact that $cost$ is divided by $lcm(b_1, \ldots, b_n)$, where $lcm$ denotes the least common multiple.

The second condition: $a_i$ is divided by $d_i$. We want $cost$ to somehow appear in this condition. Therefore, multiply both parts by $b_i$, and we get that $a_i \cdot b_i$ is divisible by $b_i \cdot d_i = cost$. That is, $a_i \cdot b_i$ is divided by $cost$. This is equivalent to $\gcd(a_1 \cdot b_1, \ldots, a_n \cdot b_n)$ is divided by $cost$.

Thus, if one price tag is enough, it is necessary that $\gcd(a_1 \cdot b_1, \ldots, a_n \cdot b_n)$ was divided by $cost$ and $cost$ was divided by $lcm(b_1, \ldots, b_n)$.

So a necessary and sufficient condition for one price tag will be "$\gcd(a_1 \cdot b_1, \ldots, a_n \cdot b_n)$ is divided by $lcm(b_1, \ldots, b_n)$".

It is not difficult to understand that if one price tag is enough for a set of candies, then if you remove any type of candy from this set, one price tag will still be enough.

This means that a simple greedy algorithm will work. Let's select the largest prefix of candies such that one price tag is enough for it, "paste" a price tag on this prefix, and repeat for the remaining candies until the array ends.

 **Solution**
```cpp
from math import gcd
 
def lcm(a, b):
  return a * b // gcd(a, b)
 
for _ in range(int(input())):
    n = int(input())
    a = []
    b = []
    for i in range(n):
       ai, bi = map(int, input().split())
       a.append(ai)
       b.append(bi)
    g = 0
    l = 1
    ans = 1
    for i in range(n):
        g = gcd(g, a[i] * b[i])
        l = lcm(l, b[i])
        if g % l:
            ans += 1
            g = a[i] * b[i]
            l = b[i]
    print(ans)
```
 **Rate the problem*** Didnt solve 

 
[*190*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*684*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*39*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*193*](https://codeforces.com/data/like?action=like "I like this")
[1798D - Shocking Arrangement](../problems/D._Shocking_Arrangement.md "Codeforces Round 860 (Div. 2)")  


  **Hint 1**  Express max1≤l≤r≤n|al+al+1+…+ar| in a simpler way.   **Hint 1.1**  Use the prefix sums of the array a.   **Hint 2**  Build the answer starting from an empty array. If you add numbers to the response so that the prefix sum is always in the half-interval (min(a),max(a)], the resulting array will fit the condition. How to do it? Remember that the sum of the array is 0.   **Tutorial**  
### [1798D - Shocking Arrangement](../problems/D._Shocking_Arrangement.md "Codeforces Round 860 (Div. 2)")

If the array consists entirely of zeros, then this is impossible, since $\max(a) - \min(a) = 0$.

Otherwise, we will put all zeros at the beginning. Now our array is without zeros.

We will add the elements into the array in order.

If now the sum of the added elements is $\leq 0$, we will take any of the remaining positive numbers as the next element. Since the sum of all the numbers is $0$, a positive number is guaranteed to be found (if there are still numbers left). 

If now the sum is $> 0$, then we will take any of the remaining negative numbers as the next element. Again, since the sum of all the numbers is $0$, a negative number is bound to be found.

Why it works:

The maximum number of the form $\lvert a_l + a_{l+1} + ... + a_r \rvert$ is the same as $maxPrefSum(a) - minPrefSum(a)$ (including $0$)

According to the structure of the algorithm, it is clear that in the resulting array $maxPrefSum \leq \max(a)$, and $minPrefSum > \min(a)$.

In total, the condition will be met.

 **Solution**
```cpp
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if max(a) == 0:
        print("No")
    else:
        print("Yes")
        prefix_sum = 0
        pos = []
        neg = []
        for x in a:
            if x >= 0:
                pos.append(x)
            else:
                neg.append(x)
        ans = []
        for _ in range(n):
            if prefix_sum <= 0:
                ans.append(pos[-1])
                pos.pop()
            else:
                ans.append(neg[-1])
                neg.pop()
            prefix_sum += ans[-1]
        print(' '.join(list(map(str, ans))))
```
 **Rate the problem*** Didnt solve 

 
[*65*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*426*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*134*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*188*](https://codeforces.com/data/like?action=like "I like this")
[1798E - Multitest Generator](../problems/E._Multitest_Generator.md "Codeforces Round 860 (Div. 2)")  


  **Hint 1**  Estimate from above the number of changes for which you can make a multitest from an arbitrary array.   **Hint 2**  How to check for each suffix whether it is a multitest by itself (without changes)?   **Hint 2.1**  This is done using one-dimensional dynamic programming by suffixes.   **Hint 3**  Let's say you want to check if an array can turn into a multitest for 1 change. Find all the elements that could potentially be changed (all the elements are such that changing them could lead to the array becoming a multitest without being it initially). For each of them, you need to determine whether it is possible to make a change that turns array into multitest. One-dimensional dynamic programming by suffixes will help to take into account all these variants of change.   **Tutorial**  
### [1798E - Multitest Generator](../problems/E._Multitest_Generator.md "Codeforces Round 860 (Div. 2)")

The first idea: you can make a multitest from any array using $2$ operations. To do this, replace the first element with $1$, and the second with $n - 2$, where $n$ is the length of the array.

It remains to learn how to determine whether it is possible to make a multitest from an array for $0$ and for $1$ change.

First let's deal with the $0$ changes. 

Question: when is the array $a_i, \ldots, a_n$ a multitest? Answer: when $a_{i+1}, \ldots, a_n$ represents exactly $a_i$ of tests written in a row.

For convenience, let's call the index $i$ good if $a_i, \ldots, a_n$ represents a certain number of tests written in a row. For all indexes, we want to find out if they are good, and if so, how many tests the corresponding suffix consists of. Denote $go_i = i + a_i + 1$. The logic is that if $i$ is the first element of a certain test, then $go_i$ is the first element of the next test. Then the index $i$ will be good if the chain $i \to go_i \to go_{go_i} \to \ldots$ ends in $n + 1$. To find out if this chain ends in $n + 1$ and if so, how many tests it consists of can be simple dynamic programming by suffixes. In total, to determine whether the suffix $a_i, \ldots, a_n$ is a multitest in itself, it is necessary to check that $i+1$ is good and its suffix consists of exactly $a_i$ tests.

Now it remains to determine whether it is possible to make a multitest for $1$ change. If the array has become a multitest after the change, then the element responsible for either the number of tests or the first element of some test has been changed.

Case one: the number of tests changes. Then the array can be made a multitest if and only if $i + 1$ is a good index.

Case two: the index after the change will become the first element of some test. We will consider "the maximum number of tests that can be achieved by changing one element" as the dynamics of the suffix. Then one change can make the suffix a multitest if the dynamics value from $i+1$ is greater than or equal to $a_i$. How to calculate this dynamics for $i+1$: The index being changed then must be one of $i+1$, $go_{i+1}$, $go_{go_{i+1}}$, $\ldots$, otherwise the test chain of $i+1$ will remain the same and the change will not affect anything. Then if $go_{i+1}, go_{go_{i+1}}, \ldots$ changes, then this change will be reflected in the dynamics value from $go_{i+1}$, through which it can be recalculated. And if $i+1$ changes, then you need to make a change so that $go_{i+1}$ is a good index (after the change). $go_{i+1}$ can become any index of $\geq i+2$ after the change. And of all these, you need to choose a good index with the maximum number of tests. This value can be maintained separately when recalculating the dynamics.

 **Solution**
```cpp
N = 300777
a = [0] * N
go = [0] * N
good_chain = [0] * N
chain_depth = [0] * N
suf_max_chain_depth = [0] * N

ans = ""
for _ in range(int(input())):
    n = int(input())
    a = [0] + list(map(int, input().split()))
    chain_depth[n + 1] = 0
    suf_max_chain_depth[n + 1] = 0
    curr_max_chain_depth = 0
    for i in range(n, 0, -1):
        go[i] = i + a[i] + 1
        if go[i] == n + 1 or (go[i] <= n and good_chain[go[i]]):
            good_chain[i] = True
        else:
            good_chain[i] = False
        chain_depth[i] = 1 + chain_depth[min(go[i], n + 1)]
        suf_max_chain_depth[i] = 1 + curr_max_chain_depth
        if go[i] <= n + 1:
            suf_max_chain_depth[i] = max(suf_max_chain_depth[i], 1 + suf_max_chain_depth[go[i]])
        if good_chain[i]:
            curr_max_chain_depth = max(curr_max_chain_depth, chain_depth[i])
    for i in range(1, n):
        if good_chain[i + 1] and chain_depth[i + 1] == a[i]:
            ans += "0 "
        elif good_chain[i + 1] or suf_max_chain_depth[i + 1] >= a[i]:
            ans += "1 "
        else:
            ans += "2 "
    ans += 'n'
print(ans)
```
 **Rate the problem*** Didnt solve 

 
[*69*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*193*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*17*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*16*](https://codeforces.com/data/like?action=like "I like this")
[1798F - Gifts from Grandfather Ahmed](../problems/F._Gifts_from_Grandfather_Ahmed.md "Codeforces Round 860 (Div. 2)")  


  **Hint 1**  Let's say the box you selected will be sent to the largest class. Then if this class has a size of s, you can send any s−1 from the available boxes there. So you can not worry about this class, and pick boxes for the rest, always having as potential options s−1 additional boxes. Plenty of room for maneuver.   **Hint 2**  The solution exists for any valid input   **Hint 3**  After Hint2 think about some specific inputs. You know, they always have a solution. This should inspire you.   **Hint 3.1**  k=2,s1=s2.   **Hint 4**  Erdős--Ginzburg--Ziv theorem   **Tutorial**  
### [1798F - Gifts from Grandfather Ahmed](../problems/F._Gifts_from_Grandfather_Ahmed.md "Codeforces Round 860 (Div. 2)")

Incredible mathematical fact: from any $2n - 1$ integers, you can choose $n$ with a sum divisible by $n$ (Erdős–Ginzburg–Ziv theorem) The proof can be found in the world wide Web. Brief idea: first prove for primes, and then prove that if true for $n = a$ and $n = b$, then true for $n = ab$.

Sort the class sizes: $s_1 \leq s_2 \leq\ldots \leq s_k$. Let's distribute the available boxes into the first $k - 1$ classes in order. Then considering the $i$ class, we have $s_i + \ldots + s_k - 1$ boxes at our disposal. $s_k\geq s_i$, which means there are at least $2\cdot s_i - 1$ boxes from which you can always allocate $s_i$ to send to the $i$ class. And for the last class, we can add a box with the necessary number of gifts ourselves to ensure divisibility.

The question remains how to allocate $s_i$ numbers with a sum divisible by $s_i$ among $2 \cdot s_i - 1$ numbers. Restrictions allow you to do this in a straight dynamics for $n^3$. $dp[i][j][k]$ — is it possible to choose $j$ among the first $i$ numbers so that their sum gives the remainder of $k$ by the required modulus. Restore of the answer is done by the classical method.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;
const int N = 210;
bool dp[N][N][N];
bool take[N][N][N];
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), s(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }
    vector<pair<int, int>> s2;
    for (int i = 0; i < k; i++) {
        s2.pb({s[i], i});
    }
    sort(all(s2));
    vector<vector<int>> ans(k);
    for (int i = 0; i < k - 1; i++) {
        int class_size = s2[i].first;
        vector<int> boxes;
        for (int _ = 0; _ < 2 * class_size - 1; _++) {
            boxes.pb(a.back());
            a.pop_back();
        }
        for (int sz = 0; sz <= class_size; sz++) {
            for (int r = 0; r < class_size; r++) {
                dp[0][sz][r] = false;
                take[0][sz][r] = false;
            }
        }
        dp[0][0][0] = true;
        dp[0][1][boxes[0] % class_size] = true;
        take[0][1][boxes[0] % class_size] = true;
        for (int j = 1; j < (int) boxes.size(); j++) {
            for (int sz = 0; sz <= class_size; sz++) {
                for (int r = 0; r < class_size; r++) {
                    dp[j][sz][r] = dp[j - 1][sz][r];
                    if (sz > 0 && dp[j - 1][sz - 1][(class_size + r - boxes[j] % class_size) % class_size]) {
                        dp[j][sz][r] = true;
                        take[j][sz][r] = true;
                    } else {
                        take[j][sz][r] = false;
                    }
                }
            }
        }
        vector<bool> used(2 * class_size - 1);
        int sz = class_size, r = 0;
        for (int j = (int) boxes.size() - 1; j >= 0; j--) {
            if (take[j][sz][r]) {
                used[j] = true;
                sz--;
                r += (class_size - boxes[j] % class_size);
                r %= class_size;
            } else {
                used[j] = false;
            }
        }
        vector<int> to_class;
        for (int j = 0; j < (int) boxes.size(); j++) {
            if (!used[j]) {
                a.pb(boxes[j]);
            } else {
                to_class.pb(boxes[j]);
            }
        }
        ans[s2[i].second] = to_class;
    }
 
    int sum = 0;
    for (auto x : a) {
        sum += x;
        sum %= (int) (a.size() + 1);
    }
    int add = (int) (a.size() + 1) - sum;
    ans[s2[k - 1].second] = a;
    ans[s2[k - 1].second].pb(add);
 
    cout << add << 'n';
    for (auto arr : ans) {
        for (auto x : arr) {
            cout << x << ' ';
        }
        cout << 'n';
    }
}
```
 **Rate the problem*** Didnt solve 

 
[*111*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*65*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*17*](https://codeforces.com/data/like?action=like "I like this")
