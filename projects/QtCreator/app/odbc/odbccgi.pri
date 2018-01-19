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
#   File: odbccgi.pri
#
# Author: $author$
#   Date: 4/30/2017
########################################################################

odbccgi_TARGET = quera-odbc-cgi

########################################################################
odbccgi_INCLUDEPATH += \
$${quera_INCLUDEPATH} \
$${porta_INCLUDEPATH} \
$${crono_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${unixODBC_INCLUDEPATH} \

odbccgi_DEFINES += \
$${framework_DEFINES} \
$${quera_DEFINES} \
$${unixODBC_DEFINES} \

########################################################################
odbccgi_HEADERS += \
$${QUERA_SRC}/quera/db/odbc/CGIMain.hpp \
$${QUERA_SRC}/quera/console/Main_main.hpp \

odbccgi_SOURCES += \
$${QUERA_SRC}/quera/db/odbc/CGIMain.cpp \
$${QUERA_SRC}/quera/console/Main_main.cpp \

########################################################################
odbccgi_LIBS += \
$${nadir_LIBS} \
$${unixODBC_LIBS} \


