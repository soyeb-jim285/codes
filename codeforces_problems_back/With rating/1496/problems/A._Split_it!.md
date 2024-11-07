<h1 style='text-align: center;'> A. Split it!</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kawashiro Nitori is a girl who loves competitive programming.

One day she found a string and an integer. As an advanced problem setter, she quickly thought of a problem.

Given a string $s$ and a parameter $k$, you need to check if there exist $k+1$ non-empty strings $a_1,a_2...,a_{k+1}$, such that $$s=a_1+a_2+\ldots +a_k+a_{k+1}+R(a_k)+R(a_{k-1})+\ldots+R(a_{1}).$$ 

Here $+$ represents concatenation. We define $R(x)$ as a reversed string $x$. For example $R(abcd) = dcba$. ## Note

 that in the formula above the part $R(a_{k+1})$ is intentionally skipped.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 100$)  — the number of test cases. The description of the test cases follows.

The first line of each test case description contains two integers $n$, $k$ ($1\le n\le 100$, $0\le k\le \lfloor \frac{n}{2} \rfloor$)  — the length of the string $s$ and the parameter $k$.

The second line of each test case description contains a single string $s$ of length $n$, consisting of lowercase English letters.

## Output

For each test case, print "YES" (without quotes), if it is possible to find $a_1,a_2,\ldots,a_{k+1}$, and "NO" (without quotes) otherwise.

You can print letters in any case (upper or lower).

## Example

## Input


```

7
5 1
qwqwq
2 1
ab
3 1
ioi
4 2
icpc
22 0
dokidokiliteratureclub
19 8
imteamshanghaialice
6 3
aaaaaa

```
## Output


```

YES
NO
YES
NO
YES
NO
NO

```
## Note

In the first test case, one possible solution is $a_1=qw$ and $a_2=q$.

In the third test case, one possible solution is $a_1=i$ and $a_2=o$.

In the fifth test case, one possible solution is $a_1=dokidokiliteratureclub$.



#### tags 

#900 #brute_force #constructive_algorithms #greedy #strings 