<h1 style='text-align: center;'> E. Array Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game. They are given an array $A$ of length $N$. The array consists of integers. They are building a sequence together. In the beginning, the sequence is empty. In one turn a player can remove a number from the left or right side of the array and append it to the sequence. The rule is that the sequence they are building must be strictly increasing. The winner is the player that makes the last move. Alice is playing first. Given the starting array, under the assumption that they both play optimally, who wins the game?

##### Input

The first line contains one integer $N$ ($1 \leq N \leq 2*10^5$) - the length of the array $A$.

The second line contains $N$ integers $A_1$, $A_2$,...,$A_N$ ($0 \leq A_i \leq 10^9$)

##### Output

The first and only line of output consists of one string, the name of the winner. If Alice won, print "Alice", otherwise, print "Bob".

## Examples

##### Input


```text
1
5
```
##### Output


```text
Alice
```
##### Input


```text
3
5 4 5
```
##### Output


```text
Alice
```
##### Input


```text
6
5 8 2 1 10 9
```
##### Output


```text
Bob
```


#### Tags 

#1900 #NOT OK #games #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Bubble_Cup_14_-_Finals_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred,_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
