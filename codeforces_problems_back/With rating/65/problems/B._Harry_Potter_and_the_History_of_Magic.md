<h1 style='text-align: center;'> B. Harry Potter and the History of Magic</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The History of Magic is perhaps the most boring subject in the Hogwarts school of Witchcraft and Wizardry. Harry Potter is usually asleep during history lessons, and his magical quill writes the lectures for him. Professor Binns, the history of magic teacher, lectures in such a boring and monotonous voice, that he has a soporific effect even on the quill. That's why the quill often makes mistakes, especially in dates.

So, at the end of the semester Professor Binns decided to collect the students' parchments with notes and check them. Ron Weasley is in a panic: Harry's notes may contain errors, but at least he has some notes, whereas Ron does not have any. Ronald also has been sleeping during the lectures and his quill had been eaten by his rat Scabbers. Hermione Granger refused to give Ron her notes, because, in her opinion, everyone should learn on their own. Therefore, Ron has no choice but to copy Harry's notes.

Due to the quill's errors Harry's dates are absolutely confused: the years of goblin rebellions and other important events for the wizarding world do not follow in order, and sometimes even dates from the future occur. Now Ron wants to change some of the digits while he copies the notes so that the dates were in the chronological (i.e. non-decreasing) order and so that the notes did not have any dates strictly later than 2011, or strictly before than 1000. To make the resulting sequence as close as possible to the one dictated by Professor Binns, Ron will change no more than one digit in each date into other digit. Help him do it.

## Input

The first input line contains an integer *n* (1 ≤ *n* ≤ 1000). It represents the number of dates in Harry's notes. Next *n* lines contain the actual dates *y*1, *y*2, ..., *y**n*, each line contains a date. Each date is a four-digit integer (1000 ≤ *y**i* ≤ 9999).

## Output

Print *n* numbers *z*1, *z*2, ..., *z**n* (1000 ≤ *z**i* ≤ 2011). They are Ron's resulting dates. Print each number on a single line. Numbers *z**i* must form the non-decreasing sequence. Each number *z**i* should differ from the corresponding date *y**i* in no more than one digit. It is not allowed to change the first digit of a number into 0. If there are several possible solutions, print any of them. If there's no solution, print "No solution" (without the quotes).

## Examples

## Input


```
3  
1875  
1936  
1721  

```
## Output


```
1835  
1836  
1921  

```
## Input


```
4  
9999  
2000  
3000  
3011  

```
## Output


```
1999  
2000  
2000  
2011  

```
## Input


```
3  
1999  
5055  
2000  

```
## Output


```
No solution  

```


#### tags 

#1700 #brute_force #greedy #implementation 