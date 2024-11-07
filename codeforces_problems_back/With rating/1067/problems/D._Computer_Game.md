<h1 style='text-align: center;'> D. Computer Game</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ivan plays some computer game. There are $n$ quests in the game. Each quest can be upgraded once, this increases the reward for its completion. Each quest has $3$ parameters $a_{i}$, $b_{i}$, $p_{i}$: reward for completing quest before upgrade, reward for completing quest after upgrade ($a_{i} < b_{i}$) and probability of successful completing the quest.

Each second Ivan can try to complete one quest and he will succeed with probability $p_{i}$. In case of success Ivan will get the reward and opportunity to upgrade any one quest (not necessary the one he just completed). In case of failure he gets nothing. Quests do not vanish after completing.

Ivan has $t$ seconds. He wants to maximize expected value of his total gain after $t$ seconds. Help him to calculate this value.

## Input

First line contains $2$ integers $n$ ($ 1 \le n \le 10^{5}$) and $t$ ($ 1 \le t \le 10^{10}$) — number of quests and total time.

Following $n$ lines contain description of quests. Each description is $3$ numbers $a_{i}$ $b_{i}$ $p_{i}$ ($1 \le a_{i} < b_{i} \le 10^{8}$, $0 < p_{i} < 1$) — reward for completing quest before upgrade, reward for completing quest after upgrade and probability of successful completing of quest. $a_{i}$ and $b_{i}$ are integers. All probabilities are given with at most $9$ decimal places.

## Output

Print the expected value.

Your answer will be accepted if absolute or relative error does not exceed $10^{-6}$. Formally, let your answer be $a$, and the jury's answer be $b$. Your answer is considered correct if $\frac{|a-b|}{max⁡(b, \,\, 1)} \le 10^{-6}$.

## Examples

## Input


```
3 2  
3 1000 0.5  
1 2 0.48  
3 20 0.3  

```
## Output


```
252.2500000000000  

```
## Input


```
2 2  
1 1000 0.1  
2 3 0.2  

```
## Output


```
20.7200000000000  

```


#### tags 

#3100 #dp #greedy #math #probabilities 