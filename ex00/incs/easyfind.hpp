/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:48:30 by emimenza          #+#    #+#             */
/*   Updated: 2024/08/12 17:48:30 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP__
#define EASYFIND_HPP__

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <exception>


class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw NotFoundException();

    return it;
}

#endif