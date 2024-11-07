<h1 style='text-align: center;'> H. Make Square</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

We call an array $b_1, b_2, \ldots, b_m$ good, if there exist two indices $i < j$ such that $b_i \cdot b_j$ is a [perfect square](https://en.wikipedia.org/wiki/Square_number).

Given an array $b_1, b_2, \ldots, b_m$, in one action you can perform one of the following: 

* multiply any element $b_i$ by any prime $p$;
* divide any element $b_i$ by prime $p$, if $b_i$ is divisible by $p$.

Let $f(b_1, b_2, \ldots, b_m)$ be the minimum number of actions needed to make the array $b$ good.

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries of the form $l_i, r_i$. For each query output $f(a_{l_i}, a_{l_i + 1}, \ldots, a_{r_i})$.

## Input

The first line contains two integers $n$ and $q$ ($2 \le n \le 194\,598$, $1 \le q \le 1\,049\,658$) — the length of the array and the number of queries.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 5\,032\,107$) — the elements of the array.

Each of the next $q$ lines contains two integers $l_i$ and $r_i$ ($1 \le l_i < r_i \le n$) — the parameters of a query.

## Output

## Output

 $q$ lines — the answers for each query in the order they are given in the input.

## Example

## Input


```
10 10  
34 37 28 16 44 36 43 50 22 13  
1 3  
4 8  
6 10  
9 10  
3 10  
8 9  
5 6  
1 4  
1 7  
2 6  

```
## Output


```
2  
0  
1  
3  
0  
1  
1  
1  
0  
0  

```
## Note

In the first query of the first sample you can multiply second number by 7 to get 259 and multiply the third one by 37 to get 1036. Then $a_2 \cdot a_3 = 268\,324 = 518^2$.

In the second query subarray is already good because $a_4 \cdot a_6 = 24^2$.

In the third query you can divide 50 by 2 to get 25. Then $a_6 \cdot a_8 = 30^2$.



#### tags 

#2900 #math 