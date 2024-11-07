# Tutorial

The problems were named after songs of my favorite musical group, Hippie Sabotage. Give them a try!

[1826A - Trust Nobody](../problems/A._Trust_Nobody.md "Codeforces Round 870 (Div. 2)")

 **Hint1**Check each number of liars independently.

 **Hint2**How to check, whether there are exactly x liars?

 **Solution**
### [1826A - Trust Nobody](../problems/A._Trust_Nobody.md "Codeforces Round 870 (Div. 2)")

Let's iterate over the number $x$ of liars in the group. Now everyone, who says $l_i > x$ is a liar, and vice versa. Let's count the actual number of liars. If those numbers match, output the answer.

Now that we've checked all possible $x$'s, we can safely output $-1$, since no number of liars is possible.

С++ Implementation: [204718333](https://codeforces.com/contest/1826/submission/204718333 "Submission 204718333 by Akulyat")

[1826B - Lunatic Never Content](../problems/B._Lunatic_Never_Content.md "Codeforces Round 870 (Div. 2)")

 **Hint1**How to solve for n=2?

 **Hint2**How to solve for n=4?

 **Solution**
### [1826B - Lunatic Never Content](../problems/B._Lunatic_Never_Content.md "Codeforces Round 870 (Div. 2)")

For the sequence to be a palindrome, it has to satisfy $b_i = b_{n - i + 1}$. In our case $b_i = a_i \pmod x$. We can rewrite the palindrome equation as $a_i \pmod x = a_{n - i + 1} \pmod x$. Moving all the terms to the left we get $a_i - a_{n - i + 1} \equiv 0 \pmod x$, which basically says $x$ divides $a_i - a_{n - i + 1}$.

Now, how to find the biggest $x$, which satisfies all such conditions? [Greatest common divisor](https://codeforces.com/https://en.wikipedia.org/wiki/Greatest_common_divisor) of course! We just need to calculate the $GCD$ of the numbers $a_i - a_{n - i + 1}$ for all $i$.

This results in a $O(n + log(10^9))$ solution, since computing the gcd of $n$ numbers up to $10^9$ takes exactly this much time.

A useful assumption here is that $GCD(x, 0) = x$ for any number $x$. This holds true for standard template library implementations. And do not forget that this function should work correctly for negative numbers too. An easy trick here is to just use the absolute value of $a_i - a_{n - i + 1}$.

С++ Implementation: [204718497](https://codeforces.com/contest/1826/submission/204718497 "Submission 204718497 by Akulyat")

[1826C - Dreaming of Freedom](../problems/C._Dreaming_of_Freedom.md "Codeforces Round 870 (Div. 2)")

 **Hint1**What is the number of options that is present in the infinite amount of rounds?

 **Hint2**Choose the smallest such number of options.

 **Hint3**How does this number and m relate to the answer?

 **Solution**
### [1826C - Dreaming of Freedom](../problems/C._Dreaming_of_Freedom.md "Codeforces Round 870 (Div. 2)")

First we need to notice, that in order to keep some amount of options indefinetely, this number has to be at least $2$ and divide $n$. Let's find the smallest such number $d$. Now, if $d \leq m$, let's always vote for the first $d$ options evenly. In the other case $(d > m)$ each round would force us to to decrease the number of remaining options, so eventually it will become one. So the answer is YES if and only if $d > m$.

Now on how to find the number $d$ fast. Since $d$ is a divisor of $n$ we can say, that $d$ is the smallest divisor of $n$ not equal to $1$.

We can find the number $d$ using different approaches. A more straightforward one, is checking all the numbers from $2$ up to $\sqrt{n}$. If no divisors found, then $n$ is prime and $d = n$. This results in a $O(t \cdot \sqrt{n})$ solution.

The solution presented before is good, but not fast enough in some languages, like Python. We've decided not to cut it off to not make the problem heavy in IO. We can optimize it via finding the smallest divisor using the [sieve of Eratosthenes](https://codeforces.com/https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes). This would result in $O(nlogn)$ or even faster precomputation and $O(1)$ to answer a test case, so the total time complexity is $O(nlogn + t)$.

С++ Implementation: [204718535](https://codeforces.com/contest/1826/submission/204718535 "Submission 204718535 by Akulyat")

[1826D - Running Miles](../problems/D._Running_Miles.md "Codeforces Round 870 (Div. 2)")

 **Hint1**What can we say about the position of the maximum elements relative to [l,r]?

 **Hint2**You can use DP, or otherwise:  
Iterate over the middle maximum element and choose [l,r] greedily.

 **Solution**
### [1826D - Running Miles](../problems/D._Running_Miles.md "Codeforces Round 870 (Div. 2)")

There is a fairly straightforward solution using DP, but I'll leave that for the comment section and present a very short and simple solution.

First we need to notice, that at two of the maximums are at the ends of $[l, r]$, otherwise we can move one of the boundaries closer to the other and improve the answer.

Using this observation we can reduce the problem to the following: choose three indices $l < m < r$, such that $b_l + b_m + b_r - (r - l)$ is maximum. 

Now, let's iterate over the middle index $m$ and rewrite the function as $b_m + (b_l + l) + (b_r - r)$. We can see, that values in the braces are pretty much independent — on of them depends only on the index $l$ and the second one depends only on the index $r$. So, for a given $m$ we can choose the numbers $l$ and $r$ greedily! To make it fast enough we can precalculate the prefix maximum for the array $b_l + l$ and the suffix maximum for array $b_r - r$. This results in a $O(n)$ time complexity solution.

С++ Implementation: [204718553](https://codeforces.com/contest/1826/submission/204718553 "Submission 204718553 by Akulyat")

[1826E - Walk the Runway](../problems/E._Walk_the_Runway.md "Codeforces Round 870 (Div. 2)")

 **Hint1**What is the relation between two models that go one after another in a show? 

 **Hint2**If you calculate the relation "model i can go before model j" somehow, how to calculate the answer?

 **Answer**Use DP on the graph.

 **Hint3**How to calculate this relation fast enough?

 **Answer**Bitsets

 **Solution**
### [1826E - Walk the Runway](../problems/E._Walk_the_Runway.md "Codeforces Round 870 (Div. 2)")

At first, let's define the relation between two models, that go one after another in the show. Their ratings must satisfy $r_{i, j} < r_{i, k}$ for all cities $i$. Now let's precompute this relations for all pairs of models naively in $O(n^2m)$, which is ok for now.

Now, we have the relations "model $i$ can go before model $j$", let's build a graph of such relations. This graph has no cycles, since the ratings are strictly increasing. Now we can build the topological sorting of this graph and compute $dp_i = $ the biggest profit, if the last model is model $i$ in $O(n^2)$.

Now, how to calculate this relation for all pairs of models fast enough? Let's process each city one by one and update the relations using bitsets! More formally, let's store a bitset of all the models, that can be before model $j$ in city $i$. If we process the models in order of increasing rating, we can update each models bitset of relations in $O(\frac{n}{64})$, so the total time complexity would be $O(\frac{n^2m}{64})$, which is fast enough.

С++ Implementation: [204718603](https://codeforces.com/contest/1826/submission/204718603 "Submission 204718603 by Akulyat")

[1826F - Fading into Fog](../problems/F._Fading_into_Fog.md "Codeforces Round 870 (Div. 2)")

 **Hint1**What happens in the general case after 2 queries?

 **Answer**There are O(n2) candidates for an answer. 

 **Hint2**Can we solve the question in 3 queries?

 **Answer**Yes!

 **Hint3**How to choose the third query, so that we don't intersect any bad candidates?

 **Solution**
### [1826F - Fading into Fog](../problems/F._Fading_into_Fog.md "Codeforces Round 870 (Div. 2)")

At first let's query two non-parallel lines. In this general case building perpendicular lines from projections and intersecting them will give us $O(n^2)$ candidates for the answer. This gives us the intuition, that 2 queries isn't enough. Also, the constraint from the statement suggests, that asking $x = 0$ and $y = 0$ will guarantee, that no two candidates are closer, than $1$ from each other, which will come in handy later.

Now let's prove we can solve the problem in 3 queries. Indeed, there will always some space between the candidates. A simple proof of that would go something like this: there are $O(n^2)$ candidates and $O(n^4)$ pairs of candidates; now we can sort the directional vectors by the angle, and there will be at least one angle of at least $\frac{2\pi}{O(n^4)}$ between some two neighbouring vectors by the pigeonhole principle, which is big enough. 

One way to choose such a line is by queriying random lines, till we find a good enough one, or query some constant amount of lines and choose the one with the biggest distance. Checking one line can be done in $O(n^2logn)$ with a simple sort. How many exactly do we need is an exercise to the reader, but it can be proven, that under the given constraints this number is $O(1)$.

Now, when we have the line, let's query it and check all the candidates in $O(n^3)$ or $O(n^2logn)$ or even $O(n^2)$. It doesn't really affect the runtime.

The total complexity is $O(n^2logn)$ per testcase.

С++ Implementation: [204718641](https://codeforces.com/contest/1826/submission/204718641 "Submission 204718641 by Akulyat")

