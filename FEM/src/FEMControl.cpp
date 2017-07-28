#include "inputFileReader.h"

void inputFileReader::startFEM()
{
    FE.start  (nodeData,
               elementData,
               materialData,
               sectionData,
               bcData,
               loadData,
               lcData);

    FE.createIDMatrix();
    FE.createStiffMatrix();
    FE.createForceMatrix();
    FE.applyBC();
    FE.solve();
    FE.populateNodalResData();
    FE.printNodeTable();
    FE.calcElmForces();
    FE.populateElementResData();
    //FE.printElementTable();
}
