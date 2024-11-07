<h1 style='text-align: center;'> C. Zero-Sum Prefixes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The score of an array $v_1,v_2,\ldots,v_n$ is defined as the number of indices $i$ ($1 \le i \le n$) such that $v_1+v_2+\ldots+v_i = 0$.

You are given an array $a_1,a_2,\ldots,a_n$ of length $n$. You can perform the following operation multiple times:

* select an index $i$ ($1 \le i \le n$) such that $a_i=0$;
* then replace $a_i$ by an arbitrary integer.

 What is the maximum possible score of $a$ that can be obtained by performing a sequence of such operations?

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($-10^9 \le a_i \le 10^9$) — array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print the maximum possible score of the array $a$ after performing a sequence of operations.

## Example

## Input


```

552 0 1 -1 031000000000 1000000000 040 0 0 083 0 2 -10 10 -30 30 091 0 0 1 -1 0 1 0 -1
```
## Output


```

3
1
4
4
5

```
## Note

In the first test case, it is optimal to change the value of $a_2$ to $-2$ in one operation.

The resulting array $a$ will be $[2,-2,1,-1,0]$, with a score of $3$:

* $a_1+a_2=2-2=0$;
* $a_1+a_2+a_3+a_4=2-2+1-1=0$;
* $a_1+a_2+a_3+a_4+a_5=2-2+1-1+0=0$.

In the second test case, it is optimal to change the value of $a_3$ to $-2\,000\,000\,000$, giving us an array with a score of $1$.

In the third test case, it is not necessary to perform any operations.



#### tags 

#1600 #brute_force #data_structures #dp #greedy #implementation 