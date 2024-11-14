#include "Scanner.hpp"

Scanner::Scanner(char *str)
{
    if (!str)
    {
        std::cout << "Empty string" << std::endl;
        return;
    }
    _str = std::string(str);
    std::cout << "Constructor" << std::endl;
}

std::list<Token> Scanner::scanTokens(void)
{
    
    // for (
    //     std::string::iterator it = _str.begin();
    //     it != _str.end();
    //     it++
    // )
    // {
    //     (*it).scanToken();
    //     // scanToken(*it);
    //     //_tokens.push_back(Token(ADD,*it));
    // }
    // return (_tokens);
}

void    Scanner::printTokens(void)
{
    for (
        std::list<Token>::iterator it = _tokens.begin();
        it != _tokens.end();
        it++
    )
    {
        switch((*it)._type)
        {
            case(ADD):
                std::cout << "ADD";
                break;
            case(MULTI):
                std::cout << "MULTI";
                break;
        }
        std::cout << " : " << (*it)._val << std::endl; 
    }
}
