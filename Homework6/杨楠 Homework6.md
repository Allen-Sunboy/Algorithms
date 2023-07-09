# Homework6

软件13 杨楠

## 1

修改条件后，设计算法伪代码如下。

```python
BOTTOM-UP-CUT-ROD(p, n)
    let r[0..n] be a new array
    r[0] = 0
    for j = 1 to n
        q = -∞
        for i = 1 to j
            if i != j
                q = max(q, p[i] + r[j-i] - c)
            else
                q = max(q, p[i] + r[j-i])
        r[j] = q
    return r[n]
```

## 2

取反例如下。

设有4个矩阵 $ \langle A_1, A_2, A_3, A_4 \rangle $ ，相对应的 $ p_0, p_1, p_2, p_3, p_4 $ 分别为 $ 100, 20, 30, 40, 100 $ 。

如果按照题目所说的贪心算法，那么第一次划分选定的 $ k = 1 $ ，第二次划分选定的 $ k = 2 $ ，括号化方案为 $ (A_1(A_2 (A_3 A_4))) $ ，所需的标量乘法次数为 $ 30 \times 40 \times 100 + 20 \times 30 \times 100 + 100 \times 20 \times 100 = 380000 $ 。

而按照动态规划的方法，得到的括号化方案为 $ (A_1 ((A_2 A_3) A_4)) $ ，所需乘法次数为 $ 20 \times 30 \times 40 + 20 \times 40 \times 100 + 100 \times 20 \times 100 = 304000 $ ，次数更少。说明这个贪心方法可能生成次优解。
