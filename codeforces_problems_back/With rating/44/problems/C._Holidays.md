<h1 style='text-align: center;'> C. Holidays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

School holidays come in Berland. The holidays are going to continue for *n* days. The students of school №*N* are having the time of their lives and the IT teacher Marina Sergeyevna, who has spent all the summer busy checking the BSE (Berland State Examination) results, has finally taken a vacation break! Some people are in charge of the daily watering of flowers in shifts according to the schedule. However when Marina Sergeyevna was making the schedule, she was so tired from work and so lost in dreams of the oncoming vacation that she perhaps made several mistakes. In fact, it is possible that according to the schedule, on some days during the holidays the flowers will not be watered or will be watered multiple times. Help Marina Sergeyevna to find a mistake.

## Input

The first input line contains two numbers *n* and *m* (1 ≤ *n*, *m* ≤ 100) — the number of days in Berland holidays and the number of people in charge of the watering respectively. The next *m* lines contain the description of the duty schedule. Each line contains two integers *a**i* and *b**i* (1 ≤ *a**i* ≤ *b**i* ≤ *n*), meaning that the *i*-th person in charge should water the flowers from the *a**i*-th to the *b**i*-th day inclusively, once a day. The duty shifts are described sequentially, i.e. *b**i* ≤ *a**i* + 1 for all *i* from 1 to *n* - 1 inclusively. 

## Output

Print "OK" (without quotes), if the schedule does not contain mistakes. Otherwise you have to find the minimal number of a day when the flowers will not be watered or will be watered multiple times, and output two integers — the day number and the number of times the flowers will be watered that day.

## Examples

## Input


```
10 5  
1 2  
3 3  
4 6  
7 7  
8 10  

```
## Output


```
OK  

```
## Input


```
10 5  
1 2  
2 3  
4 5  
7 8  
9 10  

```
## Output


```
2 2  

```
## Input


```
10 5  
1 2  
3 3  
5 7  
7 7  
7 10  

```
## Output


```
4 0  

```
## Note

Keep in mind that in the second sample the mistake occurs not only on the second day, but also on the sixth day, when nobody waters the flowers. However, you have to print the second day, i.e. the day with the minimal number.



#### tags 

#1300 #implementation 