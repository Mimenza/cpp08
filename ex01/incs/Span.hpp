/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:14:26 by emimenza          #+#    #+#             */
/*   Updated: 2024/08/12 18:14:26 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

 #include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <limits>

class Span
{
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        std::vector<int> getVector();
        void addNumber(int number);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        int shortestSpan();
        int longestSpan();

        class SpanFullException;
        class NoSpanFoundException;

    private:
        unsigned int maxSize;
        std::vector<int> numbers;
};

#endif