#include<stdio.h>
#include<math.h>
float f(float x)
{
    return cos(x) - x*exp(x);
}
void regula (float *x, float x0, float x1, float fx0, float fx1, int *itr)
{
    *x = x0 - ((x1 - x0) / (fx1 - fx0))*fx0;
    ++(*itr);
    printf("Iteration no. %3d X = %7.5f \n", *itr, *x);
}
void main ()
{
    int itr = 0, maxm;
    float x0,x1,x2,x3,err;
    printf("\nEnter the values of x0, x1, allowed error and maximum iterations:\n");
    scanf("%f %f %f %d", &x0, &x1, &err, &maxm);
    regula (&x2, x0, x1, f(x0), f(x1), &itr);
    do
    {
        if (f(x0)*f(x2) < 0)
            x1=x2;
        else
            x0=x2;
        regula (&x3, x0, x1, f(x0), f(x1), &itr);
        if (fabs(x3-x2) < err)
        {
            printf("After %d iterations, root = %6.4f\n", itr, x3);
            return 0;
        }
        x2=x3;
    }
    while (itr<maxm);
    printf("Solution does not converge or iterations not sufficient:\n");
    return 1;
}
