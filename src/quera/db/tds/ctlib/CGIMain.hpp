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
///   File: CGIMain.hpp
///
/// Author: $author$
///   Date: 4/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _QUERA_DB_TDS_CTLIB_CGIMAIN_HPP
#define _QUERA_DB_TDS_CTLIB_CGIMAIN_HPP

#include "quera/db/CGIMain.hpp"
#include "quera/db/tds/ctlib/Main.hpp"

namespace quera {
namespace db {
namespace tds {
namespace ctlib {

typedef ctlib::MainT
<db::CGIMainTImplements, db::CGIMain> CGIMain;

} // namespace ctlib 
} // namespace tds 
} // namespace db 
} // namespace quera 

#endif // _QUERA_DB_TDS_CTLIB_CGIMAIN_HPP 
