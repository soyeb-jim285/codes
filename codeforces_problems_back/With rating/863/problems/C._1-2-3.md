<h1 style='text-align: center;'> C. 1-2-3</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ilya is working for the company that constructs robots. Ilya writes programs for entertainment robots, and his current project is "Bob", a new-generation game robot. Ilya's boss wants to know his progress so far. Especially he is interested if Bob is better at playing different games than the previous model, "Alice". 

So now Ilya wants to compare his robots' performance in a simple game called "1-2-3". This game is similar to the "Rock-Paper-Scissors" game: both robots secretly choose a number from the set {1, 2, 3} and say it at the same moment. If both robots choose the same number, then it's a draw and noone gets any points. But if chosen numbers are different, then one of the robots gets a point: 3 beats 2, 2 beats 1 and 1 beats 3. 

Both robots' programs make them choose their numbers in such a way that their choice in (*i* + 1)-th game depends only on the numbers chosen by them in *i*-th game. 

Ilya knows that the robots will play *k* games, Alice will choose number *a* in the first game, and Bob will choose *b* in the first game. He also knows both robots' programs and can tell what each robot will choose depending on their choices in previous game. Ilya doesn't want to wait until robots play all *k* games, so he asks you to predict the number of points they will have after the final game. 

## Input

The first line contains three numbers *k*, *a*, *b* (1 ≤ *k* ≤ 1018, 1 ≤ *a*, *b* ≤ 3). 

Then 3 lines follow, *i*-th of them containing 3 numbers *A**i*, 1, *A**i*, 2, *A**i*, 3, where *A**i*, *j* represents Alice's choice in the game if Alice chose *i* in previous game and Bob chose *j* (1 ≤ *A**i*, *j* ≤ 3). 

Then 3 lines follow, *i*-th of them containing 3 numbers *B**i*, 1, *B**i*, 2, *B**i*, 3, where *B**i*, *j* represents Bob's choice in the game if Alice chose *i* in previous game and Bob chose *j* (1 ≤ *B**i*, *j* ≤ 3). 

## Output

Print two numbers. First of them has to be equal to the number of points Alice will have, and second of them must be Bob's score after *k* games.

## Examples

## Input


```
10 2 1  
1 1 1  
1 1 1  
1 1 1  
2 2 2  
2 2 2  
2 2 2  

```
## Output


```
1 9  

```
## Input


```
8 1 1  
2 2 1  
3 3 1  
3 1 3  
1 1 1  
2 1 1  
1 2 3  

```
## Output


```
5 2  

```
## Input


```
5 1 1  
1 2 2  
2 2 2  
2 2 2  
1 2 2  
2 2 2  
2 2 2  

```
## Output


```
0 0  

```
## Note

In the second example game goes like this:

![](images/1e21b6e200707470571d69c9946ace6b56f5279b.png)

The fourth and the seventh game are won by Bob, the first game is draw and the rest are won by Alice.



#### tags 

#1800 #graphs #implementation 