<h1 style='text-align: center;'> E. Upside Down</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

As we all know, Eleven has special abilities. Thus, Hopper convinced her to close the gate to the Upside Down World with her mind. Upside down monsters like to move between the worlds, so they are going to attack Hopper and Eleven in order to make them stop. The monsters live in the vines. The vines form a tree with *n* vertices, numbered from 1 through *n*. There's a lowercase English letter written in each tunnel (edge).

 ![](images/a64dc17c572bb1e99a35935761d00b7aa6999d3a.png) Upside down is a magical world. There are *m* types of monsters in upside down, numbered from 1 through *m*. Each type of monster has a special word that gives them powers. The special word of type *i* is *s**i*. There are *q* monsters in upside down. Each one is at a junction (vertex) and is going to some other junction. If monster of type *k* goes from junction *i* to junction *j*, the power it gains is the number of times it sees its special world (*s**k*) consecutively in the tunnels. More formally: 

If *f*(*i*, *j*) is the string we get when we concatenate the letters written in the tunnels on the shortest path from *i* to *j*, then the power the monster gains is the number of occurrences of *s**k* in *f*(*i*, *j*).

Hopper and Eleven want to get prepared, so for each monster, they want to know the power the monster gains after moving. 

## Input

The first line of input contains three integers, *n*, *m* and *q* (2 ≤ *n* ≤ 105, 1 ≤ *m*, *q* ≤ 105).

The next *n* - 1 lines contain the tunnels (edges). Each line contains two integers *v* and *u* (1 ≤ *v*, *u* ≤ *n*, *v* ≠ *u*) and a lowercase English letter *c*, meaning there's a tunnel connecting junctions *v* and *u* written *c* in it. It is guaranteed that the given graph is a tree.

The next *m* lines contain the special words. *i*-th line of them contains a single string *s**i* (1 ≤ |*s**i*| ≤ 105), consisting of lowercase English letters. It is guaranteed that |*s*1| + |*s*2| + ... + |*s**m*| ≤ 105).

The next *q* lines contain the monsters. Each line contains three integers *i*, *j* and *k* (1 ≤ *i*, *j* ≤ *n*, *i* ≠ *j*, 1 ≤ *k* ≤ *m*), meaning a monster of type *k* is going from junction number *i* to junction number *j*.

## Output

Print *q* lines. *i*-th line should contain a single integer, the power the *i*-th monster gains after moving.

## Examples

## Input


```
6 4 5  
1 6 b  
2 3 a  
1 2 b  
5 3 b  
4 5 b  
a  
b  
bb  
aa  
1 2 1  
6 2 3  
1 6 2  
4 5 4  
1 6 2  

```
## Output


```
0  
1  
1  
0  
1  

```
## Input


```
10 6 7  
1 3 s  
10 1 d  
2 6 s  
5 2 d  
7 4 l  
8 9 d  
8 10 l  
7 2 d  
8 7 l  
dl  
dssld  
d  
d  
l  
sl  
4 5 4  
3 7 5  
10 6 2  
3 1 4  
7 5 6  
10 9 4  
9 8 4  

```
## Output


```
2  
2  
0  
0  
0  
1  
1  

```


#### tags 

#3400 #data_structures #string_suffix_structures #strings #trees 