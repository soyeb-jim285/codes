<h1 style='text-align: center;'> D. Tourism</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Masha lives in a country with $n$ cities numbered from $1$ to $n$. She lives in the city number $1$. 

There is a direct train route between each pair of distinct cities $i$ and $j$, where $i \neq j$. In total there are $n(n-1)$ distinct routes. Every route has a cost, cost for route from $i$ to $j$ may be different from the cost of route from $j$ to $i$.

Masha wants to start her journey in city $1$, take exactly $k$ routes from one city to another and as a result return to the city $1$. Masha is really careful with money, so she wants the journey to be as cheap as possible. To do so Masha doesn't mind visiting a city multiple times or even taking the same route multiple times.

Masha doesn't want her journey to have odd cycles. Formally, if you can select visited by Masha city $v$, take odd number of routes used by Masha in her journey and return to the city $v$, such journey is considered unsuccessful.

Help Masha to find the cheapest (with minimal total cost of all taken routes) successful journey.

#### Input

First line of input had two integer numbers $n,k$ ($2 \leq n \leq 80; 2 \leq k \leq 10$): number of cities in the country and number of routes in Masha's journey. It is guaranteed that $k$ is even.

Next $n$ lines hold route descriptions: $j$-th number in $i$-th line represents the cost of route from $i$ to $j$ if $i \neq j$, and is 0 otherwise (there are no routes $i \to i$). All route costs are integers from $0$ to $10^8$.

#### Output

#### Output

 a single integer — total cost of the cheapest Masha's successful journey.

## Examples

#### Input


```text
5 8
0 1 2 2 0
0 0 1 1 2
0 1 0 0 0
2 1 1 0 0
2 0 1 2 0
```
#### Output


```text
2
```
#### Input


```text
3 2
0 1 1
2 0 1
2 2 0
```
#### Output


```text
3
```


#### Tags 

#2300 #NOT OK #dp #graphs #probabilities 

## Blogs
- [All Contest Problems](../VK_Cup_2019-2020_-_Elimination_Round_(Engine).md)
- [Tutorial](../blogs/Tutorial.md)
