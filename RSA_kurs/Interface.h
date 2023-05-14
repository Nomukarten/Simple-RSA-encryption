#pragma once
#include <iostream>

#include "KeysGenerator.h"
#include "DataConversion.h"
#include "RSA.h"
#include "RSAWriter.h"



class Interface
{
	public:

		std::vector<std::string> strings_array[2];
		std::vector<std::string> menu_array[2];
		Interface()
		{
			std::vector<std::string> en = {
				"RSA keys were generated", 
				"Enter file name of your encoded message (without .txt): ", 
				"Enter public key file name (without .txt): ",
				"Enter private key file name (without .txt): ",
				"Enter message you want to encode: ",
				"Decoded message: ",
				"Public key was saved as ",
				"Private key was saved as ",
				"Your message was encrypted as ",
				"Error",
				"Error: you entered incorrect values, please try again",
				"Error: file doesn't exist",
				"Error: the file is not a public key file",
				"Error: the file is not a private key file"
			};
			std::vector < std::string> ru = {
				"RSA ����� ���� �������������� ",
				"������� �������� ����� �������������� ��������� (��� .txt):",
				"������� �������� ����� ���������� ����� (��� .txt):",
				"������� �������� ����� ���������� ����� (��� .txt):",
				"������� ���������, ������� ������ �����������:",
				"������������� ���������: ",
				"��������� ���� ��� �������� ��� ",
				"��������� ���� ��� �������� ��� ",
				"���� ��������� ���� ����������� ��� ",
				".txt",
				"������",
				"������: �� ����� ������������ ��������, ���������� �����",
				"������: ���� �� ����������",
				"������: ���� �� �������� ��������� ������",
				"������: ���� �� �������� ��������� ������"
			};
			strings_array[0] = en;
			strings_array[1] = ru;

			std::vector<std::string> ru_m = {
				"1. ������������� ����� RSA",
				"2. ����������� ���������",
				"3. ����������� ���������",
				"4. �����",
				"���������� ������� �����: "
			};
			std::vector<std::string> en_m = {
				"1. Generate RSA keys"
				"2. Encrypt a message",
				"3. Decrypt encoded message",
				"4. Exit ",
				"Please enter task number: "
			};
			menu_array[0] = en_m;
			menu_array[1] = ru_m;
		}
		int language = 0;

		void generateRSAKeys(std::string pub_filename, std::string priv_filename);

		void encrypt_message(std::string message, std::string message_filename, std::string pub_filename);

		void decryptMessage(std::string message_filename, std::string priv_filename);

		bool is_file_exist(std::string fileName);
};



