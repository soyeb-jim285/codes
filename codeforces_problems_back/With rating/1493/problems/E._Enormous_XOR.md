<h1 style='text-align: center;'> E. Enormous XOR</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $l$ and $r$ in binary representation. Let $g(x, y)$ be equal to the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all integers from $x$ to $y$ inclusive (that is $x \oplus (x+1) \oplus \dots \oplus (y-1) \oplus y$). Let's define $f(l, r)$ as the maximum of all values of $g(x, y)$ satisfying $l \le x \le y \le r$.

## Output

 $f(l, r)$.

## Input

The first line contains a single integer $n$ ($1 \le n \le 10^6$) — the length of the binary representation of $r$.

The second line contains the binary representation of $l$ — a string of length $n$ consisting of digits $0$ and $1$ ($0 \le l < 2^n$).

The third line contains the binary representation of $r$ — a string of length $n$ consisting of digits $0$ and $1$ ($0 \le r < 2^n$).

It is guaranteed that $l \le r$. The binary representation of $r$ does not contain any extra leading zeros (if $r=0$, the binary representation of it consists of a single zero). The binary representation of $l$ is preceded with leading zeros so that its length is equal to $n$.

## Output

In a single line output the value of $f(l, r)$ for the given pair of $l$ and $r$ in binary representation without extra leading zeros.

## Examples

## Input


```

7
0010011
1111010

```
## Output


```

1111111
```
## Input


```

4
1010
1101

```
## Output


```

1101

```
## Note

In sample test case $l=19$, $r=122$. $f(x,y)$ is maximal and is equal to $127$, with $x=27$, $y=100$, for example.



#### tags 

#2600 #bitmasks #constructive_algorithms #greedy #math #strings #two_pointers 