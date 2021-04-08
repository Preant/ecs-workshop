/*
** EPITECH PROJECT, 2021
** hub
** File description:
** EntityManager.hpp
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <unordered_map>
#include <iostream>
#include <iterator>
#include <memory>

#include "Exception.hpp"
#include "Entity.hpp"

namespace ecs {
    class EntityManager: public std::enable_shared_from_this<EntityManager> {
        public:
            EntityManager();
            ~EntityManager();

            std::unordered_map<size_t, Entt>::iterator create(void);
            bool remove(size_t id);
            bool addComponent(size_t id, Cmpt cmpt);

            size_t getLastId(void) const;
            size_t getNewId(void);
            bool isIdGiven(size_t id) const;
            Entt getEntt(size_t id);
            std::unordered_map<size_t, Entt> getAllEntt(void);

            void status(void) const;
        private:
            std::unordered_map<size_t, Entt> _objects;
            size_t _lastId;
    };
}

#endif /* !ENTITYMANAGER_HPP_ */
