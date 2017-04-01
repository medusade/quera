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
///   File: CTLib.hpp
///
/// Author: $author$
///   Date: 3/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_TDS_CTLIB_CTLIB_HPP
#define _QUERA_DB_TDS_CTLIB_CTLIB_HPP

#include "quera/base/Base.hpp"
#include "patrona/cpp/xos/base/Created.hpp"
#include "patrona/cpp/xos/base/Attached.hpp"
#include <ctpublic.h>

namespace quera {
namespace db {
namespace tds {
namespace ctlib {

typedef nadir::charst<CS_CHAR> CS_CHARS;

typedef CharArrayT<CS_CHAR> CS_CHARArray;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <typename TChar, class TExtends = nadir::char_stringt<TChar> >
class _EXPORT_CLASS CharStringT: public TExtends {
public:
    typedef TExtends Extends;
    typedef TChar Char;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CharStringT(const CS_CHAR* chars) {
        this->Append(chars);
    }
    CharStringT(const CS_CHAR* chars, size_t length) {
        this->Append(chars, length);
    }
    CharStringT(const CharStringT& copy): Extends(copy) {
    }
    CharStringT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CharStringT& Assign(const CS_CHAR* chars) {
        this->clear();
        this->Append(chars);
        return *this;
    }
    virtual CharStringT& Assign(const CS_CHAR* chars, size_t length) {
        this->clear();
        this->Append(chars, length);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CharStringT& Append(const CS_CHAR* chars) {
        this->Append(chars, CS_CHARS::count(chars));
        return *this;
    }
    virtual CharStringT& Append(const CS_CHAR* chars, size_t length) {
        if ((chars) && (length)) {
            for (Char c = 0; length; --length, ++chars) {
                c = ((Char)(*chars));
                this->append(&c, 1);
            }
        }
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef CharStringT<char> CharString;
typedef CharStringT<tchar_t> TCharString;
typedef CharStringT<wchar_t> WCharString;

} // namespace ctlib
} // namespace tds 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_TDS_CTLIB_CTLIB_HPP 
