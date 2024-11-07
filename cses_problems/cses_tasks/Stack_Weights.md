![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Stack Weights

  * Task
  * Statistics

CSES - Stack Weights

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You have $n$ coins, each of which has a distinct weight.

There are two stacks which are initially empty. On each step you move one coin
to a stack. You never remove a coin from a stack.

After each move, your task is to determine which stack is heavier (if we can
be sure that either stack is heavier).

# Input

The first input line has an integer $n$: the number of coins. The coins are
numbered $1,2,\dots,n$. You know that coin $i$ is always heavier than coin
$i-1$, but you don't know their exact weights.

After this, there are $n$ lines that describe the moves. Each line has two
integers $c$ and $s$: move coin $c$ to stack $s$ (1 = left, 2 = right).

# Output

After each move, print `<` if the right stack is heavier, `>` if the left
stack is heavier, and `?` if we can't know which stack is heavier.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$

# Example

Input:

``` 3 2 1 3 2 1 1 ```

Output:

``` > < ? ```

Explanation: After the last move, if the coins are $[2,3,4]$, the left stack
is heavier, but if the coins are $[1,2,5]$, the right stack is heavier.

#### Additional Problems

... Inverse InversionsMonotone SubsequencesString ReorderStack WeightsPyramid
ArrayIncreasing Subsequence IIString RemovalsBit Inversions...

* * *

