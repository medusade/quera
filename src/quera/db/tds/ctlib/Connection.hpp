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
///   Date: 3/28/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_TDS_CTLIB_CONNECTION_HPP
#define _QUERA_DB_TDS_CTLIB_CONNECTION_HPP

#include "quera/db/tds/ctlib/Context.hpp"

namespace quera {
namespace db {
namespace tds {
namespace ctlib {

typedef CS_CONNECTION* ConnectionAttachedTo;

typedef patrona::CreatorT<ImplementBase> ConnectionTCreator;
typedef patrona::AttacherT
<ConnectionAttachedTo, int, 0, ConnectionTCreator> ConnectionTAttacher;
typedef patrona::AttachedT
<ConnectionAttachedTo, int, 0, ConnectionTAttacher, Base> ConnectionTAttached;
typedef patrona::CreatedT
<ConnectionAttachedTo, int, 0, ConnectionTAttacher, ConnectionTAttached> ConnectionTCreated;

typedef ConnectionTAttacher ConnectionTImplements;
typedef ConnectionTCreated ConnectionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ConnectionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ConnectionTImplements, class TExtends = ConnectionTExtends>
class _EXPORT_CLASS ConnectionT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ConnectionT(CS_CONNECTION* attachedTo = 0, bool IsCreated = false)
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
    virtual bool Create(CS_CONTEXT* ctx) {
        CS_CONNECTION* con = 0;

        if ((con = CreateAttached(ctx))) {
            this->SetIsCreated();
            return true;
        }
        return false;
    }
    virtual CS_CONNECTION* CreateAttached(CS_CONTEXT* ctx) {
        CS_CONNECTION* con = 0;

        if ((con = CreateDetached(ctx))) {
            this->Attach(con);
            return con;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const char* chars) {
        size_t length = 0;
        if ((chars) && (0 < (length = chars_t::count(chars)))) {
            CS_CHARArray nameArray(chars, length);
            CS_CHAR* name = 0;
            if ((name = nameArray.has_elements(length))) {
                if ((this->Connect(name, length))) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool Connect(CS_CHAR* name, CS_INT namelen) {
        CS_CONNECTION* con = 0;

        if ((con = this->AttachedTo()) && (name) && (namelen)) {
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_connect(con, name, namelen)...");
            if (CS_SUCCEED == (retcode = ct_connect(con, name, namelen))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_connect(con, name, namelen)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetUser(const char* chars) {
        size_t length = 0;

        if ((chars) && (0 < (length = chars_t::count(chars)))) {
            CS_CHARArray valueArray(chars, length);
            CS_CHAR* valueChars = 0;

            if ((valueChars = valueArray.has_elements(length))) {
                CharString value(valueChars, length);

                CRONO_LOG_DEBUG("SetPropery(CS_USERNAME, value = \"" << value << "\", length)");
                if ((this->SetPropery(CS_USERNAME, valueChars, length))) {
                    return chars;
                }
            }
        }
        return 0;
    }
    virtual const char* SetPassword(const char* chars) {
        size_t length = 0;

        if ((chars) && (0 < (length = chars_t::count(chars)))) {
            CS_CHARArray valueArray(chars, length);
            CS_CHAR* valueChars = 0;

            if ((valueChars = valueArray.has_elements(length))) {
                CharString value(valueChars, length);

                CRONO_LOG_DEBUG("SetPropery(CS_PASSWORD, value = \"" << value << "\", length)");
                if ((this->SetPropery(CS_PASSWORD, valueChars, length))) {
                    return chars;
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetPropery(CS_INT property, CS_VOID* buffer, CS_INT buflen) {
        CS_CONNECTION* con = 0;
        if ((con = this->AttachedTo()) && (buffer) && (buflen)) {
            CS_RETCODE retcode = CS_SUCCEED;
            CS_INT outlen = 0;

            CRONO_LOG_DEBUG("ct_con_props(con, CS_SET, property, buffer, buflen, &outlen)...");
            if (CS_SUCCEED == (retcode = ct_con_props(con, CS_SET, property, buffer, buflen, &outlen))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_con_props(con, CS_SET, property, buffer, buflen, &outlen)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CS_CONNECTION* CreateDetached(CS_CONTEXT* ctx) const {
        if ((ctx)) {
            CS_CONNECTION* con = 0;
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_con_alloc(ctx, &con)...");
            if (CS_SUCCEED == (retcode = ct_con_alloc(ctx, &con))) {
                return con;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_con_alloc(ctx, &con)");
            }
        }
        return 0;
    }
    virtual bool DestroyDetached(CS_CONNECTION* con) const {
        if ((con)) {
            bool success = true;
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_con_drop(con)...");
            if (CS_SUCCEED != (retcode = ct_con_drop(con))) {
                CRONO_LOG_DEBUG("...failed " << retcode << " on ct_con_drop(con)");
                success = false;
            }
            return success;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ConnectionT<> Connection;

} // namespace ctlib
} // namespace tds 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_TDS_CTLIB_CONNECTION_HPP 
