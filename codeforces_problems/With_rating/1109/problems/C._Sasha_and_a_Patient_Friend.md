<h1 style='text-align: center;'> C. Sasha and a Patient Friend</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fedya and Sasha are friends, that's why Sasha knows everything about Fedya.

Fedya keeps his patience in an infinitely large bowl. But, unlike the bowl, Fedya's patience isn't infinite, that is why let $v$ be the number of liters of Fedya's patience, and, as soon as $v$ becomes equal to $0$, the bowl will burst immediately. There is one tap in the bowl which pumps $s$ liters of patience per second. Notice that $s$ can be negative, in that case, the tap pumps out the patience. Sasha can do different things, so he is able to change the tap's speed. All actions that Sasha does can be represented as $q$ queries. There are three types of queries:

1. "1 t s"  — add a new event, means that starting from the $t$-th second the tap's speed will be equal to $s$.
2. "2 t"  — delete the event which happens at the $t$-th second. It is guaranteed that such event exists.
3. "3 l r v" — Sasha wonders: if you take all the events for which $l \le t \le r$ and simulate changes of Fedya's patience from the very beginning of the $l$-th second till the very beginning of the $r$-th second inclusive (the initial volume of patience, at the beginning of the $l$-th second, equals to $v$ liters) then when will be the moment when the bowl will burst. If that does not happen, then the answer will be $-1$.

Since Sasha does not want to check what will happen when Fedya's patience ends, and he has already come up with the queries, he is asking you to help him and find the answer for each query of the $3$-rd type.

It is guaranteed that at any moment of time, there won't be two events which happen at the same second.

##### Input

The first line contans one integer $q$ ($1 \le q \le 10^5$)  — the number of queries.

Each of the next $q$ lines have one of the following formats:

* 1 t s ($1 \le t \le 10^9$, $-10^9 \le s \le 10^9$), means that a new event is added, which means that starting from the $t$-th second the tap's speed will be equal to $s$.
* 2 t ($1 \le t \le 10^9$), means that the event which happens at the $t$-th second must be deleted. Guaranteed that such exists.
* 3 l r v ($1 \le l \le r \le 10^9$, $0 \le v \le 10^9$), means that you should simulate the process from the very beginning of the $l$-th second till the very beginning of the $r$-th second inclusive, and to say when will the bowl burst.

It is guaranteed that $t$, $s$, $l$, $r$, $v$ in all the queries are integers.

Also, it is guaranteed that there is at least one query of the $3$-rd type, and there won't be a query of the $1$-st type with such $t$, that there already exists an event which happens at that second $t$.

##### Output

For each query of the $3$-rd type, print in a new line the moment when the bowl will burst or print $-1$ if it won't happen.

Your answer will be considered correct if it's absolute or relative error does not exceed $10^{-6}$.

Formally, let your answer be $a$, and the jury's answer be $b$. Your answer is accepted if and only if $\frac{|a - b|}{\max{(1, |b|)}} \le 10^{-6}$.

## Examples

##### Input


```text
6
1 2 1
1 4 -3
3 1 6 1
3 1 6 3
3 1 6 4
3 1 6 5
```
##### Output


```text
5
5.666667
6
-1
```
##### Input


```text
10
1 2 2
1 4 4
1 7 -10
3 2 4 1
3 5 6 0
3 1 15 1
2 4
3 1 15 1
1 8 1
3 1 15 1
```
##### Output


```text
-1
5
8.7
8.1
-1
```
##### Input


```text
5
1 1000 9999999
1 2000 -9999
3 1000 2000 0
2 1000
3 1000 2002 1
```
##### Output


```text
1000
2000.0001
```
## Note

In the first example all the queries of the $3$-rd type cover all the events, it's simulation is following:

![](images/f388696f3778cced2285fcbb63fc871642898d25.png)



#### Tags 

#2800 #NOT OK #binary_search #data_structures #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_539_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
