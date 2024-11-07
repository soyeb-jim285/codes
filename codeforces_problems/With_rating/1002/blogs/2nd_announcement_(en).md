# 2nd_announcement_(en)

Microsoft's Quantum Team and Codeforces are excited to invite you to Microsoft Q
# Coding Contest — Summer 2018!

The contest will run **from July 6 — 9** and will consist of increasingly challenging tasks on introductory topics in quantum computing: superposition, measurement, oracles and simple algorithms. The top 50 ranked participants will receive a Microsoft Quantum T-shirt!

As a reminder, last weekend we help a warmup round with easier tasks which covered the same topics. The results were quite impressive: 167 participants solved all tasks! You can see the tasks [here](//codeforces.com/contest/1001), and the solutions with explanations [here](https://assets.codeforces.com/rounds/997-998/warmup-editorial.pdf).

Several useful reminders:

 * The contest is unrated.
* Solutions are accepted in Q
# only.
* Participants are ranked according to the number of correctly solved tasks, with penalty time as a tiebreaker.
* The tasks are grouped by topic, and the tasks within one topic are ordered in approximate order of increasing difficulty. If you find a problem too hard, don't forget to check the next problems in this topic and problems from different topics, they might turn out to be easier.
* Unlike the warmup round, you're not allowed to discuss the tasks during the contest.
* By popular demand, we have added Custom Invocation to allow you to run Q
# code on Codeforces servers. Here is the signature of the code you should use to run it (note that the namespace and operation name have to match this code exactly):

 
```cpp
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    // ------------- Operation which is called from C
# -------------------
    operation RunQsharp () : Bool
    {
        body
        {
            Message("Hi");
            return true;
        }
    }
}
```
 * For tasks which require you to create a certain quantum state or to implement a unitary transformation, any kind of error gives verdict "Wrong Answer". For tasks which have classical return, I tried to differentiate verdicts "Wrong Answer" (your return value was incorrect) and "Runtime Error" (array index out of bounds, qubits released are not in zero state, oracle called too many times etc.).
* NO PURCHASE NECESSARY. Must be 16 years of age or older. Game ends 7/9/18. For details, see [Official Rules](https://assets.codeforces.com/rounds/997-998/microsofot-quantum-summer-2018-qs-coding-contest-official-rules.pdf).

You can find the discussion of the warmup round and pointers to Q#/quantum computing materials [here](//codeforces.com/blog/entry/60209).

For first time Codeforces users:

 1. Create user account [here](//codeforces.com/register).
2. Register for the contest [here](//codeforces.com/contestRegistration/1002).
3. Once the contest starts on July 6, access the problems [here](//codeforces.com/contest/1002).

Good luck! We hope you enjoy the contest! 

**Update.** The contest is over. [Editorials](https://assets.codeforces.com/rounds/997-998/main-contest-editorial.pdf) are published.

