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
#   File: porta.pri
#
# Author: $author$
#   Date: 4/29/2017
########################################################################

########################################################################
# porta
PORTA_PKG = $${FRAMEWORK_PKG}/../porta
PORTA_PRJ = $${FRAMEWORK_PRO_DIR}$${PORTA_PKG}
PORTA_SRC = $${PORTA_PRJ}/src
PORTA_BLD = ../$${PORTA_PKG}/build/$${FRAMEWORK_OS}/QtCreator/$${FRAMEWORK_CONFIG}
PORTA_LIB = $${PORTA_BLD}/lib

porta_INCLUDEPATH += \
$${PORTA_SRC} \

porta_DEFINES += \

porta_LIBS += \
-L$${PORTA_LIB}/libporta \
-lporta \
