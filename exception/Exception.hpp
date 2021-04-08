/*
** EPITECH PROJECT, 2021
** hub
** File description:
** Exception.hpp
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

/*!
 *  \file Exception.hpp
 *  \brief Exception
 *  \author Paolo Réant--Hamadi
 */

/*! \class Exception
 *  \brief Exception handler class
 */
class Exception: std::exception {
   public:
        /*!
         *  \brief constructor
         *  ctor
         *  \param message : error message to deliver
         */
        Exception(const std::string &message): _message(message) {};
        /*!
         *  \brief destructor
         *  dtor
         */
        ~Exception() {};

        /*!
         *  \brief What function that describes exception
         *  \return error message
         */
        const std::string &What() {
            return (this->_message);
        };
    private:
        std::string _message;

};

#endif /* !EXCEPTION_HPP_ */
