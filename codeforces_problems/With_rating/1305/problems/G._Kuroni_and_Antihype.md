<h1 style='text-align: center;'> G. Kuroni and Antihype</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kuroni isn't good at economics. So he decided to found a new financial pyramid called Antihype. It has the following rules:

1. You can join the pyramid for free and get $0$ coins.
2. If you are already a member of Antihype, you can invite your friend who is currently not a member of Antihype, and get a number of coins equal to your age (for each friend you invite).

$n$ people have heard about Antihype recently, the $i$-th person's age is $a_i$. Some of them are friends, but friendship is a weird thing now: the $i$-th person is a friend of the $j$-th person if and only if $a_i \text{ AND } a_j = 0$, where $\text{AND}$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND).

Nobody among the $n$ people is a member of Antihype at the moment. They want to cooperate to join and invite each other to Antihype in a way that maximizes their combined gainings. Could you help them? 

### Input

The first line contains a single integer $n$ ($1\le n \le 2\cdot 10^5$)  — the number of people.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0\le a_i \le 2\cdot 10^5$)  — the ages of the people.

### Output

### Output

 exactly one integer  — the maximum possible combined gainings of all $n$ people.

## Example

### Input


```text
3
1 2 3
```
### Output


```text

2
```
## Note

Only the first and second persons are friends. The second can join Antihype and invite the first one, getting $2$ for it.



#### Tags 

#3500 #NOT OK #bitmasks #brute_force #dp #dsu #graphs 

## Blogs
- [All Contest Problems](../Ozon_Tech_Challenge_2020_(Div.1_+_Div.2,_Rated,_T-shirts_+_prizes!).md)
- [Ozon Tech Challenge 2020](../blogs/Ozon_Tech_Challenge_2020.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
