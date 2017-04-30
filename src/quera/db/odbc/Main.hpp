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
#include "quera/db/OptMain.hpp"
#include "quera/db/Main.hpp"
#include "quera/base/Base.hpp"

namespace quera {
namespace db {
namespace odbc {

typedef db::OptMainTImplements MainTImplements;
typedef db::OptMain MainTExtends;
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
    MainT(): m_run(0), m_queryRun(0) {
    }
    virtual ~MainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int QueryRun(int argc, char** argv, char** env) {
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
        attributes.append(this->m_sourceChars);
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

                    if ((c.Connect(this->m_sourceChars, this->m_userChars, this->m_passwordChars))) {
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

        if ((this->m_tableChars)) {
            odbc::Query& q = m_query;

            if ((q.TableColumns(this->m_tableChars))) {

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
        return this->m_statementChars;
    }
    virtual const char* NextStatement() {
        size_t statementLength = 0;

        if ((this->m_statementChars) && (0 < (statementLength = this->m_statement.length()))) {
            const char* statementsChars = 0;
            size_t statementsLength = 0;

            if ((this->m_statementsChars) && (statementsChars = (this->m_statements.has_chars(statementsLength)))) {
                size_t statementsTell = 0;

                if ((statementsTell = (this->m_statementsChars-statementsChars)) < (statementsLength)) {
                    statementsChars = this->m_statementsChars;
                    this->m_statementsChars = 0;
                    this->m_statement.clear();
                    for (char c = 0; statementsTell < statementsLength; ++statementsTell, ++statementsChars) {
                        if (';' != (c = *statementsChars)) {
                            this->m_statement.append(&c, 1);
                            continue;
                        }
                        this->m_statementsChars = ++statementsChars;
                        break;
                    }
                    this->m_statementChars = this->m_statement.has_chars();
                    return this->m_statementChars;
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
    virtual void OnLocationPartChanged() {
        if (!(m_queryRun)) {
            m_run = &Derives::RunQuery;
            m_queryRun = &Derives::RunQueryExecute;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnStatementChanged() {
        if (!(m_queryRun)) {
            m_run = &Derives::RunQuery;
            m_queryRun = &Derives::RunQueryExecute;
        }
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
                this->m_statement.clear();
                this->m_statements.clear();
                for (char c = 0; (0 < fread(&c, 1,1, f));) {
                    this->m_statements.append(&c, 1);
                }
                fclose(f);
                if ((this->m_statementsChars = (this->m_statementChars = this->m_statements.has_chars(length)))) {
                    for (char c = 0; length; --length, ++this->m_statementsChars) {
                        if (';' == (c = *(this->m_statementsChars))) {
                            this->m_statement.assign(this->m_statementChars, this->m_statementsChars-this->m_statementChars);
                            this->m_statementChars = this->m_statement.has_chars();
                            ++this->m_statementsChars;
                            CRONO_LOG_DEBUG("...statement = \"" << this->m_statement << "\"");
                            break;
                        }
                    }
                }
            }
        }
        return err;
    }

#include "quera/db/odbc/MainOpt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*MRun)(int argc, char** argv, char** env);
    MRun m_run, m_queryRun;
    odbc::Environment m_environment;
    odbc::Connection m_connection;
    odbc::Query m_query;
};
typedef MainT<> Main;

} // namespace odbc 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_MAIN_HPP 
