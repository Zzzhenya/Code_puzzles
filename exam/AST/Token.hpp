#ifndef TOKEN_HPP
# define TOKEN_HPP

enum e_type
{
    LEFT_PAREN,
    RIGHT_PAREN,
    ADD,
    MULTI,
    NUM,
    EOL,
    EO,
};

class Token
{
    public:
        Token(e_type name, char val):_type(name), _val(val) {};
        
        e_type      _type;
        char        _val;
};

#endif
