/*
** EPITECH PROJECT, 2021
** hub
** File description:
** CanShoot.hpp
*/

#ifndef CANSHOOT_HPP_
#define CANSHOOT_HPP_

#include <string>

#include "AComponent.hpp"

namespace ecs {
    class CanShoot: public AComponent {
        public:
            CanShoot() {};
            ~CanShoot() {};

            const std::string stringifyMe(void)
            {
                return ("CanShoot");
            };
    };
}

#endif /* !CANSHOOT_HPP_ */
