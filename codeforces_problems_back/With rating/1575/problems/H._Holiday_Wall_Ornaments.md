<h1 style='text-align: center;'> H. Holiday Wall Ornaments</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The Winter holiday will be here soon. Mr. Chanek wants to decorate his house's wall with ornaments. The wall can be represented as a binary string $a$ of length $n$. His favorite nephew has another binary string $b$ of length $m$ ($m \leq n$).

Mr. Chanek's nephew loves the non-negative integer $k$. His nephew wants exactly $k$ occurrences of $b$ as substrings in $a$. 

However, Mr. Chanek does not know the value of $k$. So, for each $k$ ($0 \leq k \leq n - m + 1$), find the minimum number of elements in $a$ that have to be changed such that there are exactly $k$ occurrences of $b$ in $a$.

A string $s$ occurs exactly $k$ times in $t$ if there are exactly $k$ different pairs $(p,q)$ such that we can obtain $s$ by deleting $p$ characters from the beginning and $q$ characters from the end of $t$.

## Input

The first line contains two integers $n$ and $m$ ($1 \leq m \leq n \leq 500$) — size of the binary string $a$ and $b$ respectively.

The second line contains a binary string $a$ of length $n$.

The third line contains a binary string $b$ of length $m$.

## Output

## Output

 $n - m + 2$ integers — the $(k+1)$-th integer denotes the minimal number of elements in $a$ that have to be changed so there are exactly $k$ occurrences of $b$ as a substring in $a$.

## Example

## Input


```

9 3
100101011
101

```
## Output


```

1 1 0 1 6 -1 -1 -1

```
## Note

For $k = 0$, to make the string $a$ have no occurrence of 101, you can do one character change as follows.

100101011 $\rightarrow$ 100100011

For $k = 1$, you can also change a single character.

100101011 $\rightarrow$ 100001011

For $k = 2$, no changes are needed.



#### tags 

#2200 #dp #strings 