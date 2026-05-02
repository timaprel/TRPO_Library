#include "ArendaService.h"
#include "../Domain/Arenda.h"
#include "../Domain/Person.h"
#include "../Domain/Copy.h"
#include <stdexcept>
#include <vector>

class ArendaService {
public:
    explicit ArendaService(std::shared_ptr<ArendaRepository> repository)
        : repository_(repository) {}

    void issueArenda(int personId, int copyId) {
        auto person = std::make_shared<Person>(personId, "Test User", Email("test@example.com"));
        person->addRole(std::make_shared<ReaderRole>());

        // 1. Проверить максимальное количество активных аренд
        int maxActive = person->getMaxActiveArendas();
        if (maxActive <= 0)
            throw std::logic_error("Person has no right to rent books (maxActive = 0)");

        // 2. Подсчитать текущие активные аренды этого человека (храним в сервисе)
        int currentActive = 0;
        for (const auto& a : activeArendas_) {
            if (a->isActive() && a->getPerson()->getId() == personId)
                ++currentActive;
        }
        if (currentActive >= maxActive)
            throw std::logic_error("Person already has maximum number of active rentals");

        // 3. Получить экземпляр книги (упрощённо – создаём новый Copy)
        auto copy = std::make_shared<Copy>(copyId);

        // 4. Создать аренду (конструктор проверит доступность копии, сроки и т.д.)
        auto arenda = std::make_shared<Arenda>(person, copy);

        // 5. Сохранить в репозиторий и в локальный список активных аренд
        repository_->save(arenda);
        activeArendas_.push_back(arenda);
    }

private:
    std::shared_ptr<ArendaRepository> repository_;
    std::vector<std::shared_ptr<Arenda>> activeArendas_;   // храним все аренды, созданные через этот сервис
};