# Tutorial_(en)

Hope you enjoyed the round!

 
### [1561A - Простая странная сортировка](https://codeforces.com/contest/1561/problem/A "Codeforces Round 740 (Div. 2, основан на VK Cup 2021 - Финал (Engine))")

The described sorting algorithm is similar to [Odd-even sort](https://codeforces.com/https://en.wikipedia.org/wiki/Odd-even_sort).

In this problem, it's enough to carefully implement the process described in the problem statement. Here is one sample implementation in C++:


```cpp
#include <bits/stdc++.h>  
  
using namespace std;  
  
int main() {  
  int tt;  
  cin >> tt;  
  while (tt–) {  
    int n;  
    cin >> n;  
    vector<int> a(n);  
    for (int i = 0; i < n; i++) {  
      cin >> a[i];  
    }  
    int ans = 0;  
    while (!is_sorted(a.begin(), a.end())) {  
      for (int i = ans % 2; i + 1 < n; i += 2) {  
        if (a[i] > a[i + 1]) {  
          swap(a[i], a[i + 1]);  
        }  
      }  
      ans += 1;  
    }  
    cout << ans << endl;  
  }  
  return 0;  
}  

```
To estimate the complexity of this solution, we need to know the maximum number of iterations required to sort a permutation of length $n$. It turns out that this number is equal to exactly $n$, thus the complexity of the algorithm is $O(n^2)$. This is intuitive because the algorithm looks similar to bubble sort that requires $n$ iterations too, or you can directly check that sorting $[n, n-1, \ldots, 1]$ requires $n$ iterations and reason that "more sorted" sequences can't require more iterations than "less sorted" sequences, and $[n, n-1, \ldots, 1]$ is naturally the "least sorted" sequence of them all. For a formal proof see e.g. the linked [Wikipedia page](https://codeforces.com/https://en.wikipedia.org/wiki/Odd-even_sort). The proof also follows from the editorial of problem F in Div. 1. If you have a simpler proof, please share in comments!

 
### [1558A - Очарованные игрой](../problems/A._Charmed_by_the_Game.md "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

First of all, we don't know who served first, but there are only two options, so let's just try both and unite the sets of $k$'s we get.

Assume that Alice served first. Exactly $a+b$ games were played. If $a+b$ is even, both players served exactly $\frac{a+b}{2}$ times, and if $a+b$ is odd, Alice served one more time than Borys.

The simplest way to consider both cases is to say that Alice served $p = \lceil \frac{a+b}{2} \rceil$ times, and Borys served $q = \lfloor \frac{a+b}{2} \rfloor$ times ($\lceil t \rceil$ denotes rounding up, and $\lfloor t \rfloor$ denotes rounding down).

Let $x$ be the number of times Borys broke Alice's serve ($0 \le x \le p$), and let $y$ be the number of times Alice broke Borys' serve ($0 \le y \le q$).

In this case, the number of games Alice won is $a = (p - x) + y$, and the number of games Borys won is $b = x + (q - y)$.

We know neither $x$ nor $y$, but let's loop over $x = 0 \ldots p$. From $a = (p - x) + y$, we can calculate $y = a - (p - x)$. If $0 \le y \le q$, the values of $x$ and $y$ represent a valid scenario of the match with exactly $x + y$ breaks in total.

The case when Borys served first is handled similarly.

Analyzing the formulas further, we can find a "closed-form" solution: 

* Let $d = \lfloor \frac{\lvert a-b \rvert}{2} \rfloor$.
* If $a + b$ is even, all possible values of $k$ are $d, d + 2, d + 4, \ldots, a + b - d$.
* If $a + b$ is odd, all possible values of $k$ are $d, d + 1, d + 2, \ldots, a + b - d$.
 
### [1561C - Самый нижний уровень](https://codeforces.com/contest/1561/problem/C "Codeforces Round 740 (Div. 2, основан на VK Cup 2021 - Финал (Engine))")

Consider a single cave $i$. Suppose that the hero enters the cave with power $x$. To beat the first monster, $x$ has to be greater than $a_{i, 1}$. After that, the hero's power will increase to $x+1$, and to beat the second monster, $x+1$ has to be greater than $a_{i, 2}$. Continuing this reasoning, we can write down $k_i$ inequalities: 

* $x > a_{i, 1}$;
* $x + 1 > a_{i, 2}$;
* $x + 2 > a_{i, 3}$;
* ...
* $x + (k_i - 1) > a_{i, k_i}$.

Let $b_i = \max(a_{i, 1}, a_{i, 2} - 1, a_{i, 3} - 2, \ldots, a_{i, k_i} - (k_i - 1))$. The system of inequalities above is equivalent to a single inequality: $x > b_i$.

Thus, the hero can enter cave $i$ with power $x$ if and only if $x > b_i$, and the hero's power will increase by $k_i$.

Armed with this knowledge, can we determine the best order to visit the caves for the hero?

It turns out it's always best to enter the caves in non-decreasing order of $b_i$. Indeed, if the hero can enter cave $i$, he should always do that because entering a cave never makes things worse. If the hero enters a cave with greater $b$ right before a cave with smaller $b$, he might enter these caves in reverse order as well.

Let's sort the caves accordingly and assume $b_1 \le b_2 \le \ldots \le b_n$. What is the smallest power the hero can start the level with?

We can use the same reasoning that we used for a single cave.

Suppose the hero starts the level with power $x$. To enter the first cave, $x$ has to be greater than $b_1$. After that, the hero's power will increase to $x+k_1$, and to enter the second cave, $x+k_1$ has to be greater than $b_2$. Continuing this reasoning, we can write down $n$ inequalities: 

* $x > b_1$;
* $x + k_1 > b_2$;
* $x + k_1 + k_2 > b_3$;
* ...
* $x + \sum \limits_{i=1}^{n-1} k_i > b_n$.

Let $p = \max(b_1, b_2 - k_1, b_3 - (k_1 + k_2), \ldots, b_n - \sum \limits_{i=1}^{n-1} k_i)$. The system of inequalities above is equivalent to a single inequality: $x > p$. Thus, the answer to the problem is $p + 1$.

Alternatively, instead of solving the inequalities, one can use binary search on $x$.

 
### [1558B - Верхняя ячейка](../problems/B._Up_the_Strip.md "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

This problem was inspired by [Blogewoosh #4](https://codeforces.com/blog/entry/61501) a long time ago (Blogewoosh #8 when?).

Pretty clearly, we are facing a dynamic programming problem. Let $f(x)$ be the number of ways to move from cell $x$ to cell $1$. Then, $f(1) = 1$, $f(x) = \sum \limits_{y=1}^{x-1} f(x-y) + \sum \limits_{z=2}^{x} f(\lfloor \frac{x}{z} \rfloor)$, and $f(n)$ is the answer to the problem. However, a straightforward implementation has $O(n^2)$ time complexity and is too slow.

Let's look at the main formula for $f(x)$ again: $f(x) = \sum \limits_{y=1}^{x-1} f(x-y) + \sum \limits_{z=2}^{x} f(\lfloor \frac{x}{z} \rfloor)$.

The first sum, $\sum \limits_{y=1}^{x-1} f(x-y)$, is easy to optimize: just maintain the sum of $f_1 \ldots f_{x-1}$ and recalculate it by adding $f(x)$. This takes just $O(1)$ time per cell.

For the second sum, $\sum \limits_{z=2}^{x} f(\lfloor \frac{x}{z} \rfloor)$, note that $\lfloor \frac{x}{z} \rfloor$ can take at most $O(\sqrt{x})$ different values over $z \in [2; x]$. We can handle this sum as follows: 

* Find the sum over all $z < \sqrt{x}$ directly.
* We only need to consider $z \ge \sqrt{x}$ now. For any such value, $\lfloor \frac{x}{z} \rfloor \le \sqrt{x}$. Let's loop over a cell $c \le \sqrt{x}$, for how many different values of $z$ it's true that $c = \lfloor \frac{x}{z} \rfloor$? By definition of the floor function, $c \le \frac{x}{z} < c+1$. Solving this inequality, we get $z \in [\lfloor \frac{x}{c+1} \rfloor + 1; \lfloor \frac{x}{c} \rfloor]$. The length of this segment gives us the coefficient of $f(c)$ in the sum.

This gives us an $O(n \sqrt{n})$ solution which is enough for the subtask in Division 2.

To get a faster solution, let $S(x)$ denote the multiset of cells where we can go to from cell $x$ (this multiset contains $2x-2$ values). How is $S(x+1)$ different from $S(x)$? 

* $S(x+1)$ contains an extra occurrence of $x$ because we can subtract $1$ from $x+1$.
* $S(x+1)$ contains an extra occurrence of $1$ because we can divide $x+1$ by $x+1$.
* For each $i > 1$ that is a divisor of $x+1$, $S(x+1)$ contains an occurrence of $i$ that replaces an occurrence of $i-1$.

We don't need to maintain $S(x)$ itself, but we can maintain the sum of $f(i)$ over all $i \in S(x)$ and recalculate this sum as we go from $x$ to $x+1$. The total number of changes to $S$ is limited by the total number of divisors of all numbers from $1$ to $n$, that is, $\frac{n}{1} + \frac{n}{2} + \ldots + \frac{n}{n} = O(n \log n)$.

However, if implemented directly, we need to quickly find the divisors of each $x$, and we can only afford $O(n)$ memory due to the memory limit. We can achieve that by preparing a sieve of Eratosthenes, factorizing $x$ and generating all its divisors.

A better way is do it the reverse way: once we find $f(c)$ for some $c$, let's traverse $x = 2c, 3c, \ldots$ and add $f(c) - f(c-1)$ to $f(x)$. This way the time complexity stays $O(n \log n)$ and the memory complexity is $O(n)$.

 
### [1558C - Прелестные перевороты](../problems/C._Bottom-Tier_Reversals.md "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

First of all, consider what happens when we reverse a prefix of odd length $p$. Elements $a_{p+1}$ to $a_n$ don't move at all, and for each $i$ from $1$ to $p$, $a_i$ moves to $a_{p-i+1}$. Note that $i$ and $p-i+1$ have the same parity: therefore, no element can ever change the parity of its position. In the final sorted permutation, we need to have $a_i = i$ for all $i$: that is, the parity of each element's position must match the parity of its value.

This leads to the following necessary condition: for each $i \in [1, n]$, $a_i \bmod 2 = i \bmod 2$. If for any $i$ this doesn't hold, the permutation can not be sorted.

It turns out this condition is also sufficient.

Let's devise a procedure to sort a permutation of odd length $n$. If $a_n = n$ and $a_{n - 1} = n - 1$, we don't have to touch $a_{n-1}$ and $a_n$ ever again, and we can proceed to sorting a permutation of length $n-2$. Can we actually move $n$ and $n-1$ to their final positions with a simple sequence of steps?

Indeed we can. Here is one way to do this in exactly $5$ steps: 

* Let $a_x = n$ (note that $x$ is odd). Reverse a prefix of length $x$ to move $n$ to position $1$.
* Let $a_y = n-1$ (note that $y$ is even). Reverse a prefix of length $y-1$ to move $n$ to position $y-1$.
* Reverse a prefix of length $y+1$ to move $n-1$ to position $2$ and $n$ to position $3$.
* Reverse a prefix of length $3$ to move $n$ to position $1$ ($n-1$ stays at position $2$).
* Reverse a prefix of length $n$ to move $n$ to position $n$ and $n-1$ to position $n-1$, as desired.

We can use this procedure $\frac{n-1}{2}$ times to first move $n$ and $n-1$ to their final positions, then $n-2$ and $n-3$, and so on. This solution requires exactly $\frac{5(n-1)}{2}$ steps.

 
### [1558D - Истинные вставки](../problems/D._Top-Notch_Insertions.md "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

First of all, note that the sequence of insertions uniquely determines where each element goes. For example, for $n = 5$ and a sequence of insertions $(3, 1), (4, 1), (5, 3)$, the initial sequence $[a_1, a_2, a_3, a_4, a_5]$ is always transformed into $[a_4, a_3, a_5, a_1, a_2]$, no matter what $a_i$ are. Thus, instead of counting the initial sequences, we might count the final sequences instead.

Let the final sequence be $[b_1, b_2, \ldots, b_n]$. From its sortedness, we know that $b_i \le b_{i+1}$ for every $i \in [1; n-1]$.

Consider a single iteration $i$ of the sorting algorithm. If $a_i \ge a_{i-1}$, no insertion occurs. This actually doesn't give us any extra information: we know that $a_i$ is placed later than $a_{i-1}$ in the final sequence anyway.

What happens though if $a_i$ is inserted into position $j$?

We know that $a_i < a_j$ and also, since $j$ is the smallest index with such property, $a_i \ge a_{j-1}$. Again, a non-strict inequality doesn't give us anything. However, knowing that $a_i < a_j$ is actually important.

It turns out that we are interested in elements $a_i$ such that we have ever inserted an element right before $a_i$ during sorting. For every such element, we know that the previous element in the sorted order is strictly smaller. All other pairs of neighboring elements can either be equal, or the earlier one can be smaller.

All in all, let $c$ be the number of indices $i \in [1; n-1]$ such that $b_i < b_{i+1}$ (for all the other values of $i$, $b_i \le b_{i+1}$). How many different sequences $b$ with integers from $1$ to $n$ satisfy this? This number can be shown to be equal to $\binom{2n-1-c}{n}$.

(The proof can go as follows: for each $i$ such that $b_i \le b_{i+1}$, increase each of $b_{i+1}, b_{i+2}, \ldots, b_n$ by $1$. Now for every $i$ we have $b_i < b_{i+1}$, and the maximum possible value of an element increased to $n + (n-1-c)$. Thus, we have built a bijection from the sequences we are searching for to the sequences of $n$ distinct numbers between $1$ and $n + (n-1-c)$. The number of the latter sequences is clearly $\binom{2n-1-c}{n}$.)

How to find $c$? It can be done by going through the insertions and maintaining a balanced binary search tree of your choice. However, implementation becomes simpler if we process the insertions in reverse order.

Let's maintain a set $S$ of positions in the final sorted order that are not yet filled in. Initially, the set contains all integers from $1$ to $n$. For each insertion $(x_i, y_i)$ (in reverse order), let $p$ be the $y_i$-th smallest element of $S$, and let $q$ be the $(y_i+1)$-th smallest element of $S$. Since we insert $p$ before $q$, mark position $q$ as "a position such that we have ever inserted an element right before it" (which is important for calculating $c$). Then, erase $p$ from the set.

As a data structure that can handle finding the $k$-th smallest element, we can use a balanced binary search tree, a segment tree, or binary search over Fenwick tree (in C++ we can also use a built-in policy-based data structure).

Finally, to solve each test case in $O(m \log n)$ and not $O(n \log n)$, we can have a single data structure instance for solving all test cases, and roll back any changes we apply while solving each test case.

 
### [1558E - Нижний уровень](../problems/E._Down_Below.md "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

Let's find the smallest possible initial power with binary search. Suppose the initial power is $p$.

The main idea behind the solution is to maintain a set of caves where we have beaten all the monsters, and try to extend the set by finding "augmenting" paths.

However, we can not just go in an arbitrary unvisited cave and pretend we add it to the set: since we are not allowed to turn back, it might happen that we can not move forward anymore because we don't have enough power. It's important that we must be able to reach any cave inside the set only going through caves belonging to the set itself.

Initially, the set contains just cave $1$.

What can an augmenting path look like? 

* The path can start somewhere inside the set, go out of the set, follow a simple route visiting some new caves (and beating monsters inside them), and go back to a cave belonging to the set. For example, if caves $1$ and $2$ belong to the set, the route can look like $1 \rightarrow 3 \rightarrow 4 \rightarrow 5 \rightarrow 2$, and we can add caves $3$, $4$, and $5$ to the set.
* Alternatively, instead of going back to a cave from the set, the path might go into a cave belonging to the route. For example, if caves $1$ and $2$ belong to the set, the route can look like $1 \rightarrow 3 \rightarrow 4 \rightarrow 5 \rightarrow 6 \rightarrow 4$, and we can add caves $3$, $4$, $5$, and $6$ to the set.

How do we find any augmenting path satisfying us?

It turns out that we can use the following property. Suppose we have a path $v \rightarrow u_1 \rightarrow u_2 \rightarrow \ldots \rightarrow u_k \rightarrow x$ (where $v$ is the only cave belonging to the set) that we can follow and beat all the monsters in the caves we visit. Suppose that we have another such path $v' \rightarrow u'_1 \rightarrow u'_2 \rightarrow \ldots \rightarrow u'_{k'} \rightarrow x$. Suppose that following the former path, we arrive at $x$ with the same or higher power than following the latter path. In this case, notice that 

 $v \rightarrow u_1 \rightarrow u_2 \rightarrow \ldots \rightarrow u_k \rightarrow x \rightarrow u'_{k'} \rightarrow \ldots \rightarrow u'_1 \rightarrow v'$  is actually a valid augmenting path!Thus, we can simply use BFS or DFS to find all reachable caves. Once we find a path leading back into the set, or we find two different paths leading into the same unvisited cave, we can build an augmenting path, extend the set, and start over, until the set contains all caves (in which case we can try to decrease the initial power level $p$) or until we can not find any augmenting path (in which case we must increase $p$).

At each binary search iteration, we can have at most $n$ augmenting paths and we find each of them in $O(m)$. Thus, the time complexity of the solution is $O(nm \log{a_{max}})$.

 Tutorial is loading...