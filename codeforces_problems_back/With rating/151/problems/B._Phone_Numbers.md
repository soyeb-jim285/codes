<h1 style='text-align: center;'> B. Phone Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Winters are just damn freezing cold in Nvodsk! That's why a group of *n* friends prefers to take a taxi, order a pizza and call girls. The phone numbers in the city consist of three pairs of digits (for example, 12-34-56). Each friend has a phonebook of size *s**i* (that's the number of phone numbers). We know that taxi numbers consist of six identical digits (for example, 22-22-22), the numbers of pizza deliveries should necessarily be decreasing sequences of six different digits (for example, 98-73-21), all other numbers are the girls' numbers.

You are given your friends' phone books. Calculate which friend is best to go to when you are interested in each of those things (who has maximal number of phone numbers of each type). 

If the phone book of one person contains some number two times, you should count it twice. That is, each number should be taken into consideration the number of times it occurs in the phone book.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 100) — the number of friends. 

Then follow *n* data blocks that describe each friend's phone books. Each block is presented in the following form: first goes the line that contains integer *s**i* and string *name**i* (0 ≤ *s**i* ≤ 100) — the number of phone numbers in the phone book of the *i*-th friend and the name of the *i*-th friend. The name is a non-empty sequence of uppercase and lowercase Latin letters, containing no more than 20 characters. Next *s**i* lines contain numbers as "XX-XX-XX", where X is arbitrary digits from 0 to 9.

## Output

In the first line print the phrase "If you want to call a taxi, you should call: ". Then print names of all friends whose phone books contain maximal number of taxi phone numbers. 

In the second line print the phrase "If you want to order a pizza, you should call: ". Then print names of all friends who have maximal number of pizza phone numbers. 

In the third line print the phrase "If you want to go to a cafe with a wonderful girl, you should call: ". Then print names of all friends who have maximal number of girls' phone numbers. 

Print the names in the order in which they are given in the input data. Separate two consecutive names with a comma and a space. Each line should end with exactly one point. For clarifications concerning the output form, see sample tests. It is necessary that you follow the output form strictly. Extra spaces are not allowed.

## Examples

## Input


```
4  
2 Fedorov  
22-22-22  
98-76-54  
3 Melnikov  
75-19-09  
23-45-67  
99-99-98  
7 Rogulenko  
22-22-22  
11-11-11  
33-33-33  
44-44-44  
55-55-55  
66-66-66  
95-43-21  
3 Kaluzhin  
11-11-11  
99-99-99  
98-65-32  

```
## Output


```
If you want to call a taxi, you should call: Rogulenko.  
If you want to order a pizza, you should call: Fedorov, Rogulenko, Kaluzhin.  
If you want to go to a cafe with a wonderful girl, you should call: Melnikov.  

```
## Input


```
3  
5 Gleb  
66-66-66  
55-55-55  
01-01-01  
65-43-21  
12-34-56  
3 Serega  
55-55-55  
87-65-43  
65-55-21  
5 Melnik  
12-42-12  
87-73-01  
36-04-12  
88-12-22  
82-11-43  

```
## Output


```
If you want to call a taxi, you should call: Gleb.  
If you want to order a pizza, you should call: Gleb, Serega.  
If you want to go to a cafe with a wonderful girl, you should call: Melnik.  

```
## Input


```
3  
3 Kulczynski  
22-22-22  
65-43-21  
98-12-00  
4 Pachocki  
11-11-11  
11-11-11  
11-11-11  
98-76-54  
0 Smietanka  

```
## Output


```
If you want to call a taxi, you should call: Pachocki.  
If you want to order a pizza, you should call: Kulczynski, Pachocki.  
If you want to go to a cafe with a wonderful girl, you should call: Kulczynski.  

```
## Note

In the first sample you are given four friends. Fedorov's phone book contains one taxi number and one pizza delivery number, Melnikov's phone book only has 3 numbers of girls, Rogulenko's one has 6 taxi numbers and one pizza delivery number, Kaluzhin's one contains 2 taxi numbers and one pizza delivery number.

Thus, if you need to order a taxi, you should obviously call Rogulenko, if you need to order a pizza you should call anybody of the following: Rogulenko, Fedorov, Kaluzhin (each of them has one number). Melnikov has maximal number of phone numbers of girls. 



#### tags 

#1200 #implementation #strings 