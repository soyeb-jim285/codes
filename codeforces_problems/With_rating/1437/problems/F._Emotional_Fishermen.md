<h1 style='text-align: center;'> F. Emotional Fishermen</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

$n$ fishermen have just returned from a fishing vacation. The $i$-th fisherman has caught a fish of weight $a_i$.

Fishermen are going to show off the fish they caught to each other. To do so, they firstly choose an order in which they show their fish (each fisherman shows his fish exactly once, so, formally, the order of showing fish is a permutation of integers from $1$ to $n$). Then they show the fish they caught according to the chosen order. When a fisherman shows his fish, he might either become happy, become sad, or stay content.

Suppose a fisherman shows a fish of weight $x$, and the maximum weight of a previously shown fish is $y$ ($y = 0$ if that fisherman is the first to show his fish). Then:

* if $x \ge 2y$, the fisherman becomes happy;
* if $2x \le y$, the fisherman becomes sad;
* if none of these two conditions is met, the fisherman stays content.

Let's call an order in which the fishermen show their fish emotional if, after all fishermen show their fish according to this order, each fisherman becomes either happy or sad. Calculate the number of emotional orders modulo $998244353$.

###### Input

The first line contains one integer $n$ ($2 \le n \le 5000$).

The second line contains $n$ integers $a_1$, $a_2$, ..., $a_n$ ($1 \le a_i \le 10^9$).

###### Output

Print one integer — the number of emotional orders, taken modulo $998244353$.

## Examples

###### Input


```text
4
1 1 4 9
```
###### Output


```text
20
```
###### Input


```text
4
4 3 2 1
```
###### Output


```text
0
```
###### Input


```text
3
4 2 1
```
###### Output


```text
6
```
###### Input


```text
8
42 1337 13 37 420 666 616 97
```
###### Output


```text
19200
```


#### Tags 

#2600 #NOT OK #combinatorics #dp #math #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_97_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
