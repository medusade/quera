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
#   File: unixODBC.pri
#
# Author: $author$
#   Date: 3/13/2017
########################################################################

########################################################################
# unixODBC
_unixODBC_INCLUDEPATH += \
/usr/local/include \

unixODBC_INCLUDEPATH += \
$${BUILD_HOME}/build/unixODBC/include \

unixODBC_DEFINES += \

########################################################################
unixODBC_HEADERS += \

unixODBC_SOURCES += \

########################################################################
_unixODBC_LIBS += \
-L/usr/local/lib \
-lodbc \
-lodbcinst \
-lct \

unixODBC_LIBS += \
-L$${BUILD_HOME_BLD}/build/unixODBC/lib \
-L$${BUILD_HOME_BLD}/build/FreeTDS/lib \
-lodbc \
-lodbcinst \
-lct \
-L$${BUILD_HOME_BLD}/build/libiconv/lib \
-liconv \

_unixODBC_LIBS += \
-L$${BUILD_HOME_BLD}/build/libiconv/lib \
-liconv \
