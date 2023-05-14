#include "RSAWriter.h"

#include <iostream>

PubKey RSAWriter::read_public(std::string filename)
{
	PubKey key;
	key.exp = 0; key.mod = 0;
	std::ifstream input(filename+".txt");
	std::string base;

	std::string temp;
	int is_correct = 0;

	if(input.is_open())
	{
		std::getline(input, temp);
		if (temp != public_header)
			return key;

		while (!input.eof())
		{
			std::getline(input, temp);
			if (temp == public_footer)
			{
				break;
			}
			base += temp;
		}
		base = base64_decode(base);

		std::istringstream num(base);
		num >> key.exp;
		num >> key.mod;
	}
	return key;
}

void RSAWriter::write_public(PubKey pub_key, std::string filename)
{
	std::string key = pub_key.exp.get_str() +" "+ pub_key.mod.get_str();
	unsigned char* byteArr = new unsigned char[key.length()];

	std::memcpy(byteArr, key.data(), key.length());

	std::string output = base64_encode(byteArr, key.length());

	std::ofstream writef(filename+".txt");
	if(writef.is_open())
	{
		writef << public_header<< std::endl;
		std::string sub;
		int last = 0;

		for (size_t i = 0; i < output.size(); i += 64)
		{
			sub = output.substr(i, 64);
			writef << sub << std::endl;
		}
		writef << public_footer << std::endl;
		writef.close();
	}

	delete[] byteArr;
	
}

PrivKey RSAWriter::read_private(std::string filename)
{
	PrivKey key;
	key.exp = 0; key.mod = 0;
	std::ifstream input(filename + ".txt");
	std::string base;

	std::string temp;
	int is_correct = 0;

	if (input.is_open())
	{
		std::getline(input, temp);
		if (temp != private_header)
			return key;

		while (!input.eof())
		{
			std::getline(input, temp);
			if (temp == private_footer)
			{
				break;
			}
			base += temp;
		}
		base = base64_decode(base);

		std::istringstream num(base);
		num >> key.exp;
		num >> key.mod;
	}
	return key;
}

void RSAWriter::write_private(PrivKey priv_key, std::string filename)
{
	std::string key = priv_key.exp.get_str() + " " + priv_key.mod.get_str();

	unsigned char* byteArr = new unsigned char[key.length()];

	std::memcpy(byteArr, key.data(), key.length());

	std::string output = base64_encode(byteArr, key.length());

	std::ofstream writef(filename + ".txt");
	if (writef.is_open())
	{
		writef << private_header << std::endl;
		std::string sub;
		int last = 0;

		for (size_t i = 0; i < output.size(); i += 64)
		{
			sub = output.substr(i, 64);
			writef << sub << std::endl;
		}
		writef << private_footer << std::endl;
		writef.close();
	}

	delete[] byteArr;
}

std::string RSAWriter::read_encoded_message(std::string filename)
{
	std::ifstream input(filename + ".txt");
	std::string base;

	std::string temp;
	int is_correct = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, temp);
			if (temp == "HF45")
			{
				is_correct = 1;
				continue;
			}
			base += temp;
		}
		if(!is_correct)
			base = base64_decode(base);
		
	}
	return base;
}

void RSAWriter::write_encoded_message(std::string encoded_message, std::string filename, int value)
{
	unsigned char* byteArr = new unsigned char[encoded_message.length()];

	std::memcpy(byteArr, encoded_message.data(), encoded_message.length());

	std::string output;
	if (value)
	{
		output = encoded_message;
	}
	else
	{
		output = base64_encode(byteArr, encoded_message.length());
	}

	std::ofstream writef(filename + ".txt");
	if (writef.is_open())
	{
		if (value)
			writef << "HF45" << std::endl;
		std::string sub;
		for (size_t i = 0; i < output.size(); i += 64)
		{
			sub = output.substr(i, 64);
			writef << sub << std::endl;
		}
		writef.close();
	}

	delete[] byteArr;
}

