<h1 style='text-align: center;'> B. Need For Brake</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya plays the Need For Brake. He plays because he was presented with a new computer wheel for birthday! Now he is sure that he will win the first place in the championship in his favourite racing computer game! 

*n* racers take part in the championship, which consists of a number of races. After each race racers are arranged from place first to *n*-th (no two racers share the same place) and first *m* places are awarded. Racer gains *b**i* points for *i*-th awarded place, which are added to total points, obtained by him for previous races. It is known that current summary score of racer *i* is *a**i* points. In the final standings of championship all the racers will be sorted in descending order of points. Racers with an equal amount of points are sorted by increasing of the name in lexicographical order.

Unfortunately, the championship has come to an end, and there is only one race left. Vasya decided to find out what the highest and lowest place he can take up as a result of the championship.

## Input

The first line contains number *n* (1 ≤ *n* ≤ 105) — number of racers. Each of the next *n* lines contains *s**i* and *a**i* — nick of the racer (nonempty string, which consist of no more than 20 lowercase Latin letters) and the racer's points (0 ≤ *a**i* ≤ 106). Racers are given in the arbitrary order.

The next line contains the number *m* (0 ≤ *m* ≤ *n*). Then *m* nonnegative integer numbers *b**i* follow. *i*-th number is equal to amount of points for the *i*-th awarded place (0 ≤ *b**i* ≤ 106).

The last line contains Vasya's racer nick.

## Output

## Output

 two numbers — the highest and the lowest place Vasya can take up as a result of the championship.

## Examples

## Input


```
3  
teama 10  
teamb 20  
teamc 40  
2  
10 20  
teama  

```
## Output


```
2 3
```
## Input


```
2  
teama 10  
teamb 10  
2  
10 10  
teamb  

```
## Output


```
2 2
```


#### tags 

#2000 #binary_search #greedy #sortings 