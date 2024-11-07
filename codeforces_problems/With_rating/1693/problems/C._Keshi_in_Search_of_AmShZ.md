<h1 style='text-align: center;'> C. Keshi in Search of AmShZ</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

AmShZ has traveled to Italy from Iran for the Thom Yorke concert. There are $n$ cities in Italy indexed from $1$ to $n$ and $m$ directed roads indexed from $1$ to $m$. Initially, Keshi is located in the city $1$ and wants to go to AmShZ's house in the city $n$. Since Keshi doesn't know the map of Italy, AmShZ helps him to see each other as soon as possible.

In the beginning of each day, AmShZ can send one of the following two messages to Keshi:

* AmShZ sends the index of one road to Keshi as a blocked road. Then Keshi will understand that he should never use that road and he will remain in his current city for the day.
* AmShZ tells Keshi to move. Then, Keshi will randomly choose one of the cities reachable from his current city and move there. (city $B$ is reachable from city $A$ if there's an out-going road from city $A$ to city $B$ which hasn't become blocked yet). If there are no such cities, Keshi will remain in his current city.
## Note

 that AmShZ always knows Keshi's current location.

AmShZ and Keshi want to find the smallest possible integer $d$ for which they can make sure that they will see each other after at most $d$ days. Help them find $d$.

##### Input

The first line of the input contains two integers $n$ and $m$ $(2 \le n \le 2 \cdot 10^5, 1 \le m \le 2 \cdot 10^5)$  — the number of cities and roads correspondingly.

The $i$-th line of the following $m$ lines contains two integers $v_i$ and $u_i$ $(1 \le v_i , u_i \le n,v_i \neq u_i)$, denoting a directed road going from city $v_i$ to city $u_i$.

It is guaranteed that there is at least one route from city $1$ to city $n$. 
## Note

 that there may be more than one road between a pair of cities in each direction.

##### Output

##### Output

 the smallest possible integer $d$ to make sure that AmShZ and Keshi will see each other after at most $d$ days.

## Examples

##### Input


```text
2 1
1 2
```
##### Output


```text
1
```
##### Input


```text
4 4
1 2
1 4
2 4
1 4
```
##### Output


```text
2
```
##### Input


```text
5 7
1 2
2 3
3 5
1 4
4 3
4 5
3 1
```
##### Output


```text
4
```
## Note

In the first sample, it's enough for AmShZ to send the second type of message.

In the second sample, on the first day, AmShZ blocks the first road. So the only reachable city from city $1$ will be city $4$. Hence on the second day, AmShZ can tell Keshi to move and Keshi will arrive at AmShZ's house.

It's also possible for AmShZ to tell Keshi to move for two days.



#### Tags 

#2300 #NOT OK #graphs #greedy #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_800_(Div._1).md)
- [Codeforces Round #800 (en)](../blogs/Codeforces_Round_800_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
