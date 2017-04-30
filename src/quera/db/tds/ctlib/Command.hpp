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
///   File: Command.hpp
///
/// Author: $author$
///   Date: 3/30/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_TDS_CTLIB_COMMAND_HPP
#define _QUERA_DB_TDS_CTLIB_COMMAND_HPP

#include "quera/db/tds/ctlib/Connection.hpp"

namespace quera {
namespace db {
namespace tds {
namespace ctlib {

typedef CS_COMMAND* CommandAttachedTo;

typedef patrona::CreatorT<ImplementBase> CommandTCreator;
typedef patrona::AttacherT
<CommandAttachedTo, int, 0, CommandTCreator> CommandTAttacher;
typedef patrona::AttachedT
<CommandAttachedTo, int, 0, CommandTAttacher, Base> CommandTAttached;
typedef patrona::CreatedT
<CommandAttachedTo, int, 0, CommandTAttacher, CommandTAttached> CommandTCreated;

typedef CommandTAttacher CommandTImplements;
typedef CommandTCreated CommandTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CommandT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = CommandTImplements, class TExtends = CommandTExtends>
class _EXPORT_CLASS CommandT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CommandT(CS_COMMAND* attachedTo = 0, bool IsCreated = false)
    : Extends(attachedTo, IsCreated) {
    }
    CommandT(const CommandT& copy): Extends(copy) {
    }
    virtual ~CommandT() {
        if (!(this->Destroyed())) {
            patrona::CreateException e(patrona::DestroyFailed);
            CRONO_LOG_ERROR("...throwing patrona::CreateException e(patrona::DestroyFailed)...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(CS_CONNECTION* con) {
        CS_COMMAND* cmd = 0;

        if ((cmd = CreateAttached(con))) {
            this->SetIsCreated();
            return true;
        }
        return false;
    }
    virtual CS_COMMAND* CreateAttached(CS_CONNECTION* con) {
        CS_COMMAND* cmd = 0;

        if ((cmd = CreateDetached(con))) {
            this->Attach(cmd);
            return cmd;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetStatement(const char* chars) {
        size_t length = 0;

        if ((chars) && (0 < (length = chars_t::count(chars)))) {
            CS_CHARArray valueArray(chars, length);
            CS_CHAR* valueChars = 0;

            if ((valueChars = valueArray.has_elements(length))) {
                CharString value(valueChars, length);

                CRONO_LOG_DEBUG("SetCommand(CS_LANG_CMD, value = \"" << value << "\", length, CS_UNUSED)");
                if ((this->SetCommand(CS_LANG_CMD, valueChars, length, CS_UNUSED))) {
                    return chars;
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetCommand
    (CS_INT type, CS_VOID* buffer, CS_INT buflen, CS_INT option) {
        CS_COMMAND* cmd = 0;
        if ((cmd = this->AttachedTo()) && (buffer) && (buflen)) {
            CS_RETCODE retcode = CS_SUCCEED;
            CS_INT outlen = 0;

            CRONO_LOG_DEBUG("ct_command(cmd, type, buffer, buflen, option)...");
            if (CS_SUCCEED == (retcode = ct_command(cmd, type, buffer, buflen, option))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_command(con, type, buffer, buflen, option)");
            }
        }
        return false;
    }
    virtual bool Send() {
        CS_COMMAND* cmd = 0;
        if ((cmd = this->AttachedTo())) {
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_send(cmd)...");
            if (CS_SUCCEED == (retcode = ct_send(cmd))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_send(con)");
            }
        }
        return false;
    }
    virtual bool Results(CS_INT& type) {
        CS_COMMAND* cmd = 0;
        if ((cmd = this->AttachedTo())) {
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_results(cmd, &type)...");
            if (CS_SUCCEED == (retcode = ct_results(cmd, &type))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_results(con, &type)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ResultColumns(CS_INT& cols) {
        CS_INT outlen = 0;
        CRONO_LOG_DEBUG("ResultInfo(CS_NUMDATA, &cols, CS_UNUSED, &outlen)...");
        if ((ResultInfo(CS_NUMDATA, &cols, CS_UNUSED, outlen))) {
            return true;
        }
        return false;
    }
    virtual bool ResultInfo
    (CS_INT type, CS_VOID* buffer, CS_INT buflen, CS_INT& outlen) {
        CS_COMMAND* cmd = 0;
        if ((cmd = this->AttachedTo()) && (buffer) && (buflen)) {
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_res_info(cmd, type, buffer, buflen, &outlen)...");
            if (CS_SUCCEED == (retcode = ct_res_info(cmd, type, buffer, buflen, &outlen))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_res_info(con, type, buffer, buflen, &outlen)");
            }
        }
        return false;
    }
    virtual bool GetData(CharString& value, size_t valueSize, CS_INT item) {
        CS_CHAR* valueChars = 0;
        CS_CHARArray valueArray;

        if (0 < (valueSize = valueArray.set_size(valueSize))) {
            if ((valueChars = valueArray.elements())) {
                CS_INT outlen = 0;

                if ((GetData(true, item, valueChars, valueSize, outlen))) {
                    value.clear();
                    do {
                        value.Append(valueChars, outlen);
                    } while (GetData(false, item, valueChars, valueSize, outlen));
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool GetData(CS_INT& value, CS_INT item) {
        CS_INT outlen = 0;
        if ((GetData(true, item, &value, sizeof(value), outlen))) {
            return true;
        }
        return false;
    }
    virtual bool GetData(CS_FLOAT& value, CS_INT item) {
        CS_INT outlen = 0;
        if ((GetData(true, item, &value, sizeof(value), outlen))) {
            return true;
        }
        return false;
    }
    virtual bool GetData(CS_DATETIME& value, CS_INT item) {
        CS_INT outlen = 0;
        if ((GetData(true, item, &value, sizeof(value), outlen))) {
            return true;
        }
        return false;
    }
    virtual bool GetData
    (bool firstItem, CS_INT item, CS_VOID* buffer, CS_INT buflen, CS_INT& outlen) {
        CS_COMMAND* cmd = 0;
        if ((cmd = this->AttachedTo()) && (buffer) && (buflen)) {
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_get_data(cmd, item, buffer, buflen, &outlen)...");
            if (CS_SUCCEED == (retcode = ct_get_data(cmd, item, buffer, buflen, &outlen))) {
                return true;
            } else {
                if ((CS_END_ITEM == (retcode)) && (firstItem)) {
                    return true;
                } else {
                    if ((CS_END_DATA == (retcode)) && (firstItem)) {
                        return true;
                    } else {
                        CRONO_LOG_ERROR("...failed " << retcode << " on ct_get_data(con, item, buffer, buflen, &outlen = " << outlen << ")");
                    }
                }
            }
        }
        return false;
    }
    virtual bool Describe(CS_INT item, CS_DATAFMT& type) {
        CS_COMMAND* cmd = 0;
        if ((cmd = this->AttachedTo())) {
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_describe(cmd, item, &type)...");
            if (CS_SUCCEED == (retcode = ct_describe(cmd, item, &type))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_describe(con, item, &type)");
            }
        }
        return false;
    }
    virtual bool Bind
    (CS_INT item, CS_DATAFMT& type, CS_VOID* buffer, CS_INT& copied, CS_SMALLINT& indicator) {
        CS_COMMAND* cmd = 0;
        if ((cmd = this->AttachedTo()) && (buffer)) {
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_bind(cmd, item, &type, buffer, &copied, &indicator)...");
            if (CS_SUCCEED == (retcode = ct_bind(cmd, item, &type, buffer, &copied, &indicator))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_bind(cmd, item, &type, buffer, &copied, &indicator)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Fetch(CS_INT& rows) {
        CRONO_LOG_DEBUG("Fetch(CS_UNUSED, CS_UNUSED, CS_UNUSED, rows)...");
        if ((Fetch(CS_UNUSED, CS_UNUSED, CS_UNUSED, rows))) {
            CRONO_LOG_DEBUG("...Fetch(CS_UNUSED, CS_UNUSED, CS_UNUSED, rows = " << rows << ")");
            return true;
        }
        return false;
    }
    virtual bool Fetch(CS_INT type, CS_INT offset, CS_INT option, CS_INT& rows) {
        CS_COMMAND* cmd = 0;
        if ((cmd = this->AttachedTo())) {
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_fetch(cmd, type, offset, option, &rows)...");
            if (CS_SUCCEED == (retcode = ct_fetch(cmd, type, offset, option, &rows))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_fetch(cmd, type, offset, option, &rows)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetPropery(CS_INT property, CS_VOID* buffer, CS_INT buflen) {
        CS_COMMAND* cmd = 0;
        if ((cmd = this->AttachedTo()) && (buffer) && (buflen)) {
            CS_RETCODE retcode = CS_SUCCEED;
            CS_INT outlen = 0;

            CRONO_LOG_DEBUG("ct_cmd_props(cmd, CS_SET, property, buffer, buflen, &outlen)...");
            if (CS_SUCCEED == (retcode = ct_cmd_props(cmd, CS_SET, property, buffer, buflen, &outlen))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << retcode << " on ct_cmd_props(con, CS_SET, property, buffer, buflen, &outlen)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CS_COMMAND* CreateDetached(CS_CONNECTION* con) const {
        if ((con)) {
            CS_COMMAND* cmd = 0;
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_cmd_alloc(con, &cmd)...");
            if (CS_SUCCEED == (retcode = ct_cmd_alloc(con, &cmd))) {
                return cmd;
            } else {
                CRONO_LOG_ERROR("...failed retcode = " << retcode << " on ct_cmd_alloc(con, &cmd)");
            }
        }
        return 0;
    }
    virtual bool DestroyDetached(CS_COMMAND* cmd) const {
        if ((cmd)) {
            bool success = true;
            CS_RETCODE retcode = CS_SUCCEED;

            CRONO_LOG_DEBUG("ct_cmd_drop(cmd)...");
            if (CS_SUCCEED != (retcode = ct_cmd_drop(cmd))) {
                CRONO_LOG_ERROR("...failed retcode = " << retcode << " on t_cmd_drop(cmd)");
                success = false;
            }
            return success;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CommandT<> Command;

} // namespace ctlib
} // namespace tds 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_TDS_CTLIB_COMMAND_HPP 
