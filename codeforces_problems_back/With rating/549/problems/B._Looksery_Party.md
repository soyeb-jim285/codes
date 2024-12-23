<h1 style='text-align: center;'> B. Looksery Party</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Looksery company, consisting of *n* staff members, is planning another big party. Every employee has his phone number and the phone numbers of his friends in the phone book. Everyone who comes to the party, sends messages to his contacts about how cool it is. At the same time everyone is trying to spend as much time on the fun as possible, so they send messages to everyone without special thinking, moreover, each person even sends a message to himself or herself.

Igor and Max, Looksery developers, started a dispute on how many messages each person gets. Igor indicates *n* numbers, the *i*-th of which indicates how many messages, in his view, the *i*-th employee is going to take. If Igor guesses correctly at least one of these numbers, he wins, otherwise Max wins.

You support Max in this debate, so you need, given the contact lists of the employees, to determine whether there is a situation where Igor loses. Specifically, you need to determine which employees should come to the party, and which should not, so after all the visitors send messages to their contacts, each employee received a number of messages that is different from what Igor stated.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 100) — the number of employees of company Looksery.

Next *n* lines contain the description of the contact lists of the employees. The *i*-th of these lines contains a string of length *n*, consisting of digits zero and one, specifying the contact list of the *i*-th employee. If the *j*-th character of the *i*-th string equals 1, then the *j*-th employee is in the *i*-th employee's contact list, otherwise he isn't. It is guaranteed that the *i*-th character of the *i*-th line is always equal to 1.

The last line contains *n* space-separated integers: *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ *n*), where *a**i* represents the number of messages that the *i*-th employee should get according to Igor.

## Output

In the first line print a single integer *m* — the number of employees who should come to the party so that Igor loses the dispute.

In the second line print *m* space-separated integers — the numbers of these employees in an arbitrary order.

If Igor wins the dispute in any case, print -1.

If there are multiple possible solutions, print any of them.

## Examples

## Input


```
3  
101  
010  
001  
0 1 2  

```
## Output


```
1  
1   

```
## Input


```
1  
1  
1  

```
## Output


```
0  
  

```
## Input


```
4  
1111  
0101  
1110  
0001  
1 0 1 0  

```
## Output


```
4  
1 2 3 4   

```
## Note

In the first sample Igor supposes that the first employee will receive 0 messages. Since he isn't contained in any other contact list he must come to the party in order to receive one message from himself. If he is the only who come to the party then he will receive 1 message, the second employee will receive 0 messages and the third will also receive 1 message. Thereby Igor won't guess any number.

In the second sample if the single employee comes to the party he receives 1 message and Igor wins, so he shouldn't do it.

In the third sample the first employee will receive 2 messages, the second — 3, the third — 2, the fourth — 3.



#### tags 

#2300 #constructive_algorithms #dfs_and_similar #graphs #greedy 