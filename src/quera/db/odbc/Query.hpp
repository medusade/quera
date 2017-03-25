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
///   File: Query.hpp
///
/// Author: $author$
///   Date: 3/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_ODBC_QUERY_HPP
#define _QUERA_DB_ODBC_QUERY_HPP

#include "quera/db/odbc/Connection.hpp"

namespace quera {
namespace db {
namespace odbc {

typedef SQLHSTMT QueryAttachedTo;

typedef patrona::CreatorT<ImplementBase> QueryTCreator;
typedef patrona::AttacherT
<QueryAttachedTo, int, 0, QueryTCreator> QueryTAttacher;
typedef patrona::AttachedT
<QueryAttachedTo, int, 0, QueryTAttacher, Object> QueryTAttached;
typedef patrona::CreatedT
<QueryAttachedTo, int, 0, QueryTAttacher, QueryTAttached> QueryTCreated;

typedef QueryTAttacher QueryTImplements;
typedef QueryTCreated QueryTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: QueryT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = QueryTImplements, class TExtends = QueryTExtends>

class _EXPORT_CLASS QueryT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    QueryT(SQLHSTMT attachedTo = 0, bool IsCreated = false)
    : Extends(attachedTo, IsCreated) {
    }
    QueryT(const QueryT& copy): Extends(copy) {
    }
    virtual ~QueryT() {
        if (!(this->Destroyed())) {
            patrona::CreateException e(patrona::DestroyFailed);
            CRONO_LOG_ERROR("...throwing patrona::CreateException e(patrona::DestroyFailed)...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(SQLHENV hdbc) {
        if ((hdbc)) {
            SQLHSTMT hstmt = 0;
            if ((hstmt = CreateAttached(hdbc))) {
                this->SetIsCreated();
                return true;
            }
        }
        return false;
    }
    virtual SQLHSTMT CreateAttached(SQLHDBC hdbc) {
        if ((hdbc)) {
            SQLHSTMT hstmt = 0;
            if ((hstmt = CreateDetached(hdbc))) {
                this->Attach(hstmt);
                return hstmt;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Execute(const char* chars) {
        size_t length = 0;

        if ((chars) && (0 < (length = chars_t::count(chars)))) {
            SQLCHARArray qArray(chars, length);
            SQLCHAR* qChars = 0;

            if ((qChars = qArray.has_elements(length))) {
                CharString q(qChars, length);

                CRONO_LOG_DEBUG("Execute(qChars = \"" << q << "\", length)...");
                if ((this->Execute(qChars, length))) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool Execute(SQLCHAR *szSqlStr, SQLINTEGER cbSqlStr) {
        if ((szSqlStr) && (0 < cbSqlStr)) {
            SQLHSTMT hstmt = 0;
            if ((hstmt = this->AttachedTo())) {
                SQLRETURN retcode = SQL_SUCCESS;
                /*/
                SQLRETURN SQLExecDirect
                (SQLHSTMT hstmt,        // Connection handle
                 SQLCHAR FAR *szSqlStr, // SQL statement string
                 SQLINTEGER cbSqlStr);  // Length of SQL statement string
                /*/
                CRONO_LOG_DEBUG("SQLExecDirect(hstmt, szSqlStr, cbSqlStr)...");
                if ((retcode = SQLExecDirect(hstmt, szSqlStr, cbSqlStr)) == SQL_SUCCESS) {
                    return true;
                } else {
                    CRONO_LOG_ERROR("...failed " << retcode << " on SQLExecDirect(hstmt, szSqlStr, cbSqlStr)");
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool TableColumns(const char* tableName) {
        size_t length = 0;

        if ((tableName) && (0 < (length = chars_t::count(tableName)))) {
            UCHARArray ucArray(tableName, length);
            UCHAR* uChars = 0;

            if ((uChars = ucArray.has_elements(length))) {
                CharString s(uChars, length);

                CRONO_LOG_DEBUG("TableColumns(uChars = \"" << s << "\", length)...");
                if ((this->TableColumns(uChars, length))) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool TableColumns
    (UCHAR* szTableName, USHORT cbTableName,
     UCHAR* szColumnName = NULL, USHORT cbColumnName = 0) {
        UCHAR* szCatalogName = NULL; USHORT cbCatalogName = 0;
        UCHAR* szSchemaName = NULL; USHORT cbSchemaName = 0;
        return this->Columns
        (szCatalogName, cbCatalogName, szSchemaName, cbSchemaName,
         szTableName, cbTableName, szColumnName, cbColumnName);
    }
    virtual bool Columns
    (UCHAR* szCatalogName, USHORT cbCatalogName,
     UCHAR* szSchemaName, USHORT cbSchemaName,
     UCHAR* szTableName, USHORT cbTableName,
     UCHAR* szColumnName, USHORT cbColumnName) {
        SQLHSTMT hstmt = 0;
        if ((hstmt = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN   SQLColumns
            (SQLHSTMT          hstmt,          //
             SQLCHAR     FAR   *szCatalogName, // catalog name result set qualifier
             SQLSMALLINT       cbCatalogName,  //
             SQLCHAR     FAR   *szSchemaName,  // schema name result set qualifier
             SQLSMALLINT       cbSchemaName,   //
             SQLCHAR     FAR   *szTableName,   // table name result set qualifier
             SQLSMALLINT       cbTableName,    //
             SQLCHAR     FAR   *szColumnName,  // column name result set qualifier
             SQLSMALLINT       cbColumnName);  //
            /*/
            CRONO_LOG_DEBUG("SQLColumns(hstmt, ...)...");
            if ((retcode = SQLColumns
                 (hstmt, szCatalogName, cbCatalogName, szSchemaName, cbSchemaName,
                  szTableName, cbTableName, szColumnName, cbColumnName)) == SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on SQLColumns(hstmt, ...)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ResultColumns() {
        SQLSMALLINT resultColumns = 0;
        if ((NumResultCols(&resultColumns))) {
            return resultColumns;
        }
        return -1;
    }
    virtual bool NumResultCols(SQLSMALLINT *pccol) {
        SQLHSTMT hstmt = 0;
        if ((hstmt = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN SQLNumResultCols
            (SQLHSTMT hstmt,          // Statement handle
             SQLSMALLINT FAR *pccol); // Pointer to number of result set columns
            /*/
            CRONO_LOG_DEBUG("SQLNumResultCols(hstmt, ...)...");
            if ((retcode = SQLNumResultCols(hstmt, pccol)) == SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on SQLNumResultCols(hstmt, ...)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ColumnLabel(string_t& label, unsigned column) {
        if (0 < (column)) {
            enum { DescMax = 128 };
            SQLUSMALLINT fDescType = SQL_COLUMN_LABEL;
            SQLSMALLINT cbDescMax = (sizeof(SQLCHAR)*(DescMax-1));
            SQLSMALLINT cbDesc = 0;
            SQLLEN fDesc = 0;
            SQLCHAR rgbDesc[DescMax];

            label.clear();
            memset(rgbDesc, 0, sizeof(SQLCHAR)*DescMax);
            if ((ColAttributes
                 (column, fDescType, rgbDesc, cbDescMax, &cbDesc, &fDesc))) {
                size_t length = (0<cbDesc)?(cbDesc):(SQLCHARS::count(rgbDesc));
                char c = 0;

                for (size_t i = 0; i < length; ++i) {
                    c = ((char)rgbDesc[i]);
                    label.append(&c, 1);
                }
                return true;
            }
        }
        return false;
    }
    virtual bool ColumnDisplaySize(size_t& size, unsigned column) {
        if (0 < (column)) {
            SQLUSMALLINT fDescType = SQL_COLUMN_DISPLAY_SIZE;
            SQLSMALLINT cbDescMax = 0;
            SQLSMALLINT cbDesc = 0;
            SQLLEN fDesc = 0;
            SQLCHAR *rgbDesc = 0;

            if ((ColAttributes
                 (column, fDescType, rgbDesc, cbDescMax, &cbDesc, &fDesc))) {
                size = fDesc;
                return true;
            }
        }
        return false;
    }
    virtual bool ColAttributes
    (SQLUSMALLINT icol, SQLUSMALLINT fDescType,
     SQLPOINTER rgbDesc, SQLSMALLINT cbDescMax,
     SQLSMALLINT *pcbDesc, SQLLEN *pfDesc) {
        SQLHSTMT hstmt = 0;
        if ((hstmt = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN SQLColAttributes
            (SQLHSTMT hstmt,           // Statement handle
             SQLUSMALLINT icol,        // Column number in the result set
             SQLUSMALLINT fDescType,   // Attribute buffer data type
             SQLPOINTER rgbDesc,       // Pointer to character attributes buffer
             SQLSMALLINT cbDescMax,    // Length of rgbDesc
             SQLSMALLINT FAR *pcbDesc, // Pointer to number of bytes returned in rgbDesc
             SQLLEN FAR *pfDesc);      // Pointer to number column attributes
            /*/
            CRONO_LOG_DEBUG("SQLColAttributes(hstmt, ...)...");
            if ((retcode = SQLColAttributes
                 (hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc)) == SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on SQLColAttributes(hstmt, ...)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetDataValueChars
    (string_t& value, size_t displaySize, unsigned column) {
        if ((0 < (column)) && (0 < (displaySize))) {
            enum { ValueMax = 128 };
            SQLSMALLINT fCType = SQL_C_CHAR;
            SQLLEN cbValue = 0;
            SQLLEN cbValueMax = sizeof(SQLCHAR)*(ValueMax-1);
            SQLCHAR rgbValue[ValueMax];

            value.clear();
            memset(rgbValue, 0, sizeof(SQLCHAR)*ValueMax);
            if ((GetData(column, fCType, rgbValue, cbValueMax, &cbValue))) {
                size_t length = ((0<cbValue)?(cbValue):(SQLCHARS::count(rgbValue)));
                char c = 0;

                for (size_t i = 0; i < length; ++i) {
                    c = ((char)(rgbValue[i]));
                    value.append(&c, 1);
                }
                return true;
            }
        }
        return false;
    }
    virtual bool GetData
    (SQLUSMALLINT icol, SQLSMALLINT fCType,
     SQLPOINTER rgbValue, SQLLEN cbValueMax, SQLLEN *pcbValue) {
        SQLHSTMT hstmt = 0;
        if ((hstmt = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN SQLGetData
            (SQLHSTMT hstmt,            // Statement handle
             SQLUSMALLINT icol,         // Column number of result set
             SQLSMALLINT fCType,        // C data type of the column
                                        // SQL_C_BIGINT --
                                        // SQL_C_BINARY --
                                        // SQL_C_BINARYXML --
                                        // SQL_C_BIT --
                                        // SQL_C_BLOB_LOCATOR --
                                        // SQL_C_CHAR --
                                        // SQL_C_CLOB_LOCATOR --
                                        // SQL_C_DBCHAR --
                                        // SQL_C_DBCLOB_LOCATOR
                                        // SQL_C_DOUBLE --
                                        // SQL_C_FLOAT --
                                        // SQL_C_DECIMAL64 --
                                        // SQL_C_DECIMAL128 --
                                        // SQL_C_LONG --
                                        // SQL_C_SHORT --
                                        // SQL_C_TYPE_DATE --
                                        // SQL_C_TYPE_TIME --
                                        // SQL_C_TYPE_TIMESTAMP --
                                        // SQL_C_TYPE_TIMESTAMP_EXT --
                                        // SQL_C_TINYINT --
                                        // SQL_C_WCHAR --
                                        // SQL_C_DEFAULT --
             SQLPOINTER rgbValue,       // Points to retrieved column data buffer
             SQLINTEGER cbValueMax,     // Maximum size of buffer
             SQLINTEGER FAR *pcbValue); // Number of bytes in rgbValue
            /*/
            CRONO_LOG_DEBUG("SQLGetData(hstmt, ...)...");
            if ((retcode = SQLGetData
                 (hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue))==SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on SQLGetData(hstmt, ...)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Fetch() {
        SQLHSTMT hstmt = 0;
        if ((hstmt = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN SQLFetch
            (SQLHSTMT hstmt); // Statement handle
            /*/
            CRONO_LOG_DEBUG("SQLFetch(hstmt)...");
            if ((retcode = SQLFetch(hstmt))==SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on SQLFetch(hstmt)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetPos
    (SQLSETPOSIROW RowNumber, SQLUSMALLINT Operation, SQLUSMALLINT LockType) {
        SQLHSTMT hstmt = 0;
        if ((hstmt = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN   SQLSetPos
            (SQLHSTMT StatementHandle, // Statement handle
             SQLSETPOSIROW RowNumber,  // Row for operation (0 is all)
             SQLUSMALLINT Operation,   // Operation to perform
                                       // SQL_POSITION -- position cursor to row RowNumber
                                       // SQL_REFRESH  -- '' and refresh rowset data buffers
                                       // SQL_UPDATE   -- '' and update row with rowset data buffers
                                       // SQL_DELETE   -- '' and delete row
                                       // SQL_ADD      -- '' and add row (deprecated)
             SQLUSMALLINT LockType);   // Lock type on row after operation
                                       // SQL_LOCK_NO_CHANGE -- Keep lock state of row
                                       // SQL_LOCK_EXCLUSIVE -- Lock row exclusively
                                       // SQL_LOCK_UNLOCK    -- Unlock row
            /*/
            CRONO_LOG_DEBUG("SQLSetPos(hstmt, ...)...");
            if ((retcode = SQLSetPos(hstmt, RowNumber, Operation, LockType))==SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on SQLSetPos(hstmt, ...)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SQLHSTMT CreateDetached(SQLHDBC hdbc) const {
        if ((hdbc)) {
            SQLRETURN retcode = SQL_SUCCESS;
            SQLHSTMT hstmt = 0;
            /*/
            SQLRETURN SQLAllocStmt
            (SQLHDBC hdbc,        // Connection handle
             SQLHSTMT FAR *phstmt); // Pointer to a statement handle
            /*/
            CRONO_LOG_DEBUG("SQLAllocStmt(hdbc, &hstmt)...");
            if ((retcode = SQLAllocStmt(hdbc, &hstmt)) == SQL_SUCCESS) {
                return hstmt;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on SQLAllocStmt(hdbc, &hstmt)");
            }
        }
        return 0;
    }
    virtual bool DestroyDetached(SQLHSTMT hstmt) const {
        if ((hstmt)) {
            SQLRETURN retcode = SQL_SUCCESS;
            SQLUSMALLINT fOption = SQL_DROP;
            /*/
            SQLRETURN SQLFreeStmt
            (SQLHSTMT hstmt,        // Statement handle to free
             SQLUSMALLINT fOption); // Manner to free the statement handle
                                    // SQL_UNBIND -- Unbind columns bound by SQLBindCol()
                                    // SQL_RESET_PARAMS -- Release parameters set by SQLBindParameter()
                                    // SQL_CLOSE -- Close cursor and discard all pending results
                                    // SQL_DROP (Deprecated) -- Free statement handle (SQLFreeHandle())
            /*/
            CRONO_LOG_DEBUG("SQLFreeStmt(hstmt)...");
            if ((retcode = SQLFreeStmt(hstmt, fOption)) == SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...fained " << retcode << " on SQLFreeStmt(hstmt)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef QueryT<> Query;

} // namespace odbc 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_QUERY_HPP 
