<h1 style='text-align: center;'> F. Panda Meetups</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The red pandas are in town to meet their relatives, the blue pandas! The town is modeled by a number line.

The pandas have already planned their meetup, but the schedule keeps changing. You are given $q$ updates of the form x t c.

* If $c < 0$, it means $|c|$ more red pandas enter the number line at position $x$ and time $t$. Then, each unit of time, they can each independently move one unit in either direction across the number line, or not move at all.
* If $c > 0$, it means that $c$ more blue pandas check position $x$ for red pandas at time $t$. If a blue panda does not meet a red panda at that specific location and time, they dejectedly leave the number line right away. If there is a red panda at a position at the same time a blue panda checks it, they form a friendship and leave the number line. Each red panda can form a friendship with at most one blue panda and vice versa.

The updates will be given in order of non-decreasing $x$ values. After each update, please print the maximum number of friendships if the red pandas move in an optimal order based on all the updates given in the input above (and including) this update. 

The order in which a red panda moves can change between updates.

## Input

The first line contains $q$ ($1 \leq q \leq 2 \cdot 10^5$)  – the number of updates.

The $i$-th line of the next $q$ lines consists of $3$ integers $x_i$, $t_i$ and $c_i$ ($0 \leq x_i \leq 10^9$, $0 \leq t_i \leq 10^9$, $0 < |c_i| \leq 1000$) – the description of the $i$-th update.

It is guaranteed that the $x_i$ will be given in non-decreasing order.

## Output

After each update, print the maximum number of friendships that can be formed. 

## Examples

## Input


```

5
0 6 3
4 2 -5
7 4 -6
10 5 100
10 8 7

```
## Output


```

0
3
3
3
10

```
## Input


```

5
0 6 3
4 2 -5
7 4 -6
10 5 100
11 8 7

```
## Output


```

0
3
3
3
9

```
## Input


```

7
0 8 6
2 7 -2
3 1 -6
5 3 -8
7 3 -3
8 0 -2
8 2 1

```
## Output


```

0
0
6
6
6
6
7

```
## Input


```

4
0 0 -3
0 0 2
0 0 4
0 0 -10

```
## Output


```

0
2
3
6

```
## Note

In the first example, the number of friendships after each update can be optimized as follows: 

1. $3$ blue pandas now check for red pandas at position $0$ at time $6$. There are no red pandas anywhere, so there are no friendships.
2. $5$ red pandas now appear at position $4$ and time $2$. $4$ of the red pandas can travel to position $0$ at time $6$, where $3$ of them can make friendships with the $3$ existing blue pandas.
3. $6$ red pandas now appear at position $7$ and time $4$. No new blue pandas are added, so the maximum number of friendships is still $3$.
4. $100$ blue pandas now appear at position $10$ and time $5$. No red pandas can reach them at a time of $5$, so no new friendships are created.
5. $7$ blue pandas now appear at position $10$ and time $8$. $6$ of the red pandas at position $7$ and time $4$, along with $1$ red panda at position $4$ and time $2$, can reach $7$ of the blue pandas at position $10$ at time $8$, adding $7$ new friendships. This brings the total to $10$ friendships.


#### tags 

#3500 #data_structures #dp #flows 