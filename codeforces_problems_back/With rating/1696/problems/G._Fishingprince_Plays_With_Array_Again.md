<h1 style='text-align: center;'> G. Fishingprince Plays With Array Again</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Suppose you are given a 1-indexed sequence $a$ of non-negative integers, whose length is $n$, and two integers $x$, $y$. In consecutive $t$ seconds ($t$ can be any positive real number), you can do one of the following operations:

* Select $1\le i<n$, decrease $a_i$ by $x\cdot t$, and decrease $a_{i+1}$ by $y\cdot t$.
* Select $1\le i<n$, decrease $a_i$ by $y\cdot t$, and decrease $a_{i+1}$ by $x\cdot t$.

Define the minimum amount of time (it might be a real number) required to make all elements in the sequence less than or equal to $0$ as $f(a)$.

For example, when $x=1$, $y=2$, it takes $3$ seconds to deal with the array $[3,1,1,3]$. We can:

* In the first $1.5$ seconds do the second operation with $i=1$.
* In the next $1.5$ seconds do the first operation with $i=3$.

We can prove that it's not possible to make all elements less than or equal to $0$ in less than $3$ seconds, so $f([3,1,1,3])=3$.

Now you are given a 1-indexed sequence $b$ of positive integers, whose length is $n$. You are also given positive integers $x$, $y$. Process $q$ queries of the following two types:

* 1 k v: change $b_k$ to $v$.
* 2 l r: print $f([b_l,b_{l+1},\dots,b_r])$.
## Input

The first line of input contains two integers $n$ and $q$ ($2\le n\le 2\cdot 10^5$, $1\le q\le 2\cdot 10^5$).

The second line of input contains two integers $x$ and $y$ ($1\le x,y\le 10^6$).

The third line of input contains $n$ integers $b_1,b_2,\ldots,b_n$ ($1\le b_i\le 10^6$).

This is followed by $q$ lines. Each of these $q$ lines contains three integers. The first integer $op$ is either $1$ or $2$.

* If it is $1$, it is followed by two integers $k$, $v$ ($1\le k\le n$, $1\le v\le 10^6$). It means that you should change $b_k$ to $v$.
* If it is $2$, it is followed by two integers $l$, $r$ ($1\le l<r\le n$). It means that you should print $f([b_l,b_{l+1},\dots,b_r])$.
## Output

For each query of type $2$, print one real number — the answer to the query. Your answer is considered correct if its absolute error or relative error does not exceed $10^{-9}$.

## Example

## Input


```

4 3
1 2
3 1 1 4
2 1 4
1 1 1
2 1 3

```
## Output


```

3.500000000000000
1.000000000000000

```
## Note

Let's analyse the sample.

In the first query, we are asked to compute $f([3,1,1,4])$. The answer is $3.5$. One optimal sequence of operations is:

* In the first $1.5$ seconds do the second operation with $i=1$.
* In the next $2$ seconds do the first operation with $i=3$.

In the third query, we are asked to compute $f([1,1,1])$. The answer is $1$. One optimal sequence of operations is:

* In the first $0.5$ seconds do the second operation with $i=1$.
* In the next $0.5$ seconds do the first operation with $i=2$.


#### tags 

#3300 #brute_force #data_structures #geometry #math 