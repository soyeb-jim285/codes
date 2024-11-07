<h1 style='text-align: center;'> B. Marlin</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The city of Fishtopia can be imagined as a grid of $4$ rows and an odd number of columns. It has two main villages; the first is located at the top-left cell $(1,1)$, people who stay there love fishing at the Tuna pond at the bottom-right cell $(4, n)$. The second village is located at $(4, 1)$ and its people love the Salmon pond at $(1, n)$.

The mayor of Fishtopia wants to place $k$ hotels in the city, each one occupying one cell. To allow people to enter the city from anywhere, hotels should not be placed on the border cells.

A person can move from one cell to another if those cells are not occupied by hotels and share a side.

Can you help the mayor place the hotels in a way such that there are equal number of shortest paths from each village to its preferred pond?

#### Input

The first line of input contain two integers, $n$ and $k$ ($3 \leq n \leq 99$, $0 \leq k \leq 2\times(n-2)$), $n$ is odd, the width of the city, and the number of hotels to be placed, respectively.

#### Output

Print "YES", if it is possible to place all the hotels in a way that satisfies the problem statement, otherwise print "NO".

If it is possible, print an extra $4$ lines that describe the city, each line should have $n$ characters, each of which is "#" if that cell has a hotel on it, or "." if not.

## Examples

#### Input


```text
7 2  

```
#### Output


```text
YES  
.......  
.#.....  
.#.....  
.......  

```
#### Input


```text
5 3  

```
#### Output


```text
YES  
.....  
.###.  
.....  
.....  

```


#### Tags 

#1600 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_480_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
