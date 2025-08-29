/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:59:05 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/30 00:17:48 by jle-doua         ###   ########.fr       */
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

    int toInt(void) const;
    float toFloat(void) const;
    static Fixed &min(Fixed &first, Fixed &sec);
    static const Fixed &min(Fixed const &first, Fixed const &sec);
    static Fixed &max(Fixed &first, Fixed &sec);
    static const Fixed &max(Fixed const &first, Fixed const &sec);

    bool operator>(Fixed const &a)const;
    bool operator>=(Fixed const &a)const;
    bool operator<(Fixed const &a)const;
    bool operator<=(Fixed const &a)const;
    bool operator==(Fixed const &a)const;
    bool operator!=(Fixed const &a)const;

    Fixed operator+(Fixed const &a);
    Fixed operator-(Fixed const &a);
    Fixed operator*(Fixed const &a);
    Fixed operator/(Fixed const &a);

    Fixed operator++();
    Fixed operator--();
    Fixed operator++(int);
    Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif