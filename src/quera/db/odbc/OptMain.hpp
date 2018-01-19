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
///   Date: 4/30/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_ODBC_OPTMAIN_HPP
#define _QUERA_DB_ODBC_OPTMAIN_HPP

#include "quera/db/odbc/Main.hpp"
#include "quera/db/odbc/MainOpt.hpp"

namespace quera {
namespace db {
namespace odbc {

typedef odbc::MainTImplements OptMainTImplements;
typedef odbc::Main OptMainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: OptMainT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = OptMainTImplements, class TExtends = OptMainTExtends>

class _EXPORT_CLASS OptMainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    OptMainT() {
    }
    virtual ~OptMainT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnCreateOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnCreateOption(optarg);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnExecuteOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnExecuteOption(optarg);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnColumnsOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::OnColumnsOption(optarg);
        return err;
    }

#include "quera/db/odbc/MainOpt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef OptMainT<> OptMain;

} // namespace odbc 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_OPTMAIN_HPP 
