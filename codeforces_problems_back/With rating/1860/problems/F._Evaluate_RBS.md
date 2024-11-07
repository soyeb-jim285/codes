<h1 style='text-align: center;'> F. Evaluate RBS</h1>

<h5 style='text-align: center;'>time limit per test: 10 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given $2n$ tuples of values $(a, b, c)$, where $a$ and $b$ are positive integers and $c$ is a bracket '(' or ')'. Exactly $n$ tuples have $c = $'(' and the other $n$ tuples have $c =$ ')'.

You are asked to choose two positive values $x$ and $y$ ($x > 0$ and $y > 0$; not necessarily integers) and sort the tuples in the increasing value of $a \cdot x + b \cdot y$. If several tuples have the same value, you can place them in any order among themselves.

Is it possible to choose such $x$ and $y$ that taking brackets $c$ from the tuples in the resulting order produces a regular bracket sequence?

A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence.

## Input

The first line contains a single integer $t$ ($1 \le t \le 1500$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 1500$).

The $i$-th of the next $2n$ lines contains two integers $a_i$ and $b_i$ ($1 \le a_i, b_i \le 10^6$) and a character $c_i$ ($c_i = $'(' or $c_i = $')'). Exactly $n$ tuples have $c_i = $'(' and the other $n$ tuples have $c_i =$ ')'.

The sum of $n$ over all testcases doesn't exceed $1500$.

## Output

For each testcase, print "YES" if it's possible to choose such $x$ and $y$ that taking brackets $c$ from the tuples in the resulting order produces a regular bracket sequence. Otherwise, print "NO".

## Example

## Input


```

411 4 (2 3 )11 2 )3 4 (416 5 (12 3 (19 6 )4 10 )3 10 )19 11 (19 7 )7 14 (416 8 (11 9 )20 10 )20 19 )2 13 (18 7 (15 19 )5 6 (
```
## Output


```

YES
NO
NO
YES

```
## Note

In the first testcase, you can choose $x = 10, y = 0.1$. The values for tuples will be $10 \cdot 1 + 0.1 \cdot 4 = 10.4$ and $10 \cdot 2 + 0.1 \cdot 3 = 20.3$. Thus, the first tuple will go first, then the second one, making the bracket sequence "()", which is regular.

In the second testcase, you can't choose positive $x$ and $y$ such that the opening brackets gets assigned a value less or equal to the value of the closing bracket.

In the fourth testcase, you can choose $x = 0.6, y = 0.55$. The bracket sequence is "(()(()))".



#### tags 

#2900 #data_structures #geometry #implementation #math #sortings 