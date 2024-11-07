<h1 style='text-align: center;'> D. The Omnipotent Monster Killer</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You, the monster killer, want to kill a group of monsters. The monsters are on a tree with $n$ vertices. On vertex with number $i$ ($1\le i\le n$), there is a monster with $a_i$ attack points. You want to battle with monsters for $10^{100}$ rounds. 

In each round, the following happens in order:

1. All living monsters attack you. Your health decreases by the sum of attack points of all living monsters.
2. You select some (possibly all or none) monsters and kill them. After being killed, the monster will not be able to do any attacks in the future.

There is a restriction: in one round, you cannot kill two monsters that are directly connected by an edge.

If you choose what monsters to attack optimally, what is the smallest health decrement you can have after all rounds?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). Description of the test cases follows.

The first line of each test case contains an integer $n$ ($1\le n\le 3\cdot 10^5$).

The second line of each test case contains $n$ integers $a_1,\ldots,a_n$ ($1\le a_i\le 10^{12}$).

The following $n-1$ lines each contain two integers $x,y$ ($1\le x,y\le n$), denoting an edge on the tree connecting vertex $x$ and $y$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3\cdot 10^5$.

## Output

For each test case, print one integer: the minimum possible health decrement.

## Example

## Input


```

311000000000000547 15 32 29 231 21 32 42 578 10 2 3 5 7 41 21 43 25 36 27 5
```
## Output


```

1000000000000
193
57

```
## Note

In the first test case, an optimal sequence of operations would be: 

* In the first round: first, receive the attack from the monster on vertex $1$, so your health decreases by $10^{12}$. Then kill the monster on vertex $1$.
* In the second round to the $10^{100}$-th round: all monsters have been killed, so nothing happens.

The total health decrement is $10^{12}$.

In the second test case, an optimal sequence of operations would be: 

* In the first round: first, receive the attack from the monster on vertex $1,2,3,4,5$, so your health decreases by $47+15+32+29+23=146$. Then kill the monsters on vertex $1,4,5$.
* In the second round: first, receive the attack from the monster on vertex $2,3$, so your health decreases by $15+32=47$. Then kill the monsters on vertex $2,3$.
* In the third round to the $10^{100}$-th round: all monsters have been killed, so nothing happens.

The total health decrement is $193$.

In the third test case, an optimal sequence of operations would be: 

* In the first round: first, receive the attack from the monster on vertex $1,2,3,4,5,6,7$, so your health decreases by $8+10+2+3+5+7+4=39$. Then kill the monsters on vertex $1,3,6,7$.
* In the second round: first, receive the attack from the monster on vertex $2,4,5$, so your health decreases by $10+3+5=18$. Then kill the monsters on vertex $2,4,5$.
* In the third round to the $10^{100}$-th round: all monsters have been killed, so nothing happens.

The total health decrement is $57$.



#### tags 

#2000 #brute_force #dfs_and_similar #dp #trees 