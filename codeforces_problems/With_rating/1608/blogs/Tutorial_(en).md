# Tutorial_(en)

Author: [TadijaSebez](https://codeforces.com/profile/TadijaSebez "International Grandmaster TadijaSebez") 

### [1608A - Find Array](../problems/A._Find_Array.md "Codeforces Round 758 (Div.1 + Div. 2)")

Notice that x is never divisible by x−1 for x≥3, so we can output 2,3,…,n,n+1.

Author: [oversolver](https://codeforces.com/profile/oversolver "Master oversolver") 

### [1608B - Build the Permutation](../problems/B._Build_the_Permutation.md "Codeforces Round 758 (Div.1 + Div. 2)")

First, answer does not exists if a+b+2>n.

Second, answer exists if and only if |a−b|≤1.

It happens because between every two consecutive local maximums must be exactly one local minimum. And vice versa, between two consecutive minimums must be exactly one maximum. First case gives b≥a−1, second — a≥b−1, both in total gives a−1≤b≤a+1.

Lets build answer considering a≥b. Otherwise we can build inverse answer: swap a and b, and perform replace pi=n−pi+1.

Lets take a+b+2 biggest numbers (i. e. from n downto n−a−b−1) and put them consequentially, such numbers on first position and on each second position from first are less then other numbers. It gives that every number, except first and last, are local maximum or local minimum. Rest of the numbers needed to be placed before this sequence in increasing order.

Author: [TadijaSebez](https://codeforces.com/profile/TadijaSebez "International Grandmaster TadijaSebez") 

### [1608C - Game Master](../problems/C._Game_Master.md "Codeforces Round 758 (Div.1 + Div. 2)")

Let's look at the fights in the reversed order. If player x is the winner, then he won against some player y in the last fight. In (n−2)-th fight either x or y won against some player z, and so on. 

We always expand the set by adding a player that can lose against at least one player in the set, so if we can start from x and end up with the set of all players, x can win the tournament. 

If we construct a directed graph where we add an edge from player u to player v if and only if u can win against v in a fight, the problem is equivalent to finding the set of nodes from which we can reach all the other nodes. 

To reduce the number of edges to 2n−2, we can sort players descending by ai and by bi and add only edges from i-th to (i+1)-th player in these orders. 

Notice that x can win the tournament if and only if there is a path from x to the player with maximum ai. To find the set of such nodes, we can run DFS from the player with maximum ai on the graph with each edge reversed, or do two pointers technique on arrays of players sorted by ai and bi.

Author: [TadijaSebez](https://codeforces.com/profile/TadijaSebez "International Grandmaster TadijaSebez") 

### [1608D - Dominoes](../problems/D._Dominoes.md "Codeforces Round 758 (Div.1 + Div. 2)")

If domino coloring is valid we can split cells into n pairs of cells with opposite colors, so there is exactly n cells of each color. 

Let CB and CW be the number of black and the number of white cells in the input, respectively. If CB>n or CW>n, then the answer is 0. Otherwise, the number of colorings with exactly n cells of each color is \binom{2n - C_W - C_B}{n - C_W}. Unfortunately, some of these colorings are invalid, so we need to subtract them. 

If there is at least one completely white or completely black domino we can first rearrange them and easily insert multicolored dominoes in between. If all the dominoes are colored in WB or BW the coloring is valid if and only if all dominoes are colored in the same pattern. 

We have to subtract the number of colorings where each domino is multicolored and they are not all colored in the same pattern. This can be easily done by finding the number of ways to color each domino in WB or BW, multiplying these numbers and possibly subtracting the cases when all the dominoes are colored in the same pattern.

Author: [oversolver](https://codeforces.com/profile/oversolver "Master oversolver") 

### [1608E - The Cells on the Paper](../problems/E._The_Cells_on_the_Paper.md "Codeforces Round 758 (Div.1 + Div. 2)")

Rectangles in optimal answer always arranged in one of the following ways: 

1. horizontally from left to right;
2. divided by «T»: first rectangle is upper than second and third, and the second is to the left of the third;
3. rotations of previous ways.

Lets consider all four rotations and find best answer for arrangements 1 and 2. Additionally, fix the order of colors, they will be 3!=6.

Arrangement 1 can be found by binary search on k. Greedily take k leftmost points of first color and k rightmost points of third. Check if rectangles does not cross and it is enough points of seconds color between rectangles.

Arrangement 2 is binary search on k too. Take k uppermost points of first color, in remaining area take k leftmost points of second color, check if is enough points of third color in remaining area.

Considering the constant factor, in total solution works in O(36nlogn).

Bonus. Task can be solved in O(36n + nlogn). In first, sort all points once by x and once by y. Arrangement 1 can be solved by two pointers in O(n). For arrangement 2 let first (upper) rectangle be empty, and all points be divided into two noncrossed rectangles in such way that difference between sizes is minimal possible. Now lets move bottom of first rectangle and remove points of second and third colors from their rectangles keeping difference as minimum as possible. It can be achieved with linked list in O(n).

Author: [Um_nik](https://codeforces.com/profile/Um_nik "Legendary Grandmaster Um_nik") 

### [1608F - MEX counting](../problems/F._MEX_counting.md "Codeforces Round 758 (Div.1 + Div. 2)")

Let's count dp[pos][mex][big] — the number of ways to assign first pos elements in a way that:

* |MEX([a_1, a_2, \ldots, a_i]) - b_i| \le k for each i from 1 to pos.
* MEX([a_1, a_2, \ldots, a_{pos}]) = mex
* There are exactly big distinct elements among a_1, a_2, \ldots, a_{pos}, which are bigger then mex. Let's call them large.
* We don't care about the exact values of large elements, we care only about their positions and who of them is equal to who. For example, arrays [3, 3, 4, 0, 1], [4, 4, 5, 0, 1], [5, 5, 3, 0, 1] would all be equivalent. We care about the exact values of all other elements.

We only need to consider at most 2k+1 possible values of mex for each pos. Now, let's learn how to transition from pos to pos+1.

Let's say that now we are at state (pos, mex, big). Where can we transition after assigning a_{pos+1}?

There are two cases.

* MEX doesn't change.It happens when a_{pos+1} \neq mex. Then, if a_{pos+1} is among those big large elements or is less than mex, the number of large elements won't change. Otherwise, the number of large elements increases by 1 (but we don't care about its value other than it being bigger than mex).

So, we need to add (mex + big)dp[pos][mex][big] to dp[pos][mex][big], and dp[pos][mex][big] to dp[pos][mex][big+1].
* MEX becomes mex_1 > mex.It happens only when a_{pos+1} = mex, and all numbers from mex+1 to mex_1-1 appear among those big large elements. There are \frac{big!}{(big-(mex_1-mex-1))!} ways to choose their positions there, and all of them will stop being large, so there will be only big - (mex_1 - mex - 1) elements remaining.

So, we have to add \frac{big!}{(big-(mex_1-mex-1))!}\cdot dp[pos][mex][big] to dp[pos+1][mex_1][big-(mex_1-mex-1)] for all valid pos, mex, big, mex_1.

This already gives O(n^2k^2) solution, as we have n iterations and O(nk^2) transitions on each of them. However, this TLEs. So, let's try to optimize our transitions. We will process cases when MEX doesn't change as before, as it's only O(nk) transitions. So consider only transitions where MEX changes.

Note that mex + big increases exactly by one in such transitions. Also note that we have to multiply by big! when number of large elements previously was big and divide by (big - (mex_1 - mex - 1))! when the number of large elements now becomes big - (mex_1 - mex - 1).

Then let's only consider states with mex + big =  some fixed T for now, then we have transitions of sort (mex, T-mex) \to (mex_1, T+1-mex_1) with coefficients \frac{(T-mex)!}{(T+1-mex_1)!}. So, to find what we have to add to dp[pos+1][mex_1][T+1-mex_1], we have to find sum of dp[pos][mex][T-mex]\cdot (T-mex)! over all valid mex<mex_1, and to divide this sum by (T+1-mex_1)!. This is easy to do with prefix sums.

So, the final complexity is O(n^2k).

Author: [TadijaSebez](https://codeforces.com/profile/TadijaSebez "International Grandmaster TadijaSebez") 

### [1608G - Alphabetic Tree](../problems/G._Alphabetic_Tree.md "Codeforces Round 758 (Div.1 + Div. 2)")

Let's concatenate the m input strings, separated by some character not in the input, into a string S, and build the suffix array over it. If we could lexicographically compare str(u, v) to some suffix of S, we could use binary search to find the left and right boundary of suffixes that start with str(u, v) in the suffix array. 

Knowing how to find the longest common prefix of a path in the tree and a suffix of S would help us in comparing them, since we would know the first position where these string differ. 

Letters on the tree are still unrelated to the letters in concatenated string, so let's append them to S in some helpful way. Let's split the tree into chains using heavy-light decomposition and append the chains and reversed chains to the string S. This way every path in the tree can be split into O(logn) parts which are substrings of S. 

Let's build LCP array of S from it's suffix array, and then sparse table over the LCP array, to be able to answer queries for longest common prefix of two suffixes of S in O(1). With such queries we can get longest common prefix of a path and a suffix of S in O(logn) by querying LCP for O(logn) parts of the path and corresponding suffixes of S. 

Now we know how to find the range of suffixes which have str(u, v) as a prefix. Out of these suffixes we have to count only these for which first position belongs to a string with index in the set \{l, l+1, \dots, r \}. 

We can do the counting offline, sweeping through strings from the first to the last and maintaining binary indexed tree over suffix array. In iteration i we store 1 for suffixes of strings with indices 1, 2, \dots, i, and 0 for the rest. A query can be solved by taking the difference of sums on suffix array range in iteration r and in iteration l-1. 

Building suffix array can be done in O(nlog^2n), O(nlogn) or O(n) depending on the chosen algorithm, LCP array can be constructed from the suffix array in O(n) using Kasai's algorithm, while the sparse table construction works in O(nlogn) and uses O(nlogn) memory. Searching for the ranges can be done in O(qlog^2n) as described above, and the last offline sweeping part takes O((n+q)logn) time. The overall time complexity is O((n+q)log^2n), with O(nlogn) memory.

