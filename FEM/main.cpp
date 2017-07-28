#include "inputFileReader.h"
#include "FEMEngine.h"
#include "mathlib.h"

int main()
{


// Input Data
inputFileReader FE("input.txt");
FE.read();
FE.generateFEModel();

FE.startFEM();




return 0;



}
