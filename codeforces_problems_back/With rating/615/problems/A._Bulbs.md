<h1 style='text-align: center;'> A. Bulbs</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya wants to turn on Christmas lights consisting of *m* bulbs. Initially, all bulbs are turned off. There are *n* buttons, each of them is connected to some set of bulbs. Vasya can press any of these buttons. When the button is pressed, it turns on all the bulbs it's connected to. Can Vasya light up all the bulbs?

If Vasya presses the button such that some bulbs connected to it are already turned on, they do not change their state, i.e. remain turned on.

## Input

The first line of the input contains integers *n* and *m* (1 ≤ *n*, *m* ≤ 100) — the number of buttons and the number of bulbs respectively. 

Each of the next *n* lines contains *x**i* (0 ≤ *x**i* ≤ *m*) — the number of bulbs that are turned on by the *i*-th button, and then *x**i* numbers *y**ij* (1 ≤ *y**ij* ≤ *m*) — the numbers of these bulbs.

## Output

If it's possible to turn on all *m* bulbs print "YES", otherwise print "NO".

## Examples

## Input


```
3 4  
2 1 4  
3 1 3 1  
1 2  

```
## Output


```
YES  

```
## Input


```
3 3  
1 1  
1 2  
1 1  

```
## Output


```
NO  

```
## Note

In the first sample you can press each button once and turn on all the bulbs. In the 2 sample it is impossible to turn on the 3-rd lamp.



#### tags 

#800 #implementation 