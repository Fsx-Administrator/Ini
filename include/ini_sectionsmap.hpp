#pragma once

#include <QMap>
#include <QString>
#include <QVariant>


namespace ini
{

using SettingsMap = QMap<QString, QVariant>;

class SectionsMap : public QMap<QString, SettingsMap>
{

public:
    template<class T>
    [[nodiscard]] inline T get(const QString &sectionName, const QString &valueName) const
    {
        if constexpr (std::is_same_v<T, double>)
            return value(sectionName).value(valueName).toDouble();
        else if constexpr (std::is_same_v<T, float>)
            return value(sectionName).value(valueName).toFloat();
        else if constexpr (std::is_same_v<T, bool>)
            return value(sectionName).value(valueName).toBool();
        else if constexpr (std::is_enum_v<T> || std::is_union_v<T>)
            return static_cast<T>(value(sectionName).value(valueName).toInt());
        else if constexpr (std::is_unsigned_v<T>)
            return value(sectionName).value(valueName).toUInt();
        else if constexpr (std::is_integral_v<T>)
            return value(sectionName).value(valueName).toInt();
    }

    template<class T>
    inline void set(const QString &sectionName, const QString &valueName, const T value)
    {
        this->operator[](sectionName)[valueName] = value;
    }

};


}
