/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:18:57 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/12 14:01:20 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );

public:
    using   FuncPtr = void (Harl::*)();
    
    FuncPtr functionsPtr[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    FuncPtr getFuncPtr( std::string level);
    void    complain( std::string level );
    Harl( void );
    ~Harl( void );
};

#endif