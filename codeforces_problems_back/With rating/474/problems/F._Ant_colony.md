<h1 style='text-align: center;'> F. Ant colony</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mole is hungry again. He found one ant colony, consisting of *n* ants, ordered in a row. Each ant *i* (1 ≤ *i* ≤ *n*) has a strength *s**i*.

In order to make his dinner more interesting, Mole organizes a version of «Hunger Games» for the ants. He chooses two numbers *l* and *r* (1 ≤ *l* ≤ *r* ≤ *n*) and each pair of ants with indices between *l* and *r* (inclusively) will fight. When two ants *i* and *j* fight, ant *i* gets one battle point only if *s**i* divides *s**j* (also, ant *j* gets one battle point only if *s**j* divides *s**i*). 

After all fights have been finished, Mole makes the ranking. An ant *i*, with *v**i* battle points obtained, is going to be freed only if *v**i* = *r* - *l*, or in other words only if it took a point in every fight it participated. After that, Mole eats the rest of the ants. ## Note

 that there can be many ants freed or even none.

In order to choose the best sequence, Mole gives you *t* segments [*l**i*, *r**i*] and asks for each of them how many ants is he going to eat if those ants fight.

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 105), the size of the ant colony. 

The second line contains *n* integers *s*1, *s*2, ..., *s**n* (1 ≤ *s**i* ≤ 109), the strengths of the ants. 

The third line contains one integer *t* (1 ≤ *t* ≤ 105), the number of test cases. 

Each of the next *t* lines contains two integers *l**i* and *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*), describing one query.

## Output

Print to the standard output *t* lines. The *i*-th line contains number of ants that Mole eats from the segment [*l**i*, *r**i*].

## Examples

## Input


```
5  
1 3 2 4 2  
4  
1 5  
2 5  
3 5  
4 5  

```
## Output


```
4  
4  
1  
1  

```
## Note

In the first test battle points for each ant are *v* = [4, 0, 2, 0, 2], so ant number 1 is freed. Mole eats the ants 2, 3, 4, 5.

In the second test case battle points are *v* = [0, 2, 0, 2], so no ant is freed and all of them are eaten by Mole.

In the third test case battle points are *v* = [2, 0, 2], so ants number 3 and 5 are freed. Mole eats only the ant 4.

In the fourth test case battle points are *v* = [0, 1], so ant number 5 is freed. Mole eats the ant 4.



#### tags 

#2100 #data_structures #math #number_theory 