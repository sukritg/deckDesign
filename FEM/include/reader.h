#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <boost/tokenizer.hpp>
#include <iomanip>

class reader
{
    public:
        reader(std::string _fileName);
        ~reader();
        std::vector<std::string> readLine();
    protected:

    private:
        std::string fileName;
        std::ifstream in;
};

template <typename T>
double toDouble(T dat)
{
    double res;
    std::stringstream ss;
    ss << std::setprecision(3) << dat;
    ss >> std::setprecision(3) >> res;
    ss.clear();
    return res;
}


#endif // READER_H
