#ifndef UTILS_HPP
#define UTILS_HPP

namespace DigiPlane::Utils
{
    // This is a simple function that returns the levenshtein distance between two strings
    // it is used to compare strings and find the closest match
    size_t levenshteinDistance(const char* s, size_t n, const char* t, size_t m);

    
}

#endif // UTILS_HPP