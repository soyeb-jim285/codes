<h1 style='text-align: center;'> B. Divine Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Black is gifted with a Divine array $a$ consisting of $n$ ($1 \le n \le 2000$) integers. Each position in $a$ has an initial value. After shouting a curse over the array, it becomes angry and starts an unstoppable transformation.

The transformation consists of infinite steps. Array $a$ changes at the $i$-th step in the following way: for every position $j$, $a_j$ becomes equal to the number of occurrences of $a_j$ in $a$ before starting this step.

Here is an example to help you understand the process better: 

 

| Initial array: | $2$ $1$ $1$ $4$ $3$ $1$ $2$ |
| --- | --- |
| After the $1$-st step: | $2$ $3$ $3$ $1$ $1$ $3$ $2$ |
| After the $2$-nd step: | $2$ $3$ $3$ $2$ $2$ $3$ $2$ |
| After the $3$-rd step: | $4$ $3$ $3$ $4$ $4$ $3$ $4$ |
| ... | ... |

 In the initial array, we had two $2$-s, three $1$-s, only one $4$ and only one $3$, so after the first step, each element became equal to the number of its occurrences in the initial array: all twos changed to $2$, all ones changed to $3$, four changed to $1$ and three changed to $1$.

The transformation steps continue forever.

You have to process $q$ queries: in each query, Black is curious to know the value of $a_x$ after the $k$-th step of transformation.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). Description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 2000$) — the size of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$) — the initial values of array $a$.

The third line of each test case contains a single integer $q$ ($1 \le q \le 100\,000$) — the number of queries.

Next $q$ lines contain the information about queries — one query per line. The $i$-th line contains two integers $x_i$ and $k_i$ ($1 \le x_i \le n$; $0 \le k_i \le 10^9$), meaning that Black is asking for the value of $a_{x_i}$ after the $k_i$-th step of transformation. $k_i = 0$ means that Black is interested in values of the initial array.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2000$ and the sum of $q$ over all test cases doesn't exceed $100\,000$.

## Output

For each test case, print $q$ answers. The $i$-th of them should be the value of $a_{x_i}$ after the $k_i$-th step of transformation. It can be shown that the answer to each query is unique.

## Example

## Input


```

2
7
2 1 1 4 3 1 2
4
3 0
1 1
2 2
6 1
2
1 1
2
1 0
2 1000000000

```
## Output


```

1
2
3
3
1
2

```
## Note

The first test case was described ih the statement. It can be seen that: 

1. $k_1 = 0$ (initial array): $a_3 = 1$;
2. $k_2 = 1$ (after the $1$-st step): $a_1 = 2$;
3. $k_3 = 2$ (after the $2$-nd step): $a_2 = 3$;
4. $k_4 = 1$ (after the $1$-st step): $a_6 = 3$.

For the second test case, 

| Initial array: | $1$ $1$ |
| --- | --- |
| After the $1$-st step: | $2$ $2$ |
| After the $2$-nd step: | $2$ $2$ |
| ... | ... |



It can be seen that: 

1. $k_1 = 0$ (initial array): $a_1 = 1$;
2. $k_2 = 1000000000$: $a_2 = 2$;


#### tags 

#1100 #constructive_algorithms #implementation 