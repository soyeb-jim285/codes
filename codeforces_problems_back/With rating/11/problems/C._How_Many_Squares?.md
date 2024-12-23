<h1 style='text-align: center;'> C. How Many Squares?</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

You are given a 0-1 rectangular matrix. What is the number of squares in it? A square is a solid square frame (border) with linewidth equal to 1. A square should be at least 2 × 2. We are only interested in two types of squares: 

1. squares with each side parallel to a side of the matrix;
2. squares with each side parallel to a diagonal of the matrix.


```
  
For example the following matrix contains only one square of the first type:   
0000000   
0111100   
0100100   
0100100   
0111100  

```

```
  
The following matrix contains only one square of the second type:  
0000000  
0010000  
0101000  
0010000  
0000000  

```
Regardless of type, a square must contain at least one 1 and can't touch (by side or corner) any foreign 1. Of course, the lengths of the sides of each square should be equal.

How many squares are in the given matrix?

## Input

The first line contains integer *t* (1 ≤ *t* ≤ 10000), where *t* is the number of test cases in the input. Then test cases follow. Each case starts with a line containing integers *n* and *m* (2 ≤ *n*, *m* ≤ 250), where *n* is the number of rows and *m* is the number of columns. The following *n* lines contain *m* characters each (0 or 1).

The total number of characters in all test cases doesn't exceed 106 for any input file.

## Output

You should output exactly *t* lines, with the answer to the *i*-th test case on the *i*-th line.

## Examples

## Input


```
2  
8 8  
00010001  
00101000  
01000100  
10000010  
01000100  
00101000  
11010011  
11000011  
10 10  
1111111000  
1000001000  
1011001000  
1011001010  
1000001101  
1001001010  
1010101000  
1001001000  
1000001000  
1111111000  

```
## Output


```
1  
2  

```
## Input


```
1  
12 11  
11111111111  
10000000001  
10111111101  
10100000101  
10101100101  
10101100101  
10100000101  
10100000101  
10111111101  
10000000001  
11111111111  
00000000000  

```
## Output


```
3  

```


#### tags 

#2200 #implementation 