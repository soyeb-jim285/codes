<h1 style='text-align: center;'> F. Kazaee</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a$ consisting of $n$ positive integers and you have to handle $q$ queries of the following types:

* $1$ $i$ $x$: change $a_{i}$ to $x$,
* $2$ $l$ $r$ $k$: check if the number of occurrences of every positive integer in the subarray $a_{l}, a_{l+1}, \ldots a_{r}$ is a multiple of $k$ (check the example for better understanding).
## Input

The first line of the input contains two integers $n$ and $q$ ($1 \le n , q \le 3 \cdot 10^5$), the length of $a$ and the number of queries.

Next line contains $n$ integers $a_{1}, a_{2}, \ldots a_{n}$ ($1 \le a_{i} \le 10^9$) — the elements of $a$.

Each of the next $q$ lines describes a query. It has one of the following forms.

* $1$ $i$ $x$, ($1 \le i \le n$ , $1 \le x \le 10^9$), or
* $2$ $l$ $r$ $k$, ($1 \le l \le r \le n$ , $1 \le k \le n$).
## Output

For each query of the second type, if answer of the query is yes, print "YES", otherwise print "NO".

## Example

## Input


```
10 8  
1234 2 3 3 2 1 1 2 3 4  
2 1 6 2  
1 1 1  
2 1 6 2  
2 1 9 2  
1 10 5  
2 1 9 3  
1 3 5  
2 3 10 2  

```
## Output


```
NO  
YES  
NO  
YES  
YES  

```
## Note

In the first query, requested subarray is $[1234, 2, 3, 3, 2, 1]$, and it's obvious that the number of occurrence of $1$ isn't divisible by $k = 2$. So the answer is "NO".

In the third query, requested subarray is $[1, 2, 3, 3, 2, 1]$, and it can be seen that the number of occurrence of every integer in this sub array is divisible by $k = 2$. So the answer is "YES".

In the sixth query, requested subarray is $[1, 2, 3, 3, 2, 1, 1, 2, 3]$, and it can be seen that the number of occurrence of every integer in this sub array is divisible by $k = 3$. So the answer is "YES".



#### tags 

#2800 #data_structures #hashing #probabilities 