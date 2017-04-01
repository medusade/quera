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
///   Date: 3/30/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_MAINOPT_HPP
#define _QUERA_DB_MAINOPT_HPP

#include "quera/base/Base.hpp"
#include "crono/console/getopt/Main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define QUERA_DB_MAIN_HOST_OPT "host"
#define QUERA_DB_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define QUERA_DB_MAIN_HOST_OPTARG_RESULT 0
#define QUERA_DB_MAIN_HOST_OPTARG ""
#define QUERA_DB_MAIN_HOST_OPTUSE ""
#define QUERA_DB_MAIN_HOST_OPTVAL_S "o:"
#define QUERA_DB_MAIN_HOST_OPTVAL_C 'o'
#define QUERA_DB_MAIN_HOST_OPTION \
   {QUERA_DB_MAIN_HOST_OPT, \
    QUERA_DB_MAIN_HOST_OPTARG_REQUIRED, \
    QUERA_DB_MAIN_HOST_OPTARG_RESULT, \
    QUERA_DB_MAIN_HOST_OPTVAL_C}, \

#define QUERA_DB_MAIN_DATA_OPT "data"
#define QUERA_DB_MAIN_DATA_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define QUERA_DB_MAIN_DATA_OPTARG_RESULT 0
#define QUERA_DB_MAIN_DATA_OPTARG ""
#define QUERA_DB_MAIN_DATA_OPTUSE ""
#define QUERA_DB_MAIN_DATA_OPTVAL_S "d:"
#define QUERA_DB_MAIN_DATA_OPTVAL_C 'd'
#define QUERA_DB_MAIN_DATA_OPTION \
   {QUERA_DB_MAIN_DATA_OPT, \
    QUERA_DB_MAIN_DATA_OPTARG_REQUIRED, \
    QUERA_DB_MAIN_DATA_OPTARG_RESULT, \
    QUERA_DB_MAIN_DATA_OPTVAL_C}, \

#define QUERA_DB_MAIN_USER_OPT "user"
#define QUERA_DB_MAIN_USER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define QUERA_DB_MAIN_USER_OPTARG_RESULT 0
#define QUERA_DB_MAIN_USER_OPTARG ""
#define QUERA_DB_MAIN_USER_OPTUSE ""
#define QUERA_DB_MAIN_USER_OPTVAL_S "u:"
#define QUERA_DB_MAIN_USER_OPTVAL_C 'u'
#define QUERA_DB_MAIN_USER_OPTION \
   {QUERA_DB_MAIN_USER_OPT, \
    QUERA_DB_MAIN_USER_OPTARG_REQUIRED, \
    QUERA_DB_MAIN_USER_OPTARG_RESULT, \
    QUERA_DB_MAIN_USER_OPTVAL_C}, \

#define QUERA_DB_MAIN_PASSWORD_OPT "password"
#define QUERA_DB_MAIN_PASSWORD_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define QUERA_DB_MAIN_PASSWORD_OPTARG_RESULT 0
#define QUERA_DB_MAIN_PASSWORD_OPTARG ""
#define QUERA_DB_MAIN_PASSWORD_OPTUSE ""
#define QUERA_DB_MAIN_PASSWORD_OPTVAL_S "p:"
#define QUERA_DB_MAIN_PASSWORD_OPTVAL_C 'p'
#define QUERA_DB_MAIN_PASSWORD_OPTION \
   {QUERA_DB_MAIN_PASSWORD_OPT, \
    QUERA_DB_MAIN_PASSWORD_OPTARG_REQUIRED, \
    QUERA_DB_MAIN_PASSWORD_OPTARG_RESULT, \
    QUERA_DB_MAIN_PASSWORD_OPTVAL_C}, \

#define QUERA_DB_MAIN_TABLE_OPT "table"
#define QUERA_DB_MAIN_TABLE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define QUERA_DB_MAIN_TABLE_OPTARG_RESULT 0
#define QUERA_DB_MAIN_TABLE_OPTARG ""
#define QUERA_DB_MAIN_TABLE_OPTUSE ""
#define QUERA_DB_MAIN_TABLE_OPTVAL_S "t:"
#define QUERA_DB_MAIN_TABLE_OPTVAL_C 't'
#define QUERA_DB_MAIN_TABLE_OPTION \
   {QUERA_DB_MAIN_TABLE_OPT, \
    QUERA_DB_MAIN_TABLE_OPTARG_REQUIRED, \
    QUERA_DB_MAIN_TABLE_OPTARG_RESULT, \
    QUERA_DB_MAIN_TABLE_OPTVAL_C}, \

#define QUERA_DB_MAIN_SELECT_OPT "select"
#define QUERA_DB_MAIN_SELECT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define QUERA_DB_MAIN_SELECT_OPTARG_RESULT 0
#define QUERA_DB_MAIN_SELECT_OPTARG ""
#define QUERA_DB_MAIN_SELECT_OPTUSE ""
#define QUERA_DB_MAIN_SELECT_OPTVAL_S "s:"
#define QUERA_DB_MAIN_SELECT_OPTVAL_C 's'
#define QUERA_DB_MAIN_SELECT_OPTION \
   {QUERA_DB_MAIN_SELECT_OPT, \
    QUERA_DB_MAIN_SELECT_OPTARG_REQUIRED, \
    QUERA_DB_MAIN_SELECT_OPTARG_RESULT, \
    QUERA_DB_MAIN_SELECT_OPTVAL_C}, \

#define QUERA_DB_MAIN_WHERE_OPT "where"
#define QUERA_DB_MAIN_WHERE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define QUERA_DB_MAIN_WHERE_OPTARG_RESULT 0
#define QUERA_DB_MAIN_WHERE_OPTARG ""
#define QUERA_DB_MAIN_WHERE_OPTUSE ""
#define QUERA_DB_MAIN_WHERE_OPTVAL_S "w:"
#define QUERA_DB_MAIN_WHERE_OPTVAL_C 'w'
#define QUERA_DB_MAIN_WHERE_OPTION \
   {QUERA_DB_MAIN_WHERE_OPT, \
    QUERA_DB_MAIN_WHERE_OPTARG_REQUIRED, \
    QUERA_DB_MAIN_WHERE_OPTARG_RESULT, \
    QUERA_DB_MAIN_WHERE_OPTVAL_C}, \

#define QUERA_DB_MAIN_QUERY_OPT "query"
#define QUERA_DB_MAIN_QUERY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define QUERA_DB_MAIN_QUERY_OPTARG_RESULT 0
#define QUERA_DB_MAIN_QUERY_OPTARG ""
#define QUERA_DB_MAIN_QUERY_OPTUSE ""
#define QUERA_DB_MAIN_QUERY_OPTVAL_S "q:"
#define QUERA_DB_MAIN_QUERY_OPTVAL_C 'q'
#define QUERA_DB_MAIN_QUERY_OPTION \
   {QUERA_DB_MAIN_QUERY_OPT, \
    QUERA_DB_MAIN_QUERY_OPTARG_REQUIRED, \
    QUERA_DB_MAIN_QUERY_OPTARG_RESULT, \
    QUERA_DB_MAIN_QUERY_OPTVAL_C}, \

#define QUERA_DB_MAIN_INPUT_OPT "input"
#define QUERA_DB_MAIN_INPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define QUERA_DB_MAIN_INPUT_OPTARG_RESULT 0
#define QUERA_DB_MAIN_INPUT_OPTARG ""
#define QUERA_DB_MAIN_INPUT_OPTUSE ""
#define QUERA_DB_MAIN_INPUT_OPTVAL_S "i:"
#define QUERA_DB_MAIN_INPUT_OPTVAL_C 'i'
#define QUERA_DB_MAIN_INPUT_OPTION \
   {QUERA_DB_MAIN_INPUT_OPT, \
    QUERA_DB_MAIN_INPUT_OPTARG_REQUIRED, \
    QUERA_DB_MAIN_INPUT_OPTARG_RESULT, \
    QUERA_DB_MAIN_INPUT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define QUERA_DB_MAIN_OPTIONS_CHARS \
    QUERA_DB_MAIN_HOST_OPTVAL_S \
   QUERA_DB_MAIN_DATA_OPTVAL_S \
   QUERA_DB_MAIN_USER_OPTVAL_S \
   QUERA_DB_MAIN_PASSWORD_OPTVAL_S \
   QUERA_DB_MAIN_TABLE_OPTVAL_S \
   QUERA_DB_MAIN_SELECT_OPTVAL_S \
   QUERA_DB_MAIN_WHERE_OPTVAL_S \
   QUERA_DB_MAIN_QUERY_OPTVAL_S \
    QUERA_DB_MAIN_INPUT_OPTVAL_S \
   CRONO_MAIN_OPTIONS_CHARS

#define QUERA_DB_MAIN_OPTIONS_OPTIONS \
    QUERA_DB_MAIN_HOST_OPTION \
   QUERA_DB_MAIN_DATA_OPTION \
   QUERA_DB_MAIN_USER_OPTION \
   QUERA_DB_MAIN_PASSWORD_OPTION \
   QUERA_DB_MAIN_TABLE_OPTION \
   QUERA_DB_MAIN_SELECT_OPTION \
   QUERA_DB_MAIN_WHERE_OPTION \
   QUERA_DB_MAIN_QUERY_OPTION \
    QUERA_DB_MAIN_INPUT_OPTION \
   CRONO_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define QUERA_DB_MAIN_ARGS 0
#define QUERA_DB_MAIN_ARGV

namespace quera {
namespace db {

} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_MAINOPT_HPP 
