#include "inputFileReader.h"
#include "matrix.h"
#include "writer.h"
#include "mathlib.h"
int main()
{


// Input Data
inputFileReader input("input.txt");
input.read();
input.generateFEModel();




//Node Coordinates
matrix x(3,2);
x(1,1) = 0;     x(1,2) = 13;
x(2,1) = 4;     x(2,2) = 10;
x(3,1) = 10;    x(3,2) = 0;
//Element Connectivity
matrix ix(2,2);
ix(1,1) = 1;    ix(1,2) = 2;
ix(2,1) = 2;    ix(2,2) = 3;
//ID array
matrix id(3,3);





writer out("Matrix.txt");

matrix A;
A.setSize(5,5);A.setValue(0.0);
A(1,1) =  3.5120; A(1,2) =  0.7679;
A(2,1) =  0.7679; A(2,2) = 3.1520; A(2,4) =  -2;
A(3,3) = 3.5120; A(3,4) =  -0.7679; A(3,5) =  0.7679;
A(4,2) =  -2; A(4,3) = -0.7679; A(4,4) =  3.1520; A(4,5) = -1.1520;
A(5,3) = 0.7679; A(5,4) =  -1.1520; A(5,5) = 3.1520;



matrix B;
B.setSize(5,1);
B(4,1) =  -0.04;


out.writeMatrix(A,10,false);
out.writeMatrix(B,10,false);
out.writeText("Gauss Elimination Method");
out.writeMatrix(gaussSolve(A,B),10);
out.writeText("Cholesky LLT Method");
out.writeMatrix(choleskySolve(A,B),10);
out.writeText("LU Decomposition Method");
out.writeMatrix(luSolve(A,B),10);



return 0;



}
