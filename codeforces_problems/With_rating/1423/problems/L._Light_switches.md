<h1 style='text-align: center;'> L. Light switches</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Nikola owns a large warehouse which is illuminated by $N$ light bulbs, numbered $1$ to $N$. At the exit of the warehouse, there are $S$ light switches, numbered $1$ to $S$. Each switch swaps the on/off state for some light bulbs, so if a light bulb is off, flipping the switch turns it on, and if the light bulb is on, flipping the switch turns it off.

At the end of the day, Nikola wants to turn all the lights off. To achieve this, he will flip some of the light switches at the exit of the warehouse, but since Nikola is lazy, he wants to flip the _minimum_ number of switches required to turn all the lights off. Since Nikola was not able to calculate the minimum number of switches, he asked you to help him. During a period of $D$ days, Nikola noted which light bulbs were off and which were on at the end of each day. He wants you to tell him the minimum number of switches he needed to flip to turn all the lights off for each of the $D$ days or tell him that it's impossible.

### Input

First line contains three integers, $N$, $S$ and $D$ ($1 \leq N \leq 10^3$, $1 \leq S \leq 30$, $1 \leq D \leq 10^3$) – representing number of light bulbs, the number of light switches, and the number of days respectively.

The next $S$ lines contain the description of each light switch as follows: The first number in the line, $C_i$ ($1 \leq C_i \leq N$), represents the number of light bulbs for which the on/off state is swapped by light switch $i$, the next $C_i$ numbers (sorted in increasing order) represent the indices of those light bulbs.

The next $D$ lines contain the description of light bulbs for each day as follows: The first number in the line, $T_i$ ($1 \leq T_i \leq N$), represents the number of light bulbs which are on at the end of day $i$, the next $T_i$ numbers (sorted in increasing order) represent the indices of those light bulbs.

### Output

Print $D$ lines, one for each day. In the $i^{th}$ line, print the minimum number of switches that need to be flipped on day $i$, or $-1$ if it's impossible to turn all the lights off.

## Example

### Input


```text
4 3 4
2 1 2
2 2 3
1 2
1 1
2 1 3
3 1 2 3
3 1 2 4
```
### Output


```text
2
2
3
-1
```


#### Tags 

#2600 #NOT OK #meet-in-the-middle 

## Blogs
- [All Contest Problems](../Bubble_Cup_13_-_Finals_[Online_Mirror,_unrated,_Div._1].md)
- [Announcement (en)](../blogs/Announcement_(en).md)
