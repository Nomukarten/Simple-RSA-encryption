#pragma once
#include <gmpxx.h>
#include <string>
#include <vector>

typedef std::vector<uint8_t> octet_string;
typedef unsigned char BYTE;

static inline bool is_base64(unsigned char c);
std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);
std::string base64_decode(std::string const& encoded_string);

octet_string toOctetString(const std::string str);
std::string toNormalString(const octet_string str);
mpz_class OS2IP(const octet_string os);
octet_string I2OSP(const mpz_class n, size_t length);

bool isASCII(const std::string& s);