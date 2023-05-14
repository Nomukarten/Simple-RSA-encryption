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
				"RSA ключи были сгенерированны ",
				"Введите название файла зашифрованного сообщения (без .txt):",
				"Введите название файла публичного ключа (без .txt):",
				"Введите название файла приватного ключа (без .txt):",
				"Введите сообщение, которое хотите зашифровать:",
				"Дешифрованное сообщение: ",
				"Публичный ключ был сохранен как ",
				"Приватный ключ был сохранен как ",
				"Ваше сообщение было зашифровано как ",
				".txt",
				"Ошибка",
				"Ошибка: вы ввели неправильные значения, попробуйте снова",
				"Ошибка: файл не существует",
				"Ошибка: файл не является публичным ключем",
				"Ошибка: файл не является приватным ключем"
			};
			strings_array[0] = en;
			strings_array[1] = ru;

			std::vector<std::string> ru_m = {
				"1. Сгенерировать ключи RSA",
				"2. Зашифровать сообщение",
				"3. Дешифровать сообщение",
				"4. Выход",
				"Пожалуйста введите номер: "
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



