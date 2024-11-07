<h1 style='text-align: center;'> C. Bun Lover</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tema loves cinnabon rolls — buns with cinnabon and chocolate in the shape of a "snail".

Cinnabon rolls come in different sizes and are square when viewed from above. The most delicious part of a roll is the chocolate, which is poured in a thin layer over the cinnabon roll in the form of a spiral and around the bun, as in the following picture:

 ![](images/883110c5011d3c0b7480d539e73ab22ba73d6db0.png) Cinnabon rolls of sizes 4, 5, 6 

For a cinnabon roll of size $n$, the length of the outer side of the square is $n$, and the length of the shortest vertical chocolate segment in the central part is one.

Formally, the bun consists of two dough spirals separated by chocolate. A cinnabon roll of size $n + 1$ is obtained from a cinnabon roll of size $n$ by wrapping each of the dough spirals around the cinnabon roll for another layer.

It is important that a cinnabon roll of size $n$ is defined in a unique way.

Tema is interested in how much chocolate is in his cinnabon roll of size $n$. Since Tema has long stopped buying small cinnabon rolls, it is guaranteed that $n \ge 4$.

Answer this non-obvious question by calculating the total length of the chocolate layer.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases.

The following $t$ lines describe the test cases.

Each test case is described by a single integer $n$ ($4 \le n \le 10^9$) — the size of the cinnabon roll.

### Output

### Output

 $t$ integers. The $i$-th of them should be equal to the total length of the chocolate layer in the $i$-th test case.

## Example

### Input


```text
4456179179179
```
### Output

```text

26
37
50
32105178545472401

```


#### Tags 

#800 #NOT OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_867_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
