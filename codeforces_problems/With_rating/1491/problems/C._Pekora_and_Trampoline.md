<h1 style='text-align: center;'> C. Pekora and Trampoline</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a trampoline park with $n$ trampolines in a line. The $i$-th of which has strength $S_i$.

Pekora can jump on trampolines in multiple passes. She starts the pass by jumping on any trampoline of her choice. 

If at the moment Pekora jumps on trampoline $i$, the trampoline will launch her to position $i + S_i$, and $S_i$ will become equal to $\max(S_i-1,1)$. In other words, $S_i$ will decrease by $1$, except of the case $S_i=1$, when $S_i$ will remain equal to $1$. 

If there is no trampoline in position $i + S_i$, then this pass is over. Otherwise, Pekora will continue the pass by jumping from the trampoline at position $i + S_i$ by the same rule as above.

Pekora can't stop jumping during the pass until she lands at the position larger than $n$ (in which there is no trampoline). Poor Pekora!

Pekora is a naughty rabbit and wants to ruin the trampoline park by reducing all $S_i$ to $1$. What is the minimum number of passes she needs to reduce all $S_i$ to $1$?

### Input

The first line contains a single integer $t$ ($1 \le t \le 500$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 5000$) — the number of trampolines.

The second line of each test case contains $n$ integers $S_1, S_2, \dots, S_n$ ($1 \le S_i \le 10^9$), where $S_i$ is the strength of the $i$-th trampoline.

It's guaranteed that the sum of $n$ over all test cases doesn't exceed $5000$.

### Output

For each test case, output a single integer — the minimum number of passes Pekora needs to do to reduce all $S_i$ to $1$.

## Example

### Input


```text
3
7
1 4 2 2 2 2 2
2
2 3
5
1 1 1 1 1
```
### Output


```text
4
3
0
```
## Note

For the first test case, here is an optimal series of passes Pekora can take. (The bolded numbers are the positions that Pekora jumps into during these passes.)

* $[1,4,\textbf{2},2,\textbf{2},2,\textbf{2}]$
* $[1,\textbf{4},1,2,1,\textbf{2},1]$
* $[1,\textbf{3},1,2,\textbf{1},\textbf{1},\textbf{1}]$
* $[1,\textbf{2},1,\textbf{2},1,\textbf{1},\textbf{1}]$

For the second test case, the optimal series of passes is show below.

* $[\textbf{2},3]$
* $[1,\textbf{3}]$
* $[1,\textbf{2}]$

For the third test case, all $S_i$ are already equal to $1$.



#### Tags 

#1700 #NOT OK #brute_force #data_structures #dp #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_13.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
