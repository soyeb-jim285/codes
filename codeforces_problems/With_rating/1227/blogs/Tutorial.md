# Tutorial


##### [1262A - Math Problem](https://codeforces.com/contest/1262/problem/A "Codeforces Round 602 (Div. 2, based on Technocup 2020 Elimination Round 3)")

Writer: [RDDCCD](https://codeforces.com/profile/RDDCCD "Master RDDCCD")

 **Tutorial**
### [1262A - Math Problem](https://codeforces.com/contest/1262/problem/A "Codeforces Round 602 (Div. 2, based on Technocup 2020 Elimination Round 3)")

Find the left most right point for all segments, call it $r_{min}$. The right most left point for all segments, call it $l_{max}$. It's easy to see that the answer is $\max(0,l_{max} - r_{min})$.

##### [1262B - Box](https://codeforces.com/contest/1262/problem/B "Codeforces Round 602 (Div. 2, based on Technocup 2020 Elimination Round 3)")

Writer: [RDDCCD](https://codeforces.com/profile/RDDCCD "Master RDDCCD")

 **Tutorial**
### [1262B - Box](https://codeforces.com/contest/1262/problem/B "Codeforces Round 602 (Div. 2, based on Technocup 2020 Elimination Round 3)")

Obviously, if $q_{i} \neq q_{i-1}$ then $p_{i} = q_{i}$. We assume $q_{0} = 0$. Other positions can be filled with the left numbers in increasing order. Then check whether the permutation is correct or not.

##### [1261A - Messy](https://codeforces.com/contest/1261/problem/A "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Writer: [RDDCCD](https://codeforces.com/profile/RDDCCD "Master RDDCCD")

 **Tutorial**Tutorial is loading...
##### [1261B1 - Optimal Subsequences (Easy Version)](https://codeforces.com/contest/1261/problem/B1 "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Writer: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1261B1 - Optimal Subsequences (Easy Version)](https://codeforces.com/contest/1261/problem/B1 "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Please, read the tutorial for the Hard Version.

##### [1261B2 - Optimal Subsequences (Hard Version)](https://codeforces.com/contest/1261/problem/B2 "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Writer: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1261B2 - Optimal Subsequences (Hard Version)](https://codeforces.com/contest/1261/problem/B2 "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Let's first solve the simplified version (Easy Version) without paying attention to the efficiency of the algorithm.

It is clear that the sum of the elements of the optimal subsequence is equal to the sum of $k$ maximal elements of the sequence $a$. Let the smallest (the $k$-th) of $k$ maximal elements be $x$. Obviously, all elements of $a$ that are greater than $x$ and several elements that are equal to $x$ will be included in the optimal subsequence. Among all the elements that are equal to $x$ you need to choose those that are located to the left. Thus, a simplified version solution might look like this:

* in order to build an optimal subsequence of length $k$, take an array $a$ and construct its copy $b$ sorted by non-increasing: $b_1 \ge b_2 \ge \dots \ge b_n$;
* let $x = b_k$;
* we take the following subsequence from $a$: all the elements $a_i > x$ and several leftmost occurrences of $a_i = x$ (you need to take such occurrences in order to get exactly $k$ elements in total).

To solve the complicated version, we note that the solution above is equivalent to sorting all elements of $a$ first of all by value (non-increasing), and secondly by position (ascending). The desired optimal subsequence is simply $k$ first elements of $a$ in this order.

To quickly process requests, we will use the opportunity to read all requests in the program, sort them by $k_j$ and process them in that order. Then, in order to answer the request $k_j$, $pos_j$ you need to take $k_j$ elements in this order and choose the $pos_j$-th from them (just in the order of indices). Thus, the problem is reduced to finding the $pos$-th element in a set, where only elements are added. This can be solved using a wide range of data structures (a tree of segments, a Fenwick tree, even sqrt-compositions), and using a non-standard tree built into g++ that supports the operation "quickly find the $pos$ th element of a set". Below is the solution code:


```cpp
#include <bits/stdc++.h>  
  
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>  
  
using namespace std;  
using namespace __gnu_pbds;  
  
#define forn(i, n) for (int i = 0; i < int(n); i++)  
  
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;  
  
int main() {  
    int n;  
    cin >> n;      
  
    vector<int> a(n);  
    vector<pair<int,int>> b;  
    forn(i, n) {  
        cin >> a[i];  
        b.push_back({-a[i], i});  
    }  
    sort(b.begin(), b.end());  
  
    int m;  
    cin >> m;  
    vector<pair<pair<int,int>,int>> req(m);  
    forn(i, m) {  
        cin >> req[i].first.first >> req[i].first.second;  
        req[i].second = i;  
    }  
    sort(req.begin(), req.end());  
  
    vector<int> ans(m);  
    ordered_set pos;  
    int len = 0;  
    forn(i, m) {  
        while (len < req[i].first.first)  
            pos.insert(b[len++].second);  
        ans[req[i].second] = a[*pos.find_by_order(req[i].first.second - 1)];  
    }  
  
    forn(i, m)  
        cout << ans[i] << endl;  
}  

```
##### [1261C - Arson In Berland Forest](https://codeforces.com/contest/1261/problem/C "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Writers: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1261C - Arson In Berland Forest](https://codeforces.com/contest/1261/problem/C "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Let's note that if there is a possible configuration in which the forest burnt $T$ minutes then there is a configuration when the forest burnt $T - 1$ minutes. So we can binary search the answer.

Now we need to check the existence of the configuration for a fixed time $T$. Let's find all trees that can be set on fire. There are two equivalent conditions for such trees: either the square of length $2T + 1$ with a center in this cell contains only X-s or a distance between the current cell and any cell with "." (or border) is more or equal to $T$.

We can use any of the conditions. The first condition can be checked with prefix sums on 2D - we can precalculate them one time and use them to take a sum on a rectangle. The second condition can be checked by running bfs from all "."-s or borders (or from X-s which are neighboring to "."-s or to the borders) also one time before the binary search.

The second step is to check that it's possible to cover all burnt trees starting from all set-on-fire trees. We can check it either with "add value on a rectangle" (using prefix sums) since each set-on-fire tree will burn a $(2T + 1) \times (2T + 1)$ square with center in it. Or, alternatively, we can run bfs from set-on-fire trees.

Anyways, both algorithms have $O(nm)$ complexity. And, since all damaged trees are shown on the map, the answer can't be more than $\min(n, m)$. So, the total complexity is $O(nm \log(\min(n, m)))$.

##### [1261D1 - Wrong Answer on test 233 (Easy Version)](https://codeforces.com/contest/1261/problem/D1 "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Writer: [RDDCCD](https://codeforces.com/profile/RDDCCD "Master RDDCCD")

 **Tutorial**
### [1261D1 - Wrong Answer on test 233 (Easy Version)](https://codeforces.com/contest/1261/problem/D1 "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

First of all, special judge for $k = 1$, where the answer is zero.

Let $d$ be the difference between the points for latest answer suit and the previous one. An valid answer suit means $d > 0$. 

For positions satisfying $h_{i} = h_{i \space \mod \space n + 1}$, the answer for this position will not affect $d$. Assume there's $t$ positions which $h_{i} \neq h_{i \space \mod \space n + 1}$.

For a fixed position $i$ which $h_{i} \neq h_{i \space \mod \space n + 1}$, let your answer for this position is $a_{i}$ . If $a_{i} = h_{i}$, then the $d$ value will decrease by 1. We call this kind of position as a decreasing position. If $a_{i} = h_{i \space \mod \space n + 1}$, then the $d$ value increase by 1. We call this kind of position as a increasing position. Otherwise $d$ value will not be affected, we call this kind of position zero position.

Obviously the number of increasing position should be exact larger then the decreasing position. So let's enumerate the number of zero positions. We can find the answer is equal to $k^{n-t} \times \sum_{0 \leq i \leq t - 1}{[(k-2)^i \times \binom{t}{i} \times \sum_{[\frac{t-i}{2}]+1 \leq j \leq t - i}{\binom{t-i}{j}}]}$. $i$ represent the number of zero positions and $j$ represent the number of increasing positions.

The only problem is how to calculate $\sum_{[\frac{t-i}{2}]+1 \leq j \leq t - i}{\binom{t-i}{j}}$ quickly. Due to $\binom{n}{x} = \binom{n}{n-x}$, we can tell that when $t - i$ is odd, $\sum_{[\frac{t-i}{2}]+1 \leq j \leq t - i}{\binom{t-i}{j}} = 2^{t-i-1}$. Otherwise it is equal to $\frac{2^{t-i} - \binom{t-i}{\frac{t-i}{2}}}{2}$.

##### [1261D2 - Wrong Answer on test 233 (Hard Version)](https://codeforces.com/contest/1261/problem/D2 "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Writer: [RDDCCD](https://codeforces.com/profile/RDDCCD "Master RDDCCD")

 **Tutorial**
### [1261D2 - Wrong Answer on test 233 (Hard Version)](https://codeforces.com/contest/1261/problem/D2 "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

First of all, special judge for $k = 1$, where the answer is zero.

Let $d$ be the difference between the points for latest answer suit and the previous one. An valid answer suit means $d > 0$. 

For positions satisfying $h_{i} = h_{i \space \mod \space n + 1}$, the answer for this position will not affect $d$. Assume there's $t$ positions which $h_{i} \neq h_{i \space \mod \space n + 1}$.

For a fixed position $i$ which $h_{i} \neq h_{i \space \mod \space n + 1}$, let your answer for this position is $a_{i}$ . If $a_{i} = h_{i}$, then the $d$ value will decrease by 1. We call this kind of position as a decreasing position. If $a_{i} = h_{i \space \mod \space n + 1}$, then the $d$ value increase by 1. We call this kind of position as a increasing position. Otherwise $d$ value will not be affected, we call this kind of position zero position.

Obviously the number of increasing position should be exact larger then the decreasing position. So let's enumerate the number of zero positions. We can find the answer is equal to $k^{n-t} \times \sum_{0 \leq i \leq t - 1}{[(k-2)^i \times \binom{t}{i} \times \sum_{[\frac{t-i}{2}]+1 \leq j \leq t - i}{\binom{t-i}{j}}]}$. $i$ represent the number of zero positions and $j$ represent the number of increasing positions.

The only problem is how to calculate $\sum_{[\frac{t-i}{2}]+1 \leq j \leq t - i}{\binom{t-i}{j}}$ quickly. Due to $\binom{n}{x} = \binom{n}{n-x}$, we can tell that when $t - i$ is odd, $\sum_{[\frac{t-i}{2}]+1 \leq j \leq t - i}{\binom{t-i}{j}} = 2^{t-i-1}$. Otherwise it is equal to $\frac{2^{t-i} - \binom{t-i}{\frac{t-i}{2}}}{2}$.

##### [1261E - Not Same](https://codeforces.com/contest/1261/problem/E "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Writers: [nocriz](https://codeforces.com/profile/nocriz "Grandmaster nocriz"), [RDDCCD](https://codeforces.com/profile/RDDCCD "Master RDDCCD")

 **Tutorial**
### [1261E - Not Same](https://codeforces.com/contest/1261/problem/E "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

The solution can be inspired by the output format :)

First of all, sort all numbers in decreasing order. Let them be $A_{1}, A_{2} \dots , A_{n}$. We will construct the answer column by column. Let us use a set of binary string to represent a series of operations. For example $\lbrace 10,10,10,11 \rbrace$ represent operations for $\lbrace 4,1\rbrace $(invalid, however).

Then we compress the same operations in a operation set as the number of this operation occurs. For example, $\lbrace 10,10,10,11 \rbrace$ can be compressed as $\lbrace 3,1 \rbrace$ as there's three $10$ and one $11$. Note we do not care whether the operation is, we only care how many times it occurs.

Now, as we construct the answer column by column, new numbers will be added. A new number can split some elements in the compress set. For example, we add a new $1$ in $\lbrace 4,1 \rbrace$ as it becomes $\lbrace 4,1,1 \rbrace$. We can turn the operation set $\lbrace 10,10,10,11 \rbrace$ into $\lbrace 100,100,101,11 \rbrace$, while the compress set turns $\lbrace 2,1,1 \rbrace$ from $\lbrace 3,1 \rbrace$. In general, we can turn $\lbrace X \rbrace$ into $\lbrace Y , X - Y \rbrace$ uses a number $X(1 \leq Y < X)$. Special condition: $\lbrace Y \rbrace$ can keep same but use number $Y$.

Special judge for $A_{1} = 1$, thus we use one operation to erase all numbers.

Obviously the first compress set is $\lbrace A_{1} \rbrace$, represent operation set $\lbrace 1,1,1,1, \dots ,1 \rbrace$.

If $A_{1} = A_{2}$, turn the second compress set as $\lbrace 1,A_{1} - 1,1 \rbrace$, otherwise turn it as $\lbrace A_{2} , A_{1} - A_{2} \rbrace$.

Then we maintain the compress set by keeping the sum of the elements same but the number of the elements strictly increasing. For a current compress set, let $X$ be the minimal element, and $Y$ be the new number added. If $Y < X$, split $X$ into $\lbrace Y , X - Y \rbrace$. Otherwise split $X$ into $\lbrace 1 , X - 1 \rbrace$, the left number $(Y-X+1)$ can be randomly placed.

The left number can be randomly placed if and if only the sum of the elements is larger then $Y$. Obviously the sum of the elements equals to $A_{1}$ or $A_{1} + 1$. If the sum of the elements equals to $A_{1}$, then $Y \leq A_{2} < A_{1}$.

After all split operations, the compress set must be $\lbrace 1,1,1 \dots ,1 \rbrace$, which means all operation differ from each other. We can construct the final answer now in $O(n^2)$ .

##### [1261F - Xor-Set](https://codeforces.com/contest/1261/problem/F "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Writer: [nocriz](https://codeforces.com/profile/nocriz "Grandmaster nocriz")

 **Tutorial**
### [1261F - Xor-Set](https://codeforces.com/contest/1261/problem/F "Codeforces Round 602 (Div. 1, based on Technocup 2020 Elimination Round 3)")

Consider a segment tree over the interval $[0,2^{60}-1]$, a node representing a segment of length $2^n$ would represent all numbers with the first $60-n$ bits same, with all possible last n bits. In other words, the binary representation of any number in the segment would be $a_1a_2a_3\ldots a_{59-n}a_{60-n}x_1x_2x_3\ldots x_n$, where all $a_i$ and $x_i$ is either 0 or 1. $a_1$ to $a_{60-n}$ would be fixed and all $x_i$s can be arbitrarily chosen. 

We can observe that if we have two segments $A$ and $B$ in the tree, all possible numbers that equals the xor sum of a number in $A$ and a number in $B$ also forms a segment in the tree, with the length of $\max(|A|,|B|)$, and the unchanging bits is equal to the xor sum of the two segment's unchanging bits.

Using this observation we would get an $O( (n^2 \log^2 10^{18}) \log (n^2 \log^2 10^{18}))$ or $O( n^2 \log^2 10^{18}) $ algorithm, depending on the sorting method. First, we get all segments that compose the intervals in $A$ and $B$, we can get $O( n^2 \log^2 10^{18})$ resulting segments. Then we are left with evaluating the sum in the combination of segments. We can sort these segments to get the answer. This algorithm will get an MLE in practice since the number of resulting segments could easily exceed $10^8$.

To improve this algorithm, we can make another observation that when segments of different sizes are combined as described above, the smaller segment is equivalent to the ancestor of the same size as the bigger segment. Let's call all the segments in the decomposition of the input the "real" segments, and all segments with a "real" segment in the subtree as "auxiliary" segments. Then we could iterate over 60 possible values of the size of the segment, and for each value, we could iterate over the "real" segments of set $A$ and "auxiliary" segments of set $B$ and add the results to the set. We can prove that the number of both "real" and "auxiliary" segments of any size is not greater than $4n$. Thus, the solution runs at $O( (n^2 \log 10^{18}) \log (n^2 \log 10^{18}))$ or $O( n^2 \log 10^{18}) $ algorithm, depending on the sorting method.

