<h1 style='text-align: center;'> C. Segment tree or Fenwick?</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an unusual problem in an unusual contest, here is the announcement: [http://codeforces.com/blog/entry/73543](//codeforces.com/blog/entry/73543)

You are given an array $A$ of length $n$, initially filled with zeros. You need to process $q$ queries to the array, each of one of the following types: 

1. 1 x y: you need to assign $A_x=y$;
2. 2 l r: you need to print $\sum\limits_{i=l}^r A_i$.

 Furthermore, there are $T$ independent tests you need to process.## Input

The first line contains an integer $T$ ($1 \leq T \leq 10^5$) — the number of test cases.

Each test case description starts with two integers $n, q$ ($1 \leq n, q \leq 10^5$) — the length of the array and the number of queries. The following $q$ lines contain the description of queries: $1~x~y$ ($1 \leq x \leq n$, $0 \leq y \leq 10^9$) for queries of the first type and $2~l~r$ ($1 \leq l \leq r \leq n$) for queries of the second type. 

It is guaranteed that the sum of $n$ as well as the sum of $q$ does not exceed $10^6$.

## Output

For each query of the second type print its result on a separate line.

## Example

## Input


```

2
6 5
2 1 6
1 3 2
2 2 4
1 6 3
2 1 6
5 3
1 3 7
1 1 4
2 1 5

```
## Output


```

0
2
5
11

```


#### tags 

#data_structures 