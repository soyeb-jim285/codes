<h1 style='text-align: center;'> D. Tenzing and His Animal Friends </h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tell a story about me and my animal friends.Tenzing has $n$ animal friends. He numbers them from $1$ to $n$.

One day Tenzing wants to play with his animal friends. To do so, Tenzing will host several games.

In one game, he will choose a set $S$ which is a subset of $\{1,2,3,...,n\}$ and choose an integer $t$. Then, he will play the game with the animals in $S$ for $t$ minutes.

But there are some restrictions: 

1. Tenzing loves friend $1$ very much, so $1$ must be an element of $S$.
2. Tenzing doesn't like friend $n$, so $n$ must not be an element of $S$.
3. There are m additional restrictions. The $i$-th special restriction is described by integers $u_i$, $v_i$ and $y_i$, suppose $x$ is the total time that exactly one of $u_i$ and $v_i$ is playing with Tenzing. Tenzing must ensure that $x$ is less or equal to $y_i$. Otherwise, there will be unhappiness.

Tenzing wants to know the maximum total time that he can play with his animal friends. Please find out the maximum total time that Tenzing can play with his animal friends and a way to organize the games that achieves this maximum total time, or report that he can play with his animal friends for an infinite amount of time. Also, Tenzing does not want to host so many games, so he will host at most $n^2$ games.

## Input

The first line of input contains two integers $n$ and $m$ ($2 \leq n \leq 100$, $0 \leq m \leq \frac{n(n-1)}{2}$) — the number of animal friends and the number of special restrictions.

The $i$-th of the following $m$ lines of input contains three integers $u_i$, $v_i$ and $y_i$ ($1\leq u_i<v_i\leq n$, $0\leq y_i\leq 10^9$) — describing the $i$-th special restriction. It is guaranteed that for $1 \leq i < j \leq m$, $(u_i,v_i) \neq (u_j,v_j)$.

## Output

If Tenzing can play with his animal friends for an infinite amount of time, output "inf". (## Output

 without quotes.)

Otherwise, in the first line, output the total time $T$ ($0 \leq t \leq 10^{18}$) and the number of games $k$ ($0 \leq k \leq n^2$).

In the following $k$ lines of output, output a binary string $s$ of length $n$ and an integer $t$ ($0 \leq t \leq 10^{18}$) — representing the set $S$ and the number of minutes this game will be played. If $s_i=\texttt{1}$, then $i \in S$, otherwise if $s_i=\texttt{0}$, then $i \notin S$.

Under the constraints of this problem, it can be proven that if Tenzing can only play with his friends for a finite amount of time, then he can only play with them for at most $10^{18}$ minutes.

## Examples

## Input


```

5 4
1 3 2
1 4 2
2 3 1
2 5 1

```
## Output


```

4 4
10000 1
10010 1
10100 1
11110 1

```
## Input


```

3 0

```
## Output


```

inf

```
## Note

In the first test case: 

1. Tenzing will host a game with friend $\{1\}$ for $1$ minute.
2. Tenzing will host a game with friends $\{1,4\}$ for $1$ minute.
3. Tenzing will host a game with friends $\{1,3\}$ for $1$ minute.
4. Tenzing will host a game with friends $\{1,2,3,4\}$ for $1$ minute.

If after that, Tenzing host another game with friends $\{1,2\}$ for $1$ minute. Then the time of exactly one of friends $2$ or $3$ with Tenzing will becomes $2$ minutes which will not satisfy the $3$-rd special restriction.

In the second test case, there is no special restrictions. So Tenzing can host a game with friend $\{1\}$ for an infinite amount of time.



#### tags 

#1900 #constructive_algorithms #graphs #greedy 