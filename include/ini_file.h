#pragma once

#include "ini_sectionsmap.hpp"


class QSettings;

namespace ini
{

class File
{

public:
    enum Mode
    {
        Create = 0x1,
        Read = 0x2,
        Write = 0x4,
        ReadWrite = Read | Write
    };
    Q_DECLARE_FLAGS(Modes, Mode)

    explicit File(const QString &name, Modes modes);
    ~File();

    SectionsMap read() const;
    SettingsMap read(const QString &sectionName) const;
    void write(const SectionsMap &sectionsMap);
    void write(const QString &sectionName, const SettingsMap &settingsMap);

private:
    std::unique_ptr<QSettings> settings_;

};

}
