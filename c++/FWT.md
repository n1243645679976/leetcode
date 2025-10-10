# Fast Walsh Transformation

## Introduction
這個blog是給懂fast walsh transformation (FWT)但沒有很理解他的機制的人。
這些人可能大概知道他是做bit-wise(或digit-wise, dimension-wise)的convolution，也會它的實作，但不知道他運作的機制是什麼的人。
例如比對FFT，FFT變換前的operation加法對應到FFT變換後的乘法，那FWT的operation需要轉換? 還是可以直接套用在兩個domain上?

為了回答這個問題，會先介紹FWT的運作機制，並且我們應用在以下問題：

leetcode 2044: bitwise OR出來最大值的**組合數**。

2020E: 給n個數字與選到機率，選到就加入set S。問f(S)^2的期望值，其中f(S)為S中所有的值做XOR，我們用FWT計算**機率**。

772D: 給n個數字，共2^n個set中，每個set做digit-wise minimum後取**函數G**。

## 運作機制
oi wiki上的介紹有對於$\cup$操作，有:

$FWT[A]_i = \sum_{i \cup j=i} A_j$

$\begin{aligned} F W T[A]_i \cdot F W T[B]_i & =\left(\sum_{i \cup j=i} A_j\right)\left(\sum_{i \cup k-i} B_k\right) \\ & =\sum_{i \cup j=i} \sum_{i \cup k-i} A_j B_k \\ & =\sum_{\substack{i \cup(j \cup k)=i}} A_j B_k \\ & =F W T[C]_i\end{aligned}$

我在這裡先對FWT一般化，將$\cup$, $\Sigma$與add操作做一般化為g和F與f：

$FWT[A]_i = \left(\mathop{F}\limits_{J = \{ j \in \{1, 2, \dots, n\} \mid g(i, j) = \text{true} \}} A_{j}\right) = f( ... , f (f (I, A_{J_1}), A_{J_2}), ... A_{J_{|J|}})$

其中$I$為單位元，即$F(I, A_0) = A_0$，用$\Sigma$來解釋的話，f就是add操作，I就是0，另外我們用g來確認i, j是否符合某個特徵，是的話就放入序列進行f操作，用$\cup$來解釋的話g就是確認$i \cup j = i$。因為FWT本身並沒有定義聚合的順序，因此就算把聚合的順序透過一個permutation $[p_1, p_2, ..., p_{|J|}]$，數值還是會與原本聚合的順序相同$[1,2,...,|J|]$：

$FWT[A]_i  = f( ... , f (f (I, A_{J_{p_1}}), A_{J_{p_2}}), ... A_{J_{p_{|J|}}}) = f( ... , f (f (I, A_{J_1}), A_{J_2}), ... A_{J_{|J|}})$

為了使這個等式成立，若且唯若f需要有交換律和結合律[1]。

我們定義FWT spectrum的操作為g：

$\begin{aligned} F W T[A]_i \cdot F W T[B]_i & =g\left(\left(\mathop{F}\limits_{J = \{ j \in \{1, 2, \dots, n\} \mid g(i, j) = \text{true} \}} A_{j}\right),\left(\mathop{F}\limits_{K = \{ k \in \{1, 2, \dots, n\} \mid g(i, k) = \text{true} \}} B_{k}\right)\right) \end{aligned}$   



[1] 反證法:

假設沒有交換律，f為矩陣乘法, f(f(I, A), B) = AB != f(f(I, B), A) = BA
假設沒有結合律，f為兩者平均，f(f(0, a), b) = a / 4 + b / 2 != f(f(0, b), a) = b / 4 + a / 2
因此需要有交換律與結合律。

若有交換律與結合律代表我們有辦法隨意調整apply f的順序，自然就有$f( ... , f (f (I, A_{J_{p_1}}), A_{J_{p_2}}), ... A_{J_{p_{|J|}}}) = f( ... , f (f (I, A_{J_1}), A_{J_2}), ... A_{J_{|J|}})$