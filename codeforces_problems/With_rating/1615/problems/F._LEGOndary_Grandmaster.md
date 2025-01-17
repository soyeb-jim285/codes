<h1 style='text-align: center;'> F. LEGOndary Grandmaster</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

After getting bored by playing with crayons, you decided to switch to Legos! Today, you're working with a long strip, with height $1$ and length $n$, some positions of which are occupied by $1$ by $1$ Lego pieces.

In one second, you can either remove two adjacent Lego pieces from the strip (if both are present), or add two Lego pieces to adjacent positions (if both are absent). You can only add or remove Lego's at two adjacent positions at the same time, as otherwise your chubby fingers run into precision issues.

You want to know exactly how much time you'll spend playing with Legos. You value efficiency, so given some starting state and some ending state, you'll always spend the least number of seconds to transform the starting state into the ending state. If it's impossible to transform the starting state into the ending state, you just skip it (so you spend $0$ seconds).

The issue is that, for some positions, you don't remember whether there were Legos there or not (in either the starting state, the ending state, or both). Over all pairs of (starting state, ending state) that are consistent with your memory, find the total amount of time it will take to transform the starting state to the ending state. Print this value modulo $1\,000\,000\,007$ ($10^9 + 7$). 

### Input

The first line contains one integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. Then $t$ cases follow.

The first line of each test case contains one integer $n$ ($2 \leq n \leq 2000$) — the size of the Lego strip.

The second line of each test case contains a string $s$ of length $n$, consisting of the characters 0, 1, and ? — your memory of the starting state: 

* 1 represents a position that definitely has a Lego piece,
* 0 represents a position that definitely does not have a Lego piece,
* and ? represents a position that you don't remember.

The third line of each test case contains a string $t$ of length $n$, consisting of the characters 0, 1, and ? — your memory of the ending state. It follows a similar format to the starting state.

It's guaranteed that the sum of $n$ over all test cases doesn't exceed $2000$.

### Output

For each test case, output a single integer — the answer to the problem modulo $1\,000\,000\,007$ ($10^9 + 7$). 

## Example

### Input


```text
6
2
00
11
3
???
???
3
??1
0?0
4
??0?
??11
5
?????
0??1?
10
?01??01?1?
??100?1???
```
### Output


```text
1
16
1
14
101
1674
```
## Note

For the first test case, $00$ is the only possible starting state, and $11$ is the only possible ending state. It takes exactly one operation to change $00$ to $11$.

For the second test case, some of the possible starting and ending state pairs are: 

* $(000, 011)$ — takes $1$ operation.
* $(001, 100)$ — takes $2$ operations.
* $(010, 000)$ — takes $0$ operations, as it's impossible to achieve the ending state.


#### Tags 

#2800 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_18.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
