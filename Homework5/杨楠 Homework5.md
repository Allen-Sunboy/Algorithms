# Homework5

软件13 杨楠

## 1

为了设计BUCKET-SORT里桶的大小，思路为：将这个单位圆划分成n个面积相等的同心环（包括最里面那个圆）。只需要在单位圆内依次画上半径为 $ \sqrt{\frac{1}{n}}, \sqrt{\frac{2}{n}}, ..., \sqrt{\frac{n-1}{n}} $ 的圆即可。这样，每个同心圆的面积大小依次为 $ \frac{\pi}{n}, \frac{2\pi}{n}, ..., \pi $ ，从而每个同心环的面积相等。伪代码如下。

```python
BUCKET-SORT(P)
    n = P.length
    let B[0..n-1] be a new array
    for i = 0 to n-1
        make B[i] an empty list
    for i = 1 to n
        insert P[i] into list B[floor(sqrt(n * (x[i]^2 + y[i]^2)))]
        //floor()是下取整，sqrt()是平方根
    for i = 0 to n-1
        sort list B[i] with insertion sort
    concatenate the lists B[0], B[1], ..., B[n-1] together in order
```

## 2

获取这k-1个k分位数，存入数组中。思路为：使用递归分治，每层递归中调用SELECT函数，时间是线性 $ \Omicron(n) $ （即为最坏情况），最多递归 $ \lg k $ 层，从而总时间为 $ \Omicron(n\lg k) $ 。K-QUANTILE伪代码如下。

```python

QUANTILE(A, p, r, kp, kr, B, k)
    if p <= r and kp <= kr
        kq = floor((kp + kr) / 2)
        //floor()是下取整
        q = floor(kq * (r - p + 1) / k)
        x = SELECT(A, p, r, q)
        B[kq] = x
        QUANTILE(A, p, q-1, kp, kq-1, B, k)
        QUANTILE(A, q+1, r, kq+1, kr, B, k)


K-QUANTILE(A, n, k)
    let B[1..k-1] be a new array
    QUANTILE(A, 1, n, 1, k-1, B, k)
    return B
```

