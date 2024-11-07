<h1 style='text-align: center;'> I. Deutsch-Jozsa algorithm</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a quantum oracle - an operation on *N* + 1 qubits which implements a function ![](images/ca923da5e61e139eb5596a3b9e34cc7ef42d1433.png). You are guaranteed that the function *f* implemented by the oracle is either constant (returns 0 on all inputs or 1 on all inputs) or balanced (returns 0 on exactly one half of the input domain and 1 on the other half).

There are only two possible constant functions: *f*(*x*) = 0 and *f*(*x*) = 1. The functions implemented by oracles in the two previous problems (*f*(*x*) = *x**k* and ![](images/601fd91df91c2fbae106d1ddc30f35b042b484e0.png)) are examples of balanced functions.

Your task is to figure out whether the function given by the oracle is constant. Your code is allowed to call the given oracle only once.

## Input

You have to implement an operation which takes the following inputs:

* an integer *N* - the number of qubits in the oracle input,
* an oracle *Uf*, implemented as an operation with signature ((Qubit[], Qubit) => ()), i.e., an operation which takes as input an array of qubits and an output qubit and has no output.

The return of your operation is a Boolean value: true if the oracle implements a constant function and false otherwise.

Your code should have the following signature:


```text
namespace Solution {  
    open Microsoft.Quantum.Primitive;  
    open Microsoft.Quantum.Canon;  
  
    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool  
    {  
        body  
        {  
            // your code here  
        }  
    }  
}
```


#### Tags 

#1700 #NOT OK #*special 

## Blogs
- [All Contest Problems](../Microsoft_Q_Coding_Contest_-_Summer_2018_-_Warmup.md)
- [Contest Anouncement (en)](../blogs/Contest_Anouncement_(en).md)
- [https://codeforces.com/blog/entry/60319](../blogs/https:_codeforces.com_blog_entry_60319.md)
