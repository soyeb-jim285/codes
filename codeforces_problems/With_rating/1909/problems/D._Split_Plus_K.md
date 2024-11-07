<h1 style='text-align: center;'> D. Split Plus K</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[eliteLAQ - Desert Ruins](https://soundcloud.com/lux-gg-198448038/desert-ruins)⠀There are $n$ positive integers $a_1, a_2, \dots, a_n$ on a blackboard. You are also given a positive integer $k$. You can perform the following operation some (possibly $0$) times:

* choose a number $x$ on the blackboard;
* erase one occurrence of $x$;
* write two positive integers $y$, $z$ such that $y+z = x+k$ on the blackboard.

Is it possible to make all the numbers on the blackboard equal? If yes, what is the minimum number of operations you need?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$, $k$ ($1 \le n \le 2 \cdot 10^5$, $1 \leq k \leq 10^{12}$) — the number of integers initially on the blackboard and the constant $k$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^{12}$) — the initial state of the blackboard.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single line containing an integer: the minimum number of operations you need to make all the numbers on the blackboard equal, or $-1$ if it is impossible.

## Example

### Input


```text
92 13 42 37 113 10100 40 1002 11 22 21 21 3278695413278695415 26250314066439986238782 581370817372 409476934981 287439719777 7376379831825 616753575719321037808624 222034505841 214063039282 441536506916 4640979418195 431813672576393004301966 405902283416 900951084746 672201172466 518769038906
```
### Output

```text

3
1
4
-1
-1
0
3119
28999960732
-1

```
## Note

In the first test case, $k = 1$. You can make all the numbers on the blackboard equal to $2$ with the following operations: 

* Erase $x = 4$ and write $(y, z) = (2, 3)$. 
## Note

 that $y+z=x+k$. The blackboard now contains the multiset $\{3, 2, 3\}$.
* Erase $x = 3$ and write $(y, z) = (2, 2)$. 
## Note

 that $y+z=x+k$. The blackboard now contains $\{2, 2, 2, 3\}$.
* Erase $x = 3$ and write $(y, z) = (2, 2)$. 
## Note

 that $y+z=x+k$. The blackboard now contains $\{2, 2, 2, 2, 2\}$.

This makes all the numbers equal in $3$ operations. It can be shown that you cannot make all the numbers equal in less than $3$ operations.

In the second test case, $k = 3$. You can make all the numbers on the blackboard equal to $7$ with the following operation: 

* Erase $x = 11$ and write $(y, z) = (7, 7)$. 
## Note

 that $y+z=x+k$. The blackboard now contains $\{7, 7, 7\}$.

In the third test case, $k = 10$. You can make all the numbers on the blackboard equal to $40$ with the following operations: 

* Erase $x = 100$ and write $(y, z) = (70, 40)$. 
## Note

 that $y+z=x+k$. The blackboard now contains $\{70, 40, 40, 100\}$.
* Erase $x = 70$ and write $(y, z) = (40, 40)$. 
## Note

 that $y+z=x+k$. The blackboard now contains $\{40, 40, 40, 40, 100\}$.
* Erase $x = 100$ and write $(y, z) = (40, 70)$. 
## Note

 that $y+z=x+k$. The blackboard now contains $\{40, 40, 40, 40, 40, 70\}$.
* Erase $x = 70$ and write $(y, z) = (40, 40)$. 
## Note

 that $y+z=x+k$. The blackboard now contains $\{40, 40, 40, 40, 40, 40, 40\}$.

In the fourth and in the fifth test case, you can show that it is impossible to make all the numbers on the blackboard equal.



#### Tags 

#1900 #NOT OK #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Pinely_Round_3_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
