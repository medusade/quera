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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 3/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_ODBC_MAIN_HPP
#define _QUERA_DB_ODBC_MAIN_HPP

#include "quera/db/odbc/Connection.hpp"
#include "quera/base/Base.hpp"
#include "crono/console/getopt/Main.hpp"

namespace quera {
namespace db {
namespace odbc {

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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT(): m_dsn("Data") {
    }
    virtual ~MainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int  Run(int argc, char** argv, char** env) {
        int err = 0;
        odbc::Environment& e = m_environment;

        if ((e.Create())) {
            odbc::Connection& c = m_connection;

            if ((c.Create(e))) {

                c.SetConnectOption(SQL_ACCESS_MODE, SQL_MODE_READ_WRITE);

                if ((c.Connect(m_dsn))) {

                    c.Disconnect();
                }
                c.Destroy();
            }
            e.Destroy();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char *m_dsn;
    odbc::Environment m_environment;
    odbc::Connection m_connection;
};
typedef MainT<> Main;

} // namespace odbc 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_MAIN_HPP 
