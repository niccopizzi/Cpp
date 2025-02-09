/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:56:01 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/09 19:40:56 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Creating a new Phonebook!" << std::endl;
    this->currentIndex = 1;
    this->isEmpty = true;
}

void    PhoneBook::setIsEmpty(bool isEmpty)
{
    this->isEmpty = isEmpty;
}

void    PhoneBook::setIndex(int index)
{
    if (index < 0 || index > 7)
        return;
    this->currentIndex = index;
}
int     PhoneBook::getIndex()
{
    return (this->currentIndex);
}

Contact PhoneBook::getContact(int index)
{
    return (this->Contacts[index]);
}

bool    PhoneBook::getIsEmpty()
{
    return (this->isEmpty);
}