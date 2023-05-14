#pragma once
#include "KeysGenerator.h"
#include "DataConversion.h"
#include <sstream>
#include <fstream>



const std::string public_header = "-----BEGIN RSA PUBLIC KEY-----";
const std::string public_footer = "-----END RSA PUBLIC KEY-----";
const std::string private_header = "-----BEGIN RSA PRIVATE KEY-----";
const std::string private_footer = "-----END RSA PRIVATE KEY-----";

static class RSAWriter
{
	public:
		static PubKey read_public(std::string filename);
		static void write_public(PubKey pub_key, std::string filename);
		static PrivKey read_private(std::string filename);
		static void write_private(PrivKey priv_key, std::string filename);

		static std::string read_encoded_message(std::string filename);
		static void write_encoded_message(std::string encoded_message,std::string filename, int value);
	
};

