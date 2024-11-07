<h1 style='text-align: center;'> A. Doremy's IQ</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Doremy is asked to test $n$ contests. Contest $i$ can only be tested on day $i$. The difficulty of contest $i$ is $a_i$. Initially, Doremy's IQ is $q$. On day $i$ Doremy will choose whether to test contest $i$ or not. She can only test a contest if her current IQ is strictly greater than $0$.

If Doremy chooses to test contest $i$ on day $i$, the following happens: 

* if $a_i>q$, Doremy will feel she is not wise enough, so $q$ decreases by $1$;
* otherwise, nothing changes.

 If she chooses not to test a contest, nothing changes.Doremy wants to test as many contests as possible. Please give Doremy a solution.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases. The description of the test cases follows.

The first line contains two integers $n$ and $q$ ($1 \le n \le 10^5$, $1 \le q \le 10^9$) — the number of contests and Doremy's IQ in the beginning.

The second line contains $n$ integers $a_1,a_2,\cdots,a_n$ ($1 \le a_i \le 10^9$) — the difficulty of each contest.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, you need to output a binary string $s$, where $s_i=1$ if Doremy should choose to test contest $i$, and $s_i=0$ otherwise. The number of ones in the string should be maximum possible, and she should never test a contest when her IQ is zero or less.

If there are multiple solutions, you may output any.

## Example

## Input


```

51 112 11 23 11 2 14 21 4 3 15 25 1 2 4 3
```
## Output


```

1
11
110
1110
01111

```
## Note

In the first test case, Doremy tests the only contest. Her IQ doesn't decrease.

In the second test case, Doremy tests both contests. Her IQ decreases by $1$ after testing contest $2$.

In the third test case, Doremy tests contest $1$ and $2$. Her IQ decreases to $0$ after testing contest $2$, so she can't test contest $3$.



#### tags 

#1600 #binary_search #constructive_algorithms #greedy #implementation 