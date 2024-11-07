<h1 style='text-align: center;'> D. Bananas in a Microwave</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a malfunctioning microwave in which you want to put some bananas. You have $n$ time-steps before the microwave stops working completely. At each time-step, it displays a new operation.

Let $k$ be the number of bananas in the microwave currently. Initially, $k = 0$. In the $i$-th operation, you are given three parameters $t_i$, $x_i$, $y_i$ in the input. Based on the value of $t_i$, you must do one of the following:

Type 1: ($t_i=1$, $x_i$, $y_i$) — pick an $a_i$, such that $0 \le a_i \le y_i$, and perform the following update $a_i$ times: $k:=\lceil (k + x_i) \rceil$.

Type 2: ($t_i=2$, $x_i$, $y_i$) — pick an $a_i$, such that $0 \le a_i \le y_i$, and perform the following update $a_i$ times: $k:=\lceil (k \cdot x_i) \rceil$.

## Note

 that $x_i$ can be a fractional value. See input format for more details. Also, $\lceil x \rceil$ is the smallest integer $\ge x$.

At the $i$-th time-step, you must apply the $i$-th operation exactly once.

For each $j$ such that $1 \le j \le m$, output the earliest time-step at which you can create exactly $j$ bananas. If you cannot create exactly $j$ bananas, output $-1$.

## Input

The first line contains two space-separated integers $n$ $(1 \le n \le 200)$ and $m$ $(2 \le m \le 10^5)$.

Then, $n$ lines follow, where the $i$-th line denotes the operation for the $i$-th timestep. Each such line contains three space-separated integers $t_i$, $x'_i$ and $y_i$ ($1 \le t_i \le 2$, $1\le y_i\le m$).

## Note

 that you are given $x'_i$, which is $10^5 \cdot x_i$. Thus, to obtain $x_i$, use the formula $x_i= \dfrac{x'_i} {10^5}$.

For type 1 operations, $1 \le x'_i \le 10^5 \cdot m$, and for type 2 operations, $10^5 < x'_i \le 10^5 \cdot m$.

## Output

Print $m$ integers, where the $i$-th integer is the earliest time-step when you can obtain exactly $i$ bananas (or $-1$ if it is impossible).

## Examples

## Input


```

3 20
1 300000 2
2 400000 2
1 1000000 3

```
## Output


```

-1 -1 1 -1 -1 1 -1 -1 -1 3 -1 2 3 -1 -1 3 -1 -1 -1 3 

```
## Input


```

3 20
1 399999 2
2 412345 2
1 1000001 3

```
## Output


```

-1 -1 -1 1 -1 -1 -1 1 -1 -1 3 -1 -1 -1 3 -1 2 -1 3 -1 

```
## Note

In the first sample input, let us see how to create $16$ number of bananas in three timesteps. Initially, $k=0$.

* In timestep 1, we choose $a_1=2$, so we apply the type 1 update — $k := \lceil(k+3)\rceil$ — two times. Hence, $k$ is now 6.
* In timestep 2, we choose $a_2=0$, hence value of $k$ remains unchanged.
* In timestep 3, we choose $a_3=1$, so we are applying the type 1 update $k:= \lceil(k+10)\rceil$ once. Hence, $k$ is now 16.

It can be shown that $k=16$ cannot be reached in fewer than three timesteps with the given operations.

In the second sample input, let us see how to create $17$ number of bananas in two timesteps. Initially, $k=0$.

* In timestep 1, we choose $a_1=1$, so we apply the type 1 update — $k := \lceil(k+3.99999)\rceil$ — once. Hence, $k$ is now 4.
* In timestep 2, we choose $a_2=1$, so we apply the type 2 update — $k := \lceil(k\cdot 4.12345)\rceil$ — once. Hence, $k$ is now 17.

It can be shown that $k=17$ cannot be reached in fewer than two timesteps with the given operations.



#### tags 

#2200 #dfs_and_similar #dp #graphs #implementation 