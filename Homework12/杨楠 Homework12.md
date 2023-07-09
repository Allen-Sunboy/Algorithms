# Homework12

软件13 杨楠

## 1

设计算法如下。

```python
GREEDY-SET-COVER(X, F)
    m = max{|S|, S in F}
    let A[0..m] be a new array of lists
    let L[0..|X|] be a new array of lists
    for each S in F
        add S to A[|S|]
        for each x in S
            add S to L[x]
    
    let C be a new set cover
    let U be a new set
    while m > 0
        let S' be any element of A[m]
        add S' to C
        remove S' from A[m]
        for each x in S' \ U
            for each S in L[x]
                remove S from A[|S|]
                |S| = |S| - 1
                add S to A[|S|]
                if A[m] is empty
                    m = m - 1
            add x to U
    return C
```

这里，数组 $A$ 和 $L$ 的每个元素都是一个存放子集的列表，子集族 $C$ 即为所求的集合覆盖。

首先将每个子集 $S$ 放入 $A$ 和 $L$ 相应位置的操作，复杂度为 $\Omicron(\Sigma_{S\in F}{|S|})$ 。然后是选取子集的操作，对于每个 $S$ 中的 $x$ 操作，时间为 $\Omicron(1)$ ，那么一共所需时间也为 $\Omicron(\Sigma_{S\in F}{|S|})$ 。所以算法的总时间为 $\Omicron(\Sigma_{S\in F}{|S|})$ 。

## 2

原算法修改如下。对于列表 $L_i$ 中的每个元素 $s$ ，维护其相对应的集合 $S_s$ ， $S_s$ 是 $S$ 的子集，且 $S_s$ 的元素和即为 $s$ 。

当执行 $MERGE-LISTS(L_{i-1}, L_{i-1}+x_i)$ 操作时，每个 $s$ 变成了 $s+x_i$ ，其对应的 $S_s$ 就加入元素 $x_i$ 。

当执行 $TRIM(L_i, \varepsilon/2n)$ 和 $remove$ 操作时，如果该元素被删除了，那么相应的集合也删除。

最后，返回 $z^*$ 相对应的集合 $S_{z^*}$ 即为所求。

上述添加的操作的时间都是线性的或者单位时间，则算法总的复杂度依然为完全多项式时间。
