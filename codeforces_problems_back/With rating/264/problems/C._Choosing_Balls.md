<h1 style='text-align: center;'> C. Choosing Balls</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* balls. They are arranged in a row. Each ball has a color (for convenience an integer) and an integer value. The color of the *i*-th ball is *c**i* and the value of the *i*-th ball is *v**i*.

Squirrel Liss chooses some balls and makes a new sequence without changing the relative order of the balls. She wants to maximize the value of this sequence.

The value of the sequence is defined as the sum of following values for each ball (where *a* and *b* are given constants):

* If the ball is not in the beginning of the sequence and the color of the ball is same as previous ball's color, add (the value of the ball)  ×  *a*.
* Otherwise, add (the value of the ball)  ×  *b*.

You are given *q* queries. Each query contains two integers *a**i* and *b**i*. For each query find the maximal value of the sequence she can make when *a* = *a**i* and *b* = *b**i*.

## Note

 that the new sequence can be empty, and the value of an empty sequence is defined as zero.

## Input

The first line contains two integers *n* and *q* (1 ≤ *n* ≤ 105; 1 ≤ *q* ≤ 500). The second line contains *n* integers: *v*1, *v*2, ..., *v**n* (|*v**i*| ≤ 105). The third line contains *n* integers: *c*1, *c*2, ..., *c**n* (1 ≤ *c**i* ≤ *n*).

The following *q* lines contain the values of the constants *a* and *b* for queries. The *i*-th of these lines contains two integers *a**i* and *b**i* (|*a**i*|, |*b**i*| ≤ 105).

In each line integers are separated by single spaces.

## Output

For each query, output a line containing an integer — the answer to the query. The *i*-th line contains the answer to the *i*-th query in the input order.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
6 3  
1 -2 3 4 0 -1  
1 2 1 2 1 1  
5 1  
-2 1  
1 0  

```
## Output


```
20  
9  
4  

```
## Input


```
4 1  
-3 6 -1 2  
1 2 3 1  
1 -1  

```
## Output


```
5  

```
## Note

In the first example, to achieve the maximal value:

* In the first query, you should select 1st, 3rd, and 4th ball.
* In the second query, you should select 3rd, 4th, 5th and 6th ball.
* In the third query, you should select 2nd and 4th ball.

## Note

 that there may be other ways to achieve the maximal value.



#### tags 

#2000 #dp 