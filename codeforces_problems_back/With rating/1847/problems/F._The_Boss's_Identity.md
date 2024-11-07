<h1 style='text-align: center;'> F. The Boss's Identity</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

While tracking Diavolo's origins, Giorno receives a secret code from Polnareff. The code can be represented as an infinite sequence of positive integers: $a_1, a_2, \dots $. Giorno immediately sees the pattern behind the code. The first $n$ numbers $a_1, a_2, \dots, a_n$ are given. For $i > n$ the value of $a_i$ is $(a_{i-n}\ |\ a_{i-n+1})$, where $|$ denotes the [bitwise OR operator](https://en.wikipedia.org/wiki/Bitwise_operation#OR).

Pieces of information about Diavolo are hidden in $q$ questions. Each question has a positive integer $v$ associated with it and its answer is the smallest index $i$ such that $a_i > v$. If no such $i$ exists, the answer is $-1$. Help Giorno in answering the questions!

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $q$ ($2 \leq n \leq 2 \cdot 10^5$ , $1 \leq q \leq 2 \cdot 10^5$).

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($0 \leq a_i \leq 10^9$) — the parts of the code which define the pattern.

The $i$-th line of the next $q$ lines contain a single integer $v_i$ ($0 \leq v_i \leq 10^9$) — the question Giorno asks you.

The sum of $n$ and $q$ over all test cases does not exceed $2 \cdot 10^5$. 

## Output

Print $q$ numbers. The $i$-th number is the answer to the $i$-th question asked by Giorno.

## Example

## Input


```

32 32 11234 50 2 1 3012345 51 2 3 4 572604
```
## Output


```

1
3
-1
2
2
4
-1
-1
-1
3
8
1
5

```
## Note

In the first test case, $a = [2,1,3,3,\ldots]$. 

* For the first question, $a_1=2$ is the element with the smallest index greater than $1$.
* For the second question, $a_3=3$ is the element with the smallest index greater than $2$.
* For the third question, there is no index $i$ such that $a_i > 3$.


#### tags 

#2500 #binary_search #bitmasks #data_structures #dfs_and_similar #greedy #math #sortings 