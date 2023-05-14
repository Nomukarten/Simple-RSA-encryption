#include "Interface.h"

void Interface::generateRSAKeys(std::string pub_filename, std::string priv_filename)
{
	PubKey public_key;
	PrivKey private_key;
	KeysGenerator generator;
	generator.generateKeys(public_key, private_key);
	RSAWriter::write_public(public_key, pub_filename);
	RSAWriter::write_private(private_key, priv_filename);
	std::cout << strings_array[language][0]<<std::endl;
	std::cout << strings_array[language][6]<<pub_filename<<".txt" << std::endl;
	std::cout << strings_array[language][7] << priv_filename << ".txt" << std::endl;
}
void Interface::encrypt_message(std::string message, std::string message_filename, std::string pub_filename)
{
	PubKey public_key = RSAWriter::read_public(pub_filename);
	if (public_key.exp == 0 && public_key.mod == 0)
	{
		std::cout << strings_array[language][13] << std::endl;
		return;
	}
	mpz_class intmessage = OS2IP(toOctetString(message));
	mpz_class code = RSA::encrypt(public_key, intmessage);
	int ch = 0;
	if (!isASCII(message))
		ch = 1;
	RSAWriter::write_encoded_message(code.get_str(), message_filename,ch);
	std::cout << strings_array[language][8] << message_filename << ".txt" << std::endl;
}

void Interface::decryptMessage(std::string message_filename, std::string priv_filename)
{
	PrivKey private_key;
	std::string message = RSAWriter::read_encoded_message(message_filename);
	private_key = RSAWriter::read_private(priv_filename);
	if (private_key.exp == 0 && private_key.mod == 0 )
	{
		std::cout << strings_array[language][14] << std::endl;
		return;
	}
	mpz_class encod(message,10);
	mpz_class code = RSA::decrypt(private_key, encod);
	std::cout << strings_array[language][5] << toNormalString(I2OSP(code, 500)) << std::endl;

}

bool Interface::is_file_exist(std::string fileName)
{
	std::ifstream infile(fileName+".txt");
	if (infile.is_open())
	{
		infile.close();
		return true;
	}
	else return false;

}

