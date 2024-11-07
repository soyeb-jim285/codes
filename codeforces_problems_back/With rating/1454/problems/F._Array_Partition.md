<h1 style='text-align: center;'> F. Array Partition</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ integers.

Let $min(l, r)$ be the minimum value among $a_l, a_{l + 1}, \ldots, a_r$ and $max(l, r)$ be the maximum value among $a_l, a_{l + 1}, \ldots, a_r$.

Your task is to choose three positive (greater than $0$) integers $x$, $y$ and $z$ such that:

* $x + y + z = n$;
* $max(1, x) = min(x + 1, x + y) = max(x + y + 1, n)$.

In other words, you have to split the array $a$ into three consecutive non-empty parts that cover the whole array and the maximum in the first part equals the minimum in the second part and equals the maximum in the third part (or determine it is impossible to find such a partition).

Among all such triples (partitions), you can choose any.

You have to answer $t$ independent test cases.

## Input

The first line of the input contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases. Then $t$ test cases follow.

The first line of the test case contains one integer $n$ ($3 \le n \le 2 \cdot 10^5$) — the length of $a$.

The second line of the test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$), where $a_i$ is the $i$-th element of $a$.

It is guaranteed that the sum of $n$ does not exceed $2 \cdot 10^5$ ($\sum n \le 2 \cdot 10^5$).

## Output

For each test case, print the answer: NO in the only line if there is no such partition of $a$ that satisfies the conditions from the problem statement. Otherwise, print YES in the first line and three integers $x$, $y$ and $z$ ($x + y + z = n$) in the second line.

If there are several answers, you can print any.

## Example

## Input


```

6
11
1 2 3 3 3 4 4 3 4 2 1
8
2 9 1 7 3 9 4 1
9
2 1 4 2 4 3 3 1 2
7
4 2 1 1 4 1 4
5
1 1 1 1 1
7
4 3 4 3 3 3 4

```
## Output


```

YES
6 1 4
NO
YES
2 5 2
YES
4 1 2
YES
1 1 3
YES
2 1 4

```


#### tags 

#2100 #binary_search #data_structures #greedy #two_pointers 