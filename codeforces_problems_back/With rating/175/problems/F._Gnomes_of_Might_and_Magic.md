<h1 style='text-align: center;'> F. Gnomes of Might and Magic</h1>

<h5 style='text-align: center;'>time limit per test: 8 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya plays a popular game the Gnomes of Might and Magic.

In this game Vasya manages the kingdom of gnomes, consisting of several castles, connected by bidirectional roads. The kingdom road network has a special form. The kingdom has *m* main castles *a*1, *a*2, ..., *a**m*, which form the Good Path. This path consists of roads between the castles *a**i*, *a**i* + 1 (1 ≤ *i* < *m*) as well as the road between *a**m* and *a*1. There are no other roads between the castles of the Good Path.

In addition, for each pair of neighboring Good Path castles *u* and *v* there is exactly one Evil Shortcut — a path that goes along the roads leading from the first castle (*u*) to the second one (*v*) and not having any common vertexes with the Good Path except for the vertexes *u* and *v*. It is known that there are no other roads and castles in the kingdom there, that is, every road and every castle lies either on the Good Path or the Evil Shortcut (castles can lie in both of them). In addition, no two Evil Shortcuts have any common castles, different than the castles of the Good Path.

At the beginning of each week in the kingdom appears one very bad gnome who stands on one of the roads of the kingdom, and begins to rob the corovans going through this road. One road may accumulate multiple very bad gnomes. Vasya cares about his corovans, so sometimes he sends the Mission of Death from one castle to another.

Let's suggest that the Mission of Death should get from castle *s* to castle *t*. Then it will move from castle *s* to castle *t*, destroying all very bad gnomes, which are on the roads of the Mission's path. Vasya is so tough that his Mission of Death can destroy any number of gnomes on its way. However, Vasya is very kind, so he always chooses such path between castles *s* and *t*, following which he will destroy the smallest number of gnomes. If there are multiple such paths, then Vasya chooses the path that contains the smallest number of roads among them. If there are multiple such paths still, Vasya chooses the lexicographically minimal one among them.

Help Vasya to simulate the life of the kingdom in the Gnomes of Might and Magic game.

A path is a sequence of castles, such that each pair of the neighboring castles on the path is connected by a road. Also, path *x*1, *x*2, ... , *x**p* is lexicographically less than path *y*1, *y*2, ... , *y**q*, if either *p* < *q* and *x*1 = *y*1, *x*2 = *y*2, ... , *x**p* = *y**p*, or exists such number *r* (*r* < *p*, *r* < *q*), that *x*1 = *y*1, *x*2 = *y*2, ... , *x**r* = *y**r* and *x**r* + 1 < *y**r* + 1.

## Input

The first line contains two integers *n* and *m* (3 ≤ *m* ≤ *n* ≤ 100000) — the number of castles in the kingdom, and the number of castles on the Good Path, respectively.

The second line contains *m* integers, which are numbers of Good Path castles (the castles are numbered from 1 to *n*) in the order of occurrence on the Path, starting with some castle. All Good Path castles are different.

Each of the following *m* lines describes an Evil Shortcut. First a line contains an integer *k**i* (3 ≤ *k**i* ≤ 100000) — the number of castles on the corresponding Evil Shortcut (with the two castles which are on the Good Path), followed by a *k**i* integers — number of castles in the order of occurrence in the given Shortcut. All castles in one Evil Shortcut are different. It is guaranteed that the first and the last castles from the Shortcut are on the Good Path and the first castles in the Evil Shortcuts form the Good Path and are presented in the same order in which the Path was represented on the second line.

The next line contains an integer *q* (1 ≤ *q* ≤ 100000) — the number of events in the life of the kingdom. Each of the following *q* lines describes a single event. An event is described by the symbol *c**j* and two numbers or castles *s**j* and *t**j* (the character and numbers of castles are separated by a single space). If the character of *c**j* is equal to "+" (a plus), it means that a very bad gnome (probably not the first one) has appeared on the road between castles *s**j* and *t**j*. If *c**j* equals "?" (a question), then Vasya sent a Mission of Death from castle *s**j* to castle *t**j*. It is guaranteed that for each request "+", the road between castles *s**j* and *t**j* exists. The events are given in chronological order, starting with the earliest one. Initially there are no very bad gnomes on the roads.

All numbers in all lines are separated by single spaces. It is guaranteed that all the given Evil Shortcuts and Good Path fit in the limitations given in the problem statement.

## Output

For each query "?" print a single number on a single line — the number of very bad gnomes destroyed by the corresponding Mission of Death. Print the answers to queries in the chronological order.

## Examples

## Input


```
6 3  
1 2 3  
3 1 4 2  
3 2 5 3  
3 3 6 1  
10  
+ 1 2  
+ 4 2  
+ 1 3  
+ 2 3  
? 1 2  
+ 2 5  
? 1 2  
? 1 2  
+ 1 2  
? 1 2  

```
## Output


```
0  
1  
0  
1  

```
## Note

In the example after the first four requests there is only one path from castle 1 to castle 2, which does not contain roads with very bad gnomes: 1 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 6 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 3 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 5 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 2.

After a gnome stood on the road (2, 5), the next Mission of Death moves along path 1 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 2, and destroys the gnome, who was on the road (1, 2). The next Mission of Death follows the same path which is already free of gnomes.

After yet another gnome stood on the road (1, 2), the next Mission of Death goes on the path 1 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 2, and kills the gnome.



#### tags 

#3000 #data_structures #graphs #implementation #shortest_paths 