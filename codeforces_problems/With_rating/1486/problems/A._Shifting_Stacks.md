<h1 style='text-align: center;'> A. Shifting Stacks</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have $n$ stacks of blocks. The $i$-th stack contains $h_i$ blocks and it's height is the number of blocks in it. In one move you can take a block from the $i$-th stack (if there is at least one block) and put it to the $i + 1$-th stack. Can you make the sequence of heights strictly increasing?

## Note

 that the number of stacks always remains $n$: stacks don't disappear when they have $0$ blocks.

### Input

First line contains a single integer $t$ $(1 \leq t \leq 10^4)$ — the number of test cases.

The first line of each test case contains a single integer $n$ $(1 \leq n \leq 100)$. The second line of each test case contains $n$ integers $h_i$ $(0 \leq h_i \leq 10^9)$ — starting heights of the stacks.

It's guaranteed that the sum of all $n$ does not exceed $10^4$.

### Output

For each test case output YES if you can make the sequence of heights strictly increasing and NO otherwise.

You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

## Example

### Input


```text
6
2
1 2
2
1 0
3
4 4 4
2
0 0
3
0 1 0
4
1000000000 1000000000 1000000000 1000000000
```
### Output


```text
YES
YES
YES
NO
NO
YES
```
## Note

In the first test case there is no need to make any moves, the sequence of heights is already increasing.

In the second test case we need to move one block from the first stack to the second. Then the heights become $0$ $1$.

In the third test case we could move one block from the first stack to the second and then from the second to the third, which would make the heights $3$ $4$ $5$.

In the fourth test case we can't make a move, but the sequence is not increasing, so the answer is NO.

In the fifth test case we can only make one move (from the second to the third stack), which would make the heights $0$ $0$ $1$. Both $0$ $1$ $0$ and $0$ $0$ $1$ are not increasing sequences, so the answer is NO.



#### Tags 

#900 #NOT OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_703_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
