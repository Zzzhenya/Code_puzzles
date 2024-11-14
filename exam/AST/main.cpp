#include <list>
#include <iostream>
#include <string>
#include <typeinfo>

enum e_type{
    MULTI,
    ADD
};

class Token
{
    public:

    Token(e_type name, char val):_type(name), _val(val) {};
    char    _val;
    e_type _type;
};

class Scanner
{
    public:
        Scanner(char *str)
        {
            if (!str)
            {
                std::cout << "Empty string" << std::endl;
                return;
            }
            _str = std::string(str);
            std::cout << "Constructor" << std::endl;
        };
        ~Scanner(void){};
        std::list<Token> scanTokens(void)
        {
            for (
                std::string::iterator it = _str.begin();
                it != _str.end();
                it++
            )
            {
                _tokens.push_back(Token(ADD,*it));
            }
            return (_tokens);
        };
        void    printTokens(void)
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
        };
        
    private:
        std::list<Token>    _tokens;
        std::string         _str;

};

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    Scanner *scanner = new Scanner(argv[1]);
    std::list<Token> tokens = scanner->scanTokens();
    scanner->printTokens();
    delete scanner;
    return (0);
}