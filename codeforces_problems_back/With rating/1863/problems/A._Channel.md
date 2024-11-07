<h1 style='text-align: center;'> A. Channel</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya is an administrator of a channel in one of the messengers. A total of $n$ people are subscribed to his channel, and Petya is not considered a subscriber.

Petya has published a new post on the channel. At the moment of the publication, there were $a$ subscribers online. We assume that every subscriber always reads all posts in the channel if they are online.

After this, Petya starts monitoring the number of subscribers online. He consecutively receives $q$ notifications of the form "a subscriber went offline" or "a subscriber went online". Petya does not know which exact subscriber goes online or offline. It is guaranteed that such a sequence of notifications could have indeed been received.

Petya wonders if all of his subscribers have read the new post. Help him by determining one of the following: 

* it is impossible that all $n$ subscribers have read the post;
* it is possible that all $n$ subscribers have read the post;
* it is guaranteed that all $n$ subscribers have read the post.
## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains three integers $n$, $a$, and $q$ ($1 \le n \le 100$, $0 \le a \le n$, $1 \le q \le 100$) — the number of subscribers of the channel, the initial number of subscribers online, and the number of notifications.

The second line of each test case contains a string of length $q$, consisting of characters '+' and '-'. The $i$-th of these characters is '+', if the $i$-th notification tells that a subscriber goes online, and it is '-' otherwise.

## Output

For each test case, output a single line: "YES" if all $n$ subscribers are guaranteed to have read the post, "NO" if it is impossible for all $n$ subscribers to have read the post, and "MAYBE" otherwise.

## Example

## Input


```

45 5 3--+5 2 3++-5 4 2-+5 0 7++++-++
```
## Output


```

YES
NO
MAYBE
YES

```
## Note

In the first test case, there are $5$ out of $5$ subscribers online in the very beginning, so they will all read the post no matter what. The answer is "YES".

In the second test case, the number of subscribers online becomes $4$ after the first two notifications, next someone goes offline, and thus the fifth subscriber has no chance of reading the post. It is impossible for all the subscribers to read the post, so the answer is "NO".

In the third test case, on the one hand, the same person may have gone offline and online (in this case only $4$ out of $5$ subscribers have read the post), on the other hand, the last notification may have told that the fifth subscriber has gone online (in this case all subscribers have read the post). We cannot deduce which of the two holds, so the answer is "MAYBE".

In the fourth test case, there have to be five subscribers online after all the notifications. All of them will read the post, so the answer is "YES".



#### tags 

#800 #greedy #implementation 