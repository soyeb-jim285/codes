<h1 style='text-align: center;'> D. INOI Final Contests</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Today is the final contest of INOI (Iranian National Olympiad in Informatics). The contest room is a row with $n$ computers. All computers are numbered with integers from $1$ to $n$ from left to right. There are $m$ participants, numbered with integers from $1$ to $m$.

We have an array $a$ of length $m$ where $a_{i}$ ($1 \leq a_i \leq n$) is the computer behind which the $i$-th participant wants to sit.

Also, we have another array $b$ of length $m$ consisting of characters 'L' and 'R'. $b_i$ is the side from which the $i$-th participant enters the room. 'L' means the participant enters from the left of computer $1$ and goes from left to right, and 'R' means the participant enters from the right of computer $n$ and goes from right to left.

The participants in the order from $1$ to $m$ enter the room one by one. The $i$-th of them enters the contest room in the direction $b_i$ and goes to sit behind the $a_i$-th computer. If it is occupied he keeps walking in his direction until he reaches the first unoccupied computer. After that, he sits behind it. If he doesn't find any computer he gets upset and gives up on the contest.

The madness of the $i$-th participant is the distance between his assigned computer ($a_i$) and the computer he ends up sitting behind. The distance between computers $i$ and $j$ is equal to $|i - j|$.

The values in the array $a$ can be equal. There exist $n^m \cdot 2^m$ possible pairs of arrays $(a, b)$.

Consider all pairs of arrays $(a, b)$ such that no person becomes upset. For each of them let's calculate the sum of participants madnesses. Find the sum of all these values.

You will be given some prime modulo $p$. Find this sum by modulo $p$.

###### Input

The only line contains three integers $n$, $m$, $p$ ($1 \leq m \leq n \leq 500, 10^8 \leq p \leq 10 ^ 9 + 9$).

It is guaranteed, that the number $p$ is prime.

###### Output

Print only one integer — the required sum by modulo $p$.

## Examples

###### Input


```text
3 1 1000000007
```
###### Output


```text
0
```
###### Input


```text
2 2 1000000009
```
###### Output


```text
4
```
###### Input


```text
3 2 998244353
```
###### Output


```text
8
```
###### Input


```text
20 10 1000000009
```
###### Output


```text
352081045
```
## Note

In the first test, there are three possible arrays $a$: $\{1\}$, $\{2\}$, and $ \{3\}$ and two possible arrays $b$: $\{\mathtt{L}\}$ and $\{\mathtt{R}\}$. For all six pairs of arrays $(a, b)$, the only participant will sit behind the computer $a_1$, so his madness will be $0$. So the total sum of madnesses will be $0$.

In the second test, all possible pairs of arrays $(a, b)$, such that no person becomes upset are:

* $(\{1, 1\}, \{\mathtt{L}, \mathtt{L}\})$, the sum of madnesses is $1$;
* $(\{1, 1\}, \{\mathtt{R}, \mathtt{L}\})$, the sum of madnesses is $1$;
* $(\{2, 2\}, \{\mathtt{R}, \mathtt{R}\})$, the sum of madnesses is $1$;
* $(\{2, 2\}, \{\mathtt{L}, \mathtt{R}\})$, the sum of madnesses is $1$;
* all possible pairs of $a \in \{\{1, 2\}, \{2, 1\}\}$ and $b \in \{\{\mathtt{L}, \mathtt{L}\}, \{\mathtt{R}, \mathtt{L}\}, \{\mathtt{L}, \mathtt{R}\}, \{\mathtt{R}, \mathtt{R}\}\}$, the sum of madnesses is $0$.

So, the answer is $1 + 1 + 1 + 1 + 0 \ldots = 4$.



#### Tags 

#3100 #NOT OK #combinatorics #dp #fft 

## Blogs
- [All Contest Problems](../Codeforces_Round_684_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
