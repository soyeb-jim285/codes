<h1 style='text-align: center;'> B. Button Pressing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given $N$ buttons (numbered from $1$ to $N$) and $N$ lamps (numbered from $1$ to $N$). Each lamp can either be on or off. Initially, lamp $i$ is on if $A_i = 1$, and off if $A_i = 0$.

Button $i$ is connected to lamp $i - 1$ (if $i > 1$) and lamp $i + 1$ (if $i < N$). In one move, you can press a button $i$ only if lamp $i$ is on. When a button is pressed, the state of the lamps connected to this button is toggled. Formally, the lamps will be on if it was off previously, and the lamps will be off if it was on previously. ## Note

 that lamp $i$ is not connected to button $i$, thus, the state of lamp $i$ does not change if button $i$ is pressed.

After zero or more moves, you want lamp $i$ to be on if $B_i = 1$, and off if $B_i = 0$. Determine if it is possible to achieve this task.

## Input

This problem has multiple test cases. The first line consists of an integer $T$ ($1 \leq T \leq 1000$), which represents the number of test cases. Each test case consists of three lines.

The first line of each test case consists of an integer $N$ ($3 \le N \le 200\,000$). The sum of $N$ over all test cases does not exceed $200\,000$.

The second line of each test case consists of a string $A$ of length $N$. Each character of $A$ can either be 0 or 1. The $i$-th character represents the initial state of lamp $i$.

The third line of each test case consists of a string $A$ of length $N$. Each character of $B$ can either be 0 or 1. The $i$-th character represents the desired final state of lamp $i$.

## Output

For each test case, output YES in a single line if the final state of all lamps can be reached after zero or more moves, or NO otherwise.

## Examples

## Input


```

2
4
0101
0100
3
000
010

```
## Output


```

YES
NO

```
## Input


```

5
7
0101011
1111010
5
11111
00000
4
1101
1101
6
101010
100100
3
000
000

```
## Output


```

NO
NO
YES
YES
YES

```
## Note

Explanation for the sample input/output #1

For the first test case, by pressing the buttons $4, 2, 4, 3, 1, 2$ in sequence, the condition of the buttons changes as: $0101 \rightarrow 0111 \rightarrow 1101 \rightarrow 1111 \rightarrow 1010 \rightarrow 1110 \rightarrow 0100$.

For the second test case, you are unable to press any button, hence it is impossible to reach the final state.



#### tags 

#2600 #bitmasks #constructive_algorithms #hashing 