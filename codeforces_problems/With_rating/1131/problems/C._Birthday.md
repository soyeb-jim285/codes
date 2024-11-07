<h1 style='text-align: center;'> C. Birthday</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Cowboy Vlad has a birthday today! There are $n$ children who came to the celebration. In order to greet Vlad, the children decided to form a circle around him. Among the children who came, there are both tall and low, so if they stand in a circle arbitrarily, it may turn out, that there is a tall and low child standing next to each other, and it will be difficult for them to hold hands. Therefore, children want to stand in a circle so that the maximum difference between the growth of two neighboring children would be minimal possible.

Formally, let's number children from $1$ to $n$ in a circle order, that is, for every $i$ child with number $i$ will stand next to the child with number $i+1$, also the child with number $1$ stands next to the child with number $n$. Then we will call the discomfort of the circle the maximum absolute difference of heights of the children, who stand next to each other.

Please help children to find out how they should reorder themselves, so that the resulting discomfort is smallest possible.

#### Input

The first line contains a single integer $n$ ($2 \leq n \leq 100$) — the number of the children who came to the cowboy Vlad's birthday.

The second line contains integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) denoting heights of every child.

#### Output

Print exactly $n$ integers — heights of the children in the order in which they should stand in a circle. You can start printing a circle with any child.

If there are multiple possible answers, print any of them.

## Examples

#### Input


```text
5
2 1 1 3 2
```
#### Output


```text
1 2 3 2 1
```
#### Input


```text
3
30 10 20
```
#### Output


```text
10 20 30
```
## Note

In the first example, the discomfort of the circle is equal to $1$, since the corresponding absolute differences are $1$, $1$, $1$ and $0$. 
## Note

, that sequences $[2, 3, 2, 1, 1]$ and $[3, 2, 1, 1, 2]$ form the same circles and differ only by the selection of the starting point.

In the second example, the discomfort of the circle is equal to $20$, since the absolute difference of $10$ and $30$ is equal to $20$.



#### Tags 

#1200 #NOT OK #binary_search #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_541_(Div._2).md)
- [Announcement #1 (ru)](../blogs/Announcement_1_(ru).md)
- [A (en)](../blogs/A_(en).md)
- [Tutorial](../blogs/Tutorial.md)
