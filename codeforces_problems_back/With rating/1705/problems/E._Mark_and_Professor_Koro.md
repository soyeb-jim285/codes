<h1 style='text-align: center;'> E. Mark and Professor Koro</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After watching a certain anime before going to sleep, Mark dreams of standing in an old classroom with a blackboard that has a sequence of $n$ positive integers $a_1, a_2,\dots,a_n$ on it.

Then, professor Koro comes in. He can perform the following operation:

* select an integer $x$ that appears at least $2$ times on the board,
* erase those $2$ appearances, and
* write $x+1$ on the board.

Professor Koro then asks Mark the question, "what is the maximum possible number that could appear on the board after some operations?"

Mark quickly solves this question, but he is still slower than professor Koro. Thus, professor Koro decides to give Mark additional challenges. He will update the initial sequence of integers $q$ times. Each time, he will choose positive integers $k$ and $l$, then change $a_k$ to $l$. After each update, he will ask Mark the same question again.

Help Mark answer these questions faster than Professor Koro!

## Note

 that the updates are persistent. Changes made to the sequence $a$ will apply when processing future updates.

## Input

The first line of the input contains two integers $n$ and $q$ ($2\leq n\leq 2\cdot 10^5$, $1\leq q\leq 2\cdot 10^5$) — the length of the sequence $a$ and the number of updates, respectively.

The second line contains $n$ integers $a_1,a_2,\dots,a_n$ ($1\leq a_i\leq 2\cdot 10^5$)

Then, $q$ lines follow, each consisting of two integers $k$ and $l$ ($1\leq k\leq n$, $1\leq l\leq 2\cdot 10^5$), telling to update $a_k$ to $l$.

## Output

Print $q$ lines. The $i$-th line should consist of a single integer — the answer after the $i$-th update.

## Examples

## Input


```

5 4
2 2 2 4 5
2 3
5 3
4 1
1 4

```
## Output


```

6
5
4
5

```
## Input


```

2 1
200000 1
2 200000

```
## Output


```

200001

```
## Note

In the first example test, the program must proceed through $4$ updates.

The sequence after the first update is $[2,3,2,4,5]$. One sequence of operations that achieves the number $6$ the following. 

* Initially, the blackboard has numbers $[2,3,2,4,5]$.
* Erase two copies of $2$ and write $3$, yielding $[3,4,5,\color{red}{3}]$.
* Erase two copies of $3$ and write $4$, yielding $[4,5,\color{red}{4}]$.
* Erase two copies of $4$ and write $5$, yielding $[5,\color{red}{5}]$.
* Erase two copies of $5$ and write $6$, yielding $[\color{red}{6}]$.

Then, in the second update, the array is changed to $[2,3,2,4,3]$. This time, Mark cannot achieve $6$. However, one sequence that Mark can use to achieve $5$ is shown below. 

* Initially, the blackboard has $[2,3,2,4,3]$.
* Erase two copies of $2$ and write $3$, yielding $[3,4,3,\color{red}{3}]$.
* Erase two copies of $3$ and write $4$, yielding $[3,4,\color{red}{4}]$.
* Erase two copies of $4$ and write $5$, yielding $[3,\color{red}{5}]$.

In the third update, the array is changed to $[2,3,2,1,3]$. One way to achieve $4$ is shown below. 

* Initially, the blackboard has $[2,3,2,1,3]$.
* Erase two copies of $3$ and write $4$, yielding $[2,2,1,\color{red}{4}]$.


#### tags 

#2300 #binary_search #bitmasks #brute_force #combinatorics #data_structures #greedy 