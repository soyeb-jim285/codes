# Tutorial_(en)

Thanks for the participation!

 
### [1732A - Bestie](../problems/A._Bestie.md "Codeforces Round 830 (Div. 2)")

Let's make an important observation: gcd(n−1,n)=1gcd(n−1,n)=1 for any value of nn. Moreover, choosing i=n−1i=n−1 and i=ni=n are the cheapest operations. From this we can conclude that the answer is ≤3≤3.

Let gg be the gcdgcd of all numbers in the array. Then we have the following cases:

* If g=1g=1, then the operation can be omitted and the answer is 00,
* Otherwise, let's try the cheapest operation i=ni=n. If gcd(g,n)=1gcd(g,n)=1, then the answer is 11.
* Otherwise, let's try the next cheapest operation, ie i=n−1i=n−1. If gcd(g,n−1)=1gcd(g,n−1)=1, then the answer is 22.
* Otherwise, the answer is 33, since gcd(g,n−1,n)=1gcd(g,n−1,n)=1.
 
### [1732B - Ugu](../problems/B._Ugu.md "Codeforces Round 830 (Div. 2)")

Let's mentally imagine the following array of length $n - 1$: $a_i = 0$ if $s_i = s_{i+1}$, and $1$ otherwise. Note that if we apply the operation to the index $i$, then all the values ​​of the array $a$ do not change, except for $a_{i - 1}$. Let's look at this in more detail:

* For $i \leq j$, note that the $j$th and $(j+1)$th elements invert their value, so $a_j$ does not change.
* For $j < i - 1$, note that the $j$-th and $(j+1)$-th elements do not change their value, so $a_j$ does not change.
* For $j = i - 1$, note that the $j$th element does not change its value, but the $(j+1)$th element does, so $a_j$ will change its value.

If we look at the array $a$ for a sorted binary string, we can see that this array does not contain more than one unit (you either have a string consisting of only zeros or only ones, or it looks like this — $0000\ldots01\ldots11111$ ).

Let $s$ be the number of ones in the original array $a$. We have now shown that the answer is $\geq \max(s - 1, 0)$. In fact, if the string starts with $0$, then the answer is $\max(s - 1, 0)$, otherwise it is $s$.

Let's prove that if the string starts with $0$, then we can get the answer $\max(s - 1, 0)$ (the case with $1$ will be similar). Let's show a constructive proof using a small example $s = 0001110010$:

* Choose $i = 3$, then $s = 0000001101$,
* Choose $i = 7$, then $s = 0000000010$,
* Choose $i = 9$, then $s = 0000000001$.
 
### [1732C1 - Sheikh (Easy version)](../problems/C1._Sheikh_(Easy_version).md "Codeforces Round 830 (Div. 2)")

Note that $f(l, r) \leq f(l, r + 1)$. To prove this fact, let's see how the sum and xor change when the element $x$ is added. The sum will increase by $x$, but $xor$ cannot increase by more than $x$.

Then it was possible to use two pointers or binary search to solve the problem. If you solve the problem in the second way, then you iterate over the right boundary of the answer and look for the optimal left boundary for it by binary search. You will need $O(1)$ to find the sum on the segment and xor on the segment. To do this, you can use prefix sums and prefix xor.

 
### [1732C2 - Sheikh (Hard Version)](../problems/C2._Sheikh_(Hard_Version).md "Codeforces Round 830 (Div. 2)")

Note that $f(l, r) \leq f(l, r + 1)$. To prove this fact, let's see how the sum and xor change when the element $x$ is added. The sum will increase by $x$, but $xor$ cannot increase by more than $x$. From this we obtain that the maximum value of $f$ is reached on the entire subsegment.

Next, let's see in which case $xor$ changes exactly by $x$, because if it changes by a smaller value, then $f(l, r)$ will be strictly less than $f(l, r + 1)$. The value of $xor$ will change exactly by $x$ if all 1 bits of $x$ were zeros in the current $xor$. In fact, this means that if we consider the first $\log A + 1$ non-zero element, then at least one of the bits will occur twice, and thus the value of the function will become smaller.

Let's put all these facts together: we can remove at most $\log A + 1= 30 + 1= 31$ non-zero element from the beginning and end of the subsegment. Then let's just iterate over how many non-zero elements we remove on the prefix and suffix (their positions can be found using binary search) and using prefix sums and $xor$-s, calculate the value on this subsegment.

 
### [1732D1 - Balance (Easy version)](../problems/D1._Balance_(Easy_version).md "Codeforces Round 830 (Div. 2)")

Let's look at a stupid solution and try to improve it.

In a stupid solution, we can simply add to the set, and when answering a query, iterate over the numbers ${0, k, 2k, 3k, \ldots}$ and so on until we find the answer. This solution will take a long time if the answer is $c \cdot k$, where $c$ is large.

We will improve the solution. If a request comes to us for the first time for a given $k$, then we calculate the answer for it greedily and remember it. In the future, we will no longer check with $0$ whether there is a number in the set, but with the previous answer.

Let's count for each value $x$ how many times we can check for its presence in the set. First, we do this for $k$ such that $x$ is divisible by $k$. Secondly, the set must already contain elements ${0, k, 2k, \ldots, x - k}$, that is, $\frac{x}{k}$ numbers. Note that if $k$ is not one of the largest divisors of $x$, then $\frac{x}{k}$ becomes greater than $q$. Therefore, this solution will work quite quickly.

 
### [1732D2 - Balance (Hard version)](../problems/D2._Balance_(Hard_version).md "Codeforces Round 830 (Div. 2)")

Let's look at a stupid solution and try to improve it.

In a stupid solution, we can simply add and remove elements from the set, and when answering a query, iterate over the numbers ${0, k, 2k, 3k, \ldots}$ and so on until we find the answer. This solution will take a long time if the answer is $c \cdot k$, where $c$ is large.

We will improve the solution, first consider the solution of the problem without the removal operation. If a request comes to us for the first time for a given $k$, then we calculate the answer for it greedily and remember it. In the future, we will no longer check with $0$ whether there is a number in the set, but with the previous answer.

Now consider a variant of the problem with the delete operation. Let's set for a fixed $k$ to store all the numbers that we have removed and they are $\leq$ than the maximum answer found for this $k$. Then let's see what happens during the search for an answer operation. If set for a given $k$ is not empty, then the answer will be the minimum element from the set, otherwise we will try to improve the current maximum answer for this $k$ (that is, if it was equal to $c \cdot k$, then we will check $ c \cdot k, (c + 1) \cdot k, \ldots$).

It remains to figure out how we can recalculate these set in the case of an add/remove operation. Let's actually just remember for each value in which set it participates and we will update all of them.

Let's calculate the running time. Let's understand how many sets a given value $x$ can participate in. First, it lies in sets where $x$ is divisible by $k$. Second, if $x$ is in the set for the number $k$, then at least $\frac{x}{k}$ numbers have already been added. That is, if $x$ lies in $t$ sets and among these $k$ there are the largest divisors of $x$, then we should already have added approximately $\sum\limits_{k_i=1}^t \frac{x }{k_i}$, where $k_i$ is the $i$-th largest divisor of $x$. Since we have $q$ queries in total, the given value $x$ may not lie in a large number of sets.

 
### [1732E - Location](../problems/E._Location.md "Codeforces Round 830 (Div. 2)")

Tasks of this kind, as a rule, are solved using data structures, and this one is no exception. Since the constraints in the problem are not large enough, it is logical to think in the direction of root optimizations.

Let's divide the array into blocks of length $k$, we will have about $\frac{n}{k}$ such blocks. For each block, we want to maintain a response, i.e. a minimum value of $\frac{lcm(a_i, b_i)}{gcd(a_i, b_i)}$.

Let's see what happens with the first type of operation. If the block partially intersects with the segment of the request, then it is possible to go through this block for $O(k)$ and recalculate the answer. There are no more than two such blocks, so in total we will spend $O(k)$ on this (we neglect the running time of $\gcd$). If the block lies entirely in the segment of the request (and there can be $\frac{n}{k}$ such blocks), then you need to somehow recalculate the response more quickly.

To do this, let's precalculate the following value for each block: $answer_x$ — what will be the answer in the block if we assign the value $x$ to all numbers. Let's learn how to calculate the answer for a fixed $x$ first. To do this, let's iterate over all divisors $d$ of the number $x$ — in fact, by enumeration of this divisor, we will try to fix $\gcd$. Then note that since we want the value to minimize the value, we need to find the minimum value of $b_i$ that is divisible by $d$. And then we make $answer_x = \min(\frac{b_i}{d})$ over all such $d$. Let's note that $\gcd(b_i, x)$ may not actually be equal to $d$, but we know for sure that $\gcd(b_i, x) \geq d$, and since we want to minimize the value , then we do not do worse.

Already now we can calculate the answer for $A \log A$ inside the block, where $A$ is the maximum value. But you can do even better!

Let's note that $answer_x = min(answer_{\frac{x}{p}} \cdot p)$ where $p$ is a prime divisor of $x$, and don't forget the case when $d = x$ . This follows from the fact that all divisors of the number $x$ are contained among the divisors of numbers of the form $\frac{x}{p}$.

Let's calculate the running time and find the optimal $k$. We need to find all its divisors for each number in order to quickly find out the minimum number that is divisible by the given one inside the block — we do this in $O(n \sqrt A)$. Inside each block, our precalculation now works for $O(A \log \log A)$, that is, in total for all blocks $O(\frac{n}{k} \cdot A \log \log A)$. We answer the request for $O(k \cdot \gcd + \frac{n}{k})$. Hence we get that it is advantageous to take $k$ approximately $\sqrt n$ (we have all quantities of the same order, so we use $n$).

