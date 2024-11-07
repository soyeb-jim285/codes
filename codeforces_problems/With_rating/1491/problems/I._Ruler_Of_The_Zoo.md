<h1 style='text-align: center;'> I. Ruler Of The Zoo</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After realizing that Zookeeper is just a duck, the animals have overthrown Zookeeper. They now have to decide a new ruler among themselves through a fighting tournament of the following format:

Initially, animal $0$ is king, while everyone else queues up with animal $1$ at the front of the queue and animal $n-1$ at the back. The animal at the front of the queue will challenge the king to a fight, and the animal with greater strength will win the fight. The winner will become king, while the loser joins the back of the queue.

An animal who wins $3$ times consecutively will be crowned ruler for the whole zoo. The strength of each animal depends on how many consecutive fights he won. Animal $i$ has strength $A_i$ with $0$ consecutive win, $B_i$ with $1$ consecutive win, and $C_i$ with $2$ consecutive wins. Initially, everyone has $0$ consecutive win.

For all animals, $A_i > B_i$ and $C_i > B_i$. Also, the values of $A_i$, $B_i$, $C_i$ are distinct (all $3n$ values are pairwise different). 

In other words, an animal who is not a king has strength $A_i$. A king usually has a strength of $B_i$ or $C_i$. The exception is on the first turn, the first king (animal $0$) has strength $A_i$.

Who is the new ruler, and after how many fights? Or will it end up that animals fight forever with no one ending up as ruler?

#### Input

The first line contains one integer $n$ ($4 \leq n \leq 6000$) — number of the animals. 

$i$-th of the next $n$ lines contains $3$ integers $A_i$, $B_i$ and $C_i$ ($0 \leq A_i, B_i, C_i \leq 10^9$).

It is guaranteed that $A_i > B_i$ and $C_i > B_i$, and that all values of $A_i$, $B_i$ and $C_i$ are distinct.

#### Output

#### Output

 two integers in a single line. The first is the index of the animal that will become ruler, and the second is the number of fights passed until some animal becomes the ruler.

If the animals will fight for infinitely long, output -1 -1 instead.

## Examples

#### Input


```text
4
5 1 2
10 8 11
9 0 3
7 4 6
```
#### Output


```text
-1 -1
```
#### Input

```text

5
11 7 12
8 6 14
2 1 10
13 0 9
5 3 4

```
#### Output


```text
1 7
```
## Note

The following describes the sequence of events for the second sample. 
## Note

 that in fight $1$, the king (animal $0$) has strength $A_0$. The tournament ends at fight $7$ as animal $1$ wins fight $5$, $6$ and $7$. ![](images/fe6e81eade0cb2e4e38606d105bd80b5164ab85d.png)



#### Tags 

#3500 #NOT OK #brute_force #data_structures 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_13.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
