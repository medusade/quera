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
///   Date: 3/30/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_MAIN_HPP
#include "quera/db/MainOpt.hpp"

namespace quera {
namespace db {

typedef crono::console::getopt::MainImplements MainTImplements;
typedef crono::console::getopt::Main MainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MainTImplements, class TExtends = MainTExtends>

class _EXPORT_CLASS MainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
#endif // _QUERA_DB_MAIN_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case QUERA_DB_MAIN_HOST_OPTVAL_C:
            err = OnHostOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_MAIN_DATA_OPTVAL_C:
            err = OnDataOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_MAIN_USER_OPTVAL_C:
            err = OnUserOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_MAIN_PASSWORD_OPTVAL_C:
            err = OnPasswordOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_MAIN_TABLE_OPTVAL_C:
            err = OnTableOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_MAIN_SELECT_OPTVAL_C:
            err = OnSelectOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_MAIN_WHERE_OPTVAL_C:
            err = OnWhereOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_MAIN_QUERY_OPTVAL_C:
            err = OnQueryOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case QUERA_DB_MAIN_INPUT_OPTVAL_C:
            err = OnInputOption
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
        case QUERA_DB_MAIN_HOST_OPTVAL_C:
            optarg = QUERA_DB_MAIN_HOST_OPTARG;
            chars = QUERA_DB_MAIN_HOST_OPTUSE;
            break;
        case QUERA_DB_MAIN_DATA_OPTVAL_C:
            optarg = QUERA_DB_MAIN_DATA_OPTARG;
            chars = QUERA_DB_MAIN_DATA_OPTUSE;
            break;
        case QUERA_DB_MAIN_USER_OPTVAL_C:
            optarg = QUERA_DB_MAIN_USER_OPTARG;
            chars = QUERA_DB_MAIN_USER_OPTUSE;
            break;
        case QUERA_DB_MAIN_PASSWORD_OPTVAL_C:
            optarg = QUERA_DB_MAIN_PASSWORD_OPTARG;
            chars = QUERA_DB_MAIN_PASSWORD_OPTUSE;
            break;
        case QUERA_DB_MAIN_TABLE_OPTVAL_C:
            optarg = QUERA_DB_MAIN_TABLE_OPTARG;
            chars = QUERA_DB_MAIN_TABLE_OPTUSE;
            break;
        case QUERA_DB_MAIN_SELECT_OPTVAL_C:
            optarg = QUERA_DB_MAIN_SELECT_OPTARG;
            chars = QUERA_DB_MAIN_SELECT_OPTUSE;
            break;
        case QUERA_DB_MAIN_WHERE_OPTVAL_C:
            optarg = QUERA_DB_MAIN_WHERE_OPTARG;
            chars = QUERA_DB_MAIN_WHERE_OPTUSE;
            break;
        case QUERA_DB_MAIN_QUERY_OPTVAL_C:
            optarg = QUERA_DB_MAIN_QUERY_OPTARG;
            chars = QUERA_DB_MAIN_QUERY_OPTUSE;
            break;
        case QUERA_DB_MAIN_INPUT_OPTVAL_C:
            optarg = QUERA_DB_MAIN_INPUT_OPTARG;
            chars = QUERA_DB_MAIN_INPUT_OPTUSE;
            break;
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = QUERA_DB_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            QUERA_DB_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

#ifndef _QUERA_DB_MAIN_HPP
};

} // namespace db
} // namespace quera 
#endif // _QUERA_DB_MAIN_HPP
