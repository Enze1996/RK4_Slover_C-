#include<iostream>
#include "Integrate.h"
#include "diff_func.h"  // 引入微分方程头文件

#include<fstream>
using namespace std;



int main() {
    const int N = 2;  // Two state variables: position (y) and velocity (v)
    const double Ts = 0.01;  // Time step (e.g., 10ms)
    double initial_conditions[2] = { 1.0, 0.0 };  // Initial condition: y(0) = 1.0, v(0) = 0.0

    // Create an Integrater object
    Integrater integrater;
    integrater.Initial(N, Ts, initial_conditions);

    // Array to store the results (state over time)
    const int num_steps = 1000;
    double results[2][num_steps];  // To store y and v at each time step

    // Integrate over time
    for (int i = 0; i < num_steps; i++) {
        // Save the current state to results
        results[0][i] = integrater.Sheet0[0];  // y (position)
        results[1][i] = integrater.Sheet0[1];  // v (velocity)

        // Call the Integrate function to update the state
        //修改了 Integrate 函数的调用，从 initial_conditions 改为 integrater.Sheet0。----- 20241127
        // 这样每次迭代时，Integrate 会使用当前的状态而不是初始条件::

        integrater.Integrate(diff_func, i, integrater.Sheet0);  // Pass Sheet0, which is the current state
    }

    // Output the results (for demonstration, we'll print the first 10 steps)
    for (int i = 0; i < 100; i++) {
        cout << "Step " << i << ": y = " << results[0][i] << ", v = " << results[1][i] << endl;
    }

    // Output the results to a file
    ofstream output_file("results241128.txt");  // 创建一个文件流对象来写入文件
    if (output_file.is_open()) {
        for (int i = 0; i < num_steps; i++) {
            output_file << "Step " << i << ": y = " << results[0][i] << ", v = " << results[1][i] << endl;
        }
        output_file.close();  // 关闭文件流
        cout << "Results have been saved to results hhh.txt" << endl;
    }
    else {
        cout << "Failed to open file for writing." << endl;
    }

    return 0;
}
