#include "inputFileReader.h"

void inputFileReader::generateFEModel()
{
    double length = (NUM_BEAMS-1)*BEAM_CC_SPACING + BEAM_OVR_LENGTH*2;
    node n;
    element e;
    int iD = 1;
    // Node Definition
    if (BEAM_OVR_LENGTH>0)
    {
        n.setID(iD);
        n.setProperty(0,0);
        nodeData.push_back(n);
        iD++;
        n.setID(iD);
        n.setProperty(BEAM_OVR_LENGTH,0);
        nodeData.push_back(n);
        iD++;

        for (int i=1; i<=NUM_BEAMS-1;i++)
        {
            n.setID(iD); iD++;
            n.setProperty(BEAM_OVR_LENGTH+BEAM_CC_SPACING*i,0);
            nodeData.push_back(n);
        }
        n.setID(iD);
        n.setProperty(length,0);
        nodeData.push_back(n);
    }
    else
    {
        for (int i=1; i<=NUM_BEAMS-1;i++)
        {
            n.setID(iD); iD++;
            n.setProperty(BEAM_OVR_LENGTH+BEAM_CC_SPACING*i,0);
            nodeData.push_back(n);
        }
    }
    // Section Definition
    // Expecting 1 section property
    section s;
    s.setID(1);
    std::vector<double> values;
    values.push_back( Area); values.push_back(Inertia);
    s.setProperty(values);
    values.clear();

    // Material Definition
    // Expecting 1 material property
    material m;
    m.setID(1);
    values.push_back(1820*sqrt(PERM_STRESS_C));

    // Element Definition
    node SN, EN;
    std::vector<node> nData;

    for (unsigned int i = 0; i <nodeData.size()-1; i++)
    {
        SN = nodeData[i]; EN = nodeData[i+1];
        nData.push_back(SN); nData.push_back(EN);
        e.setID(i+1);
        e.setProperty(nData,m,s);
        elementData.push_back(e);
        nData.clear();
    }


    // Boundary Definition

    // Load Definition

// Display Input Summary
std::cout << "========================="<< std::endl;
std::cout << "NODE SUMMARY" << std::endl;
std::cout << "========================="<< std::endl;
std::cout <<std::left << std::setw(5) <<"ID" <<std::setw(10) <<"X" << std::setw(10)<< "Y" << std::endl;
std::cout << " -------------------------"<< std::endl;
   for (unsigned int i=0; i<nodeData.size();i++)
        nodeData[i].displayProperty();

std::cout << "========================="<< std::endl;
std::cout << "ELEMENT SUMMARY" << std::endl;
std::cout << "========================="<< std::endl;
std::cout <<std::left << std::setw(5) <<"ID" <<std::setw(10) <<"SN" << std::setw(10)<< "EN" << std::endl;
std::cout << " -------------------------"<< std::endl;
    for (unsigned int i=0; i<elementData.size();i++)
        elementData[i].displayProperty();



}
