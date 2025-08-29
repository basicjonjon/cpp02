/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:59:36 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/29 18:04:52 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = copy._rawBits;
}

Fixed::Fixed(const int value)
{
    this->_rawBits = value * (1 << this->_fractionalBits);
}

Fixed::Fixed(const float fValue)
{
    this->_rawBits = roundf(fValue * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = a.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_rawBits / (float)(1 << this->_fractionalBits));
}
int Fixed::toInt(void) const
{
    return (this->_rawBits / (1 << this->_fractionalBits));
}

std::ostream& operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}