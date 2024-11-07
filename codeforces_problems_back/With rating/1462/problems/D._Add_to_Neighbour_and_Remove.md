<h1 style='text-align: center;'> D. Add to Neighbour and Remove</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp was given an array of $a[1 \dots n]$ of $n$ integers. He can perform the following operation with the array $a$ no more than $n$ times:

* Polycarp selects the index $i$ and adds the value $a_i$ to one of his choice of its neighbors. More formally, Polycarp adds the value of $a_i$ to $a_{i-1}$ or to $a_{i+1}$ (if such a neighbor does not exist, then it is impossible to add to it).
* After adding it, Polycarp removes the $i$-th element from the $a$ array. During this step the length of $a$ is decreased by $1$.

The two items above together denote one single operation.

For example, if Polycarp has an array $a = [3, 1, 6, 6, 2]$, then it can perform the following sequence of operations with it: 

* Polycarp selects $i = 2$ and adds the value $a_i$ to $(i-1)$-th element: $a = [4, 6, 6, 2]$.
* Polycarp selects $i = 1$ and adds the value $a_i$ to $(i+1)$-th element: $a = [10, 6, 2]$.
* Polycarp selects $i = 3$ and adds the value $a_i$ to $(i-1)$-th element: $a = [10, 8]$.
* Polycarp selects $i = 2$ and adds the value $a_i$ to $(i-1)$-th element: $a = [18]$.

## Note

 that Polycarp could stop performing operations at any time.

Polycarp wondered how many minimum operations he would need to perform to make all the elements of $a$ equal (i.e., he wants all $a_i$ are equal to each other).

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 3000$) — the number of test cases in the test. Then $t$ test cases follow.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 3000$) — the length of the array. The next line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^5$) — array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3000$.

## Output

For each test case, output a single number — the minimum number of operations that Polycarp needs to perform so that all elements of the $a$ array are the same (equal).

## Example

## Input


```

4
5
3 1 6 6 2
4
1 2 2 1
3
2 2 2
4
6 3 2 1

```
## Output


```

4
2
0
2

```
## Note

In the first test case of the example, the answer can be constructed like this (just one way among many other ways):

$[3, 1, 6, 6, 2]$ $\xrightarrow[]{i=4,~add~to~left}$ $[3, 1, 12, 2]$ $\xrightarrow[]{i=2,~add~to~right}$ $[3, 13, 2]$ $\xrightarrow[]{i=1,~add~to~right}$ $[16, 2]$ $\xrightarrow[]{i=2,~add~to~left}$ $[18]$. All elements of the array $[18]$ are the same.

In the second test case of the example, the answer can be constructed like this (just one way among other ways):

$[1, 2, 2, 1]$ $\xrightarrow[]{i=1,~add~to~right}$ $[3, 2, 1]$ $\xrightarrow[]{i=3,~add~to~left}$ $[3, 3]$. All elements of the array $[3, 3]$ are the same.

In the third test case of the example, Polycarp doesn't need to perform any operations since $[2, 2, 2]$ contains equal (same) elements only.

In the fourth test case of the example, the answer can be constructed like this (just one way among other ways):

$[6, 3, 2, 1]$ $\xrightarrow[]{i=3,~add~to~right}$ $[6, 3, 3]$ $\xrightarrow[]{i=3,~add~to~left}$ $[6, 6]$. All elements of the array $[6, 6]$ are the same.



#### tags 

#1400 #greedy #math #number_theory 