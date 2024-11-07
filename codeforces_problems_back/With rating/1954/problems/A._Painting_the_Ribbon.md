<h1 style='text-align: center;'> A. Painting the Ribbon</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Alice and Bob have bought a ribbon consisting of $n$ parts. Now they want to paint it.

First, Alice will paint every part of the ribbon into one of $m$ colors. For each part, she can choose its color arbitrarily.

Then, Bob will choose at most $k$ parts of the ribbon and repaint them into the same color (he chooses the affected parts and the color arbitrarily).

Bob would like all parts to have the same color. However, Alice thinks that this is too dull, so she wants to paint the ribbon in such a way that Bob cannot make all parts have the same color.

Is it possible to paint the ribbon in such a way?

## Input

The first line contains one integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Each test case consists of one line containing three integers $n$, $m$ and $k$ ($1 \le m, k \le n \le 50$) — the number of parts, the number of colors and the number of parts Bob can repaint, respectively.

## Output

For each test case, print YES if Alice can paint the ribbon so that Bob cannot make all parts have the same color. Otherwise, print NO.

You can print every letter in any register. For example, Yes, yes, yEs will all be recognized as positive answer.

## Example

## Input


```

51 1 15 1 15 2 15 2 25 5 3
```
## Output


```

NO
NO
YES
NO
YES

```
## Note

In the first test case, a ribbon consists of $1$ part. So all its parts will always have the same color.

In the second test case, there is only $1$ color.

In the third test case, Alice can paint the ribbon as follows: $[1, 2, 1, 2, 1]$. It's impossible to change the color of at most $1$ part so that all parts have the same color.

In the fourth test case, no matter how Alice paints the ribbon, Bob will always be able to repaint $2$ parts so that all parts have the same color.

In the fifth test case, Alice can paint the ribbon as follows: $[1, 2, 3, 4, 5]$. It's impossible to change the color of at most $3$ parts so that all parts have the same color.



#### tags 

#900 #constructive_algorithms #greedy #math 