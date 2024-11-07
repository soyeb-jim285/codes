<h1 style='text-align: center;'> C. Divisor Chain</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $x$. Your task is to reduce $x$ to $1$.

To do that, you can do the following operation:

* select a divisor $d$ of $x$, then change $x$ to $x-d$, i.e. reduce $x$ by $d$. (We say that $d$ is a divisor of $x$ if $d$ is an positive integer and there exists an integer $q$ such that $x = d \cdot q$.)

There is an additional constraint: you cannot select the same value of $d$ more than twice.

For example, for $x=5$, the following scheme is invalid because $1$ is selected more than twice: $5\xrightarrow{-1}4\xrightarrow{-1}3\xrightarrow{-1}2\xrightarrow{-1}1$. The following scheme is however a valid one: $5\xrightarrow{-1}4\xrightarrow{-2}2\xrightarrow{-1}1$.

## Output

 any scheme which reduces $x$ to $1$ with at most $1000$ operations. It can be proved that such a scheme always exists.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

The only line of each test case contains a single integer $x$ ($2\le x \le 10^{9}$).

## Output

For each test case, output two lines.

The first line should contain an integer $k$ ($1 \le k \le 1001$).

The next line should contain $k$ integers $a_1,a_2,\ldots,a_k$, which satisfy the following:

* $a_1=x$;
* $a_k=1$;
* for each $2 \le i \le k$, the value $(a_{i-1}-a_i)$ is a divisor of $a_{i-1}$. Each number may occur as a divisor at most twice.
## Example

## Input


```

33514
```
## Output


```

3
3 2 1
4
5 4 2 1
6
14 12 6 3 2 1

```
## Note

In the first test case, we use the following scheme: $3\xrightarrow{-1}2\xrightarrow{-1}1$.

In the second test case, we use the following scheme: $5\xrightarrow{-1}4\xrightarrow{-2}2\xrightarrow{-1}1$.

In the third test case, we use the following scheme: $14\xrightarrow{-2}12\xrightarrow{-6}6\xrightarrow{-3}3\xrightarrow{-1}2\xrightarrow{-1}1$.



#### tags 

#1300 #bitmasks #constructive_algorithms #math #number_theory 