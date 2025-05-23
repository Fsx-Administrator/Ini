#pragma once

#include "ini_sectionsmap.hpp"


namespace ini
{

class Storage
{

public:
    Storage() noexcept = delete;
    Storage(const Storage &) = delete;
    Storage(Storage &&) = delete;
    ~Storage() = delete;

    Storage& operator=(const Storage &) = delete;
    Storage& operator=(Storage &&) = delete;

    static void save(const QString &fileName, const SectionsMap &sections);
    static void save(const QString &fileName, const QString &sectionName, const SettingsMap &settings);
    [[nodiscard]] static SectionsMap load(const QString &fileName);
    [[nodiscard]] static SettingsMap load(const QString &fileName, const QString &sectionName);

};

}
