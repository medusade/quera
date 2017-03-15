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
#   File: quera.pri
#
# Author: $author$
#   Date: 3/12/2017
########################################################################

########################################################################
# quera
QUERA_PKG = $${FRAMEWORK_PKG}/../quera
QUERA_PRJ = $${FRAMEWORK_PRO_DIR}$${QUERA_PKG}
QUERA_SRC = $${QUERA_PRJ}/src
QUERA_BLD = ../$${QUERA_PKG}/build/$${FRAMEWORK_OS}/QtCreator/$${FRAMEWORK_CONFIG}
QUERA_LIB = $${QUERA_BLD}/lib

quera_INCLUDEPATH += \
$${QUERA_SRC} \
$${crono_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \

quera_DEFINES += \

quera_LIBS += \
-L$${QUERA_LIB}/libquera \
-lquera \
