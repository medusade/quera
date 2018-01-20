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
# crono
CRONO_VERSION_MAJOR = 0
CRONO_VERSION_MINOR = 0
CRONO_VERSION_RELEASE = 0
CRONO_VERSION = $${CRONO_VERSION_MAJOR}.$${CRONO_VERSION_MINOR}.$${CRONO_VERSION_RELEASE}
CRONO_NAME = crono
CRONO_GROUP = $${CRONO_NAME}
CRONO_DIR = $${CRONO_GROUP}/$${CRONO_NAME}-$${CRONO_VERSION}

CRONO_PKG = $${FRAMEWORK_PKG}/../crono
CRONO_PRJ = $${FRAMEWORK_PRO_DIR}$${CRONO_PKG}
CRONO_SRC = $${CRONO_PRJ}/src
CRONO_BLD = ../$${CRONO_PKG}/build/$${FRAMEWORK_OS}/QtCreator/$${FRAMEWORK_CONFIG}
CRONO_LIB = $${CRONO_BLD}/lib

_crono_INCLUDEPATH += \
$${CRONO_SRC} \

crono_INCLUDEPATH += \
$${BUILD_HOME}/$${CRONO_DIR}/src \

crono_DEFINES += \

_crono_LIBS += \
-L$${CRONO_LIB}/libcrono \
-lcrono \

crono_LIBS += \
-L$${BUILD_HOME_BLD}/build/crono/lib \
-lcrono \
