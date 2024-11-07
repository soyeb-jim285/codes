<h1 style='text-align: center;'> F. Banners</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

All modern mobile applications are divided into free and paid. Even a single application developers often release two versions: a paid version without ads and a free version with ads.

 ![](images/b84bb1e422f6a97bc24c28cd7f92e7591f236cfd.png) Suppose that a paid version of the app costs *p* (*p* is an integer) rubles, and the free version of the application contains *c* ad banners. Each user can be described by two integers: *a**i* — the number of rubles this user is willing to pay for the paid version of the application, and *b**i* — the number of banners he is willing to tolerate in the free version.

The behavior of each member shall be considered strictly deterministic:

* if for user *i*, value *b**i* is at least *c*, then he uses the free version,
* otherwise, if value *a**i* is at least *p*, then he buys the paid version without advertising,
* otherwise the user simply does not use the application.

Each user of the free version brings the profit of *c* × *w* rubles. Each user of the paid version brings the profit of *p* rubles.

Your task is to help the application developers to select the optimal parameters *p* and *c*. Namely, knowing all the characteristics of users, for each value of *c* from 0 to (*max* *b**i*) + 1 you need to determine the maximum profit from the application and the corresponding parameter *p*.

## Input

The first line contains two integers *n* and *w* (1 ≤ *n* ≤ 105; 1 ≤ *w* ≤ 105) — the number of users and the profit from a single banner. Each of the next *n* lines contains two integers *a**i* and *b**i* (0 ≤ *a**i*, *b**i* ≤ 105) — the characteristics of the *i*-th user.

## Output

Print (*max* *b**i*) + 2 lines, in the *i*-th line print two integers: *pay* — the maximum gained profit at *c* = *i* - 1, *p* (0 ≤ *p* ≤ 109) — the corresponding optimal app cost. If there are multiple optimal solutions, print any of them.

## Examples

## Input


```
2 1  
2 0  
0 2  

```
## Output


```
0 3  
3 2  
4 2  
2 2  

```
## Input


```
3 1  
3 1  
2 2  
1 3  

```
## Output


```
0 4  
3 4  
7 3  
7 2  
4 2  

```


#### tags 

#3000 #brute_force #data_structures #dp 