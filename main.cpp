#include <memory>
#include <iostream>
#include <vector>

#include "application/ArendaService.h"
#include "infrastructure/InMemoryArendaRepository.h"
#include "Domain//Email.h"
#include "Domain/Person.h"
#include "Domain/Role.h"
#include "Domain/Book.h"
#include "Domain/Copy.h"
#include "Domain/isbn.h"

int main()
{
    try
    {
        // 1. Создать репозиторий
        auto repository = std::make_shared<InMemoryArendaRepository>();
        // 2. Создать сервис
        ArendaService service(repository);
        // 3. Создать пользователя (читателя)
        auto reader = std::make_shared<Person>(1, "Denis Lobov", Email("ldenis@petrsu.ru"));
        // 4. Задать пользователю роль "Читатель"
        reader->addRole(std::make_shared<ReaderRole>());
        // 5. Создать книгу
        std::vector<std::string> authors = {"Эрик Эванс", "Мартин Фаулер", "Вон Вернон"};
        auto book = std::make_shared<Book>("Domain-Driven Design", ISBN("978-5-6040724-9-3"), authors, 2011);
        // 6. Создать копию книги (инвентарный номер 1)
        auto copy = std::make_shared<Copy>(1, book);
        // 7. Проверить доступность копии до выдачи
        if (copy->isAvailable())
            std::cout << "Copy is available\n";
        else
            std::cout << "Copy is not available\n";
        // 8. Выдать книгу (создать аренду)
        auto arenda = service.createArenda(reader, copy);
        // 9. Проверить доступность после выдачи
        if (copy->isAvailable())
            std::cout << "Copy is available\n";
        else
            std::cout << "Copy is not available\n";
        // 10. Вернуть книгу
        service.closeArenda(arenda);
        // 11. Проверить доступность после возврата
        if (copy->isAvailable())
            std::cout << "Copy returned successfully\n";
        else
            std::cout << "Copy is still not available\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}