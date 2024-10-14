/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperko <sperko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:20:11 by absalah           #+#    #+#             */
/*   Updated: 2024/10/14 03:16:57 by sperko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) 
{
    if (ac != 2) 
    {
        std::cerr << "Usage: " << av[0] << " <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}