#include "ini_file.h"

#include "ini_exception.hpp"

#include <QFileInfo>
#include <QSettings>


namespace ini
{

File::File(const QString &name, Modes modes)
    : settings_{nullptr}
{
    if (!QFileInfo{}.exists(name) && !modes.testFlag(Create))
        throw Exception{name, "Ini-file does not exist"};

    settings_ = std::make_unique<QSettings>(name, QSettings::IniFormat);
}

File::~File() {}

SectionsMap File::read() const
{
    SectionsMap sectionsMap;

    for (const auto &group : settings_->childGroups())
        sectionsMap[group] = read(group);

    return sectionsMap;
}

SettingsMap File::read(const QString &sectionName) const
{
    SettingsMap settingsMap;

    settings_->beginGroup(sectionName);
    if (settings_->childKeys().empty())
        throw Exception(settings_->fileName(), "There is not section " + sectionName);

    for (const auto &key : settings_->childKeys())
        settingsMap[key] = settings_->value(key, QVariant(0));
    settings_->endGroup();

    return settingsMap;
}

void File::write(const SectionsMap &sectionsMap)
{
    for (const auto &section : sectionsMap)
        write(sectionsMap.key(section), section);
}

void File::write(const QString &sectionName, const SettingsMap &settingsMap)
{
    settings_->beginGroup(sectionName);

    const auto keys = settingsMap.keys();
    for (const auto &key : keys)
        settings_->setValue(key, settingsMap[key]);

    settings_->endGroup();
}

}
