<h1 style='text-align: center;'> B. Keyboard</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya learns to type. He has an unusual keyboard at his disposal: it is rectangular and it has *n* rows of keys containing *m* keys in each row. Besides, the keys are of two types. Some of the keys have lowercase Latin letters on them and some of the keys work like the "Shift" key on standard keyboards, that is, they make lowercase letters uppercase.

Vasya can press one or two keys with one hand. However, he can only press two keys if the Euclidean distance between the centers of the keys does not exceed *x*. The keys are considered as squares with a side equal to 1. There are no empty spaces between neighbouring keys.

Vasya is a very lazy boy, that's why he tries to type with one hand as he eats chips with his other one. However, it is possible that some symbol can't be typed with one hand only, because the distance between it and the closest "Shift" key is strictly larger than *x*. In this case he will have to use his other hand. Having typed the symbol, Vasya returns other hand back to the chips.

You are given Vasya's keyboard and the text. Count the minimum number of times Vasya will have to use the other hand.

## Input

The first line contains three integers *n*, *m*, *x* (1 ≤ *n*, *m* ≤ 30, 1 ≤ *x* ≤ 50).

Next *n* lines contain descriptions of all the keyboard keys. Each line contains the descriptions of exactly *m* keys, without spaces. The letter keys are marked with the corresponding lowercase letters. The "Shift" keys are marked with the "S" symbol. 

Then follow the length of the text *q* (1 ≤ *q* ≤ 5·105). The last line contains the text *T*, which consists of *q* symbols, which are uppercase and lowercase Latin letters.

## Output

If Vasya can type the text, then print the minimum number of times he will have to use his other hand. Otherwise, print "-1" (without the quotes).

## Examples

## Input


```
2 2 1  
ab  
cd  
1  
A  

```
## Output


```
-1  

```
## Input


```
2 2 1  
ab  
cd  
1  
e  

```
## Output


```
-1  

```
## Input


```
2 2 1  
ab  
cS  
5  
abcBA  

```
## Output


```
1  

```
## Input


```
3 9 4  
qwertyuio  
asdfghjkl  
SzxcvbnmS  
35  
TheQuIcKbRoWnFOXjummsovertHeLazYDOG  

```
## Output


```
2  

```
## Note

In the first sample the symbol "A" is impossible to print as there's no "Shift" key on the keyboard.

In the second sample the symbol "e" is impossible to print as there's no such key on the keyboard.

In the fourth sample the symbols "T", "G" are impossible to print with one hand. The other letters that are on the keyboard can be printed. Those symbols come up in the text twice, thus, the answer is 2.



#### tags 

#1500 #implementation 