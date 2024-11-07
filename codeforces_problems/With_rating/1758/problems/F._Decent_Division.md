<h1 style='text-align: center;'> F. Decent Division</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A binary string is a string where every character is $\texttt{0}$ or $\texttt{1}$. Call a binary string decent if it has an equal number of $\texttt{0}$s and $\texttt{1}$s.

Initially, you have an infinite binary string $t$ whose characters are all $\texttt{0}$s. You are given a sequence $a$ of $n$ updates, where $a_i$ indicates that the character at index $a_i$ will be flipped ($\texttt{0} \leftrightarrow \texttt{1}$). You need to keep and modify after each update a set $S$ of disjoint ranges such that: 

* for each range $[l,r]$, the substring $t_l \dots t_r$ is a decent binary string, and
* for all indices $i$ such that $t_i = \texttt{1}$, there exists $[l,r]$ in $S$ such that $l \leq i \leq r$.

You only need to output the ranges that are added to or removed from $S$ after each update. You can only add or remove ranges from $S$ at most $\mathbf{10^6}$ times.

More formally, let $S_i$ be the set of ranges after the $i$-th update, where $S_0 = \varnothing$ (the empty set). Define $X_i$ to be the set of ranges removed after update $i$, and $Y_i$ to be the set of ranges added after update $i$. Then for $1 \leq i \leq n$, $S_i = (S_{i - 1} \setminus X_i) \cup Y_i$. The following should hold for all $1 \leq i \leq n$: 

* $\forall a,b \in S_i, (a \neq b) \rightarrow (a \cap b = \varnothing)$;
* $X_i \subseteq S_{i - 1}$;
* $(S_{i-1} \setminus X_i) \cap Y_i = \varnothing$;
* $\displaystyle\sum_{i = 1}^n {(|X_i| + |Y_i|)} \leq 10^6$.
### Input

The first line contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the number of updates.

The next $n$ lines each contain a single integer $a_i$ ($1 \leq a_i \leq 2 \cdot 10^5$) — the index of the $i$-th update to the string.

### Output

After the $i$-th update, first output a single integer $x_i$ — the number of ranges to be removed from $S$ after update $i$.

In the following $x_i$ lines, output two integers $l$ and $r$ ($1 \leq l < r \leq 10^6$), which denotes that the range $[l,r]$ should be removed from $S$. Each of these ranges should be distinct and be part of $S$.

In the next line, output a single integer $y_i$ — the number of ranges to be added to $S$ after update $i$.

In the following $y_i$ lines, output two integers $l$ and $r$ ($1 \leq l < r \leq 10^6$), which denotes that the range $[l,r]$ should be added to $S$. Each of these ranges should be distinct and not be part of $S$.

The total number of removals and additions across all updates must not exceed $\mathbf{10^6}$.

After processing the removals and additions for each update, all the ranges in $S$ should be disjoint and cover all ones.

It can be proven that an answer always exists under these constraints.

## Example

### Input


```text
5
1
6
5
5
6
```
### Output


```text

0
1
1 2

0
1
5 6

1
5 6
2
6 7
4 5

1
4 5
0

1
6 7
0
```
## Note

Line breaks are provided in the sample only for the sake of clarity, and you don't need to print them in your output.

After the first update, the set of indices where $a_i = 1$ is $\{1\}$. The interval $[1, 2]$ is added, so $S_1 = \{[1, 2]\}$, which has one $\texttt{0}$ and one $\texttt{1}$.

After the second update, the set of indices where $a_i = 1$ is $\{1, 6\}$. The interval $[5, 6]$ is added, so $S_2 = \{[1, 2], [5, 6]\}$, each of which has one $\texttt{0}$ and one $\texttt{1}$.

After the third update, the set of indices where $a_i = 1$ is $\{1, 5, 6\}$. The interval $[5, 6]$ is removed and the intervals $[4, 5]$ and $[6, 7]$ are added, so $S_3 = \{[1, 2], [4, 5], [6, 7]\}$, each of which has one $\texttt{0}$ and one $\texttt{1}$.

After the fourth update, the set of indices where $a_i = 1$ is $\{1, 6\}$. The interval $[4, 5]$ is removed, so $S_4 = \{[1, 2], [6, 7]\}$, each of which has one $\texttt{0}$ and one $\texttt{1}$.

After the fifth update, the set of indices where $a_i = 1$ is $\{1\}$. The interval $[6, 7]$ is removed, so $S_5 = \{[1, 2]\}$, which has one $\texttt{0}$ and one $\texttt{1}$.



#### Tags 

#3000 #NOT OK #constructive_algorithms #data_structures 

## Blogs
- [All Contest Problems](../Codeforces_Round_836_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
