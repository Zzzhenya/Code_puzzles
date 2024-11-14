#ifndef SCANNER_HPP
# define SCANNER_HPP

# include <iostream>
# include <list>
# include "Token.hpp"

class Scanner
{
    public:
        Scanner(char *str);
        ~Scanner(void){};

        std::list<Token>    scanTokens(void);
        void                printTokens(void);
        void                error(int line, std::string message)
        {
            
        }
        
    private:
        std::list<Token>    _tokens;
        std::string         _str;

};

#endif
