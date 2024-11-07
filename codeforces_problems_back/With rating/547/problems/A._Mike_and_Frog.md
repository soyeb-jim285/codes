<h1 style='text-align: center;'> A. Mike and Frog</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mike has a frog and a flower. His frog is named Xaniar and his flower is named Abol. Initially(at time 0), height of Xaniar is *h*1 and height of Abol is *h*2. Each second, Mike waters Abol and Xaniar.

 ![](images/1f498406135eb7cd7e35d764b73fec9763281493.png) So, if height of Xaniar is *h*1 and height of Abol is *h*2, after one second height of Xaniar will become ![](images/2fe18334e8025eeb03e58258a1a73999e06eaded.png) and height of Abol will become ![](images/fc063cc983b60502463ef52c01f1c9f44150fd93.png) where *x*1, *y*1, *x*2 and *y*2 are some integer numbers and ![](images/57fc4a50a6c33bac9327d8c392910a6dbf5c89bb.png) denotes the remainder of *a* modulo *b*.

Mike is a competitive programmer fan. He wants to know the minimum time it takes until height of Xania is *a*1 and height of Abol is *a*2.

Mike has asked you for your help. Calculate the minimum time or say it will never happen.

## Input

The first line of input contains integer *m* (2 ≤ *m* ≤ 106).

The second line of input contains integers *h*1 and *a*1 (0 ≤ *h*1, *a*1 < *m*).

The third line of input contains integers *x*1 and *y*1 (0 ≤ *x*1, *y*1 < *m*).

The fourth line of input contains integers *h*2 and *a*2 (0 ≤ *h*2, *a*2 < *m*).

The fifth line of input contains integers *x*2 and *y*2 (0 ≤ *x*2, *y*2 < *m*).

It is guaranteed that *h*1 ≠ *a*1 and *h*2 ≠ *a*2.

## Output

Print the minimum number of seconds until Xaniar reaches height *a*1 and Abol reaches height *a*2 or print -1 otherwise.

## Examples

## Input


```
5  
4 2  
1 1  
0 1  
2 3  

```
## Output


```
3  

```
## Input


```
1023  
1 2  
1 0  
1 2  
1 1  

```
## Output


```
-1  

```
## Note

In the first sample, heights sequences are following:

Xaniar: ![](images/85da629b05969e7a8a6636d995b8fe7a0494e8f4.png)

Abol: ![](images/ea95da14490864ae8b8bfcd4a8b7c02ad3a666b3.png)



#### tags 

#2200 #brute_force #greedy #implementation #math 