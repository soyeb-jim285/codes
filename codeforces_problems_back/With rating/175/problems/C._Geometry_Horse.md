<h1 style='text-align: center;'> C. Geometry Horse</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya plays the Geometry Horse.

The game goal is to destroy geometric figures of the game world. A certain number of points is given for destroying each figure depending on the figure type and the current factor value. 

There are *n* types of geometric figures. The number of figures of type *k**i* and figure cost *c**i* is known for each figure type. A player gets *c**i*·*f*  points for destroying one figure of type *i*, where *f* is the current factor. The factor value can be an integer number from 1 to *t* + 1, inclusive. At the beginning of the game the factor value is equal to 1. The factor is set to *i* + 1 after destruction of *p**i* (1 ≤ *i* ≤ *t*) figures, so the (*p**i* + 1)-th figure to be destroyed is considered with factor equal to *i* + 1.

Your task is to determine the maximum number of points Vasya can get after he destroys all figures. Take into account that Vasya is so tough that he can destroy figures in any order chosen by him.

## Input

The first line contains the only integer number *n* (1 ≤ *n* ≤ 100) — the number of figure types.

Each of the following *n* lines contains two integer numbers *k**i* and *c**i* (1 ≤ *k**i* ≤ 109, 0 ≤ *c**i* ≤ 1000), separated with space — the number of figures of the *i*-th type and the cost of one *i*-type figure, correspondingly.

The next line contains the only integer number *t* (1 ≤ *t* ≤ 100) — the number that describe the factor's changes. 

The next line contains *t* integer numbers *p**i* (1 ≤ *p*1 < *p*2 < ... < *p**t* ≤ 1012), separated with spaces.

Please, do not use the %lld specificator to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d specificator.

## Output

Print the only number — the maximum number of points Vasya can get.

## Examples

## Input


```
1  
5 10  
2  
3 6  

```
## Output


```
70
```
## Input


```
2  
3 8  
5 10  
1  
20  

```
## Output


```
74
```
## Note

In the first example Vasya destroys three figures first and gets 3·1·10 = 30 points. Then the factor will become equal to 2 and after destroying the last two figures Vasya will get 2·2·10 = 40 points. As a result Vasya will get 70 points.

In the second example all 8 figures will be destroyed with factor 1, so Vasya will get (3·8 + 5·10)·1 = 74 points.



#### tags 

#1600 #greedy #implementation #sortings #two_pointers 