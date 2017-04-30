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
///   File: Context.hpp
///
/// Author: $author$
///   Date: 3/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_TDS_CTLIB_CONTEXT_HPP
#define _QUERA_DB_TDS_CTLIB_CONTEXT_HPP

#include "quera/db/tds/ctlib/CTLib.hpp"

namespace quera {
namespace db {
namespace tds {
namespace ctlib {

typedef CS_CONTEXT* ContextAttachedTo;

typedef patrona::CreatorT<ImplementBase> ContextTCreator;
typedef patrona::AttacherT
<ContextAttachedTo, int, 0, ContextTCreator> ContextTAttacher;
typedef patrona::AttachedT
<ContextAttachedTo, int, 0, ContextTAttacher, Base> ContextTAttached;
typedef patrona::CreatedT
<ContextAttachedTo, int, 0, ContextTAttacher, ContextTAttached> ContextTCreated;

typedef ContextTAttacher ContextTImplements;
typedef ContextTCreated ContextTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ContextT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ContextTImplements, class TExtends = ContextTExtends>
class _EXPORT_CLASS ContextT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ContextT(CS_CONTEXT* attachedTo = 0, bool IsCreated = false)
    : Extends(attachedTo, IsCreated) {
    }
    ContextT(const ContextT& copy): Extends(copy) {
    }
    virtual ~ContextT() {
        if (!(this->Destroyed())) {
            patrona::CreateException e(patrona::DestroyFailed);
            CRONO_LOG_ERROR("...throwing patrona::CreateException e(patrona::DestroyFailed)...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create() {
        CS_INT version = this->Version();
        return this->Create(version);
    }
    virtual CS_CONTEXT* CreateAttached() {
        CS_INT version = this->Version();
        return this->CreateAttached(version);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(CS_INT version) {
        CS_CONTEXT* ctx = 0;
        if ((ctx = CreateAttached(version))) {
            this->SetIsCreated();
            return true;
        }
        return false;
    }
    virtual CS_CONTEXT* CreateAttached(CS_INT version) {
        CS_CONTEXT* ctx = 0;
        if ((ctx = CreateDetached(version))) {
            this->Attach(ctx);
            return ctx;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Convert
    (CharString& to, size_t toSize, CS_DATETIME& from) {
        CS_CHAR* valueChars = 0;
        CS_CHARArray valueArray;

        if (0 < (toSize = valueArray.set_size(toSize))) {
            if ((valueChars = valueArray.elements())) {
                CS_INT resultlen = 0;
                CS_DATAFMT srcfmt, destfmt;

                memset(&srcfmt, 0, sizeof(srcfmt));
                memset(&destfmt, 0, sizeof(destfmt));
                srcfmt.datatype = CS_DATETIME_TYPE;
                destfmt.datatype = CS_CHAR_TYPE;
                destfmt.maxlength = toSize;
                if ((Convert(srcfmt, &from, destfmt, valueChars, resultlen))) {
                    to.Assign(valueChars, resultlen);
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool Convert
    (CS_DATAFMT& srcfmt, CS_VOID* srcdata,
     CS_DATAFMT& destfmt, CS_VOID* destdata, CS_INT& resultlen) {
        CS_CONTEXT* ctx = 0;

        if ((ctx = this->AttachedTo()) && (srcdata) && (destdata)) {
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("cs_convert(ctx, &srcfmt, srcdata, &destfmt, destdata, &resultlen)...");
            if (CS_SUCCEED == (retcode = cs_convert(ctx, &srcfmt, srcdata, &destfmt, destdata, &resultlen))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed retcode = " << retcode << " on cs_convert(ctx, &srcfmt, srcdata, &destfmt, destdata, &resultlen)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CS_CONTEXT* CreateDetached(CS_INT version) const {
        CS_RETCODE retcode = CS_SUCCEED;
        CS_CONTEXT* ctx = 0;

        CRONO_LOG_DEBUG("cs_ctx_alloc(version, &ctx)...");
        if (CS_SUCCEED == (retcode = cs_ctx_alloc(version, &ctx))) {

            CRONO_LOG_DEBUG("ct_init(ctx, version)...");
            if (CS_SUCCEED == (retcode = ct_init(ctx, version))) {
                return ctx;
            } else {
                CRONO_LOG_DEBUG("...failed retcode = " << retcode << " on ct_init(ctx, version)");
            }
            CRONO_LOG_DEBUG("cs_ctx_drop(ctx)...");
            if (CS_SUCCEED != (retcode = cs_ctx_drop(ctx))) {
                CRONO_LOG_DEBUG("...failed retcode = " << retcode << " on cs_ctx_drop(ctx)");
            }
        } else {
            CRONO_LOG_ERROR("...failed retcode = " << retcode << " on cs_ctx_alloc(version, &ctx)");
        }
        return 0;
    }
    virtual bool DestroyDetached(CS_CONTEXT* ctx) const {
        if ((ctx)) {
            bool success = true;
            CS_RETCODE retcode = CS_SUCCEED;
            CS_INT unused = 0;

            CRONO_LOG_DEBUG("ct_exit(ctx, unused)...");
            if (CS_SUCCEED != (retcode = ct_exit(ctx, unused))) {
                CRONO_LOG_DEBUG("...failed retcode = " << retcode << " on ct_exit(ctx, unused)");
                success = false;
            }
            CRONO_LOG_DEBUG("cs_ctx_drop(ctx)...");
            if (CS_SUCCEED != (retcode = cs_ctx_drop(ctx))) {
                CRONO_LOG_DEBUG("...failed retcode = " << retcode << " on cs_ctx_drop(ctx)");
                success = false;
            }
            return success;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CS_INT Version() const {
        CS_INT version = CS_VERSION_100;
        return version;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ContextT<> Context;

} // namespace ctlib 
} // namespace tds 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_TDS_CTLIB_CONTEXT_HPP 
        

