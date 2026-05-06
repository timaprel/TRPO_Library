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
#include "policy/ArendaPolicy.h"

int main()
{
    try
    {
        auto repository = std::make_shared<InMemoryArendaRepository>();

        auto compositePolicy = std::make_shared<CompositeArendaPolicy>();

        compositePolicy->addPolicy(std::make_shared<AvailabilityPolicy>());
        compositePolicy->addPolicy(std::make_shared<MaxActiveArendasPolicy>());
        compositePolicy->addPolicy(std::make_shared<OverduePolicy>());

        ArendaService service(repository, compositePolicy);

        auto reader = std::make_shared<Person>(1, "Denis Lobov", Email("ldenis@petrsu.ru"));
        reader->addRole(std::make_shared<ReaderRole>());

        std::vector<std::string> authors = {"Эрик Эванс", "Мартин Фаулер", "Вон Вернон"};
        auto book = std::make_shared<Book>("Domain-Driven Design", ISBN("978-5-6040724-9-3"), authors, 2011);
        auto copy = std::make_shared<Copy>(1, book);

        if (copy->isAvailable())
            std::cout << "Copy is available\n";

        auto arenda = service.createArenda(reader, copy);

        if (copy->isAvailable())
            std::cout << "Copy is available\n";
        else
            std::cout << "Copy is not available\n";

        service.closeArenda(arenda);

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