#ifndef QUAD_H
#define QUAD_H

struct CQuadraticFunction
{
    double* coeff = (double*)malloc(3 * sizeof(double));
    double root1;
    double root2;
    bool isQuadratic = false;
    bool hasRealRoots = false;
    int numRoots = -1;
    int ComputeRoots();
    void PrintRoots();
};


#endif