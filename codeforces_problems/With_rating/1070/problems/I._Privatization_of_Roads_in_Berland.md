<h1 style='text-align: center;'> I. Privatization of Roads in Berland</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ cities and $m$ two-way roads in Berland, each road connecting two distinct cities.

Recently the Berland government has made a tough decision to transfer ownership of the roads to private companies. In total, there are $100500$ private companies in Berland, numbered by integers from $1$ to $100500$. After the privatization, every road should belong to exactly one company.

The anti-monopoly committee demands that after the privatization each company can own at most two roads. The urbanists of Berland also stated their opinion: each city should be adjacent to the roads owned by at most $k$ companies.

Help the government to distribute the roads between the companies so that both conditions are satisfied. That is, each company gets at most two roads, and each city has roads of at most $k$ distinct companies adjacent to it.

### Input

### Input

 contains one or several test cases. The first line contains an integer $t$ ($1 \le t \le 300$) — the number of test cases in the input. Solve test cases separately, test cases are completely independent and do not affect each other.

The following lines describe the test cases. Each case starts with a line consisting of three space-separated integers $n$, $m$ and $k$ ($2 \le n \le 600$, $1 \le m \le 600$, $1 \le k \le n - 1$) — the number of cities, the number of roads and the maximum diversity of the roads adjacent to a city.

Then $m$ lines follow, each having a pair of space-separated integers $a_i$, $b_i$ ($1 \le a_i, b_i \le n$; $a_i \ne b_i$). It means that the $i$-th road connects cities $a_i$ and $b_i$. All roads are two-way. There is at most one road between a pair of the cities.

The sum of $n$ values for all test cases doesn't exceed $600$. The sum of $m$ values for all test cases doesn't exceed $600$.

### Output

Print $t$ lines: the $i$-th line should contain the answer for the $i$-th test case. For a test case, print a sequence of integers $c_1, c_2, \dots, c_m$ separated by space, where $c_i$ ($1 \le c_i \le 100500$) is the company which owns the $i$-th road in your plan. If there are multiple solutions, output any of them. If there is no solution for a test case, print $c_1=c_2=\ldots=c_m=0$.

## Example

### Input


```text
3  
3 3 2  
1 2  
2 3  
3 1  
4 5 2  
1 2  
1 3  
1 4  
2 3  
2 4  
4 6 2  
1 2  
1 3  
1 4  
2 3  
2 4  
3 4  

```
### Output


```text
1 2 3   
2 1 1 2 3   
0 0 0 0 0 0   

```


#### Tags 

#2400 #NOT OK #flows #graph_matchings #graphs 

## Blogs
- [All Contest Problems](../2018-2019_ICPC,_NEERC,_Southern_Subregional_Contest_(Online_Mirror,_ACM-ICPC_Rules,_Teams_Preferred).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
