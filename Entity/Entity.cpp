/*
** EPITECH PROJECT, 2021
** hub
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

ecs::Entity::Entity(size_t id, EM em): _id(id), _relatedToEcs(em)
{
}

ecs::Entity::~Entity()
{
}

const size_t &
ecs::Entity::getEnttId(void) const
{
    return (this->_id);
}

const std::vector<ecs::Cmpt> &
ecs::Entity::getBehaviour(void) const
{
    return (this->_behaviour);
}

bool
ecs::Entity::addBehaviour(Cmpt behaviour)
{
    (void)behaviour;
    /*to fill: add the Component behaviour to the vector of component and return true if succeed or false if failed*/
    return (true);
}

bool
ecs::Entity::removeBehaviour(Cmpt behaviour)
{
    for (auto it = this->_behaviour.begin(); it != this->_behaviour.end(); it++) {
        if ((*it) == behaviour) {
            this->_behaviour.erase(it);
            return (true);
        }
    }
    return (false);
}

ecs::EM
ecs::Entity::getEnttManager(void)
{
    return (this->_relatedToEcs);
}