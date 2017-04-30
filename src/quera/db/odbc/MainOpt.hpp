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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 3/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_ODBC_MAINOPT_HPP
#define _QUERA_DB_ODBC_MAINOPT_HPP

#include "quera/db/MainOpt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define QUERA_DB_ODBC_MAIN_CREATE_OPT "create"
#define QUERA_DB_ODBC_MAIN_CREATE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define QUERA_DB_ODBC_MAIN_CREATE_OPTARG_RESULT 0
#define QUERA_DB_ODBC_MAIN_CREATE_OPTARG ""
#define QUERA_DB_ODBC_MAIN_CREATE_OPTUSE ""
#define QUERA_DB_ODBC_MAIN_CREATE_OPTVAL_S "r"
#define QUERA_DB_ODBC_MAIN_CREATE_OPTVAL_C 'r'
#define QUERA_DB_ODBC_MAIN_CREATE_OPTION \
   {QUERA_DB_ODBC_MAIN_CREATE_OPT, \
    QUERA_DB_ODBC_MAIN_CREATE_OPTARG_REQUIRED, \
    QUERA_DB_ODBC_MAIN_CREATE_OPTARG_RESULT, \
    QUERA_DB_ODBC_MAIN_CREATE_OPTVAL_C}, \

#define QUERA_DB_ODBC_MAIN_EXECUTE_OPT "execute"
#define QUERA_DB_ODBC_MAIN_EXECUTE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define QUERA_DB_ODBC_MAIN_EXECUTE_OPTARG_RESULT 0
#define QUERA_DB_ODBC_MAIN_EXECUTE_OPTARG ""
#define QUERA_DB_ODBC_MAIN_EXECUTE_OPTUSE ""
#define QUERA_DB_ODBC_MAIN_EXECUTE_OPTVAL_S "e"
#define QUERA_DB_ODBC_MAIN_EXECUTE_OPTVAL_C 'e'
#define QUERA_DB_ODBC_MAIN_EXECUTE_OPTION \
   {QUERA_DB_ODBC_MAIN_EXECUTE_OPT, \
    QUERA_DB_ODBC_MAIN_EXECUTE_OPTARG_REQUIRED, \
    QUERA_DB_ODBC_MAIN_EXECUTE_OPTARG_RESULT, \
    QUERA_DB_ODBC_MAIN_EXECUTE_OPTVAL_C}, \

#define QUERA_DB_ODBC_MAIN_COLUMNS_OPT "columns"
#define QUERA_DB_ODBC_MAIN_COLUMNS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define QUERA_DB_ODBC_MAIN_COLUMNS_OPTARG_RESULT 0
#define QUERA_DB_ODBC_MAIN_COLUMNS_OPTARG ""
#define QUERA_DB_ODBC_MAIN_COLUMNS_OPTUSE ""
#define QUERA_DB_ODBC_MAIN_COLUMNS_OPTVAL_S "c"
#define QUERA_DB_ODBC_MAIN_COLUMNS_OPTVAL_C 'c'
#define QUERA_DB_ODBC_MAIN_COLUMNS_OPTION \
   {QUERA_DB_ODBC_MAIN_COLUMNS_OPT, \
    QUERA_DB_ODBC_MAIN_COLUMNS_OPTARG_REQUIRED, \
    QUERA_DB_ODBC_MAIN_COLUMNS_OPTARG_RESULT, \
    QUERA_DB_ODBC_MAIN_COLUMNS_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define QUERA_DB_ODBC_MAIN_OPTIONS_CHARS \
   QUERA_DB_ODBC_MAIN_CREATE_OPTVAL_S \
   QUERA_DB_ODBC_MAIN_EXECUTE_OPTVAL_S \
   QUERA_DB_ODBC_MAIN_COLUMNS_OPTVAL_S \
   QUERA_DB_MAIN_OPTIONS_CHARS

#define QUERA_DB_ODBC_MAIN_OPTIONS_OPTIONS \
   QUERA_DB_ODBC_MAIN_CREATE_OPTION \
   QUERA_DB_ODBC_MAIN_EXECUTE_OPTION \
   QUERA_DB_ODBC_MAIN_COLUMNS_OPTION \
   QUERA_DB_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define QUERA_DB_ODBC_MAIN_ARGS 0
#define QUERA_DB_ODBC_MAIN_ARGV

namespace quera {
namespace db {
namespace odbc {

} // namespace odbc 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_MAINOPT_HPP 
