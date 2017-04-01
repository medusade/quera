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
///   Date: 3/30/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_MAIN_HPP
#define _QUERA_DB_MAIN_HPP

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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT(const char* userChars = 0, const char* passwordChars = 0)
    : m_hostChars("localhost"), m_sourceChars("Data"),
      m_userChars(userChars), m_passwordChars(passwordChars),
      m_tableChars("Table"), m_selectChars("*"), m_whereChars(0),
      m_statementChars("select * from Table"), m_statementsChars(0) {
    }
    virtual ~MainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((m_hostChars = m_host.assign(optarg).chars())) {
                CRONO_LOG_DEBUG("...host = \"" << m_hostChars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnDataOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((m_sourceChars = m_source.assign(optarg).chars())) {
                CRONO_LOG_DEBUG("...source = \"" << m_sourceChars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnUserOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((m_userChars = m_user.assign(optarg).has_chars())) {
                CRONO_LOG_DEBUG("...user = \"" << m_userChars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnPasswordOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((m_passwordChars = m_password.assign(optarg).has_chars())) {
                CRONO_LOG_DEBUG("...password = \"" << m_passwordChars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnStatementPartChanged() {
        m_statement.assign("select ");
        m_statement.append(m_selectChars);
        m_statement.append(" from ");
        m_statement.append(m_tableChars);
        if ((m_whereChars)) {
            m_statement.append(" where ");
            m_statement.append(m_whereChars);
        }
        m_statementChars = m_statement.chars();
        CRONO_LOG_DEBUG("...statement = \"" << m_statementChars << "\"");
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnTableOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((m_tableChars = m_table.assign(optarg).chars())) {
                OnStatementPartChanged();
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnSelectOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((m_selectChars = m_select.assign(optarg).chars())) {
                OnStatementPartChanged();
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnWhereOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((m_whereChars = m_where.assign(optarg).chars())) {
                OnStatementPartChanged();
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnQueryOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((m_statementChars = m_statement.assign(optarg).chars())) {
                CRONO_LOG_DEBUG("...statement = \"" << m_statementChars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnInputOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

#include "quera/db/MainOpt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char *m_hostChars,
               *m_sourceChars, *m_userChars, *m_passwordChars,
               *m_tableChars, *m_selectChars, *m_whereChars,
               *m_statementChars, *m_statementsChars;
    string_t m_host, m_source, m_user, m_password,
             m_table, m_select, m_where,
             m_statement, m_statements;
};
typedef MainT<> Main;

} // namespace db
} // namespace quera 

#endif // _QUERA_DB_MAIN_HPP 
