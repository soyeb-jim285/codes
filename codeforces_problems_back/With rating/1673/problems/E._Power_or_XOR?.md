<h1 style='text-align: center;'> E. Power or XOR?</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The symbol $\wedge$ is quite ambiguous, especially when used without context. Sometimes it is used to denote a power ($a\wedge b = a^b$) and sometimes it is used to denote the [XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) operation ($a\wedge b=a\oplus b$). 

You have an ambiguous expression $E=A_1\wedge A_2\wedge A_3\wedge\ldots\wedge A_n$. You can replace each $\wedge$ symbol with either a $\texttt{Power}$ operation or a $\texttt{XOR}$ operation to get an unambiguous expression $E'$.

The value of this expression $E'$ is determined according to the following rules: 

* All $\texttt{Power}$ operations are performed before any $\texttt{XOR}$ operation. In other words, the $\texttt{Power}$ operation takes precedence over $\texttt{XOR}$ operation. For example, $4\;\texttt{XOR}\;6\;\texttt{Power}\;2=4\oplus (6^2)=4\oplus 36=32$.
* Consecutive powers are calculated from left to right. For example, $2\;\texttt{Power}\;3 \;\texttt{Power}\;4 = (2^3)^4 = 8^4 = 4096$.

You are given an array $B$ of length $n$ and an integer $k$. The array $A$ is given by $A_i=2^{B_i}$ and the expression $E$ is given by $E=A_1\wedge A_2\wedge A_3\wedge\ldots\wedge A_n$. You need to find the XOR of the values of all possible unambiguous expressions $E'$ which can be obtained from $E$ and has at least $k$ $\wedge$ symbols used as $\texttt{XOR}$ operation. Since the answer can be very large, you need to find it modulo $2^{2^{20}}$. Since this number can also be very large, you need to print its binary representation without leading zeroes. If the answer is equal to $0$, print $0$.

## Input

The first line of input contains two integers $n$ and $k$ $(1\leq n\leq 2^{20}, 0\leq k < n)$.

The second line of input contains $n$ integers $B_1,B_2,\ldots,B_n$ $(1\leq B_i < 2^{20})$.

## Output

Print a single line containing a binary string without leading zeroes denoting the answer to the problem. If the answer is equal to $0$, print $0$.

## Examples

## Input


```

3 2
3 1 2

```
## Output


```

1110

```
## Input


```

3 1
3 1 2

```
## Output


```

1010010

```
## Input


```

3 0
3 1 2

```
## Output


```

1000000000000000001010010

```
## Input


```

2 1
1 1

```
## Output


```

0

```
## Note

For each of the testcases $1$ to $3$, $A = \{2^3,2^1,2^2\} = \{8,2,4\}$ and $E=8\wedge 2\wedge 4$.

For the first testcase, there is only one possible valid unambiguous expression $E' = 8\oplus 2\oplus 4 = 14 = (1110)_2$.

For the second testcase, there are three possible valid unambiguous expressions $E'$: 

* $8\oplus 2\oplus 4 = 14$
* $8^2\oplus 4 = 64\oplus 4= 68$
* $8\oplus 2^4 = 8\oplus 16= 24$

 XOR of the values of all of these is $14\oplus 68\oplus 24 = 82 = (1010010)_2$.For the third testcase, there are four possible valid unambiguous expressions $E'$: 

* $8\oplus 2\oplus 4 = 14$
* $8^2\oplus 4 = 64\oplus 4= 68$
* $8\oplus 2^4 = 8\oplus 16= 24$
* $(8^2)^4 = 64^4 = 2^{24} = 16777216$

 XOR of the values of all of these is $14\oplus 68\oplus 24\oplus 16777216 = 16777298 = (1000000000000000001010010)_2$.For the fourth testcase, $A=\{2,2\}$ and $E=2\wedge 2$. The only possible valid unambiguous expression $E' = 2\oplus 2 = 0 = (0)_2$.



#### tags 

#2500 #bitmasks #combinatorics #math #number_theory 