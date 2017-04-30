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
///   File: MainOpt.cpp
///
/// Author: $author$
///   Date: 3/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_ODBC_MAIN_HPP
#include "quera/db/odbc/MainOpt.hpp"
#include "quera/db/Main.hpp"

namespace quera {
namespace db {
namespace odbc {

typedef db::MainTImplements MainTImplements;
typedef db::Main MainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MainTImplements, class TExtends = MainTExtends>

class _EXPORT_CLASS MainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
#endif // _QUERA_DB_ODBC_MAIN_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case QUERA_DB_ODBC_MAIN_CREATE_OPTVAL_C:
            err = OnCreateOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_ODBC_MAIN_EXECUTE_OPTVAL_C:
            err = OnExecuteOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_ODBC_MAIN_COLUMNS_OPTVAL_C:
            err = OnColumnsOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case QUERA_DB_ODBC_MAIN_CREATE_OPTVAL_C:
            optarg = QUERA_DB_ODBC_MAIN_CREATE_OPTARG;
            chars = QUERA_DB_ODBC_MAIN_CREATE_OPTUSE;
            break;
        case QUERA_DB_ODBC_MAIN_EXECUTE_OPTVAL_C:
            optarg = QUERA_DB_ODBC_MAIN_EXECUTE_OPTARG;
            chars = QUERA_DB_ODBC_MAIN_EXECUTE_OPTUSE;
            break;
        case QUERA_DB_ODBC_MAIN_COLUMNS_OPTVAL_C:
            optarg = QUERA_DB_ODBC_MAIN_COLUMNS_OPTARG;
            chars = QUERA_DB_ODBC_MAIN_COLUMNS_OPTUSE;
            break;
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = QUERA_DB_ODBC_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            QUERA_DB_ODBC_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

#ifndef _QUERA_DB_ODBC_MAIN_HPP
};

} // namespace odbc
} // namespace db 
} // namespace quera 
#endif // _QUERA_DB_ODBC_MAIN_HPP
