#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/String/String.h"


namespace ToyUtility
{


// Path to file or directory
//
// FilePath uses a unified format for storing paths that can be used consistently on every
// platform, using only '/' as a separator.
class FilePath
{
public:
    FilePath();

    // Copy constructor
    FilePath(const FilePath& filePath);

    // Move constructor
    FilePath(FilePath&& filePath);

    FilePath(const String& path);

    FilePath(String&& path);

    FilePath(const char* path);

    // Copy assignment operator
    FilePath& operator=(const FilePath& rhs);

    // Move assignment operator
    FilePath& operator=(FilePath&& rhs);

    const String& Path() const;
    void SetPath(const String& path);
    void SetPath(String&& path);
    void SetPath(const char* path);
    
    String ToNative() const;

    // Check if path is empty
    bool IsEmpty() const;

    /**
    *  @brief
    *    Check if path points to the contents of a directory or container
    *
    *  @return
    *    'true' if it points to the contents, else 'false'
    *
    *  @remarks
    *    A path can either end with a filename (e.g., '/path/to/dir'),
    *    or with a separator (e.g., '/path/to/dir/'). For files, there
    *    is no difference in both. For directories however, it is
    *    assumed that a path that ends with a separator points to the
    *    contents of the directory rather than the directory itself.
    *    The same may be true for containers, such as archive files.
    *    This function can therefore be used to determine if the path
    *    ends with a separator, yet it makes no difference between
    *    files and directories (as it can operate only on the string).
    */
    bool PointsToContent() const;

    /**
    *  @brief
    *    Get full path
    *
    *  @return
    *    Full path in unified format, but without a trailing separator
    *
    *  @remarks
    *    If you want trailing separators to remain in the string, use path().
    *    Calling this function triggers a full analysis of the path (costly operation).
    */
    const String& FullPath() const;

    /**
    *  @brief
    *    Get file name
    *
    *  @return
    *    File name of the stored path (with extension)
    *
    *  @remarks
    *    This function returns "something.ex" for both "/path/to/something.ex" and
    *    "/path/to/something.ex/".
    *    Calling this function triggers a full analysis of the path (costly operation).
    */
    const String& FileName() const;


    /**
    *  @brief
    *    Get base name
    *
    *  @return
    *    Base name of the stored path (without extension)
    *
    *  @remarks
    *    This function returns "something" for both "/path/to/something.ex" and
    *    "/path/to/something.ex/".
    */
    const String& BaseName() const;

    /**
    *  @brief
    *    Get file extension
    *
    *  @return
    *    Extension of the stored path
    *
    *  @remarks
    *    This function returns ".ex" for both "/path/to/something.ex" and
    *    "/path/to/something.ex/". If the path has no extension, an empty
    *    string is returned.
    */
    const String & Extension() const;

    /**
    *  @brief
    *    Get directory path
    *
    *  @return
    *    Path to the directory, with trailing slashes
    *
    *  @remarks
    *    This function returns "/path/to/" as directory path for both
    *    "/path/to/directory" and "/path/to/directory/".
    *    Calling this function triggers a full analysis of the path (costly operation).
    */
    const String & DirectoryPath() const;

    /**
    *  @brief
    *    Get drive letter
    *
    *  @return
    *    Drive letter of the path on Windows (e.g., "C:").
    *
    *  @remarks
    *    If there is no drive letter (Linux, Mac), an empty string is returned.
    *    Calling this function triggers a full analysis of the path (costly operation).
    */
    const String & DriveLetter() const;

    /**
    *  @brief
    *    Check if path is absolute
    *
    *  @return
    *    'true' if path is absolute, else 'false'
    */
    bool IsAbsolute() const;

    /**
    *  @brief
    *    Check if path is relative
    *
    *  @return
    *    'true' if path is relative, else 'false'
    */
    bool IsRelative() const;

    /**
    *  @brief
    *    Resolve relative path from this path
    *
    *  @param[in] relativePath
    *    Path
    *
    *  @return
    *    Combined path
    *
    *  @remarks
    *    This function applies the specified path to the
    *    current path of this object. It uses the following
    *    rules:
    *    - If path is absolute, path is returned
    *    - If path is relative, it is appended to this path
    *    - If path ends with a separator, the new path also will
    *    - Trailing separators of this path are not preserved when adding path
    */
    FilePath Resolve(const FilePath & relativePath) const;

    /**
    *  @brief
    *    Resolve path (removed '.' and '..' entries if possible)
    *
    *  @param[in] path
    *    Path
    *
    *  @return
    *    Resolved path
    *
    *  @remarks
    *    This function resolves occurences of '.' and '..', taking into
    *    account the root path, e.g.:
    *      'a/b/../c' -> 'a/c'
    *      '../../a' -> '../../a'
    *      'a/../../b' -> '../b'
    *      '/a/../b/' - '/b'
    *      etc.
    */
    String Resolved() const;


private:
    /**
    *  @brief
    *    Analyze path and fill in the additional information
    *
    *  @remarks
    *    This function will populate additional information,
    *    such as m_filename, etc. and set m_Analysed to 'true'.
    *    If m_Analysed is already 'true', it returns immediately.
    */
    void _Analyse();


private:
    String m_Path;                  // Path (unified format)
    
    mutable bool m_Analysed;        // 'true' if path details have been analyzed, else 'false'

    mutable bool m_PointsToContent; // 'true' if the path has a trailing separator, else 'false'
    mutable String m_FullPath;      // Full path (without trailing separators)
    mutable String m_FileName;      // Filename component
    mutable String m_BaseName;      // Basename component
    mutable String m_Extension;     // Extension component
    mutable String m_DirectoryPath; // Path to containing directory
    mutable String m_DriveLetter;   // Drive letter component
    mutable bool m_Absolute;        // 'true' if path is absolute, else 'false'
};


} // end of namespace ToyUtility