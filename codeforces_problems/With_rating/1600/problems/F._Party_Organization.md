<h1 style='text-align: center;'> F. Party Organization</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On the great island of Baltia, there live $N$ people, numbered from $1$ to $N$. There are exactly $M$ pairs of people that are friends with each other. The people of Baltia want to organize a successful party, but they have very strict rules on what a party is and when the party is successful. On the island of Baltia, a party is a gathering of exactly $5$ people. The party is considered to be successful if either all the people at the party are friends with each other (so that they can all talk to each other without having to worry about talking to someone they are not friends with) or no two people at the party are friends with each other (so that everyone can just be on their phones without anyone else bothering them). Please help the people of Baltia organize a successful party or tell them that it's impossible to do so.

#### Input

The first line contains two integer numbers, $N$ ($5 \leq N \leq 2*10^5$) and $M$ ($0 \leq M \leq 2*10^5$) – the number of people that live in Baltia, and the number of friendships. The next $M$ lines each contains two integers $U_i$ and $V_i$ ($1 \leq U_i,V_i \leq N$) – meaning that person $U_i$ is friends with person $V_i$. Two friends can not be in the list of friends twice (no pairs are repeated) and a person can be friends with themselves ($U_i \ne V_i$).

#### Output

If it's possible to organize a successful party, print $5$ numbers indicating which $5$ people should be invited to the party. If it's not possible to organize a successful party, print $-1$ instead. If there are multiple successful parties possible, print any.

## Examples

#### Input


```text
6 3
1 4
4 2
5 4
```
#### Output


```text
1 2 3 5 6
```
#### Input


```text
5 4
1 2
2 3
3 4
4 5
```
#### Output


```text
-1
```


#### Tags 

#2300 #NOT OK #brute_force #math #probabilities 

## Blogs
- [All Contest Problems](../Bubble_Cup_14_-_Finals_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred,_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
