/*
** EPITECH PROJECT, 2021
** hub
** File description:
** AComponent.hpp
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <memory>
#include <vector>
#include <unordered_map>

namespace ecs {
    class EntityManager;
    using EM = std::shared_ptr<EntityManager>;
    class Entity;
    using Entt = std::shared_ptr<ecs::Entity>;
    class AComponent;
    using Cmpt = std::shared_ptr<AComponent>;
}

namespace ecs {
    class AComponent {
        public:
            ~AComponent() {};

            virtual const std::string stringifyMe(void) = 0;

        private:
            EM _relatedToEcs;
            size_t _relatedToEntt;
    };
}

#endif /* !ICOMPONENT_HPP_ */
