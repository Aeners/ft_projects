#include <iostream>
#include "../includes/PhoneBook.class.hpp"

void    handleReturns( bool ret ) {
    if (ret) {
        PRINT("SUCCESS");
        NEWLINE();
        // std::cout << "SUCCESS" << std::endl;
    } else {
        PRINT("FAIL");
        NEWLINE();
        // std::cout << "FAIL" << std::endl;
    }
}

int     main( void )
{
    PhoneBook   contacts;
    std::string cmd;
    std::string knowCmd[3] = { "ADD", "SEARCH", "EXIT" };

    while(true) {
        PRINT("THE AWESOME PHONEBOOK WAITING FOR YOU !");
        // std::cout << "THE AWESOME PHONEBOOK WAITING FOR YOU !" << std::endl;
        std::getline(std::cin, cmd);
        
        if (!cmd.compare(knowCmd[0])) {
            handleReturns(contacts.add());
        } else {
            if (!cmd.compare(knowCmd[1])) {
                handleReturns(contacts.getContact());
            } else {
                if (!cmd.compare(knowCmd[2])) {
                    PRINT("Good bye, see you soon!");
                    return 0;
                } else {
                    std::cout << "AwesomePhoneBook: illegal option -- " << cmd << std::endl;
                    PRINT("usage: {ADD, SEARCH, EXIT}");
                }
            }
        }
        
    }
    return 0;
}
