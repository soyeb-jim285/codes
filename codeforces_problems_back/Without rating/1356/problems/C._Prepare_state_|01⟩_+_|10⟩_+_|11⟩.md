<h1 style='text-align: center;'> C. Prepare state |01⟩ + |10⟩ + |11⟩</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two qubits in state $|00 \rangle$. Your task is to prepare the following state on them:

$$\frac{1}{\sqrt{3}} \big( |01 \rangle + |10 \rangle + |11 \rangle)$$

This task is very similar to [problem A1 of the Winter 2019 contest](https://codeforces.com/contest/1116/problem/A1), but this time you are not allowed to use any gates except the Pauli gates (X, Y and Z), the Hadamard gate and the controlled versions of those. However, you are allowed to use measurements.

You have to implement an operation which takes an array of 2 qubits as an input and has no output. The "output" of your solution is the state in which it left the input qubits.

Your code should have the following signature:


```
namespace Solution {  
    open Microsoft.Quantum.Intrinsic;  
  
    operation Solve (qs : Qubit[]) : Unit {  
        // your code here  
    }  
}
```


#### tags 

#*special 