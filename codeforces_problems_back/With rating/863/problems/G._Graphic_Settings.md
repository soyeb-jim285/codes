<h1 style='text-align: center;'> G. Graphic Settings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently Ivan bought a new computer. Excited, he unpacked it and installed his favourite game. With his old computer Ivan had to choose the worst possible graphic settings (because otherwise the framerate would be really low), but now he wants to check, maybe his new computer can perform well even with the best possible graphics?

There are *m* graphics parameters in the game. *i*-th parameter can be set to any positive integer from 1 to *a**i*, and initially is set to *b**i* (*b**i* ≤ *a**i*). So there are ![](images/d17cddb5b1a0e3249ccc45df1ee5a6d7b87bbca4.png) different combinations of parameters. Ivan can increase or decrease any of these parameters by 1; after that the game will be restarted with new parameters (and Ivan will have the opportunity to check chosen combination of parameters).

Ivan wants to try all *p* possible combinations. Also he wants to return to the initial settings after trying all combinations, because he thinks that initial settings can be somehow best suited for his hardware. But Ivan doesn't really want to make a lot of restarts.

So he wants you to tell the following:

* If there exists a way to make exactly *p* changes (each change either decreases or increases some parameter by 1) to try all possible combinations and return to initial combination, then Ivan wants to know this way.
* Otherwise, if there exists a way to make exactly *p* - 1 changes to try all possible combinations (including the initial one), then Ivan wants to know this way.

Help Ivan by showing him the way to change parameters!

## Input

The first line of input contains one integer number *m* (1 ≤ *m* ≤ 6).

The second line contains *m* integer numbers *a*1, *a*2, ..., *a**m* (2 ≤ *a**i* ≤ 1000). It is guaranteed that ![](images/0ada6082392fb845829961539792ec286cdb5a27.png).

The third line contains *m* integer numbers *b*1, *b*2, ..., *b**m* (1 ≤ *b**i* ≤ *a**i*).

## Output

If there is a way to make exactly *p* changes (each change either decreases or increases some parameter by 1) to try all possible combinations and return to initial combination, then output Cycle in the first line. Then *p* lines must follow, each desribing a change. The line must be either inc x (increase parameter *x* by 1) or dec x (decrease it).

Otherwise, if there is a way to make exactly *p* - 1 changes to try all possible combinations (including the initial one), then output Path in the first line. Then *p* - 1 lines must follow, each describing the change the same way as mentioned above.

Otherwise, output No.

## Examples

## Input


```
1  
3  
1  

```
## Output


```
Path  
inc 1  
inc 1  

```
## Input


```
1  
3  
2  

```
## Output


```
No  

```
## Input


```
2  
3 2  
1 1  

```
## Output


```
Cycle  
inc 1  
inc 1  
inc 2  
dec 1  
dec 1  
dec 2  

```


#### tags 

#3200 