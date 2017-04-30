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
#   File: tdscgi.pri
#
# Author: $author$
#   Date: 4/29/2017
########################################################################

tdscgi_TARGET = quera-tds-cgi

########################################################################
tdscgi_INCLUDEPATH += \
$${quera_INCLUDEPATH} \
$${porta_INCLUDEPATH} \
$${crono_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \

tdscgi_DEFINES += \
$${framework_DEFINES} \
$${quera_DEFINES} \

########################################################################
tdscgi_HEADERS += \
$${QUERA_SRC}/quera/db/tds/ctlib/CGIMain.hpp \
$${QUERA_SRC}/quera/console/Main_main.hpp \

tdscgi_SOURCES += \
$${QUERA_SRC}/quera/db/tds/ctlib/CGIMain.cpp \
$${QUERA_SRC}/quera/console/Main_main.cpp \

########################################################################
tdscgi_LIBS += \
$${nadir_LIBS} \
