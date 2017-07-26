#pragma once
#ifndef FEMENGINE_H
#define FEMENGINE_H

#include <vector>
#include "node.h"
#include "element.h"
#include "bConditions.h"
#include "load.h"
#include "matrix.h"
#include "material.h"
#include "section.h"
#include "lcombination.h"
#include <iomanip>
#include "mathlib.h"

class FEMEngine
{
public:
    FEMEngine(const std::vector<node> &_nodalData,
              const std::vector<element> &_elementData,
              const std::vector<material> &_materialData,
              const std::vector<section> &_sectionData,
              const std::vector<bConditions> &_bcData,
              const std::vector<load> &_loadData,
              const std::vector<lCombination> &_loadComboData);


    ~FEMEngine();

protected:

private:
         std::vector<node> nodalData;
         std::vector<element> elementData;
         std::vector<material> materialData;
         std::vector<section> sectionData;
         std::vector<bConditions> bcData;
         std::vector<load> loadData;
         std::vector<lCombination> loadComboData;


};
#endif // FEMENGINE_H
