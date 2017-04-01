########################################################################
# Copyright (c) 1988-2017 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: odbc.pri
#
# Author: $author$
#   Date: 3/12/2017
########################################################################

odbc_TARGET = quera-odbc

########################################################################
odbc_INCLUDEPATH += \
$${quera_INCLUDEPATH} \
$${crono_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \

odbc_DEFINES += \
$${framework_DEFINES} \
$${quera_DEFINES} \

########################################################################
odbc_HEADERS += \
$${QUERA_SRC}/quera/db/tds/ctlib/Context.hpp \
$${QUERA_SRC}/quera/db/tds/ctlib/CTLib.hpp \

odbc_SOURCES += \
$${QUERA_SRC}/quera/db/tds/ctlib/Context.cpp \
$${QUERA_SRC}/quera/db/tds/ctlib/CTLib.cpp \

########################################################################
odbc_HEADERS += \
$${QUERA_SRC}/quera/db/odbc/Query.hpp \
$${QUERA_SRC}/quera/db/odbc/Connection.hpp \
$${QUERA_SRC}/quera/db/odbc/Environment.hpp \
$${QUERA_SRC}/quera/db/odbc/Object.hpp \
$${QUERA_SRC}/quera/db/odbc/Main.hpp \
$${QUERA_SRC}/quera/db/odbc/ODBC.hpp \
$${QUERA_SRC}/quera/base/Base.hpp \

odbc_SOURCES += \
$${QUERA_SRC}/quera/db/odbc/Query.cpp \
$${QUERA_SRC}/quera/db/odbc/Connection.cpp \
$${QUERA_SRC}/quera/db/odbc/Environment.cpp \
$${QUERA_SRC}/quera/db/odbc/Object.cpp \
$${QUERA_SRC}/quera/db/odbc/Main.cpp \
$${QUERA_SRC}/quera/db/odbc/ODBC.cpp \
$${QUERA_SRC}/quera/base/Base.cpp \

########################################################################
odbc_LIBS += \
$${nadir_LIBS} \
