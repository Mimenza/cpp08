/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:48:34 by emimenza          #+#    #+#             */
/*   Updated: 2024/08/12 18:48:34 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

class Span::SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span is already full";
        }
    };

class Span::NoSpanFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "No span can be found";
        }
    };

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span& other) {
    maxSize = other.maxSize;
    numbers = other.numbers;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (numbers.size() >= maxSize)
    {
        throw SpanFullException();
    }
    numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (numbers.size() + std::distance(begin, end) > maxSize)
    {
        throw SpanFullException();
    }
    numbers.insert(numbers.end(), begin, end);
}


std::vector<int> Span::getVector()
{
    return numbers;
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
    {
        throw NoSpanFoundException();
    }
    int shortest = std::numeric_limits<int>::max();

    std::vector<int> sortedNumbers(numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    for (std::size_t i = 1; i < sortedNumbers.size(); ++i) {
    int span = sortedNumbers[i] - sortedNumbers[i - 1];
    if (span < shortest)
    {
        shortest = span;
    }
    }

    return shortest;
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
    {
        throw NoSpanFoundException();
    }
    int minElement = *std::min_element(numbers.begin(), numbers.end());
    int maxElement = *std::max_element(numbers.begin(), numbers.end());

    return maxElement - minElement;

}

