<h1 style='text-align: center;'> B. Glad to see you!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem. In the output section below you will see the information about flushing the output.

On Sunday Leha the hacker took Nura from the house where she lives and went with her to one of the most luxurious restaurants in Vičkopolis. Upon arrival, they left the car in a huge parking lot near the restaurant and hurried inside the building.

In the restaurant a polite waiter immediately brought the menu to Leha and Noora, consisting of *n* dishes. It is interesting that all dishes in the menu are numbered with integers from 1 to *n*. After a little thought, the girl ordered exactly *k* different dishes from available in the menu. To pass the waiting time while the chefs prepare ordered dishes, the girl invited the hacker to play a game that will help them get to know each other better.

The game itself is very simple: Noora wants Leha to guess any two dishes among all ordered. At the same time, she is ready to answer only one type of questions. Leha can say two numbers *x* and *y* (1 ≤ *x*, *y* ≤ *n*). After that Noora chooses some dish *a* for the number *x* such that, at first, *a* is among the dishes Noora ordered (*x* can be equal to *a*), and, secondly, the value ![](images/e5a4a1705bc256e413564795cc8b70857f0ae44c.png) is the minimum possible. By the same rules the girl chooses dish *b* for *y*. After that Noora says «TAK» to Leha, if ![](images/a65cb6a9b614699e12e529560e2d39ffa39127db.png), and «NIE» otherwise. However, the restaurant is preparing quickly, so Leha has enough time to ask no more than 60 questions. After that he should name numbers of any two dishes Noora ordered.

Help Leha to solve this problem!

## Input

There are two numbers *n* and *k* (2 ≤ *k* ≤ *n* ≤ 105) in the single line of input denoting the number of dishes in the menu and the number of dishes Noora ordered.

## Output

If you want to provide an answer, output a string of the form 2 *x* *y* (1 ≤ *x*, *y* ≤ *n*, *x* ≠ *y*), if you think the dishes *x* and *y* was among dishes ordered by Noora. After that, flush the output and terminate your program.

## Interaction

While helping Leha, you can ask queries to Noora no more than 60 times. Each query should be printed in it's own line and have the form 1 *x* *y* (1 ≤ *x*, *y* ≤ *n*). You have to both print the end-of-line character and flush the output. After flushing you should read the answer for this query from input.

After each query jury's program will print one line «TAK» or «NIE» (without quotes) in input stream depending on the girl's answer.

To flush you can use (just after printing an integer and end-of-line):

* fflush(stdout) in C++;
* System.out.flush() in Java;
* stdout.flush() in Python;
* flush(output) in Pascal;
* see the documentation for other languages.

Hacking

For hacking you should write numbers *n* and *k* (2 ≤ *k* ≤ *n* ≤ 105) in the first line and, for describing dishes Noora ordered, *k* different integers *a*1, *a*2, ..., *a**k* (1 ≤ *a**i* ≤ *n*), written in ascending order in the second line. Of course, solution you want to hack won't be able to read the numbers of ordered dishes.

## Example

## Input


```
3 2  
NIE  
TAK  
NIE  
TAK  
TAK  
TAK  

```
## Output


```
1 1 2  
1 2 1  
1 1 3  
1 3 1  
1 2 3  
1 3 2  
2 2 3  

```
## Note

There are three dishes in sample. Noora ordered dished numberes 2 and 3, which Leha should guess. If Noora receive requests for the first dish (*x* = 1), then she'll choose the second dish (*a* = 2) as the dish with the minimum value ![](images/e5a4a1705bc256e413564795cc8b70857f0ae44c.png). For the second (*x* = 2) and the third (*x* = 3) dishes themselves will be optimal, because in that case ![](images/79add195d023131e992b60a354fec89501759e75.png). 

Let Leha asks Noora about the next couple of dishes:

* *x* = 1, *y* = 2, then he'll recieve «NIE» answer, because |1 - 2| > |2 - 2|
* *x* = 2, *y* = 1, then he'll recieve «TAK» answer, because |2 - 2| ≤ |1 - 2|
* *x* = 1, *y* = 3, then he'll recieve «NIE» answer, because |1 - 2| > |3 - 3|
* *x* = 3, *y* = 1, then he'll recieve «TAK» answer, because |3 - 3| ≤ |1 - 2|
* *x* = 2, *y* = 3, then he'll recieve «TAK» answer, because |2 - 2| ≤ |3 - 3|
* *x* = 3, *y* = 2, then he'll recieve «TAK» answer, because |3 - 3| ≤ |2 - 2|

According to the available information, it is possible to say that Nura ordered dishes with numbers 2 and 3.



#### tags 

#2200 #binary_search #interactive 