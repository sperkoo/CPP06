/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:01:15 by absalah           #+#    #+#             */
/*   Updated: 2024/10/15 00:01:40 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif