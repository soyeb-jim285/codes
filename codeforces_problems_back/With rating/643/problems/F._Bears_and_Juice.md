<h1 style='text-align: center;'> F. Bears and Juice</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* bears in the inn and *p* places to sleep. Bears will party together for some number of nights (and days).

Bears love drinking juice. They don't like wine but they can't distinguish it from juice by taste or smell.

A bear doesn't sleep unless he drinks wine. A bear must go to sleep a few hours after drinking a wine. He will wake up many days after the party is over.

Radewoosh is the owner of the inn. He wants to put some number of barrels in front of bears. One barrel will contain wine and all other ones will contain juice. Radewoosh will challenge bears to find a barrel with wine.

Each night, the following happens in this exact order:

1. Each bear must choose a (maybe empty) set of barrels. The same barrel may be chosen by many bears.
2. Each bear drinks a glass from each barrel he chose.
3. All bears who drink wine go to sleep (exactly those bears who chose a barrel with wine). They will wake up many days after the party is over. If there are not enough places to sleep then bears lose immediately.

At the end, if it's sure where wine is and there is at least one awake bear then bears win (unless they have lost before because of the number of places to sleep).

Radewoosh wants to allow bears to win. He considers *q* scenarios. In the *i*-th scenario the party will last for *i* nights. Then, let *R**i* denote the maximum number of barrels for which bears surely win if they behave optimally. Let's define ![](images/aa85ca4caef891acc09b71a549d14e5ac2d80746.png). Your task is to find ![](images/a9508034c6074683459bbbd26844e1b3e9b41d5e.png), where ![](images/c4b7092c0f7ce6535f2574569c98f7b3c2fe2c5f.png) denotes the exclusive or (also denoted as XOR).

## Note

 that the same barrel may be chosen by many bears and all of them will go to sleep at once.

## Input

The only line of the input contains three integers *n*, *p* and *q* (1 ≤ *n* ≤ 109, 1 ≤ *p* ≤ 130, 1 ≤ *q* ≤ 2 000 000) — the number of bears, the number of places to sleep and the number of scenarios, respectively.

## Output

Print one integer, equal to ![](images/a9508034c6074683459bbbd26844e1b3e9b41d5e.png).

## Examples

## Input


```
5 1 3  

```
## Output


```
32  

```
## Input


```
1 100 4  

```
## Output


```
4  

```
## Input


```
3 2 1  

```
## Output


```
7  

```
## Input


```
100 100 100  

```
## Output


```
381863924  

```
## Note

In the first sample, there are 5 bears and only 1 place to sleep. We have *R*1 = 6, *R*2 = 11, *R*3 = 16 so the answer is ![](images/b3272ae710321a0a8ceffa5d8c9afe3bf54e75eb.png). Let's analyze the optimal strategy for scenario with 2 days. There are *R*2 = 11 barrels and 10 of them contain juice.

* In the first night, the *i*-th bear chooses a barrel *i* only.
	+ If one of the first 5 barrels contains wine then one bear goes to sleep. Then, bears win because they know where wine is and there is at least one awake bear.
	+ But let's say none of the first 5 barrels contains wine. In the second night, the *i*-th bear chooses a barrel 5 + *i*.
		- If one of barrels 6 – 10 contains wine then one bear goes to sleep. And again, bears win in such a situation.
		- If nobody went to sleep then wine is in a barrel 11.

In the second sample, there is only one bear. He should choose an empty set of barrels in each night. Otherwise, he would maybe get wine and bears would lose (because there must be at least one awake bear). So, for any number of days we have *R**i* = 1. The answer is ![](images/c8b4cc3bcaf1329398e221289359b01c0a392ec5.png).



#### tags 

#2900 #dp #math #meet-in-the-middle 