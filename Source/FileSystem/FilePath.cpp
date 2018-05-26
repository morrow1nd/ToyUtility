#include "ToyUtility/FileSystem/FilePath.h"

#include <sstream>
#include <algorithm>
#include <vector>
#include <string>


namespace ToyUtility
{


FilePath::FilePath()
    :
    m_Path(""),
    m_PointsToContent(false),
    m_Analysed(false)
{
}

FilePath::FilePath(const FilePath & filePath)
    :
    m_Path(filePath.m_Path),
    m_PointsToContent(filePath.m_PointsToContent),
    m_Analysed(filePath.m_Analysed),
    m_FullPath(filePath.m_FullPath),
    m_FileName(filePath.m_FileName),
    m_BaseName(filePath.m_BaseName),
    m_Extension(filePath.m_Extension),
    m_DirectoryPath(filePath.m_DirectoryPath),
    m_DriveLetter(filePath.m_DriveLetter),
    m_Absolute(filePath.m_Absolute)
{
}

FilePath::FilePath(FilePath && filePath)
    :
    m_Path(std::move(filePath.m_Path)),
    m_PointsToContent(std::move(filePath.m_PointsToContent)),
    m_Analysed(std::move(filePath.m_Analysed)),
    m_FullPath(std::move(filePath.m_FullPath)),
    m_FileName(std::move(filePath.m_FileName)),
    m_BaseName(std::move(filePath.m_BaseName)),
    m_Extension(std::move(filePath.m_Extension)),
    m_DirectoryPath(std::move(filePath.m_DirectoryPath)),
    m_DriveLetter(std::move(filePath.m_DriveLetter)),
    m_Absolute(std::move(filePath.m_Absolute))
{
}

FilePath::FilePath(const String & path)
    :
    FilePath()
{
    SetPath(path);
}

FilePath::FilePath(String && path)
    :
    m_Path(std::move(path)),
    m_PointsToContent(false),
    m_Analysed(false)
{
    _Analyse();
}

FilePath::FilePath(const char * path)
    :
    FilePath(String(path))
{
}

FilePath & FilePath::operator=(const FilePath & rhs)
{
    m_Path = rhs.m_Path;
    m_PointsToContent = rhs.m_PointsToContent;
    m_Analysed = rhs.m_Analysed;
    m_FullPath = rhs.m_FullPath;
    m_FileName = rhs.m_FileName;
    m_BaseName = rhs.m_BaseName;
    m_Extension = rhs.m_Extension;
    m_DirectoryPath = rhs.m_DirectoryPath;
    m_DriveLetter = rhs.m_DriveLetter;
    m_Absolute = rhs.m_Absolute;

    return *this;
}

FilePath & FilePath::operator=(FilePath && rhs)
{
    m_Path = std::move(rhs.m_Path);
    m_PointsToContent = std::move(rhs.m_PointsToContent);
    m_Analysed = std::move(rhs.m_Analysed);
    m_FullPath = std::move(rhs.m_FullPath);
    m_FileName = std::move(rhs.m_FileName);
    m_BaseName = std::move(rhs.m_BaseName);
    m_Extension = std::move(rhs.m_Extension);
    m_DirectoryPath = std::move(rhs.m_DirectoryPath);
    m_DriveLetter = std::move(rhs.m_DriveLetter);
    m_Absolute = std::move(rhs.m_Absolute);

    return *this;
}

const String & FilePath::Path() const
{
    return m_Path;
}

void FilePath::SetPath(const String & path)
{
    m_Path = path;

    _Analyse();
}

void FilePath::SetPath(String && path)
{
    m_Path = std::move(path);
    
    _Analyse();
}

void FilePath::SetPath(const char * path)
{
    m_Path = String(path);

    _Analyse();
}

String FilePath::ToNative() const
{
    auto path = m_Path; // copy one

    // TODOH
#if defined(SYSTEM_WINDOWS)
    std::replace(path.begin(), path.end(), '/', '\\');
#endif

    return path;
}

bool FilePath::IsEmpty() const
{
    return m_Path.empty();
}

bool FilePath::PointsToContent() const
{
    return m_PointsToContent;
}

const String & FilePath::FullPath() const
{
    return m_FullPath;
}

const String & FilePath::FileName() const
{
    return m_FileName;
}

const String & FilePath::BaseName() const
{
    return m_BaseName;
}

const String & FilePath::Extension() const
{
    return m_Extension;
}

const String & FilePath::DirectoryPath() const
{
    return m_DirectoryPath;
}

const String & FilePath::DriveLetter() const
{
    return m_DriveLetter;
}

bool FilePath::IsAbsolute() const
{
    return m_Absolute;
}

bool FilePath::IsRelative() const
{
    return !m_Absolute;
}

FilePath FilePath::Resolve(const FilePath & relativePath) const
{
    // Return empty path if both paths are empty
    if (relativePath.IsEmpty() && IsEmpty())
    {
        return FilePath();
    }

    // Return input path if it is an absolute path or this path is empty
    if (relativePath.IsAbsolute() || IsEmpty())
    {
        return relativePath;
    }

    // Return this path if input path is empty
    if (relativePath.IsEmpty())
    {
        return *this;
    }

    // Combine paths
    return FilePath(FullPath() + "/" + relativePath.Path());
}

String FilePath::Resolved() const
{
    // Split path into parts
    std::vector<std::string> parts;
    std::stringstream ss(m_Path);

    std::string name;
    while (std::getline(ss, name, '/'))
    {
        parts.push_back(name);
    }

    // Process sub-paths, handling '.' and '..'
    std::vector<std::string> stack;
    size_t removableItems = 0;
    bool absolute = false;

    size_t numParts = parts.size();
    for (size_t i = 0; i < numParts; i++)
    {
        // Get sub-path
        const std::string & path = parts[i];

        // Check if it is the beginning of an absolute path
        if (i == 0 && (path.empty() || (path.length() == 2 && path[1] == ':')))
        {
            absolute = true;
        }

        // Ignore '.'
        if (path == ".")
        {
            continue;
        }

        // Handle '..'
        else if (path == ".." && removableItems > 0)
        {
            stack.pop_back();
            removableItems--;
        }

        // Regular sub-path
        else
        {
            // Add to stack
            stack.push_back(path);

            // Check if sub-path is removable by '..' entries
            if (!(i == 0 && absolute) && path != "..")
            {
                removableItems++;
            }
        }
    }

    // Compose resolved string
    std::string resolved = "";

    for (size_t i = 0; i < stack.size(); i++)
    {
        // Add sub-string
        resolved += stack[i];

        // Add separator, except for the last item (unless it is also the beginning of an absolute path)
        if (i + 1 < stack.size() || (i == 0 && absolute))
            resolved += "/";
    }

    // Return resolved path
    if (resolved.empty()) return ".";
    else                  return resolved;
}

void FilePath::_Analyse() const
{
    // Convert path into unified form
    std::replace(m_Path.begin(), m_Path.end(), '\\', '/');

    // Check if path ends with a delimiter
    auto pos = m_Path.find_last_of('/');
    if (pos == m_Path.size() - 1)
    {
        m_PointsToContent = true;
    }

    // Reset details
    m_FullPath = "";
    m_FileName = "";
    m_BaseName = "";
    m_Extension = "";
    m_DirectoryPath = "";
    m_DriveLetter = "";
    m_Absolute = false;

    // Split path into parts
    std::vector<std::string> parts;
    std::stringstream ss(m_Path);

    std::string name;
    while (std::getline(ss, name, '/'))
    {
        parts.push_back(name);
    }

    // Fix sub-paths
    size_t numParts = parts.size();

    for (size_t i = 0; i < numParts; i++)
    {
        // Get sub-path
        const std::string & path = parts[i];

        // If this is the first path and it is absolute, ensure '/' at the end
        if (i == 0 && (path.empty() || (path.length() == 2 && path[1] == ':')))
        {
            parts[i] += "/";
            m_Absolute = true;
        }

        // For all sub-paths before the filename, ensure '/' at the end
        else if (i < numParts - 1)
        {
            parts[i] += "/";
        }
    }

    // Determine filename
    m_FileName = (numParts > 0) ? parts[numParts - 1] : "";

    // Determine directory path and full path
    m_DirectoryPath = "";

    if (numParts > 1)
    {
        // Path has at least two parts
        for (size_t i = 0; i<numParts - 1; i++)
        {
            m_DirectoryPath += parts[i];
        }

        m_FullPath = m_DirectoryPath + m_FileName;
    }

    else if (numParts == 1 && m_Absolute)
    {
        // Path has only one part and that is absolute
        m_DirectoryPath = parts[0];
        m_FullPath = m_DirectoryPath;
    }

    else if (numParts == 1)
    {
        // Path has one part that is not absolute
        m_FullPath = m_FileName;
    }

    // Determine basename and extension
    size_t pos = m_FileName.find_first_of('.', 1);

    if (m_FileName == "." || m_FileName == ".." || pos == std::string::npos)
    {
        m_BaseName = m_FileName;
        m_Extension = "";
    }

    else
    {
        m_BaseName = m_FileName.substr(0, pos);
        m_Extension = m_FileName.substr(pos);
    }

    // Determine drive letter
    pos = m_FullPath.find_first_of(':');

    m_DriveLetter = pos == 1 ? m_Path.substr(0, pos + 1) : "";

    // Set state
    m_Analysed = true;
}

} // end of namespace ToyUtility