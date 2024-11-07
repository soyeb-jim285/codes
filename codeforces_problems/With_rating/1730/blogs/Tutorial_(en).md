# Tutorial_(en)


### [1730A - Planets](../problems/A._Planets.md "Codeforces Round 823 (Div. 2)")

To solve the problem, it was enough to count the number of planets with the same orbits $cnt_i$ and sum up the answers for the orbits separately. For one orbit, it is advantageous either to use the second machine once and get the cost $c$, or to use only the first one and get the cost equal to $cnt_i$.

Jury solution: [173498496](https://codeforces.com/contest/1730/submission/173498496 "Submission 173498496 by shnirelman") 

### [1730B - Meeting on the Line](../problems/B._Meeting_on_the_Line.md "Codeforces Round 823 (Div. 2)")

There are many solutions to this problem, here are 2 of them.

1) Let people be able to meet in time $T$, then they could meet in time $T + \varepsilon$, where $\varepsilon > 0$. So we can find $T$ by binary search. It remains to learn how to check whether people can meet for a specific time $T$. To do this, for the $i$-th person, find a segment of positions that he can get to in time $T$: if $T < t_i$ then this segment is empty, otherwise it is $[x_i - (T - t_i), x_i + (T - t_i)]$. Then people will be able to meet only if these segments intersect, that is, the minimum of the right borders is greater than or equal to the maximum of the left borders. In order to find the answer by the minimum $T$, you need to intersect these segments in the same way (should get a point, but due to accuracy, most likely, a segment of a very small length will turn out) and take any point of this intersection. Asymptotics is $O(n \log n)$.

2) If all $t_i$ were equal to $0$, then this would be a classical problem, the solution of which would be to find the average of the minimum and maximum coordinates of people. We can reduce our problem to this one if we replace the person ($x_i$, $t_i$) with two people: ($x_i - t_i$, $0$) and ($x_i + t_i$, $0$). Proof. Let the meeting be at the point $y$. Let $x_i \le y$. Then this person will need $t_i + y - x_i$ of time to get to her, and the two we want to replace him with — $y - x_i + t_i$ and $y - x_i - t_i$. it is easy to see that the first value is equal to the initial value, and the second is not greater than the initial value, then the maximum of these two values is equal to the initial value. The proof is similar for the case $y \le x_i$. Then for any meeting point, the time in the original problem and after the replacement does not differ, which means that such a replacement will not change the answer and it can be done. Asymptotics is $O(n)$.

binary search: [173497901](https://codeforces.com/contest/1730/submission/173497901 "Submission 173497901 by shnirelman")

classic: [173497940](https://codeforces.com/contest/1730/submission/173497940 "Submission 173497940 by shnirelman")

 
### [1730C - Minimum Notation](../problems/C._Minimum_Notation.md "Codeforces Round 823 (Div. 2)")

We leave all suffix minimums by the digits $mn_i$ (digits less than or equal to the minimum among the digits to the right of them), remove the rest and replace them with $\min{(d + 1, 9)}$ (using the described operations) and add to lexicographically minimum order on the right (due to the appropriate order of operations, this is possible). The suffix minimums $mn_i$ should be left, because no matter what digit we leave after $mn_i$, it will be no less than $mn_i$, and therefore will not improve the answer. The rest must be removed at the end with operations, since there is a number to the right less than this one, i.e. if you remove everything before it (put $mn_i$ at the current position), the answer will become less than if you leave another digit at this position.

Jury solution: [173498569](https://codeforces.com/contest/1730/submission/173498569 "Submission 173498569 by shnirelman")

 
### [1730D - Prefixes and Suffixes](../problems/D._Prefixes_and_Suffixes.md "Codeforces Round 823 (Div. 2)")

If you reflect the second string and see what happens, it is easy to see that the elements at the same positions in both strings after any action remain at the same positions relative to each other. Let's combine them into unsorted pairs and treat these pairs as single objects. Now we need to compose a palindrome from these objects. This is always possible with the help of these actions, if there is a palindrome consisting of these objects (pay attention to odd palindromes, there must be a pair of the form (a, a) in the center).

Proof of possibility:

Let's make an array of pairs, in one action we expand some prefix of this array and the elements in the pairs of this prefix are swapped. Let's prove that we can change the order of the pairs in the array as we like. We will build from the end. Let all the pairs after position $i$ already stand as we want, and now the pair that we want to place in position $i$ at position $j \leq i$. Let's do the following:

$1.$ $k = j$ — will move the pair from position $j$ to the beginning.

$2*.$ $k = 1$ — swap elements within a pair if needed (so pairs are considered unsorted).

$3.$ $k = i$ — move the pair from the beginning to position $i$.

(* the $2$ action is optional if you don't want to change the order of the elements in the pair)

With this construction, we can get any permutation of these pairs and a palindrome, if it is possible. If you divide the final palindrome into two strings and expand the second one back, you get the first string.

Example:

From the test suite from the condition:

$s_1 = \mathtt{bbcaa}$, $s_2 = \mathtt{cbaab}$, expanded $s_2 = \mathtt{baabc}$.

Couples:

$\mathtt{(b, b)}$, $\mathtt{(b, a)}$, $\mathtt{(c, a)}$, $\mathtt{(a, b)}$, $\ mathtt{(a, c)}$.

Pairs unordered:

$\mathtt{(b, b)}$, $\mathtt{(a, b)} \cdot 2$, $\mathtt{(a, c)} \cdot 2$.

Pairs in a palindrome:

$\mathtt{(a, b)}$, $\mathtt{(a, c)}$, $\mathtt{(b, b)}$, $\mathtt{(a, c)}$, $\mathtt{(a, b)}$.

Real couples:

$\mathtt{(a, b)}$, $\mathtt{(a, c)}$, $\mathtt{(b, b)}$, $\mathtt{(c, a)}$, $\mathtt{(b, a)}$.

Strings: $s_1 = \mathtt{aabcb}$ expanded $s_2 = \mathtt{bcbaa}$, $s_2 = \mathtt{aabcb}$.

!!! The pair $\mathtt{(b, b)}$ !!!

Jury solution: [173498668](https://codeforces.com/contest/1730/submission/173498668 "Submission 173498668 by shnirelman") 

### [1730E - Maximums and Minimums](../problems/E._Maximums_and_Minimums.md "Codeforces Round 823 (Div. 2)")

Let's introduce some new variables: $lge_i$ - the position of the nearest left greater or equal than $a_i$($-1$ if there is none). $rg_i$ - position of the nearest right greater than $a_i$($n$ if there is none). $ll_i$ - position of the nearest left lower than $a_i$($-1$ if there is none). $rl_i$ - position of the nearest right lower than $a_i$($n$ if there is none). All this can be calculated, for example, using a stack in $O(n)$ or using binary search and sparse table in $O(n\log n)$

Let's iterate over the position $i$ of the leftmost maximum of the good segment. Then the $i$-th element will be the maximum on the segment [l, r] if $lge_i < l \le i$ and $i \le r < rg_i$ $(1)$. For the segment to pass the test, the minimum must be a divisor of the maximum. Let's iterate over this divisor $d$ and find the number of segments where the maximum is $a_i$ and the minimum is $d$. Consider positions of occurrence of $d$ $j_1$ and $j_2$ — the nearest left and right to $i$(they can be found using two pointers). Let's find the number of segments satisfying the condition $(1)$, in which the element $j_1$ is a minimum. To do this, similar conditions must be added to $(1)$: $ll_i < l \le j_1$ and $j_1 \le r < rg_i$. Intersecting these conditions, we obtain independent segments of admissible values of the left and right boundaries of the desired segment. Multiplying their lengths, we get the number of required segments. Similarly, the number of segments satisfying $(1)$, in which $j_2$ is the minimum, is found, but in order not to count 2 times one segment, one more condition must be added: $j_1 < l$. The sum of these quantities over all $i$ and divisors of $a_i$ will give the answer to the problem.

To enumerate divisors, it is better to precompute the divisors of all numbers in $O(A\log A)$, where $A$ is the constraint on $a_i$. So the whole solution runs in $O(A\log A + nD)$, where $D$ is the maximum number of divisors.

 Jury solution: [173498009](https://codeforces.com/contest/1730/submission/173498009 "Submission 173498009 by shnirelman") 
### [1730F - Almost Sorted](../problems/F._Almost_Sorted.md "Codeforces Round 823 (Div. 2)")

Let's build a permutation $q$ from left to right. If the current prefix contains the number $i$, let's call the element $p_i$ used, otherwise — unused. Consider the smallest unused element $mn = p_j$. All elements greater than $mn + k$ must also be unused, and all elements less than $mn$ must be used. Then the current state can be described by the number $mn$ and the mask, $i$-th bit of which indicates whether the element with the value $mn + i$ is used. 

Let's solve the problem by dynamic programming: $dp[mn][mask]$ is the minimum number of inversions. We can continue building a permutation by adding the number $i$ such that $mn \le p_i \le mn + k$ and $p_i$ hasn't been used yet. New inversions can be divided into two types: those formed with indices of elements less than $mn$ (they can be counted using Fenwick tree) and those formed with indices of elements not less than $mn$ (but their number is not more than $k$).

The time complexity is $O(n \cdot 2^k \cdot k \cdot (k + \log n))$.

 Jury solution: [173498327](https://codeforces.com/contest/1730/submission/173498327 "Submission 173498327 by shnirelman")