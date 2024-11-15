<h1 style='text-align: center;'> C. Harry Potter and the Golden Snitch</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Brothers Fred and George Weasley once got into the sporting goods store and opened a box of Quidditch balls. After long and painful experiments they found out that the Golden Snitch is not enchanted at all. It is simply a programmed device. It always moves along the same trajectory, which is a polyline with vertices at the points (*x*0, *y*0, *z*0), (*x*1, *y*1, *z*1), ..., (*x**n*, *y**n*, *z**n*). At the beginning of the game the snitch is positioned at the point (*x*0, *y*0, *z*0), and then moves along the polyline at the constant speed *v**s*. The twins have not yet found out how the snitch behaves then. Nevertheless, they hope that the retrieved information will help Harry Potter and his team in the upcoming match against Slytherin. Harry Potter learned that at the beginning the game he will be at the point (*P**x*, *P**y*, *P**z*) and his super fast Nimbus 2011 broom allows him to move at the constant speed *v**p* in any direction or remain idle. *v**p* is not less than the speed of the snitch *v**s*. Harry Potter, of course, wants to catch the snitch as soon as possible. Or, if catching the snitch while it is moving along the polyline is impossible, he wants to hurry the Weasley brothers with their experiments. Harry Potter catches the snitch at the time when they are at the same point. Help Harry.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 10000). The following *n* + 1 lines contain the coordinates *x**i*, *y**i*, *z**i*, separated by single spaces. The coordinates of any two consecutive points do not coincide. The next line contains the velocities *v**p* and *v**s*, the last line contains *P**x*, *P**y*, *P**z*, separated by single spaces. All the numbers in the input are integers, their absolute value does not exceed 104. The speeds are strictly positive. It is guaranteed that *v**s* ≤ *v**p*.

## Output

If Harry Potter can catch the snitch while it is moving along the polyline (including the end (*x**n*, *y**n*, *z**n*)), print "YES" in the first line (without the quotes). Print in the second line *t*, which is the earliest moment of time, when Harry will be able to catch the snitch. On the third line print three numbers *X*, *Y*, *Z*, the coordinates of the point at which this happens. The absolute or relative error in the answer should not exceed 10- 6. If Harry is not able to catch the snitch during its moving along the described polyline, print "NO".

## Examples

## Input


```
4  
0 0 0  
0 10 0  
10 10 0  
10 0 0  
0 0 0  
1 1  
5 5 25  

```
## Output


```
YES  
25.5000000000  
10.0000000000 4.5000000000 0.0000000000  

```
## Input


```
4  
0 0 0  
0 10 0  
10 10 0  
10 0 0  
0 0 0  
1 1  
5 5 50  

```
## Output


```
NO  

```
## Input


```
1  
1 2 3  
4 5 6  
20 10  
1 2 3  

```
## Output


```
YES  
0.0000000000  
1.0000000000 2.0000000000 3.0000000000  

```


#### tags 

#2100 #binary_search #geometry 