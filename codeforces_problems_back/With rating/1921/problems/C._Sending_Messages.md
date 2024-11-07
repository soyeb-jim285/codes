<h1 style='text-align: center;'> C. Sending Messages</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Stepan is a very busy person. Today he needs to send $n$ messages at moments $m_1, m_2, \dots m_n$ ($m_i < m_{i + 1}$). Unfortunately, by the moment $0$, his phone only has $f$ units of charge left. At the moment $0$, the phone is turned on.

The phone loses $a$ units of charge for each unit of time it is on. Also, at any moment, Stepan can turn off the phone and turn it on later. This action consumes $b$ units of energy each time. Consider turning on and off to be instantaneous, so you can turn it on at moment $x$ and send a message at the same moment, and vice versa, send a message at moment $x$ and turn off the phone at the same moment.

If at any point the charge level drops to $0$ (becomes $\le 0$), it is impossible to send a message at that moment.

Since all messages are very important to Stepan, he wants to know if he can send all the messages without the possibility of charging the phone.

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. This is followed by the descriptions of the test cases.

The first line of each test case contains four integers $n$, $f$, $a$, and $b$ ($1 \le n \le 2 \cdot 10^5$, $1 \le f, a, b \le 10^9$) — the number of messages, the initial phone's charge, the charge consumption per unit of time, and the consumption when turned off and on sequentially.

The second line of each test case contains $n$ integers $m_1, m_2, \dots, m_n$ ($1 \le m_i \le 10^9$, $m_i < m_{i + 1}$) — the moments at which messages need to be sent.

It is guaranteed that in a test the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output "YES" if Stepan can send all the messages, and "NO" otherwise.

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

## Example

## Input


```

61 3 1 537 21 1 34 6 10 13 17 20 265 10 1 21 2 3 4 51 1000000000 1000000000 100000000010000000003 11 9 66 8 1012 621526648 2585904 356629951789 61859 71998 73401 247675 298086 606959 663464 735972 806043 806459 919683
```
## Output


```

NO
YES
YES
NO
NO
YES

```
## Note

In the first test case of the example, at moment $0$, the phone's charge is $3$. When sending a message at moment $3$ without turning it off, $(3 - 0) \cdot 1 = 3$ units of charge will be spent. In this case, the charge will drop to $0$ and Stepan will not be able to send the message. When turning off and on, the phone's charge will decrease by $5$, so it will not be possible to send the message in this way.

In the third test case of the example, at moment $0$, the phone's charge is $10$. The phone loses $1$ unit of charge per unit of time, and when turned off and on, it loses $2$ units of charge. To send all messages, the following actions can be taken:

* Turn off the phone at moment $0$ and turn it on at moment $1$, after which $10 - 2 = 8$ units of charge will remain;
* send a message at moment $1$;
* send a message at moment $2$, after which $8 - (2 - 1) \cdot 1 = 7$ units of charge will remain;
* Turn off the phone at moment $2$ and turn it on at moment $3$, after which $7 - 2 = 5$ units of charge will remain;
* send a message at moment $3$;
* Turn off the phone at moment $3$ and turn it on at moment $4$, after which $5 - 2 = 3$ units of charge will remain;
* send a message at moment $4$;
* Turn off the phone at moment $4$ and turn it on at moment $5$, after which $3 - 2 = 1$ unit of charge will remain;
* send a message at moment $5$.

The last (sixth) test set of the example may fail if there is an integer overflow in your solution.



#### tags 

#900 #greedy #math 