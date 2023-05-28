# 多维向量装箱问题模拟系统

本仓库为毕业设计的代码仓库，主要用于模拟多维向量装箱问题的模拟系统。

## 编译步骤

以下步骤在Ubuntu 22.04.2 LTS下测试通过。

### 1. 安装必要的软件和依赖库Eigen-3.4.0

```bash
$ sudo apt update
$ sudo apt install cmake build-essential
$ https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
$ tar -xvf eigen-3.4.0.tar.gz
```

### 2. 编译

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make -j 8
```

## 如何运行

编译将会产生三个可执行文件：

1. `BinPackingFFD`：主文件，直接运行将会自动执行全部的流程，包括生成测试用例、执行测试用例、输出测试结果。
2. `BinPackingFFD_single`：单个测试用例的执行文件，运行后需要手动在终端输入测试用例，格式请参照毕业论文。
3. `BinPackingFFD_case_generator`：单纯用来生成测试样例，可以将生成的文件作为输入给`BinPackingFFD_single`。

此外，`test/`下还有一系列的单元测试程序，用于测试本项目中各模块的正确性。因为涉及到随机数生成，它们大多数为
手动测试，即打印出结果然后人工检查是否合理。

## 运行流程

**以下流程可以通过在`build/`下使用一个命令自动化运行**：
  
```bash
$ make run
```

### 1. 生成测试用例

本仓库一共有三种测试用例生成器，分别是：
1. `RandomGenerator`：随机生成器，可以生成任意维度的测试用例，但是测试用例的维度和数量需要手动指定。其生成
的物体在各维度上是独立的。
2. `RandomGeneratorNegRel`：随机生成器，但是生成的物体在各维度上有一个-0.7的相关系数。
3. `RandomSplitGenerator`：随机分割生成器，将一个单位桶随机分成随机数量的物体，每个维度上都是独立的。该
生成器将会带有最优解。

测试用例按照`[生成器算法]-[维数]-case.txt`的格式保存到各自的文件中，例如`RandomGenerator-3-case.txt`将会保存
三维随机生成的测试用例。每个测试用例的格式如下：
  
  ```
  [维数] [物体数量] [最优解 | 仅在RandomSplitGenerator中存在]
  [物体1的向量]
  [物体2的向量]
  ...
  [物体n的体积]
  ```

每个测试用例文件中会含有多个测试用例，一般是5个，每个测试用例的物体数量不同。

### 2. 执行测试用例

测试结果将保存在`[生成器名称]-[维数].txt`中。
对于每一个测试用例，我们首先在第一行写入测试用例包含的物体个数，从第二行开始，
我们按照`[算法名称]#[解]#[求解时间]`保存一个算法的输出结果。我们将测试以下
五种算法：

1. First Fit
2. First Fit Decreasing Item-Centric by Product
3. First Fit Decreasing Item-Centric by Average Sum
4. First Fit Decreasing Bin-Centric by Dot Product
5. First Fit Decreasing Bin-Centric by Norm2

### 3. 可视化结果

在执行完`BinPackingFFD`后，我们便有了全部执行结果的日志。接下来我们可以通过Python脚本来可视化结果：

```bash
$ cd ../
$ python3 plot.py
```

该步骤将在`build/`下为每一个测试结果文件生成一个同名的`.png`文件，用于可视化结果。
