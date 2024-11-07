<h1 style='text-align: center;'> E. Iva & Pav</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Iva and Pav are a famous Serbian competitive programming couple. In Serbia, they call Pav "papuca" and that's why he will make all of Iva's wishes come true.

Iva gave Pav an array $a$ of $n$ elements.

Let's define $f(l, r) = a_l \ \\& \ a_{l+1} \ \\& \dots \\& \ a_r$ (here $\\&$ denotes the [bitwise AND operation](http://tiny.cc/bitwise_and)). 

## Note

 that $f(l, r)$ is not defined when $l>r$.

Iva also gave Pav $q$ queries.

Each query consists of 2 numbers, $k$ and $l$, and she wants Pav to find the largest index $r$ ($l \le r \le n$), such that $f(l, r) \ge k$. 

Pav wants to solve this problem fast because he doesn't want to upset Iva. He needs your help.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the elements of array $a$.

The third line of each test case contains a single integer $q$ ($1 \le q \le 10^5$) — the number of queries Iva gave Pav.

The next $q$ lines of each test case contains two numbers, $l$ and $k$ ($1 \le l \le n$, $1 \le k \le 10^9$) — the left bound for the subsegment, and the integer $k$ described in statement.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. Also, it is guaranteed that the sum of $q$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each query output maximal index $r$ ($l \le r \le n$) such that $a_l \ \\& \ a_{l+1} \ \\& \dots \\& \ a_r \ \ge \ k$.

If such $r$ doesn't exist, output $-1$.

## Example

## Input


```

3515 14 17 42 3431 72 154 557 5 3 1 741 75 72 32 2719 20 15 12 21 7 1141 154 47 125 7
```
## Output


```

2 -1 5 
1 5 2 2 
2 6 -1 5 

```
## Note

In the first test case $n=5$, and the array $a = [15, 14, 17, 42, 34]$

The first query asks for the biggest index $r$ such that the $f(1, r) \ge 7$.

$f(1,1) = 15, \ f(1, 2) = 14, \ f(1,3)=0 \ f(1, 4)=0 \ f(1, 5)=0$, so $r=2$ is the answer.

The second query asks for $f(2, r) \ge 15$. Since such $r$ doesn't exist, the answer is $-1$.

The third query asks for $f(4, r) \ge 5$. $f(4, 4) = 42, \ f(4, 5) = 34$, so $r=5$ is the answer.

In the second test case $n=5$, and the array $a= [7, 5, 3, 1, 7]$.

For the first query, $f(1, r) \ge 7$.

$f(1, 1)=7, \ f(1, 2)=5, \ f(1, 3) = 1, \ f(1,4) = 1, \ f(1, 5)=1$, so the answer to this query is $1$.

For the second query, $f(5, r) \ge 7$.

$f(5, 5) = 7$, so the answer is $5$.

For the third query, $f(2, r) \ge 3$.

$f(2, 2) = 5, \ f(2, 3) = 1, \ f(2, 4) = 1, \ f(2, 5) = 1$, so the answer is $2$.



#### tags 

#1400 #binary_search #bitmasks #data_structures #greedy 