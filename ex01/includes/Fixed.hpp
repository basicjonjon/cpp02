/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:59:05 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/29 18:02:39 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _rawBits;
    const static int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed(const int value);
    Fixed(const float fValue);
    ~Fixed();
    Fixed& operator=(Fixed const &a);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream &o, Fixed const &fixed);

#endif