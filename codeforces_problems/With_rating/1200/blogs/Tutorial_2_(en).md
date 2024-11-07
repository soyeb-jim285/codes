# Tutorial_2_(en)

The problems with Gildong (B, D, F) are by me, and Amugae (A, C, E) are by [nong](https://codeforces.com/profile/nong "Мастер nong").

 
### [1200A - Отельер](../problems/A._Hotelier.md "Codeforces Round 578 (Div. 2)")

Make an array of size 10 filled with 0. Then for each character from the input: L : Find the first position containing 0, then change it to 1. R : Find the last position containing 0, then change it to 1. 0   9 : array[x] = 0.

Time complexity: $O(n)$

 
### [1200B - Block Adventure](../problems/B._Block_Adventure.md "Codeforces Round 578 (Div. 2)")

We can easily see that it's always optimal to have as many blocks as possible in the bag before getting to the next column. Therefore, if the character is currently on the top of the $i$-th column, Gildong just needs to make $h_i$ become $max(0, h_{i+1} - k)$ by repeating the $1$-st or the $2$-nd action. In other words, we should add $h_i - max(0, h_{i+1} - k)$ blocks to the bag. Adding or subtracting one by one will lead to TLE. If there exists a situation where the bag will have negative number of blocks, the answer is NO. Otherwise the answer is YES.

Time complexity: $O(n)$ for each test case.

 
### [1200C - Круглый коридор](../problems/C._Round_Corridor.md "Codeforces Round 578 (Div. 2)")

Denote the corridor's length as $1$. Then, there is a wall at $(1, \frac{1}{n}), (1, \frac{2}{n}), \cdots, (1, \frac{n}{n}), (2, \frac{1}{m}), (2, \frac{2}{m}), \cdots (2, \frac{m}{m})$. For some value $x$, If there are walls at $(1, x)$ and $(2, x)$ at the same time, we can't move from $y$ to $z$ for $y \lt x$ and $z \gt x$. Let's call them a "dual wall."

Suppose $g = gcd(n, m)$. Then dual walls exist at $\frac{1}{g}, \frac{2}{g}, \cdots, \frac{g}{g} $. So we can make $g$ groups. We can move freely in the same group, and we can't move from one group to another group.For $x = 1$, $(1, 1), (1,2), \cdots, (1,\frac{n}{g})$ belong to group $1$, and $(1, \frac{n}{g} + 1), (1, \frac{n}{g} + 2), \cdots, (1, \frac{2n}{g})$ belong to group $2$, and so on. For $x = 2$, $(2, 1), (2, 2), \cdots, (2, \frac{m}{g})$ belong to group $1$, and $(2, \frac{m}{g} + 1), (2, \frac{m}{g} + 2), \cdots, (2, \frac{2m}{g})$ belong to group $2$, and so on.

For each query, print YES if $(sx, sy)$ and $(ex, ey)$ belong to the same group. Otherwise, print NO.

time complexity: $O(log(max(n,m)) + q)$

 
### [1200D - Белые полосы](../problems/D._White_Lines.md "Codeforces Round 578 (Div. 2)")

Let's consider a single row that contains at least one black cell. If the first appearance of a black cell is at the $l$-th column and the last appearance of a black cell is at the $r$-th column, we can determine whether it becomes a white line when a certain cell $(i, j)$ is clicked in $O(1)$, after some preprocessing. It becomes a white line if and only if a cell $(i,j)$ is clicked where the row is at $[i,i+k-1]$ and $j \le l \le r \le j+k-1$. We just need to compute $l$ and $r$ in advance.

Now let's consider all $n$ rows (not columns). First, count all rows that are already white lines before clicking. Then we count the number of white rows when the cell $(1,1)$ is clicked, by applying the above method to all rows from $1$ to $k$. Ignore the already-white rows that we counted before. So far we obtained the number of white rows when the cell $(1,1)$ is clicked. From now, we slide the window. Add the $k+1$-st row and remove the $1$-st row by applying the same method to them, and we obtain the number of white rows when the cell $(2,1)$ is clicked. We can repeat this until we calculate all $n-k+1$ cases for clicking the cells at the $1$-st column. Then we repeat the whole process for all $n-k+1$ columns.

The same process can be done for counting white columns, too. Now we know the number of white rows and white columns when each cell is clicked, so we can find the maximum value among their sums.

Time complexity: $O(n^2)$

 
### [1200E - Склеивание слов](../problems/E._Compress_Words.md "Codeforces Round 578 (Div. 2)")

Denote the words from left to right as $W_1, W_2, W_3, \cdots, W_n$.

If we define string $F(k)$ as the result of merging as described in the problem $k$ times, we can get $F(k+1)$ by the following process:

1. If length of $F(k)$ > length of $W_{k+1}$
	* Assume the length of $F(K)$ is $x$, and the length of $W_{k+1}$ is $y$. Construct the string $c = W_{k+1} + F(k)[x-y...x] $ ( * $s[x..y]$ for string $s$ is the substring from index $x$ to $y$)
	* Get the KMP failure function from string $c$.
	* We can get maximum overlapped length of $W_{k+1}$'s prefix and $F(k)$'s suffix from this function. Suppose the last element of the failure function smaller than the length of $W_{k+1}$ is $z$. Then the longest overlapped length of $F(k)$'s suffix and $W_{k+1}$'s prefix is $min(z, y)$. Let $L = min(z, y)$.
	* Then, $F(k+1) = F(k) + W_{k+1}[L+1...y]$
2. Otherwise
	* Construct $c$ as $W_{k+1}[1...x] + F(k)$. We can get $F(k+1)$ from the same process described in 1.

In this process, we can get $F(k+1)$ from $F(k)$ in time complexity $O(len(W_{k+1}))$. So, we can get $F(N)$ (the answer of this problem) in $O(len(W_1) + len(W_2) + \cdots + len(W_N))$.

 
### [1200F - Graph Traveler](../problems/F._Graph_Traveler.md "Codeforces Round 578 (Div. 2)")

Since a travel will never end, it is clear that every travel will eventually get into an infinite loop. But we should consider more than just the vertices, since $c$ could be different every time he visits the same vertex. Since the number of outgoing edges of each vertex is at most $10$, we can see a state can be reduced to $lcm(1..10) = 2520$ for each vertex. Therefore, we can think that the graph actually has $2520 \cdot n$ vertices, each with a single outgoing edge.

To simulate the travels, we just need to follow the exact process written in the description, except that $c$ should be kept in modulo $2520$. The problem is when to stop, and how to count the number of distinct vertices that are in the loop.

We can stop simulating until we find a state that we already have visited. There can be two cases when we find a visited state.

The first case is when we have not visited this state in the previous travels, i.e. this is the first travel that visits this state. We need to check all of the states after the first visit of this state and count the number of distinct vertices. Duplicated vertices can be removed simply by using a set, or more efficiently, using timestamp. Then we can apply the answer to all of the states we visited in this travel.

The second case is when the state was visited in one of the previous travels. We know that both the previous travel and the current travel will end in the same loop, so we can apply the same answer to all of the states we visited in this travel.

On a side note, the simulation can be done with recursion, but this can lead to maximum of $2520000$ recursion depth. This causes stack overflow or recursion limit excess for some languages (including Java).

Time complexity: $O(2520n + q)$

