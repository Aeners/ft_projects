#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# define MAX_LENGTH_BOOK 8
# define PRINT(x) std::cout << x << std::endl
# define NEWLINE() std::cout << std::endl

# include <string>

class PhoneBook {

    private:
        int             _i;
        std::string     _firstName[MAX_LENGTH_BOOK];
        std::string     _lastName[MAX_LENGTH_BOOK];
        std::string     _nickname[MAX_LENGTH_BOOK];
        std::string     _postalAddress[MAX_LENGTH_BOOK];
        std::string     _emailAddress[MAX_LENGTH_BOOK];
        std::string     _phoneNumber[MAX_LENGTH_BOOK];
        std::string     _birthdayDate[MAX_LENGTH_BOOK];
        std::string     _favoriteMeal[MAX_LENGTH_BOOK];
        std::string     _underwearColor[MAX_LENGTH_BOOK];
        std::string     _darkestSecret[MAX_LENGTH_BOOK];

        void            _setContact( void );
        void            _shrinkValues( std::string * );
        bool            _contactController( void ) const;
        void            _showAllContact( void ) const;
        void            _showContact( int ) const;

      public: 

        PhoneBook( void );
        ~PhoneBook( void );

        bool        add( void );
        bool        getContact( void );

};

#endif