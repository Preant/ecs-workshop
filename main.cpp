/*
** EPITECH PROJECT, 2021
** hub
** File description:
** main.cpp
*/

#include <vector>
#include <memory>
#include <exception>
#include <iostream>

#include "EntityManager.hpp"
#include "CanShoot.hpp"

enum Color {
    BLANC,
    ROUGE,
    VERT,
    VIOLET,
    BLEU,
    DEBUGCOLOR
};

void log(const std::string &&message, Color color)
{

    switch (color)
    {
    case BLANC:
        std::cout << "\033[1;37m";
        break;
    case VERT:
        std::cout << "\033[1;32m";
        break;
    case ROUGE:
        std::cout << "\033[1;31m";
        break;
    case VIOLET:
        std::cout << "\033[1;35m";
        break;
    case BLEU:
        std::cout << "\033[1;34m";
        break;
    case DEBUGCOLOR:
        std::cout << "\033[1;36m";
    }
    std::cout << message << std::endl;

    std::cout << "\033[1;37m";
};

bool TremoveEntity(void)
{
    log("\n\t\tTest07:removeEntity", VIOLET);

    ecs::EM em = std::make_shared<ecs::EntityManager>();
    auto pair = *(em->create());
    size_t id = pair.second->getEnttId();
    em->status();
    log("removing Entt...", DEBUGCOLOR);
    em->remove(id);
    em->status();
    if (em->isIdGiven(id)) {
        log("remove failed", ROUGE);
    }
    log("remove succeed", VERT);
    return (true);
}

bool TaddCmpttoEmptyEntity(void)
{
    log("\n\t\tTest03:addCmpttoEmptyEntity", VIOLET);

    ecs::EM em = std::make_shared<ecs::EntityManager>();
    auto pair = *(em->create());
    ecs::Cmpt shoot = std::make_shared<ecs::CanShoot>();
    em->addComponent(pair.first, shoot);

    em->status();
    if (pair.second->getBehaviour().size() != 1) {
        log("addCmpt failed", ROUGE);
        return (false);
    }
    log("addCmpt succeed", VERT);
    return (true);
}

bool TcreateEmptyEntity(void)
{
    log("\n\t\tTest02:createEmptyEntity", VIOLET);

    ecs::EM em = std::make_shared<ecs::EntityManager>();
    ecs::Entt entt = (*(em->create())).second;
    if (!entt) {
        log("Empty entity not created", ROUGE);
        return (false);
    }
    em->status();
    log("Empty entity created", VERT);
    return (true);
}

bool TcreateSingleCmpt(void)
{
    log("\n\t\tTest01:createSingleCmpt", VIOLET);

    void *shoot = nullptr;
    /*to fill: create a ecs::Cmpt shoot that refers to an instance of CanShoot component */
    if (!shoot) {
        log("CanShoot not created", ROUGE);
        return (false);
    }
    log("CanShoot created", VERT);
    return (true);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "missing parameters" << std::endl;
        return (84);
    }
    int part = atoi(av[1]);
    try {
        std::vector<bool> results;

        try {
            if (part >= 1) {
                results.push_back(TcreateSingleCmpt());
            }
        } catch (Exception &except) {
            std::cerr << except.What() << std::endl;
        }
        try {
            if (part >= 2) {
                results.push_back(TcreateEmptyEntity());
            }
        } catch (Exception &except) {
            std::cerr << except.What() << std::endl;
        }
        try {
            if (part >= 3) {
                results.push_back(TaddCmpttoEmptyEntity());
            }
        } catch (Exception &except) {
            std::cerr << except.What() << std::endl;
        }
        try {
            if (part >= 4) {
                results.push_back(TremoveEntity());
            }
        } catch (Exception &except) {
            std::cerr << except.What() << std::endl;
        }

        if (std::find(results.begin(), results.end(), false) != results.end()) {
            throw Exception("one or several tests has failed");
        }
        
        log("\n\tTESTS SUCCEED", VERT);
        return (0);
    } catch (Exception &except) {
        std::cerr << except.What() << std::endl;
        log("\n\tTESTS FAILED", ROUGE);
        return (84);
    }
}