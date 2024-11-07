<h1 style='text-align: center;'> A. Thorns and Coins</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

During your journey through computer universes, you stumbled upon a very interesting world. It is a path with $n$ consecutive cells, each of which can either be empty, contain thorns, or a coin. In one move, you can move one or two cells along the path, provided that the destination cell does not contain thorns (and belongs to the path). If you move to the cell with a coin, you pick it up.

 ![](images/72d3c406478fef9e56248f7c9ffe6c6be6f9cab2.png) Here, green arrows correspond to legal moves, and the red arrow corresponds to an illegal move. You want to collect as many coins as possible. Find the maximum number of coins you can collect in the discovered world if you start in the leftmost cell of the path.

### Input

The first line of input contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 50$) — the length of the path.

The second line of each test case contains a string of $n$ characters, the description of the path. The character '.' denotes an empty cell, '@' denotes a cell with a coin, and '*' denotes a cell with thorns. It is guaranteed that the first cell is empty.

### Output

For each test case, output a single integer, the maximum number of coins you can collect.

## Example

### Input


```text
310.@@*@.**@@5.@@@@15.@@..@***..@@@*
```
### Output

```text

3
4
3

```
## Note

The picture for the first example is in the problem statement.

Here is the picture for the second example:

 ![](images/f219f5a838ea637b58a96f6c654757ed91cb7ec6.png) And here is the picture for the third example:

 ![](images/cd296e35c57468456bdab9bfec7d2b41542e6976.png) 

#### Tags 

#800 #NOT OK #dp #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_927_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
