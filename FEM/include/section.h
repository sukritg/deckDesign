#pragma once
#include <vector>

class section
{
    private:
    int sectionID;
    double Ax,Iz;

    public:
    void setProperty(std::vector<double> &data)
    {
        Ax = data[0];
        Iz = data[1];
    }

    std::vector<double> getProperty()
    {
        std::vector<double> data;
        data.push_back(Ax);
        data.push_back(Iz);
        return data;

    }

    int getID()
    {
        return sectionID;
    }

    void setID(int id)
    {
        sectionID = id;
    }
};
