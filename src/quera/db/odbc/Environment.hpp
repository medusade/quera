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
///   File: Environment.hpp
///
/// Author: $author$
///   Date: 3/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_ODBC_ENVIRONMENT_HPP
#define _QUERA_DB_ODBC_ENVIRONMENT_HPP

#include "quera/db/odbc/Object.hpp"

namespace quera {
namespace db {
namespace odbc {

typedef SQLHENV EnvironmentAttachedTo;

typedef patrona::CreatorT<ImplementBase> EnvironmentTCreator;
typedef patrona::AttacherT
<EnvironmentAttachedTo, int, 0, EnvironmentTCreator> EnvironmentTAttacher;
typedef patrona::AttachedT
<EnvironmentAttachedTo, int, 0, EnvironmentTAttacher, Object> EnvironmentTAttached;
typedef patrona::CreatedT
<EnvironmentAttachedTo, int, 0, EnvironmentTAttacher, EnvironmentTAttached> EnvironmentTCreated;

typedef EnvironmentTAttacher EnvironmentTImplements;
typedef EnvironmentTCreated EnvironmentTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: EnvironmentT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = EnvironmentTImplements, class TExtends = EnvironmentTExtends>

class _EXPORT_CLASS EnvironmentT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    EnvironmentT(SQLHENV attachedTo = 0, bool IsCreated = false)
    : Extends(attachedTo, IsCreated) {
    }
    EnvironmentT(const EnvironmentT& copy): Extends(copy) {
    }
    virtual ~EnvironmentT() {
        if (!(this->Destroyed())) {
            patrona::CreateException e(patrona::DestroyFailed);
            CRONO_LOG_ERROR("...throwing patrona::CreateException e(patrona::DestroyFailed)...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SQLHENV CreateDetached() const {
        SQLRETURN retcode = SQL_SUCCESS;
        SQLHENV henv = 0;
        /*/
        SQLRETURN SQLAllocEnv
        (SQLHENV FAR *phenv); // Environment handle to allocate
        /*/
        CRONO_LOG_DEBUG("SQLAllocEnv(&henv)...");
        if ((retcode = SQLAllocEnv(&henv)) == SQL_SUCCESS) {
            return henv;
        } else {
            CRONO_LOG_ERROR("...failed " << retcode << " on SQLAllocEnv(&henv)");
        }
        return 0;
    }
    virtual bool DestroyDetached(SQLHENV henv) const {
        SQLRETURN retcode = SQL_SUCCESS;
        if ((henv)) {
            /*/
            SQLRETURN SQLFreeEnv
            (SQLHENV henv); // Environment handle to free
            /*/
            CRONO_LOG_DEBUG("SQLFreeEnv(henv)...");
            if ((retcode = SQLFreeEnv(henv)) == SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...fained " << retcode << " on SQLFreeEnv(henv)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Error
    (SQLHDBC hdbc, SQLHSTMT hstmt,
     SQLCHAR *szSqlState, SQLINTEGER *pfNativeError,
     SQLCHAR *szErrorMsg, SQLSMALLINT cbErrorMsgMax, SQLSMALLINT *pcbErrorMsg) const {
        SQLHENV henv = 0;
        if ((henv = this->AttachedTo())) {
            SQLRETURN retcode = SQL_SUCCESS;
            /*/
            SQLRETURN SQLError
            (SQLHENV           henv,           // Environment handle
             SQLHDBC           hdbc,           // Database connection handle
             SQLHSTMT          hstmt,          // Statement handle
             SQLCHAR     FAR   *szSqlState,    // SQLSTATE as a string of 5 characters
             SQLINTEGER  FAR   *pfNativeError, // Native error code
             SQLCHAR     FAR   *szErrorMsg,    // Error message text
             SQLSMALLINT       cbErrorMsgMax,  // Error message text size
             SQLSMALLINT FAR   *pcbErrorMsg);  // Error message text length
            /*/
            CRONO_LOG_DEBUG("SQLError(henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg)...");
            if ((retcode = SQLError
                 (henv, hdbc, hstmt, szSqlState, pfNativeError,
                  szErrorMsg, cbErrorMsgMax, pcbErrorMsg)) == SQL_SUCCESS) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed retcode = " << retcode << " on SQLError(henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef EnvironmentT<> Environment;

} // namespace odbc 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_ODBC_ENVIRONMENT_HPP 
