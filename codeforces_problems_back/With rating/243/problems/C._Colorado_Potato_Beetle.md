<h1 style='text-align: center;'> C. Colorado Potato Beetle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Old MacDonald has a farm and a large potato field, (1010 + 1) × (1010 + 1) square meters in size. The field is divided into square garden beds, each bed takes up one square meter.

Old McDonald knows that the Colorado potato beetle is about to invade his farm and can destroy the entire harvest. To fight the insects, Old McDonald wants to spray some beds with insecticides.

So Old McDonald went to the field, stood at the center of the central field bed and sprayed this bed with insecticides. Now he's going to make a series of movements and spray a few more beds. During each movement Old McDonald moves left, right, up or down the field some integer number of meters. As Old McDonald moves, he sprays all the beds he steps on. In other words, the beds that have any intersection at all with Old McDonald's trajectory, are sprayed with insecticides.

When Old McDonald finished spraying, he wrote out all his movements on a piece of paper. Now he wants to know how many beds won't be infected after the invasion of the Colorado beetles.

It is known that the invasion of the Colorado beetles goes as follows. First some bed on the field border gets infected. Than any bed that hasn't been infected, hasn't been sprayed with insecticides and has a common side with an infected bed, gets infected as well. Help Old McDonald and determine the number of beds that won't be infected by the Colorado potato beetle.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 1000) — the number of Old McDonald's movements.

Next *n* lines contain the description of Old McDonald's movements. The *i*-th of these lines describes the *i*-th movement. Each movement is given in the format "*d**i* *x**i*", where *d**i* is the character that determines the direction of the movement ("L", "R", "U" or "D" for directions "left", "right", "up" and "down", correspondingly), and *x**i* (1 ≤ *x**i* ≤ 106) is an integer that determines the number of meters in the movement.

## Output

Print a single integer — the number of beds that won't be infected by the Colorado potato beetle.

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
5  
R 8  
U 9  
L 9  
D 8  
L 2  

```
## Output


```
101
```
## Input


```
7  
R 10  
D 2  
L 7  
U 9  
D 2  
R 3  
D 10  

```
## Output


```
52
```


#### tags 

#2200 #dfs_and_similar #implementation 