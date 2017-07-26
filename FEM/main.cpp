#include "inputFileReader.h"
#include "FEMEngine.h"

int main()
{


// Input Data
inputFileReader input("input.txt");
input.read();
input.generateFEModel();



return 0;



}
