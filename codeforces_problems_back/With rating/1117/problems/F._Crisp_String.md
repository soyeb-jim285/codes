<h1 style='text-align: center;'> F. Crisp String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string of length $n$. Each character is one of the first $p$ lowercase Latin letters.

You are also given a matrix $A$ with binary values of size $p \times p$. This matrix is symmetric ($A_{ij} = A_{ji}$). $A_{ij} = 1$ means that the string can have the $i$-th and $j$-th letters of Latin alphabet adjacent.

Let's call the string crisp if all of the adjacent characters in it can be adjacent (have 1 in the corresponding cell of matrix $A$).

You are allowed to do the following move. Choose any letter, remove all its occurrences and join the remaining parts of the string without changing their order. For example, removing letter 'a' from "abacaba" will yield "bcb".

The string you are given is crisp. The string should remain crisp after every move you make.

You are allowed to do arbitrary number of moves (possible zero). What is the shortest resulting string you can obtain?

## Input

The first line contains two integers $n$ and $p$ ($1 \le n \le 10^5$, $1 \le p \le 17$) — the length of the initial string and the length of the allowed prefix of Latin alphabet.

The second line contains the initial string. It is guaranteed that it contains only first $p$ lowercase Latin letters and that is it crisp. Some of these $p$ first Latin letters might not be present in the string.

Each of the next $p$ lines contains $p$ integer numbers — the matrix $A$ ($0 \le A_{ij} \le 1$, $A_{ij} = A_{ji}$). $A_{ij} = 1$ means that the string can have the $i$-th and $j$-th letters of Latin alphabet adjacent.

## Output

Print a single integer — the length of the shortest string after you make arbitrary number of moves (possible zero).

## Examples

## Input


```

7 3
abacaba
0 1 1
1 0 0
1 0 0

```
## Output


```

7

```
## Input


```

7 3
abacaba
1 1 1
1 0 0
1 0 0

```
## Output


```

0

```
## Input


```

7 4
bacadab
0 1 1 1
1 0 0 0
1 0 0 0
1 0 0 0

```
## Output


```

5

```
## Input


```

3 3
cbc
0 0 0
0 0 1
0 1 0

```
## Output


```

0

```
## Note

In the first example no letter can be removed from the initial string.

In the second example you can remove letters in order: 'b', 'c', 'a'. The strings on the intermediate steps will be: "abacaba" $\rightarrow$ "aacaa" $\rightarrow$ "aaaa" $\rightarrow$ "".

In the third example you can remove letter 'b' and that's it.

In the fourth example you can remove letters in order 'c', 'b', but not in the order 'b', 'c' because two letters 'c' can't be adjacent.



#### tags 

#2500 #bitmasks #dp 