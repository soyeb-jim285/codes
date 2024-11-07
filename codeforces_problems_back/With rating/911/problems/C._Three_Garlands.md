<h1 style='text-align: center;'> C. Three Garlands</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mishka is decorating the Christmas tree. He has got three garlands, and all of them will be put on the tree. After that Mishka will switch these garlands on.

When a garland is switched on, it periodically changes its state — sometimes it is lit, sometimes not. Formally, if *i*-th garland is switched on during *x*-th second, then it is lit only during seconds *x*, *x* + *k**i*, *x* + 2*k**i*, *x* + 3*k**i* and so on.

Mishka wants to switch on the garlands in such a way that during each second after switching the garlands on there would be at least one lit garland. Formally, Mishka wants to choose three integers *x*1, *x*2 and *x*3 (not necessarily distinct) so that he will switch on the first garland during *x*1-th second, the second one — during *x*2-th second, and the third one — during *x*3-th second, respectively, and during each second starting from *max*(*x*1, *x*2, *x*3) at least one garland will be lit.

Help Mishka by telling him if it is possible to do this!

## Input

The first line contains three integers *k*1, *k*2 and *k*3 (1 ≤ *k**i* ≤ 1500) — time intervals of the garlands.

## Output

If Mishka can choose moments of time to switch on the garlands in such a way that each second after switching the garlands on at least one garland will be lit, print YES.

Otherwise, print NO.

## Examples

## Input


```
2 2 3  

```
## Output


```
YES  

```
## Input


```
4 2 3  

```
## Output


```
NO  

```
## Note

In the first example Mishka can choose *x*1 = 1, *x*2 = 2, *x*3 = 1. The first garland will be lit during seconds 1, 3, 5, 7, ..., the second — 2, 4, 6, 8, ..., which already cover all the seconds after the 2-nd one. It doesn't even matter what *x*3 is chosen. Our choice will lead third to be lit during seconds 1, 4, 7, 10, ..., though.

In the second example there is no way to choose such moments of time, there always be some seconds when no garland is lit.



#### tags 

#1400 #brute_force #constructive_algorithms 