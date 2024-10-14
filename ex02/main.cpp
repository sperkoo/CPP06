/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:03:29 by absalah           #+#    #+#             */
/*   Updated: 2024/10/15 00:07:07 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"


int main() 
{
    Base* ptr = generate();
    std::cout << "Pointer identification: ";
    identify(ptr);
    std::cout << "Reference identification: ";
    identify(*ptr);
    delete ptr;
    std::cout << std::endl;
    return 0;
}