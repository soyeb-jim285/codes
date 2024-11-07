<h1 style='text-align: center;'> C. Bricks and Bags</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ bricks numbered from $1$ to $n$. Brick $i$ has a weight of $a_i$.

Pak Chanek has $3$ bags numbered from $1$ to $3$ that are initially empty. For each brick, Pak Chanek must put it into one of the bags. After this, each bag must contain at least one brick.

After Pak Chanek distributes the bricks, Bu Dengklek will take exactly one brick from each bag. Let $w_j$ be the weight of the brick Bu Dengklek takes from bag $j$. The score is calculated as $|w_1 - w_2| + |w_2 - w_3|$, where $|x|$ denotes the absolute value of $x$.

It is known that Bu Dengklek will take the bricks in such a way that minimises the score. What is the maximum possible final score if Pak Chanek distributes the bricks optimally?

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 2 \cdot 10^4$) — the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains an integer $n$ ($3 \leq n \leq 2 \cdot 10^5$) — the number of bricks.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the weights of the bricks.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a line containing an integer representing the maximum possible final score if Pak Chanek distributes the bricks optimally.

## Example

## Input


```

353 1 5 2 3417 8 19 458265 265 265 265 265 265 265 265
```
## Output


```

6
63
0

```
## Note

In the first test case, one way of achieving a final score of $6$ is to do the following: 

* Put bricks $1$, $4$, and $5$ into bag $1$.
* Put brick $3$ into bag $2$.
* Put brick $2$ into bag $3$.

If Pak Chanek distributes the bricks that way, a way Bu Dengklek can take the bricks is: 

* Take brick $5$ from bag $1$.
* Take brick $3$ from bag $2$.
* Take brick $2$ from bag $3$.

The score is $|a_5 - a_3| + |a_3 - a_2| = |3 - 5| + |5 - 1| = 6$. It can be shown that Bu Dengklek cannot get a smaller score from this distribution.

It can be shown that there is no other distribution that results in a final score bigger than $6$.



#### tags 

#1400 #constructive_algorithms #games #greedy #sortings 