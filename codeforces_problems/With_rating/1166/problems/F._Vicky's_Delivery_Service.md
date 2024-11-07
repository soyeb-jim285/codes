<h1 style='text-align: center;'> F. Vicky's Delivery Service</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a magical land there are $n$ cities conveniently numbered $1, 2, \dots, n$. Some pairs of these cities are connected by magical colored roads. Magic is unstable, so at any time, new roads may appear between two cities.

Vicky the witch has been tasked with performing deliveries between some pairs of cities. However, Vicky is a beginner, so she can only complete a delivery if she can move from her starting city to her destination city through a double rainbow. A double rainbow is a sequence of cities $c_1, c_2, \dots, c_k$ satisfying the following properties:

* For each $i$ with $1 \le i \le k - 1$, the cities $c_i$ and $c_{i + 1}$ are connected by a road.
* For each $i$ with $1 \le i \le \frac{k - 1}{2}$, the roads connecting $c_{2i}$ with $c_{2i - 1}$ and $c_{2i + 1}$ have the same color.

For example if $k = 5$, the road between $c_1$ and $c_2$ must be the same color as the road between $c_2$ and $c_3$, and the road between $c_3$ and $c_4$ must be the same color as the road between $c_4$ and $c_5$.

Vicky has a list of events in chronological order, where each event is either a delivery she must perform, or appearance of a new road. Help her determine which of her deliveries she will be able to complete.

### Input

The first line contains four integers $n$, $m$, $c$, and $q$ ($2 \le n \le 10^5$, $1 \le m, c, q \le 10^5$), denoting respectively the number of cities, the number of roads initially present, the number of different colors the roads can take, and the number of events.

Each of the following $m$ lines contains three integers $x$, $y$, and $z$ ($1 \le x, y \le n$, $1 \le z \le c$), describing that there initially exists a bidirectional road with color $z$ between cities $x$ and $y$.

Then $q$ lines follow, describing the events. Each event is one of the following two types: 

1. + x y z ($1 \le x, y \le n$, $1 \le z \le c$), meaning a road with color $z$ appears between cities $x$ and $y$;
2. ? x y ($1 \le x, y \le n$), meaning you should determine whether Vicky can make a delivery starting at city $x$ and ending at city $y$. It is guaranteed that $x \neq y$.

It is guaranteed that at any moment, there is at most one road connecting any pair of cities, and that no road connects a city to itself. It is guaranteed that the input contains at least one event of the second type.

### Output

For each event of the second type, print a single line containing "Yes" (without quotes) if the delivery can be made, or a single line containing "No" (without quotes) otherwise.

## Example

### Input


```text
4 3 2 4
1 2 1
2 3 1
3 4 2
? 1 4
? 4 1
+ 3 1 2
? 4 1
```
### Output


```text
Yes
No
Yes
```
## Note

The following picture corresponds to the sample.

 ![](images/0b7802f83c1f81f78793f89b14fe71d69f0c83ee.png) For her first delivery, Vicky can use the sequence 1, 2, 3, 4 which is a double rainbow. However, she cannot complete the second delivery, as she can only reach city $3$. After adding the road between cities $1$ and $3$, she can now complete a delivery from city $4$ to city $1$ by using the double rainbow 4, 3, 1.



#### Tags 

#2400 #NOT OK #data_structures #dsu #graphs #hashing 

## Blogs
- [All Contest Problems](../Codeforces_Round_561_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
