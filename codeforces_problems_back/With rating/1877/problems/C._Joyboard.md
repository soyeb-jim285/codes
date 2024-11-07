<h1 style='text-align: center;'> C. Joyboard</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Chaneka, a gamer kid, invented a new gaming controller called joyboard. Interestingly, the joyboard she invented can only be used to play one game.

The joyboard has a screen containing $n+1$ slots numbered from $1$ to $n+1$ from left to right. The $n+1$ slots are going to be filled with an array of non-negative integers $[a_1,a_2,a_3,\ldots,a_{n+1}]$. Chaneka, as the player, must assign $a_{n+1}$ with an integer between $0$ and $m$ inclusive. Then, for each $i$ from $n$ to $1$, the value of $a_i$ will be equal to the remainder of dividing $a_{i+1}$ (the adjacent value to the right) by $i$. In other words, $a_i = a_{i + 1} \bmod i$.

Chaneka wants it such that after every slot is assigned with an integer, there are exactly $k$ distinct values in the entire screen (among all $n+1$ slots). How many valid ways are there for assigning a non-negative integer into slot $n+1$?

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 2\cdot10^4$) — the number of test cases. The following lines contain the description of each test case.

The only line of each test case contains three integers $n$, $m$, and $k$ ($1 \leq n \leq 10^9$; $0 \leq m \leq 10^9$; $1 \leq k \leq n+1$) — there are $n+1$ slots, the integer assigned in slot $n+1$ must not be bigger than $m$, and there should be exactly $k$ distinct values.

## Output

For each test case, output a line containing an integer representing the number of valid ways for assigning a non-negative integer into slot $n+1$.

## Example

## Input


```

44 6 32 0 1265 265 2653 10 2
```
## Output


```

2
1
0
5

```
## Note

In the first test case, one of the $2$ possible ways for Chaneka is to choose $a_{n+1}=6$. If she does that, then: 

* $a_4=a_5\bmod 4=6\bmod 4=2$
* $a_3=a_4\bmod 3=2\bmod 3=2$
* $a_2=a_3\bmod 2=2\bmod 2=0$
* $a_1=a_2\bmod 1=0\bmod 1=0$
* $a = [0, 0, 2, 2, 6]$
* There are $3$ distinct values.

In the second test case, the $1$ possible way for Chaneka is to choose $a_{n+1}=0$. If she does that, then $a = [0, 0, 0]$. There is only $1$ distinct value.

In the third test case, there is no possible way for assigning a non-negative integer into slot $n+1$.



#### tags 

#1200 #math #number_theory 