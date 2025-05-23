#include "ini_storage.h"

#include "ini_exception.hpp"
#include "ini_file.h"


namespace ini
{

SectionsMap Storage::load(const QString &fileName)
{
    try
    {
        return File{fileName, File::Read}.read();
    }
    catch (const Exception &)
    {
        throw;
    }
}

SettingsMap Storage::load(const QString &fileName, const QString &sectionName)
{
    try
    {
        return File{fileName, File::Read}.read(sectionName);
    }
    catch (const Exception &)
    {
        throw;
    }
}

void Storage::save(const QString &fileName, const SectionsMap &sections)
{
    try
    {
        File{fileName, File::Create}.write(sections);
    }
    catch (const Exception &)
    {
        throw;
    }
}

void Storage::save(
    const QString &fileName,
    const QString &sectionName,
    const SettingsMap &settings
)
{
    try
    {
        File{fileName, File::Create}.write(sectionName, settings);
    }
    catch (const Exception &)
    {
        throw;
    }
}

}
