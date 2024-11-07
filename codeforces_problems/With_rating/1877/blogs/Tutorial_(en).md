# Tutorial_(en)

[2A](../problems/A._Goals_of_Victory.md). Goals of Victory
---------------------------------------------------------------------

Author: [nandonathaniel](https://codeforces.com/profile/nandonathaniel "Candidate Master nandonathaniel")  
Developer: [nandonathaniel](https://codeforces.com/profile/nandonathaniel "Candidate Master nandonathaniel") 

 **Tutorial**
### [1877A - Goals of Victory](../problems/A._Goals_of_Victory.md "Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)")

Notice that each goal increases the efficiency of the team that scores by $1$. But it also simultaneously decreases the efficiency of the opposite team by $1$. This means, if we maintain the sum of efficiency for all teams, each goal does not change the sum. Therefore, the sum must be $0$.

In order to make the sum to be $0$, the efficiency of the missing team must be equal to the sum of efficiency of the other $n-1$ teams, multiplied by $-1$.

Time complexity for each test case: $O(n)$

[2B](https://codeforces.com/contest/1877/problem/B)/[1A](https://codeforces.com/contest/1876/problem/A). Helmets in Night Light
-------------------------------------------------------------------------------------------------------------------------------

Author: [ArvinCiu](https://codeforces.com/profile/ArvinCiu "Candidate Master ArvinCiu")  
Developer: [gansixeneh](https://codeforces.com/profile/gansixeneh "Candidate Master gansixeneh") 

 **Tutorial**
### [1876A - Helmets in Night Light](https://codeforces.com/contest/1876/problem/A "Codeforces Round 902 (Div. 1, based on COMPFEST 15 - Final Round)")

Notice that since there are $n$ residents, there must be $n$ shares.

There are two types of shares. A share directly by Pak Chanek to a resident, and a share by a resident to another resident. A share by Pak Chanek is unlimited, while a share by a resident is limited by $a_i$. So there are unlimited shares with cost $p$ and for each $i$, there are $a_i$ shares with cost $b_i$.

In the beginning, no residents are notified about the announcement, so Pak Chanek must share once to some resident in the beginning.

After that, since there are $n-1$ residents remaining, there must be $n-1$ shares. Theoretically, the lowerbound of the minimum cost is the $n-1$ cheapest shares (including Pak Chanek's shares). Turns out, there is always a strategy to use the $n-1$ cheapest shares to notify all $n$ residents after the first share by Pak Chanek.

The strategy is we share the announcement to the residents with the smallest values of $b_i$ first. Using the fact that $a_i\geq1$, we can deduce that we will always have a resident with an available share.

We can solve this using a simple sorting or a priority queue. Keep in mind about the unlimited shares with cost $p$.

Time complexity for each test case: $O(n\log n)$

[2C](../problems/C._Joyboard.md). Joyboard
-------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [gansixeneh](https://codeforces.com/profile/gansixeneh "Candidate Master gansixeneh") 

 **Tutorial**
### [1877C - Joyboard](../problems/C._Joyboard.md "Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)")

There are only a few cases. 

1. If $a_{n+1}=0$, then every value of $a_i$ is $0$. So there is only $1$ distinct value.
2. If $1\leq a_{n+1}\leq n$, then there exists an index $p$ ($p=a_{n+1}$) such that $a_i=a_{n+1}$ for all indices $p+1\leq i\leq n+1$ and $a_i=0$ for all $1\leq i\leq p$. So there are $2$ distinct values.
3. If $a_{n+1}>n$ and $a_{n+1}$ is divisible by $n$, then $a_n=0$ and all values to the left of that are also $0$. So there are $2$ distinct values.
4. If $a_{n+1}>n$ and $a_{n+1}$ is not divisible by $n$, then $1\leq a_n\leq n-1$. This is is equivalent to case 2, which means that there are $2$ distinct values from index $1$ to $n$. So in total, there are $3$ distinct values.

So the number of ways is as follows: 

* If $k=1$, there is always $1$ way, since $m\geq0$.
* If $k=2$ and $m\leq n$, there are $m$ ways.
* If $k=2$ and $m>n$, there are $n+\lfloor\frac{m-n}{n}\rfloor$.
* If $k=3$ and $m\leq n$, there are $0$ ways.
* If $k=3$ and $m>n$, there are $m-n-\lfloor\frac{m-n}{n}\rfloor$.
* If $k>3$, there are $0$ ways.

Time complexity for each test case: $O(1)$

[2D](https://codeforces.com/contest/1877/problem/D)/[1B](https://codeforces.com/contest/1876/problem/B). Effects of Anti Pimples
--------------------------------------------------------------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1876B - Effects of Anti Pimples](https://codeforces.com/contest/1876/problem/B "Codeforces Round 902 (Div. 1, based on COMPFEST 15 - Final Round)")

For some value $w$, let $f(w)$ be the number of different ways to choose the black indices such that the score is exactly $w$ and let $g(w)$ be the number of different ways to choose the black indices such that the score is at most $w$. Then $f(w) = g(w) - g(w-1)$.

Let's try to calculate $g(w)$. First, group the elements in $a$ into two groups, with group 1 containing elements with values greater than $w$ and group 2 containing elements with values not greater than $w$. Notice that the only requirement we must satisfy is to not make any group 1 element black or green and we can do anything to the group 2 elements. In order to make sure that no group 1 element is black or green, we must make sure that no black index we choose is a factor of at least one group 1 index. This means, we just need calculate some value $c$ that represents the number of different indices that is a factor at least one group 1 index, then the value of $g(w)$ is $2^{n-c}-1$.

The answer to the original problem is the sum of $f(w)\cdot w$ for all possible values $w$. However, we just care about the values $w$ such that $f(w)\neq0$, which only happens if $w$ is equal to the value of some element of $a$.

In order to calculate $g(w)$ for all desired values of $w$, we need to iterate the elements of $a$ from the biggest value to the smallest value. Each element we iterate, we iterate every index that is a factor of the index of the current element and mark those indices as group 1 while we keep track of the value of $c$.

The total number of iterations is the total number of factors for every index, which is $n\log n$.

Time Complexity: $O(n\log n)$

[2E](https://codeforces.com/contest/1877/problem/E)/[1C](https://codeforces.com/contest/1876/problem/C). Autosynthesis
----------------------------------------------------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1876C - Autosynthesis](https://codeforces.com/contest/1876/problem/C "Codeforces Round 902 (Div. 1, based on COMPFEST 15 - Final Round)")

Let's say we have coloured each element of $a$ into black or white and we want to find a sequence of operations that results in all black elements being circles and all white elements being uncircled. Notice that such a sequence exists if and only if the following holds: 

* For each black element, there must exist at least one white element with a value equal to the index of that black element. (There must be a value in $p$ that circles that black element)
* For each white element, there cannot be any white element with a value equal to the index of that black element. (There cannot be a value in $p$ that circles that white element)

Construct a directed graph of $n$ vertices and $n$ directed edges. Each edge $i$ is from vertex $i$ to vertex $a_i$. For an edge from $x$ to $y$, define $x$ as a child of $y$ and define $y$ as a parent of $x$. Notice that each vertex only has exactly one parent. This means that each connected component in the graph looks like a directed rooted tree with a cycle of arbitrary size at the root.

Let each vertex $i$ represent whether element $a_i$ is white or black. From the knowledge above, we can get the following for determining the colour of a certain vertex: 

* If it has at least one white child, then it must be black.
* If it has no white children, then it must be white.

This means we can determine the colour of a vertex once we have determined the colours of its children. Additionally, once there is at least one white child, we can guarantee the vertex to be black.

We can solve this by maintaining a queue. First, fill the queue with each vertex with no children ($0$ indegree). When we process a vertex in the queue, determine the colour using the rules above, and then decrease the indegree of its parent (as if the current processed vertex is deleted from the graph). If the indegree of the parent reaches $0$, add the parent to the queue. In particular, if the current vertex is white, we can immediately determine the colour of the parent to be black and add it to the queue as well.

The process stops once there are no vertices left with $0$ indegrees and none of the remaining vertices has a white child. Because of the special structure of the graph, once this happens, the remaining graph only contains zero or more disjoint cycles.

Let's solve each cycle independently. Notice that if a cycle is of even length, we can colour its vertices black and white alternatingly. However, if a cycle is of odd length, it is impossible to colour it.

Time complexity: $O(n)$

[2F](https://codeforces.com/contest/1877/problem/F)/[1D](https://codeforces.com/contest/1876/problem/D). Lexichromatography
---------------------------------------------------------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1876D - Lexichromatography](https://codeforces.com/contest/1876/problem/D "Codeforces Round 902 (Div. 1, based on COMPFEST 15 - Final Round)")

There are two conditions in the problem. The lexicography condition and the imbalanced subarrays condition.

Let's look at the imbalanced subarrays condition. Consider some value $k$ and consider all elements in $a$ with a value of $k$. In order to satisfy this condition, those elements must be coloured blue and red alternatingly from left to right. So for each value $k$ that is present in $a$, there are $2$ ways to colour its elements, either starting from blue or starting from red. This means, if we ignore the lexicography condition, the number of colourings is $2^c$ with $c$ representing the number of different values in $a$.

From now on, we are only considering the colourings that satisfy the imbalanced subarray condition.

Define the following: 

* $\text{less}$: the number of colourings with the blue subsequence less than the red subsequence lexicographically.
* $\text{equal}$: the number of colourings with the blue subsequence equal to the red subsequence.
* $\text{more}$: the number of colourings with the blue subsequence bigger than the red subsequence lexicographically.

We can get that $\text{less}+\text{equal}+\text{more}=2^c$. Furthermore, we can get that $\text{less}=\text{more}$ since we can always flip the colouring to get the opposite one. Therefore, $\text{less}=\frac{2^c-\text{equal}}{2}$.

Now, let's calculate the value of $\text{equal}$. Iterate the array from left to right while simultaneously maintaining both the blue and red subsequences. During the iteration, we want both subsequences to be equal. For the first element, we can colour it either red or blue, and put the value of that element into its corresponding subsequence. We iterate each element but we stop the next time both subsequences have the same length. So if we colour the first element blue, then the blue subsequence will be longer than the red one throughout this process, until both subsequences have equal lengths. For each of the next elements, there are a few cases: 

* If we have not found an element with this value before, we must put the element in the currently longer subsequence. (If we put it in the shorter subsequence it will not match with the corresponding element in the longer subsequence.
* If we have found an element with this value before, it must be the opposite colour than the previous one. This means we must put it in the shorter subsequence. If the corresponding element in the longer subsequence does not match, then $\text{equal}=0$. Otherwise, we can continue the process.

Once both subsequences have equal lengths, let's say we ignore all of the previous elements and the currently built subsequences and assume we continue iterating the array while forgetting about all things we did before. We cannot actually do this to calculate $\text{equal}$ properly, but we will get to that later. Notice that continuing the iteration now is just like how we start in the beginning. We can choose the colour of the first element and every other element after that is forced until both subsequences have the same length. We continue doing this repeatedly until the end of $a$.

If at the end of $a$, the lengths of both subsequences are different or we hit the $\text{equal}=0$ case at least once, then $\text{equal}=0$.

Otherwise, from our assumption above, we can deduce that each time we add an element when both subsequences have equal lengths, we can freely choose the colour of that element. We can split $a$ into several sections where the sections are separated by the times both subsequences have the same length. Using our assumption above, the number of colourings is $2^d$ with $d$ being the number of sections, because there are $2$ starting colours we can choose for each section.

However, as we have said before, when starting a new section, we cannot completely ignore the previous sections. Since the colouring of the elements with the same value must be alternating, two sections that have at least one common value must have the same starting colour. This means we can construct a graph of sections and connect the sections that have a common value with edges. Then, the true value of $\text{equal}$ is $2^{d'}$ with $d'$ being the number of connected components.

Time complexity: $O(n)$

[2G](https://codeforces.com/contest/1877/problem/G)/[1E](https://codeforces.com/contest/1876/problem/E). Ball-Stackable
------------------------------------------------------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**Tutorial is loading...[1F](https://codeforces.com/contest/1876/problem/F). Indefinite Clownfish
-------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1876F - Indefinite Clownfish](https://codeforces.com/contest/1876/problem/F "Codeforces Round 902 (Div. 1, based on COMPFEST 15 - Final Round)")

We want to find two disjoint subsequences (for the females and the males) such that: 

* The female subsequence contains consecutively increasing values.
* The male subsequence contains consecutively decreasing values
* The total length is exactly $k$.
* The mean values of both subsequences are the same.

For a group of consecutive values with minimum value $\text{min}$ and maximum value $\text{max}$, the mean is $\frac{\text{max}+\text{min}}{2}$. So we must make both values of $\text{max}+\text{min}$ the same.

We can obtain that since both means are equal, the two subsequences must contain at least one common value. And a common value can only occur twice in the entirety of the two subsequences.

For a way to choose the two subsequences, let $x$ be a common value of the two subsequences such that the difference in indices of its two occurences is minimum. Let $p$ and $q$ be the indices of the left and right occurences of $x$ respectively. There are two cases, either the $p$ is female and $q$ is male, or vice versa. If the $p$ is female, the following must be true: 

* To the left $p$, in decreasing indices, the chosen subsequence (the female one) has the values $x-1$, $x-2$, $x-3$, and so on.
* To the right of $q$, in increasing indices, the chosen subsequence (the male one) has the values $x-1$, $x-2$, $x-3$, and so on.

How about the values in the chosen subsequences that are bigger than $x$? Would they conflict in the indices between $p$ and $q$? Well, since we choose $x$ with the minimum difference in indices of its two occurences, then all values bigger than $x$ in the chosen subsequences that are located between $p$ and $q$ are either only from the female subsequence or only from the male subsequence. So, we only need to consider where for a fixed index that is either $p$ or $q$: 

* To the left of that index, in decreasing indices, the chosen subsequence (the male one) has the values $x+1$, $x+2$, $x+3$, and so on.
* To the right of that index, in increasing indices, the chosen subsequence (the female one) has the values $x+1$, $x+2$, $x+3$, and so on.

That means, if $p$ is female, there are two cases (either choosing the index to be $p$ or $q$). If $p$ is male, a similar thing also applies, but the roles of the values smaller than $x$ and the values bigger than $x$ are switched, so there are also two cases. So there are only four cases in total.

Notice that in each of the four cases, we can see it as having a pair of indices $(p, q)$ with the same value and having four legs of consecutive values coming out of it in four different directions. Notice that the elements in different legs can never conflict with each other. Each leg is independent.

Let's group the four legs into two groups, the two left legs and the two right legs. Next, define $\text{min}_f$ and $\text{max}_f$ as the minimum and maximum value in the female subsequence and define $\text{min}_m$ and $\text{max}_m$ as the minimum and maximum value in the male subsequence. It must hold that $\text{max}_f+\text{min}_f=\text{max}_m+\text{min}_m$. So $\text{max}_m-\text{min}_f=\text{max}_f-\text{min}_m$.

Notice that $\text{max}_m-\text{min}_f$ is the total number of elements in the two left legs and $\text{max}_f-\text{min}_m$ is the total number of elements in the two right legs if we exclude $p$ and $q$. Since we want to make the number of elements in the two groups the same, each group must contain exactly $\frac{k-2}{2}$ elements. This means if $k$ is odd, it is impossible.

We obtain that we can handle the two groups independently. We just need to make sure the number of elements in one group is exactly $\frac{k-2}{2}$. We want to minimise the value of $r-l$. This means, we want to maximise $l$ in the left group and minimise $r$ in the right group. These two tasks are equivalent, just mirrored.

To solve this, let's construct a graph using the array. Each element $a_i$ in the array has four parents: 

* The rightmost element to the left of it with value $a_i-1$.
* The rightmost element to the left of it with value $a_i+1$.
* The leftmost element to the right of it with value $a_i-1$.
* The leftmost element to the right of it with value $a_i+1$.

For each type of parent, construct the binary lifting for it so that for each element, we can get its $d$-th parent of a certain for any value of $d$ in $O(\log n)$.

Using this, in order to calculate the maximum value of $l$ of the left group, we can do a binary search to find the optimal number of elements in each of the two left legs. We do the same thing for the right group. We do this for each of the four cases to finally find the minimum value of $r-l$ for a particular pair of $(p, q)$.

We do that entire process repeatedly for all pairs of adjacent occurences of the same value.

Time complexity: $O(n\log^2n)$

[1G](https://codeforces.com/contest/1876/problem/G). Clubstep
-------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1876G - Clubstep](https://codeforces.com/contest/1876/problem/G "Codeforces Round 902 (Div. 1, based on COMPFEST 15 - Final Round)")

Let's try to solve a single query $(l,r,x)$ in $O(n)$. It is clear that in the optimal strategy, we do not want to do any attempts that die on parts to the left of $l$ or to the right of $r$. There are two cases: 

* If $a_r\geq x$, then we can ignore index $r$ and solve the query for $(l,r-1,x)$.
* If $a_r<x$, then it is optimal to do $\lceil\frac{x-a_r}{2}\rceil$ attempts that die on part $r$. This takes $r\cdot\lceil\frac{x-a_r}{2}\rceil$ seconds and will make all indices from $1$ to $r-1$ increase by $\lceil\frac{x-a_r}{2}\rceil$. After doing that, it is equivalent to ignoring index $r$ and solving the query for $(l,r-1,x-\lceil\frac{x-a_r}{2}\rceil)$.

For now, let's ignore $l$ and focus on $(r,x)$. For some pair $(r,x)$, there are two cases it can recurse into. We mainly care about the second case since it is the only one that contributes to the total time. For some pair $(r,x)$ of a query, we can turn it into $(r,x)$ where $r'$ ($r'\leq r$) is the rightmost index with $a_{r'}<x$. For some pair $(r,x)$ with $a_r<x$, we can see it as the pair recursing immediately to $(r',x-\lceil\frac{x-a_r}{2}\rceil)$ where $r'$ ($r'<r$) is the rightmost index with $a_{r'}<x-\lceil\frac{x-a_r}{2}\rceil$.

We want to maintain all important pairs $(r,x)$ that are needed to answer all queries. Two pairs with the same values of $r$ and $x$ that comes from different queries can be treated as the same pair.

Let's imagine a process to calculate all important pairs $(r,x)$. To do this, we iterate $r$ from $n$ to $1$ while maintaining all of the current important values of $x$, including the ones not bigger than $a_r$. Each iteration, we just modify the values of $x$ from the previous iteration. For each $r$, we first add new values of $x$ for all queries with this current value of $r$. Then, the important pairs $(r,x)$ for this value of $r$ are all current values of $x$ that are greater than $a_r$. And those values of $x$ are the values of $x$ which will get updated (changed into $x-\lceil\frac{x-a_r}{2}\rceil$) for the next iteration. If more than one value of $x$ updates into the same value, they merge and the number of values decreases.

Using the logic of the process above, it can be obtained that the total number of important pairs $(r,x)$ is $O(n+q\log\max(x))$.

Proof.

Notice that the number of important pairs is about equal to the number of updates to the value of $x$ in all iterations. Let's calculate the total number of updates.

Instead of looking at the values of $x$ that we maintain, let's sort those values and look at the gaps between adjacent values. For a value of $r$, the value of $a_r$ lies in one of the gaps. Then, that gap and all gaps located to the right of it in the number line will get updated. The gap that contains $a_r$ can change arbitrarily, but each gap that is to the right of that gap will have its length divided by $2$, either floored or ceilinged.

This means, each gap can only have $\log\max(x)$ updates before having a length of $1$. Then, its length can get ceilinged multiple times before getting floored to $0$. When its length becomes $0$, the two values at the endpoints of the gap will merge.

It may look like there can be many updates because a length of $1$ can be ceilinged multiple times. However, for every gap having its length divided by $2$ in an iteration, the case where a length of $1$ gets ceilinged cannot happen on two adjacent gaps, so if there are $c$ gaps updated, that particular case can only happen on $\lceil\frac{c}{2}\rceil$ gaps. That means, the total number of updates is about two times the total number of times a gap gets its length decreased, plus the total number of gaps that contains $a_r$.

Therefore, the total number of important pairs is $O(n+q\log\max(x))$. $\blacksquare$

Knowing that, we can calculate all important pairs quickly using a stack and a priority queue. The stack maintains the current values of $x$ that have already been updated at least once. The priority queue only maintains new values of $x$ that have not been updated yet. In each iteration, we only process several values at the top of the stack and at the top of the priority queue, then each of those gets pushed into the stack with their new values, without changes in their order. The total number of operations in the stack is equal to the number of important pairs, but the total number of changes in the priority queue is only equal to the number of queries. So the total complexity of this is $O(n+q(\log\max(x)+\log n))$.

While calculating all important pairs, we can simultaneously construct a tree of pairs where the parent of each pair $(r,x)$ is its corresponding pair $(r',x-\lceil\frac{x-a_r}{2}\rceil)$.

We can solve each query using a simple binary lifting in the tree, but that would be too slow since there are $O(n+q\log\max(x))$ vertices. Instead, we can do a DFS traversal from the root while maintaining a stack of the values of $r$ in the DFS recursion. Solving a query in a vertex is just doing a binary search in the stack. So the total complexity of answering all queries is $O(n+(q\log\max(x)+\log n))$.

Time complexity: $O(n+(q\log\max(x)+\log n))$

