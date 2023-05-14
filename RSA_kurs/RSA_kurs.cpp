// RSA_kurs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <regex>

#include "Interface.h"
#include <windows.h>



int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Interface inter ;
    std::string temp;
    std::cout << "Choose language/ Выберете язык: english - 0, русский - 1";
    std::cout << std::endl;
    bool exit = 0;
    while(true)
    {
        std::getline(std::cin, temp);
        if(temp == "0")
        {
            inter.language = 0;
            break;
        }
        if(temp == "1")
        {
            inter.language = 1;
            break;
        }
        std::cout << inter.strings_array[0][11]<<std::endl;
    }
    while(true)
    {
        std::cout << inter.menu_array[inter.language][0] << std::endl;
        std::cout << inter.menu_array[inter.language][1] << std::endl;
        std::cout << inter.menu_array[inter.language][2] << std::endl;
        std::cout << inter.menu_array[inter.language][3] << std::endl;
        std::cout << std::endl;
        std::cout << inter.menu_array[inter.language][4];
        char n = 0;
        std::cin >> n;
        std::cout << std::endl;
        std::cin.ignore();
        switch (n)
        {
			case '1':
	        {
                std::string pub, priv;
                std::cout << inter.strings_array[inter.language][2];
 
                std::getline(std::cin, temp);
                    if(!std::regex_match(temp, std::regex("^[A-Za-z0-9]+$")))
                    {
                        std::cout << inter.strings_array[inter.language][11] << std::endl;
                        break;
                    }
                pub = temp;
                std::cout << std::endl;

                std::cout << inter.strings_array[inter.language][3];

                std::getline(std::cin, temp);
                if (!std::regex_match(temp, std::regex("^[A-Za-z0-9]+$")))
                {
                    std::cout << inter.strings_array[inter.language][11] << std::endl;
                    break;
                }
                priv = temp;
                std::cout << std::endl;
                inter.generateRSAKeys(pub, priv);
                    std::cout << std::endl;
		        break;
	        }
            case '2':
            {
                std::string pub;
                std::cout << inter.strings_array[inter.language][2];
 
                std::getline(std::cin, temp);
                if (!std::regex_match(temp, std::regex("^[A-Za-z0-9]+$")))
                {
                    std::cout << inter.strings_array[inter.language][11] << std::endl;
                    break;
                }
				if(!inter.is_file_exist(temp))
				{
                    std::cout << inter.strings_array[inter.language][12] << std::endl;
                    break;
				}
                pub = temp;
                std::cout << std::endl;

                std::string message;
                std::cout << inter.strings_array[inter.language][4];

                std::getline(std::cin, temp);
                if (message.length() > 500)
                {
                    std::cout << inter.strings_array[inter.language][11] << std::endl;
                    break;
                }
                message = temp;
                std::cout << std::endl;

                std::string mess;
                std::cout << inter.strings_array[inter.language][1];

                std::getline(std::cin, temp);
                if (!std::regex_match(temp, std::regex("^[A-Za-z0-9]+$")))
                {
                    std::cout << inter.strings_array[inter.language][11] << std::endl;
                    break;
                }
                mess = temp;
                std::cout << std::endl;
                inter.encrypt_message(message, mess, pub);

                break;
            }
            case '3':
            {
                std::string priv;
                std::string mess;
                std::cout << inter.strings_array[inter.language][1];

                std::getline(std::cin, temp);
                if (!std::regex_match(temp, std::regex("^[A-Za-z0-9]+$")))
                {
                    std::cout << inter.strings_array[inter.language][11] << std::endl;
                    break;
                }
                mess = temp;
                std::cout << std::endl;

                std::cout << inter.strings_array[inter.language][3];

                std::getline(std::cin, temp);
                if (!std::regex_match(temp, std::regex("^[A-Za-z0-9]+$")))
                {
                    std::cout << inter.strings_array[inter.language][11] << std::endl;
                    break;
                }
                priv = temp;
                std::cout << std::endl;
                inter.decryptMessage(mess, priv);
                break;
            }
            case '4':
            {
                exit = 1;
                break;
            }
            default: { break; }
        }
        std::cout << std::endl;
        if(exit)
            break;
    }

    std::getline(std::cin, temp);
}
