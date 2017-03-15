///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: ODBC.hpp
///
/// Author: $author$
///   Date: 3/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_ODBC_ODBC_HPP
#define _QUERA_DB_ODBC_ODBC_HPP

#include "nadir/platform/platform_build.h"

#if defined(WINDOWS)
#include "quera/base/Base.hpp"
#endif // defined(WINDOWS)

#include <sql.h>
#include <sqlext.h>

#if !defined(WINDOWS)
#define BOOL QUERA_BOOL
#define WCHAR QUERA_WCHAR
#define ULONG QUERA_ULONG
#define PWSTR QUERA_PWSTR
#define PCWSTR QUERA_PCWSTR
#define LPWSTR QUERA_LPWSTR
#define LPCWSTR QUERA_LPCWSTR
#include "quera/base/Base.hpp"
#undef BOOL
#undef WCHAR
#undef ULONG
#undef PWSTR
#undef PCWSTR
#undef LPWSTR
#undef LPCWSTR
#endif // !defined(WINDOWS)

namespace quera {
namespace db {
namespace odbc {

typedef nadir::charst<SQLCHAR> SQLCHARS;
typedef nadir::arrayt<SQLCHAR> SQLCHARArray;

} // namespace odbc 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_ODBC_HPP 
