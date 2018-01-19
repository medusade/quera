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
#   File: odbccgi.pro
#
# Author: $author$
#   Date: 4/30/2017
########################################################################
include(../../../../QtCreator/framework.pri)
include(../../framework.pri)
include(../../../../QtCreator/quera.pri)
include(../../quera.pri)
include(../../../../QtCreator/porta.pri)
include(../../porta.pri)
include(../../../../QtCreator/crono.pri)
include(../../crono.pri)
include(../../../../QtCreator/patrona.pri)
include(../../patrona.pri)
include(../../../../QtCreator/nadir.pri)
include(../../nadir.pri)
include(../../../../QtCreator/unixODBC.pri)
include(../../unixODBC.pri)
include(../../../../QtCreator/app/odbc/odbccgi.pri)

TARGET = $${odbccgi_TARGET}

########################################################################
INCLUDEPATH += \
$${odbccgi_INCLUDEPATH} \

DEFINES += \
$${odbccgi_DEFINES} \

########################################################################
HEADERS += \
$${odbccgi_HEADERS} \

SOURCES += \
$${odbccgi_SOURCES} \

########################################################################
LIBS += \
$${odbccgi_LIBS} \

