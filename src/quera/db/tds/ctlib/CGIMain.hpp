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
///   Date: 4/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_TDS_CTLIB_CGIMAIN_HPP
#define _QUERA_DB_TDS_CTLIB_CGIMAIN_HPP

#include "quera/db/tds/ctlib/Main.hpp"
#include "porta/app/console/cgi/Main.hpp"

namespace quera {
namespace db {
namespace tds {
namespace ctlib {

typedef porta::app::console::cgi::MainTImplements CGIMainTImplements;
typedef ctlib::MainT
<CGIMainTImplements, db::MainT
 <CGIMainTImplements, porta::app::console::cgi::Main> > CGIMainTExtends;
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
    CGIMainT()
    : m_queryName("Query"), m_tableName("Table"), m_selectName("Select"),
      m_whereName("Where"), m_dataName("Data"), m_hostName("Host"),
      m_userName("User"), m_passwordName("Password") {
    }
    virtual ~CGIMainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunCgi(int argc, char** argv, char** env) {
        int err = 0;
        this->OutContentType();
        err = this->QueryRun(argc, argv, env);
        return err;
    }
    virtual int BeforeRunCgi(int argc, char** argv, char** env) {
        int err = 0;
        const char* chars = 0;
        this->SetContentTypeToHtml();
        if ((chars = this->FindFormValue(m_hostName.chars()))) {
            this->OnHostOption(chars);
        }
        if ((chars = this->FindFormValue(m_dataName.chars()))) {
            this->OnDataOption(chars);
        }
        if ((chars = this->FindFormValue(m_userName.chars()))) {
            this->OnUserOption(chars);
        }
        if ((chars = this->FindFormValue(m_passwordName.chars()))) {
            this->OnPasswordOption(chars);
        }
        if ((chars = this->FindFormValue(m_tableName.chars()))) {
            this->OnTableOption(chars);
        }
        if ((chars = this->FindFormValue(m_selectName.chars()))) {
            this->OnSelectOption(chars);
        }
        if ((chars = this->FindFormValue(m_whereName.chars()))) {
            this->OnWhereOption(chars);
        }
        if ((chars = this->FindFormValue(m_queryName.chars()))) {
            this->OnQueryOption(chars);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_queryName, m_tableName, m_selectName, m_whereName,
           m_dataName, m_hostName, m_userName, m_passwordName;
};
typedef CGIMainT<> CGIMain;

} // namespace ctlib 
} // namespace tds 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_TDS_CTLIB_CGIMAIN_HPP 
