<h1 style='text-align: center;'> D. Permutation Addicts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Given a permutation $a_1, a_2, \dots, a_n$ of integers from $1$ to $n$, and a threshold $k$ with $0 \leq k \leq n$, you compute a sequence $b_1, b_2, \dots, b_n$ as follows. 

For every $1 \leq i \leq n$ in increasing order, let $x = a_i$. 

* If $x \leq k$, set $b_{x}$ to the last element $a_j$ ($1 \leq j < i$) that $a_j > k$. If no such element $a_j$ exists, set $b_{x} = n+1$.
* If $x > k$, set $b_{x}$ to the last element $a_j$ ($1 \leq j < i$) that $a_j \leq k$. If no such element $a_j$ exists, set $b_{x} = 0$.

Unfortunately, after the sequence $b_1, b_2, \dots, b_n$ has been completely computed, the permutation $a_1, a_2, \dots, a_n$ and the threshold $k$ are discarded. 

Now you only have the sequence $b_1, b_2, \dots, b_n$. Your task is to find any possible permutation $a_1, a_2, \dots, a_n$ and threshold $k$ that produce the sequence $b_1, b_2, \dots, b_n$. It is guaranteed that there exists at least one pair of permutation $a_1, a_2, \dots, a_n$ and threshold $k$ that produce the sequence $b_1, b_2, \dots, b_n$.

A permutation of integers from $1$ to $n$ is a sequence of length $n$ which contains all integers from $1$ to $n$ exactly once. 

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^5$), indicating the length of the permutation $a$.

The second line of each test case contains $n$ integers $b_1, b_2, \dots, b_n$ ($0 \leq b_i \leq n+1$), indicating the elements of the sequence $b$.

It is guaranteed that there exists at least one pair of permutation $a_1, a_2, \dots, a_n$ and threshold $k$ that produce the sequence $b_1, b_2, \dots, b_n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output the threshold $k$ ($0 \leq k \leq n$) in the first line, and then output the permutation $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq n$) in the second line such that the permutation $a_1, a_2, \dots, a_n$ and threshold $k$ produce the sequence $b_1, b_2, \dots, b_n$. If there are multiple solutions, you can output any of them.

## Example

## Input


```

345 3 1 267 7 7 3 3 364 4 4 0 0 0
```
## Output


```

2
1 3 2 4
3
1 2 3 4 5 6
3
6 5 4 3 2 1

```
## Note

For the first test case, permutation $a = [1,3,2,4]$ and threshold $k = 2$ will produce sequence $b$ as follows. 

* When $i = 1$, $x = a_i = 1 \leq k$, there is no $a_j$ ($1 \leq j < i$) that $a_j > k$. Therefore, $b_1 = n + 1 = 5$.
* When $i = 2$, $x = a_i = 3 > k$, the last element $a_j$ that $a_j \leq k$ is $a_1$. Therefore, $b_3 = a_1 = 1$.
* When $i = 3$, $x = a_i = 2 \leq k$, the last element $a_j$ that $a_j > k$ is $a_2$. Therefore, $b_2 = a_2 = 3$.
* When $i = 4$, $x = a_i = 4 > k$, the last element $a_j$ that $a_j \leq k$ is $a_3$. Therefore, $b_4 = a_3 = 2$.

 Finally, we obtain sequence $b = [5,3,1,2]$. For the second test case, permutation $a = [1,2,3,4,5,6]$ and threshold $k = 3$ will produce sequence $b$ as follows. 

* When $i = 1, 2, 3$, $a_i \leq k$, there is no $a_j$ ($1 \leq j < i$) that $a_j > k$. Therefore, $b_1 = b_2 = b_3 = n + 1 = 7$.
* When $i = 4, 5, 6$, $a_i > k$, the last element $a_j$ that $a_j \leq k$ is $a_3$. Therefore, $b_4 = b_5 = b_6 = a_3 = 3$.

 Finally, we obtain sequence $b = [7,7,7,3,3,3]$. For the third test case, permutation $a = [6,5,4,3,2,1]$ and threshold $k = 3$ will produce sequence $b$ as follows. 

* When $i = 1, 2, 3$, $a_i > k$, there is no $a_j$ ($1 \leq j < i$) that $a_j \leq k$. Therefore, $b_4 = b_5 = b_6 = 0$.
* When $i = 4, 5, 6$, $a_i \leq k$, the last element $a_j$ that $a_j > k$ is $a_3$. Therefore, $b_1 = b_2 = b_3 = a_3 = 4$.

 Finally, we obtain sequence $b = [4,4,4,0,0,0]$. 

#### tags 

#1900 #constructive_algorithms #data_structures #dfs_and_similar #dsu #graphs #trees 