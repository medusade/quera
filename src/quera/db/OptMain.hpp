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
///   File: OptMain.hpp
///
/// Author: $author$
///   Date: 4/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_OPTMAIN_HPP
#define _QUERA_DB_OPTMAIN_HPP

#include "quera/db/Main.hpp"

namespace quera {
namespace db {

typedef MainTImplements OptMainTImplements;
typedef Main OptMainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: OptMainT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = OptMainTImplements, class TExtends = OptMainTExtends>

class _EXPORT_CLASS OptMainT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    OptMainT(const char* userChars = 0, const char* passwordChars = 0)
    : Extends(userChars, passwordChars) {
    }
    virtual ~OptMainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char** argv, char** env) {
        int err = this->QueryRun(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnHostOption(optarg);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnDataOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnDataOption(optarg);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnUserOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnUserOption(optarg);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnPasswordOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnPasswordOption(optarg);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnTableOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnTableOption(optarg);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnSelectOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnSelectOption(optarg);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnWhereOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnWhereOption(optarg);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnQueryOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnQueryOption(optarg);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnInputOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnInputOption(optarg);
        return err;
    }

#include "quera/db/MainOpt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef OptMainT<> OptMain;

} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_OPTMAIN_HPP 
