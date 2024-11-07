<h1 style='text-align: center;'> A. Digits Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's define $S(x)$ to be the sum of digits of number $x$ written in decimal system. For example, $S(5) = 5$, $S(10) = 1$, $S(322) = 7$.

We will call an integer $x$ interesting if $S(x + 1) < S(x)$. In each test you will be given one integer $n$. Your task is to calculate the number of integers $x$ such that $1 \le x \le n$ and $x$ is interesting.

## Input

The first line contains one integer $t$ ($1 \le t \le 1000$)  — number of test cases.

Then $t$ lines follow, the $i$-th line contains one integer $n$ ($1 \le n \le 10^9$) for the $i$-th test case.

## Output

Print $t$ integers, the $i$-th should be the answer for the $i$-th test case.

## Example

## Input


```

5
1
9
10
34
880055535

```
## Output


```

0
1
1
3
88005553

```
## Note

The first interesting number is equal to $9$.



#### tags 

#800 #math #number_theory 