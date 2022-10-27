#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>

namespace DigiPlane::Utils
{
    size_t levenshteinDistance(const char* s, size_t n, const char* t, size_t m)
    {
       ++n; ++m;
       size_t* d = new size_t[n * m]; // allocate memory
       memset(d, 0, sizeof(size_t) * n * m);
       for (size_t i = 1, im = 0; i < m; ++i, ++im) {
          for (size_t j = 1, jn = 0; j < n; ++j, ++jn) {
             if (s[jn] == t[im])
                d[(i * n) + j] = d[((i - 1) * n) + (j - 1)];
             else
                d[(i * n) + j] = std::min(d[(i - 1) * n + j] + 1, // A deletion
                                 std::min(d[i * n + (j - 1)] + 1, // An insertion
                                 d[(i - 1) * n + (j - 1)] + 1));  // A substitution.
          }
       }
       size_t r = d[n * m - 1];
       delete [] d;
       return r;
    }

    
}

#endif // UTILS_HPP