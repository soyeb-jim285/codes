<h1 style='text-align: center;'> A. Amazing Trick</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Alice is a magician and she creates a new trick. She has $n$ cards with different numbers from $1$ to $n$ written on them. First, she asks an audience member to shuffle the deck and put cards in a row. Let's say the $i$-th card from the left has the number $a_i$ on it. 

Then Alice picks two permutations $p$ and $q$. There is a restriction on $p$ and $q$ — permutations can't have fixed points. Which means $\forall i: p_i \ne i\ and\ q_i \ne i$.

After permutations are chosen, Alice shuffles the cards according to them. Now the $i$-th card from the left is the card $a[p[q[i]]$. The trick is considered successful if $i$-th card from the left has the number $i$ on it after the shuffles.

Help Alice pick the permutations $p$ and $q$ or say it is not possible for the specific starting permutation $a$. 

### Input

The first line of the input contains the number of tests $t$ ($1 \leq t \leq 10^5$). 

Each test is described in two lines. The first line contains one integer $n$ — the number of cards ($1 \leq n \leq 10^5$). The second line contains $n$ integers $a_i$ — the initial permutation of the cards ($1 \leq a_i \leq n$; $\forall i \neq j: a_i \neq a_j$). 

It is guaranteed that the sum of $n$ over all tests does not exceed $10^5$.

### Output

Print the answer for each test case in the same order the cases appear in the input.

For each test case, print "Impossible" in a single line, if no solution exists.

Otherwise, print "Possible" in the first line, and in the following two lines print permutations $p$ and $q$.

## Example

### Input


```text
422 131 2 342 1 4 355 1 4 2 3
```
### Output

```text

Impossible
Possible
3 1 2
2 3 1
Possible
3 4 2 1
3 4 2 1
Possible
4 1 2 5 3
3 1 4 5 2

```


#### Tags 

#1900 #NOT OK #constructive_algorithms #graph_matchings #math #probabilities 

## Blogs
- [All Contest Problems](../2022-2023_ICPC,_NERC,_Northern_Eurasia_Onsite_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement](../blogs/Announcement.md)
