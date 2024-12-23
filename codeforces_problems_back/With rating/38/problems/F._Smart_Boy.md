<h1 style='text-align: center;'> F. Smart Boy</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once Petya and Vasya invented a new game and called it "Smart Boy". They located a certain set of words — the dictionary — for the game. It is admissible for the dictionary to contain similar words. 

The rules of the game are as follows: first the first player chooses any letter (a word as long as 1) from any word from the dictionary and writes it down on a piece of paper. The second player adds some other letter to this one's initial or final position, thus making a word as long as 2, then it's the first player's turn again, he adds a letter in the beginning or in the end thus making a word as long as 3 and so on. But the player mustn't break one condition: the newly created word must be a substring of a word from a dictionary. The player who can't add a letter to the current word without breaking the condition loses.

Also if by the end of a turn a certain string *s* is written on paper, then the player, whose turn it just has been, gets a number of points according to the formula:

![](images/831de813618e0dc55fa0e07c8768f46b91d18927.png)where 

* ![](images/ba84be02bcc8a18469dd8faac3056b4c4eb0054f.png) is a sequence number of symbol *c* in Latin alphabet, numbered starting from 1. For example, ![](images/691184ea4a48c6be138dfe5989d6d0e5e3184a6b.png), and ![](images/a92af08618cdbc859838ca588e67ffbee1b7683d.png).
* ![](images/52774077a8c15647cbf170fd26873d90f60c914a.png) is the number of words from the dictionary where the line *s* occurs as a substring at least once.

Your task is to learn who will win the game and what the final score will be. Every player plays optimally and most of all tries to win, then — to maximize the number of his points, then — to minimize the number of the points of the opponent.

## Input

The first input line contains an integer *n* which is the number of words in the located dictionary (1 ≤ *n* ≤ 30). The *n* lines contain the words from the dictionary — one word is written on one line. Those lines are nonempty, consisting of Latin lower-case characters no longer than 30 characters. Equal words can be in the list of words.

## Output

On the first output line print a line "First" or "Second" which means who will win the game. On the second line output the number of points of the first player and the number of points of the second player after the game ends. Separate the numbers by a single space.

## Examples

## Input


```
2  
aba  
abac  

```
## Output


```
Second  
29 35  

```
## Input


```
3  
artem  
nik  
max  

```
## Output


```
First  
2403 1882  

```


#### tags 

#2100 #dp #games #strings 