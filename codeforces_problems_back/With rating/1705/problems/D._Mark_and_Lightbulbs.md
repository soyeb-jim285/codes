<h1 style='text-align: center;'> D. Mark and Lightbulbs</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mark has just purchased a rack of $n$ lightbulbs. The state of the lightbulbs can be described with binary string $s = s_1s_2\dots s_n$, where $s_i=\texttt{1}$ means that the $i$-th lightbulb is turned on, while $s_i=\texttt{0}$ means that the $i$-th lightbulb is turned off.

Unfortunately, the lightbulbs are broken, and the only operation he can perform to change the state of the lightbulbs is the following:

* Select an index $i$ from $2,3,\dots,n-1$ such that $s_{i-1}\ne s_{i+1}$.
* Toggle $s_i$. Namely, if $s_i$ is $\texttt{0}$, set $s_i$ to $\texttt{1}$ or vice versa.

Mark wants the state of the lightbulbs to be another binary string $t$. Help Mark determine the minimum number of operations to do so.

## Input

The first line of the input contains a single integer $q$ ($1\leq q\leq 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($3\leq n\leq 2\cdot 10^5$) — the number of lightbulbs.

The second line of each test case contains a binary string $s$ of length $n$ — the initial state of the lightbulbs.

The third line of each test case contains a binary string $t$ of length $n$ — the final state of the lightbulbs.

It is guaranteed that the sum of $n$ across all test cases does not exceed $2\cdot 10^5$.

## Output

For each test case, print a line containing the minimum number of operations Mark needs to perform to transform $s$ to $t$. If there is no such sequence of operations, print $-1$.

## Example

## Input


```

4401000010410100100501001000116000101010011
```
## Output


```

2
-1
-1
5

```
## Note

In the first test case, one sequence of operations that achieves the minimum number of operations is the following. 

* Select $i=3$, changing $\texttt{01}\color{red}{\texttt{0}}\texttt{0}$ to $\texttt{01}\color{red}{\texttt{1}}\texttt{0}$.
* Select $i=2$, changing $\texttt{0}\color{red}{\texttt{1}}\texttt{10}$ to $\texttt{0}\color{red}{\texttt{0}}\texttt{10}$.

 In the second test case, there is no sequence of operations because one cannot change the first digit or the last digit of $s$.In the third test case, even though the first digits of $s$ and $t$ are the same and the last digits of $s$ and $t$ are the same, it can be shown that there is no sequence of operations that satisfies the condition.

In the fourth test case, one sequence that achieves the minimum number of operations is the following: 

* Select $i=3$, changing $\texttt{00}\color{red}{\texttt{0}}\texttt{101}$ to $\texttt{00}\color{red}{\texttt{1}}\texttt{101}$.
* Select $i=2$, changing $\texttt{0}\color{red}{\texttt{0}}\texttt{1101}$ to $\texttt{0}\color{red}{\texttt{1}}\texttt{1101}$.
* Select $i=4$, changing $\texttt{011}\color{red}{\texttt{1}}\texttt{01}$ to $\texttt{011}\color{red}{\texttt{0}}\texttt{01}$.
* Select $i=5$, changing $\texttt{0110}\color{red}{\texttt{0}}\texttt{1}$ to $\texttt{0110}\color{red}{\texttt{1}}\texttt{1}$.
* Select $i=3$, changing $\texttt{01}\color{red}{\texttt{1}}\texttt{011}$ to $\texttt{01}\color{red}{\texttt{0}}\texttt{011}$.


#### tags 

#1800 #combinatorics #constructive_algorithms #greedy #math #sortings 