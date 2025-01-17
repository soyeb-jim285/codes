<h1 style='text-align: center;'> B. DZY Loves FFT</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

DZY loves Fast Fourier Transformation, and he enjoys using it.

Fast Fourier Transformation is an algorithm used to calculate convolution. Specifically, if *a*, *b* and *c* are sequences with length *n*, which are indexed from 0 to *n* - 1, and

![](images/954d85f8c44a768d0814c95b7202d2f2d8b5fc92.png)We can calculate *c* fast using Fast Fourier Transformation.

DZY made a little change on this formula. Now

![](images/09afa7cc3a89ee532dca56e03f335bb766d7af37.png)To make things easier, *a* is a permutation of integers from 1 to *n*, and *b* is a sequence only containing 0 and 1. Given *a* and *b*, DZY needs your help to calculate *c*.

Because he is naughty, DZY provides a special way to get *a* and *b*. What you need is only three integers *n*, *d*, *x*. After getting them, use the code below to generate *a* and *b*.


```
  
//x is 64-bit variable;  
function getNextX() {  
    x = (x * 37 + 10007) % 1000000007;  
    return x;  
}  
function initAB() {  
    for(i = 0; i < n; i = i + 1){  
        a[i] = i + 1;  
    }  
    for(i = 0; i < n; i = i + 1){  
        swap(a[i], a[getNextX() % (i + 1)]);  
    }  
    for(i = 0; i < n; i = i + 1){  
        if (i < d)  
            b[i] = 1;  
        else  
            b[i] = 0;  
    }  
    for(i = 0; i < n; i = i + 1){  
        swap(b[i], b[getNextX() % (i + 1)]);  
    }  
}  
  

```
Operation x % y denotes remainder after division *x* by *y*. Function swap(x, y) swaps two values *x* and *y*.

## Input

The only line of input contains three space-separated integers *n*, *d*, *x* (1 ≤ *d* ≤ *n* ≤ 100000; 0 ≤ *x* ≤ 1000000006). Because DZY is naughty, *x* can't be equal to 27777500.

## Output

## Output

 *n* lines, the *i*-th line should contain an integer *c**i* - 1.

## Examples

## Input


```
3 1 1  

```
## Output


```
1  
3  
2  

```
## Input


```
5 4 2  

```
## Output


```
2  
2  
4  
5  
5  

```
## Input


```
5 4 3  

```
## Output


```
5  
5  
5  
5  
4  

```
## Note

In the first sample, *a* is [1 3 2], *b* is [1 0 0], so *c*0 = *max*(1·1) = 1, *c*1 = *max*(1·0, 3·1) = 3, *c*2 = *max*(1·0, 3·0, 2·1) = 2.

In the second sample, *a* is [2 1 4 5 3], *b* is [1 1 1 0 1].

In the third sample, *a* is [5 2 1 4 3], *b* is [1 1 1 1 0].



#### tags 

#2300 #probabilities 