<h1 style='text-align: center;'> C. Instant Noodles</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Wu got hungry after an intense training session, and came to a nearby store to buy his favourite instant noodles. After Wu paid for his purchase, the cashier gave him an interesting task.

You are given a bipartite graph with positive integers in all vertices of the right half. For a subset $S$ of vertices of the left half we define $N(S)$ as the set of all vertices of the right half adjacent to at least one vertex in $S$, and $f(S)$ as the sum of all numbers in vertices of $N(S)$. Find the greatest common divisor of $f(S)$ for all possible non-empty subsets $S$ (assume that GCD of empty set is $0$).

Wu is too tired after his training to solve this problem. Help him!

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 500\,000$) — the number of test cases in the given test set. Test case descriptions follow.

The first line of each case description contains two integers $n$ and $m$ ($1~\leq~n,~m~\leq~500\,000$) — the number of vertices in either half of the graph, and the number of edges respectively.

The second line contains $n$ integers $c_i$ ($1 \leq c_i \leq 10^{12}$). The $i$-th number describes the integer in the vertex $i$ of the right half of the graph.

Each of the following $m$ lines contains a pair of integers $u_i$ and $v_i$ ($1 \leq u_i, v_i \leq n$), describing an edge between the vertex $u_i$ of the left half and the vertex $v_i$ of the right half. It is guaranteed that the graph does not contain multiple edges.

Test case descriptions are separated with empty lines. The total value of $n$ across all test cases does not exceed $500\,000$, and the total value of $m$ across all test cases does not exceed $500\,000$ as well.

### Output

For each test case print a single integer — the required greatest common divisor.

## Example

### Input


```text
3
2 4
1 1
1 1
1 2
2 1
2 2

3 4
1 1 1
1 1
1 2
2 2
2 3

4 7
36 31 96 29
1 2
1 3
1 4
2 2
2 4
3 1
4 3
```
### Output


```text
2
1
12
```
## Note

The greatest common divisor of a set of integers is the largest integer $g$ such that all elements of the set are divisible by $g$.

In the first sample case vertices of the left half and vertices of the right half are pairwise connected, and $f(S)$ for any non-empty subset is $2$, thus the greatest common divisor of these values if also equal to $2$.

In the second sample case the subset $\{1\}$ in the left half is connected to vertices $\{1, 2\}$ of the right half, with the sum of numbers equal to $2$, and the subset $\{1, 2\}$ in the left half is connected to vertices $\{1, 2, 3\}$ of the right half, with the sum of numbers equal to $3$. Thus, $f(\{1\}) = 2$, $f(\{1, 2\}) = 3$, which means that the greatest common divisor of all values of $f(S)$ is $1$.



#### Tags 

#2300 #NOT OK #graphs #hashing #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_626_(Div._1,_based_on_Moscow_Open_Olympiad_in_Informatics).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
