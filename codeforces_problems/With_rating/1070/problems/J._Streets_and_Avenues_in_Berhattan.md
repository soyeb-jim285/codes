<h1 style='text-align: center;'> J. Streets and Avenues in Berhattan</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Berhattan is the capital of Berland. There are $n$ streets running parallel in the east-west direction (horizontally), and there are $m$ avenues running parallel in the south-north direction (vertically). Each street intersects with each avenue, forming a crossroad. So in total there are $n \cdot m$ crossroads in Berhattan.

Recently, the government has changed in Berland. The new government wants to name all avenues and all streets after heroes of revolution.

The special committee prepared the list of $k$ names. Only these names can be used as new names for streets and avenues. Each name can be used at most once.

The members of committee want to name streets and avenues in the way that minimizes inconvenience for residents. They believe that if street and avenue names start with the same letter, then their crossroad will be inconvenient. Hence only the first letter of each name matters.

Given first letters of $k$ names, find $C$ — minimal possible number of inconvenient crossroads in Berhattan after the naming process.

#### Input

#### Input

 contains one or several test cases to process. The first line contains $t$ ($1 \le t \le 30000$) — the number of test cases. Solve test cases separately, test cases are completely independent and do not affect each other.

The description of $t$ test cases follows. Each test case starts with line with space-separated numbers $n, m, k$ ($1 \le n,m \le 30000$; $n+m \le k \le 2\cdot10^5$) — the number of streets, number of avenues and the number of names in the committee's list, respectively.

The the second line of each test case contains a string of $k$ uppercase English letters. $i$-th letter of the string is the first letter of $i$-th name from the committee's list. 

It's guaranteed that the sum of numbers $n$ from all test cases is not greater than $30000$. Similarly, the sum of numbers $m$ from all test cases is not greater than $30000$. The sum of numbers $k$ from all test cases is not greater than $2\cdot10^5$.

#### Output

For each test case print single number $C$ in the separate line — minimal possible number of inconvenient crossroads in Berhattan after the naming process.

## Examples

#### Input


```text
2  
2 3 9  
EEZZEEZZZ  
2 7 9  
EEZZEEZZZ  

```
#### Output


```text
0  
4  

```
#### Input


```text
2  
4 4 8  
CZBBCZBC  
1 1 4  
TTCT  

```
#### Output


```text
1  
0  

```


#### Tags 

#2300 #NOT OK #dp 

## Blogs
- [All Contest Problems](../2018-2019_ICPC,_NEERC,_Southern_Subregional_Contest_(Online_Mirror,_ACM-ICPC_Rules,_Teams_Preferred).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
