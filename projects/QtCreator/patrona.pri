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
#   File: patrona.pri
#
# Author: $author$
#   Date: 3/12/2017
########################################################################

########################################################################
# patrona
PATRONA_VERSION_MAJOR = 0
PATRONA_VERSION_MINOR = 0
PATRONA_VERSION_RELEASE = 0
PATRONA_VERSION = $${PATRONA_VERSION_MAJOR}.$${PATRONA_VERSION_MINOR}.$${PATRONA_VERSION_RELEASE}
PATRONA_NAME = patrona
PATRONA_GROUP = $${PATRONA_NAME}
PATRONA_DIR = $${PATRONA_GROUP}/$${PATRONA_NAME}-$${PATRONA_VERSION}

PATRONA_PKG = $${FRAMEWORK_PKG}/../patrona
PATRONA_PRJ = $${FRAMEWORK_PRO_DIR}$${PATRONA_PKG}
PATRONA_SRC = $${PATRONA_PRJ}/src

_patrona_INCLUDEPATH += \
$${PATRONA_SRC} \

patrona_INCLUDEPATH += \
$${BUILD_HOME}/$${PATRONA_DIR}/src \

patrona_DEFINES += \

patrona_LIBS += \
