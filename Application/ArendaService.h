#pragma once
#include <memory>
#include "../infrastructure/ArendaRepository.h"
class ArendaService {
public:
 explicit
ArendaService(std::shared_ptr<ArendaRepository>
repository);
 void issueArenda(int personId, int copyId);
private:
 std::shared_ptr<ArendaRepository> repository_;
};