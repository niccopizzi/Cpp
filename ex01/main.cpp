/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:29:21 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/09 19:43:41 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.h"

bool    isValidInput(std::string input, int index)
{
    if (input.empty())
    {
        std::cerr << "Error! A Contact cannot have empty variables\n";
        return (false);
    }
    if (index == 2 || index == 3)
        return (true); /*Skip checks for nickname and darkest secret*/
    for(std::string::iterator it = input.begin(); it != input.end(); it++)
    {
        if (*it >= '0' && *it <= '9')
        {
            if (index != 4)
            {
                std::cerr << "Error! A Name cannot have numbers!\n";
                return (false);
            }
        }
        else if (index == 4) //this gets executed if the input is not numbers and we are validating a number
        {
            std::cerr << "Error! A phone number can have only digits!\n";
            return (false);
        }
    }
    return (true);
}

void    handleAddCommand(PhoneBook *newPhoneBook)
{
    const   char    *strings[5] = {"First Name", "Last Name", "Nickname", 
                                            "Darkest Secret", "Phone Number"};
    std::string      userinput[5];
    for (int i = 0; i < 5; ++i)
    {
        do
        {
            std::cout << "Insert " << strings[i] << std::endl;
            std::cout << "> ";
            getline(std::cin , userinput[i]);
            if (std::cin.eof()) 
                break;
            std::cin.clear();
        }   while (!isValidInput(userinput[i], i));
    }
    newPhoneBook->Contacts[newPhoneBook->getIndex()].setContact(userinput[0], userinput[1], userinput[2], userinput[3], userinput[4]);
    newPhoneBook->setIndex(newPhoneBook->getIndex() + 1);
    if (newPhoneBook->getIsEmpty())
        newPhoneBook->setIsEmpty(false);
}

std::string     setOutputString(std::string value)
{
    if (value.length() >= 10)
    {
        value.at(8) = '.';
        return (value.substr(0, 9));
    }
    return (value);
}

void    handleSearchCommand(PhoneBook *newPhoneBook, int index)
{
    std::string     value;
    
    if (newPhoneBook->getIsEmpty())
    {
        std::cout<< "\x1b[34m""\x1b[1m""\tYOU HAVE NO CONTACTS""\x1b[0m"<< std::endl;
        return;
    }
    std::cout<< "\x1b[34m""\x1b[1m""\tLIST OF CONTACTS""\x1b[0m"<< std::endl;
    std::cout << std::setw(10) << "INDEX" << " | ";
    std::cout << std::setw(10) << "FIRST NAM." << " | ";
    std::cout << std::setw(10) << "LAST NAME" << " | ";
    std::cout << std::setw(10) << "NICKNAME" << "\n\n";
    
    for (int i = 1; i < newPhoneBook->getIndex(); ++i)
    {
        std::cout << std::setw(10) << i << " | ";
        value = setOutputString(newPhoneBook->Contacts[i].getFirstName());
        std::cout << std::setw(10) << value << " | ";
        value = setOutputString(newPhoneBook->Contacts[i].getLastName());
        std::cout << std::setw(10) << value << " | ";
        value = setOutputString(newPhoneBook->Contacts[i].getNickname());
        std::cout << std::setw(10) << value << std::endl;
    }
}

int main(void)
{
    std::string input;
    PhoneBook newPhoneBook;
    
    std::cout << "\x1b[34m""\x1b[1m"; //set bold blue color
    std::cout << "\n\tWELCOME TO YOUR PHONE BOOK MY FRIEND!\n";
    std::cout <<  "\x1b[0m"; //reset colors
    std::cout << "\n\t\tWhat would you like to do?\n\n";
    
    do
    {
        std::cout << "Please select one of the following options:\n\n";
        std::cout << "\x1b[1m" "->\t1)ADD\n\n->\t2)SEARCH\n\n->\t3)EXIT\n\n" "\x1b[0m";
        std:: cout << "> ";
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "You inserted EOF - Goodbye!" <<std::endl;
            break;
        } 
        if (input == "ADD")
        {
            handleAddCommand(&newPhoneBook);
        }
        else if (input == "SEARCH")
        {
            handleSearchCommand(&newPhoneBook, 0);   
        }
    } while (input != "EXIT" && std::cin.good());
    return (0);
}