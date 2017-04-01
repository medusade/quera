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
#ifndef _QUERA_DB_TDS_CTLIB_MAIN_HPP
#define _QUERA_DB_TDS_CTLIB_MAIN_HPP

#include "quera/db/Main.hpp"
#include "quera/db/tds/ctlib/Command.hpp"
#include "quera/db/tds/ctlib/Connection.hpp"
#include "quera/db/tds/ctlib/Context.hpp"
#include "quera/db/tds/ctlib/CTLib.hpp"

namespace quera {
namespace db {
namespace tds {
namespace ctlib {

typedef db::MainTImplements MainTImplements;
typedef db::Main MainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MainTImplements, class TExtends = MainTExtends>
class _EXPORT_CLASS MainT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT(): Extends("User", "Password") {
        OnStatementPartChanged();
    }
    virtual ~MainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char** argv, char** env) {
        int err = 0;
        tds::ctlib::Context& ctx = m_ctx;

        if ((ctx.Create())) {
            tds::ctlib::Connection& con = m_con;

            if ((con.Create(ctx))) {
                const char* chars = 0;

                if ((chars = this->m_userChars)) {
                    if ((con.SetUser(chars))) {

                        if ((chars = this->m_passwordChars)) {
                            if ((con.SetPassword(chars))) {

                                if ((chars = this->m_hostChars)) {
                                    if ((con.Connect(chars))) {
                                        tds::ctlib::Command& cmd = m_cmd;

                                        if ((cmd.Create(con))) {

                                            if ((chars = this->m_statementChars)) {

                                                if ((cmd.SetStatement(chars))) {

                                                    if ((cmd.Send())) {
                                                        ResultsRun(argc, argv, env);
                                                    }
                                                }
                                            }
                                            cmd.Destroy();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                con.Destroy();
            }
            ctx.Destroy();
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int ResultsRun(int argc, char** argv, char** env) {
        int err = 0;
        CS_INT type = 0;
        tds::ctlib::Command& cmd = m_cmd;

        if ((cmd.Results(type))) {
            const char* chars = 0;
            CS_INT rows = 0, cols = 0;
            int row = 1, col = 1;
            CS_DATAFMT format;
            String name;

            BeginResultRowsRun(argc, argv, env);
            do {
                if (CS_ROW_RESULT == (type)) {
                    CRONO_LOG_DEBUG("...CS_ROW_RESULT = " << type << "");
                    if (2 > (row)) {
                        if ((cmd.ResultColumns(cols))) {
                            BeginResultColsRun(argc, argv, env);
                            for (col = 1; col <= cols; ++col) {
                                if ((cmd.Describe(col, format))) {
                                    BeginResultColRun(0, col, argc, argv, env);
                                    if ((chars = name.assign(format.name, format.namelen).has_chars())) {
                                        ResultColRun(0, col, chars, argc, argv, env);
                                    }
                                    EndResultColRun(0, col, argc, argv, env);
                                }
                            }
                            EndResultColsRun(argc, argv, env);
                        }
                    }
                    if ((cmd.Fetch(rows))) {
                        for (; 0 < rows; --rows, ++row) {
                            BeginResultRowRun(row, argc, argv, env);
                            if ((cmd.ResultColumns(cols))) {
                                for (col = 1; col <= cols; ++col) {
                                    BeginResultColRun(row, col, argc, argv, env);
                                    if ((cmd.Describe(col, format))) {
                                        ResultColRun(row, col, format, argc, argv, env);
                                    }
                                    EndResultColRun(row, col, argc, argv, env);
                                }
                            }
                            EndResultRowRun(row, argc, argv, env);
                        }
                    }
                } else {
                    CRONO_LOG_DEBUG("...type = " << type << "");
                }
            } while (cmd.Results(type));

            EndResultRowsRun(argc, argv, env);
        }
        return err;
    }
    virtual int ResultColRun
    (int row, int col, CS_DATAFMT& format, int argc, char** argv, char** env) {
        int err = 0;
        tds::ctlib::Command& cmd = m_cmd;
        CS_INT type = format.datatype;
        CS_INT intValue = 0;
        CharString stringValue;

        switch(type) {
        case CS_CHAR_TYPE:
            CRONO_LOG_DEBUG("...CS_CHAR_TYPE = " << type);
            if ((cmd.GetData(stringValue, 128, col))) {
                ResultColRun(row, col, stringValue.chars(), argc, argv, env);
            }
            break;
        case CS_INT_TYPE:
            CRONO_LOG_DEBUG("...CS_INT_TYPE = " << type);
            if ((cmd.GetData(intValue, col))) {
                ResultColRun(row, col, stringValue.assign_int(intValue).chars(), argc, argv, env);
            }
            break;
        default:
            CRONO_LOG_DEBUG("...type = " << type);
            break;
        }
        return err;
    }
    virtual int BeginResultRowsRun(int argc, char** argv, char** env) {
        int err = 0;
        this->OutLn("<html><body><table border=\"1\">");
        return err;
    }
    virtual int EndResultRowsRun(int argc, char** argv, char** env) {
        int err = 0;
        this->OutLn("</table></body></html>");
        return err;
    }
    virtual int BeginResultRowRun(int row, int argc, char** argv, char** env) {
        int err = 0;
        this->Out("<tr row=\"");
        this->Out(String().assign_int(row).chars());
        this->Out("\">");
        return err;
    }
    virtual int EndResultRowRun(int row, int argc, char** argv, char** env) {
        int err = 0;
        this->OutLn("</tr>");
        return err;
    }
    virtual int BeginResultColsRun(int argc, char** argv, char** env) {
        int err = 0;
        this->Out("<tc>");
        return err;
    }
    virtual int EndResultColsRun(int argc, char** argv, char** env) {
        int err = 0;
        this->OutLn("</tc>");
        return err;
    }
    virtual int BeginResultColRun(int row, int col, int argc, char** argv, char** env) {
        int err = 0;
        this->Out("<td><nobr>");
        if (1 > row) this->Out("<b>");
        return err;
    }
    virtual int EndResultColRun(int row, int col, int argc, char** argv, char** env) {
        int err = 0;
        if (1 > row) this->Out("</b>");
        this->Out("</nobr></td>");
        return err;
    }
    virtual int ResultColRun
    (int row, int col, const char* chars, int argc, char** argv, char** env) {
        int err = 0;
        if (chars) this->Out(chars);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnStatementPartChanged() {
        this->m_statement.assign("select ");
        this->m_statement.append(this->m_selectChars);
        this->m_statement.append(" from ");
        this->m_statement.append(this->m_sourceChars);
        this->m_statement.append("..");
        this->m_statement.append(this->m_tableChars);
        if ((this->m_whereChars)) {
            this->m_statement.append(" where ");
            this->m_statement.append(this->m_whereChars);
        }
        this->m_statementChars = this->m_statement.chars();
        CRONO_LOG_DEBUG("...statement = \"" << this->m_statementChars << "\"");
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tds::ctlib::Context m_ctx;
    tds::ctlib::Connection m_con;
    tds::ctlib::Command m_cmd;
};
typedef MainT<> Main;

} // namespace ctlib 
} // namespace tds 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_TDS_CTLIB_MAIN_HPP 
        

