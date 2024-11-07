<h1 style='text-align: center;'> A. Alexey and Train</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alexey is travelling on a train. Unfortunately, due to the bad weather, the train moves slower that it should!

Alexey took the train at the railroad terminal. Let's say that the train starts from the terminal at the moment $0$. Also, let's say that the train will visit $n$ stations numbered from $1$ to $n$ along its way, and that Alexey destination is the station $n$.

Alexey learned from the train schedule $n$ integer pairs $(a_i, b_i)$ where $a_i$ is the expected time of train's arrival at the $i$-th station and $b_i$ is the expected time of departure.

Also, using all information he has, Alexey was able to calculate $n$ integers $tm_1, tm_2, \dots, tm_n$ where $tm_i$ is the extra time the train need to travel from the station $i - 1$ to the station $i$. Formally, the train needs exactly $a_i - b_{i-1} + tm_i$ time to travel from station $i - 1$ to station $i$ (if $i = 1$ then $b_0$ is the moment the train leave the terminal, and it's equal to $0$).

The train leaves the station $i$, if both conditions are met: 

1. it's on the station for at least $\left\lceil \frac{b_i - a_i}{2} \right\rceil$ units of time (division with ceiling);
2. current time $\ge b_i$.

Since Alexey spent all his energy on prediction of time delays, help him to calculate the time of arrival at the station $n$.

### Input

The first line contains one integer $t$ ($1 \le t \le 100$) — the number of test cases.

The first line of each test case contains the single integer $n$ ($1 \le n \le 100$) — the number of stations.

Next $n$ lines contain two integers each: $a_i$ and $b_i$ ($1 \le a_i < b_i \le 10^6$). It's guaranteed that $b_i < a_{i+1}$. 

Next line contains $n$ integers $tm_1, tm_2, \dots, tm_n$ ($0 \le tm_i \le 10^6$).

### Output

For each test case, print one integer — the time of Alexey's arrival at the last station.

## Example

### Input


```text
2
2
2 4
10 12
0 2
5
1 4
7 8
9 10
13 15
19 20
1 2 3 4 5
```
### Output


```text
12
32
```
## Note

In the first test case, Alexey arrives at station $1$ without any delay at the moment $a_1 = 2$ (since $tm_1 = 0$). After that, he departs at moment $b_1 = 4$. Finally, he arrives at station $2$ with $tm_2 = 2$ extra time, or at the moment $12$.

In the second test case, Alexey arrives at the first station with $tm_1 = 1$ extra time, or at moment $2$. The train, from one side, should stay at the station at least $\left\lceil \frac{b_1 - a_1}{2} \right\rceil = 2$ units of time and from the other side should depart not earlier than at moment $b_1 = 4$. As a result, the trains departs right at the moment $4$.

Using the same logic, we can figure out that the train arrives at the second station at the moment $9$ and departs at the moment $10$; at the third station: arrives at $14$ and departs at $15$; at the fourth: arrives at $22$ and departs at $23$. And, finally, arrives at the fifth station at $32$.



#### Tags 

#800 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_707_(Div._2,_based_on_Moscow_Open_Olympiad_in_Informatics).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
