<h1 style='text-align: center;'> E. Petya and Post</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Vasya's uncle is a postman. The post offices are located on one circular road. Besides, each post office has its own gas station located next to it. Petya's uncle works as follows: in the morning he should leave the house and go to some post office. In the office he receives a portion of letters and a car. Then he must drive in the given car exactly one round along the circular road and return to the starting post office (the uncle can drive along the circle in any direction, counterclockwise or clockwise). Besides, since the car belongs to the city post, it should also be fuelled with gasoline only at the Post Office stations. 

The total number of stations equals to *n*. One can fuel the car at the *i*-th station with no more than *a**i* liters of gasoline. Besides, one can fuel the car no more than once at each station. Also, the distance between the 1-st and the 2-nd station is *b*1 kilometers, the distance between the 2-nd and the 3-rd one is *b*2 kilometers, ..., between the (*n* - 1)-th and the *n*-th ones the distance is *b**n* - 1 kilometers and between the *n*-th and the 1-st one the distance is *b**n* kilometers. Petya's uncle's high-tech car uses only one liter of gasoline per kilometer. It is known that the stations are located so that the sum of all *a**i* is equal to the sum of all *b**i*. The *i*-th gas station and *i*-th post office are very close, so the distance between them is 0 kilometers.

Thus, it becomes clear that if we start from some post offices, then it is not always possible to drive one round along a circular road. The uncle faces the following problem: to what stations can he go in the morning to be able to ride exactly one circle along the circular road and visit all the post offices that are on it?

Petya, who used to attend programming classes, has volunteered to help his uncle, but his knowledge turned out to be not enough, so he asks you to help him write the program that will solve the posed problem.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105). The second line contains *n* integers *a**i* — amount of gasoline on the *i*-th station. The third line contains *n* integers *b*1, *b*2, ..., *b**n*. They are the distances between the 1-st and the 2-nd gas stations, between the 2-nd and the 3-rd ones, ..., between the *n*-th and the 1-st ones, respectively. The sum of all *b**i* equals to the sum of all *a**i* and is no more than 109. Each of the numbers *a**i*, *b**i* is no less than 1 and no more than 109.

## Output

Print on the first line the number *k* — the number of possible post offices, from which the car can drive one circle along a circular road. Print on the second line *k* numbers in the ascending order — the numbers of offices, from which the car can start.

## Examples

## Input


```
4  
1 7 2 3  
8 1 1 3  

```
## Output


```
2  
2 4  

```
## Input


```
8  
1 2 1 2 1 2 1 2  
2 1 2 1 2 1 2 1  

```
## Output


```
8  
1 2 3 4 5 6 7 8  

```


#### tags 

#2000 #data_structures #dp 