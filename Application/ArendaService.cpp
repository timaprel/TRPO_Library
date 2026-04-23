#include "ArendaService.h"
#include "../Arenda.h"
ArendaService::ArendaService(std::shared_ptr<ArendaRepository> repository) : repository_(repository) {}
void ArendaService::issueArenda(int /*personId*/, int /*copyId*/)
{
    // Реализация сценария выдачи книги
    // Здесь будет: - поиск читателя; - проверка правил
    // - создание Arenda; - сохранение через
    repository_
}
