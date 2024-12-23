<h1 style='text-align: center;'> E. Appleman and a Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Appleman and Toastman like games. Today they play a game with strings with the following rules. Firstly Toastman tells Appleman two strings *s* and *t* both consisting only of letters 'A', 'B', 'C', 'D'. Then Appleman must build string *s* as quickly as possible. Initially he has empty string, and in one second he can append to end of the current string any contiguous substring of *t*.

Now, Toastman and Appleman are beginning to play the game. Toastman has already told string *t* to Appleman, but he hasn't come up with string *s* yet. Toastman only thinks, that he should choose string *s* consisting of *n* characters. Of course, he wants to find the worst string for Appleman (such string, that Appleman will spend as much time as possible during the game). Tell Toastman, how much time will Appleman spend during the game if Toastman finds the worst string for him. You can assume that Appleman plays optimally, therefore he builds any string *s* in minimal possible time.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 1018). The second line contains string *t* (1 ≤ |*t*| ≤ 105). String *t* consists of only letters 'A', 'B', 'C', 'D'. Each letter appears at least once in string *t*.

## Output

Print a single integer — the largest possible time Appleman needs.

## Examples

## Input


```
5  
ABCCAD  

```
## Output


```
5  

```
## Input


```
5  
AAABACADBABBBCBDCACBCCCDDDBDCDD  

```
## Output


```
4  

```
## Note

In the first example, Toastman can choose *s* equal to "AAAAA".

In the second example, Toastman can choose *s* equal to "DADDA".



#### tags 

#3000 #binary_search #shortest_paths #strings 