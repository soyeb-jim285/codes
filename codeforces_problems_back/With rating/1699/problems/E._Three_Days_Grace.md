<h1 style='text-align: center;'> E. Three Days Grace</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ibti was thinking about a good title for this problem that would fit the round theme (numerus ternarium). He immediately thought about the third derivative, but that was pretty lame so he decided to include the best band in the world — [Three Days Grace](https://www.youtube.com/channel/UCJDON3eLf8709E9YfjAgLOw).

You are given a multiset $A$ with initial size $n$, whose elements are integers between $1$ and $m$. In one operation, do the following: 

* select a value $x$ from the multiset $A$, then
* select two integers $p$ and $q$ such that $p, q > 1$ and $p \cdot q = x$. Insert $p$ and $q$ to $A$, delete $x$ from $A$.

## Note

 that the size of the multiset $A$ increases by $1$ after each operation. 

We define the balance of the multiset $A$ as $\max(a_i) - \min(a_i)$. Find the minimum possible balance after performing any number (possible zero) of operations.

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases.

The second line of each test case contains two integers $n$ and $m$ ($1 \le n \le 10^6$, $1 \le m \le 5 \cdot 10^6$) — the initial size of the multiset, and the maximum value of an element.

The third line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le m$) — the elements in the initial multiset.

It is guaranteed that the sum of $n$ across all test cases does not exceed $10^6$ and the sum of $m$ across all test cases does not exceed $5 \cdot 10^6$.

## Output

For each test case, print a single integer — the minimum possible balance.

## Example

## Input


```

45 102 4 2 4 23 5012 2 32 406 352 51 5
```
## Output


```

0
1
2
4

```
## Note

In the first test case, we can apply the operation on each of the $4$s with $(p,q) = (2,2)$ and make the multiset $\{2,2,2,2,2,2,2\}$ with balance $\max(\{2,2,2,2,2,2,2\}) - \min(\{2,2,2,2,2,2,2\}) = 0$. It is obvious we cannot make this balance less than $0$.

In the second test case, we can apply an operation on $12$ with $(p,q) = (3,4)$. After this our multiset will be $\{3,4,2,3\}$. We can make one more operation on $4$ with $(p,q) = (2,2)$, making the multiset $\{3,2,2,2,3\}$ with balance equal to $1$.

In the third test case, we can apply an operation on $35$ with $(p,q) = (5,7)$. The final multiset is $\{6,5,7\}$ and has a balance equal to $7-5 = 2$.

In the forth test case, we cannot apply any operation, so the balance is $5 - 1 = 4$.



#### tags 

#2600 #data_structures #dp #greedy #math #number_theory #two_pointers 