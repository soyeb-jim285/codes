# Tutorial_(en)


### [1573A - Countdown](https://codeforces.com/contest/1573/problem/A "Codeforces Round 743 (Div. 2)")

Let $s$ be the sum of all digits. In one operation we can decrease $s$ by at most $1$ and we are finished iff $s = 0$. This leads us to a conclusion that it is always unoptimal to decrease the number on the clock, when the least significant digit shows $0$, since it will cost us at least $9$ more operations.

Using this observation, the following strategy turns out to be optimal: 

* if the least significant digit is positive, decrease the number by $1$
* if the least significant digit equals $0$, swap it with some positive digit

Let $p$ be the number of digits that are positive and aren't the least significant digit. Our answer will be $s + p$. This can be computed in $O(n)$.

**Prepared by [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry")** 

### [1573B - Swaps](https://codeforces.com/contest/1573/problem/B "Codeforces Round 743 (Div. 2)")

Since the array $a$ has odd numbers and array $b$ has even numbers, then they will differ at the first position no matter how we perform the operations. It follows that in order to make the first array lexicographically smaller than the second one we need to make the first element of $a$ smaller than the first element of $b$. To move the $i$-th element of an array to the first position we can perform the operation on elements $i - 1$, $i - 2$, ..., $2$, $1$, which is optimal. The answer is then the minimum of $i + j - 2$ over all $a_i$, $b_j$ such that $a_i < b_j$.

Now we will think how to calculate this effectively. Let $p_i$ be the position of number $i$ in its respective sequence ($a$ for odd and $b$ for even). We will go through the numbers from biggest to smallest. Let $l$ be the position of the leftmost number in sequence $b$ that was already considered. If $i$ is even we will set $l$ to $min(l, p_i)$. If $i$ is odd we will set $answer$ to $min(answer, p_i + l)$.

Our total time complexity is then $O(n)$.

 **Prepared by [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz")** 
### [1572A - Book](../problems/A._Book.md "Codeforces Round 743 (Div. 1)")

There are two main solutions in this task.

The first solution simulates the process of reading the book. Let $r_i$ be the number of chapters that need to be understood in order to understand $i$-th chapter. We will keep this array updated during the simulation. Now we will simulate the process by keeping a set of chapters that are ready to be understood. Suppose we have just understood chapter $x$. We will update array $r$ by iterating over all chapters that require $x$ to be understood. If some chapter becomes ready to be understood, we will insert it to the set. Then, we will lowerbound on our set to the next chapter that can be understood and when we hit the end, the answer increases by one and we come back to the beginning.

The entire process runs in $O(n \log n)$.

The second solution is more graph based. We will construct a graph, where there is a directed edge from $a$ to $b$ if chapter $b$ is needed to understand chapter $a$. This edge has weight $0$ if $a > b$ and $1$ otherwise. The answer is the length of the longest weighted path in this graph incremented by $1$. If there exists a cycle we should output $-1$. If the graph is a DAG, we can use toposort and a simple DP to calculate the answer.

This solution works in $O(n)$

 **Prepared by [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry")** 
### [1572B - Xor of 3](../problems/B._Xor_of_3.md "Codeforces Round 743 (Div. 1)")

If the xor of all numbers in the array equals $1$ it is impossible to make everything equal to $0$, since the parity of all numbers doesn't change after an operation. From now on we will assume that the xor of all numbers equals $0$.

Lets consider the case when $n$ is odd. We can perform operations on positions $1, 3, ... n-4, n-2$. After this for every even $i$, $a_{i-1} = a_i$. Additionally, $a_n = a_{n-1} = a_{n-2} = 0$. Second one is true since the xor of all numbers equals $0$. Now we can perform operations on positions $n-4, n-6, ... 3, 1$. This will make the array equal to $0$.

In the case of even $n$ we will find a prefix of odd length and even xor of numbers and call the above solution on it and its respective suffix. If there is no such prefix, the solution doesn't exist. Here is a proof of it. Assume that every prefix of odd length has an odd xor. This means that $a_1 = a_n = 1$ and for every even $i < n$, $a_i = a_{i+1}$. Consider an operation on an even position $i$ (odd is analogous). We know that $a_i = a_{i+1}$ so after this operation $a_i$ and $a_{i+1}$ will be set to $a_{i+2}$. This means that after every operation for every even $i < n$, $a_i = a_{i+1}$ still holds. Thus we will never be able to make $a_1$ equal to $0$ since performing an operation on it won't change it.

Summing up, we perform no more than $n$ operations and our solution runs in $O(n)$

 **Prepared by [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz"), [Monogon](https://codeforces.com/profile/Monogon "International Grandmaster Monogon") and [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry")** Tutorial is loading... **Prepared by [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz")** Tutorial is loading... **Prepared by [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz")** 
### [1572E - Polygon](../problems/E._Polygon.md "Codeforces Round 743 (Div. 1)")

We are going to binary search the answer.

Lets say that we want to check whether we can obtain $k+1$ regions with area of at least $w$. From now on a correct cut means a cut that will cut off a region with area of a least $w$.

Lets consider some interval of vertices $(i, j)$. We will cut it off virtually using a cut from $i$ to $j$. We would like to know how many correct regions we can obtain by performing cuts only in this interval. The area next to the virtual cut is considered a leftover. Given two sets of correct cuts in this interval it's always optimal to choose the one with more cuts and if they have the same amount of cuts, the one with the bigger leftover.

This observation leads us to a dynamic programming solution. Let $dp_{i, j}$ be a pair $(r_{i, j}, l_{i, j})$ where $r_{i, j}$ means the biggest amount of regions and $l_{i, j}$ the biggest leftover we can obtain by performing cuts in the interval $(i, j)$.

To calculate this $dp$ we will iterate over all vertices $k$ such that $i < k < j$ and consider vertex $k$ as one of the vertices that are included in the leftover region. This is a simple transition from states $dp_{i, k}$ and $dp_{k, j}$. After we calculate our $dp$ state we can safely cut this interval off if $l_{i, j} \ge w$.

Iff $r_{1, n} \ge k + 1$ the answer equals at least $w$.

This solution runs in $O(n^3 \log(10^{16}))$.

 **Prepared by [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry") and [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz")** 
### [1572F - Stations](../problems/F._Stations.md "Codeforces Round 743 (Div. 1)")

We will maintain the array $b$ on a range add/sum segment tree. Queries are done then in $O(\log n)$ per query.

Now lets focus on the station rebuilds. Lets maintain an array $w$, which means how far a station can broadcast information including the fact that some stations might block the signal. When a station is rebuild in city $c_i$ we need to perform a $min$ operation on interval $(1, c_i - 1)$ with value $c_i-1$. Next we have to set $w_{c_i}$ to $g_i$. These are all changes to array $w$ that happen during a single rebuild.

Now we want to keep array $b$ up to date. We need to know what has been changed and a list of changes to array $w$ is all we need. When setting $w_{c_i}$ to $g_i$ we can add $1$ on interval $(c_i, g_i)$. This is fast enough to do with a single operation on array $b$, since we do this once for every rebuild. Lets say that $w_j$ was decreased as a result of the $min$ operation. To update array $b$ accordingly we should subtract 1 on interval $(c_i, w_j)$.

Sadly, performing a subtraction on $b$ for every value in array $w$ that has changed during the $min$ operation one by one is too slow and we can't afford it. Thankfully, we can speed this up. First, we will think how to keep array $w$ updated. We can use segment tree beats to perform the $min$ operation. Recall that during the $min$ operation we get to know what elements and how many times have changed. This is traditionally used to update the sum over interval information. Now we are going to use it in a different way. Lets say that value $r$ was decreased $p$ times in a node where we perform a tag. To keep array $b$ updated we only need subrtact $p$ from interval $(c_i, r)$.

Lets think about the complexity now. Segment tree beats with $min$ and $set$ $point$ operations run in amortized $O((n+q) \log n)$ meaning that we will perform at most this many changes on array $b$. This leads us to our total time complexity of $O((n+q) \log^2 n)$.

 **Prepared by [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry")**