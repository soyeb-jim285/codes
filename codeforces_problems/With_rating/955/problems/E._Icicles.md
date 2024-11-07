<h1 style='text-align: center;'> E. Icicles</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Andrew's favourite Krakozyabra has recenly fled away and now he's eager to bring it back!

At the moment the refugee is inside an icy cave with *n* icicles dangling from the ceiling located in integer coordinates numbered from 1 to *n*. The distance between floor and the *i*-th icicle is equal to *a**i*.

Andrew is free to choose an arbitrary integer point *T* in range from 1 to *n* inclusive and at time instant 0 launch a sound wave spreading into both sides (left and right) at the speed of one point per second. Any icicle touched by the wave starts falling at the same speed (that means that in a second the distance from floor to icicle decreases by one but cannot become less that zero). While distance from icicle to floor is more than zero, it is considered passable; as soon as it becomes zero, the icicle blocks the path and prohibits passing.

Krakozyabra is initially (i.e. at time instant 0) is located at point ![](images/eb946338365d9781f7d2e9ec692c26702d0ae3a7.png) and starts running in the right direction at the speed of one point per second. You can assume that events in a single second happen in the following order: first Krakozyabra changes its position, and only then the sound spreads and icicles fall; in particular, that means that if Krakozyabra is currently at point ![](images/888531a0e13807ef7dd73a80ad9f8310660a8f1f.png) and the falling (i.e. already touched by the sound wave) icicle at point *i* is 1 point from the floor, then Krakozyabra will pass it and find itself at ![](images/032de8ef739262586ef499646cfcdea1584e7a25.png) and only after that the icicle will finally fall and block the path.

Krakozyabra is considered entrapped if there are fallen (i.e. with *a**i* = 0) icicles both to the left and to the right of its current position. Help Andrew find the minimum possible time it takes to entrap Krakozyabra by choosing the optimal value of *T* or report that this mission is impossible.

###### Input

The first line contains the number of icicles *n* (2 ≤ *n* ≤ 105).

The next line contains *n* space-separated numbers *a**i* (1 ≤ *a**i* ≤ 105) — the distances from floor to icicles.

###### Output

Print an only integer — the minimum time it takes to entrap Krakozyabra between two fallen icicles. If it is impossible, print  - 1.

## Examples

###### Input


```text
5  
1 4 3 5 1  

```
###### Output


```text
3  

```
###### Input


```text
4  
1 2 1 1  

```
###### Output


```text
2  

```
###### Input


```text
2  
2 1  

```
###### Output


```text
3  

```
###### Input


```text
2  
1 2  

```
###### Output


```text
-1  

```
## Note

In sample case one it's optimal to launch the sound wave from point 3. Then in two seconds icicles 1 and 5 will start falling, and in one more seconds they will block the paths. Krakozyabra will be located at ![](images/36de0b98a41a7a3c26317908808c214e6d4ac3ff.png) at that time. 
## Note

 that icicle number 3 will also be fallen, so there will actually be two icicles blocking the path to the left.

In sample case two it is optimal to launch the wave from point 2 and entrap Krakozyabra in 2 seconds.

In sample case four the answer is impossible.



#### Tags 

#2900 #NOT OK 

## Blogs
- [All Contest Problems](../Codeforces_Round_471_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial](../blogs/Editorial.md)
