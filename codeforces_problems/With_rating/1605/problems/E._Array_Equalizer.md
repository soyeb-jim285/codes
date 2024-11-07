<h1 style='text-align: center;'> E. Array Equalizer</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jeevan has two arrays $a$ and $b$ of size $n$. He is fond of performing weird operations on arrays. This time, he comes up with two types of operations:

* Choose any $i$ ($1 \le i \le n$) and increment $a_j$ by $1$ for every $j$ which is a multiple of $i$ and $1 \le j \le n$.
* Choose any $i$ ($1 \le i \le n$) and decrement $a_j$ by $1$ for every $j$ which is a multiple of $i$ and $1 \le j \le n$.

He wants to convert array $a$ into an array $b$ using the minimum total number of operations. However, Jeevan seems to have forgotten the value of $b_1$. So he makes some guesses. He will ask you $q$ questions corresponding to his $q$ guesses, the $i$-th of which is of the form: 

* If $b_1 = x_i$, what is the minimum number of operations required to convert $a$ to $b$?

Help him by answering each question.

#### Input

The first line contains a single integer $n$ $(1 \le n \le 2 \cdot 10^{5})$  — the size of arrays $a$ and $b$.

The second line contains $n$ integers $a_1, a_2, ..., a_n$ $(1 \le a_i \le 10^6)$.

The third line contains $n$ integers $b_1, b_2, ..., b_n$ $(1 \le b_i \le 10^6$ for $i \neq 1$; $b_1 = -1$, representing that the value of $b_1$ is unknown$)$.

The fourth line contains a single integer $q$ $(1 \le q \le 2 \cdot 10^{5})$  — the number of questions.

Each of the following $q$ lines contains a single integer $x_i$ $(1 \le x_i \le 10^6)$  — representing the $i$-th question.

#### Output

#### Output

 $q$ integers  — the answers to each of his $q$ questions.

## Examples

#### Input


```text
2
3 7
-1 5
3
1
4
3
```
#### Output


```text
2
4
2
```
#### Input


```text
6
2 5 4 1 3 6
-1 4 6 2 3 5
3
1
8
4
```
#### Output


```text
10
29
9
```
## Note

Consider the first test case.

* $b_1 = 1$: We need to convert $[3, 7] \rightarrow [1, 5]$. We can perform the following operations:$[3, 7]$ $\xrightarrow[\text{decrease}]{\text{i = 1}}$ $[2, 6]$ $\xrightarrow[\text{decrease}]{\text{i = 1}}$ $[1, 5]$

Hence the answer is $2$.
* $b_1 = 4$: We need to convert $[3, 7] \rightarrow [4, 5]$. We can perform the following operations: $[3, 7]$ $\xrightarrow[\text{decrease}]{\text{i = 2}}$ $[3, 6]$ $\xrightarrow[\text{decrease}]{\text{i = 2}}$ $[3, 5]$ $\xrightarrow[\text{increase}]{\text{i = 1}}$ $[4, 6]$ $\xrightarrow[\text{decrease}]{\text{i = 2}}$ $[4, 5]$

Hence the answer is $4$.
* $b_1 = 3$: We need to convert $[3, 7] \rightarrow [3, 5]$. We can perform the following operations:$[3, 7]$ $\xrightarrow[\text{decrease}]{\text{i = 2}}$ $[3, 6]$ $\xrightarrow[\text{decrease}]{\text{i = 2}}$ $[3, 5]$

Hence the answer is $2$.

 

#### Tags 

#2400 #NOT OK #binary_search #greedy #implementation #math #number_theory #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_754_(Div._2).md)
- [announcement (en)](../blogs/announcement_(en).md)
- [tutorial (en)](../blogs/tutorial_(en).md)
