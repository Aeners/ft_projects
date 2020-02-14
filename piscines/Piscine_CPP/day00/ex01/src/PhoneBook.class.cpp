#include <iostream>
#include <iomanip>

#include "../includes/PhoneBook.class.hpp"

PhoneBook::PhoneBook( void ) : _i( 0 ) {
    return;
}

PhoneBook::~PhoneBook( void ) {
    return;
}
/**
 * ADD CONTACT RELATED
 **/
void    PhoneBook::_setContact( void ) {
    std::cout << "First name: ";
    std::getline(std::cin, this->_firstName[this->_i]);
    std::cout << "Last name: ";
    std::getline(std::cin, this->_lastName[this->_i]);
    std::cout << "Nickname: ";
    std::getline(std::cin, this->_nickname[this->_i]);
    std::cout << "Postal address: ";
    std::getline(std::cin, this->_postalAddress[this->_i]);
    std::cout << "Email address: ";
    std::getline(std::cin, this->_emailAddress[this->_i]);
    std::cout << "Phone number: ";
    std::getline(std::cin, this->_phoneNumber[this->_i]);
    std::cout << "Birthday date: ";
    std::getline(std::cin, this->_birthdayDate[this->_i]);
    std::cout << "Favorite meal: ";
    std::getline(std::cin, this->_favoriteMeal[this->_i]);
    std::cout << "Underwear color: ";
    std::getline(std::cin, this->_underwearColor[this->_i]);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, this->_darkestSecret[this->_i]);
}

void    PhoneBook::_shrinkValues( std::string *v ) {
    int         len = (*v).length();
    if (len > 10) {
        (*v).erase(9, len - 9);
        (*v).push_back('.');
    }
}

/**
 * SEARCH CONTACT RELATED
 **/
void    PhoneBook::_showAllContact( void ) const {
    int         i = 0;
    std::cout << this->_i << std::endl;

    while (i < this->_i) {
        if (i == 0) {
            std::cout << "\x1B[2J\x1B[H";
            std::cout << std::setw(10) << "index" << "|";
            std::cout << std::setw(10) << "first name" << "|";
            std::cout << std::setw(10) << "last name" << "|";
            std::cout << std::setw(10) << "nickname" << "|" << std::endl;
        }
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << this->_firstName[i] << "|";
        std::cout << std::setw(10) << this->_lastName[i] << "|";
        std::cout << std::setw(10) << this->_nickname[i] << "|" << std::endl;
        i++;
    }
}

void    PhoneBook::_showContact( int index ) const {
    std::cout << "\x1B[2J\x1B[H";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << "|";  
    std::cout << std::setw(10) << "postal ad." << "|";
    std::cout << std::setw(10) << "email add." << "|";
    std::cout << std::setw(10) << "phone num." << "|";
    std::cout << std::setw(10) << "birthday ." << "|";
    std::cout << std::setw(10) << "favorite ." << "|";
    std::cout << std::setw(10) << "underwear." << "|";
    std::cout << std::setw(10) << "darkest s." << std::endl;
    std::cout << std::setw(10) << this->_firstName[index] << "|";
    std::cout << std::setw(10) << this->_lastName[index] << "|";
    std::cout << std::setw(10) << this->_nickname[index] << "|";
    std::cout << std::setw(10) << this->_postalAddress[index] << "|";
    std::cout << std::setw(10) << this->_emailAddress[index] << "|";
    std::cout << std::setw(10) << this->_phoneNumber[index] << "|";
    std::cout << std::setw(10) << this->_birthdayDate[index] << "|";
    std::cout << std::setw(10) << this->_favoriteMeal[index] << "|";
    std::cout << std::setw(10) << this->_underwearColor[index] << "|";
    std::cout << std::setw(10) << this->_darkestSecret[index] << std::endl;
}

bool    PhoneBook::_contactController( void ) const {
    this->_showAllContact();
    int indexDesired;
    int tries = 0;
    std::cout << "Index desired ?:";
    while (!(std::cin >> indexDesired) || indexDesired > this->_i || indexDesired < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (++tries == 3) {
            return false;
        }
        std::cout << "Invalid input.  Try again: ";
    }
    this->_showContact(indexDesired);
    return true;
}

bool    PhoneBook::getContact( void ) {
    if (this->_i < 0)
        return false;
    return this->_contactController();
}


bool    PhoneBook::add( void ) {
    if (this->_i < MAX_LENGTH_BOOK)
    {
        this->_setContact();
        this->_shrinkValues(&this->_firstName[this->_i]);
        this->_shrinkValues(&this->_lastName[this->_i]);
        this->_shrinkValues(&this->_nickname[this->_i]);
        this->_shrinkValues(&this->_postalAddress[this->_i]);
        this->_shrinkValues(&this->_emailAddress[this->_i]);
        this->_shrinkValues(&this->_phoneNumber[this->_i]);
        this->_shrinkValues(&this->_birthdayDate[this->_i]);
        this->_shrinkValues(&this->_favoriteMeal[this->_i]);
        this->_shrinkValues(&this->_underwearColor[this->_i]);
        this->_shrinkValues(&this->_darkestSecret[this->_i]);
        NEWLINE();
        this->_i++;
        return true;
    } else {
        std::cout << MAX_LENGTH_BOOK << " contacts already inserted" << std::endl;
        return false;
    }
}