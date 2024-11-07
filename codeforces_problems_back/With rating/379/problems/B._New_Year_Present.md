<h1 style='text-align: center;'> B. New Year Present</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The New Year is coming! That's why many people today are busy preparing New Year presents. Vasily the Programmer is no exception.

Vasily knows that the best present is (no, it's not a contest) money. He's put *n* empty wallets from left to right in a row and decided how much money to put in what wallet. Vasily decided to put *a**i* coins to the *i*-th wallet from the left.

Vasily is a very busy man, so the money are sorted into the bags by his robot. Initially, the robot stands by the leftmost wallet in the row. The robot can follow instructions of three types: go to the wallet that is to the left of the current one (if such wallet exists), go to the wallet that is to the right of the current one (if such wallet exists), put a coin to the current wallet. Due to some technical malfunctions the robot cannot follow two "put a coin" instructions in a row.

Vasily doesn't want to wait for long, so he wants to write a program for the robot that contains at most 106 operations (not necessarily minimum in length) the robot can use to put coins into the wallets. Help him.

## Input

The first line contains integer *n* (2 ≤ *n* ≤ 300) — the number of wallets. The next line contains *n* integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 300).

It is guaranteed that at least one *a**i* is positive.

## Output

Print the sequence that consists of *k* (1 ≤ *k* ≤ 106) characters, each of them equals: "L", "R" or "P". Each character of the sequence is an instruction to the robot. Character "L" orders to move to the left, character "R" orders to move to the right, character "P" orders the robot to put a coin in the wallet. The robot is not allowed to go beyond the wallet line. In other words, you cannot give instructions "L" if the robot is at wallet 1, or "R" at wallet *n*.

As a result of the performed operations, the *i*-th wallet from the left must contain exactly *a**i* coins. If there are multiple answers, you can print any of them.

## Examples

## Input


```
2  
1 2  

```
## Output


```
PRPLRP
```
## Input


```
4  
0 2 0 2  

```
## Output


```
RPRRPLLPLRRRP
```


#### tags 

#1200 #constructive_algorithms #implementation 