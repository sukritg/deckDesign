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
    FE.printElementTable();

    int lc = 2;
    int elementID = 4;
    double distance = 0.5;

    std::cout << "====================================================================="<<std::endl;
    std::cout << "Axial force = " << FE.sectionForce(lc,elementID,distance,SFType::AXIAL) << std::endl;
    std::cout << "====================================================================="<<std::endl;

    std::cout << "====================================================================="<<std::endl;
    std::cout << "Shear force = " << FE.sectionForce(lc,elementID,distance,SFType::SHEAR) << std::endl;
    std::cout << "====================================================================="<<std::endl;

    std::cout << "====================================================================="<<std::endl;
    std::cout << "Bending Moment = " << FE.sectionForce(lc,elementID,distance,SFType::MOMENT) << std::endl;
    std::cout << "====================================================================="<<std::endl;

}
