<h1 style='text-align: center;'> E. Bear and Bowling</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Limak is an old brown bear. He often goes bowling with his friends. Today he feels really good and tries to beat his own record!

For rolling a ball one gets a score — an integer (maybe negative) number of points. Score for *i*-th roll is multiplied by *i* and scores are summed up. So, for *k* rolls with scores *s*1, *s*2, ..., *s**k*, total score is ![](images/c8a1cac733e2c38459a7a155ea158ee99d347e49.png). Total score is 0 if there were no rolls.

Limak made *n* rolls and got score *a**i* for *i*-th of them. He wants to maximize his total score and he came up with an interesting idea. He will cancel some rolls, saying that something distracted him or there was a strong wind.

Limak is able to cancel any number of rolls, maybe even all or none of them. Total score is calculated as if there were only non-canceled rolls. Look at the sample tests for clarification. What maximum total score can Limak get?

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 105).

The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (|*a**i*| ≤ 107) - scores for Limak's rolls.

## Output

Print the maximum possible total score after choosing rolls to cancel.

## Examples

## Input


```
5  
-2 -8 0 5 -3  

```
## Output


```
13  

```
## Input


```
6  
-10 20 -30 40 -50 60  

```
## Output


```
400  

```
## Note

In first sample Limak should cancel rolls with scores  - 8 and  - 3. Then he is left with three rolls with scores  - 2, 0, 5. Total score is 1·( - 2) + 2·0 + 3·5 = 13.

In second sample Limak should cancel roll with score  - 50. Total score is 1·( - 10) + 2·20 + 3·( - 30) + 4·40 + 5·60 = 400.



#### tags 

#3200 #data_structures #greedy 