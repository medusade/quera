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
///   File: CGIMain.hpp
///
/// Author: $author$
///   Date: 4/30/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_ODBC_CGIMAIN_HPP
#define _QUERA_DB_ODBC_CGIMAIN_HPP

#include "quera/db/odbc/Main.hpp"
#include "quera/db/CGIMain.hpp"

namespace quera {
namespace db {
namespace odbc {

typedef db::CGIMainTImplements CGIMainTImplements;
typedef odbc::MainT
<CGIMainTImplements, db::CGIMain> CGIMainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CGIMainT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = CGIMainTImplements, class TExtends = CGIMainTExtends>
class _EXPORT_CLASS CGIMainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CGIMainT() {
    }
    virtual ~CGIMainT() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeRunCgi(int argc, char** argv, char** env) {
        int err = Extends::BeforeRunCgi(argc, argv, env);
        const char* host = 0;
        if ((host = this->m_host.has_chars())) {
            this->OnDataOption(host);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CGIMainT<> CGIMain;

} // namespace odbc
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_CGIMAIN_HPP 
