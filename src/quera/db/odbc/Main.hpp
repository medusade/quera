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

#include "quera/db/odbc/Query.hpp"
#include "quera/db/odbc/MainOpt.hpp"
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
    typedef MainT Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT()
    : m_run(0), m_queryRun(0),
      m_sourceChars("Data"), m_userChars(0), m_passwordChars(0),
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
        if ((m_run)) {
            err = (this->*m_run)(argc, argv, env);
        } else {
            err = this->Usage(argc, argv, env);
        }
        return err;
    }
    virtual int RunCreate(int argc, char** argv, char** env) {
        int err = 0;
        HWND hwndParent = NULL;
        WORD fRequest = ODBC_ADD_SYS_DSN;
        LPCSTR lpszDriver = NULL;
        LPCSTR lpszAttributes = NULL;
        TString driver, attributes;

        driver.assign("Microsoft Access Driver (*.mdb)");
        attributes.append("CREATE_DB=./");
        attributes.append(m_sourceChars);
        attributes.append(".mdb");
        attributes.append("\0", 1);

        if ((lpszDriver = driver.has_chars())) {
            CRONO_LOG_DEBUG("dirver = \"" << String(lpszDriver) << "\"");

            if ((lpszAttributes = attributes.has_chars())) {
                CRONO_LOG_DEBUG("attributes = \"" << String(lpszAttributes) << "\"");

                CRONO_LOG_DEBUG("SQLConfigDataSource(hwndParent, fRequest, lpszDriver, lpszAttributes)...");
                if ((SQLConfigDataSource(hwndParent, fRequest, lpszDriver, lpszAttributes))) {
                } else {
                    CRONO_LOG_ERROR("...failed on SQLConfigDataSource(hwndParent, fRequest, lpszDriver, lpszAttributes)");
                }
            }
        }
        return err;
    }
    virtual int RunQuery(int argc, char** argv, char** env) {
        int err = 0;
        if ((m_queryRun)) {
            odbc::Environment& e = m_environment;

            if ((e.Create())) {
                odbc::Connection& c = m_connection;

                if ((c.Create(e))) {
                    c.SetConnectOption(SQL_ACCESS_MODE, SQL_MODE_READ_WRITE);

                    if ((c.Connect(m_sourceChars, m_userChars, m_passwordChars))) {
                        odbc::Query& q = m_query;

                        if ((q.Create(c))) {

                            err = (this->*m_queryRun)(argc, argv, env);
                            q.Destroy();
                        }
                        c.Disconnect();
                    } else {
                        CharString errorMsg;
                        if ((c.Error(errorMsg))) {
                            this->OutLn(errorMsg.chars());
                        }
                    }
                    c.Destroy();
                }
                e.Destroy();
            }
        } else {
            err = this->Usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int  RunQueryColumns(int argc, char** argv, char** env) {
        int err = 0;

        if ((m_tableChars)) {
            odbc::Query& q = m_query;

            if ((q.TableColumns(m_tableChars))) {

                RunBeginQueryResults(argc, argv, env);
                RunQueryResults(argc, argv, env);
                RunEndQueryResults(argc, argv, env);
            }
        }
        return err;
    }
    virtual int  RunQueryExecute(int argc, char** argv, char** env) {
        int err = 0;
        bool begin = false, end = false;
        const char* chars = 0;

        if ((begin = ((chars = FirstStatement()) != 0))) {
            odbc::Query& q = m_query;

            do {
                if ((q.Execute(chars))) {
                    if ((end = begin)) {
                        begin = false;
                        RunBeginQueryResults(argc, argv, env);
                    }
                    RunQueryResults(argc, argv, env);
                } else {
                    odbc::Environment& e = m_environment;
                    odbc::Connection& c = m_connection;
                    CharString errorMsg;
                    if ((e.Error(errorMsg, c, q))) {
                        this->OutLn(errorMsg.chars());
                    }
                    break;
                }
            } while ((chars = NextStatement()));
            if ((end)) {
                end = false;
                RunEndQueryResults(argc, argv, env);
            }
        }
        return err;
    }
    virtual const char* FirstStatement() {
        return m_statementChars;
    }
    virtual const char* NextStatement() {
        size_t statementLength = 0;

        if ((m_statementChars) && (0 < (statementLength = m_statement.length()))) {
            const char* statementsChars = 0;
            size_t statementsLength = 0;

            if ((m_statementsChars) && (statementsChars = (m_statements.has_chars(statementsLength)))) {
                size_t statementsTell = 0;

                if ((statementsTell = (m_statementsChars-statementsChars)) < (statementsLength)) {
                    statementsChars = m_statementsChars;
                    m_statementsChars = 0;
                    m_statement.clear();
                    for (char c = 0; statementsTell < statementsLength; ++statementsTell, ++statementsChars) {
                        if (';' != (c = *statementsChars)) {
                            m_statement.append(&c, 1);
                            continue;
                        }
                        m_statementsChars = ++statementsChars;
                        break;
                    }
                    m_statementChars = m_statement.has_chars();
                    return m_statementChars;
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int  RunQueryResults(int argc, char** argv, char** env) {
        int err = 0;
        err = RunQueryResultsHtml(argc, argv, env);
        return err;
    }
    virtual int  RunBeginQueryResults(int argc, char** argv, char** env) {
        int err = 0;
        err = RunBeginQueryResultsHtml(argc, argv, env);
        return err;
    }
    virtual int  RunEndQueryResults(int argc, char** argv, char** env) {
        int err = 0;
        err = RunEndQueryResultsHtml(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int  RunBeginQueryResultsHtml(int argc, char** argv, char** env) {
        int err = 0;
        this->OutLn("<html><body>");
        return err;
    }
    virtual int  RunEndQueryResultsHtml(int argc, char** argv, char** env) {
        int err = 0;
        this->OutLn("</body></html>");
        return err;
    }
    virtual int  RunQueryResultsHtml(int argc, char** argv, char** env) {
        int err = 0;
        odbc::Query& q = m_query;
        size_t cols = 0, col = 0, row = 0;

        this->OutLn("<table border=\"1\">");
        if (0 < (cols = q.ResultColumns())) {
            size_t size = 0;
            string_t value;

            this->Out("<tc>");
            for (col = 1; col <= cols; ++col) {
                if (1 < (col)) {
                    this->Out("");
                }
                this->Out("<td colnum=\"");
                this->Out(value.assign_unsigned(col).chars());
                this->Out("\"");
                if ((q.ColumnLabel(value, col))) {
                    this->Out(" colname=\"");
                    this->Out(value.chars());
                    this->Out("\"");
                }
                this->Out("><nobr><b>");
                if ((q.ColumnLabel(value, col))) {
                    this->Out(value.chars());
                }
                this->Out("</b></nobr></td>");
            }
            this->OutLn("</tc>");

            while ((q.Fetch())) {
                ++row;
                this->Out("<tr row=\"");
                this->Out(value.assign_unsigned(row).chars());
                this->Out("\">");
                for (col = 1; col <= cols; ++col) {
                    if (1 < (col)) {
                        this->Out("");
                    }
                    this->Out("<td colnum=\"");
                    this->Out(value.assign_unsigned(col).chars());
                    this->Out("\"");
                    if ((q.ColumnLabel(value, col))) {
                        this->Out(" colname=\"");
                        this->Out(value.chars());
                        this->Out("\"");
                    }
                    this->Out("><nobr>");
                    if ((q.ColumnDisplaySize(size, col))) {
                        if (0 < (size)) {
                            if ((q.GetDataValueChars(value, size, col))) {
                                this->Out(value.chars());
                            }
                        }
                    }
                    this->Out("</nobr></td>");
                }
                this->OutLn("</tr>");
            }
        }
        this->OutLn("</body></html>");
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnCreateOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::RunCreate;
        m_queryRun = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnExecuteOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::RunQuery;
        m_queryRun = &Derives::RunQueryExecute;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnColumnsOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::RunQuery;
        m_queryRun = &Derives::RunQueryColumns;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnDataOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((m_sourceChars = m_source.assign(optarg).chars())) {
                CRONO_LOG_DEBUG("...source = \"" << m_sourceChars << "\"");
                if (!(m_queryRun)) {
                    m_run = &Derives::RunQuery;
                    m_queryRun = &Derives::RunQueryExecute;
                }
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
        if (!(m_queryRun)) {
            m_run = &Derives::RunQuery;
            m_queryRun = &Derives::RunQueryExecute;
        }
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
                if (!(m_queryRun)) {
                    m_run = &Derives::RunQuery;
                    m_queryRun = &Derives::RunQueryExecute;
                }
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
            FILE* f = 0;
            if ((f = fopen(optarg, "r"))) {
                size_t length = 0;
                m_statement.clear();
                m_statements.clear();
                for (char c = 0; (0 < fread(&c, 1,1, f));) {
                    m_statements.append(&c, 1);
                }
                fclose(f);
                if ((m_statementsChars = (m_statementChars = m_statements.has_chars(length)))) {
                    for (char c = 0; length; --length, ++m_statementsChars) {
                        if (';' == (c = *(m_statementsChars))) {
                            m_statement.assign(m_statementChars, m_statementsChars-m_statementChars);
                            m_statementChars = m_statement.has_chars();
                            ++m_statementsChars;
                            CRONO_LOG_DEBUG("...statement = \"" << m_statement << "\"");
                            break;
                        }
                    }
                }
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOutputOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

#include "quera/db/odbc/MainOpt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*MRun)(int argc, char** argv, char** env);
    MRun m_run, m_queryRun;
    const char *m_sourceChars, *m_userChars, *m_passwordChars, 
               *m_tableChars, *m_selectChars, *m_whereChars,
               *m_statementChars, *m_statementsChars;
    string_t m_source, m_user, m_password, 
             m_table, m_select, m_where,
             m_statement, m_statements;
    odbc::Environment m_environment;
    odbc::Connection m_connection;
    odbc::Query m_query;
};
typedef MainT<> Main;

} // namespace odbc 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_MAIN_HPP 
