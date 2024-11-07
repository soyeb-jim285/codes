# https:_codeforces.com_blog_entry_60319

*(text courtesy of my colleague Chris Granade)*

A quantum oracle *O* is a "black box" operation that is used as input to another algorithm. Often, such operations are defined using a classical function *f*: {0, 1}*n* → {0, 1}*m* which takes *n*-bit binary input and produces an *m*-bit binary output. To do so, consider a particular binary input *x* = (*x*0, *x*1, ..., *x**n* - 1). We can label qubit states as ![](images/fccd3f6ba1b53d1643bdaef4ff239e0511e1fab7.png).

We may first attempt to define *O* so that ![](images/f1baed3f79a34385e2e34c5c69adebc008db6eb7.png), but this has a couple problems. First, *f* may have a different size of input and output (*n* ≠ *m*), such that applying *O* would change the number of qubits in the register. Second, even if *n* = *m*, the function may not be invertible: if *f*(*x*) = *f*(*y*) for some *x* ≠ *y*, then ![](images/b190005299578b5cd70f0435fe3205ac36cec5b3.png) but ![](images/9875277db259ddf327923a1752ca0934a3f931e0.png). This means we won't be able to construct the adjoint operation ![](images/d316aa4c1f080fec52fbe6ccd1157e6fdd6afdd6.png), and oracles have to have an adjoint defined for them.

We can deal with both of these problems by introducing a second register of *m* qubits to hold our answer. Then we will define the effect of the oracle on all computational basis states: for all ![](images/8b244dbe5630e70199a06f4d4c7d310425ceb36d.png) and ![](images/bc2579c75acc978ee47889c24219c2a359e13a53.png), O(|x⟩⊗|y⟩)=|x⟩⊗|y⊕f(x)⟩. Now ![](images/3f0375238be2302ab8eb4a9bc35ad291f81a9ee5.png) by construction, thus we have resolved both of the earlier problems.

Importantly, defining an oracle this way for each computational basis state ![](images/0a59a86d798c0c8a2982d72e673326073493cf05.png) also defines how *O* acts for any other state. This follows immediately from the fact that *O*, like all quantum operations, is linear in the state that it acts on. Consider the Hadamard operation, for instance, which is defined by ![](images/8808baaf34ef4192e6cb9f2d0c5ea5d517e22bd8.png) and ![](images/6b944cf44b9b747596c5ebb54f0f6dbf90c0d55f.png). If we wish to know how *H* acts on ![](images/891b1e75c93e44f237b7fde497062f8e85c1d952.png), we can use that *H* is linear:

H|+⟩=12–√H(|0⟩+|1⟩)=12–√(H|0⟩+H|1⟩)=12–√(|+⟩+|−⟩)=|0⟩

In the case of defining our oracle *O*, we can similarly use that any state ![](images/a2b41145e9f49aa274a587b2f9d65cc9e1009d74.png) on *n* + *m* qubits can be written as

 ![](images/b78f9c6aac7843b838afffd6f3214c6a182d5a82.png)Thus, the effect of the oracle *O* on this state is 

 ![](images/83bfaa69ac9bf9e5e621a4824b478c820ed49e7c.png)