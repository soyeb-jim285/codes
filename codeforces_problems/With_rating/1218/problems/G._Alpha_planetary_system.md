<h1 style='text-align: center;'> G. Alpha planetary system</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 128 megabytes</h5>

Three planets $X$, $Y$ and $Z$ within the Alpha planetary system are inhabited with an advanced civilization. The spaceports of these planets are connected by interplanetary space shuttles. The flight scheduler should decide between $1$, $2$ and $3$ return flights for every existing space shuttle connection. Since the residents of Alpha are strong opponents of the symmetry, there is a strict rule that any two of the spaceports connected by a shuttle must have a different number of flights. 

For every pair of connected spaceports, your goal is to propose a number $1$, $2$ or $3$ for each shuttle flight, so that for every two connected spaceports the overall number of flights differs. 

You may assume that:

1) Every planet has at least one spaceport 

2) There exist only shuttle flights between spaceports of different planets 

3) For every two spaceports there is a series of shuttle flights enabling traveling between them

4) Spaceports are not connected by more than one shuttle

### Input

The first row of the input is the integer number $N$ $(3 \leq N \leq 100 000)$, representing overall number of spaceports. The second row is the integer number $M$ $(2 \leq M \leq 100 000)$ representing number of shuttle flight connections. 

Third row contains $N$ characters from the set $\{X, Y, Z\}$. Letter on $I^{th}$ position indicates on which planet is situated spaceport $I$. For example, "XYYXZZ" indicates that the spaceports $0$ and $3$ are located at planet $X$, spaceports $1$ and $2$ are located at $Y$, and spaceports $4$ and $5$ are at $Z$. 

Starting from the fourth row, every row contains two integer numbers separated by a whitespace. These numbers are natural numbers smaller than $N$ and indicate the numbers of the spaceports that are connected. For example, "$12\ 15$" indicates that there is a shuttle flight between spaceports $12$ and $15$. 

### Output

The same representation of shuttle flights in separate rows as in the input, but also containing a third number from the set $\{1, 2, 3\}$ standing for the number of shuttle flights between these spaceports.

## Example

### Input


```text
10
15
XXXXYYYZZZ
0 4
0 5
0 6
4 1
4 8
1 7
1 9
7 2
7 5
5 3
6 2
6 9
8 2
8 3
9 3
```
### Output


```text
0 4 2
0 5 2
0 6 2
4 1 1
4 8 1
1 7 2
1 9 3
7 2 2
7 5 1
5 3 1
6 2 1
6 9 1
8 2 3
8 3 1
9 3 1
```


#### Tags 

#3000 #NOT OK #constructive_algorithms #graphs #shortest_paths 

## Blogs
- [All Contest Problems](../Bubble_Cup_12_-_Finals_[Online_Mirror,_unrated,_Div._1].md)
- [Announcement (en)](../blogs/Announcement_(en).md)
