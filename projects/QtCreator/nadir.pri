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
#   File: stara.pri
#
# Author: $author$
#   Date: 3/12/2017
########################################################################

########################################################################
# nadir
NADIR_PKG = $${FRAMEWORK_PKG}/../nadir
NADIR_PRJ = $${FRAMEWORK_PRO_DIR}$${NADIR_PKG}
NADIR_SRC = $${NADIR_PRJ}/src
NADIR_BLD = ../$${NADIR_PKG}/build/$${FRAMEWORK_OS}/QtCreator/$${FRAMEWORK_CONFIG}
NADIR_LIB = $${NADIR_BLD}/lib

_nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_INCLUDEPATH += \
$${BUILD_HOME}/nadir/nadir-1.1.1/src \

nadir_DEFINES += \

_nadir_LIBS += \
-L$${NADIR_LIB}/libnadir \
-lnadir \

nadir_LIBS += \
-L$${BUILD_HOME_BLD}/build/nadir/lib \
-lnadir \
