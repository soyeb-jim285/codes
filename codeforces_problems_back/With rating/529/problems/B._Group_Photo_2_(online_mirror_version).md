<h1 style='text-align: center;'> B. Group Photo 2 (online mirror version)</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Many years have passed, and *n* friends met at a party again. Technologies have leaped forward since the last meeting, cameras with timer appeared and now it is not obligatory for one of the friends to stand with a camera, and, thus, being absent on the photo.

Simply speaking, the process of photographing can be described as follows. Each friend occupies a rectangle of pixels on the photo: the *i*-th of them in a standing state occupies a *w**i* pixels wide and a *h**i* pixels high rectangle. But also, each person can lie down for the photo, and then he will occupy a *h**i* pixels wide and a *w**i* pixels high rectangle.

The total photo will have size *W* × *H*, where *W* is the total width of all the people rectangles, and *H* is the maximum of the heights. The friends want to determine what minimum area the group photo can they obtain if no more than *n* / 2 of them can lie on the ground (it would be strange if more than *n* / 2 gentlemen lie on the ground together, isn't it?..)

Help them to achieve this goal.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 1000) — the number of friends.

The next *n* lines have two integers *w**i*, *h**i* (1 ≤ *w**i*, *h**i* ≤ 1000) each, representing the size of the rectangle, corresponding to the *i*-th friend.

## Output

Print a single integer equal to the minimum possible area of the photo containing all friends if no more than *n* / 2 of them can lie on the ground.

## Examples

## Input


```
3  
10 1  
20 2  
30 3  

```
## Output


```
180  

```
## Input


```
3  
3 1  
2 2  
4 3  

```
## Output


```
21  

```
## Input


```
1  
5 10  

```
## Output


```
50  

```


#### tags 

#1900 #brute_force #greedy #sortings 