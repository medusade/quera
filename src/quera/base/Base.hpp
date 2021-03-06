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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 3/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_BASE_BASE_HPP
#define _QUERA_BASE_BASE_HPP

#include "nadir/base/chars.hpp"
#include "nadir/base/array.hpp"
#include "nadir/base/string.hpp"
#include "crono/io/Logger.hpp"

namespace quera {

typedef nadir::implement_base ImplementBase;
typedef nadir::base Base;

typedef nadir::chars_t chars_t;
typedef nadir::tchars_t tchars_t;
typedef nadir::wchars_t wchars_t;

typedef nadir::char_string string_t;
typedef nadir::tchar_string tstring_t;
typedef nadir::wchar_string wstring_t;

typedef nadir::char_array char_array;
typedef nadir::tchar_array tchar_array;
typedef nadir::wchar_array wchar_array;

typedef string_t String;
typedef tstring_t TString;
typedef wstring_t WString;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <typename TChar, class TExtends = nadir::arrayt<TChar> >
class _EXPORT_CLASS CharArrayT: public TExtends {
public:
    typedef TExtends Extends;
    typedef TChar Char;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CharArrayT(const char* chars) {
        this->Append(chars);
    }
    CharArrayT(const char* chars, size_t length) {
        this->Append(chars, length);
    }
    CharArrayT(const CharArrayT& copy): Extends(copy) {
    }
    CharArrayT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CharArrayT& Assign(const char* chars) {
        this->clear();
        this->Append(chars);
        return *this;
    }
    virtual CharArrayT& Assign(const char* chars, size_t length) {
        this->clear();
        this->Append(chars, length);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CharArrayT& Append(const char* chars) {
        this->Append(chars, chars_t::count(chars));
        return *this;
    }
    virtual CharArrayT& Append(const char* chars, size_t length) {
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

} // namespace quera

#endif // _QUERA_BASE_BASE_HPP 
