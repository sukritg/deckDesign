#include "reader.h"

reader::reader(std::string _fileName)
{
    //ctor
    fileName = _fileName;
    in.open(fileName);
    if (!in.good()) {std::cout<<"Error accessing input file"<<std::endl;}
}

reader::~reader()
{
    //dtor
    in.close();
}

std::vector<std::string> reader::readLine()
{
    std::vector<std::string> tokens;
    std::string str;
    bool flag = true;
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    boost::char_separator<char> sep{"\t "};

    while (flag)
    {
        if (!std::getline(in,str))
        {
        tokens.push_back("END");
        std::cout<<"END"<<std::endl;
        return tokens;
        }
        tokenizer tok{str, sep};
        for (const auto &t : tok)
        {
            if (t=="//") {break;};
            tokens.push_back(t);
            flag = false;
        }
    }
    return tokens;
}
