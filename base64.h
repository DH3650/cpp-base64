//
//  base64 encoding and decoding with C++.
//  Version: 1.02.00
//

#ifndef CPP_BASE64_H
#define CPP_BASE64_H

#include <string>
#include <vector>

std::string base64_encode(unsigned char const* buf, unsigned int len);
std::vector<unsigned char> base64_decode(std::string const& s);

#endif /* CPP_BASE64_H */
