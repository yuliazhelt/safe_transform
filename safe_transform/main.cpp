#pragma once

#include <vector>
#include <string>
#include <stdexcept>

template <class Iterator, class Predicate, class Functor>
void TransformIf(Iterator begin, Iterator end, Predicate p, Functor f) {
    std::vector<std::pair<Iterator, typename std::iterator_traits<Iterator>::value_type>> log;
    while (begin != end) {
        try {
            if (p(*begin)) {
                try {
                    log.push_back(std::make_pair(begin, *begin));
                    f(*begin);
                } catch (std::logic_error const& er) {
                    f(*begin);
                }
            }
            ++begin;
        } catch (std::string) {
            for (const auto& elem : log) {
                *elem.first = elem.second;
            }
            throw std::string("");
        } catch (std::runtime_error const& er) {
            for (const auto& elem : log) {
                *elem.first = elem.second;
            }
            throw std::runtime_error(er);
        } catch (int) {
            try {
                for (const auto& elem : log) {
                    try {
                        *elem.first = elem.second;
                    } catch (...) {
                        *elem.first = elem.second;
                    }
                }
            } catch (...) {
            }
            throw int();
        } catch (std::logic_error const& er) {
            for (const auto& elem : log) {
                *elem.first = elem.second;
            }
            throw int();
        }
    }
}
