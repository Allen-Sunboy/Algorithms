每个cpp都是单独编译运行。

命令行输入make，即可分别编译所有cpp文件。
```shell
make
```

若只需编译某个cpp，则在命令行输入相应的cpp文件名。比如，如果只要编译demo1.cpp，则命令行输入：
```shell
make demo1
```
每个可执行文件都是逐行输出。

对于demo1，demo2，demo3-1，demo4，每一行的第1个数字表示所求的是第几项，第2个数字表示计算该项所用的时间（单位为微秒），第3个数字表示所求得的值（可能溢出）。

对于demo3-2，每一行的第1个数字表示所求的是第几项，第2个数字表示理论值，第3个数字表示实际计算时所求的值，第4个数字表示计算误差（也就是前两个数字的差值）。

demo1是递归法，demo2是递推法，demo3-1是公式法，demo4是矩阵乘法。

每个程序的主函数末尾都写上了：
```cpp
system("pause");
```
这样，单独运行可执行文件，输出完毕后程序会暂停，而不会立即退出。
