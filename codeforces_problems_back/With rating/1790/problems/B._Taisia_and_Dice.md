<h1 style='text-align: center;'> B. Taisia and Dice</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Taisia has $n$ six-sided dice. Each face of the die is marked with a number from $1$ to $6$, each number from $1$ to $6$ is used once.

Taisia rolls all $n$ dice at the same time and gets a sequence of values $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 6$), where $a_i$ is the value on the upper face of the $i$-th dice. The sum of this sequence is equal to $s$.

Suddenly, Taisia's pet cat steals exactly one dice with maximum value $a_i$ and calculates the sum of the values on the remaining $n-1$ dice, which is equal to $r$.

You only know the number of dice $n$ and the values of $s$, $r$. Restore a possible sequence $a$ that fulfills the constraints.

## Input

The first line contains the integer $t$ ($1 \le t \le 1000$) — the number of testcases.

Each testcase is given on a separate line and contains three integers $n$, $s$, $r$ ($2 \le n \le 50$, $1 \le r < s \le 300$).

It is guaranteed that a solution exists.

## Output

For each testcase, print: $n$ integers $a_1, a_2, \ldots, a_n$ in any order. It is guaranteed that such sequence exists.

If there are multiple solutions, print any.

## Example

## Input


```

72 2 12 4 24 9 55 17 113 15 104 4 35 20 15
```
## Output


```

1 1
2 2 
1 2 2 4
6 4 2 3 2
5 5 5
1 1 1 1
1 4 5 5 5

```


#### tags 

#800 #greedy #greedy #math 