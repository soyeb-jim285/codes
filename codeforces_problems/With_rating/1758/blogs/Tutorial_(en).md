# Tutorial_(en)

Thank you for participating in our contest! We hope you enjoyed it. Implementations will be added soon (when Codeforces lets authors submit solutions!).

Please let us know what you thought of the problems by voting!

[1758A - Ддввооииттссяя вв ггллааззаахх](../problems/A._SSeeeeiinngg_DDoouubbllee.md "Codeforces Round 836 (Div. 2)")

 **Hint**In a palindrome, the first and last characters are equal, the second and second last characters are equal, ...

 **Solution**
### [1758A - SSeeeeiinngg DDoouubbllee](../problems/A._SSeeeeiinngg_DDoouubbllee.md "Codeforces Round 836 (Div. 2)")

Output $s + \text{reverse}(s)$. 

It works, since each character in $s$ occurs exactly twice (once in $s$, once in $\text{reverse}(s)$), and the result is a palindrome.

 **Implementation (C++)**[182556248](https://codeforces.com/contest/1758/submission/182556248 "Посылка 182556248 от ScarletS")

 **Implementation (Java)**[182551321](https://codeforces.com/contest/1758/submission/182551321 "Посылка 182551321 от fishy15")

 **Implementation (Python)**[182551219](https://codeforces.com/contest/1758/submission/182551219 "Посылка 182551219 от manish.17")

 **Feedback*** [*37*](https://codeforces.com/data/like?action=like "I like this")





 Amazing problem
* [*212*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*23*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*6*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve :sadness:
[1758B - ИЛИ = среднее](../problems/B._XOR_=_Average.md "Codeforces Round 836 (Div. 2)")

 **Hint**Think small, then big!

 **Solution**
### [1758B - XOR = Average](../problems/B._XOR_=_Average.md "Codeforces Round 836 (Div. 2)")

Let us consider the cases when $n$ is odd and when its even. 

* $n$ is odd: We can see that printing $\underbrace{1,\dots,1}_{n\text{ times}}$ will lead to an average of $1$ and an XOR of $1$ (since $1 \oplus 1 = 0$). Similarly, you could print any integer $n$ times to pass this case.
* $n$ is even: We use a slight modification of the solution for odd $n$ here. Instead of printing the same number $n$ times, we print $1, 3, \underbrace{2, \dots, 2}_{n-2\text{ times}}$. Both the XOR and the average of $1$ and $3$ are $2$. Therefore the average of the total sequence remains $2$, and the XOR of the whole sequence is also $2$.

Note that there are other possible solutions, but the simplest one is described here. 

 **Implementation (C++)**[182734541](https://codeforces.com/contest/1758/submission/182734541 "Посылка 182734541 от ScarletS")

 **Implementation (Java)**[182551371](https://codeforces.com/contest/1758/submission/182551371 "Посылка 182551371 от fishy15")

 **Implementation (Python)**[182551107](https://codeforces.com/contest/1758/submission/182551107 "Посылка 182551107 от manish.17")

 **Video Editorial**[Video Editorial](https://codeforces.com/https://youtu.be/x2VzmWBeDag)

 **Feedback*** [*231*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*104*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*62*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*39*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve :sadness:
[1758C - Почти все - кратные](../problems/C._Almost_All_Multiples.md "Codeforces Round 836 (Div. 2)")

 **Hint**Consider the cycles in the permutation. What cycles can there be?

 **Solution**
### [1758C - Almost All Multiples](../problems/C._Almost_All_Multiples.md "Codeforces Round 836 (Div. 2)")

We start by giving the answer for $n=12$, $k=2$: $$[\color{red}{2}, \color{red}{4}, 3, \color{red}{12}, 5, 6, 7, 8, 9, 10, 11, \color{red}{1}]$$ and for $n=12$, $k=3$: $$[\color{red}{3}, 2, \color{red}{6}, 4, 5, \color{red}{12}, 7, 8, 9, 10, 11, \color{red}{1}].$$

As you can see, the array is almost the identity permutation, with certain elements rotated to the left. In particular, these are the elements that you get when you find the longest sequence $a_i$ such that $x \mid a_1 \mid a_2 \mid \dots \mid n$ (recall $a \mid b$ means $a$ divides $b$). For example, $3 \mid 6 \mid 12$ and $2 \mid 4 \mid 12$. To find this longest sequence, you need to prime factorize $\frac{n}{x}$. The complexity is $\mathcal{O}(n \log n)$.

The main idea is intuitive, but the proof is rather long. We include it below.

The idea is to look at cycles in the permutation. Consider any cycle of length greater than $1$, say $c_1, c_2, \dots, c_k$ (that is, $p_{c_1}=c_2$, $p_{c_2}=c_3, \dots, p_{c_k}=c_1$). We claim that for at least one element $c_i$ of the cycle, $p_{c_i}$ is not a multiple of $c_i$.

In fact, we'll show a more general claim: for one element of the cycle $p_{c_i} < c_i$, which implies that $p_{c_i}$ cannot be a multiple of $c_i$. Indeed, let's sum $p_{c_i} - c_i$ over all elements of the cycle. This sum is $0$, because each element appears once before the $-$ sign and once afterwards. Since none of these equal $0$, it follows that at least one of these terms is negative (and at least one is positive). If $p_{c_i} - c_i < 0$, then $p_{c_i} < c_i$, as desired.

So in each cycle, we must have at least one element breaking the key claim in the problem. But this claim holds for all $1 \leq i \leq n-1$, so the only cycle we can have goes through $p_n$! Indeed, since $p_n=1$ and $p_1=x$, the cycle goes $n \to 1 \to x \to \dots \to n$. For all arrows except the first one, we $a \mid b$ to write $a \to b$, because only $p_n$ can break the condition. Since we want the permutation to be lexicographically minimal, we want the longest such chain. 

So we should find the longest sequence of numbers from $x$ to $n$, such that each number divides the previous. If there are multiple such sequences, we need to pick the one that puts smaller numbers earlier, since we want smaller elements earlier on in the sequence. To do this, we can just find the prime factorization of $\frac{n}{x}$ (it is the longest, since the primes cannot be broken up into smaller factors), sort it, and cycle it.

 **Implementation (C++)**[183029471](https://codeforces.com/contest/1758/submission/183029471 "Посылка 183029471 от ScarletS")

 **Implementation (Java)**Soon

 **Implementation (Python)**[182603684](https://codeforces.com/contest/1758/submission/182603684 "Посылка 182603684 от manish.17")

 **Video Editorial**[Video Editorial](https://codeforces.com/https://youtu.be/EMbH4E7uBAo)

 **Feedback*** [*120*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*160*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*51*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*114*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve :sadness:
[1758D - Интервал = √Суммы](../problems/D._Range_=_√Sum.md "Codeforces Round 836 (Div. 2)")

 **Hint**Try separating the even and odd cases.

 **Solution**
### [1758D - Range = √Sum](../problems/D._Range_=_√Sum.md "Codeforces Round 836 (Div. 2)")

Let us consider the cases when $n$ is odd and when its even. 

* $n$ is odd: First, we can start with the $n$ consecutive distinct numbers centered at $n$. The minimum-maximum difference is $n - 1$, and the sum is $n^2$. If we add 2 to each number, the minimum-maximum difference remains the same, and the sum increases to $n^2 + 2n$.Now, we can decrease the minimum by 1 and the increase the maximum by 1. The sum remains at $n^2 + 2n$, while the difference increases to $n + 1$. To make the sum equal $(n + 1)^2 = n^2 + 2n + 1$, we can increase the 2nd last number by 1, which we can do since we previously increased the maximum by 1. 

As an example, this sequence is followed for $n = 5$: 


	+ [3, 4, 5, 6, 7] (centered at $5$)
	+ [5, 6, 7, 8, 9] (increase by $2$)
	+ [4, 6, 7, 8, 10] (shift min/max)
	+ [4, 6, 7, 9, 10] (shift 2nd last)
* $n$ is even: We can let $[a_1, \dots, a_n] = [n / 2, n / 2 + 1, \dots, n - 1, n + 1, \dots, 3n / 2]$. The difference between the minimum and maximum is $n$, and the sum of the numbers equals $n^2$, so this is valid.

Other solutions exist, only one is described here.

 **Implementation (C++)**Soon

 **Implementation (Java)**Soon

 **Implementation (Python)**[182550901](https://codeforces.com/contest/1758/submission/182550901 "Посылка 182550901 от manish.17")

 **Video Editorial**[Video Editorial](https://codeforces.com/https://youtu.be/YgTAmaJeBhY)

 **Feedback*** [*185*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*76*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*155*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*57*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve :sadness:
[1758E - Тик-так](../problems/E._Tick,_Tock.md "Codeforces Round 836 (Div. 2)")

 **Hint**What do two clocks with assigned values on the same column tell us about their respective rows?

 **Solution**
### [1758E - Tick, Tock](../problems/E._Tick,_Tock.md "Codeforces Round 836 (Div. 2)")

Notice that a relationship between two clocks with assigned values on the grid on different rows but the same column, that is, $g_{x, z}$ and $g_{y, z}$, can be represented as $g_{y, z} \equiv g_{x, z} + d \pmod{h}$, where $0 \le d < h$. Now, for every $1 \le i \le m$, $g_{y, i} \equiv g_{x, i} + d \pmod{h}$. Using these relationships, we can create a weighted directed graph using our rows as nodes.

Obviously, no solutions exist if there are discrepancies in the graph $\pmod{h}$, no solution exists. Now, for each connected component, if there is an assigned value in one of the rows it contains, we can determine all of the other values for that column in the connected component. We can merge different connected components $i, j$ by choosing a common difference $d_{i, j}$ for these components. This needs to be done (connected components - 1) times, and there are $h$ different ways to choose a common difference when combining different components, resulting in $h^{\text{connected components} - 1}$ different ways to combine all components into one connected component.

This leaves us with columns that are fully empty, i.e., they consist $\textit{only}$ of unassigned clocks. As all rows are in one connected component at this point, assigning a clock in one empty column results in all other clocks in that column becoming assigned values too. There are $h^{\text{empty columns}}$ different ways to assign clocks to these empty columns.

Thus, overall, our solution is $h^{\text{connected components} + \text{empty columns} - 1}$.

 **Implementation (C++)**[182550042](https://codeforces.com/contest/1758/submission/182550042 "Посылка 182550042 от ScarletS")

 **Implementation (Java)**Soon

 **Implementation (Python)**[182550690](https://codeforces.com/contest/1758/submission/182550690 "Посылка 182550690 от manish.17")

 **Feedback*** [*28*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*26*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*13*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*54*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve :sadness:
[1758F - Приличное разделение](../problems/F._Decent_Division.md "Codeforces Round 836 (Div. 2)")

 **Hint**If we are modifying a point already in an interval, how can we grow/split the interval to maintain balance?

 **Solution**
### [1758F - Decent Division](../problems/F._Decent_Division.md "Codeforces Round 836 (Div. 2)")

After each update, we want to maintain the invariant that each interval is balanced, and additionally that there is a gap containing at least one zero in between each pair of consecutive intervals. Since every $\texttt{1}$ must be contained in an interval, this is equivalent to having non-empty gaps between consecutive intervals after an update.

There are several cases we need to handle. 

* Case 1: Bit $a_i$ is changed from $\texttt{0}$ to $\texttt{1}$.
	+ Case 1a: Bit $a_i$ is contained in an interval after the previous updateIf we are inside an interval, then we want to grow the interval that contains it by 2 zeros to maintain balance. If the interval containing $a_i$ is $[l, r]$, then we can expand it to $[l, r + 1]$. Since there is at least one $\texttt{0}$ after each interval, $a_{r + 1} = 0$, so this contains one of the two zeroes we need.
	
	If there is another interval $r + 2 \in [l', r']$, then increasing the right bound again by 1 would overlap with this interval. In this case, We know that $a_{r' + 1} = 0$ as well, so we can merge both intervals together into $[l, r' + 1]$ to get a total of two new zeros. $[l', r']$ was also previously balanced, so the interval is still balanced. In this case, we removed two intervals and added one interval, so a total of three operations were used.
	
	If there is no intervals where $r + 2 \in [l', r']$, then $a_{r + 2} = 0$, so we can simply expand the current interval once more to $[l, r + 2]$. One interval was removed and one interval was added, so a total of two operations were used.
	+ Case 1b: Bit $a_i$ is not contained in an interval.If there exists an interval where $i + 1 \in [i + 1, r]$, then we can expand it to $[k, r + 1]$. This interval is directly after $a_i$, so expanding it by one to the left will include an extra $\texttt{1}$. $a_{r + 1} = 0$ since it is part of the gap between two intervals, so including it balances $a_i$. One interval was removed and one interval was added, so a total of two operations were used.
	
	If there is no interval where $i + 1 \in [i + 1, r]$, then $a_{i + 1} = 0$. Therefore, we can simply add $[i, i + 1]$, which is balanced. One interval was added, so a total of one operation was used.In both cases, after adding a new interval to the set, we can merge with any adjacent intervals to the left or right. This will maintain the invariant that there is a gap between consecutive ranges as mentioned earlier. We merge at most once to the left and one to the right. Since the maximum number of operations done earlier is 3, the maximum number of operations in total is 5 in this case.
* Case 2: Bit $a_i$ is changed from $\texttt{1}$ to $\texttt{0}$. Suppose that $i \in [l, r]$. In this case, we want to somehow split the interval into two balanced portions. Now, suppose we compute the prefix sums of the balance, where $\texttt{0}$ corresponds to $-1$ and $\texttt{1}$ corresponds to $+1$. If $x$ is the first location where the prefix sum equals $-2$, then we claim that we can split the interval into $[l, x - 2]$ and $[x + 1, r]$.

To prove this, note that the balance of the empty prefix is 0, so before the prefix sum equals $-2$ for the first time, it must have gone $..., 0, -1, -2$. To have two decreases in a row, we must have $a_{x - 1} = a_x = 0$. In the interval $[l, x - 2]$, the final balance prefix sum is $0$, so the first interval is balanced. Since we changed a $\texttt{1}$ to a $\texttt{1}$ and removed two $\texttt{0}$s, the first interval being balanced implies that the second interval is balanced as well. In addition, since the original interval satisfied the separation invariant, and the new intervals are separated by two $\texttt{0}$s, the separation invariant is still satisfied.

To compute the first time when the balance prefix sum equals -2, we can use binary search on the interval using a lazy segment tree. The segment tree represents a global balance prefix sum, and we can range query the minimum balance on an interval. We can binary search for the lowest index on the interval where the minimum prefix sum is less than -2.

In this case, we removed one interval and added two new intervals, for a total of three operations.

In both cases, we use at most 5 operations in a single step, so we in total use at most $5n$ operations, which fits in our bound. In practice, this upper bound is quite loose.

Because of the binary search on the lazy segment tree, the time complexity for this solution is $O(n \log^2 n)$. Note that this can be optimized to $O(n \log n)$ by optimizing the binary search, but this was not required.

 **Implementation (C++)**[182550752](https://codeforces.com/contest/1758/submission/182550752 "Посылка 182550752 от fishy15")

 **Implementation (Python)**[182550559](https://codeforces.com/contest/1758/submission/182550559 "Посылка 182550559 от manish.17")

 **Feedback*** [*7*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*2*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*17*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*36*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve :sadness:
