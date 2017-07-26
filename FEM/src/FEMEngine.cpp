#include "FEMEngine.h"

FEMEngine::  FEMEngine(const std::vector<node> &_nodalData,
              const std::vector<element> &_elementData,
              const std::vector<material> &_materialData,
              const std::vector<section> &_sectionData,
              const std::vector<bConditions> &_bcData,
              const std::vector<load> &_loadData,
              const std::vector<lCombination> &_loadComboData)
              {
                    nodalData = _nodalData;
                    elementData = _elementData;
                    materialData = _materialData;
                    sectionData = _sectionData;
                    bcData = _bcData;
                    loadData = _loadData;
                    loadComboData = _loadComboData;

              }

FEMEngine::~FEMEngine()
{

}

