#include <iostream>
#include "quadratic.h"
#include <math.h>
#include <conio.h>

using std::cout;
using std::cin;
int CQuadraticFunction::ComputeRoots()
{
    if(coeff[0] == 0)
    {
        isQuadratic = false;
        numRoots = -1;
        return numRoots;
    }
    else if(coeff[1] * coeff[1] < 4 * coeff[0] * coeff[2])
    {
        hasRealRoots = false;
        numRoots = 0;
        return numRoots;
    }
    else if(coeff[1] * coeff[1] == 4 * coeff[0] * coeff[2])
    {
        isQuadratic = true;
        hasRealRoots = true;
        root1 = (-1 * coeff[1]) / (2 * coeff[0] * coeff[2]);
        numRoots = 1;
        return numRoots;
    }
    else
    {
        isQuadratic = true;
        hasRealRoots = true;
        int a = coeff[0];
        int b = coeff[1];
        int c = coeff[2];
        root1 = (-1.0f * coeff[1] + sqrt(coeff[1] * coeff[1] - 4.0f * coeff[0] * coeff[2])) / (2.0f * coeff[0]);
        root2 = (-1 * coeff[1] - sqrt(coeff[1] * coeff[1] - 4 * coeff[0] * coeff[2])) / (2 * coeff[0]);
        numRoots = 2;
        return numRoots;
    }
}

void CQuadraticFunction::PrintRoots()
{
    if(numRoots < 0 || !isQuadratic)
    {
        cout << "This is not a quadratic function";
    }
    else if(numRoots == 0 || !hasRealRoots)
    {
        cout << "This quadratic has imaginary roots";
    }
    else if(numRoots == 1)
    {
        cout << "This quadratic has root " << root1 << " with multiplicity 2";
    }
    else if(numRoots == 2)
    {
        cout << "The roots of this quadratic are " << root1 << " and " << root2;
    }
}

char* PrintCoeff(int root1, int root2)
{
    cout << 1 << " " << -1 * root1 - root2 << " " << root1 * root2 << "\n";
    return 0;
}

int main(int argc, char* argv[])
{
    PrintCoeff(5, 8);
    CQuadraticFunction quad;
    cout << "Please input the coefficients A, B, and C separated with spaces: ";
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    quad.coeff[0] = a;
    quad.coeff[1] = b;
    quad.coeff[2] = c;
    quad.ComputeRoots();
    quad.PrintRoots();
    getch();
    return 0;
}