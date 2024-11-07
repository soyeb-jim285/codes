<h1 style='text-align: center;'> A. Doremy's Paint</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Doremy has $n$ buckets of paint which is represented by an array $a$ of length $n$. Bucket $i$ contains paint with color $a_i$. 

Let $c(l,r)$ be the number of distinct elements in the subarray $[a_l,a_{l+1},\ldots,a_r]$. Choose $2$ integers $l$ and $r$ such that $l \leq r$ and $r-l-c(l,r)$ is maximized.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 10^4$)  — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le n$).

It is guaranteed that the sum of $n$ does not exceed $10^5$.

## Output

For each test case, output $l$ and $r$ such that $l \leq r$ and $r-l-c(l,r)$ is maximized.

If there are multiple solutions, you may output any.

## Example

## Input


```

751 3 2 2 451 2 3 4 542 1 2 132 3 322 21199 8 5 2 1 1 2 3 3
```
## Output


```

2 4
1 5
1 4
2 3
1 2
1 1
3 9

```
## Note

In the first test case, $a=[1,3,2,2,4]$.

* When $l=1$ and $r=3$, $c(l,r)=3$ (there are $3$ distinct elements in $[1,3,2]$).
* When $l=2$ and $r=4$, $c(l,r)=2$ (there are $2$ distinct elements in $[3,2,2]$).

It can be shown that choosing $l=2$ and $r=4$ maximizes the value of $r-l-c(l,r)$ at $0$.

For the second test case, $a=[1,2,3,4,5]$. 

* When $l=1$ and $r=5$, $c(l,r)=5$ (there are $5$ distinct elements in $[1,2,3,4,5]$).
* When $l=3$ and $r=3$, $c(l,r)=1$ (there is $1$ distinct element in $[3]$).

It can be shown that choosing $l=1$ and $r=5$ maximizes the value of $r-l-c(l,r)$ at $-1$. Choosing $l=3$ and $r=3$ is also acceptable.



#### tags 

#800 #greedy 