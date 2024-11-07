<h1 style='text-align: center;'> G. Game of Chance</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

The King wants to marry off his daughter, and he wants her husband to have the greatest innate luckiness possible. To find such a person he decided to hold a heads-or-tails tournament. 

If person $A$ with luckiness $x$ and person $B$ with luckiness $y$ play heads-or-tails against each other, person $A$ wins with probability $x/(x+y)$. 

The tournament has several rounds. Each round some participants are split into pairs. Each pair plays against each other, and the loser leaves the tournament. 

The participants are numbered from $1$ to $n$. During the first round, a number $k$ ($1 \le k \le n$) is selected such that $n-k/2$ is a power of $2$ (such $k$ always exists and is unique). Only participants numbered from $1$ to $k$ take part in the first round. It ensures that in all other rounds the number of participants is the power of $2$. 

During other rounds, all the participants who still have not left the tournament take part. If during some round, participants numbered $p_1 < \ldots < p_{2m}$ take part, then they are split into pairs in the following manner: participant $p_{2i-1}$ plays against participant $p_{2i}$ for each $i$ from $1$ to $m$. 

The rounds are held until only one participant is left. He is declared the winner of the tournament and he will marry the King's daughter. The princess can't wait to find out who is her future husband. She asked every participant to tell her his luckiness. Assuming they did not lie, she wants to know the probability of each participant winning the tournament. As you are the best friend of the princess, she asks you to help her.

### Input

The first line of the input contains the number of participants, $n$ ($2 \le n \le 3 \cdot 10^5$). The second line of the input contains $n$ integer numbers, $a_1, \ldots, a_{n}$ ($1 \le a_i \le 10^9$). The luckiness of the $i$-th participant equals to $a_i$.

### Output

Print $n$ numbers $p_i$. The $i$-th number should be the probability of the $i$-th participant winning the tournament. The absolute error of your answer must not exceed $10^{-9}$.

## Example

### Input


```text
5
1 4 1 1 4
```
### Output


```text
0.026 0.3584 0.0676 0.0616 0.4864
```
## Note

Here is an example of a tournament bracket, showing the winning probability in each pair.

 ![](images/18b84d65937b16f06814512441764fd5410233ec.png) 

#### Tags 

#3500 #NOT OK #math #probabilities 

## Blogs
- [All Contest Problems](../ICPC_WF_Moscow_Invitational_Contest_-_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
