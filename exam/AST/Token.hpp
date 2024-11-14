#ifndef TOKEN_HPP
# define TOKEN_HPP

enum e_type
{
    MULTI,
    ADD
};

class Token
{
    public:
        Token(e_type name, char val):_type(name), _val(val) {};
        
        e_type      _type;
        char        _val;
};

#endif
