#pragma once

#include <QString>


namespace ini
{

class Exception : public std::runtime_error
{

public:
    Exception(const QString &fileName, const QString &error)
        : std::runtime_error{QString{fileName + " :: " + error}.toStdString()}
    {}

};

}
