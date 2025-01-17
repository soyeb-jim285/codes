<h1 style='text-align: center;'> C. Helping People</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Malek is a rich man. He also is very generous. That's why he decided to split his money between poor people. A charity institute knows *n* poor people numbered from 1 to *n*. The institute gave Malek *q* recommendations. A recommendation is a segment of people like [*l*, *r*] which means the institute recommended that Malek gives one dollar to every person whose number is in this segment.

However this charity has very odd rules about the recommendations. Because of those rules the recommendations are given in such a way that for every two recommendation [*a*, *b*] and [*c*, *d*] one of the following conditions holds: 

* The two segments are completely disjoint. More formally either *a* ≤ *b* < *c* ≤ *d* or *c* ≤ *d* < *a* ≤ *b*
* One of the two segments are inside another. More formally either *a* ≤ *c* ≤ *d* ≤ *b* or *c* ≤ *a* ≤ *b* ≤ *d*.

The goodness of a charity is the value of maximum money a person has after Malek finishes giving his money. The institute knows for each recommendation what is the probability that Malek will accept it. They want to know the expected value of goodness of this charity. So they asked you for help.

You have been given the list of recommendations and for each recommendation the probability of it being accepted by Malek. You have also been given how much money each person initially has. You must find the expected value of goodness.

## Input

In the first line two space-separated integers *n*, *q* (1 ≤ *n* ≤ 105, 1 ≤ *q* ≤ 5000) are given.

In the second line *n* space-separated integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 109) are given meaning that person number *i* initially has *a**i* dollars. 

Each of the next *q* lines contains three space-separated numbers *l**i*, *r**i*, *p**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*, 0 ≤ *p* ≤ 1) where *l**i* and *r**i* are two integers describing the segment of recommendation and *p**i* is a real number given with exactly three digits after decimal point which is equal to probability of Malek accepting this recommendation.

Note that a segment may appear several times in recommendations.

## Output

## Output

 the sought value. Your answer will be considered correct if its absolute or relative error is less than 10- 6.

## Examples

## Input


```
5 2  
1 7 2 4 3  
1 3 0.500  
2 2 0.500  

```
## Output


```
8.000000000  

```
## Input


```
5 2  
281 280 279 278 282  
1 4 1.000  
1 4 0.000  

```
## Output


```
282.000000000  

```
## Input


```
3 5  
1 2 3  
1 3 0.500  
2 2 0.250  
1 2 0.800  
1 1 0.120  
2 2 0.900  

```
## Output


```
4.465000000  

```


#### tags 

#2600 #dp #probabilities 