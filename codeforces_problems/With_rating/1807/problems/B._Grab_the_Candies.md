<h1 style='text-align: center;'> B. Grab the Candies</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mihai and Bianca are playing with bags of candies. They have a row $a$ of $n$ bags of candies. The $i$-th bag has $a_i$ candies. The bags are given to the players in the order from the first bag to the $n$-th bag. 

If a bag has an even number of candies, Mihai grabs the bag. Otherwise, Bianca grabs the bag. Once a bag is grabbed, the number of candies in it gets added to the total number of candies of the player that took it. 

Mihai wants to show off, so he wants to reorder the array so that at any moment (except at the start when they both have no candies), Mihai will have strictly more candies than Bianca. Help Mihai find out if such a reordering exists.

### Input

The first line of the input contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 100$) — the number of bags in the array.

The second line of each test case contains $n$ space-separated integers $a_i$ ($1 \leq a_i \leq 100$) — the number of candies in each bag.

### Output

For each test case, output "YES" (without quotes) if such a reordering exists, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

### Input


```text
341 2 3 441 1 1 231 4 3
```
### Output

```text

YES
NO
NO

```
## Note

In the first test case, Mihai can reorder the array as follows: $[4, 1, 2, 3]$. Then the process proceeds as follows: 

* the first bag has $4$ candies, which is even, so Mihai takes it — Mihai has $4$ candies, and Bianca has $0$.
* the second bag has $1$ candies, which is odd, so Bianca takes it — Mihai has $4$ candies, and Bianca has $1$.
* the third bag has $2$ candies, which is even, so Mihai takes it — Mihai has $6$ candies, and Bianca has $1$.
* the fourth bag has $3$ candies, which is odd, so Bianca takes it — Mihai has $6$ candies, and Bianca has $4$.

 Since Mihai always has more candies than Bianca, this reordering works.

#### Tags 

#800 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_859_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
