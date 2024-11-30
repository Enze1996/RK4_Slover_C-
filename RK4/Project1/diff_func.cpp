
#include "diff_func.h"

// Example differential equation: d^2y/dt^2 = -y
// Sheet1[0] is y (position), Sheet1[1] is v (velocity)
// Calculate derivatives: dy/dt = v, dv/dt = -y
void diff_func(int i_tic, int i_lgkt, double* datain, double* Sheet1, double* Sheet2)
{
    Sheet2[0] = Sheet1[1];    // dy/dt = v
    Sheet2[1] = -Sheet1[0];   // dv/dt = -y
}