<h1 style='text-align: center;'> D. Nanami's Power Plant</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Nanami likes playing games, and is also really good at it. This day she was playing a new game which involved operating a power plant. Nanami's job is to control the generators in the plant and produce maximum output.

There are *n* generators in the plant. Each generator should be set to a generating level. Generating level is an integer (possibly zero or negative), the generating level of the *i*-th generator should be between *l**i* and *r**i* (both inclusive). The output of a generator can be calculated using a certain quadratic function *f*(*x*), where *x* is the generating level of the generator. Each generator has its own function, the function of the *i*-th generator is denoted as *f**i*(*x*).

However, there are *m* further restrictions to the generators. Let the generating level of the *i*-th generator be *x**i*. Each restriction is of the form *x**u* ≤ *x**v* + *d*, where *u* and *v* are IDs of two different generators and *d* is an integer.

Nanami found the game tedious but giving up is against her creed. So she decided to have a program written to calculate the answer for her (the maximum total output of generators). Somehow, this became your job.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 50; 0 ≤ *m* ≤ 100) — the number of generators and the number of restrictions.

Then follow *n* lines, each line contains three integers *a**i*, *b**i*, and *c**i* (|*a**i*| ≤ 10; |*b**i*|, |*c**i*| ≤ 1000) — the coefficients of the function *f**i*(*x*). That is, *f**i*(*x*) = *a**i**x*2 + *b**i**x* + *c**i*.

Then follow another *n* lines, each line contains two integers *l**i* and *r**i* ( - 100 ≤ *l**i* ≤ *r**i* ≤ 100).

Then follow *m* lines, each line contains three integers *u**i*, *v**i*, and *d**i* (1 ≤ *u**i*, *v**i* ≤ *n*; *u**i* ≠ *v**i*; |*d**i*| ≤ 200), describing a restriction. The *i*-th restriction is *x**u**i* ≤ *x**v**i* + *d**i*.

## Output

Print a single line containing a single integer — the maximum output of all the generators. It is guaranteed that there exists at least one valid configuration.

## Examples

## Input


```
3 3  
0 1 0  
0 1 1  
0 1 2  
0 3  
1 2  
-100 100  
1 2 0  
2 3 0  
3 1 0  

```
## Output


```
9  

```
## Input


```
5 8  
1 -8 20  
2 -4 0  
-1 10 -10  
0 1 0  
0 -1 1  
1 9  
1 4  
0 10  
3 11  
7 9  
2 1 3  
1 2 3  
2 3 3  
3 2 3  
3 4 3  
4 3 3  
4 5 3  
5 4 3  

```
## Output


```
46  

```
## Note

In the first sample, *f*1(*x*) = *x*, *f*2(*x*) = *x* + 1, and *f*3(*x*) = *x* + 2, so we are to maximize the sum of the generating levels. The restrictions are *x*1 ≤ *x*2, *x*2 ≤ *x*3, and *x*3 ≤ *x*1, which gives us *x*1 = *x*2 = *x*3. The optimal configuration is *x*1 = *x*2 = *x*3 = 2, which produces an output of 9.

In the second sample, restrictions are equal to |*x**i* - *x**i* + 1| ≤ 3 for 1 ≤ *i* < *n*. One of the optimal configurations is *x*1 = 1, *x*2 = 4, *x*3 = 5, *x*4 = 8 and *x*5 = 7.



#### tags 

#2900 #flows 