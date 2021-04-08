/*
** EPITECH PROJECT, 2021
** hub
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "AComponent.hpp"

namespace ecs {
    class Entity {
        public:
            Entity(size_t id, EM em);
            ~Entity();

            const size_t &getEnttId(void) const;
            const std::vector<Cmpt> &getBehaviour(void) const;

            bool addBehaviour(Cmpt behaviour);
            bool removeBehaviour(Cmpt behaviour);
            ecs::EM getEnttManager(void);

        private:
            size_t _id;
            ecs::EM _relatedToEcs;
            std::vector<Cmpt> _behaviour;
    };
} //namespace ecs

#endif /* !ENTITY_HPP_ */
