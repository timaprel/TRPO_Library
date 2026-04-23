#include <memory>
#include "application/ArendaService.h"
#include "infrastructure/InMemoryArendaRepository.h"

int main() {
auto repository = std::make_shared<InMemoryArendaRepository>();
 // ArendaService arendaService(repository);
 // Mock
return 0;
}