<h1 style='text-align: center;'> A. Submission Bait</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game in an array $a$ of size $n$.

They take turns to do operations, with Alice starting first. The player who can not operate will lose. At first, a variable $mx$ is set to $0$.

In one operation, a player can do:

* Choose an index $i$ ($1 \le i \le n$) such that $a_{i} \geq mx$ and set $mx$ to $a_{i}$. Then, set $a_{i}$ to $0$.

Determine whether Alice has a winning strategy.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases.

For each test case: 

* The first line contains an integer $n$ ($2 \leq n \leq 50$) — the size of the array.
* The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$) — the elements of the array.
### Output

For each test case, if Alice has a winning strategy, output "YES". Otherwise, output "NO".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input


```text
522 121 133 3 343 3 4 441 2 2 2
```
### Output

```text

YES
NO
YES
NO
YES

```
## Note

In the first test case, Alice can choose $i=1$ since $a_1=2 \ge mx=0$.

After Alice's operation, $a=[0,1]$ and $mx=2$. Bob can not do any operation. Alice wins.

In the second test case, Alice doesn't have a winning strategy.

For example, if Alice chooses $i=1$, after Alice's operation: $a=[0,1]$ and $mx=1$. Then, Bob can choose $i=2$ since $a_2=1 \ge mx=1$. After Bob's operation: $a=[0,0]$ and $mx=1$. Alice can not do any operation. Bob wins.



#### Tags 

#900 #NOT OK #brute_force #games #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_960_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
