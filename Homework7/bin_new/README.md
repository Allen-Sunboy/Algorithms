# 使用

运行seam_carving.exe程序，输入所需压缩的图片的路径（不带引号），绝对路径或者相对路径均可。

路径本身可以包含空格，因为是通过`getline()`的方式读取一整行路径，不会有影响。

尽量是英文路径。中文路径在自机实测可行，但不排除可能由于编码不同而导致的乱码。

会在该exe相同目录下生成压缩后的图片。

bin文件夹里的demo文件夹，包含了示例图片可以测试。也可自己选用图片。

bin文件夹里包含了运行程序所需的与opencv有关的dll文件。

OpenCV版本是4.5.2，src中的Makefile文件仅作参考，因为不同电脑里的OpenCV版本不同，所在的路径也不同，从而相应的命令行参数有差异。
