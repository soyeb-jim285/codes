<h1 style='text-align: center;'> E. Heaven Tour</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The story was not finished as PMP thought. God offered him one more chance to reincarnate and come back to life. But before he can come back, God told him that PMP should ask *n* great men including prominent programmers about their life experiences.

The men are standing on a straight line. They are numbered 1 through *n* from left to right. The coordinate of the *i*-th man is *x**i* (*x**i* < *x**i* + 1, *i* < *n*). PMP should visit all these people one by one in arbitrary order. Each men should be visited exactly once. At the beginning of his tour, he starts at location of *s*-th man and asks him about his experiences.

Each time PMP wants to change his location, he should give a ticket to an angel and the angel carries him to his destination. Angels take PMP from one location, fly to his destination and put him down there. Nobody else is visited in this movement. Moving from *i*-th man to *j*-th man, takes |*x**i* - *x**j*| time. PMP can get back to life as soon as he visits all men.

There are two types of angels: Some angels are going to the right and they only accept right tickets. Others are going the left and they only accept left tickets. There are an unlimited number of angels of each type. PMP has *l* left tickets and *n* - 1 - *l* right tickets.

PMP wants to get back to life as soon as possible to be able to compete in this year's final instead of the final he missed last year. He wants to know the quickest way to visit all the men exactly once. He also needs to know the exact sequence moves he should make.

## Input

The first line of input contains three space-separated integers *n*, *l*, *s* (2 ≤ *n* ≤ 105, 0 ≤ *l* < *n*, 1 ≤ *s* ≤ *n*) — the number of people to visit, the number left tickets PMP got, and initial location of PMP. Next line contains *n* space-separated integers. The *i*-th integer in this line is *x**i* (0 = *x*1 < *x*2 < ... < *x**n* ≤ 109) — the location of *i*-th man.

## Output

If PMP cannot visit all men with the tickets he got print -1 in the only line of output. Otherwise, in the first line you should print the minimum time PMP can visit all men. In the second line you should print *n* - 1 integers that are the numbers of the men that PMP should visit in order in one optimal solution. If there are multiple answers, output any of them.

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d specifier.

## Examples

## Input


```
5 2 2  
0 10 11 21 22  

```
## Output


```
33  
1 3 5 4  

```
## Input


```
4 3 1  
0 1 2 3  

```
## Output


```
-1  

```
## Input


```
7 3 2  
0 100 200 201 301 303 305  

```
## Output


```
409  
1 3 4 7 6 5  

```
## Note

Let us remind here, a great contestant of all times, who left us about a year ago. May Renat Mullakhanov rest in peace.



#### tags 

#2900 #data_structures #greedy 