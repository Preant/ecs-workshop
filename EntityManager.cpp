/*
** EPITECH PROJECT, 2021
** hub
** File description:
** EntityManager.cpp
*/

#include "EntityManager.hpp"

ecs::EntityManager::EntityManager(): _lastId(0)
{
}

ecs::EntityManager::~EntityManager()
{
}

std::unordered_map<size_t, ecs::Entt>::iterator
ecs::EntityManager::create(void)
{
    /*to fill: create an ecs::Entt and add it to the map _objects. don't forget to return an iterator on the pair with the id as key*/
    size_t id = 0;
    if (this->_objects.size() == 0) {
        throw Exception("error while creating a new entity.");
    }
    return (this->_objects.find(id));
}

bool 
ecs::EntityManager::remove(size_t id)
{
    (void)id;
    /*to fill: remove the entity with the given id of the map of entity. Care to check before is the id exists. return true if succeed or false if failed*/
    return (true);
}

bool
ecs::EntityManager::addComponent(size_t id, Cmpt cmpt)
{
    if (!this->isIdGiven(id)) {
        return (false);
    }
    this->_objects[id]->addBehaviour(cmpt);
    return (true);
}

size_t
ecs::EntityManager::getLastId(void) const
{
    return (this->_lastId);
}

size_t
ecs::EntityManager::getNewId(void)
{
    return (this->_lastId++);
}

bool
ecs::EntityManager::isIdGiven(size_t id) const {
    return (this->_objects.find(id) != this->_objects.end());
}

ecs::Entt
ecs::EntityManager::getEntt(size_t id)
{
    if (!this->isIdGiven(id)) {
        throw Exception("ECS: EntityManager.cpp getEntt: Requested Id isn't related to any Entity");
    }
    return (this->_objects[id]);
}

std::unordered_map<size_t, ecs::Entt>
ecs::EntityManager::getAllEntt(void)
{
    return (this->_objects);
}

void
ecs::EntityManager::status(void) const
{
    std::cout << "\033[1;39m";
    std::cout << "-------------STATUS ECS-----------------" << std::endl;

    for (auto const &[key, value]: this->_objects) {
        std::cout << "id: " << key << ", Entt: " << "common entity" << ", Cmpt: ";
        for (auto const behaviour: value->getBehaviour()) {
            std::cout << behaviour->stringifyMe() << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------END STATUS-----------------" << std::endl;
    std::cout << "\033[1;37m";
}