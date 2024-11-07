# Tutorial_(en)

I hope you guys enjoyed the contest — I hope to host another one soon :D

With that said, here are the tutorials:

 
### [1038A - Равенство](../problems/A._Equality.md "Codeforces Round 508 (Div. 2)")

First we need to find the frequencies of the first $k$ alphabets in the string. Let the minimum frequency among these frequencies be $m$. Then we cannot select $m+1$ characters of one kind, and we can definitely select $m$ characters of each kind, hence the answer is given by $\mathrm{min}$(frequency of first $k$ characters) * $k$

Overall Complexity: $O(n)$

Author's Code: [42591712](https://codeforces.com/contest/1038/submission/42591712 "Посылка 42591712 от Ashishgup")

 
### [1038B - Не взаимно простое разбиение](../problems/B._Non-Coprime_Partition.md "Codeforces Round 508 (Div. 2)")

There are many ways to solve this question. The easiest way perhaps was to note that the sum of first $n$ numbers is given by $\frac{n*(n+1) }{2}$, and one of $\frac{n}{2}$ or $\frac{n+1}{2}$ has to be an integer, suppose $k$. Then we can partition the numbers into two sets, one containing $k$ and the other containing the remaining integers, both of which will have $k$ as a common factor. 

Special Case: There is no answer for $n \le 2$

Overall Complexity: $O(n)$

Author's Code: [42591830](https://codeforces.com/contest/1038/submission/42591830 "Посылка 42591830 от Ashishgup")

 
### [1038C - Азартные игры](../problems/C._Gambling.md "Codeforces Round 508 (Div. 2)")

This problem was greedy.

First, it is obvious that both the players will try to either take their own maximum value or remove the opponent's maximum value. Hence, the arrays should be sorted and two pointers should be maintained to keep track of how many elements from each array have been counted/removed already.

In every move, if the person has a choice to either take his own value $A$ or remove his opponent's value $B$, then he will make the choice dependent on the values of $A$ and $B$. In fact, it turns out that it is optimal just to select the choice with a greater number (in case of tie any will do).

How to prove it? One can show by induction that it does the same as the dynamic programming of size $n^2$. However, there is a more nice way.

Let's say that initially each player gets $0.5$ of all numbers in his list. This way when you choose a number from your own list you add the rest $0.5$ of it to the score. And when you remove the number from opponent's list you remove the $0.5$ of it from your opponent's score. Clearly, all moves become symmetrical to both players now! So each player can make a decision just based on which of the moves is greater. 

If $A \gt B$, then he will take his number. If $A \lt B$, he will discard the opponent's number $B$. If $A=B$, he can make either of the above moves, it will not make a difference.

Complexity: $O(n \log n)$

Author's Code: [42591846](https://codeforces.com/contest/1038/submission/42591846 "Посылка 42591846 от Ashishgup")

 
### [1038D - Слизняки](../problems/D._Slime.md "Codeforces Round 508 (Div. 2)")

For every slime, its value will either be added in the final answer or subtracted. Let us give each slime a sign $+$ or $-$ to denote whether its value will be added or subtracted.

The key observation to solving the problem is that any combination of $+$ and $-$ is obtainable, except where all signs are $+$ or all are $-$ (exception n=1, where the answer is the value of the slime itself)

If the array contains a combination of non-zero positive elements and non-zero negative elements, then we can simply add all their absolute values (since we can put $+$ in front of positive-valued slimes and $-$ in front of negative-valued slimes)

However, if the array contains only positive-valued slimes, we put $-$ in front of the least valued slime and $+$ in front of all the others. Similarly, for negative-valued slimes, we put $+$ in front of minimum absolute valued slime.

It could have also been solved with DP where we check if - sign has been taken or not, and + sign has been taken or not. ($4n$ states)

Overall Complexity: $O(n)$

Author's Code: [42591882](https://codeforces.com/contest/1038/submission/42591882 "Посылка 42591882 от Ashishgup")

 
### [1038E - Наибольшее паросочетание](../problems/E._Maximum_Matching.md "Codeforces Round 508 (Div. 2)")

Create a graph with $4$ nodes $1-4$ representing the colors. Then the value of a block serves as an edge between the two colors of that block. 

Then the question reduces to finding an euler tour in the graph with the maximum sum of edges traveled. An euler tour may not exist with all the given edges, so the question is: Which edges do we remove?

One can note that there are $16$ types of edges. (Edges connecting 1 to 1, 1 to 2 and so on). There may be multiple edges of a specific type, however atmost 1 of it will be removed to form a valid euler tour. This is because if we have $2x + y$ edges between node $A$ and node $B$ where $0 \le y \le 1$, we can simply loop back and forth between $A$ and $B$ $x$ times to end up at the node we started from.

Since there are only $16$ types of edges, we can use bitmask to iterate over all the possibilities, and checking whether an euler tour exists in the graph with the marked edges removed (if there are multiple edges between node $A$ and node $B$, we remove only one edge, the one with the least value). 

Refer to author's solution/any AC codes to see implementation details. 

Overall Complexity: $O(2^{16} \times n)$

Bonus: Can you solve this question in $O(n^2)$? How about $O(n)$?

Author's Code: [42592019](https://codeforces.com/contest/1038/submission/42592019 "Посылка 42592019 от Ashishgup")

 
### [1038F - Поворот строки](../problems/F._Wrap_Around.md "Codeforces Round 508 (Div. 2)")

The idea was to solve the problem using Dynamic Programming. The constraints of the question were set low to allow even the most basic Dynamic Programming approaches to pass (see the author's solution to see an easy, but time-costly implementation).

The solution idea was to use $2n^4$ DP with 4 states: $DP[A][B][C][D]$ $\\\ $ $A$ = Current matching suffix length of string ($n$) $\\\ $ $B$ = Length of string $t$ so far ($n$) $\\\ $ $C$ = Whether string $t$ contains $s$ as a substring (non-cyclical) so far ($2$) $\\\ $ $D$ = Length of the suffix of $t$ that is a prefix of $s$ ($n^2$)

You can refer to AC codes for transitions. We may add more details by tomorrow.

You can see author's code for an unoptimised approach, and to tester's code for an optimised solution.

Overall Complexity: $O(n^4)$

Author's Code: [42592026](https://codeforces.com/contest/1038/submission/42592026 "Посылка 42592026 от Ashishgup")

Tester([cdkrot](https://codeforces.com/profile/cdkrot "Гроссмейстер cdkrot"))'s Code: [42593206](https://codeforces.com/contest/1038/submission/42593206 "Посылка 42593206 от Ashishgup")

For *O*(*n*3) or *O*(*n*2) solution, refer to [this](Tutorial_(en).md?#comment-456664) comment by [pranjal.ssh](https://codeforces.com/profile/pranjal.ssh "Международный мастер pranjal.ssh")

