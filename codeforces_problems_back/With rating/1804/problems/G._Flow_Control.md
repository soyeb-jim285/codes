<h1 style='text-align: center;'> G. Flow Control</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Raj has a single physical network line that connects his office to the Internet. This line bandwidth is $b$ bytes per millisecond.

There are $n$ users who would like to use this network line to transmit some data. The $i$-th of them will use the line from millisecond $s_i$ to millisecond $f_i$ inclusive. His initial data rate will be set to $d_i$. That means he will use data rate equal to $d_i$ for millisecond $s_i$, and then it will change according to the procedure described below.

The flow control will happen as follows. Suppose there are $m$ users trying to transmit some data via the given network line during millisecond $x$. Denote as $t_i$ the data rate that the $i$-th of these $m$ users has at the beginning of this millisecond. All $t_i$ are non-negative integer values. 

1. If $m = 0$, i. e. there are no users trying to transmit data during this millisecond, nothing happens.
2. If the sum of all $t_i$ is less than or equal to $b$, each active user successfully completes his transmission (the $i$-th active user transmits $t_i$ bytes). After that, the data rate of each active user grows by $1$, i. e. each $t_i$ is increased by $1$.
3. If the sum of all $t_i$ is greater than $b$, the congestion occurs and no data transmissions succeed this millisecond at all. If that happens, each $t_i$ decreases twice, i. e. each $t_i$ is replaced with $\lfloor \frac{t_i}{2} \rfloor$.

Raj knows all the values $n$, $b$, $s_i$, $f_i$, and $d_i$, he wants to calculate the total number of bytes transmitted by all the users in the aggregate.

## Input

The first line of the input contains two integers $n$ and $b$ ($1 \leq n \leq 2 \cdot 10^5$, $1 \leq b \leq 10^9$), the number of users who will use the line and the line bandwidth, respectively.

Each of the following $n$ lines contains three integers $s_i$, $f_i$ and $d_i$ ($1 \leq s_i \leq f_i \leq 10^9$, $1 \leq d_i \leq 10^9$), denoting that the $i$-th user will try to transmit data during each millisecond between $s_i$ and $f_i$ inclusive, and the initial data rate of the $i$-th user.

## Output

Print one integer — the total number of bytes all users will successfully transmit.

## Examples

## Input


```

1 3
1 5 2

```
## Output


```

10

```
## Input


```

1 10
7 11 1000

```
## Output


```

0

```
## Input


```

2 6
1 12 1
8 20 3

```
## Output


```

64

```
## Input


```

3 10
1 100 1
30 60 20
40 80 6

```
## Output


```

534

```
## Note

Consider the first example.

* Millisecond $1$: User $1$ transmits $2$ bytes.
* Millisecond $2$: User $1$ transmits $3$ bytes.
* Millisecond $3$: Congestion occurs, and no user transmits data.
* Millisecond $4$: User $1$ transmits $2$ bytes.
* Millisecond $5$: User $1$ transmits $3$ bytes.

In the second example, at each millisecond from the $7$-th to the $11$-th inclusive, congestion occurs, and the only user decreases their rate twice. However, they don't decrease the speed enough before disconnecting.

Consider the third example.

* Millisecond $1$: User $1$ transmits $1$ bytes.
* Millisecond $2$: User $1$ transmits $2$ bytes.
* Millisecond $3$: User $1$ transmits $3$ bytes.
* Millisecond $4$: User $1$ transmits $4$ bytes.
* Millisecond $5$: User $1$ transmits $5$ bytes.
* Millisecond $6$: User $1$ transmits $6$ bytes.
* Millisecond $7$: Congestion occurs, and no user transmits data.
* Millisecond $8$: User $1$ transmits $3$ bytes. User $2$ transmits $3$ bytes.
* Millisecond $9$: Congestion occurs, and no user transmits data.
* Millisecond $10$: User $1$ transmits $2$ bytes. User $2$ transmits $2$ bytes.
* Millisecond $11$: User $1$ transmits $3$ bytes. User $2$ transmits $3$ bytes.
* Millisecond $12$: Congestion occurs, and no user transmits data.
* Millisecond $13$: User $2$ transmits $2$ bytes.
* Millisecond $14$: User $2$ transmits $3$ bytes.
* Millisecond $15$: User $2$ transmits $4$ bytes.
* Millisecond $16$: User $2$ transmits $5$ bytes.
* Millisecond $17$: User $2$ transmits $6$ bytes.
* Millisecond $18$: Congestion occurs, and no user transmits data.
* Millisecond $19$: User $2$ transmits $3$ bytes.
* Millisecond $20$: User $2$ transmits $4$ bytes.


#### tags 

#3500 #data_structures #dsu #implementation 