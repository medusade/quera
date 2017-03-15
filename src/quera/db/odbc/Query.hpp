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
#include "quera/base/Base.hpp"

namespace quera {
namespace db {
namespace odbc {


///////////////////////////////////////////////////////////////////////
///  Class: QueryT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = QueryTImplements, class TExtends = QueryTExtends>
class _EXPORT_CLASS QueryT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    QueryT() {
    }
    virtual ~QueryT() {
    }
};


} // namespace odbc 
} // namespace db 
} // namespace quera 


#endif // _QUERA_DB_ODBC_QUERY_HPP 
        

