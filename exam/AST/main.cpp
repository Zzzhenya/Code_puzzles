#include <list>
#include <iostream>
#include <string>
#include <typeinfo>

#include "Token.hpp"
#include "Scanner.hpp"



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