/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:59:36 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/30 00:26:56 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
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
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &a)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = a.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
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

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}

bool Fixed::operator>(Fixed const &a) const
{
    return ((this->toFloat() > a.toFloat()) ? this : &a);
}

bool Fixed::operator>=(Fixed const &a) const
{
    return ((this->toFloat() >= a.toFloat()) ? this : &a);
}

bool Fixed::operator<(Fixed const &a) const
{
    return ((this->toFloat() < a.toFloat()) ? this : &a);
}

bool Fixed::operator<=(Fixed const &a) const
{
    return ((this->toFloat() <= a.toFloat()) ? this : &a);
}

bool Fixed::operator==(Fixed const &a) const
{
    return ((this->toFloat() == a.toFloat()) ? this : &a);
}

bool Fixed::operator!=(Fixed const &a) const
{
    return ((this->toFloat() != a.toFloat()) ? this : &a);
}

Fixed Fixed::operator+(Fixed const &a)
{
    Fixed result;
    result.setRawBits(this->_rawBits + a._rawBits);
    return (result);
}

Fixed Fixed::operator-(Fixed const &a)
{
    Fixed result;
    result.setRawBits(this->_rawBits - a._rawBits);
    return (result);
}
    

Fixed Fixed::operator*(Fixed const &a)
{
    Fixed result;
    result.setRawBits((this->getRawBits() * a.getRawBits()) >> this->_fractionalBits);
    return (result);
}

Fixed Fixed::operator/(Fixed const &a)
{
    Fixed result;
    result.setRawBits((this->getRawBits() / a.getRawBits()) << this->_fractionalBits);
    return (result);
}

Fixed Fixed::operator++()
{
    this->_rawBits += (1 << this->_fractionalBits);
    return (*this);
}

Fixed Fixed::operator--()
{
    this->_rawBits -= (1 << this->_fractionalBits);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_rawBits += (1 << this->_fractionalBits);
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_rawBits -= (1 << this->_fractionalBits);
    return (temp);
}

Fixed &Fixed::min(Fixed &first, Fixed &sec)
{
    return ((first < sec) ? first : sec);
}

const Fixed &Fixed::min(Fixed const &first, Fixed const &sec)
{
    return ((first < sec) ? first : sec);
}

Fixed &Fixed::max(Fixed &first, Fixed &sec)
{
    return ((first > sec) ? first : sec);
}

const Fixed &Fixed::max(Fixed const &first, Fixed const &sec)
{
    return ((first > sec) ? first : sec);
}