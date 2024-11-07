<h1 style='text-align: center;'> A. Two Vessels</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have two vessels with water. The first vessel contains $a$ grams of water, and the second vessel contains $b$ grams of water. Both vessels are very large and can hold any amount of water.

You also have an empty cup that can hold up to $c$ grams of water.

In one move, you can scoop up to $c$ grams of water from any vessel and pour it into the other vessel. 
## Note

 that the mass of water poured in one move does not have to be an integer.

What is the minimum number of moves required to make the masses of water in the vessels equal? 
## Note

 that you cannot perform any actions other than the described moves.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

Each test case consists of a single line containing three integers $a$, $b$, and $c$ ($1 \le a, b, c \le 100$) — the mass of water in the vessels and the capacity of the cup, respectively.

### Output

For each test case, output a single number — the minimum number of moves required to make the masses of water in the vessels equal. It can be shown, that it is always possible.

## Example

### Input


```text
63 7 217 4 317 17 117 21 1001 100 197 4 3
```
### Output

```text

1
3
0
1
50
16

```
## Note

In the first test case, only one move is enough: if we pour $2$ grams of water from the second vessel into the first one, both vessels will contain $5$ grams of water.

In the second example test case, three moves are enough:

* Pour $3$ grams of water from the first vessel into the second one. After this move, the first vessel will contain $17 - 3 = 14$ grams of water, and the second vessel will contain $4 + 3 = 7$ grams.
* Pour $2$ grams of water from the first vessel into the second one. After this move, the first vessel will contain $14 - 2 = 12$ grams of water, and the second vessel will contain $7 + 2 = 9$ grams.
* Finally, pour $1.5$ grams of water from the first vessel into the second one. After this move, the first vessel will contain $12 - 1.5 = 10.5$ grams of water, and the second vessel will contain $9 + 1.5 = 10.5$ grams.

## Note

 that this is not the only way to equalize the vessels in $3$ moves, but there is no way to do it in $2$ moves.

In the third example test case, the vessels initially contain the same amount of water, so no moves are needed. The answer is $0$.



#### Tags 

#800 #OK #brute_force #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_895_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
