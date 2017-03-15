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
///   File: Connection.hpp
///
/// Author: $author$
///   Date: 3/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_ODBC_CONNECTION_HPP
#define _QUERA_DB_ODBC_CONNECTION_HPP

#include "quera/db/odbc/Environment.hpp"

namespace quera {
namespace db {
namespace odbc {

typedef SQLHDBC ConnectionAttachedTo;

typedef patrona::CreatorT<ImplementBase> ConnectionTCreator;
typedef patrona::AttacherT
<ConnectionAttachedTo, int, 0, ConnectionTCreator> ConnectionTAttacher;
typedef patrona::AttachedT
<ConnectionAttachedTo, int, 0, ConnectionTAttacher, Object> ConnectionTAttached;
typedef patrona::CreatedT
<ConnectionAttachedTo, int, 0, ConnectionTAttacher, ConnectionTAttached> ConnectionTCreated;

typedef ConnectionTAttacher ConnectionTImplements;
typedef ConnectionTCreated ConnectionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ConnectionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ConnectionTImplements, class TExtends = ConnectionTExtends>

class _EXPORT_CLASS ConnectionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ConnectionT(SQLHDBC attachedTo = 0, bool IsCreated = false)
    : Extends(attachedTo, IsCreated) {
    }
    ConnectionT(const ConnectionT& copy): Extends(copy) {
    }
    virtual ~ConnectionT() {
        if (!(this->Destroyed())) {
            patrona::CreateException e(patrona::DestroyFailed);
            CRONO_LOG_ERROR("...throwing patrona::CreateException e(patrona::DestroyFailed)...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(SQLHENV henv) {
        if ((henv)) {
            SQLHDBC hdbc = 0;
            if ((hdbc = CreateAttached(henv))) {
                this->SetIsCreated();
                return true;
            }
        }
        return false;
    }
    virtual SQLHDBC CreateAttached(SQLHENV henv) {
        if ((henv)) {
            SQLHDBC hdbc = 0;
            if ((hdbc = CreateDetached(henv))) {
                this->Attach(hdbc);
                return hdbc;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetConnectOption
    (SQLUSMALLINT fOption, SQLUINTEGER vParam) {
        SQLHDBC hdbc = 0;
        if ((hdbc = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN SQLSetConnectOption
            (SQLHDBC           hdbc,    // Connection handle
             SQLUSMALLINT      fOption, // Connect attribute to set
             SQLUINTEGER       vParam); // 32 bit integer or pointer to string
            /*/
            CRONO_LOG_DEBUG("SQLSetConnectOption(hdbc, fOption, vParam)...");
            if (SQL_SUCCESS == (retcode = SQLSetConnectOption(hdbc, fOption, vParam))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed retcode = " << retcode << " on SQLSetConnectOption(hdbc, fOption, vParam)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const char *szDSN) {
        size_t dsnLength = 0;

        if ((szDSN) && (0 < (dsnLength = chars_t::count(szDSN)))) {
            SQLCHAR *dsnChars = 0;
            SQLCHARArray dsnArray;

            for (SQLCHAR dsnChar = 0; dsnLength; --dsnLength) {
                dsnChar = ((SQLCHAR)(*szDSN));
                dsnArray.append(&dsnChar, 1);
            }
            if ((dsnChars = dsnArray.has_elements(dsnLength))) {
                if ((this->Connect(dsnChars, dsnLength))) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool Connect(SQLCHAR *szDSN, SQLSMALLINT cbDSN) {
        if ((this->Connect(szDSN, cbDSN, NULL, 0, NULL, 0))) {
            return true;
        }
        return false;
    }
    virtual bool Connect
    (SQLCHAR *szDSN, SQLSMALLINT cbDSN,
     SQLCHAR *szUID, SQLSMALLINT cbUID,
     SQLCHAR *szAuthStr, SQLSMALLINT cbAuthStr) {
        SQLHDBC hdbc = 0;
        if ((hdbc = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN SQLConnect
            (SQLHDBC           hdbc,       // Connection handle
             SQLCHAR     FAR   *szDSN,     // Data source name
             SQLSMALLINT       cbDSN,      // Length of DSN
             SQLCHAR     FAR   *szUID,     // Authorization/User name
             SQLSMALLINT       cbUID,      // Length of UID
             SQLCHAR     FAR   *szAuthStr, // Authentication/password string
             SQLSMALLINT       cbAuthStr); // Length of AuthStr
            /*/
            CRONO_LOG_DEBUG("SQLConnect(hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr)...");
            if (SQL_SUCCESS == (retcode = SQLConnect
                (hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed retcode = " << retcode << " on SQLConnect(hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr)");
            }
        }
        return false;
    }
    virtual bool Disconnect() {
        SQLHDBC hdbc = 0;
        if ((hdbc = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN SQLDisconnect
            (SQLHDBC hdbc); // Connection handle
            /*/
            CRONO_LOG_DEBUG("SQLDisconnect(hdbc)...");
            if (SQL_SUCCESS == (retcode = SQLDisconnect(hdbc))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed retcode = " << retcode << " on SQLDisconnect(hdbc)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SQLHDBC CreateDetached(SQLHENV henv) const {
        if ((henv)) {
            SQLRETURN retcode = SQL_SUCCESS;
            SQLHDBC hdbc = 0;
            /*/
            SQLRETURN SQLAllocConnect
            (SQLHENV henv,        // Environment handle
             SQLHDBC FAR *phdbc); // Pointer to a connection handle
            /*/
            CRONO_LOG_DEBUG("SQLAllocConnect(henv, &hdbc)...");
            if ((retcode = SQLAllocConnect(henv, &hdbc)) == SQL_SUCCESS) {
                return hdbc;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on SQLAllocConnect(henv, &hdbc)");
            }
        }
        return 0;
    }
    virtual bool DestroyDetached(SQLHDBC hdbc) const {
        SQLRETURN retcode = SQL_SUCCESS;
        if ((hdbc)) {
            /*/
            SQLRETURN SQLFreeConnect
            (SQLHDBC hdbc); // Connection handle to free
            /*/
            CRONO_LOG_DEBUG("SQLFreeConnect(hdbc)...");
            if ((retcode = SQLFreeConnect(hdbc)) == SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...fained " << retcode << " on SQLFreeConnect(hdbc)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ConnectionT<> Connection;

} // namespace odbc 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_CONNECTION_HPP 
