<h1 style='text-align: center;'> C. Skier</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Skier rides on a snowy field. Its movements can be described by a string of characters 'S', 'N', 'W', 'E' (which correspond to $1$ meter movement in the south, north, west or east direction respectively).

It is known that if he moves along a previously unvisited segment of a path (i.e. this segment of the path is visited the first time), then the time of such movement is $5$ seconds. If he rolls along previously visited segment of a path (i.e., this segment of the path has been covered by his path before), then it takes $1$ second.

Find the skier's time to roll all the path.

### Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases in the input. Then $t$ test cases follow.

Each set is given by one nonempty string of the characters 'S', 'N', 'W', 'E'. The length of the string does not exceed $10^5$ characters.

The sum of the lengths of $t$ given lines over all test cases in the input does not exceed $10^5$.

### Output

For each test case, print the desired path time in seconds.

## Example

### Input


```text
5
NNN
NS
WWEN
WWEE
NWNWS
```
### Output


```text
15
6
16
12
25
```


#### Tags 

#1400 #NOT OK #data_structures #implementation 

## Blogs
- [All Contest Problems](../Testing_Round_16_(Unrated).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
