<h1 style='text-align: center;'> D. X(or)-mas Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

'Twas the night before Christmas, and Santa's frantically setting up his new Christmas tree! There are $n$ nodes in the tree, connected by $n-1$ edges. On each edge of the tree, there's a set of Christmas lights, which can be represented by an integer in binary representation.

 ![](images/68f9ff20c3fb3b810e87ef926c20443256e2728d.png) He has $m$ elves come over and admire his tree. Each elf is assigned two nodes, $a$ and $b$, and that elf looks at all lights on the simple path between the two nodes. After this, the elf's favorite number becomes the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of the values of the lights on the edges in that path.

However, the North Pole has been recovering from a nasty bout of flu. Because of this, Santa forgot some of the configurations of lights he had put on the tree, and he has already left the North Pole! Fortunately, the elves came to the rescue, and each one told Santa what pair of nodes he was assigned $(a_i, b_i)$, as well as the parity of the number of set bits in his favorite number. In other words, he remembers whether the number of $1$'s when his favorite number is written in binary is odd or even.

Help Santa determine if it's possible that the memories are consistent, and if it is, remember what his tree looked like, and maybe you'll go down in history!

## Input

The first line contains one integer $t$ ($1 \leq t \leq 2 \cdot 10^4$) — the number of test cases. Then $t$ cases follow.

The first line of each test case contains two integers, $n$ and $m$ ($2 \leq n \leq 2 \cdot 10^5$; $1 \leq m \leq 2 \cdot 10^5$) — the size of tree and the number of elves respectively.

The next $n-1$ lines of each test case each contains three integers, $x$, $y$, and $v$ ($1 \leq x, y \leq n$; $-1 \leq v < 2^{30}$) — meaning that there's an edge between nodes $x$ and $y$. If 

* $v = -1$: Santa doesn't remember what the set of lights were on for this edge.
* $v \geq 0$: The set of lights on the edge is $v$.

The next $m$ lines of each test case each contains three integers, $a$, $b$, and $p$ ($1 \leq a, b \leq n$; $a \neq b$; $0 \leq p \leq 1$) — the nodes that the elf was assigned to, and the parity of the number of set bits in the elf's favorite number.

It is guaranteed that the sum of all $n$ and the sum of all $m$ don't exceed $2 \cdot 10^5$ each.

It is guaranteed that the given edges form a tree.

## Output

For each test case, first print either YES or NO (in any case), whether there's a tree consistent with Santa's memory or not. 

If the answer is YES, print $n-1$ lines each containing three integers: $x$, $y$, and $v$ ($1 \le x, y \le n$; $0 \le v < 2^{30}$) — the edge and the integer on that edge. The set of edges must be the same as in the input, and if the value of some edge was specified earlier, it can not change. You can print the edges in any order.

If there are multiple answers, print any.

## Example

## Input


```

4
6 5
1 2 -1
1 3 1
4 2 7
6 3 0
2 5 -1
2 3 1
2 5 0
5 6 1
6 1 1
4 5 1
5 3
1 2 -1
1 3 -1
1 4 1
4 5 -1
2 4 0
3 4 1
2 3 1
3 3
1 2 -1
1 3 -1
1 2 0
1 3 1
2 3 0
2 1
1 2 1
1 2 0

```
## Output


```

YES
1 2 0
1 3 1
2 4 7
3 6 0
2 5 0
YES
1 2 1
1 3 0
1 4 1
4 5 1
NO
NO

```
## Note

The first test case is the image in the statement.

One possible answer is assigning the value of the edge $(1, 2)$ to $5$, and the value of the edge $(2, 5)$ to $3$. This is correct because: 

* The first elf goes from node $2$ to node $3$. This elf's favorite number is $4$, so he remembers the value $1$ (as $4$ has an odd number of $1$ bits in its binary representation).
* The second elf goes from node $2$ to node $5$. This elf's favorite number is $3$, so he remembers the value $0$ (as $3$ has an even number of $1$ bits in its binary representation).
* The third elf goes from node $5$ to node $6$. This elf's favorite number is $7$, so he remembers the value $1$ (as $7$ has an odd number of $1$ bits in its binary representation).
* The fourth elf goes from node $6$ to node $1$. This elf's favorite number is $1$, so he remembers the value $1$ (as $1$ has an odd number of $1$ bits in its binary representation).
* The fifth elf goes from node $4$ to node $5$. This elf's favorite number is $4$, so he remembers the number $1$ (as $4$ has an odd number of $1$ bits in its binary representation).

## Note

 that there are other possible answers.



#### tags 

#2200 #bitmasks #dfs_and_similar #dsu #graphs #trees 