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
#   File: tds.pri
#
# Author: $author$
#   Date: 3/28/2017
########################################################################

tds_TARGET = quera-tds

########################################################################
tds_INCLUDEPATH += \
$${quera_INCLUDEPATH} \
$${crono_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \

tds_DEFINES += \
$${framework_DEFINES} \
$${quera_DEFINES} \

########################################################################
tds_HEADERS += \
$${QUERA_SRC}/quera/db/tds/ctlib/Command.hpp \
$${QUERA_SRC}/quera/db/tds/ctlib/Connection.hpp \
$${QUERA_SRC}/quera/db/tds/ctlib/Context.hpp \
$${QUERA_SRC}/quera/db/tds/ctlib/CTLib.hpp \

tds_SOURCES += \
$${QUERA_SRC}/quera/db/tds/ctlib/Command.cpp \
$${QUERA_SRC}/quera/db/tds/ctlib/Connection.cpp \
$${QUERA_SRC}/quera/db/tds/ctlib/Context.cpp \
$${QUERA_SRC}/quera/db/tds/ctlib/CTLib.cpp \

########################################################################
tds_HEADERS += \
$${QUERA_SRC}/quera/db/tds/ctlib/Main.hpp \
$${QUERA_SRC}/quera/db/Main.hpp \
$${QUERA_SRC}/quera/db/MainOpt.hpp \

tds_SOURCES += \
$${QUERA_SRC}/quera/db/tds/ctlib/Main.cpp \

########################################################################
tds_LIBS += \
$${nadir_LIBS} \
